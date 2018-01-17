<?php

$pagetitle = "Post";

include 'includes/header.php';

if ($_SERVER['REQUEST_METHOD'] == "POST") {
    if (empty($_POST['pageorder'])) {
        $pages = Page::getList($_POST['category']);
        $greatestOrder = 0;
        foreach ($pages['pages'] as $page) {
            if ($page->pageorder > $greatestOrder) $greatestOrder = $page->pageorder;
        }
        unset($page);
        $_POST['pageorder'] = $greatestOrder + 1;
    }
    if (empty($_POST['showing']))
        $_POST['showing'] = 0;
    if (empty($_POST['label']))
        $_POST['label'] = $_POST['title'];
    $page = new Page;
    $page->storeFormValues($_POST);
    if (isset($_POST['publish'])) $page->insert();
    if (isset($_POST['save'])) {
        $page->save(); 
        header("Location: edit.php?page=$page->id");
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
                            Post New
                        </h1>
                        <ol class="breadcrumb">
                            <li>
                                <i class="fa fa-dashboard"></i>  <a href="admin.php">Home</a> / <i class="fa fa-pencil"></i> Post
                            </li>
                        </ol>
                    </div>
                </div>
                <!-- /.row -->

                <div class="row">
                <form action="" method="POST" class="dirty-check">
                    <div class="col-sm-9">
                    <div class="form-group">
                        <input type="text" name="title" class="form-control input-lg" placeholder="Enter title" required="">
                    </div>
                    <div id="content">
                        <textarea class="content" name="content"></textarea>      
                    </div>              
                    </div>
                    <div class="col-sm-3">
                        <button type="submit" name="save" class="btn btn-primary">Save as Draft</button>
                        <div class="form-group">
                        <br>
                            <label for="category">Category: </label>
                            <select class="form-control" id="category" name="category">
                                <?php
                                for ($i = 0; $i < count($categories); $i++) { 
                                    extract($categories[$i]);
                                    echo "<option value=\"$id\">$name</option>\n";
                                }
                                ?>
                            </select>
                        </div>
                        <div class="form-group">
                            <label for="label">Link Label (leave blank to be the same as the title of the page): </label>
                            <input class="form-control" type="text" id="label" name="label">
                        </div>
                        <div class="form-group row">
                            <div class="col-xs-2 col-sm-4">
                                <label for="pageorder">Order: </label>
                                <input class="form-control" type="number" id="pageorder" name="pageorder">
                            </div>
                            <div class="col-xs-8 col-sm-8">
                                <b>Show on Menu?</b><br>
                                <label class="switch"><input type="checkbox" name="showing" value="1" checked><div class="slider"></div></label>
                            </div>
                        </div>
                        <button type="submit" name="publish" class="btn btn-primary">Publish</button>
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

<?php

include 'includes/footer.php';

?>