<?php

require_once 'includes/config.php';

?>
<!DOCTYPE html>
<html lang="en">

<head>

	<title><?php if (isset($pagetitle)) echo htmlspecialchars($pagetitle) . " |" ?>Team 1676 Dashboard</title>
	<link rel="stylesheet" type="text/css" href="bootstrap/css/bootstrap.min.css">
	<link rel="stylesheet" type="text/css" href="https://maxcdn.bootstrapcdn.com/font-awesome/4.7.0/css/font-awesome.min.css">
	<link rel="manifest" href="scripts/manifest.json">
  	<link rel="shortcut icon" type="image/x-icon" href="http://dashboard.team1676.com/favicon.ico" />
 
    <!-- Include Editor style. -->
    <link href="https://cdnjs.cloudflare.com/ajax/libs/froala-editor/2.6.0/css/froala_editor.pkgd.min.css" rel="stylesheet" type="text/css" />
    <link href="https://cdnjs.cloudflare.com/ajax/libs/froala-editor/2.6.0/css/froala_style.min.css" rel="stylesheet" type="text/css" />

	<meta charset="utf-8">
	<meta name="viewport" content="width=device-width, initial-scale=1">
	
	<!-- Global site tag (gtag.js) - Google Analytics -->
<script async src="https://www.googletagmanager.com/gtag/js?id=UA-109504052-2"></script>
<script>
  window.dataLayer = window.dataLayer || [];
  function gtag(){dataLayer.push(arguments);}
  gtag('js', new Date());

  gtag('config', 'UA-109504052-2');
</script>


</head>

<body>

<?php

include 'includes/templates/menu.php';

?>
