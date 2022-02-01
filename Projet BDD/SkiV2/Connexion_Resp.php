<!DOCTYPE html>

<html>
	<head>
		<meta charset = "utf-8">
	    <meta name = "viewport" content = "width=device-width, initial-scale=1">
	    <link rel = "stylesheet" type = "text/css" href = "Ski.css">
	</head>

	<body>
		<?php
			include('EnTete.html');
			include('connexion.inc.php');
		?>

		<div class = "box">
			<h2> Connexion Responsable</h2>
				<form action = "" method = POST>
					<div class = "inputBox">
						<input type = "text" name = "identifiant" required = "">
						<label> Nom de compte </label>
					</div>
					<div class = "inputBox">
						<input type = "password" name = "mdp" required = "">
						<label> Mot de passe </label>
					</div>
					<input type = "submit" name = "Valider" value = "Valider">
				</form>
		</div>

		<?php
			session_start();

			if(isset($_POST['Valider'])) {

				$pseudo = $_POST['identifiant'];
				$pass = $_POST['mdp'];
				$rang = "Responsable";

				if(!empty($pseudo) AND !empty($pass)){
			    	$requete = $cnx->prepare('SELECT ndc, mdp, rang FROM compte WHERE ndc = ? AND mdp = ? AND rang = ?');
			      	$requete->execute(array($pseudo, $pass, $rang));
			      	$resultat = $requete->rowCount();

			     	if($resultat == 1) {
		     			$info = $requete->fetch();
			         	$_SESSION['ndc'] = $info['ndc'];
			         	$_SESSION['mdp'] = $info['mdp'];


			         	if ($_SESSION['rang'] != $info['rang']){
			         		header("Location: Accueil_Resp.php");
			         	}
				    }
			      	else{
			        	echo "Mauvais identifiant ou mot de passe !";
			      	}
			   	}
			   	else{
			    	echo "Tous les champs doivent être complétés !";
			   	}
			}
		?>
	</body>
</html>
