<!DOCTYPE html>

<html>
	<head>
		<meta charset = "utf-8">
	    <meta name = "viewport" content = "width=device-width, initial-scale=1">
	    <link rel = "stylesheet" type = "text/css" href = "Ski.css">
	</head>

	<body>
		<?php
			include('EnTete_Admin.html');
			include('connexion.inc.php');
		?>

		<div class = "box">
			<h2> Création de groupe </h2>
				<form action = "" method = POST>
					<div class = "inputBox">
						<input type = "text" name = "Groupe" required = "">
					 	<label> Nom Groupe </label>
					</div>
					<div class = "inputBox">
						<input type = "text" name = "Type" required = "">
			 			<label> Type de Groupe (F/G) </label>
			 		</div>
					<input type = "submit" name = "Valider" value = "Valider">
				</form>
		</div>

		<?php
			if(isset($_POST['Valider'])){
				$Nom_gp = $_POST['Groupe'];
				$Type_gp = $_POST['Type'];

				$cnx->exec("INSERT INTO groupe(nom_gp, type_gp) VALUES('".$Nom_gp."', '".$Type_gp."')");

				echo 'Le groupe'.$Nom_gp.'de type'.$Type_gp.'a été crée !';
			}
		?>
	</body>
</html>
