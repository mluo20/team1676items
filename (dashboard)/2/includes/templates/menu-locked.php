<nav class="navbar navbar-inverse navbar-fixed-top">
  <div class="container">
    <div class="navbar-header">
      <a class="navbar-brand" id="dashLogo" href="dashboard.php" style="top: 0px; margin-bottom: 18px; padding-left: 5px; padding-right: 3px;"><img src="../dashboard-logo.png"></a>
      <a class="navbar-brand" href="dashboard.php" style="margin-bottom: 15px; padding-left: 0px; padding-right: 0px;"><img src="../newlogo.png"></a>
      <button type="button" class="navbar-toggle" data-toggle="collapse" data-target="#myNavbar" style="margin-top: 17px;">
        <span class="icon-bar"></span>
        <span class="icon-bar"></span>
        <span class="icon-bar"></span> 
      </button>
    </div>
    
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
    }
    </style>
    
    
    <div class="collapse navbar-collapse" id="myNavbar">
      <ul class="nav navbar-nav" style="font-size: 18px; margin-top: 8px; float: right; padding-right: 10px;">
        <li><a href="backend/login.php" target="_blank" style="right:0px;"><i class="fa fa-lock" style="transform: scale(2);" aria-hidden="true"></i>&nbsp;&nbsp;&nbsp;Not Logged-In</a></li>
      </ul>
    </div>
  </div>
</nav>