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
  <div class="col-lg-10 col-lg-offset-1 col-md-12">
<br><br>

	<style>
	p {
	font-size: 16px;
	}
	</style>

    <?php
    if (isset($content)) {
      echo $content;
    };
    ?>

  </div>
  </div>

</div>

</div>