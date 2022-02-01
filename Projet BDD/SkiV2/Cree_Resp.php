<!DOCTYPE html>

<html>
	<head>
		<meta charset = "utf-8">
	    <title> Zarza-ski </title>
	    <meta name = "viewport" content = "width=device-width, initial-scale=1">
	    <link rel = "stylesheet" type = "text/css" href = "Ski.css">

	</head>

	<body>
		<?php
			include('EnTete_Admin.html');
			include('connexion.inc.php');
		?>

		<div class = "box">
			<h2> Création de compte responsable </h2>
				<form action = "" method = POST>
					<select name = "Id">
							<option value = "" selected = "selected"> -- Identifiant -- </option>
								<?php
									$requete = $cnx->query('SELECT id_client FROM client');
									foreach ($requete as $valeur){
										echo '<option>'.$valeur[id_client].'</option>';
									}
								?>
					</select>
					<select name = "Nom">
							<option value = "" selected = "selected"> -- Nom -- </option>
								<?php
									$requete = $cnx->query('SELECT nom FROM client');
									foreach ($requete as $valeur){
										echo '<option>'.$valeur[nom].'</option>';
									}
								?>
					</select>
					<select name = "Prenom">
							<option value = "" selected = "selected"> -- Prénom -- </option>
								<?php
									$requete = $cnx->query('SELECT prenom FROM client');
									foreach ($requete as $valeur){
										echo '<option>'.$valeur[prenom].'</option>';
									}
								?>
					</select>
					<br><br>
					<div class = "inputBox">
						<input type = "password" name = "mdp1" required = "">
						<label> Mot de passe </label>
					</div>
					<div class = "inputBox">
						<input type = "password" name = "mdp2" required = "">
						<label> Confirmez votre mot de passe </label>
					</div>
					<input type = "submit" name = "Valider" value = "Valider">
				</form>
		</div>

		<?php
			if(isset($_POST['Valider'])){

				$Id = $_POST['Id'];
				$nom = $_POST['Nom'];
				$prenom = $_POST['Prenom'];
				$Resp = 'Responsable';
				$mdp = $_POST['mdp1'];
				$log = $nom.$prenom.$Id;

				$requete = $cnx->query('SELECT * FROM client');
				$requete1 = $cnx->query('SELECT * FROM compte');

				if($_POST['mdp1'] != $_POST['mdp2']){
					echo "Vous n'avez pas rentré les memes mot de passe !";
				}

				$reponse = $cnx->prepare('SELECT ndc FROM compte WHERE ndc = "'.$log.'"');
				$reponse->execute();
        $login = $reponse->fetch();

        if($log == $login['ndc']){
            $erreur = "Ce nom d'utilisateur est déjà utilisé";
        }
				else{
					$cnx->exec("INSERT INTO compte(ndc, mdp, rang) VALUES('".$log."', '".$mdp."', '".$Resp."')");
				}

				/*
				$test = -1;
				foreach ($requete as $valeur){
					## si le drapeau n'est pas monté alors on insere la valeur dans la bdd
					if ($test == 0){
						echo 'huuu<br>';
						$cnx->exec("INSERT INTO compte(ndc, mdp, rang) VALUES('".$valeur['nom'].$valeur['prenom'].$Id."', '".$mdp."', '".$Resp."')");
					}
					foreach ($requete1 as $val){
						## si la personne est deja dans le tableau
						if($valeur['nom'].$valeur['prenom'].$Id == $val['ndc']){
							## si le meme mdp et meme ndc on leve le drapeau
							if($mdp == $val['mdp']){
								echo 'meme mdp et meme utilisateur<br>';
								$test = 2;
							}
							else {
								echo 'ERREUR 404 PD<br>';
								$test = 1;
							}
						}
						## sinon on baisse le drapeau et on passe au suivant
						else{
							$test = 0;
							echo 'c bon<br>';
						}
					}
				}*/
			}

			?>
	</body>
</html>
