<div class="container-fluid text-center heading offset">
<div class="row">
<div class="col-lg-10 col-lg-offset-1 col-md-12"><br>
  <h1><?php if (isset($title)) {echo $title; $pagetitle = $title;} ?></h1>
  <!--insert with share links-->
  <div class="text-center" id="share">
  <small>Share this page: <br></small>
  <!-- links are broken -->
    <span class="fa-stack fa-lg">
      <a href="https://www.facebook.com/sharer/sharer.php?u=http%3A//team1676.com<?php echo urlencode($_SERVER['PHP_SELF']."?page=$id");?>" target="_blank"><i class="fa fa-circle fa-stack-2x"></i>
      <i class="fa fa-facebook fa-stack-1x fa-inverse"></i></a>
    </span>
    <span class="fa-stack fa-lg">
      <a href="https://twitter.com/home?status=Check%20out%20this%20from%20the%20Pascack%20Pioneers%20Team%201676!%0A<?php echo urlencode($_SERVER['PHP_SELF']."?page=$id")?>" target="_blank"><i class="fa fa-circle fa-stack-2x"></i>
      <i class="fa fa-twitter fa-stack-1x fa-inverse"></i></a>
    </span>
    <span class="fa-stack fa-lg">
      <a href="https://plus.google.com/share?url=https%3A//team1676.com<?php echo urlencode($_SERVER['PHP_SELF']."?page=$id") ?>" target="_blank"><i class="fa fa-circle fa-stack-2x"></i>
      <i class="fa fa-google-plus fa-stack-1x fa-inverse"></i></a>
    </span>
    <span class="fa-stack fa-lg">
      <a href="mailto:?subject=Pascack+Pioneers+Article&body=Check+out+this+article+by+the+Pascack+Pioneers+Team+1676%21%0A%0A<?php urlencode($_SERVER['PHP_SELF']."?page=$id")?>" target="_blank"><i class="fa fa-circle fa-stack-2x"></i>
      <i class="fa fa-envelope fa-stack-1x fa-inverse"></i></a>
    </span>
    </div>
</div>
</div>

</div>

<div class="layout fr-view">

<div class="container">

  <div class="row">
  <div class="col-lg-6 col-lg-offset-3 col-md-12">
<br><br>

	<style>
	p {
	font-size: 16px;
	}
	</style>
	
    <legend style="border-bottom: 0px;"><b>Published By:&nbsp;&nbsp;</b><a href='mailto:<?php if (isset($publisher)) {echo $publisher;}; ?>'><?php if (isset($publisher)) {echo $publisher;}; ?></a>.</legend>
    <legend style="border-bottom: 0px;"><b>Due Date:&nbsp;&nbsp;</b><?php if (isset($date)) {echo $date;}; ?> @ 11:59pm.</legend>

    <div id="hide">
    <?php
    if (isset($content)) {
      echo $content;
    };
    ?>
    </div>
    
    <div id="show" style="display: none;">
    <img src="http://dashboard.team1676.com/stop.jpg" style="padding-left: 25%; padding-right: 25%;">
    </div>

  </div>
  </div>

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

refreshAt(23,59,01); //refreshes the page at 7:55:00 PM automaticaly (cheat prevention)


window.setInterval(function() {

  var current = new Date();
  var expiry = new Date('<?php if (isset($date)) {echo $date;}; ?> 23:59:00'); //hides the slideshows at 7:54:59 PM automaticaly (cheat prevention)

  if (current.getTime() > expiry.getTime()) {
    $('#hide').hide();
    $('#show').show();
  }
});
</script>