        </div>
        <!-- /#page-wrapper -->

    </div>
    <!-- /#wrapper -->

    <!-- jQuery -->
    <script src="https://ajax.googleapis.com/ajax/libs/jquery/3.2.1/jquery.min.js"></script>

    <!-- Bootstrap Core JavaScript -->
    <script src="../bootstrap/js/bootstrap.min.js"></script>
    <script src="../scripts/jquery.are-you-sure.js"></script>
    <script src="../scripts/ays-beforeunload-shim.js"></script>

    <!-- Include external JS libs. -->
    <!-- <script type="text/javascript" src="https://cdnjs.cloudflare.com/ajax/libs/jquery/1.11.0/jquery.min.js"></script> -->
    <script type="text/javascript" src="https://cdnjs.cloudflare.com/ajax/libs/codemirror/5.25.0/codemirror.min.js"></script>
    <script type="text/javascript" src="https://cdnjs.cloudflare.com/ajax/libs/codemirror/5.25.0/mode/xml/xml.min.js"></script>
 
    <!-- Include Editor JS files. -->
    <script type="text/javascript" src="https://cdnjs.cloudflare.com/ajax/libs/froala-editor/2.6.0/js/froala_editor.pkgd.min.js"></script>
 
    <!-- Initialize the editor. -->
    <script>
    	$(function() { 

        var changed = false;

    		$('textarea.content').froalaEditor({
    			toolbarButtons: ['fullscreen', 'undo', 'redo', '|', 'bold', 'italic', 'underline', 'insertHR', 'paragraphFormat', 'align', 'formatOL', 'formatUL', 'quote', '|', 'insertLink', 'insertImage', 'insertVideo', 'insertFile'],
                theme: 'dark',
                height: 360,
                imageUploadURL: '../scripts/save_image.php',
                fileUploadURL: '../scripts/upload_file.php',
                videoUploadURL: '../scripts/upload_video.php',
                imageManagerPageSize: 20,
                imageManagerScrollOffset: 10,
                imageManagerLoadURL: "../scripts/load_images.php",
                imageManagerLoadMethod: "GET",
                imageManagerDeleteURL: "../scripts/delete_image.php",
                imageManagerDeleteMethod: "POST"
    		}).on('froalaEditor.image.removed', function (e, editor, $img) {
                $.ajax({
                  method: "POST",
                  url: "../scripts/delete_image.php",
                  data: {
                    src: $img.attr('src')
                  }
                })
                .done (function (data) {
                  console.log ('image was deleted');
                })
                .fail (function () {
                  console.log ('image delete problem');
                })
            }).on('froalaEditor.file.unlink', function (e, editor, link) {
                $.ajax({
                  method: "POST",
                  url: "../scripts/delete_file.php",
                  data: {
                    src: link.attributes[1].value
                  }
                })
            }).on('froalaEditor.video.removed', function (e, editor, $video) {
                $.ajax({
                  method: "POST",
                  url: "../scripts/delete_video.php",
                  data: {
                    src: $video.find("video").attr('src')
                  }
                })
            }).on('froalaEditor.contentChanged', function (e, editor) {
                changed = true;
            });

            $('form.dirty-check').areYouSure();

            // var forms = document.getElementsByTagName("form")

            // for (var i = 0; i < forms.length; i++) {
            //   setAttribute("class", "democlass");
            // }

            var submitting = false;

            $( "form" ).submit(function( ) {
              submitting = true;
            });

            //for the froala editor
            window.onbeforeunload = function(e) {
              if (changed && !submitting) {
                var dialogText = 'You have unsaved changes.';
                e.returnValue = dialogText;
                return dialogText;
              }
            };

    	}); 
    </script>

</body>

</html>
