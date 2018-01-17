<?php
    $src = $_POST["src"];

    $file = basename($src);
    $path = "../uploads/".$file;

    if (file_exists($path)) {
      unlink($path);
    }