`<style>

 	
   </style>
   <br><br>

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
<br><br>
<h1><a href="dashboard.html"><b>The Pascack Pioneers Dashboard</b></a></h1>

</div> -->

<div class="container">
                <div class="row">
                    <div class="col-lg-12">
                        <h1 class="page-header">
                            Calendar
                        </h1>
                    </div>
                </div>
<div id="news">

<iframe src="https://calendar.google.com/calendar/embed?showTitle=0&amp;showNav=0&amp;showPrint=0&amp;showCalendars=0&amp;showTz=0&amp;height=600&amp;wkst=1&amp;bgcolor=%23FFFFFF&amp;src=team1676%40gmail.com&amp;color=%000&amp;ctz=America%2FNew_York" style="border-width:0" width="100%" height="600" frameborder="0" scrolling="no"></iframe>


</div>

</div>

<?php

}

include 'includes/templates/footer.php';

?>
      
      
     