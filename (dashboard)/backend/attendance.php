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

                        <h2>Attendance</h2>
                        <iframe src="http://dashboard.team1676.com/backend/report2.php" width="100%" height="650" frameBorder="0">Browser not compatible.</iframe>
                    </div>
                </div>
                </div>
                </div>

            </div>
            <!-- /.container-fluid -->

<?php

include 'includes/footer.php';

?>