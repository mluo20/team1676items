<?php

date_default_timezone_set("America/New_York");

$host = "localhost";
$db = "cms_test";
$user = "shine";
$pass = "dogra214";

$conn = new mysqli($host, $user, $pass, $db);
if ($conn->connect_error) die("Connection failed: " . $conn->connect_error);

require_once "../includes/classes/Article.php";

$article = Article::get_by_id($_POST['id'], "saved_articles");
$article->store_form_values($_POST);
$article->update("saved_articles");