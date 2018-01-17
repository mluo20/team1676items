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

} else if (isset($_GET['form'])) {

  if (empty($_GET['form']));

  $page = Form::getById($_GET['form']);

  if (($page->showing == 0 && !(isset($_GET['preview']) && $_GET['preview'])) || !isset($_SESSION['authorized'])) ;
  
  $id = $page->id;
  $title = $page->title;
  $content = $page->content;
  $publisher = $page->publisher;
  $date = $page->date;

  include 'includes/templates/form.php';

} else {

$pagetitle = "Index";

$slider = $cms->getSlider();
$events = $cms->getEvents();
$links = $cms->getLinks();

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
<h1><a href="dashboard.html"><b>The Pascack Pioneers Dashboard</b></a></h1>

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
</style>

<div id="news">
    <a id="clockInOutLinkButton" href="attendance.php" class="btn custom_button">
        <p id="clockInOutButton" style="margin: 0 0 0px;"></p>
    </a>

    <?php
      foreach ($links as $link2) {
          extract($link2);
          if (!empty($link)) $l = "<a href=\"$link\" target=\"_blank\" class=\"btn custom_button\">"; else $l = "";
      echo <<<_END
      	      $l
	          <p style="margin: 0 0 0px;">$title</p>
	      </a>
_END;
      }
      ?> 
      <br>
      <br>
</div>

<div id="news">

	<h2 class="page-header white">Latest News</h2>
	<div class="row">

  <?php
  $news = Article::getList(3);
  foreach ($news['articles'] as $article) {

    $date = date("F j, Y", strtotime($article->date));
    $description = nl2br($article->description);
    $readmore = $article->link == "" ? "" : "<a href=\"$article->link\" class=\"btn btn-md\" target=\"_blank\">More Info</a>";

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

      
      <style>
      /* CSS - Shea Parker */

/********* BASE **********/
*, *:before, *:after {
    box-sizing: border-box;
    -moz-box-sizing: border-box;
    -webkit-box-sizing: border-box;
}

body,html {
    min-height:100%;
}


.leaderboard {
    top: 20px;
    height:70%;
    max-width:960px;
    min-width:200px;
    overflow: hidden;
    max-height: 290px;
}

.leaderboard h1{
    text-align: center;
    text-transform: uppercase;
    margin:30px;
    padding:0;
    color: #cc7713;
}

.content {
    position:relative;
    margin:3px auto 0 auto;
    min-width:150px;
    right: 0px;

}

.content ul{
    margin:0;
    padding:0;
    list-style: none;
    border:3px solid #e9e901;
    background: #101010;
}
.content ul li{
    position: relative;
    color:#FFF;
    font-family: helvetica;
    padding:2% 5%;
    border-bottom: 1px solid #555;
}

.content ul li:last-child{
    border-bottom:none;
}

.name{
    font-weight:bold;
}
.count{
    display:inline-block;
    float:right;
    color:#e9e901;
    font-weight:bold;
}
.count:after{
    content:' Hours';
    color:#CCC;
    font-size:80%;
    font-weight:normal;
}


/********* BLING **********/
.content ul{
    border-radius: 2px;
}

.animate {
    -moz-animation: flashIt 0.2s ease 1;
    -webkit-animation: flashIt 0.2s ease 1;
    animation: flashIt 0.2s ease 1;
}

.animate .countold{
    -moz-animation: spinIt 0.3s ease 1;
    -webkit-animation: spinIt 0.3s ease 1;
    animation: spinIt 0.3s ease 1;
}


@-moz-keyframes flashIt {
    100% { opacity: 0; background-color: #FFF;}
}
@-webkit-keyframes flashIt {
    100% { opacity: 0; background-color: #FFF;}
}
@keyframes flashIt {
    100% { opacity: 0; }
}

@-moz-keyframes spinIt {
    20% {-moz-transform: rotate(-10deg)}
    40% {-moz-transform: rotate(10deg)}
    60% {-moz-transform: rotate(-10deg)}
    80% {-moz-transform: rotate(10deg)}
    100% {-moz-transform: rotate(-10deg)}
}
@-webkit-keyframes spinIt {
    20% {-webkit-transform: rotate(-10deg)}
    40% {-webkit-transform: rotate(10deg)}
    60% {-webkit-transform: rotate(-10deg)}
    80% {-webkit-transform: rotate(10deg)}
    100% {-webkit-transform: rotate(-10deg)}
}
@keyframes spinIt {
     20% {transform: rotate(-10deg)}
     40% {transform: rotate(10deg)}
     60% {transform: rotate(-10deg)}
     80% {transform: rotate(10deg)}
     100% {transform: rotate(-10deg)}
 }


      </style>
      
            <h2 class="page-header white">Attendance Stats</h2>   
              <div class='leaderboard'>
	        <div class="content"></div>
              </div>
            <p style="color: rgba(255, 255, 255, 0); font-size: 7px;">yet</p>
		</div>
	</div>	

</div>

</div>

<script>
(function ($) {
  var FakePoller = function(options, callback){
  var defaults = {
			frequency: 60,
			limit: 10
		};
		this.callback = callback;
		this.config = $.extend(defaults, options);
		this.list = [
			'1. Ryan Hall',
			'2. ',
			'3. ',
			'4. ',
			'5. ',
			'6. ',
			'7. ',
			'8. '
		];
	}
	FakePoller.prototype.getData = function() {
		var results = [];
		for (var i = 0, len = this.list.length; i < len; i++) {
			results.push({
				name: this.list[i],
				count: rnd(0, 2000)
			});
		}
		return results;
	};
	FakePoller.prototype.processData = function() {
		return this.sortData(this.getData()).slice(0, this.config.limit);
	};

	FakePoller.prototype.sortData = function(data) {
		return data.sort(function(a, b) {
			return b.count - a.count;
		});
	};
	FakePoller.prototype.start = function() {
		var _this = this;
		this.interval = setInterval((function() {
			_this.callback(_this.processData());
		}), this.config.frequency * 1000);
		this.callback(this.processData());
		return this;
	};
	FakePoller.prototype.stop = function() {
		clearInterval(this.interval);
		return this;
	};
	window.FakePoller = FakePoller;

	var Leaderboard = function (elemId, options) {
		var _this = this;
		var defaults = {
			limit:10,
			frequency:15
		};
		this.currentItem = 0;
		this.currentCount = 0;
		this.config = $.extend(defaults,options);

		this.$elem = $(elemId);
		if (!this.$elem.length)
			this.$elem = $('<div>').appendTo($('body'));

		this.list = [];
		this.$content = $('<ul>');
		this.$elem.append(this.$content);

		this.poller = new FakePoller({frequency: this.config.frequency, limit: this.config.limit}, function (data) {
			if (data) {
				if(_this.currentCount != data.length){
					_this.buildElements(_this.$content,data.length);
				}
				_this.currentCount = data.length;
				_this.data = data;
				_this.list[0].$item.addClass('animate');
			}
		});

		this.poller.start();
	};

	Leaderboard.prototype.buildElements = function($ul,elemSize){
		var _this = this;
		$ul.empty();
		this.list = [];

		for (var i = 0; i < elemSize; i++) {
			var item = $('<li>')
				.on("animationend webkitAnimationEnd oAnimationEnd",eventAnimationEnd.bind(this) )
				.appendTo($ul);
			this.list.push({
			

$item: item,
               $name: $('<span class="name">Loading...</span>').appendTo(item),
               $count: $('<span class="count">Loading...</span>').appendTo(item)
           });
		}

		function eventAnimationEnd (evt){
			this.list[this.currentItem].$name.text(_this.data[this.currentItem].name);
			this.list[this.currentItem].$count.text(_this.data[this.currentItem].count);
			this.list[this.currentItem].$item.removeClass('animate');
			this.currentItem = this.currentItem >= this.currentCount - 1 ? 0 : this.currentItem + 1;
			if (this.currentItem != 0) {
				this.list[this.currentItem].$item.addClass('animate');
			}
		}
	};

	Function.prototype.bind = function(){
		var fn = this, args = Array.prototype.slice.call(arguments),
			object = args.shift();
		return function(){
			return fn.apply(object,args.concat(Array.prototype.slice.call(arguments)));
		};
	};

	window.Leaderboard = Leaderboard;
	//Helper
	function rnd (min,max){
		min = min || 100;
		if (!max){
			max = min;
			min = 1;
		}
		return	Math.floor(Math.random() * (max-min+1) + min);
	}

	function numberFormat(num) {
		return num.toString().replace(/\B(?=(\d{3})+(?!\d))/g, ",");
	}
})(jQuery);

$(document).ready(function ($) {
	var myLeaderboard = new Leaderboard(".content", {limit:8,frequency:8});
});

               
</script>

<?php

}

include 'includes/templates/footer.php';

?>
      
      
     