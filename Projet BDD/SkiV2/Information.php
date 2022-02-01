<!DOCTYPE html>
<html>
	<head>
		<meta http-equiv = "Content-Type" content = "text/html ; charset=UTF-8">
 		<meta name = "title" content = "Titre de la page">
		<link rel = "stylesheet" type = "text/css" href = "Ski.css">
	</head>

<body>

	<?php
		include('EnTete_Resp.html');
		include('connexion.inc.php');

	?>

	<div class="box">
		<table>
			<thead>
				<tr><th> Information client</th></tr>
			</thead>
		<tbody>
				<tr><td>Id</td><td>Nom</td><td>Prénom</td><td>Date de naissance</td><td>Adresse</td><td>Téléphone</td><td>Taille</td><td>Poids</td><td>Pointure</td><td>Niv de ski</td></tr>
					<?php
						$requete = $cnx->query('SELECT * FROM client');

					 	foreach($requete as $valeur){
						 	echo "<tr><th>".$valeur['id_client']."</th><td>".$valeur['nom']."</td><td>".$valeur['prenom']."</td><td>".$valeur['date_n']."</td><td>".$valeur['adresse']."</td><td>"
												.$valeur['telephone']."</td><td>".$valeur['taille']."</td><td>".$valeur['poids']."</td><td>".$valeur['pointure']."</td><td>".$valeur['niv_ski']."</td></tr>";
					 	}
					?>

		</tbody>
	</table>
</div>


</body>
</html>
