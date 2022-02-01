<!DOCTYPE html>

<html>
  <head>
    <meta charset = "utf-8">
    <meta name = "viewport" content = "width=device-width, initial-scale=1">
    <link rel = "stylesheet" type = "text/css" href = "Ski.css">
	<style>
	.box3{
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
      include('EnTete.html');
	  include('connexion.inc.php');
    ?>

    <div class = "Accueil">
	</div>
	<div class="box3">
		<table>
			<thead>
				<tr><th> Les Formules </th></tr>
			</thead>
		<tbody>
				<tr><td>id de la formule</td><td>nom de la formule</td><td>Tarif</td></tr>
					<?php
						$requete = $cnx->query('SELECT * FROM formule');

					 	foreach($requete as $valeur){
						 	echo "<tr><th>".$valeur['id_formule']."</th><td>".$valeur['nom_formule']."</td><td>".$valeur['tarif']." €</td></tr>";
					 	}
					?>
		</tbody>
	</table>
</div>

  </body>
</html>
