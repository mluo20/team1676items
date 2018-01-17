<br><br><br>

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






<br>

<?php

  //For into Pi-Tech database instead of default database, look for comments with "***" for instructions.

  ini_set('date.timezone', 'America/New_York');
  $ip = $_SERVER['REMOTE_ADDR'];
  $host = $_SERVER['REMOTE_HOST'];
  //echo $ip;
  //echo $host;
  $loggedIn = false;
  require("connect.inc.php");
  $today = date("m/d/Y");
  $timestamp = date("m/d/Y H:i:s");

  if (isset($_GET['new'])){
  

    extract($_POST);
    //$ACL = 1;
    $uName = addslashes($username);

    $checkUser = "SELECT username FROM attendance_login2 WHERE username = '$uName'";
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
      $query = "INSERT INTO attendance_login2 (username, password, email, school, first, last, salt) VALUES ('$uName', '$hashedPassword', '$email', '$school', '$fName', '$lName', '$salt')";
      $returnedQuery= $mysqli->query($query);
    //  echo $query;
      if(!$returnedQuery){
        $mysqli->error;
      }
    }
  }
  else if (isset($_GET['login'])){
    extract($_POST);
    $query = "SELECT * FROM attendance_login2 WHERE username = '$username'";
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
      //$query = "INSERT INTO attendance_records3(uid, clockin, locationin, ip_in, host_in, pitechnum) VALUES ('$uid', '$timestamp', '41.06056988239288, -74.05045330524444', '$ip', '$host', 'Pi-Tech #1')";
      
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
<!DOCTYPE html>
<html>
<head>
  <meta content="true" name="HandheldFriendly">

  <meta content="width=device-width" name="Viewport">
  <title>Pascack Pi-oneers Attendance</title>
  
  <link rel="icon" href="www.team1676.com/favicon.ico">
  <link rel="stylesheet" type="text/css" href="bootstrap/css/bootstrap.min.css">

  <script type="text/javascript">
    if (screen.width < 720) {
        window.location = "http://dashboard.team1676.com/login_mobile.php";
    }
  </script>
  
  <style>
   body {
    	background: #000 url("piBack.png") no-repeat;
    	    background-attachment: fixed;
    background-position: center; 
      }

    table.loginTable {

   
    margin: 0 auto;
}

.main {
    margin-top: 50%;
    margin-bottom: 50%;
}

    .buton{
     margin: 0 auto; 
    }
    #loginTable{
      margin: 0 auto;
      align:center;
    }
         .bgimg{
             position: fixed;
             top: 50%;
             left: 50%;
             min-width: 100%;
             min-height: 100%;
             width: auto;
             height: auto;
             z-index: -100;
             -ms-transform: translateX(-50%) translateY(-50%);
             -moz-transform: translateX(-50%) translateY(-50%);
             -webkit-transform: translateX(-50%) translateY(-50%);
             transform: translateX(-50%) translateY(-50%);
             
  
             
             
      filter: blur(10px);
-webkit-filter: blur(10px);
-moz-filter: blur(10px);
-o-filter: blur(10px);
-ms-filter: blur(10px);
         }
         .login{
             margin-left:auto;
             margin-right:auto;
         }
         
         
         .cbp-mc-form {
	position: relative;
}

h3{
color: #fff;
text-transform: uppercase;
font-family: 'Lato', Calibri, Arial, sans-serif;
font-size: 2.2em;
text-align: center;
}

h1{
color: #fff;
text-transform: uppercase;
font-family: 'Lato', Calibri, Arial, sans-serif;
font-size: 2.1em;
text-align: center;
}

h2{
color: #fff;
text-transform: uppercase;
font-family: 'Lato', Calibri, Arial, sans-serif;
font-size: 1.1em;
text-align: center;
}

h4{
color: #000;
text-transform: uppercase;
font-family: 'Lato', Calibri, Arial, sans-serif;
text-align: center;
font-size: 25px;
background-color: #e9e901;
display: block;
border-radius: 14px;
margin-left: 25%;
margin-right: 25%;
padding: 3px;
}

         .animated {
            -webkit-animation-duration: 10s;animation-duration: 10s;
            -webkit-animation-fill-mode: both;animation-fill-mode: both;
         }

         @-webkit-keyframes fadeOut {
            0% {opacity: 1;}
            75% {opacity: 1;}
            100% {opacity: 0;}
         }

         @keyframes fadeOut {
            0% {opacity: 1;}
            75% {opacity: 1;}
            100% {opacity: 0;}
         }

         .fadeOut {
            -webkit-animation-name: fadeOut;
            animation-name: fadeOut;
         }

