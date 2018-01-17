<?php

$pagetitle = "Forms";

include 'includes/header.php';

$forms = Form::getList("1 OR 1=1");
$categories = $cms->getCategories();
include 'includes/menu.php';
?>

            <div class="container-fluid">

                <!-- Page Heading -->
                <div class="row">
                    <div class="col-lg-12">
                        <h1 class="page-header">
                            View Emails
                        </h1>
                        <ol class="breadcrumb">
                            <li>
                                <i class="fa fa-dashboard"></i>  <a href="admin.php">Dashboard</a>  / <i class="fa fa-fw fa-file-text"></i> Emails
                            </li>
                        </ol>
                    </div>
                </div>
                <!-- /.row -->

                <div class="row">
                    <div class="col-lg-12">
                    <h3>On the menu</h2>
                    <div class="table-responsive">
                    <?php if ($forms['count'] > 0)  {?>
                        
                        <table class="table table-striped">
                            <thead>
                            <tr>
                                <th>Category</th>
                                <th>Order</th>
                                <th>Title</th>
                                <th>Content</th>
                                <th>Link Label</th>
                                <th>Actions</th>
                            </tr>
                            </thead>
                            <tbody>
                            <?php
                            foreach ($forms['forms'] as $page) {
                                if (!$page->showing) continue;
                                $category = null;
                                foreach ($categories as $categoryl) {
                                    if ($categoryl['id'] == $page->category)
                                        $category = $categoryl['name'];
                                }
                                $content = strip_tags($page->content);
                                if (strlen($content) > 50) $content = substr($content, 0, 51)."&hellip;"; 
                                echo <<<_END
                            <tr>
                                <td>$category</td>
                                <td>$page->pageorder</td>
                                <td>$page->title</td>
                                <td>$content</td>
                                <td>$page->label</td>
                                <td>
                                    <a href="edit1.php?form=$page->id" class="btn btn-primary btn-xs">Edit</a>
                                    <a href="../dashboard.php?form=$page->id" class="btn btn-primary btn-xs">View</a>
                                    <a href="edit1.php?form=$page->id&action=delete" class="btn btn-primary btn-xs">Delete</a>
                                </td>
                            </tr>
_END;
                            }
                            ?>
                            
                            </tbody>
                        </table>

                    <?php } 
                    else echo "<p>No forms yet!</p>";
                    ?>

                    </div>
                    </div>
                </div>

                <div class="row">
                    <div class="col-lg-12">
                    <h3>Drafts/Hidden</h2>
                    <div class="table-responsive">
                    <?php if ($forms['count'] > 0)  {?>
                        
                        <table class="table table-striped">
                            <thead>
                            <tr>
                                <th>Category</th>
                                <th>Order</th>
                                <th>Title</th>
                                <th>Content</th>
                                <th>Link Label</th>
                                <th>Actions</th>
                            </tr>
                            </thead>
                            <tbody>
                            <?php
                            foreach ($forms['forms'] as $page) {
                                if ($page->showing) continue;
                                $category = null;
                                $content = strip_tags($page->content);
                                if (strlen($content) > 30) $content = substr($content, 0, 31)."&hellip;"; 
                                echo <<<_END
                            <tr>
                                <td>$page->category</td>
                                <td>$page->pageorder</td>
                                <td>$page->title</td>
                                <td>$content</td>
                                <td>$page->label</td>
                                <td>
                                    <a href="edit1.php?form=$page->id" class="btn btn-primary btn-xs">Edit</a>
                                    <a href="edit1.php?form=$page->id&action=delete" class="btn btn-primary btn-xs">Delete</a>
                                    <a href="../dashboard.php?form=$page->id&preview=true" class="btn btn-primary btn-xs">View</a>
                                </td>
                            </tr>
_END;
                            }
                            ?>
                            
                            </tbody>
                        </table>

                    <?php } 
                    else echo "<p>No forms yet!</p>";
                    ?>

                    </div>
                    </div>
                </div>

            </div>
            <!-- /.container-fluid -->

<?php

include 'includes/footer.php';

?>