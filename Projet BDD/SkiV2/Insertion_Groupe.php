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
			<h2> Insérer un membre </h2>
				<form action = "" method = POST>
					<select name = "Idgp">
							<option value = "" selected = "selected"> -- Id groupe -- </option>
								<?php
									$requete = $cnx->query('SELECT id_gp FROM groupe');
									foreach ($requete as $valeur){
										echo '<option>'.$valeur[id_gp].'</option>';
									}
								?>
					</select>
					<select name = "Nomgp">
							<option value = "" selected = "selected"> -- Nom groupe -- </option>
								<?php
									$requete = $cnx->query('SELECT nom_gp FROM groupe');
									foreach ($requete as $valeur){
										echo '<option>'.$valeur[nom_gp].'</option>';
									}
								?>
					</select>
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
					<br><br>
					<div class = "inputBox">
						<input type = "text" name = "Date_deb" required = "">
						<label> Date de début du séjour </label>
					<div class = "inputBox">
			 			<input type = "text" name = "Date_fin" required = "">
			 			<label> Date de Fin du séjour </label>
			 		</div>
					<input type = "submit" name = "Valider" value = "Valider"/>
				</form>
		</div>

		<?php
			if(isset($_POST['Valider'])){
				$Idgp = $_POST['Idgp'];
				$Idcli = $_POST['Idcli'];
				$Date_deb = $_POST['Date_deb'];
				$Date_fin = $_POST['Date_fin'];
				$niv_pref = 0;
				$id_formule = 0;
				$num_chambre = 0;

				$requete = $cnx->query('SELECT * FROM reservation');

				/*foreach ($requete as $valeur){
					if(){*/
						$requete1 = $cnx->exec("INSERT INTO reservation(date_debut, date_fin, niv_pref, id_client, id_formule, id_gp, num_chambre)
												VALUES ('".$Date_deb."','".$Date_fin."','".$niv_pref."','".$Idcli."','".$id_formule."','".$Idgp."','".$num_chambre."')");
						/*if ($requete1 == 0){
						echo "Erreur!";
						}
						else{
							echo "Insertion réussit";
						}
					}
				}*/
			}

		?>
	</body>
</html>
