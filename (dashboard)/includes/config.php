<?php

$host = "localhost";
$user = "team1676";
$pass = "Pi~1676_Oneers";
$db = "dashboard";

$conn = new mysqli($host, $user, $pass, $db);
if ($conn->connect_error) echo "<p>Error in connecting to database: $conn->connect_error</p>";

require_once 'classes/Page.php';
require_once 'classes/Article.php';
require_once 'classes/RoboticsCMS.php';

$cms = new RoboticsCMS();