<?php
	//Rob's Viewdata.php
	//Make it so you can view who showed up x days over y amount of time (also make availabe to "query" special days like Mandatory days)
	$mysqli = new mysqli("mysql4.brinkster.com","team1676","Pi~1676_Oneers","team1676");
	

	/*
	$getUsers = "SELECT * FROM attendance_login WHERE id NOT IN (SELECT DISTINCT `uid` FROM attendance_records WHERE 
	`clockin` LIKE '10-29-2014%'
	clockin LIKE '11-03-2014%'
	`clockin` LIKE ''
	OR `clockin` LIKE '11-20-2014%'
	OR `clockin` LIKE '11-25-2014%' ORDER BY `uid` ASC) AND username != '' ORDER BY last ASC";
	$getRes = $mysqli->query($getUsers);*/

	$dates = array();
	$query = "";
	$optionBOriginal = "";
	if(isset($_GET['search1']) || isset($_GET['search2']))
	{
		extract($_POST);
		$optionBOriginal = $optionB;
		if($optionADate1==""&$optionADate2==""&$optionANum==""&$optionB!="")
		{
			$queryStart = "";
			if($optionBNegation=="on")
				$queryStart = "SELECT * FROM attendance_login WHERE id NOT IN (SELECT DISTINCT `uid` FROM attendance_records WHERE ";
			else
				$queryStart = "SELECT * FROM attendance_login WHERE id IN (SELECT DISTINCT `uid` FROM attendance_records WHERE ";
			$queryMiddle = "";
			$queryEnd = ") AND username!= ''";

			while($optionB!="")
			{
				$needle = "/";
				$occurance = strpos($optionB,$needle);
				$date = substr($optionB,0,$occurance)."%";
				if($occurance==false)
				{
					$date = $optionB."%";
					$tempString = "`clockin` LIKE '$date'";
					$queryMiddle = $queryMiddle.$tempString;
					$optionB = "";
				}
				else
				{
					$date = substr($optionB,0,$occurance)."%";
					$tempString = "`clockin` LIKE '$date' OR";
					$queryMiddle = $queryMiddle.$tempString;
					$optionB = substr($optionB,$occurance+1);
				}

				array_push($dates, $date);
			}
		$query = $queryStart.$queryMiddle.$queryEnd;
		}
		else if($optionADate1!=""&$optionADate2!=""&$optionANum!=""&$optionB=="")
		{
			/*
			$getUsers = "SELECT * FROM attendance_login WHERE id NOT IN (SELECT DISTINCT `uid` FROM attendance_records WHERE `clockin` >= 10-29-2014% OR clockin <= 11-03-2014% ORDER BY `uid` ASC) AND username != '' ORDER BY last ASC";
			$getRes = $mysqli->query($getUsers);*/
			//$query = "SELECT * FROM attendance_login WHERE (COUNT (SELECT `uid` FROM attendance_records WHERE `clockin` >= '$optionADate1%' OR clockin <= '$optionADate2%')>$optionANum)";
			$query = "SELECT uid, COUNT(*) AS cnt FROM attendance_records WHERE `clockin` >= '$optionADate1%' AND `clockin` <='$optionADate2%' GROUP BY `uid`";
			//echo $query;
		}
		else
			echo "Invalid submission";
	}
	else
		$query = "SELECT * FROM attendance_records WHERE uid !=''  ORDER BY clockin DESC";
	$result = $mysqli->query($query);
	if(!$result)
	{
		echo "Query failed";
	}
	$loginQuery = "SELECT * FROM attendance_login ORDER BY id";
	$columns = "SHOW COLUMNS FROM attendance_records";
	$colRes = $mysqli->query($columns);
	$resultLogin = $mysqli->query($loginQuery);
	$colArray = array();
	$i=0;

	$userArray = array();
	$userNameArray = array();
	if(isset($_GET['search']))
	{
		//CODE IN PROGRESS
	}
	else
	{
		while($row = $resultLogin->fetch_assoc())
		{
			$userArray[$row['id']] = $row['last'].", ".$row['first'];
		}
		$c = 0;
		while($col = $colRes->fetch_assoc()){
			$curr = $col['Field'];
			if($c==0||$c==1||$c==2||$c==3||$c==10)
			{
		//	echo "<th>$curr</th>";
				$colArray[$i] = $curr;
			}
			else
			{
		//		echo "";
			}
			$i++;
			$c++;
		}
	}

