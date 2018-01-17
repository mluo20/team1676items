<?php

session_start();

if (isset($_SESSION['authorized'])) header("Location: admin.php");

$adminuser = "pioneersadmin";
$adminpass = "Pioneers#1676";

if (isset($_GET['logout'])) $error = "<div class=\"alert alert-info\">You are now logged out.</div>";
if (isset($_GET['auth'])) $error = "<div class=\"alert alert-danger\">You are not authorized to access this page. Please log in.</div>";

if ($_SERVER['REQUEST_METHOD'] == "POST") {

	extract($_POST);

	if ($username == $adminuser && $password == $adminpass) {
		$_SESSION['authorized'] = $adminuser;
		header("Location: admin.php");
	}
	else {
		$error = "<div class=\"alert alert-danger\">Username or password is incorrect. Please try again.</div>";
	}

}

?>
<!DOCTYPE html>
<html>
<head>

	<title>Login</title>

	<link rel="stylesheet" type="text/css" href="../bootstrap/css/bootstrap.min.css">
	<link rel="stylesheet" type="text/css" href="https://maxcdn.bootstrapcdn.com/font-awesome/4.7.0/css/font-awesome.min.css">

</head>
<body>

<div class="container">
	<div class="row">
	<div class="col-lg-4 col-lg-offset-4">
	<h1>Login</h1>
	<?php
	if (isset($error)) echo $error;
	?>
		<form action="" method="POST">
		  <div class="input-group input-group-lg" style="margin-bottom: 5px;">
		    <span class="input-group-addon"><i class="fa fa-user" aria-hidden="true"></i></span>
		    <input id="username" type="text" class="form-control" name="username" placeholder="Username" required>
		  </div>
		  <div class="input-group input-group-lg">
		    <span class="input-group-addon"><i class="fa fa-unlock-alt" aria-hidden="true"></i></span>
		    <input id="password" type="password" class="form-control" name="password" placeholder="Password" required>
		  </div><br>
		  <button type="submit" class="btn btn-primary">Login</button>
		</form>
	</div>
	</div>
</div>

</body>
</html>