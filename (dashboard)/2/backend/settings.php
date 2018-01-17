<?php

$pagetitle = "Settings";

include 'includes/header.php';
include 'includes/menu.php';

//maybe make all into functions?
//also make all into 2d arrays

$events = $cms->getEvents();

//get slider pics
$slider = $cms->getSlider();

//get categories
$categories = $cms->getCategories();

if (isset($_POST['delete'])) {
    extract($_POST);
    $query = "DELETE FROM $table WHERE id = $id";
    $result = $conn->query($query);
    // header("Location: settings.php?message=1");
    if (!$result) echo "<p>Something went wrong.<br>" . $conn->error ."</p>";
    if ($table == "slider_pics") {
        if (file_exists($origurl)) {
             unlink($origurl);
        }
    }
}

if (isset($_POST['edit'])) {
    extract($_POST);
    $query = "SELECT * FROM $table WHERE id = $id";
    $result = $conn->query($query);
    if (!$result) echo "<p>Something went wrong.<br>" . $conn->error ."</p>";
    $rows = $result->num_rows;
    
    for ($i = 0; $i < $rows; $i++) {
        $result->data_seek($i);
        $row = $result->fetch_array(MYSQL_ASSOC);
        $l = $row['id'];
        if ($table == "categories") {
            $o = $row['catorder'];
            $n = $row['name'];
        }
        else if ($table == "slider_pics") {
            $o = $row['slider_order'];
            $li = $row['link'];
            $u = $row['url'];
            $des = $row['description'];
        }
        else if ($table == "events") {
            $etitle = $row['title'];
            $edate = $row['date'];
            $dateend = $row['date_end'];
            $edescription = $row['description'];
            $elink = $row['link'];
        }
    }
    echo $l;
}

//events
if (isset($_POST['event'])) {
    extract($_POST);

    if ($event == "update")
        $query = "UPDATE events SET title = '$eventtitle', date = '$datefrom', date_end = '$dateto', description = '$eventdesc', link = '$eventlink' WHERE id = $id";
    else 
        $query = "INSERT INTO events (title, date, date_end, description, link) VALUES ('$eventtitle', '$datefrom', '$dateto', '$eventdesc', '$eventlink') ";
    $result = $conn->query($query);
    // header("Location: settings.php?message=1");
    if (!$result) echo "<p>Something went wrong.<br>" . $conn->error ."</p>";
}

//slider

if (isset($_POST['slider_pics'])) {

    extract($_POST);

    //image upload stuff
    $target_dir = "images/";
    $target_file = "../".$target_dir . basename($_FILES["url"]["name"]);
    $uploadOk = 1;
    $imageFileType = pathinfo($target_file, PATHINFO_EXTENSION);

    if (!empty($_FILES["url"]["tmp_name"])) {
        // Check if image file is a actual image or fake image
        $check = getimagesize($_FILES["url"]["tmp_name"]);
        if($check !== false) {
            $uploadOk = 1;
        } else {
            echo "File is not an image.";
            $uploadOk = 0;
        }
        // Check if file already exists
        if (file_exists($target_file)) {
            unlink($target_file);
        }
        // Check file size
        // if ($_FILES["url"]["size"] > 500000) {
        //     echo "Sorry, your file is too large.";
        //     $uploadOk = 0;
        // }
        // Allow certain file formats
        if($imageFileType != "jpg" && $imageFileType != "png" && $imageFileType != "jpeg"
        && $imageFileType != "gif" ) {
            echo "Sorry, only JPG, JPEG, PNG & GIF files are allowed.";
            $uploadOk = 0;
        }
        // Check if $uploadOk is set to 0 by an error
        if ($uploadOk == 0) {
            echo "Sorry, your file was not uploaded.";
        // if everything is ok, try to upload file
        } 
        else {
            if (move_uploaded_file($_FILES["url"]["tmp_name"], $target_file)) {
                echo "<p>The file ". basename( $_FILES["url"]["name"]). " has been uploaded.</p>";
            } else {
                echo "<p>Sorry, there was an error uploading your file.</p>";
            }
        }
        $url = $target_dir . basename($_FILES["url"]["name"]);
        if ($slider_pics == "update" && $url != $origurl) {
            if (file_exists($origurl)) {
                unlink($origurl);
            }
        }
    }
    else $url = $origurl;

    if ($slider_pics == "update") {
        $query = "UPDATE slider_pics SET url = '$url', description = '$description', link = '$link', slider_order = $slider_order WHERE id = $id";
    }

    else {
        //insert stuff
        $query = "INSERT INTO slider_pics (url, description, link, slider_order) VALUES ('$url', '$description', '$link', $slider_order) ";
    }
        $result = $conn->query($query);
        // header("Location: settings.php?message=1");
        if (!$result) echo "<p>Something went wrong.<br>" . $conn->error ."</p>";

}

