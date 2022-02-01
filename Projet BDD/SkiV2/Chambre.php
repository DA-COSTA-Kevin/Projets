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
				<h2> Insertion chambre </h2>
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
						<br><br>
					<select name = "num_chambre">
							<option value = "" selected = "selected"> -- N° chambre -- </option>
								<?php
									$requete = $cnx->query('SELECT num_chambre FROM chambre');
									foreach ($requete as $valeur){
										echo '<option>'.$valeur[num_chambre].'</option>';
									}
								?>
					</select>
					<br><br>
					<select name = "niv_pref">
							<option value = "" selected = "selected"> -- Niveaux de préférence -- </option>
								<?php
									$requete = $cnx->query('SELECT niv_pref FROM preference');
									foreach ($requete as $valeur){
										echo '<option>'.$valeur[niv_pref].'</option>';
									}
								?>
					</select>
					<br><br>
					<input type = "submit" name = "Valider" value = "Valider">
			</form>
		</div>

		<?php
			if(isset($_POST['Valider'])){

				$Id = $_POST['Idcli'];
				$niv_pref = $_POST['niv_pref'];
				$num_chambre = $_POST['num_chambre'];
				$res = 0;
				$res1 = 0;

				$requete = $cnx->exec("SELECT count(num_chambre) as compteur FROM reservation WHERE num_chambre = $num_chambre ");
				foreach ($requete as $valeur) {
					$res = $valeur['compteur'];
					echo $res;
				}

				$requete1 = $cnx->exec("SELECT capactié FROM chambre WHERE num_chambre = $num_chambre"); ## A MODIFIER LE CAPACTIE
				foreach ($requete1 as $valeur) {
					$res1 = $valeur['capactié'];
					echo $res1;
				}

				if ($res < $res1){
					$resultat = $cnx->exec("UPDATE reservation SET niv_pref = $niv_pref, num_chambre = $num_chambre WHERE id_client = $Id");
				}
				else {
					echo "Il n'y a plus de place dans la chambre choisie";
				}
			}
		?>
	</body>
</html>
