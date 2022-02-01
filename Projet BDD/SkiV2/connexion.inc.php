<!DOCTYPE html>

<html>
	<head>
		<meta http-equiv = "Content-Type" content = "text/html ; charset=UTF-8">
 		<meta name = "title" content = "Titre de la page" />

	</head>

	<body>
		<?php
			$user = 'schen07';
			$pass = '17072000';
			try{
		    	$cnx = new PDO('pgsql: host = sqletud.u-pem.fr ; dbname = schen07_db', $user, $pass);  
		    	//echo "Connexion réussi ! ";
			}
			catch (PDOException $e) {
		    	//echo "Erreur de connexion ! ";
		    }
		?>
	</body>
</html>