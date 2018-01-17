<?php

session_start();

if (!isset($_SESSION['authorized'])) header("Location: login.php?auth=1");

require_once '../includes/config.php';
?>

<!DOCTYPE html>
<html lang="en">

<head>

    <meta charset="utf-8">
    <meta name="viewport" content="width=device-width, initial-scale=1">

    <title><?php if (isset($pagetitle)) echo htmlspecialchars($pagetitle) . " |" ;?> Team1676 Admin</title>

    <!-- Bootstrap Core CSS -->
    <link href="../bootstrap/css/bootstrap.min.css" rel="stylesheet">
    <link rel="stylesheet" type="text/css" href="https://maxcdn.bootstrapcdn.com/font-awesome/4.7.0/css/font-awesome.min.css">
    <!-- Include external CSS. -->
    <link href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.4.0/css/font-awesome.min.css" rel="stylesheet" type="text/css" />
    <link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/codemirror/5.25.0/codemirror.min.css">
 
    <!-- Include Editor style. -->
    <link href="https://cdnjs.cloudflare.com/ajax/libs/froala-editor/2.6.0/css/froala_editor.pkgd.min.css" rel="stylesheet" type="text/css" />
    <link href="https://cdnjs.cloudflare.com/ajax/libs/froala-editor/2.6.0/css/froala_style.min.css" rel="stylesheet" type="text/css" />
    <link href="../css/sb-admin.css" rel="stylesheet">
    
    <style>
    .page-header {
        padding-bottom: 9px;
        margin-top: 10px;
        margin-bottom: 5px;
        border-bottom: 1px solid #eee;
    }
    </style>

</head>

<body>

    <div id="wrapper">

        <!-- <div id="page-wrapper"> -->