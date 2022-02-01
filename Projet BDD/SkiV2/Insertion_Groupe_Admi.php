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
			include("connexion.inc.php");
		?>

		<div class = "box">
			<h2> Insérer un membre </h2>
				<form action = "" method = POST>
					<div class = "inputBox">
			 			<input type = "text" name = "Idgp" required = "" >
			 			<label> Id Groupe </label>
			 		</div>
			 		<div class = "inputBox">
						<input type = "text" name = "Idcli" required = "">
						<label> Id Client </label>
					</div>
					<div class = "inputBox">
						<input type = "text" name = "Date_deb" required = "">
						<label> Date de début du séjour </label>
					</div>
					<div class = "inputBox">
			 			<input type = "text" name = "Date_fin" required = "">
			 			<label> Date de Fin du séjour </label>
			 		</div>
			 		<div class = "inputBox">
			 			<input type = "text" name = "niv_pref" required = "">
			 		 	<label> Niveaux de préférence (0 à 4)</label>
			 		 </div>
					<input class = "Valider" type = "submit" name = "Valider" value = "Valider"/>
				</form>
		</div>

		<?php
			if(isset($_POST['Valider'])){
				$idgp = $_POST['Idgp'];
				$idcli = $_POST['Idcli'];
				$Date_deb = $_POST['Date_deb'];
				$Date_fin = $_POST['Date_fin'];
				$niv_pref = $_POST['niv_pref'];
				$id_formule = 0;
				$num_chambre = 0;

				$requete = $cnx->query('SELECT id_client FROM reservation');

				//foreach ($requete as $valeur){
				//	if('$valeur[id_client]' != $idcli){
						$requete1 = $cnx->exec("INSERT INTO reservation(date_debut, date_fin, niv_pref, id_client, id_formule, id_gp, num_chambre)
												VALUES ('".$Date_deb."','".$Date_fin."','".$niv_pref."','".$idcli."','".$id_formule."','".$idgp."','".$num_chambre."')");

						if ($requete1 == 0){
						echo "Erreur!";
						}
						else{
							echo "Insertion réussit";
						}
					}
					//else {
						//echo "Ce client est déja dans le groupe";
					//}
				//}
			//}

		?>
	</body>
</html>
