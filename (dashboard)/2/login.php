<!-- Loads Top Navigation -->
<?php
include 'includes/templates/header.php';

if (isset($_GET['page'])) {

  if (empty($_GET['page']));

  $page = Page::getById($_GET['page']);

  if (($page->showing == 0 && !(isset($_GET['preview']) && $_GET['preview'])) || !isset($_SESSION['authorized'])) ;
  
  $id = $page->id;
  $title = $page->title;
  $content = $page->content;

  include 'includes/templates/page.php';
  
} else {

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

    $checkUser = "SELECT username FROM attendance_login_google WHERE username = '$uName'";
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
    $allowedChars ='ABCDEFGHIJKLMN
    OPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789./';
    $charsLen = 63;
    $saltLength = 21;
    $salt = "";
    for($i=0; $i<$saltLength; $i++){
         $salt .= $allowedChars[mt_rand(0,$charsLen)];
    }
    //echo $pwd; echo " " . $confirm;
    $hashedPassword = crypt($pwd, $salt);
    if ($pwd == $confirm && !$exists){
      $query = "INSERT INTO attendance_login_google (username, password, email, school, subDivision, PIN, first, last, salt) VALUES ('$uName', '$hashedPassword', '$email', '$school', '$sub', '$pin', '$fName', '$lName', '$salt')";
      $returnedQuery= $mysqli->query($query);
    //  echo $query;
      if(!$returnedQuery){
        $mysqli->error;
      }
    }
  }
  //clock-in page
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
    if ($hashed == $row['password']){
      $loggedIn=true;
      session_start();
      $_SESSION['uid'] = $row['id'];
      $_SESSION['admin'] = $row['isAdmin'];
      $_SESSION['name'] = $row['first'] . " " . $row['last'];
    }
    else {
      echo "<script>function newUser() {
  document.getElementById('showButton').style.bottom = '100%';
  document.getElementById('hideButton').style.bottom = '100%';
  document.getElementById('hideButton2').style.display = 'block';
  document.getElementById('center-me').style.display = 'none';
  document.getElementById('bod').style.position = 'static';
  document.getElementById('not-logged-in').style.display = 'block';
  }
  window.onload = newUser;
  </script>";
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

<link rel="stylesheet" type="text/css" href="css/signin.css">


<head>
  <!-- Mobile Switch Detect -->
  <script type="text/javascript">
    if (screen.width < 720) {
        window.location = "http://dashboard.team1676.com/2/login_mobile.php";
    }
  </script>
  <!-- /Mobile Switch Detect -->
</head>


<!-- Load Icon -->
<script>
  $( document ).ready(function() {
    var rand = Math.round(Math.random() * (1500 - 300)) + 300;
    document.getElementById("load").style.display = "block";
    setTimeout(function(){
      document.getElementById("load").style.display = "none";
      document.getElementById("page").style.visibility = "visible";
    }, rand);
  });
</script>
<!-- /Load Icon -->


<!-- Body -->
<body style="background-color: black;" id="bod" class="back">
<div id="load">
  <br><br><br><br><br><br><br><br><br><br><br>
  <img src="giphy.gif" style="transform: scale(.30);">
