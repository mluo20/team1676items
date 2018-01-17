<?php
session_start();

unset($_SESSION['authorized']);

header("Location: login.php?logout=1")

?>