/* Clearfix hack by Nicolas Gallagher: http://nicolasgallagher.com/micro-clearfix-hack/ */
.cbp-mc-form:before, 
.cbp-mc-form:after { 
	content: " "; display: table; 
}

.cbp-mc-form:after { 
	clear: both; 
}

.cbp-mc-column {
	padding: 10px 30px;
	float: left;
}

.cbp-mc-form label {
	display: block;
	padding: 40px 5px 5px 2px;
	font-size: 1.1em;
	text-transform: uppercase;
	letter-spacing: 1px;
	cursor: pointer;
}

.cbp-mc-form input,
.cbp-mc-form textarea,
.cbp-mc-form select,
.cbp-mc-form button {
	font-family: 'Lato', Calibri, Arial, sans-serif;
	line-height: 1.5;
	font-size: 1.4em;
	padding: 5px 10px;
	color: #fff;
	display: block;

	background: transparent;
}

.cbp-mc-form input,
.cbp-mc-form textarea {
	border: 3px solid #fff;
}

.cbp-mc-form textarea {
	min-height: 200px;
}

.cbp-mc-form input:focus,
.cbp-mc-form button,
.cbp-mc-form textarea:focus,
.cbp-mc-form label:active + input,
.cbp-mc-form label:active + textarea {
	outline: none;
	border: 3px solid #e9e901;
}

.cbp-mc-form input:valid {
	outline: none;
	border: 3px solid #e9e901;
}

.buttonb {
	outline: none;
	
	color: #fff;
	display: block;
	width: 100%;
	background: transparent;
		font-size: 1.4em;
}

.buttonb:hover{
	outline: none;
	border: 3px solid #e9e901;
		cursor: pointer;
}

.cbp-mc-form select:focus {
	outline: none;
}

::-webkit-input-placeholder { /* WebKit browsers */
    color: #fff;
    font-style: italic;
}

:-moz-placeholder { /* Mozilla Firefox 4 to 18 */
    color: #fff;
    font-style: italic;
}

::-moz-placeholder { /* Mozilla Firefox 19+ */
    color: #fff;
    font-style: italic;
}

:-ms-input-placeholder { /* Internet Explorer 10+ */
    color: #fff;
    font-style: italic;
}

.cbp-mc-submit-wrap {
	text-align: center;
	padding-top: 40px;
	clear: both;
}

.cbp-mc-form input.cbp-mc-submit {
	background: #fff;
	border: none;
	color: #000;
	width: auto;
	cursor: pointer;
	text-transform: uppercase;
	display: inline-block;
	padding: 15px 30px;
	font-size: 1.1em;
	border-radius: 2px;
	letter-spacing: 1px;
}

.cbp-mc-form input.cbp-mc-submit:hover {
	background: #e9e901;
	color: #000;
}

.clock-in {
	background: #fff;
	border: none;
	color: #000;
	width: auto;
	cursor: pointer;
	text-transform: uppercase;
	font-size: 4.8em;
	border-radius: 14px;
	letter-spacing: 1px;
	margin-left: 19%;
	margin-right: 50%;
	
}

.clock-in:hover {
	background: #e9e901;
	
}

.clearfix:before, .clearfix:after { content: " "; display: table; }
.clearfix:after { clear: both; }
  </style>
