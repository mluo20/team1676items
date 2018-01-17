//When "Old Sign-In" button clicked:
function signOut() {
  //changes visual appearance of sign-in form (new to old)
  document.getElementById("showButton").style.bottom = "100%";
  document.getElementById("hideButton").style.bottom = "100%";
  document.getElementById("hideButton2").style.display = "block";
  document.getElementById("center-me").style.display = "none";
  document.getElementById("bod").style.position = "static";
}


//When "New Sign-In" button clicked:
function viewNew() {
  //changes vvisual appearance of sign-in form (old to new)
  document.getElementById("showButton").style.bottom = "0px";
  document.getElementById("hideButton").style.bottom = "0px";
  document.getElementById("hideButton2").style.display = "none";
  document.getElementById("center-me").style.display = "block";
  document.getElementById("bod").style.position = "fixed";
}


//When "Sign Out" link clicked:
function justSignOut() {
  //signs user out of Google auto-fill
  var auth2 = gapi.auth2.getAuthInstance();
  auth2.signOut().then(function () {
    console.log('User signed out.');
    document.cookie = "username=; expires=Thu, 01 Jan 1970 00:00:00 UTC; path=/;";
  });
}


//Creates LogIn Cookie
function setCookie(cname, cvalue, exdays) {
    var d = new Date();
    d.setTime(d.getTime() + (exdays * 24 * 60 * 60 * 1000));
    var expires = "expires="+d.toUTCString();
    document.cookie = cname + "=" + cvalue + ";" + expires + ";path=/";
}

  
//When information from Google is sent and verified:
function onSignIn(googleUser) {
  //Useful data for our client-side scripts:
  var profile = googleUser.getBasicProfile();
  
  var email = profile.getEmail();
  setCookie("username", email, 7);
  
  document.getElementById("action-buttons").style.display = "block";
  document.getElementById("goog").style.display = "none";
        
  //Google "Sign-In" Id
  var pass = profile.getId().substring(0, 8);
  document.getElementById("pwd").value = pass;
  document.getElementById("pwd2").value = pass;
  document.getElementById("pwd3").value = pass;
        
  //Full Name
  console.log('Full Name: ' + profile.getName());
  document.getElementById("welcome-message").innerHTML = ("Not " + profile.getName() + "?");
  document.getElementById("welcome-message2").innerHTML = ("Sign Out");
  
  //First Name
  console.log('Given Name: ' + profile.getGivenName());
  document.getElementById("fName").value = profile.getGivenName();
  var welcom = document.getElementById("welcome");
  welcom.innerHTML = ("Hello, " + profile.getGivenName() + "!");
        
  //Last Name
  console.log('Family Name: ' + profile.getFamilyName());
  document.getElementById("lName").value = profile.getFamilyName();
        
  //Image
  console.log("Image URL: " + profile.getImageUrl());
  document.getElementById("profile").src = profile.getImageUrl();
        
  //Email
  console.log("Email: " + profile.getEmail());
  var use = profile.getEmail().substring(0, profile.getEmail().length - 12);
  document.getElementById("email").value = use;
  document.getElementById("email2").value = profile.getEmail();
  document.getElementById("email3").value = use;
};
      
//something else I dont want to delete      
/*(function ($) {
  var FakePoller = function(options, callback){
  var defaults = {
			frequency: 60,
			limit: 10
		};
		this.callback = callback;
		this.config = $.extend(defaults, options);
		this.list = [
			'Ryan Hall',
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
*/
               