?>
<!doctype html>
	<head>
		<title>View Attandance Data</title>
		<!-- DataTables CSS -->
		<link rel="stylesheet" type="text/css" href="DataTables-1.10.4/media/css/jquery.dataTables.css">
  		<!-- jQuery -->
		<script type="text/javascript" charset="utf8" src="DataTables-1.10.4/media/js/jquery.js"></script>
  		<!-- DataTables -->
		<script type="text/javascript" charset="utf8" src="DataTables-1.10.4/media/js/jquery.dataTables.js"></script>
	</head>
	<body>
		<div id="main">
			<h1 align="center">View Attendance Records</h1><br>
			<h4>Showed up x number of times over y time? (Check box to search who did NOT show up)
			<form action="viewdata.php?search1" method="post">
            	<input type="text" placeholder="Start Date - Ex: 01-19-2015" name="optionADate1" id="optionADate1" /> 
            	<input type="text" placeholder="End Date - Ex: 01-24-2015" name="optionADate2" id="optionADate2" />
            	<input type="number" placeholder="# of Days Present" name="optionANum" od="optionANum" />
            	<input type="checkbox" id="optionANegation" name = "optionANegation" />
            	<input type="submit" value="Search" />
            </form>
            <form action="viewdata.php?search2" method="post">
            	<p>Present on which days? (Check box to search who was NOT present)</p>
           		<input type="text" placeholder="Ex: 01-14-2015/02-14-2015/02-16-2015" name="optionB" id="optionB"/>
           		<input type="checkbox" id="optionBNegation" name = "optionBNegation" />
            	<input type="submit" value="Search" />
            </form>
            </h4>

			<script type="text/javascript">
				$(document).ready( function () {
					var table = $('#logins').DataTable();
    				new $.fn.dataTable.FixedHeader( table, {
       				 bottom: true
    				} );
    			//	$('#logins').DataTable();
				} );
			</script>
			<?php 
				if (isset($_GET['search1'])){ 
					if($optionANegation!="on")
					{ ?>
				<h3 align"left">You Searched for students who attended at least <?php echo $optionANum . " "; ?>meetings between <?php echo $optionADate1 . " and " .  $optionADate2; 
					}
					else
					{ ?>
				<h3 align"left">You Searched for students who did NOT attend at least <?php echo $optionANum . " "; ?>meetings between <?php echo $optionADate1 . " and " .  $optionADate2; 
					}
				?></h3>
				<table id="logins" class="display">
					<thead>
						<tr>
							<th align="left">User</th>
							<th align="left">Number of Times Attended within Range</th>
						</tr>
					</thead>
					<tbody>
						<?php
							$result = $mysqli->query($query);
							while ($row=$result->fetch_assoc()){
								$col=$colArray[1];
								$sumtin = $row["$col"];
								$userName = $userArray[$sumtin];
								if ($userName==", " || $userName==""){}
								else
								{ 
									if($optionANegation!="on")
									{
										if ($row['cnt'] >= $optionANum)
										{
											?>
											<tr>
												<td><?php echo $userName; ?></td>
												<td><?php echo $row['cnt']; ?></td>
											</tr>
									

						<?php			}
									}
									else
									{
										if ($row['cnt'] < $optionANum)
										{
											?>
											<tr>
												<td><?php echo $userName; ?></td>
												<td><?php echo $row['cnt']; ?></td>
											</tr>
						<?php
										}
									}
								}
							}
						?>
					</tbody>
				</table>
			<?php }
				else if (isset($_GET['search2'])){ 
					if($optionBNegation!="on")
					{		?>
			<h3 align = "left">You searched for students who showed up on these dates: <?php echo $optionBOriginal; 
					}
					else
					{?>
			<h3 align = "left">You searched for students who did NOT show up on these dates: <?php echo $optionBOriginal; }?>
			<table id="logins" class="display">
				<thead>
					<tr>
						<th align="left">User</th>
					</tr>
				</thead>
				<tobdy>
					<?php
					$result = $mysqli->query($query);
						while ($row=$result->fetch_assoc())
						{
							$col=$colArray[1];
							$sumtin = $row["$col"];
							$id = $row['id'];
							$userName = $userArray["$id"];
							if ($userName == "," || $userName=="" || $userName == ", " || $userName == " ," || $userName == " , " || $userName == " "){}
							else{
								?>
								<tr>
									<td align="left"><?php echo $userName; ?></td>
								</tr>
					<?php  
						} }
						?>
				</tbody>
			</table>
			<?php }
				else{
			?>
			<table id="logins" class="display">
				<thead>
					<tr>
						<th>User</th>
						<th>Clock In</th>
						<th>Clock Out</th>
						<th>What Student Accomplished</th>
					</tr>
				</thead>
				<tbody>
					<?php
					while($row = $result->fetch_assoc()){
						$col=$colArray[1];
						$sumtin = $row["$col"];
						$userName = $userArray[$sumtin];
						if ($userName==", " || $userName==""){}
						else{
					 ?>
						<tr>
							<td><?php echo $userName; ?></td>
							<td><?php echo $row['clockin']; ?></td>
							<td><?php echo $row['clockout']; ?></td>
							<td><?php echo $row['whatidid']; ?></td>
						</tr>
					<?php } }
					?>
				</tbody>
			</table>
			<?php } ?>
		</div>
	</body>

</html>