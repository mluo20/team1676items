<html>
<head>
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

body{
    background:#444;
}

.leaderboard {
    position:relative;
    width:40%;
    height:70%;
    max-width:960px;
    min-width:100px;
    min-height:600px;
    margin: 30px auto 0 auto;
    padding:3%;
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
    width:40%;
    margin:3px auto 0 auto;
    min-width:100px;

}

.content ul{
    margin:0;
    padding:0;
    list-style: none;
    border:5px solid #CCC;
    background: rgba(40,40,40,0.75);
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
    color:#F00;
    font-weight:bold;
}
.count:after{
    content:' Likes';
    color:#CCC;
    font-size:80%;
    font-weight:normal;
}


/********* BLING **********/
.content ul{
    border-radius: 20px;
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
<script src="jquery-3.2.1.min.js"></script>
<script src="https://ajax.googleapis.com/ajax/libs/jquery/3.2.1/jquery.min.js"></script>
</head>

<body>
<div class='leaderboard'>
    <h1><span>Leader Board</span></h1>
    <div class="content"></div>
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
			'Game of Thrones',
			'The Walking Dead',
			'Survivor',
			'Dead Like Me',
			'Being Human',
			'American Idol',
			'X Factor',
			'Firefly',
			'SGU',
			'Battlestar Galactica',
			'Farscape',
			'The Mentalist',
			'True Blood',
			'Dexter',
			'Rick Astley'
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
</body>

</html>