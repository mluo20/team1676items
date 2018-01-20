jQuery(window).load(function() {
    
  /* Navigation */

	jQuery('#main-menu > ul').superfish({ 
		delay:       500,								// 0.1 second delay on mouseout 
		animation:   { opacity:'show',height:'show'},	// fade-in and slide-down animation 
		dropShadows: true								// disable drop shadows 
	});	  

	jQuery('#main-menu > ul').mobileMenu({
		prependTo:'.mobilenavi'
	});
	

});

	


( function() {
	var is_webkit = navigator.userAgent.toLowerCase().indexOf( 'webkit' ) > -1,
	    is_opera  = navigator.userAgent.toLowerCase().indexOf( 'opera' )  > -1,
	    is_ie     = navigator.userAgent.toLowerCase().indexOf( 'msie' )   > -1;

	if ( ( is_webkit || is_opera || is_ie ) && 'undefined' !== typeof( document.getElementById ) ) {
		var eventMethod = ( window.addEventListener ) ? 'addEventListener' : 'attachEvent';
		window[ eventMethod ]( 'hashchange', function() {
			var element = document.getElementById( location.hash.substring( 1 ) );

			if ( element ) {
				if ( ! /^(?:a|select|input|button|textarea)$/i.test( element.tagName ) )
					element.tabIndex = -1;

				element.focus();
			}
		}, false );
	}
})();

	if (!$(".portfolio_grid").hasClass("done")){

		$(".portfolio_grid").isotope({
			itemSelector: '.mix',
			layoutMode: 'fitRows'
		});

		$(' .portfolio_grid > div ').each( function() { $(this).hoverdir(); } );
		
		$(".portfolio_grid").magnificPopup({
	        delegate: 'a',
	        type: 'inline',
	        removalDelay: 300,
	        mainClass: 'my-mfp-slide-bottom'
	    });

	    $(".portfolio_grid").addClass("done");
	}

    $('.portfolio_selector li').on('click', function(){
	    $('.portfolio_selector li').removeClass('active');
	    $(this).addClass('active');

    	var selector = $(this).attr('data-filter');
		$('.portfolio_grid').isotope({
			filter: selector
		});
		return false;
    });

	//portfolio type selector
	$('.quickview_portfolio_item').magnificPopup({
	    image: {
	      markup: 	'<div class="quickview_content">'+
	                	'<div class="row">'+
		                    '<div class="col-md-12 top">'+
		                        '<div class="mfp-img item_image"></div>'+
		                        '<iframe class="item_video" width="560" height="315" src="" style="border:none;" allowfullscreen></iframe>'+
		                    '</div>'+
		                    '<div class="col-md-12 bottom">'+
		                        '<h3 class="title"></h3>'+
					            '<p class="project_description"></p>'+
					            '<div class="line">'+
					                '<a href="#" class="project_link">Go to project</a>'+
					                '<div class="share">'+
					                    '<span class="project_share_text">or share it</span>'+
					                    '<a href="#" class="fa fa-twitter twitter_link"></a>'+
					                    '<a href="#" class="fa fa-facebook facebook_link"></a>'+
					                    '<a href="#" class="fa fa-youtube youtube_link"></a>'+
					                    '<div class="clear"></div>'+
					               '</div>'+
					            '</div>'+
		                    '</div>'+
	                  	'</div>'+
	              	'</div>', 
	      titleSrc: 'title',
	      verticalFit: true
	    },
	    type: 'image',
	    callbacks: {
	        open: function() {
	            var instance = $.magnificPopup.instance;
	            var current_item = instance.st.el;
	            var title = current_item.attr('data-title');
	            var client_name = current_item.attr('data-client-name');
	            var date = current_item.attr('data-date');
	            var description = current_item.attr('data-description');
	            var link = current_item.attr('data-link');
	            var link_text = current_item.attr('data-link-text');
	            var share_text = current_item.attr('data-share-text');
	            var twitter_url = current_item.attr('data-twitter-url');
	            var facebook_url = current_item.attr('data-facebook-url');
	            var youtube_url = current_item.attr('data-youtube-url');
	            var video_url = current_item.attr('data-video-url');
	            $('.quickview_content .title').text(title);
	            $('.quickview_content .client_name').text(client_name);
	            $('.quickview_content .project_date').text(date);
	            $('.quickview_content .project_description').text(description);
	            $('.quickview_content .project_link').attr("src", link);
	            $('.quickview_content .project_link').text(link_text);
	            $('.quickview_content .project_share_text').text(share_text);
	            $('.quickview_content .twitter_link').attr("href", twitter_url);
	            $('.quickview_content .facebook_link').attr("href", facebook_url);
	            $('.quickview_content .youtube_link').attr("href", youtube_url);

	            if (current_item.is(".is_video")){
	            	$('.quickview_content .item_image').css("display", "none !important");
	            	$('.quickview_content .item_video').css("display", "block !important");
            	  	$('.quickview_content .item_video').attr("src", video_url);
	            }else{
	            	$('.quickview_content .item_image').css("display", "block !important");
	            	$('.quickview_content .item_video').css("display", "none !important");
	            }
	        }
	    }
	});
