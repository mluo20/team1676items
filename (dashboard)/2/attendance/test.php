<?php
//quick report
include ('connect.inc.php');
$getUsers = "SELECT * FROM attendance_login WHERE id IN (SELECT DISTINCT `uid` FROM attendance_records WHERE COUNT(`uid`)) AND username != ''";
$getRes = $mysqli->query($getUsers);

?>

<h1 align="center">Users who have missed all 5 pi-techs</h1>
<p align="center">
<?php
	
	while ($rows = $getRes->fetch_assoc()){
		echo $rows['last'] . ", " . $rows['first'] . "<br>";
	}
?>
</p>