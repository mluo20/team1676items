<?php
//quick report
include ('connect.inc.php');
$getUsers = "SELECT * FROM attendance_login WHERE id NOT IN (SELECT DISTINCT `uid` FROM attendance_records WHERE 
	/*`clockin` LIKE '10-29-2014%'*/
	/*clockin LIKE '11-03-2014%'*/
	`clockin` LIKE '11-11-2014%'
	/*OR `clockin` LIKE '11-20-2014%'*/
	OR `clockin` LIKE '11-25-2014%' ORDER BY `uid` ASC) AND username != '' ORDER BY last ASC";
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