</div>

  <!-- Page Content -->
  <div id="page" style="visibility: hidden;">
  <br>
  <div class="item"><br> 
  
    <!-- Old Sign-In Form -->
    <div id="main">
    <br><br><br><br>
    
      <!-- Table -->
      <table class="loginTable">
      <tr>
      
      <!-- Column One -->
      <td valign="top">
        <?php if (!$loggedIn){ ?>
        <?php if ($exists){echo "<h2 align='center'>Username $uName already exists, please try logging in instead.</h2>";} ?>
        <h3 align="center" style="display: none;">Login</h3>
      <form id="login" action="login.php?login" method="post" class="cbp-mc-form" autocomplete="off" style="display: none;">
      <div class="cbp-mc-column" style="width: 100%;">
        <table class="login" style="width: 100%;">
          <tr style="display: none;">
            <td><input class="textbox" name="username" id="email" type="text" placeholder="Username" value="" required ></td>
          </tr>
          <tr style="display: none;">
            <td><p style="color: rgba(255, 255, 255, 0); font-size: 7px;">Have</td>
          </tr>
          <tr style="display: none;">
            <td><input class="textbox" name="pwd" id="pwd" type="password" placeholder="Password" value="" required></td>
          </tr>
          <tr style="display: none;">
            <td><p style="color: rgba(255, 255, 255, 0);">you</td>
          </tr>
          <tr style="display: none;">
            <td><input class="button cbp-mc-submit" type="submit" value="Login"></td>
          </tr>
        </table>
      </form>
      </td>
      <!-- /Column One -->
      
      <!-- Column Two -->
      <td valign="top">
      <br><br><br>
      <h3 align="center">Sign-Up</h3>
      <p style="width: 350px; text-size: 16px; color: white; align: center;">Our systems have detected that this is your first time on Dashboard 2018. Please fill in the questions below to complete your registration. Thanks!</p>
      <form id="register" action="login.php?new" method="post" class="cbp-mc-form" autocomplete="off">
      <div class="cbp-mc-column" style="width: 100%;">
        <table class="login" style="width: 100%;">
          <tr style="display: none;">
            <td><input class="textbox" name="fName" id="fName" type="text" placeholder="First Name" value="" required></td>
          </tr>
          <tr style="display: none;">
            <td><p style="color: rgba(255, 255, 255, 0); font-size: 7px;">found</td>
          </tr>
          <tr style="display: none;">
            <td><input class="textbox" name="lName" id="lName" type="text" placeholder="Last Name" value="" required></td>
          </tr>
          <tr style="display: none;">
            <td><p style="color: rgba(255, 255, 255, 0); font-size: 7px;">the</td>
          </tr>
          <tr style="display: none;">
            <td><input class="textbox" name="email" id="email2" type="text" placeholder="Email" value="" required></td>
          </tr>
          <tr>
            <td><p style="color: rgba(255, 255, 255, 0); font-size: 7px;">secret</td>
          </tr>
          <tr>
            <td><select class="textbox" name="school" required style="display: block; width: 100%;">
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
            <td><p style="color: rgba(255, 255, 255, 0); font-size: 7px;">secret</td>
          </tr>
          <tr>
            <td><select class="textbox" name="sub" required style="display: block; width: 100%;">
              <option value="">
              	Sub-Division
              </option>
              <option value="1">
                One
              </option>
              <option value="2">
                Two...
              </option>
            </select></td>
          </tr>
          <tr>
            <td><p style="color: rgba(255, 255, 255, 0); font-size: 7px;">secret</td>
          </tr>
          <tr>
            <td><p style="color: rgba(255, 255, 255, 0); font-size: 7px;">secret</td>
          </tr>
          <tr>
            <td><input class="textbox" name="pin" type="number" size="4" placeholder="Choose a 4-Digit Security Pin" value="" required style="display: block; width: 100%;"></td>
          </tr>
          <tr style="display: none;">
            <td><p style="color: rgba(255, 255, 255, 0); font-size: 7px;">Can</td>
          </tr>`
          <tr style="display: none;">
            <td><input class="textbox" name="username" id="email3" type="text" placeholder="Username" value="" required></td>
          </tr>
          <tr style="display: none;">
            <td><p style="color: rgba(255, 255, 255, 0); font-size: 7px;">message</td>
          </tr>
          <tr style="display: none;">
            <td><input class="textbox" name="pwd" id="pwd2" type="password" placeholder="Password" value="" required></td>
          </tr>
          <tr style="display: none;">
            <td><p style="color: rgba(255, 255, 255, 0); font-size: 7px;">yet</td>
          </tr>
          <tr style="display: none;">
            <td><input class="textbox" name="confirm" id="pwd3" type="password" placeholder="Re-type Password" value="" required></td>
          </tr>
          <tr>
            <td><p style="color: rgba(255, 255, 255, 0);">?</td>
          </tr>
            <td><input class="button cbp-mc-submit" type="submit" value="Register" style="border: none; width: 50%; margin-left: 25%;"></td>
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
      <form action="http://goo.gl/forms/VFr50Abc64" method="get" class="cbp-mc-form" style="display: none;">
        <table class="login">
          <tr>
            <td>&nbsp;&nbsp;&nbsp;<input style="cursor: pointer;" class="buttonb" type="submit" value="Forgot to sign in?"></td>
          </tr>
        </table>
      </div>
      </form>
      <!-- /Forgot to Sign In -->
      
    <!-- /Old Sign-In Form -->
    
    
    <!-- New Sign-In Form -->
    <div class="item-overlay bottom" id="showButton">
      <div class="center-me" id="center-me">
        <div class="animated fadeOut" id="notificationA" style="display: none;"><h4>Clock-In Successfull</h4></div>
        <div class="animated fadeOut" id="notificationB" style="display: none;"><h4>Clock-In Successfull</h4></div>
        <div class="animated fadeOut" id="notificationC" style="display: none;"><h4>Clock-In Successfull</h4></div>
        <br><br><br><br><br><br><br><br><br><br><br><br>
        <div id="bigger">
          <h1 id="welcome">Welcome!</h1>
          <p id="welcome-message" style="margin-bottom: 0px;">Please click &quot;Sign in&quot; below to continue.</p>
          <a onclick="justSignOut()" href="login.php"><p id="welcome-message2"></p></a>
          <div class="g-signin2" id="goog" data-onsuccess="onSignIn" data-theme="dark"></div>
          <img id="profile">
        </div><br><br><br><br>
        <div id="action-buttons" style="display: none;"><br><br>
          <input class="button cbp-mc-submit" type="submit" form="login" id="login" value="Continue"><br><br>
        </div>
      </div>
    </div>
    </div>
    <!-- /New Sign-In Form -->
    
    <script>
    //When information from Google is sent and verified:
function onSignIn(googleUser) {
  console.log("Running...");

  //Useful data for our client-side scripts:
  var profile = googleUser.getBasicProfile();
  
  var email = profile.getEmail();
  setCookie("username", email, 7);
  
  document.getElementById("action-buttons").style.display = "block";
  document.getElementById("goog").style.display = "none";
        
  //Google "Sign-In" Id
  var pass = profile.getId().substring(0, 8);
  document.getElementById("pwd").value = pass;
  document.getElementById("pwd2").value = pass;
  document.getElementById("pwd3").value = pass;
        
  //Full Name
  console.log('Full Name: ' + profile.getName());
  document.getElementById("welcome-message").innerHTML = ("Not " + profile.getName() + "?");
  document.getElementById("welcome-message2").innerHTML = ("Sign Out");
  
  //First Name
  console.log('Given Name: ' + profile.getGivenName());
  document.getElementById("fName").value = profile.getGivenName();
  var welcom = document.getElementById("welcome");
  welcom.innerHTML = ("Hello, " + profile.getGivenName() + "!");
        
  //Last Name
  console.log('Family Name: ' + profile.getFamilyName());
  document.getElementById("lName").value = profile.getFamilyName();
        
  //Image
  console.log("Image URL: " + profile.getImageUrl());
  document.getElementById("profile").src = profile.getImageUrl();
        
  //Email
  console.log("Email: " + profile.getEmail());
  var use = profile.getEmail().substring(0, profile.getEmail().length - 12);
  document.getElementById("email").value = use;
  document.getElementById("email2").value = profile.getEmail();
  document.getElementById("email3").value = use;
};
    </script>


  <!-- Toggle View Switches
  <div class="google-auto" id="hideButton">
    <p>Dev Toggle:</p>
    <button onclick="signOut();" style="color: #000; background: #c1c1c1;" class="cbp-mc-submit">&nbsp;&nbsp;&nbsp;Old Sign-In&nbsp;&nbsp;&nbsp;</button>
  </div>
  <div class="google-auto" id="hideButton2" style="display: none;">
    <p>Change View:</p>
    <button onclick="viewNew();" style="color: #000; background: #c1c1c1;" class="cbp-mc-submit">&nbsp;&nbsp;&nbsp;New Sign-In&nbsp;&nbsp;&nbsp;</button>
  </div>
  /Toggle View Switches -->
      
  </div>
  </div>
  </div>
  <!-- /Page Content -->
  
   
  <!-- JavaScript and Stuff -->
  <script src="http://dashboard.team1676.com/2/js/signin.js"></script>
  <!-- /JavaScript and Stuff -->
  

  <?php } else{ ?>
  
    <script>
      $( document ).ready(function() {
        document.getElementById("bod").style.position = "static";
      });
    </script>
  
    <center>
    <br><br><br>
        <?php
          $uid = $_SESSION['uid'];
                        
          //***For into Pi-Tech database, change "attendance_records2" to "attendance_records3".
                        
          $getIOstatus = "SELECT * FROM attendance_records2 WHERE uid = '$uid' AND clockin LIKE '$today%' AND clockout = '0'";
          $getIOresult = $mysqli->query($getIOstatus);
          //clock in
          if ($getIOresult->num_rows == 0){ 
        ?>
    <img src="giphy.gif" style="transform: scale(.30);">
      <form action="login.php?ci" method="post">
        <div id="frm"></div>
          <?php 
            if($_SESSION['uid'] == 0){
              echo "<h3 align='center'>Not Logged In.</h3>";
            }
            else{ 
          ?>
          <script>location.href='dashboard.php';</script>
      </form>
    </center>
      
  <?php } } else{ ?>
    <center>
      <img src="giphy.gif" style="transform: scale(.30);">
    </center>
  <?php } ?><?php } ?>
  
  
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

  <!-- JavaScript and Stuff -->
  <script src="http://dashboard.team1676.com/2/js/signin.js"></script>
  <!-- /JavaScript and Stuff -->