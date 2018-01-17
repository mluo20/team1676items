<?php

$pagetitle = "Edit";

include 'includes/header.php';

if (!isset($_GET['page'])) header("Location: pages.php");
if (empty($_GET['page'])) header("Location: pages.php");
if (isset($_GET['action'])) { 
    $page = Page::getById($_GET['page']); 
    $page->delete(); 
    header("Location: pages.php"); 
}

$editing = Page::getById($_GET['page']);

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
    if (isset($_POST['publish'])) {
        $editing->storeFormValues($_POST);
        $editing->showing = 1;
        $editing->update();
        header("Location: ../index?page=$editing->id");
    }
    if (isset($_POST['save'])) {
        $editing->storeFormValues($_POST);
        $editing->update();
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
                            Edit Page
                        </h1>
                        <ol class="breadcrumb">
                            <li>
                                <i class="fa fa-dashboard"></i>  <a href="admin.php">Dashboard</a> / <i class="fa fa-pencil"></i> Edit
                            </li>
                        </ol>
                    </div>
                </div>
                <!-- /.row -->

                <div class="row">
                <form action="" method="POST" class="dirty-check">
                    <div class="col-sm-9">
                    <div class="form-group">
                        <input type="text" name="title" class="form-control input-lg" placeholder="Enter title" value="<?php echo $editing->title; ?>" required>
                    </div>
                    <div id="content">
                        <textarea class="content" name="content"><?php echo $editing->content; ?></textarea>      
                    </div>              
                    </div>
                    <div class="col-sm-3">
                        <button type="submit" name="save" class="btn btn-primary">Save</button>
                        <a href="../index.php?page=<?php echo $editing->id."&preview=true"; ?>" target="_blank">Preview</a>
                        <div class="form-group">
                        <br>
                            <label for="category">Category: </label>
                            <select class="form-control" id="category" name="category">
                                <?php
                                for ($i = 0; $i < count($categories); $i++) { 
                                    extract($categories[$i]);

                                    echo "<option value=\"$id\" ";
                                    if ($id == $editing->category) echo "selected";
                                    echo ">$name</option>\n";
                                }
                                ?>
                            </select>
                        </div>
                        <div class="form-group">
                            <label for="label">Link Label (leave blank to be the same as the title of the page): </label>
                            <input class="form-control" type="text" id="label" name="label" value="<?php echo $editing->label; ?>">
                        </div>
                        <div class="form-group row">
                            <div class="col-xs-2 col-sm-4">
                                <label for="pageorder">Order: </label>
                                <input class="form-control" type="number" id="pageorder" name="pageorder" value="<?php echo $editing->pageorder; ?>">
                            </div>
                            <div class="col-xs-8 col-sm-8">
                                <b>Show on Menu?</b><br>
                                <label class="switch"><input type="checkbox" name="showing" value="1" <?php if ($editing->showing) echo "checked"; ?>><div class="slider"></div></label>
                            </div>
                        </div>
                        <?php
                        if (!$editing->showing)
                         echo "<button type=\"submit\" name=\"publish\" class=\"btn btn-primary\">Publish</button>";
                        ?>
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