<?php
session_start();
require_once 'includes/config.php';
?>


<!DOCTYPE html>
<html lang="en">


<!-- Head -->
<head>

    <!-- Text Editor Stuff -->
    <title><?php if (isset($pagetitle)) echo htmlspecialchars($pagetitle) . " |" ?>Team 1676 Dashboard</title>
    <!-- Text Editor Stuff -->
    
    
    <!-- CSS and File Linking -->
    <link rel="stylesheet" type="text/css" href="bootstrap/css/bootstrap.min.css">
    <link rel="stylesheet" type="text/css" href="https://maxcdn.bootstrapcdn.com/font-awesome/4.7.0/css/font-awesome.min.css">
    
    <link rel="manifest" href="scripts/manifest.json">
    <link rel="shortcut icon" type="image/x-icon" href="http://dashboard.team1676.com/favicon.ico" />
    <!-- /CSS and File Linking -->
    
    
    <!-- JQuary Link -->
    <script src="https://apis.google.com/js/platform.js" async defer></script>
    <script src="https://ajax.googleapis.com/ajax/libs/jquery/3.2.1/jquery.min.js"></script>
    <!-- /JQuary Link -->
    
    
    <!-- Google Sign-In Button Stuff -->
    <meta name="google-signin-scope" content="profile email">
    <meta name="google-signin-client_id" content="178662378799-g65hoifhubripj63ghkrvleoa2gp4jlp.apps.googleusercontent.com">
    <!-- /Google Sign-In Button Stuff -->
 
 
    <!-- Text Editor Stuff -->
    <link href="https://cdnjs.cloudflare.com/ajax/libs/froala-editor/2.6.0/css/froala_editor.pkgd.min.css" rel="stylesheet" type="text/css" />
    <link href="https://cdnjs.cloudflare.com/ajax/libs/froala-editor/2.6.0/css/froala_style.min.css" rel="stylesheet" type="text/css" />
    <!-- /Text Editor Stuff -->


    <!-- Browser Stuff -->
    <meta charset="utf-8">
    <meta name="viewport" content="width=device-width, initial-scale=1">
    <!-- /Browser Stuff -->

  
    <!-- Google Analytics -->
    <script async src="https://www.googletagmanager.com/gtag/js?id=UA-109504052-2"></script>
    <script>
        window.dataLayer = window.dataLayer || [];
        function gtag(){dataLayer.push(arguments);}
        gtag('js', new Date());

        gtag('config', 'UA-109504052-2');
    </script>
    <!-- /Google Analytics -->

</head>
<!-- /Head -->


<!-- Body -->
<body onload="checkCookie()">
<div id="load-screen" style="height: 110%; position: relative; margin-top: -100px; display: none;">
    <br><br><br><br>
    <h1 style="text-align: center;">Loading...</h1>
    <br>
 
    <style>
    #myProgress {
      background-color: #ddd;
    }

    #myBar {
      width: 1%;
      height: 30px;
      background-color: #ffcc00;
    }
    
    #position {
      margin-left: 15%;
      width: 70%;
    }
    </style>
    
    <div id="position">
        <div id="myProgress">
            <div id="myBar"><br></div>
        </div>
        <br>
        <h3 style="display: none;" id="helpText">&nbsp;&nbsp;&nbsp;Still Not Loading? Click <a href="login.php">Here</a>!</h3>
    </div>
