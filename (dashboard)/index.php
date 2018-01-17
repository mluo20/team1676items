<?php

session_start();

include 'includes/templates/header.php';

if (isset($_GET['page'])) {

  if (empty($_GET['page'])) header("Location: index.php");

  $page = Page::getById($_GET['page']);

  if (($page->showing == 0 && !(isset($_GET['preview']) && $_GET['preview'])) || !isset($_SESSION['authorized'])) header("Location: index.php");
  
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

<h1><a href="index.html">The Pascack Pioneers</a></h1>

</div> -->
<br><br>
<div class="container">

<div id="news">

	<h2 class="page-header white">Latest News</h2>
	<div class="row">

  <?php
  $news = Article::getList(6);
  foreach ($news['articles'] as $article) {

    $date = date("F j, Y", strtotime($article->date));
    $description = nl2br($article->description);
    $readmore = $article->link == "" ? "" : "<a class=\"btn btn-md\" target=\"_blank\">Read More</a>";

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
    <div class="col-sm-4">
    		<div class="panel panel-default">
	      		<div class="panel-heading">May 28, 2017</div>
	      		<div class="panel-body">
	      			<h3>We won</h3>
	      			<p>We're cool now. Please read about it.</p>
	      			<button type="button" class="btn btn-md js-push-button" disabled>Enable Notifications</button>
	      		</div>
      		</div>
    	</div>
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
      <h2>About the Pascack Pioneers</h2>
			<p>Hi we're pretty cool</p>
      <button type="button" class="btn btn-md">Read more about us!</button>
		</div>
		<div class="col-sm-4">
			<h2>Upcoming events</h2>
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
	</div>	

</div>

</div>

<?php

}

include 'includes/templates/footer.php';

?>