//category
if (isset($_POST['category'])) {
    extract($_POST);
    $insert = 1;
    if ($category == "update") {
        $query = "UPDATE categories SET name = '$name', catorder = '$catorder' WHERE id = $id";
        $result = $conn->query($query);
        // header("Location: settings.php?message=1");
        if (!$result) echo "<p>Something went wrong.<br>" . $conn->error ."</p>";
    }
    else {
        for ($i = 0; $i < count($categories); $i++) { 
            if (($catorder == $categories[$i]['catorder'] || $name == $categories[$i]['name']) && ($category != "update")) {
                $error = "<div class=\"alert alert-danger\">You cannot have a category with the same order number or name as an existing one.</div>";
                $insert = 0;
            }
        }
        if ($insert) {
            $query = "INSERT INTO categories (name, catorder) VALUES ('$name', $catorder) ";
            $result = $conn->query($query);
            // header("Location: settings.php?message=1");
            if (!$result) echo "<p>Something went wrong.<br>" . $conn->error ."</p>";
        }
    }
}
?>

            <div class="container-fluid">

                <!-- Page Heading -->
                <div class="row">
                    <div class="col-lg-12">
                        <h1 class="page-header">
                            Settings
                        </h1>
                        <ol class="breadcrumb">
                            <li>
                                <i class="fa fa-dashboard"></i>  <a href="admin.php">Dashboard</a>  / <i class="fa fa-fw fa-wrench"></i> Settings
                            </li>
                        </ol>
                    </div>
                </div>
                <!-- /.row -->

                <?php
                if (isset($error)) {
                echo <<<_END
                <div class="row">
                    <div class="col-lg-12">
                        $error
                    </div>
                </div>
_END;
                }
                ?>

                <div class="row">
                    <div class="col-sm-6">
                    <div class="panel panel-default">
                        <div class="panel-heading">
                            Categories
                        </div>
                        <div class="panel-body">
                            <table class="table table-striped">
                                <thead>
                                <tr>
                                    <th>Order</th>
                                    <th>Name</th>
                                    <th>Actions</th>
                                </tr>
                                </thead>
                                <tbody>
                                <?php
                                for ($i = 0; $i < count($categories); $i++) { 
                                    extract($categories[$i]);
                                    echo <<<_END
                                <tr>
                                    <td>$catorder</td>
                                    <td>$name</td>
                                    <td>
                                        <form action="" method="POST">
                                        <input type="hidden" name="id" value="$id">
                                        <input type="hidden" name="table" value="categories">
                                        <button type="submit" name="delete" class="btn btn-primary btn-xs">Delete</button>
                                        <button type="submit" name="edit" class="btn btn-primary btn-xs">Edit</button>
                                    </td>
                                    </form>
                                </tr>
_END;
                                }
                                ?>
                                </tbody>
                            </table>
                            <form action="" method="POST">
                            <?php
                            if (isset($l)) echo "<input type=\"hidden\" name=\"id\" value=\"$l\">";
                            ?>
                                <div class="form-group row">
                                    <div class="col-xs-3 col-sm-2">
                                    <label for="catorder">Order: </label> <input type="number" name="catorder" id="catorder" class="form-control input-sm" value="<?php if (isset($o)) echo $o; else echo $categories[count($categories) - 1]['catorder'] + 1;?>" required>
                                    </div>
                                <!-- </div> -->
                                <!-- <div class="form-group"> -->
                                    <div class="col-xs-5 col-sm-4">
                                    <label for="name">Name: </label> <input type="text" name="name" id="name" class="form-control input-sm" value="<?php if (isset($n)) echo $n;?>" required>
                                    </div>
                                </div>
                                <button type="submit" name="category" <?php if (isset($n)) echo "value=\"update\""?> class="btn btn-primary"><?php if (isset($n)) echo "Update"; else echo "Add +"?></button>
                            </form>
                        </div>
                    </div>
                    </div>
                    <div class="col-sm-6">
                    <div class="panel panel-default">
                        <div class="panel-heading">
                            Slider Pictures
                        </div>
                        <div class="panel-body">
                        <div class="table-responsive">
                            <table class="table table-striped">
                                <thead>
                                <tr>
                                    <th>Order</th>
                                    <th>Picture</th>
                                    <th>Description</th>
                                    <th>Link</th>
                                    <th>Actions</th>
                                </tr>
                                </thead>
                                <tbody>
                                <?php
                                for ($i = 0; $i < count($slider); $i++) { 
                                    extract($slider[$i]);
                                    echo <<<_END
                                <tr>
                                    <td>$slider_order
                                    <td><img src="../$url" width="100px"></td>
                                    <td>$description</td>
                                    <td>$link</td>
                                    <td>
                                        <form action="" method="POST">
                                        <input type="hidden" name="id" value="$id">
                                        <input type="hidden" name="table" value="slider_pics">
                                        <input type="hidden" name="origurl" value="$url">
                                        <button type="submit" name="delete" class="btn btn-primary btn-xs">Delete</button>
                                        <button type="submit" name="edit" class="btn btn-primary btn-xs">Edit</button>
                                    </td>
                                    </form>
                                </tr>
_END;
                                }
                                ?>
                                </tbody>
                            </table>
                            </div>
                            <form action="" method="POST" enctype="multipart/form-data" class="form">
                            <input type="hidden" name="id" value="<?php if (isset($l)) echo $l; ?>">
                            <input type="hidden" name="origurl" value="<?php if (isset($u)) echo $u;?>">
                                <div class="form-group row">
                                    <div class="col-xs-3 col-sm-2">
                                    <label for="slider_order">Order: </label> <input type="number" name="slider_order" id="slider_order" class="form-control input-sm" value="<?php if (isset($o)) echo $o; else echo $slider[count($slider) - 1]['slider_order'] + 1; ?>" required>
                                    </div>
                                <!-- </div> -->
                                <!-- <div class="form-group"> -->
                                    <div class="col-xs-5 col-sm-6">
                                    <label for="url">Picture (note, all pictures the same dimensions and should be 1919 x 659): </label> <input type="file" name="url" id="url" <?php if (!isset($li)) echo "required" ?>>
                                    </div>
                                </div>
                                <div class="form-group">
                                    <label for="description">Description: </label> <input type="text" name="description" id="description" class="form-control input" value="<?php if (isset($des)) echo $des; ?>">
                                </div>
                                <div class="form-group">
                                    <label for="link">Link: </label> <input type="url" name="link" id="link" class="form-control input" value="<?php if (isset($li)) echo $li ;?>">
                                </div>
                                <button type="submit" name="slider_pics" class="btn btn-primary" <?php if (isset($li)) echo "value=\"update\""?> class="btn btn-primary"><?php if (isset($li)) echo "Update"; else echo "Add +"?></button>
                            </form>
                        </div>
                    </div>
                    </div>
                </div>

                <div class="row" id="events">
                <div class="col-lg-12">
                <div class="panel panel-default">
                    <div class="panel-heading">
                        Events
                    </div>
                    <div class="panel-body">
                        <div class="col-sm-6">
                        <h2>Upcoming events</h2>
                        <ul class="list-group">
                        <?php

                        foreach ($events as $event) {
                            extract($event);
                            if (!is_null($date_end) && $date_end != "0000-00-00") $fulldate = date("m/d/Y", strtotime($date)) . " &ndash; " . date("m/d/Y", strtotime($date_end)); else $fulldate = date("m/d/Y", strtotime($date)); 
                            if (!empty($link)) $lin = "<a href=\"$link\" target=\"_blank\">Read more &raquo;</a>"; else $lin = "";
                            //maybe use google calendar as link instead, and have the external link a button
                        echo <<<_END
                            <li class="list-group-item">
                                <h4 class="list-group-item-heading">($fulldate) $title</h4>
                                <p class="list-group-item-text">$description</p>
                                $lin
                            </li>
                            <form action="#events" method="POST">
                                <input type="hidden" name="id" value="$id">
                                <input type="hidden" name="table" value="events">
                                <button type="submit" name="delete" class="btn btn-primary btn-xs">Delete</button>
                                <button type="submit" name="edit" class="btn btn-primary btn-xs">Edit</button>
                            </form>
_END;
                        }
                        ?>  
                        </ul>

                        </div>
                        <div class="col-sm-6">
                            <form method="POST" action="#events">
                                <input type="hidden" name="id" value="<?php if (isset($l)) echo $l; ?>">
                                <div class="form-group">
                                    <label for="eventtitle">Title: </label>
                                    <input type="text" name="eventtitle" id="eventtitle" class="form-control" value="<?php if (isset($etitle)) echo $etitle; ?>" required>
                                </div>
                                <div class="form-group row">
                                    <div class="col-lg-6">
                                        <label for="datefrom">Date (from): </label>
                                        <input type="date" name="datefrom" id="datefrom" class="form-control" value="<?php if (isset($edate)) echo $edate; ?>" required>
                                    </div>
                                    <div class="col-lg-6">
                                        <label for="dateto">Date (to, leave blank if one day only): </label>
                                        <input type="date" name="dateto" id="dateto" class="form-control" value="<?php if (isset($dateend)) echo $dateend; ?>">
                                    </div>
                                </div>
                                <div class="form-group">
                                    <label for="eventdesc">Description: </label>
                                    <input type="text" name="eventdesc" id="eventdesc" class="form-control" value="<?php if (isset($edescription)) echo $edescription; ?>">
                                </div>
                                <div class="form-group">
                                    <label for="eventlink">External Link: </label>
                                    <input type="link" name="eventlink" id="eventlink" class="form-control" value="<?php if (isset($elink)) echo $elink; ?>">
                                </div>
                                <button type="submit" name="event" class="btn btn-primary" <?php if (isset($etitle)) echo "value=\"update\""?>><?php if (isset($etitle)) echo "Update"; else echo "Add +"?></button>
                            </form>
                        </div>
                    </div>
                </div>
                </div>
                </div>

            </div>
            <!-- /.container-fluid -->

<?php

include 'includes/footer.php';

?>