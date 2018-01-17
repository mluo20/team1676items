<?php

include 'includes/header.php';
include 'includes/menu.php';

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
?>

            <div class="container-fluid">

                <!-- Page Heading -->
                <div class="row">
                    <div class="col-lg-12">
                        <h1 class="page-header">
                            Feedback
                        </h1>
                        <iframe src="https://docs.google.com/forms/d/e/1FAIpQLScSsEftled7LxPsJBTZenm9ge5yauWMa0Qu9rhVwdE3kCFung/viewform?embedded=true" width="100%" height="600" frameborder="0" marginheight="0" marginwidth="0">Loading...</iframe>
                    </div>
                </div>
                </div>
                </div>

            </div>
            <!-- /.container-fluid -->

<?php

include 'includes/footer.php';

?>