<?php

$pagetitle = "Post";

include 'includes/header.php';

if ($_SERVER['REQUEST_METHOD'] == "POST") {
    if (empty($_POST['pageorder'])) {
        $forms = Form::getList($_POST['category']);
        $greatestOrder = 0;
        foreach ($forms['forms'] as $page) {
            if ($page->pageorder > $greatestOrder) $greatestOrder = $page->pageorder;
        }
        unset($page);
        $_POST['pageorder'] = $greatestOrder + 1;
    }
    if (empty($_POST['showing']))
        $_POST['showing'] = 0;
    if (empty($_POST['label']))
        $_POST['label'] = $_POST['title'];
    $page = new Form;
    $page->storeFormValues($_POST);
    if (isset($_POST['publish'])) $page->insert();
    if (isset($_POST['save'])) {
        $page->save(); 
        header("Location: edit.php?form=$page->id");
    }
}

$categories = $cms->get_categories();

include 'includes/menu.php';

?>

            <div class="container-fluid">

                <!-- Page Heading -->
                <div class="row">
                    <div class="col-lg-12">
                        <h1 class="page-header">
                            Post New Form
                        </h1>
                        <ol class="breadcrumb">
                            <li>
                                <i class="fa fa-dashboard"></i>  <a href="admin.php">Home</a> / <i class="fa fa-pencil"></i> Post Form
                            </li>
                        </ol>
                    </div>
                </div>
                <!-- /.row -->

                <div class="row">
                <form action="#" method="POST" class="dirty-check" id="contentForm">
                    <div class="col-sm-12">
                    <div class="form-group">
                        <input type="text" name="title" class="form-control input-lg" placeholder="Enter Title (Ex. Week of 1/1 Dinner Order Form)" required="">
                    </div>
                    <div id="content">
                        <!--Iframe Text-Input: <textarea id="render" class="col-md-12"></textarea>-->
                        <!--Default Text-Input: <input class="content form-control" name="content"></input>-->
                        <input class="content form-control" name="content" style="display: none;"></input>
                    </div>              
                    </div>
                    <div class="col-sm-12" style="margin-bottom: 15px;">
                        <h3 style="margin-top: 15px; margin-bottom: 15px;">Form Wizard:</h3>
                        <iframe src="http://dashboard.team1676.com/2/form.html" scrolling="no" id="ifrm" style="width: 100%; height: 450px; margin-bottom: 10px; border-style: ridge; border-color: rgb(204, 204, 204);"></iframe>
                    </div>
                    <div class="col-sm-9">
                        <div class="form-group">
                            <label for="category">Category: </label>
                            <select class="form-control" id="category" name="category">
                                <option value="1">Food</option>
                                <option value="2">Two...</option>
                                <option value="3">Three...</option>
                                <option value="4">Four...</option>
                            </select>
                        </div>
                        <div class="form-group">
                            <label for="date">Due Date: </label>
                            <input class="date form-control" type="date" id="date" name="date" required>
                        </div>
                        <div class="form-group" style="display: none;">
                            <label for="date">Your Email: </label>
                            <input class="date form-control" type="email" id="publisher" name="publisher" required>
                        </div>
                        <div class="form-group" style="display: none;">
                            <label for="label">Form Label (Optional): </label>
                            <input class="form-control" type="text" id="label" name="label">
                        </div>
                    </div>
                    <div class="col-sm-3">
                        <div class="form-group row">
                            <div class="col-xs-2 col-sm-4" style="display: none;">
                                <label for="pageorder">Order: </label>
                                <input class="form-control" type="number" id="pageorder" name="pageorder">
                            </div>
                            <div class="col-xs-8 col-sm-8">
                                <b>Show on "Forms" Page:</b><br>
                                <label class="switch"><input type="checkbox" name="showing" value="1" checked><div class="slider"></div></label>
                            </div>
                        </div>
                        <br>
                        <button type="submit" name="publish" class="btn btn-primary">Publish</button>
                        <button type="submit" name="save" class="btn btn-primary">Save as Draft</button>
                    </div>
                    </form>
                </div>
                <div class="row">
                    <div class="col-lg-12">
                        &nbsp;
                    </div>
                </div>

            </div>
            <!-- /.container-fluid -->

<script>
function getCookie(cname) {
    var name = cname + "=";
    var decodedCookie = decodeURIComponent(document.cookie);
    var ca = decodedCookie.split(';');
    for(var i = 0; i <ca.length; i++) {
        var c = ca[i];
        while (c.charAt(0) == ' ') {
            c = c.substring(1);
        }
        if (c.indexOf(name) == 0) {
            return c.substring(name.length, c.length);
        }
    }
    return "";
}

// attach handlers once iframe is loaded
document.getElementById('ifrm').onload = function() {

    // get reference to form to attach button onclick handlers
    var form = document.getElementById('contentForm');
    
    // reference form element in iframed document
    form.elements.publish.onclick = function() {
        var re = /[^-a-zA-Z!,'"?<>/()\s]-/g; // to filter out unwanted characters
        var ifrm = document.getElementById('ifrm');
        // reference to document in iframe
        var doc = ifrm.contentDocument? ifrm.contentDocument: ifrm.contentWindow.document;
        // get reference to greeting text box in iframed document
        var fld = doc.forms['components'].elements['stuff'];
        var val = fld.value.replace(re, '');
        // display value in text box
        this.form.elements.content.value = val;
        
        var user = getCookie("username");
        if (user == "") {
            alert("Please sign in to publish a form.");
        } else {
            document.getElementById('publisher').value = user;
        }
    }
    
}
</script>

<?php

include 'includes/footer.php';

?>