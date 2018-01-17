<?php
	$mysqli = new mysqli("localhost","team1676","Pi~1676_Oneers","team1676");

	$query1 = "SELECT * FROM attendance_login  ORDER BY last ASC, first ASC";
	$query2 = "SELECT * FROM attendance_records WHERE clockin LIKE '%2017%' ORDER BY uid ASC, id ASC";
	

	$result1 = $mysqli->query($query1);
	$result2 = $mysqli->query($query2);
//	$alt = $result1;


	?>
	<html>
	<head>
		<title>Attendance Report</title>

	</head>
	<body>
		<h1 algin="center">Attendance Report</h1>
		<table border="1">
			<tr>
				<th>Name</th>
				<th>Clock In</th>
				<th>Clock Out</th>
				<th>What I Did Today</th>
			</tr>
	<?php
		while ($row2 = $result2->fetch_assoc()){
			$uid = $row2['uid'];
			$query3 = "SELECT * FROM attendance_login WHERE id = '$uid'";
			$result = $mysqli->query($query3);
			while ($row1 = $result->fetch_assoc()){
				//if ($row2['uid'] == $row1['id']){
					echo "<tr>";
					echo "<td>" . $row1['last'] . ", " . $row1['first'] . "</td>";
					echo "<td>" . $row2['clockin'] . "</td>";
					echo "<td>" . $row2['clockout'] . "</td>";
					echo "<td>" . $row2['whatidid'] . "</td>";
					echo "</tr>";
				//}
			}
		}

?>
	</table>
	</body>
	</html>