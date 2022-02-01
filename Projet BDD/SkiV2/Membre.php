<!DOCTYPE html>

<html>
	<head>
		<meta charset = "utf-8">
	    <meta name = "viewport" content = "width=device-width, initial-scale=1">
	    <link rel = "stylesheet" type = "text/css" href = "Ski.css">
		<style>
		.box{
		  position: absolute;
		  top: 50%;
		  left: 50%;
		  transform: translate(-50%, -50%);
		  width: 300px;
		  padding: 40px;
		  background: rgba(0, 0, 0, 0.8);
		  box-shadow: 0 15px 25px rgba(0, 0, 0, 0.5);
		  border-radius: 10px;
		}
		</style>
	</head>

	<body>
		<?php
			include('EnTete_Admin.html');
			include("connexion.inc.php");
		?>

		<div class = "box">
			<h2> Nouveau client </h2>
				<form action = "" method = POST>
					<div class = "inputBox">
						<input type = "text" name = "Nom"  required = "">
						<label> Nom </label>
					</div>
					<div class = "inputBox">
						<input type = "text" name = "Prenom"  required = "">
						<label> Prénom </label>
					</div>
					<div class = "inputBox">
			 			<input type = "text" name = "Adresse"  required = "">
			 			<label> Adresse </label>
			 		</div>
					<div class = "inputBox">
			 			<input type = "text" name = "Telephone"  required = "">
			 			<label> Téléphone </label>
			 		</div>
					<div class = "inputBox">
			   			<input type = "text" name = "Date_n"  required = "">
			   			<label> Date de naissance </label>
			   		</div>
			   		<!-- Taille -->
					<select name = "Taille">
						<label> Taille </label>
							<option value = "" selected = "selected"> -- taille(cm) -- </option>
								<?php
									for($taille = 40 ; $taille <= 250 ; $taille++){
						          		echo '<option>'.$taille.'</option>';
						        	}
								?>
					</select>
					<!-- Poids -->
					<select name = "Poids">
						<label> Poids </label>
							<option value = "" selected = "selected"> -- poids(kg) -- </option>
								<?php
									for($poids = 10 ; $poids <= 200 ; $poids++){
						          		echo '<option>'.$poids.'</option>';
						        	}
								?>
					</select>
					<!-- Pointure -->
					<select name = "Pointure">
						<label> Pointure </label>
							<option value = "" selected = "selected"> -- pointure -- </option>
								<?php
									for($pointure = 10 ; $pointure <= 50 ; $pointure++){
						          		echo '<option>'.$pointure.'</option>';
						        	}
								?>
					</select>
					<!-- Niveau de ski -->
					<select name = "Niveau">
					 	<label> Niveau de ski </label>
							<option value = "" selected = "selected"> -- Niveau ski -- </option>
							<?php
								echo '<option>débutant</option>';
								echo '<option>moyen</option>';
								echo '<option>confirmé</option>';
							?>
					</select>
			<br><br>
			<input type = "submit" name = "Valider" value = "Valider"/>
		</form>
	</div>

		<?php
			if(isset($_POST['Valider'])){
				$resultat = $cnx->exec("INSERT INTO client(nom, prenom, adresse, telephone, taille, poids, pointure, niv_ski)
					                    VALUES ('".$_POST['Nom']."', '".$_POST['Prenom']."', '".$_POST['Adresse']."', '".$_POST['Telephone']."',
					                            '".$_POST['Taille']."', '".$_POST['Poids']."', '".$_POST['Pointure']."', '".$_POST['Niveau']."')");
				if ($resultat == 0){
					echo "Erreur, la personne n'a pas pu etre ajouté.";
				}
				else{
					echo "Insertion réussit";
				}
			}
		?>
	</body>
</html>
