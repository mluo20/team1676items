/**
 * main4.js
 * http://www.codrops.com
 *
 * Licensed under the MIT license.
 * http://www.opensource.org/licenses/mit-license.php
 * 
 * Copyright 2014, Codrops
 * http://www.codrops.com
 */
(function() {

	var bodyEl = document.body,
		content = document.querySelector( '.content-wrap' ),
		openbtn = document.getElementById( 'bottom-menu-open-button' ),
		closebtn = document.getElementById( 'bottom-menu-close-button' ),
		isOpen = false,

		morphEl = document.getElementById( 'bottom-menu-morph-shape' ),
		s = Snap( morphEl.querySelector( 'svg' ) );
		path = s.select( 'path' );
		initialPath = this.path.attr('d'),
		steps = morphEl.getAttribute( 'data-morph-open' ).split(';');
		stepsTotal = steps.length;
		isAnimating = false;

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
		if( isAnimating ) return false;
		isAnimating = true;
		if( isOpen ) {
			classie.remove( bodyEl, 'bottom-menu-show-menu' );
			// animate path
			setTimeout( function() {
				// reset path
				path.attr( 'd', initialPath );
				isAnimating = false; 
			}, 300 );
		}
		else {
			classie.add( bodyEl, 'bottom-menu-show-menu' );
			// animate path
			var pos = 0,
				nextStep = function( pos ) {
					if( pos > stepsTotal - 1 ) {
						isAnimating = false; 
						return;
					}
					path.animate( { 'path' : steps[pos] }, pos === 0 ? 400 : 500, pos === 0 ? mina.easein : mina.elastic, function() { nextStep(pos); } );
					pos++;
				};

			nextStep(pos);
		}
		isOpen = !isOpen;
	}

	init();

})();