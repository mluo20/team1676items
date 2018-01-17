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

     <!--<div class="item active">
      <img src="images/1.jpg" alt="Los Angeles">
      <div class="carousel-caption">
        <h3>The Pascack Pioneers</h3>
        <p>See about us!</p>
      </div>
    </div>



<!-- <div class="container-fluid text-center">
<br>

<h1><a href="dashboard.html"><b>The Pascack Pioneers Dashboard</b></p></h1>

</div> -->

<div class="container">

<h1 class="page-header">The Pascack Pioneers Dashboard</h1>

<style>
.custom_button {
	font-size: 25px;
	background-color: #ffcc00;
	display: inline-block;
	border-radius: 14px;
	color: #000;
	margin: 5px;
	margin-left: 0px;
}

.custom_alert {
	padding: 6px 12px;
	font-size: 25px;
	background-color: #f44242;
	display: inline-block;
	border-radius: 14px;
	color: #000;
	margin: 5px;
	margin-left: 0px;
}
</style>

<div id="news">
	<!--<p class="custom_alert"><i class="fa fa-exclamation-triangle" aria-hidden="true"></i>&nbsp;Please Note: Dashboard will be shut down temporarily on January 26th, 2018 for an update.</p>-->
	<a href="login.php" class="btn custom_button"><i class="fa fa-clock-o" aria-hidden="true"></i>&nbsp;CLOCK IN/CLOCK OUT</a>
	<a href="#collapseExample" class="btn custom_button" data-toggle="collapse" aria-expanded="false" aria-controls="collapseExample"><i class="fa fa-chrome" aria-hidden="true"></i>&nbsp;Pioneer Chrome Theme</a>
	<a href="https://goo.gl/x3W17e" target="_blank" class="btn custom_button"><i class="fa fa-bullhorn" aria-hidden="true"></i>&nbsp;Feedback</a>
</div>

<div id="collapseExample" class="collapse alert alert-warning fade">
  <h4 class="alert-heading">The Pascack Pioneers Chrome Theme Installation:</h4>
  <p>Step One: Click on 'Download' below.</p>
  <p>Step Two: Click on the 'Continue' button in your downloads bar.</p>
  <p>Step Three: Click 'Add theme' in the popup message.</p>
  <hr>
  <p class="mb-0"><a href="http://goo.gl/yYW7fs" download="PiTheme.crx">Download</a> - Theme by Jason Zeller</p>
</div>

