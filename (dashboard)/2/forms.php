`<style>

    
   </style>
   <br><br>

      <?php

session_start();

include 'includes/templates/header.php';

if (isset($_GET['form'])) {

  if (empty($_GET['form']));

  $page = Form::getById($_GET['form']);

  if (($page->showing == 0 && !(isset($_GET['preview']) && $_GET['preview'])) || !isset($_SESSION['authorized'])) ;
  
  $id = $page->id;
  $title = $page->title;
  $content = $page->content;
  $date = $page->date;

  include 'includes/templates/form.php';

}

else {

$pagetitle = "Index";

$slider = $cms->getSlider();
$events = $cms->getEvents();

$forms = Form::getList("1 OR 1=1");
$categories = $cms->getCategories();
include 'includes/menu.php';

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
            <div class="container-fluid">

                <!-- Page Heading -->
                <div class="row">
                    <div class="col-lg-12">
                        <h1 class="page-header">
                            Active Forms
                        </h1>
                    </div>
                </div>
                <!-- /.row -->

                <div class="row">
                    <div class="col-lg-12">
                    <!--<h3>To Fill Out:</h2>-->
                    <div class="table-responsive">
                    <?php if ($forms['count'] > 0)  {?>
                        
                        <table class="table table-striped">
                            <thead>
                            <tr>
                                <th>Category</th>
                                <th>Title</th>
                                <th>Due Date</th>
                                <th>Content</th>
                                <th>Actions</th>
                            </tr>
                            </thead>
                            <tbody>
                            <?php
                            foreach ($forms['forms'] as $page) {
                                if ($page->date <= date("Y-m-d")) {
                                    $page->showing = 0;
                                }
                                if (!$page->showing) continue;
                                $category = null;
                                foreach ($categories as $categoryl) {
                                    if ($categoryl['id'] == $page->category)
                                        $category = $categoryl['name'];
                                }
                                $content = strip_tags($page->content);
                                if (strlen($content) > 50) $content = substr($content, 0, 51)."&hellip;"; 
                                echo <<<_END

                            <tr>
                                <td>$category</td>
                                <td>$page->title</td>
                                <td>$page->date</td>
                                <td>$content</td>
                                <td>
                                    <a href="http://dashboard.team1676.com/2/dashboard.php?form=$page->id" class="btn btn-primary btn-xs">Fill Out</a>
                                </td>
                            </tr>
_END;
                            }
                            ?>
                            
                            </tbody>
                        </table>

                    <?php } 
                    else echo "<p>No forms yet!</p>";
                    ?>

                    </div>
                    </div>
                </div>

                <!--<div class="row">
                    <div class="col-lg-12">
                    <h3>Completed:</h2>
                    <div class="table-responsive">
                    <?php if ($forms['count'] > 0)  {?>
                        
                        <table class="table table-striped">
                            <thead>
                            <tr>
                                <th>Category</th>
                                <th>Title</th>
                                <th>Description</th>
                                <th>Actions</th>
                            </tr>
                            </thead>
                            <tbody>
                            <?php
                            foreach ($forms['forms'] as $page) {
                                if ($page->showing) continue;
                                $category = null;
                                $content = strip_tags($page->content);
                                if (strlen($content) > 30) $content = substr($content, 0, 31)."&hellip;"; 
                                echo <<<_END
                            <tr>
                                <td>$page->category</td>
                                <td>$page->title</td>
                                <td>$content</td>
                                <td>
                                    <a href="http://dashboard.team1676.com/2/dashboard.php?form=$page->id&preview=true" class="btn btn-primary btn-xs">View</a>
                                </td>
                            </tr>
_END;
                            }
                            ?>
                            
                            </tbody>
                        </table>

                    <?php } 
                    else echo "<p>No forms yet!</p>";
                    ?>

                    </div>
                    </div>
                </div>-->

            </div>
            <!-- /.container-fluid -->
</div>

</div>

<script>
function refreshAt(hours, minutes, seconds) {
    var now = new Date();
    var then = new Date();

    if(now.getHours() > hours ||
       (now.getHours() == hours && now.getMinutes() > minutes) ||
        now.getHours() == hours && now.getMinutes() == minutes && now.getSeconds() >= seconds) {
        then.setDate(now.getDate() + 1);
    }
    then.setHours(hours);
    then.setMinutes(minutes);
    then.setSeconds(seconds);

    var timeout = (then.getTime() - now.getTime());
    setTimeout(function() { window.location.reload(true); }, timeout);
}

refreshAt(23,59,59); //refreshes the page at 11:59 PM automaticaly 
</script>

<?php

}

include 'includes/templates/footer.php';

?>
      
      
     