</div>
<div id="loaded-screen" style="display: none;">

    <!-- Login Cookie Testing -->
    <script>
    
    function getCookie(cname) {
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
        return "";
    }
    
    var check = function(){
        document.getElementById("load-screen").style.display = "none";
        document.getElementById("position").style.display = "none";
        document.getElementById("loaded-screen").style.display = "block";
    }
    
    setTimeout(function notLoading(){
        document.getElementById("helpText").style.display = "block";
        check();
    }, 2700);
    
    setTimeout(function loadingBar(){
        var url = window.location.pathname;
        if (url == "/2/login.php" || url == "/2/login_mobile.php" || url == "/2/attendance.php") {
            check();
        } else {
            document.getElementById("load-screen").style.display = "block";
            var elem = document.getElementById("myBar");   
            var width = 1;
            var id = setInterval(frame, 16);
            function frame() {
                if (width >= 100) {
                    clearInterval(id);
                } else {
                    width++; 
                    elem.style.width = width + '%'; 
                }
            }
        }
    }, 1000);

    function checkCookie() {
        var user = getCookie("username");
        var url = window.location.pathname;
        var oldURL = document.referrer;
        var x = 1;
        
        var oldURLlong = oldURL.replace(oldURL.substring(oldURL.indexOf(".php") + 4),"");
        var oldURLshort = oldURL.substring(oldURL.indexOf(".php") + 4);
        
        if (oldURLlong == "http://dashboard.team1676.com/2/attendance.php" && oldURLshort == "?co") {
            var xyz = document.getElementById("snackbarOut")
            xyz.className = "show";
            setTimeout(function(){ xyz.className = xyz.className.replace("show", ""); }, 9000);
        }
        if (oldURLlong == "http://dashboard.team1676.com/2/attendance.php" && oldURLshort == "?ci") {
            var xy = document.getElementById("snackbarIn")
            xy.className = "show";
            setTimeout(function(){ xy.className = xy.className.replace("show", ""); }, 9000);
        }
        
        if (url == "/2/login.php" || url == "/2/login_mobile.php" || url == "/2/attendance.php") {
            document.getElementById("not-logged-in").style.display = "block";
            check();
        } else {
            if ((user != "")) {
                console.log("Valid Login Cookie");
                checkCookie2();
                document.getElementById("main-links").style.display = "block";
                document.getElementById("logged-in").style.display = "block";
            } else {
                console.log("Invalid Login");
                if (url == "/2/login.php" || url == "/2/login_mobile.php" || url == "/2/attendance.php") {
                    x = 0;
                }
                if (x == 1) {
                    window.location.replace("http://dashboard.team1676.com/2/login.php");
                }
                document.getElementById("not-logged-in").style.display = "block";
            }
        }
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
    var data2 = getCookie2("clockedIn");
    if (data2 == "true") {
        document.getElementById("clockInOut").innerHTML = "Clock-Out";
        document.getElementById("clockInOutButton").innerHTML = "Clock-Out";
    } else if (data2 == "false") {
        document.getElementById("clockInOut").innerHTML = "Clock-In";
        document.getElementById("clockInOutButton").innerHTML = "Clock-In";
    } else if (data2 == "done") {
        document.getElementById("clockInOutLink").style.display = "none";
        document.getElementById("clockInOutLinkButton").style.display = "none";
    }
}
    </script>
    <!-- /Login Cookie Testing -->


    <!-- Website Navigation -->
    <nav class="navbar navbar-inverse navbar-fixed-top">
        <div class="container">
      
            <!-- Navigation Basics -->
            <div class="navbar-header">
          
                <!-- Dashboard Logo -->
                <a class="navbar-brand" id="dashLogo" href="dashboard.php" style="top: 0px; margin-bottom: 18px; padding-left: 5px; padding-right: 3px;">
                    <img src="../dashboard-logo.png">
                </a>
                <!-- /Dashboard Logo -->
          
                <!-- Dashboard Label -->
                <a class="navbar-brand" href="dashboard.php" style="margin-bottom: 15px; padding-left: 0px; padding-right: 0px;">
                    <img src="../newlogo.png">
                </a>
                <!-- /Dashboard Label -->
          
                <!-- Mobile Navigation Button -->
                <button type="button" class="navbar-toggle" data-toggle="collapse" data-target="#myNavbar" style="margin-top: 17px;">
                    <span class="icon-bar"></span>
                    <span class="icon-bar"></span>
                    <span class="icon-bar"></span> 
                </button>
                <!-- /Mobile Navigation Button -->
          
            </div>
            <!-- /Navigation Basics -->
        
        
            <!-- Navigation Style -->
            <style>
                @media only screen and (min-width : 720px) {
                    .navbar-brand {
                        padding-right: 25px !important;
                    }
                }
            
                @media only screen and (max-width : 347px) {
                    #dashLogo {
                        display: none !important;
                    }
              
                    .lock {
                        padding-right: 27% !important;
                    }
                }
                
                .logged {
                    font-size: 18px !important; 
                    margin-top: 8px !important; 
                    float: right !important; 
                    padding-right: 10px !important; 
                    display: none;
                }
            </style>
            <!-- /Navigation Style -->
        
        
            <!-- Navigation Content -->
            <div class="collapse navbar-collapse" id="myNavbar">
            
                <!-- Menu Links -->
                <ul class="nav navbar-nav" style="font-size: 18px; margin-top: 8px; display: none;" id="main-links">
                    <li>
                        <a href="dashboard.php">Home</a>
                    </li>
                    <?php
                    $categories = $cms->getCategories();
                    foreach ($categories as $category) {
                        extract($category);
                        $pageitems = Page::getList($id);
                        echo "<li class=\"dropdown\"><a class=\"dropdown-toggle\" data-toggle=\"dropdown\" href=\"#\">$name<span class=\"caret\"></span></a>";
                        if ($pageitems['count'] > 0) {
                            echo "<ul class=\"dropdown-menu\">";
                            foreach ($pageitems['pages'] as $page) {
                                if ($page->showing)
                                    echo "<li><a href=\"dashboard.php?page=$page->id\">$page->label</a></li>";
                            }
                            echo "</ul>";
                        }
                        echo "</li>";
                    }
                    unset($category);
                    ?>
                    <li>
                        <a href="forms.php">Forms</a>
                    </li>
                    <li>
                        <a href="calendar.php">Calendar</a>
                    </li>
                    <li id="clockInOutLink">
                        <a href="attendance.php"><p id="clockInOut"></p></a>
                    </li>
                    <li>
                        <a href="backend/login.php" target="_blank">Admin</a>
                    </li> 
                </ul>
                <!-- /Menu Links -->
                
                <!-- Not Logged In -->
                <ul class="nav navbar-nav lock logged" id="not-logged-in">
                    <li>
                        <a style="right:0px;">
                            <i class="fa fa-lock" style="transform: scale(2);" aria-hidden="true"></i>&nbsp;&nbsp;&nbsp;Not Logged-In
                        </a>
                    </li>
                </ul>
                <!-- /Not Logged In -->
                
                <!-- Logged In -->
                <ul class="nav navbar-nav lock logged" id="logged-in">
                    <li>
                        <a style="right: 0px; color: #fff;" href="login.php">
                            <i class="fa fa-unlock-alt" style="transform: scale(2);" aria-hidden="true"></i>&nbsp;&nbsp;&nbsp;Logged-In
                        </a>
                    </li>
                </ul>
                <!-- /Logged In -->
              
            </div>
            <!-- /Navigation Content -->
        
        </div>
    </nav>
    <!-- /Website Navigation -->

    <br>
    
