<?php

$pagetitle = "News";

include 'includes/header.php';

if (isset($_POST['add'])) {
    $cms->addNews($_POST);
}

if (isset($_POST['update'])) {
    $cms->updateNews($_POST);
    header("Location: news.php");
}

$action = isset($_GET['action']) ? $_GET['action'] : "";

if (isset($_GET['action']) && !isset($_GET['id'])) header("Location: news.php");

if ($action == "delete") {
    $cms->delete("news", $_GET['id']);
    header("Location: news.php");
}
else if ($action == "edit") {
    $article = $cms->getById("news", $_GET['id']);
    $id = $article['id'];
    $etitle = $article['title'];
    $elink = $article['link'];
    $edescription = strip_tags($article['description']);
}

include 'includes/menu.php';

?>

            <div class="container-fluid">

                <!-- Page Heading -->
                <div class="row">
                    <div class="col-lg-12">
                        <h1 class="page-header">
                            News
                        </h1>
                        <ol class="breadcrumb">
                            <li>
                                <i class="fa fa-dashboard"></i>  <a href="admin.php">Home</a>  / <i class="fa fa-fw fa-newspaper-o"></i> News
                            </li>
                        </ol>
                    </div>
                </div>
                <!-- /.row -->

                <div class="row">
                    <div class="col-lg-6 col-sm-offset-3">
                       <h3>Add New</h3>
                       <form action="" method="POST">
                           <?php
                           if ($action == "edit") echo "<input type=\"hidden\" name=\"id\" value=\"$id\">";
                           ?>
                           <div class="form-group row">
                               <div class="col-sm-6">
                                   <label for="title">Title: </label>
                                   <input type="text" name="title" id="title" class="form-control" value="<?php if (isset($etitle)) echo $etitle; ?>" required>
                               </div>
                               <div class="col-sm-6">
                                   <label for="link">Link: </label>
                                   <input type="link" name="link" class="form-control" id="link" value="<?php if (isset($elink)) echo $elink; ?>">
                               </div>
                           </div>
                           <div class="form-group">
                               <label for="description">Description: </label>
                               <textarea class="form-control" name="description" id="description" rows="8" required><?php if (isset($edescription)) echo $edescription; ?></textarea>
                           </div>
                           <?php
                           if ($action == "edit") echo "<button type=\"submit\" name=\"update\" class=\"btn btn-primary\">Update</button>";
                           else echo "<button type=\"submit\" name=\"add\" class=\"btn btn-primary\">Add +</button>";
                           ?>
                       </form>
                    </div>
                </div>
                <div class="row">
                    <div class="col-lg-12">
                    <h2>News</h2>
                    <div class="table-responsive">
                        <table class="table table-striped">
                            <thead>
                            <tr>
                                <th>Date</th>
                                <th>Title</th>
                                <th>Description</th>
                                <th>Link</th>
                                <th>Actions</th>
                            </tr>
                            </thead>
                            <tbody>
                        <?php
                        $news = $cms->getNews();
                        foreach ($news as $article) {
                            $date = date("F j, Y", strtotime($article['date']));
                            $description = strip_tags($article['description']);
                            echo <<<_END
                            <tr>
                                <td>$date</td>
                                <td>{$article['title']}</td>
                                <td>$description</td>
                                <td>{$article['link']}</td>
                                <td>
                                    <a href="news.php?action=delete&id={$article['id']}" class="btn btn-primary btn-xs">Delete</a>
                                    <a href="news.php?action=edit&id={$article['id']}" class="btn btn-primary btn-xs">Edit</a>
                                </td>
                            </tr>
_END;
                        }
                        ?>
                            </tbody>
                        </table>
                    </div>
                    </div>
                </div>
                
                

            </div>
            <!-- /.container-fluid -->

<?php

include 'includes/footer.php';

?>