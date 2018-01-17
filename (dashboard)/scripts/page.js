$(function() {

    var newHash      = "",
        $mainContent = $("#main-content"),
        $pageWrap    = $("#pagewrap"),
        baseHeight   = 0,
        $el;
        
    $pageWrap.height($pageWrap.height());
    baseHeight = $pageWrap.height() - $mainContent.height();
    
    $("nav").delegate("a", "click", function() {
        _link = $(this).attr("href");
        history.pushState(null, null, _link);
        loadContent(_link);
        return false;
    });

    function loadContent(href){
        $mainContent
                .find("#the-beef")
                .fadeOut(200, function() {
                    $mainContent.hide().load(href + " #the-beef", function() {
                        $mainContent.fadeIn(200, function() {
                            $pageWrap.animate({
                                height: baseHeight + $mainContent.height() + "px"
                            });
                        });
                    });
                });
    }
    
    $(window).bind('popstate', function(){
       _link = location.pathname.replace(/^.*[\\\/]/, '');
       loadContent(_link);
    });

    
});