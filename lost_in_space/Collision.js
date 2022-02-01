function CollisionVaisseaux(world["VAISSEAU"],world["ALIENS"],context){
	// zone Vaisseau
	var zoneVaisseau = [[world["VAISSEAU"].x - world["VAISSEAU"].hitbox[0],world["VAISSEAU"].y - world["VAISSEAU"].hitbox[2]]
	,[world["VAISSEAU"].x + world["VAISSEAU"].hitbox[1],world["VAISSEAU"].y]];
	// verification d'une collision avec un alien 
	for ( var i = 0 ; i < world["ALIENS"].length ; i++ ) {
		var zoneAlien = [world["ALIENS"][i].x - world["ALIENS"][i].hitbox[0],world["ALIENS"][i].y - world["ALIENS"][i].hitbox[0]],[world["ALIENS"][i].x + world["ALIENS"][i].hitbox[0],world["ALIENS"][i].y + world["ALIENS"][i].hitbox[0]]]);
		
		if (zoneVaisseau[0][0] < zoneAlien[1][0] && zoneVaisseau[0][0] > zoneAlien[0][0] && zoneVaisseau[0][1] < zoneAlien[1][1] && zoneVaisseau[0][1] > zoneAlien[0][1]){
			world["ALIENS"][i].vie = false;
			world["VAISSEAU"].vie = false;	
		}
		else if (zoneVaisseau[1][0] > zoneAlien[0][0] && zoneVaisseau[1][0] < zoneAlien[1][0] && zoneVaisseau[0][1] < zoneAlien[1][1] && zoneVaisseau[0][1] > zoneAlien[0][1]){
			world["ALIENS"][i].vie = false;
			world["VAISSEAU"].vie = false;
		}
		else if (zoneVaisseau[1][0] > zoneAlien[0][0] && zoneVaisseau[1][0] < zoneAlien[1][0] && zoneVaisseau[1][1] < zoneAlien[1][1] && zoneVaisseau[1][1] > zoneAlien[0][1]){
			world["ALIENS"][i].vie = false;
			world["VAISSEAU"].vie = false;
		}
		else if (zoneVaisseau[0][0] < zoneAlien[1][0] && zoneVaisseau[0][0] > zoneAlien[0][0] && zoneVaisseau[1][1] < zoneAlien[1][1] && zoneVaisseau[1][1] > zoneAlien[0][1]){
			world["ALIENS"][i].vie = false;
			world["VAISSEAU"].vie = false;
		}
	}
}
 // for ( var i = 0 ; i < world["ALIENS"].length ; i++) {CollisionMissile(world["ALIENS"][i],world["MISSILES"],context);}
 // CollisionMissile(world["VAISSEAU"],world["MISSILES"],context);
function CollisionMissile(world["VAISSEAU"],world["MISSILES"],context){
	// zone Vaisseau
	var zoneVaisseau = [[world["VAISSEAU"].x - world["VAISSEAU"].hitbox[0],world["VAISSEAU"].y - world["VAISSEAU"].hitbox[2]]
	,[world["VAISSEAU"].x + world["VAISSEAU"].hitbox[1],world["VAISSEAU"].y]];
	// verification d'une collision avec le vaisseau
	for ( var i = 0 ; i < world["MISSILES"].length ; i++ ) { 
		world["MISSILES"][i].ptImpact = world["MISSILES"][i].x + 1;
		if (world["MISSILES"][i].ptImpact < zoneVaisseau[1][0] && world["MISSILES"][i].ptImpact > zoneVaisseau[0][0] && world["MISSILES"][i].y < zoneVaisseau[1][1] && world["MISSILES"][i].y > zoneVaisseau[0][1]){
			world["MISSILES"][i].vie = false;
			world["VAISSEAU"].vie = false;
		}
	}
}