</head>
<body style="background-color: black;">

  <div id="page">
  



    <div id="header"></div><img class="bgimg">
    <div id="main">
    <table class="loginTable">
      <tr>

        <td valign="top">
        
      <?php if (!$loggedIn){ ?>
      <?php
                          if ($exists){
                            echo "<h2 align='center'>Username $uName already exists, please try logging in instead.</h2>";
                          }
                        ?>
      <h3 align="center">Login</h3>
      <form action="login.php?login" method="post" class="cbp-mc-form" autocomplete="off">
      <div class="cbp-mc-column">
        <table class="login">
          <tr>
            <td><input class="textbox" name="username" type="text" placeholder="Username" required></td>
          </tr>
          <tr>
            <td><p style="color: rgba(255, 255, 255, 0); font-size: 7px;">Have</td>
          </tr>
          <tr>
            <td><input class="textbox" name="pwd" type="password" placeholder="Password" required></td>
          </tr>
          <tr>
            <td><p style="color: rgba(255, 255, 255, 0);">you</td>
          </tr>
          <tr>
            <td><input class="button cbp-mc-submit" type="submit" value="Login"></td>
          </tr>
        </table>
      </form>
      </td>
      
      <td valign="top">
      <h3 align="center">Register</h3>
      <form action="login.php?new" method="post" class="cbp-mc-form" autocomplete="off">
      <div class="cbp-mc-column">
        <table class="login">
          <tr>
            <td><input class="textbox" name="fName" type="text" placeholder="First Name" required></td>
          </tr>
          <tr>
            <td><p style="color: rgba(255, 255, 255, 0); font-size: 7px;">found</td>
          </tr>
          <tr>
            <td><input class="textbox" name="lName" type="text" placeholder="Last Name" required></td>
          </tr>
          <tr>
            <td><p style="color: rgba(255, 255, 255, 0); font-size: 7px;">the</td>
          </tr>
          <tr>
            <td><input class="textbox" name="email" type="text" placeholder="Email" required></td>
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
            <td><input class="textbox" name="username" type="text" placeholder="Username" required></td>
          </tr>
          <tr>
            <td><p style="color: rgba(255, 255, 255, 0); font-size: 7px;">message</td>
          </tr>
          <tr>
            <td><input class="textbox" name="pwd" type="password" placeholder="Password" required></td>
          </tr>
          <tr>
            <td><p style="color: rgba(255, 255, 255, 0); font-size: 7px;">yet</td>
          </tr>
          <tr>
            <td><input class="textbox" name="confirm" type="password" placeholder="Re-type Password" required></td>
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
      </tr>
      </table>
      
      <form action="https://goo.gl/forms/EAW51HJu8Lz4QVdA2" method="get" class="cbp-mc-form">
        <table class="login">
          <tr>
            <td>&nbsp;&nbsp;&nbsp;<input style="cursor: pointer;" class="buttonb" type="submit" value=
            "Forgot to Clock-In?"></td>
          </tr>
        </table>
      </div>
      </form>
      
      
      
      
     
    </div>
  </div>
  
  <center>

   <?php } else{ ?>
  
   
   
  
      <h3 align="center" style="color: white;">Pascack Pi-oneers Dashboard</h3><?php
                        $uid = $_SESSION['uid'];
                        
                        //***For into Pi-Tech database, change "attendance_records2" to "attendance_records3".
                        
                        $getIOstatus = "SELECT * FROM attendance_records2 WHERE uid = '$uid' AND clockin LIKE '$today%' AND clockout = '0'";
                        $getIOresult = $mysqli->query($getIOstatus);
                        //clock in
                        if ($getIOresult->num_rows == 0){ ?>
      <h3 align="center" style="color: white;">Welcome, <?php echo $_SESSION['name']; ?>.</h3>
     <center>
      <form action="login.php?ci" method="post">
        <div id="frm"></div><?php if($_SESSION['uid'] == 0){
                                  echo "<h3 align='center'>Not Logged In.</h3>";
                                }
                                else{ ?><input class="buton clock-in" type='submit' value='Clock In'>
      </form>
            <form action="https://goo.gl/forms/EAW51HJu8Lz4QVdA2" method="get" class="cbp-mc-form">
        <table class="login">
          <tr>
            <td>&nbsp;&nbsp;&nbsp;<input style="cursor: pointer;" class="buttonb" type="submit" value=
            "Forgot to Clock-In?"></td>
          </tr>
        </table>
      </div>
      </form>
       </center>
      
      <?php
                          }
                        }
                        //clock out
                        else{ ?>
      <h3 align="center">Welcome, <?php echo $_SESSION['name']; ?>.</h3>
      <center>
        <form action="login.php?co" method="post">
          <div id="frm2">
            <p></p>
          </div>
          <div class='question'>
            <h2>How did you contribute today?</h2>
          </div><br>
          <textarea width="100%" cols='50' name='what' required="" rows='15'></textarea><br><br><br><br>
          <input type='submit' class="buttonb" value='Clock Out'>
        </form>
              <form action="https://goo.gl/forms/EAW51HJu8Lz4QVdA2" method="get" class="cbp-mc-form">
        <table class="login">
          <tr>
            <td>&nbsp;&nbsp;&nbsp;<input style="cursor: pointer;" class="buttonb" type="submit" value=
            "Forgot to Clock-In?"></td>
          </tr>
        </table>
      </div>
      </form>
      </center>
   <?php }
                        ?><?php } ?>

  </center>
  
</body>
</html>




<?php

}

include 'includes/templates/footer.php';

?>
      