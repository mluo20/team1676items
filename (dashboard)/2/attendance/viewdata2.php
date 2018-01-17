<?php
    

	$mysqli = new mysqli("mysql4.brinkster.com","team1676","Pi~1676_Oneers","team1676");
	$query = "SELECT * FROM attendance_records WHERE uid !=''  ORDER BY uid,clockin DESC";
	$result = $mysqli->query($query);
	$loginQuery = "SELECT * FROM attendance_login ORDER BY id";

	$columns = "SHOW COLUMNS FROM attendance_records";
	$colRes = $mysqli->query($columns);
	$resultLogin = $mysqli->query($loginQuery);
	$colArray = array();
	$i=0;

	$userArray = array();
	$userNameArray = array();
	
	while($row = $resultLogin->fetch_assoc())
	{
		$userArray[$row['id']] = $row['last'].", ".$row['first'];
	}
	/*while($row = $resultLogin->fetch_assoc())
	{
		$last = $row['last'];
		$first = $row['first'];
		$userArray[$counter] = $last+","+$first;
		$counter++;
	}
	echo $userArray[2];*/

?>

<!doctype html>
	<head>
	<script type="text/javascript" src="jquery-2.1.3.min.js"></script>
	<!--<script type="text/javascript" src="jquery-latest.js"></script> -->
	<script type="text/javascript" src="jquery.tablesorter.js">
	$(document).ready(function() 
    { 
        $(".myTable").tablesorter(); 
    } 

	); 
	</script>
		<title>View Data</title>
	<!--<style>
	table td {
  	border-left:solid 30px transparent;
  	border: 1px solid black;
    border-collapse: collapse;
	}
	table td:first-child {
  	border-left:0;
	}
	</style>-->
	</head>
	<body>
		<div id="main">
			<h1 align="center">View Data</h1>
			<table class="myTable" id="data" class="tablesorter">
				<tr>
				<thead>
					<?php
						$c = 0;
						while($col = $colRes->fetch_assoc()){
							$curr = $col['Field'];
							if($c==0||$c==1||$c==2||$c==3||$c==10)
							{
								echo "<th>$curr</th>";
								$colArray[$i] = $curr;
							}
							else
							{
								echo "";
							}
							$i++;
							$c++;
						}
					?>
				</thead>
				</tr>
				<tbody>
					<?php
					$j=0;
					while($row = $result->fetch_assoc()){
						$j=0;
						if ($j == 0){
							echo "<tr>";
							$col = $colArray[$j];
							echo "<td>";
							$sumtin = $row["$col"];
							echo "$sumtin";
							echo "</td>";
						}
						for ($j = 0; $j<$i; $j++){
							if($j==1)
							{
								$col = $colArray[$j];
								echo "<td>";
								$sumtin = $row["$col"];
								$userName = $userArray[$sumtin];
								echo "$userName";
								echo "</td>";
							}
							else if($j==2||$j==3||$j==10)
							{
							$col = $colArray[$j];
							echo "<td>";
							$sumtin = $row["$col"];
							echo "$sumtin</td>";
							}
						}
						if ($j == $i){
							echo "</tr>";
						}
					}
				?>
			</tbody>
			</table>
		</div>
	</body>
</html>