/*
~~~~~~~~~~~~~~~~~~~~~~~~~
------1. TOP MENU-------
~~~~~~~~~~~~~~~~~~~~~~~~~
*/

var cbpAnimatedHeader = (function() {

	var docElem = document.documentElement,
		header = document.querySelector( '.top-menu' ),
		didScroll = false,
		changeHeaderOn = 25;

	function init() {
		window.addEventListener( 'scroll', function( event ) {
			if( !didScroll ) {
				didScroll = true;
				setTimeout( scrollPage, 0 );
			}
		}, false );
	}

	function scrollPage() {
		var sy = scrollY();
		if ( sy >= changeHeaderOn ) {
			classie.add( header, 'top-menu-shrink' );
		}
		else {
			classie.remove( header, 'top-menu-shrink' );
		}
		didScroll = false;
	}

	function scrollY() {
		return window.pageYOffset || docElem.scrollTop;
	}

	init();

})();



			(function(){

			  var parallax = document.querySelectorAll(".parallax"),
			      speed = 0.60;

			  window.onscroll = function(){
			    [].slice.call(parallax).forEach(function(el,i){

			      var windowYOffset = window.pageYOffset,
			          elBackgrounPos = "60% " + (windowYOffset * speed) + "px";

			      el.style.backgroundPosition = elBackgrounPos;

			    });
			  };

			})();





/*
~~~~~~~~~~~~~~~~~~~~~~~~~
-----2. BOTTOM MENU------
~~~~~~~~~~~~~~~~~~~~~~~~~
*/

(function() {

	var bodyEl = document.body,
		content = document.querySelector( '.content-wrap' ),
		openbtn = document.getElementById( 'bottom-menu-open-button' ),
		closebtn = document.getElementById( 'bottom-menu-close-button' ),
		isOpen = false;

	function init() {
		initEvents();
	}

	function initEvents() {
		openbtn.addEventListener( 'click', toggleMenu );
		if( closebtn ) {
			closebtn.addEventListener( 'click', toggleMenu );
		}

	}

	function toggleMenu() {
		if( isOpen ) {
			classie.remove( bodyEl, 'bottom-menu-show-menu' );
		}
		else {
			classie.add( bodyEl, 'bottom-menu-show-menu' );
		}
		isOpen = !isOpen;
	}

	init();

})();