<?php
    $src = $_POST["src"];

    $file = basename($src);
    $path = "../images/".$file;

    if (file_exists($path)) {
      unlink($path);
    }