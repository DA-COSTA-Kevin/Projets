<!DOCTYPE html>

<html>
	<head>
		<meta charset = "utf-8">
	    <meta name = "viewport" content = "width=device-width, initial-scale=1">
	    <link rel = "stylesheet" type = "text/css" href = "Ski.css">
	</head>

	<body>
		<?php
			include('EnTete_Resp.html');
			include('connexion.inc.php');
		?>

		<div class = "box">
			<h2> Supprimer un client de votre groupe </h2>
				<form action = "" method = POST>
					<select name = "Idcli">
							<option value = "" selected = "selected"> -- Id client -- </option>
								<?php
									$requete = $cnx->query('SELECT id_client FROM client');
									foreach ($requete as $valeur){
										echo '<option>'.$valeur[id_client].'</option>';
									}
								?>
					</select>
					<select name = "nomcli">
							<option value = "" selected = "selected"> -- Nom client -- </option>
								<?php
									$requete = $cnx->query('SELECT nom FROM client');
									foreach ($requete as $valeur){
										echo '<option>'.$valeur[nom].'</option>';
									}
								?>
					</select>
					<select name = "prenomcli">
							<option value = "" selected = "selected"> -- Prénom client -- </option>
								<?php
									$requete = $cnx->query('SELECT prenom FROM client');
									foreach ($requete as $valeur){
										echo '<option>'.$valeur[prenom].'</option>';
									}
								?>
					</select>
					<br><br>
					<input class = "Valider" type = "submit" name = "Valider1" value = "Valider"/>
				</form>
		</div>

		<?php
			if(isset($_POST['Valider1'])){
				$resultat = $cnx->exec("DELETE FROM reservation WHERE id_client = ".$_POST['Idcli']."");

				echo '<p> Vous avez supprimé '.$_POST['nomcli'].' '.$_POST['prenomcli'].' pour identifiant : '.$_POST['Idcli'];
			}
		?>
	</body>
</html>