<div id="news">

	<h2 class="page-header white">Latest News</h2>
	<div class="row">

  <?php
  $news = Article::getList(3);
  foreach ($news['articles'] as $article) {

    $date = date("F j, Y", strtotime($article->date));
    $description = nl2br($article->description);
    $readmore = $article->link == "" ? "" : "<a class=\"btn btn-md\" target=\"_blank\">Sign Up</a>";

    echo <<<_END
      <div class="col-sm-4"> 
          <div class="panel panel-default">
            <div class="panel-heading">$date</div>
            <div class="panel-body">
              <h3>$article->title</h3>
              $description
              $readmore
            </div>
          </div>
      </div>
_END;

  }

  unset($article);

  ?>
    	<!-- <div class="col-sm-4"> 
      		<div class="panel panel-default">
	      		<div class="panel-heading">May 28, 2017</div>
	      		<div class="panel-body">
	      			<h3>Title</h3>
	      			<p>Lorem ipsum dolor sit amet, consectetur adipiscing elit. Mauris tempus, elit vel pretium fringilla, nibh dolor ullamcorper dui, et malesuada arcu dui ut arcu. Praesent iaculis pretium enim, quis pharetra tellus maximus pretium. Morbi convallis urna eros, a dignissim purus porta eu. Suspendisse sit amet diam at arcu vehicula egestas quis id dolor. Aenean non sem sapien. Vivamus ac luctus sem. Nam vehicula libero nec ultrices cursus. Suspendisse pharetra a orci ac vestibulum. Nam vitae tempus metus. Fusce elementum lacus erat, ultricies viverra erat cursus vel. Vivamus elementum elit in purus aliquam, et scelerisque sem accumsan.</p>
	      			<button type="button" class="btn btn-md">Read More</button>
	      		</div>
      		</div>
    	</div>
    	<div class="col-sm-4">
    		<div class="panel panel-default">
	      		<div class="panel-heading">May 28, 2017</div>
	      		<div class="panel-body">
	      			<h3>Title</h3>
	      			<p>Lorem ipsum dolor sit amet, consectetur adipiscing elit. Mauris tempus, elit vel pretium fringilla, nibh dolor ullamcorper dui, et malesuada arcu dui ut arcu. Praesent iaculis pretium enim, quis pharetra tellus maximus pretium. Morbi convallis urna eros, a <a href="#">dignissim</a> purus porta eu. Suspendisse sit amet diam at arcu vehicula egestas quis id dolor. Aenean non sem sapien. Vivamus ac luctus sem. Nam vehicula libero nec ultrices cursus. Suspendisse pharetra a orci ac vestibulum. Nam vitae tempus metus. Fusce elementum lacus erat, ultricies viverra erat cursus vel. Vivamus elementum elit in purus aliquam, et scelerisque sem accumsan.</p>
	      			<button type="button" class="btn btn-md">Read More</button>
	      		</div>
      		</div>
    	</div> -->
  	</div>

</div>

</div>

<div id="info">
<div class="container">
	<div class="row">
		<div class="col-sm-8">
			<h2 class="page-header white">Important Dates</h2>
      <ul class="list-group">
      <?php
      foreach ($events as $event) {
          extract($event);
          //maybe use google calendar as link instead, and have the external link a button
          if (!is_null($date_end) && $date_end != "0000-00-00") $fulldate = date("m/d/Y", strtotime($date)) . " &ndash; " . date("m/d/Y", strtotime($date_end)); else $fulldate = date("m/d/Y", strtotime($date)); 
          if (!empty($link)) $l = "<a href=\"$link\" target=\"_blank\">Read more &raquo;</a>"; else $l = "";
      echo <<<_END
          <li class="list-group-item">
              <h4 class="list-group-item-heading">($fulldate) $title</h4>
              <p class="list-group-item-text">$description</p>
              $l
          </li>
_END;
      }
      ?> 
        <!-- <a href="#" class="list-group-item">
          <h4 class="list-group-item-heading">First List Group Item Heading</h4>
          <p class="list-group-item-text">List Group Item Text</p>
        </a>
        <a href="#" class="list-group-item">
          <h4 class="list-group-item-heading">Second List Group Item Heading</h4>
          <p class="list-group-item-text">List Group Item Text</p>
        </a>
        <a href="#" class="list-group-item">
          <h4 class="list-group-item-heading">Third List Group Item Heading</h4>
          <p class="list-group-item-text">List Group Item Text</p>
        </a> -->
      </ul>
		</div>
		<div class="col-sm-4">

      
      
            <h2 class="page-header white">Upcoming Events</h2>   
      <iframe src="https://calendar.google.com/calendar/embed?showTitle=0&amp;showNav=0&amp;showDate=0&amp;showPrint=0&amp;showTabs=0&amp;showCalendars=0&amp;showTz=0&amp;mode=AGENDA&amp;height=600&amp;wkst=1&amp;bgcolor=%23FFFFFF&amp;src=team1676%40gmail.com&amp;color=%232F6309&amp;ctz=America%2FNew_York" style="border-width:0" width="100%" height="300" frameborder="0" scrolling="no"></iframe>
            <p style="color: rgba(255, 255, 255, 0); font-size: 7px;">yet</p>
		</div>
	</div>	

</div>

</div>

<?php

}

include 'includes/templates/footer.php';

?>
      
      
     