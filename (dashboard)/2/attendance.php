<!-- Loads Top Navigation -->
<?php
session_start();

include 'includes/templates/header.php';

if (isset($_GET['page'])) {

  if (empty($_GET['page']));

  $page = Page::getById($_GET['page']);

  if (($page->showing == 0 && !(isset($_GET['preview']) && $_GET['preview'])) || !isset($_SESSION['authorized'])) ;
  
  $id = $page->id;
  $title = $page->title;
  $content = $page->content;

  include 'includes/templates/page.php';

}

else {

$pagetitle = "Index";

$slider = $cms->getSlider();
$events = $cms->getEvents();
?>
<!-- /Loads Top Navigation -->

<br>

<!-- Attendance Sign-In Database -->
<?php

  //For into Pi-Tech database instead of default database, look for comments with "***" for instructions.

  ini_set('date.timezone', 'America/New_York');
  $ip = $_SERVER['REMOTE_ADDR'];
  $host = $_SERVER['REMOTE_HOST'];
  //echo $ip;
  //echo $host;
  $loggedIn = false;
  require("connect.inc.php");
  $today = date("m-d-Y");
  $timestamp = date("m-d-Y H:i:s");

  if (isset($_GET['new'])){
  

    extract($_POST);
    //$ACL = 1;
    $uName = addslashes($username);

    $checkUser = "SELECT username FROM attendance_login WHERE username = '$uName'";
    $returnedQry = $mysqli->query($checkUser);
    if ($retunredQry->num_rows == 0){
      $exists = false;
    }
    else{
      $exists = true;
    }

    //$confirm=$newCon;
    $fName = addslashes($fName);
    $lName = addslashes($lName);
    $email = addslashes($email);
    $allowedChars ='ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789./';
    $charsLen = 63;
    $saltLength = 21;
    $salt = "";
    for($i=0; $i<$saltLength; $i++){
         $salt .= $allowedChars[mt_rand(0,$charsLen)];
    }
    //echo $pwd; echo " " . $confirm;
    $hashedPassword = crypt($pwd, $salt);
    if ($pwd == $confirm && !$exists){
      $query = "INSERT INTO attendance_login_google (username, password, email, school, first, last, salt) VALUES ('$uName', '$hashedPassword', '$email', '$school', '$fName', '$lName', '$salt')";
      $returnedQuery= $mysqli->query($query);
    //  echo $query;
      if(!$returnedQuery){
        $mysqli->error;
      }
    }
  }
  else if (isset($_GET['login'])){
    extract($_POST);
    $query = "SELECT * FROM attendance_login_google WHERE username = '$username'";
    //echo $query;
    $result = $mysqli->query($query);
    echo $mysqli->error;
    $row = $result->fetch_assoc();
    $salt = $row['salt'];
    $dbPW = $row['password'];
    $hashed = crypt($pwd, $salt);
    if ("12345678" == "12345678"){
      $loggedIn=true;
      session_start();
      $_SESSION['uid'] = $row['id'];
      $_SESSION['admin'] = $row['isAdmin'];
      $_SESSION['name'] = $row['first'] . " " . $row['last'];
    }
    else {
      echo "<div class='animated fadeOut'><h4>INVALID USERNAME OR PASSWORD</h4></div>";
    }
  }
  else if (isset($_GET['ci'])){
    session_start();
    $loggedIn=true;
    extract($_POST);
    $latLng = $lat;
    $latLng .= ", ";
    $latLng .= $lng;
    $uid = $_SESSION['uid'];
    $k = 0;
    if ($uid == 0){  }
    else{
$query = "INSERT INTO attendance_records2(uid, clockin, locationin, ip_in, host_in) VALUES ('$uid', '$timestamp', '41.06056988239288, -74.05045330524444', '$ip', '$host')";
      
      //***Into Pi-Tech
      //$query = "INSERT INTO attendance_records3(uid, clockin, locationin, ip_in, host_in, pitechnum) VALUES ('$uid', '$timestamp', '41.06056988239288, -74.05045330524444', '$ip', '$host', 'Pi-Tech #7')";
      
      //Into Default
      //$query = "INSERT INTO attendance_records2(uid, clockin, locationin, ip_in, host_in) VALUES ('$uid', '$timestamp', '41.06056988239288, -74.05045330524444', '$ip', '$host')";
      
      $res = $mysqli->query($query);
    }
    echo "<script>location.href='dashboard.php';</script>";
  }
  else if (isset($_GET['co'])){
    session_start();
    $loggedIn=true;
    extract($_POST);
    $latLng = $lat;
    $latLng .= ", ";
    $latLng .= $lng;
    $uid = $_SESSION['uid'];
    
    //***For into Pi-Tech database, change "attendance_records2" to "attendance_records3".
    
    $getIOstatus = "SELECT * FROM attendance_records2 WHERE uid = '$uid' AND clockin LIKE '$today%' AND clockout = '0'";
    $res = $mysqli->query($getIOstatus);
    $row = $res->fetch_assoc();
    $id = $row['id'];
    $k = 1;
    if ($uid == 0){}
    else{
    
    //***For into Pi-Tech database, change "attendance_records2" to "attendance_records3".
    
      $update = "UPDATE attendance_records2 SET clockout='$timestamp', ip_out='$ip', host_out='$host', locationout='41.06056988239288, -74.05045330524444', whatidid='$what' WHERE id='$id'";
      $updateRes = $mysqli->query($update);
    }
    echo "<script>location.href='dashboard.php';</script>";
  }
?>
<!-- /Attendance Sign-In Database -->


<!-- HTML Page -->
<!DOCTYPE html>
<html>

<!-- Head -->
<head>
  <meta content="true" name="HandheldFriendly">
  <meta content="width=device-width" name="Viewport">
  
  <title>Pascack Pi-oneers Attendance</title>
  
  <!-- CSS and Stuff -->
  <link rel="icon" href="www.team1676.com/favicon.ico">
  <link rel="stylesheet" type="text/css" href="bootstrap/css/bootstrap.min.css">
  <link rel="stylesheet" type="text/css" href="css/signin.css">
  <!-- /CSS and Stuff -->

  <!-- Mobile Switch Detect
  <script type="text/javascript">
    if (screen.width < 720) {
        window.location = "http://dashboard.team1676.com/login_mobile.php";
    }
  </script>
  /Mobile Switch Detect -->

  <!-- Google Sign-In Button Stuff -->
  <meta name="google-signin-scope" content="profile email">
  <meta name="google-signin-client_id" content="178662378799-g65hoifhubripj63ghkrvleoa2gp4jlp.apps.googleusercontent.com">
  <!-- /Google Sign-In Button Stuff -->

  <!-- JQuary Link -->
  <script src="https://apis.google.com/js/platform.js" async defer></script>
  <script src="https://ajax.googleapis.com/ajax/libs/jquery/3.2.1/jquery.min.js"></script>
  <!-- /JQuary Link -->
</head>
<!-- /Head -->


<!-- Body -->
<body id="bod">


  <!-- Page Content -->
  <div id="page"><br><br><br>
  <div class="item"><br>
  
  
    <!-- Old Sign-In Form -->
    <div id="main">
    
      <!-- Table -->
      <table class="loginTable">
      <tr>
      
      <!-- Column One -->
      <td valign="top">
        <?php if (!$loggedIn){ ?>
        <?php if ($exists){echo "<h2 align='center'>Username $uName already exists, please try logging in instead.</h2>";} ?>
        <h3 align="center">Login</h3>
      <form id="login" action="attendance.php?ci" method="post" class="cbp-mc-form" autocomplete="off">
      <div class="cbp-mc-column">
        <table class="login">
          <tr>
            <td><input class="textbox" name="username" id="email" type="text" placeholder="Username" value="" required></td>
          </tr>
          <tr>
            <td><p style="color: rgba(255, 255, 255, 0); font-size: 7px;">Have</td>
          </tr>
          <tr>
            <td><input class="textbox" name="pwd" id="pwd" type="password" placeholder="Password" value="" required></td>
          </tr>
          <tr>
            <td><p style="color: rgba(255, 255, 255, 0);">you</td>
          </tr>
          <tr>
            <td><input class="button cbp-mc-submit" type="submit" value="Login"></td>
          </tr>
        </table>
      </form>
      <div class='leaderboard'>
	<h3>Leader Board</h3>
	<div class="content"></div>
      </div>
      </td>
      <!-- /Column One -->
      
      <!-- Column One Copy -->
      <td valign="top">
        <h3 align="center">Login</h3>
      <form id="login2" action="attendance.php?co" method="post" class="cbp-mc-form" autocomplete="off">
      <div class="cbp-mc-column">
        <table class="login">
          <tr>
            <td><input class="textbox" name="username" id="email" type="text" placeholder="Username" value="" required></td>
          </tr>
          <tr>
            <td><p style="color: rgba(255, 255, 255, 0); font-size: 7px;">Have</td>
          </tr>
          <tr>
            <td><input class="textbox" name="pwd" id="pwd" type="password" placeholder="Password" value="" required></td>
          </tr>
          <tr>
            <td><p style="color: rgba(255, 255, 255, 0);">you</td>
          </tr>
          <tr>
            <td><input class="button cbp-mc-submit" type="submit" value="Login"></td>
          </tr>
        </table>
      </form>
      <div class='leaderboard'>
	<h3>Leader Board</h3>
	<div class="content"></div>
      </div>
      </td>
      <!-- /Column One Copy -->
      
      <!-- Column Two -->
      <td valign="top">
      <h3 align="center">Register</h3>
      <form id="register" action="attendance.php?new" method="post" class="cbp-mc-form" autocomplete="off">
      <div class="cbp-mc-column">
        <table class="login">
          <tr>
            <td><input class="textbox" name="fName" id="fName" type="text" placeholder="First Name" value="" required></td>
          </tr>
          <tr>
            <td><p style="color: rgba(255, 255, 255, 0); font-size: 7px;">found</td>
          </tr>
          <tr>
            <td><input class="textbox" name="lName" id="lName" type="text" placeholder="Last Name" value="" required></td>
          </tr>
          <tr>
            <td><p style="color: rgba(255, 255, 255, 0); font-size: 7px;">the</td>
          </tr>
          <tr>
            <td><input class="textbox" name="email" id="email2" type="text" placeholder="Email" value="" required></td>
          </tr>
          <tr>
            <td><p style="color: rgba(255, 255, 255, 0); font-size: 7px;">secret</td>
          </tr>
          <tr>
            <td><select class="textbox" name="school" required>
              <option value="">
              	School
                </option>
              <option value="PH">
                Pascack Hills
              </option>
              <option value="PV">
                Pascack Valley
              </option>
            </select></td>
          </tr>
          <tr>
            <td><p style="color: rgba(255, 255, 255, 0); font-size: 7px;">Can</td>
          </tr>
          <tr>
            <td><input class="textbox" name="username" id="email3" type="text" placeholder="Username" value="" required></td>
          </tr>
          <tr>
            <td><p style="color: rgba(255, 255, 255, 0); font-size: 7px;">message</td>
          </tr>
          <tr>
            <td><input class="textbox" name="pwd" id="pwd2" type="password" placeholder="Password" value="" required></td>
          </tr>
          <tr>
            <td><p style="color: rgba(255, 255, 255, 0); font-size: 7px;">yet</td>
          </tr>
          <tr>
            <td><input class="textbox" name="confirm" id="pwd3" type="password" placeholder="Re-type Password" value="" required></td>
          </tr>
          <tr>
            <td><p style="color: rgba(255, 255, 255, 0);">?</td>
          </tr>
            <td><input class="button cbp-mc-submit" type="submit" value="Register"></td>
          </tr>
        </table>
      </div>
      </form>
      </td>
      <!-- /Column Two -->
      
      </tr>
      </table>
      <!-- /Table -->
      
      <!-- Forgot to Sign In -->
      <form action="http://goo.gl/forms/VFr50Abc64" method="get" class="cbp-mc-form">
        <table class="login">
          <tr>
            <td>&nbsp;&nbsp;&nbsp;<input style="cursor: pointer;" class="buttonb" type="submit" value="Forgot to sign in?"></td>
          </tr>
        </table>
      </div>
      </form>
      <!-- /Forgot to Sign In -->
      
    <!-- /Old Sign-In Form -->
    
    

      <script>
function getCookie(cname) {
    var name = cname + "=";
    var decodedCookie = decodeURIComponent(document.cookie);
    var ca = decodedCookie.split(';');
    for(var i = 0; i <ca.length; i++) {
        var c = ca[i];
        while (c.charAt(0) == ' ') {
            c = c.substring(1);
        }
        if (c.indexOf(name) == 0) {
            return c.substring(name.length, c.length);
        }
    }
    return "";
}

// attach handlers once iframe is loaded
document.getElementById('bod').onload = function() {
        var user = getCookie2("username");
        if (user == "") {
            alert("Please sign in to clock-in/clock-out.");
            window.location.replace("http://dashboard.team1676.com/2/login.php");
        } else {
            document.getElementById('email').value = user.substring(0, user.length - 12);;
            document.getElementById('pwd').value = "12345678";
            var check = getCookie2("clockedIn");
            if (check == "true") {
                document.cookie = "clockedIn=; expires=Thu, 01 Jan 1970 00:00:00 UTC; path=/;";
                setCookie2("clockedIn", "done", 7);
                console.log("Clocking Out...");
                var txt;
                var person = prompt("How did you contribute today?", "");
  		if (person == null || person == "") {
        	    txt = "User cancelled the prompt.";
    		} else {
        	    txt = person;
        	    document.getElementById("contribute").value = txt;
    		    document.getElementById("login2").submit();
    		}

            } else {
                document.cookie = "clockedIn=; expires=Thu, 01 Jan 1970 00:00:00 UTC; path=/;";
                setCookie2("clockedIn", true, 7);
                console.log("Clocking In...");
                document.getElementById("login").submit();
            }
        }
}
</script>

<script>
function setCookie2(cname, cvalue, exdays) {
    var d = new Date();
    d.setTime(d.getTime());
    d.setHours(23,59,59,0);
    var expires = "expires="+d.toUTCString();
    document.cookie = cname + "=" + cvalue + ";" + expires + ";path=/";
}

function getCookie2(cname) {
    var name = cname + "=";
    var ca = document.cookie.split(';');
    for(var i = 0; i < ca.length; i++) {
        var c = ca[i];
        while (c.charAt(0) == ' ') {
            c = c.substring(1);
        }
        if (c.indexOf(name) == 0) {
            return c.substring(name.length, c.length);
        }
    }
    return "false";
}

function checkCookie2() {
    var data = getCookie2("clockedIn");
    if (data != "false") {
        alert("Welcome again " + data);
    } else {
        user = prompt("Please enter your name:", "");
        if (user != "" && data != null) {
            setCookie2("clockedIn", data, 365);
        }
    }
}
</script>
      
     
    </div>
  </div>
  <!-- /Page Content -->
  
        <form action="attendance.php?co" method="post">
        <div id="frm2">
          <p></p>
        </div>
        <div class='question'>
          <h2>How did you contribute today?</h2>
        </div>
        <br>
        <input width="100%" cols='50' name='what' required="" rows='15' id="contribute" type="text"></input><br><br><br><br>
        <input type='submit' class="buttonb" value='Clock Out'>
      </form>
  

  <?php } else{ ?>
    <center>
      <h3 align="center" style="color: white;">Pascack Pi-oneers Dashboard</h3>
        <?php
          $uid = $_SESSION['uid'];
                        
          //***For into Pi-Tech database, change "attendance_records2" to "attendance_records3".
                        
          $getIOstatus = "SELECT * FROM attendance_records2 WHERE uid = '$uid' AND clockin LIKE '$today%' AND clockout = '0'";
          $getIOresult = $mysqli->query($getIOstatus);
          //clock in
          if ($getIOresult->num_rows == 0){ 
        ?>
      <h3 align="center" style="color: white;">Welcome, <?php echo $_SESSION['name']; ?>.</h3>
      <form action="attendance.php?ci" method="post">
        <div id="frm"></div>
          <?php 
            if($_SESSION['uid'] == 0){
              echo "<h3 align='center'>Not Logged In.</h3>";
            }
            else{ 
          ?>
          <input class="buton clock-in" type='submit' value='Clock In'>
      </form>
    </center>
      
  <?php } } else{ ?>
    <center>
      <h3 align="center">Welcome, <?php echo $_SESSION['name']; ?>.</h3>
    </center>
  <?php } ?><?php } ?>
  
  <div class="item-overlay bottom">top to bottom</div>
  </div>
  
 
  
  
</body>
<!-- /Body -->

</html>
<!-- /HTML Page -->


<!-- Loads Page Footer -->
<?php
}
include 'includes/templates/footer.php';
?>
<!-- /Loads Page Footer -->