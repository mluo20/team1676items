`<style>

 	
   </style>
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
<br><br>
<h1><a href="dashboard.html"><b>The Pascack Pioneers Dashboard</b></a></h1>

</div> -->

<div class="container">
<h1>Pi-Tech Presentations:</h1><br>
<div id="news">

<div id="hide">
<iframe src="https://docs.google.com/a/pascack.org/presentation/d/e/2PACX-1vTw9rmM3XKdNuFgCQ-9HxEOhF7_rjR_GApsALkJPiwIPZ_3QPj6Lhht_izaFeP73lFrqqdreI1JS_VA/embed?start=false&loop=false&delayms=15000" frameborder="0" width="100%" height="65%" allowfullscreen="true" mozallowfullscreen="true" webkitallowfullscreen="true" style="margin-bottom: 20px;"></iframe>

<iframe src="https://docs.google.com/presentation/d/e/2PACX-1vSpgfuPtYy4SkejHiVV2GFwZFCsHqPLobZ7kYRyXEhkEsuVOCc3Iwl5T1ptEy_shX2vIx-G6NjRdsq_/embed?start=false&loop=false&delayms=15000" frameborder="0" width="100%" height="65%" allowfullscreen="true" mozallowfullscreen="true" webkitallowfullscreen="true" style="margin-bottom: 20px;"></iframe>

<iframe src="https://docs.google.com/presentation/d/e/2PACX-1vTJY3fYhblKszf1lH9dT6ciKLHm7MPA425dJb5kkAcXR1x_SOuQhM98xK5C6wkXK-qo5S8I_TMnpJZ0/embed?start=false&loop=false&delayms=15000" frameborder="0" width="100%" height="65%" allowfullscreen="true" mozallowfullscreen="true" webkitallowfullscreen="true" style="margin-bottom: 20px;"></iframe>

<iframe src="https://docs.google.com/presentation/d/e/2PACX-1vSRJS8jyFxo8Jv3M-vc8PYUMzOeJ5JJeEKmXwtUTyjWLh_7r71C2Xd3FbXmEXlwjaB5nWpwnC0jIxsj/embed?start=false&loop=false&delayms=15000" frameborder="0" width="100%" height="65%" allowfullscreen="true" mozallowfullscreen="true" webkitallowfullscreen="true" style="margin-bottom: 20px;"></iframe>

<iframe src="https://docs.google.com/presentation/d/e/2PACX-1vQDrk43FAc6JgCR2MGZ_3YTZCx4Rq8V3y0EQIZKxIUic9hgzmkfhALt5frvOlMfagyyfW8vH50GDAVe/embed?start=false&loop=false&delayms=15000" frameborder="0" width="100%" height="65%" allowfullscreen="true" mozallowfullscreen="true" webkitallowfullscreen="true" style="margin-bottom: 20px;"></iframe>

<iframe src="https://docs.google.com/presentation/d/e/2PACX-1vTebyh0v4GYd-0dorydR8vDLAfHpneykFphurkHQDIR_ol0Ffpy5Y6UHxl2LppWhh5Tz0a1xV6i2w_l/embed?start=false&loop=false&delayms=15000" frameborder="0" width="100%" height="65%" allowfullscreen="true" mozallowfullscreen="true" webkitallowfullscreen="true" style="margin-bottom: 20px;"></iframe>
</div>
</div>

<div id="show" style="display: none;">
<img src="http://dashboard.team1676.com/stop.jpg" style="padding-left: 25%; padding-right: 25%;">
<h3>The Pi-Tech exam is now in session. Please don&apos;t try to cheat! Good Luck!</h3>
<p>(Presentations will reappear tonight sometime after the exam.)</p>
</div>

</div>

<!--
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

refreshAt(19,55,00); //refreshes the page at 7:55:00 PM automaticaly (cheat prevention)


window.setInterval(function() {

  var current = new Date();
  var expiry = new Date('December 7, 2017 19:54:59'); //hides the slideshows at 7:54:59 PM automaticaly (cheat prevention)

  if (current.getTime() > expiry.getTime()) {
    $('#hide').hide();
    $('#show').show();
  }
});
</script>
-->

<?php

}

include 'includes/templates/footer.php';

?>
      
      
     