<style>
#snackbarIn {
    visibility: hidden;
    min-width: 250px;
    margin-left: -125px;
    background-color: #333;
    color: #fff;
    text-align: center;
    border-radius: 2px;
    padding: 16px;
    position: fixed;
    z-index: 1;
    left: 50%;
    bottom: 30px;
    font-size: 17px;
}

#snackbarIn.show {
    visibility: visible;
    -webkit-animation: fadein 0.5s, fadeout 0.5s 5s;
    animation: fadein 0.5s, fadeout 0.5s 5s;
}

#snackbarOut {
    visibility: hidden;
    min-width: 250px;
    margin-left: -125px;
    background-color: #333;
    color: #fff;
    text-align: center;
    border-radius: 2px;
    padding: 16px;
    position: fixed;
    z-index: 1;
    left: 50%;
    bottom: 30px;
    font-size: 17px;
}

#snackbarOut.show {
    visibility: visible;
    -webkit-animation: fadein 0.5s, fadeout 0.5s 5s;
    animation: fadein 0.5s, fadeout 0.5s 5s;
}

@-webkit-keyframes fadein {
    from {bottom: 0; opacity: 0;} 
    to {bottom: 30px; opacity: 1;}
}

@keyframes fadein {
    from {bottom: 0; opacity: 0;}
    to {bottom: 30px; opacity: 1;}
}

@-webkit-keyframes fadeout {
    from {bottom: 30px; opacity: 1;} 
    to {bottom: 0; opacity: 0;}
}

@keyframes fadeout {
    from {bottom: 30px; opacity: 1;}
    to {bottom: 0; opacity: 0;}
}
</style>
    
    <div id="snackbarIn">Clock In Successful!</div>
    <div id="snackbarOut">Clock Out Successful!</div>