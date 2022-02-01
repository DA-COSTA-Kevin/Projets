"use strict";
var score = 0;
var fireRate = 0;
var vague = 0;
window.onload = function () {
    var world = initialiseWorld();
    window.setInterval(function () {
        fireRate++
    }, 10);

    // deplacement vaisseau
    window.addEventListener('keydown', function (event) {
        if (event.keyCode == 37) {
            world["VAISSEAU"].move[0] = true;
        } else if (event.keyCode == 38) {
            world["VAISSEAU"].move[2] = true;
        } else if (event.keyCode == 39) {
            world["VAISSEAU"].move[1] = true;
        } else if (event.keyCode == 40) {
            world["VAISSEAU"].move[3] = true;
        } else if (event.keyCode == 32) {
            world["VAISSEAU"].move[4] = true;
            if (world["VAISSEAU"].move[4] == true) {
                // Empeche de spammer les missiles (:p)  
                if (fireRate > 10) {
                    world["MISSILES"].push(new Missile(world["VAISSEAU"].x, world["VAISSEAU"].y));
                    fireRate = 0;
                }
            }
        }
    }, false);

    window.addEventListener('keyup', function (event) {
        if (event.keyCode == 37) {
            world["VAISSEAU"].move[0] = false;
        } else if (event.keyCode == 38) {
            world["VAISSEAU"].move[2] = false;
        } else if (event.keyCode == 39) {
            world["VAISSEAU"].move[1] = false;
        } else if (event.keyCode == 40) {
            world["VAISSEAU"].move[3] = false;
        } else if (event.keyCode == 32) {
            world["VAISSEAU"].move[4] = false;
        }
    }, false);

    // affiche l'arene et tout ce qu'elle contient
    window.setInterval(function () {
        gameloop(world);
    }, 1000.0 / 60.0);
};

function initialiseWorld() {
    var world = [];
    world["VAISSEAU"] = new Vaisseau(((600 - 32) / 2), 560);
    world["ALIENS"] = [];
    for (var i = 0; i < 20; i++) {
        world["ALIENS"].push(new Alien(Math.random() * 600, i * 5));
    }
    world["MISSILES"] = [];
    return world;
}

function gameloop(world) {
    update(world);
    draw(world);
}

function update(world) {
    var canvas = document.getElementById('game_area');
    var context = canvas.getContext("2d");

    // gestion du vaisseau
    world["VAISSEAU"].update();
    console.log(world["VAISSEAU"].vie);
    if (world["VAISSEAU"].vie == false) {
        afficheMort(context, score);
        world["VAISSEAU"] = [];
    }

    // gestion des aliens 
    world["ALIENS"].forEach(aliens => aliens.update());
    world["ALIENS"] = world["ALIENS"].filter(aliens => (aliens.vie == true));

    // fait reapparaitre 20 aliens s'ils ont été détruits 
    if (world["ALIENS"].length == 0) {
        vague += 1;
        for (var i = 0; i < 20 + vague; i++) {
            world["ALIENS"].push(new Alien(Math.random() * 600, i * 5));
        }
    }

    // gestion des missiles 
    world["MISSILES"].forEach(missiles => missiles.update());
    world["MISSILES"] = world["MISSILES"].filter(missile => (missile.distance < 300));
    world["MISSILES"] = world["MISSILES"].filter(missile => (missile.vie == true));

    // verification des collisions 
    for (var i = 0; i < world["ALIENS"].length; i++) {
        CollisionMissile(world["ALIENS"][i], world["MISSILES"], context);
        CollisionVaisseaux(world["VAISSEAU"], world["ALIENS"][i], context);
    }
    for (var i = 0; i < world["MISSILES"].length; i++) {
        CollisionMissile(world["VAISSEAU"], world["MISSILES"], context);
    }
    // renvoie le score a afficher
    return score;
}

function draw(world) {
    var canvas = document.getElementById('game_area');
    var context = canvas.getContext("2d");
    context.clearRect(0, 0, 600, 600);
    world["VAISSEAU"].draw(context);
    world["ALIENS"].forEach(aliens => aliens.draw(context));
    world["MISSILES"].forEach(missiles => missiles.draw(context));
    afficheScore(context, score);
    afficheVague(context, vague);
}

// verification d'une collision avec un alien 
function CollisionVaisseaux(VAISSEAU, ALIENS, context) {
    // coin Vaisseau
    // [[ coin gauche , coin haut ] , [ coin droite , coin bas ]] 
    var zoneVaisseau = [[VAISSEAU.x - VAISSEAU.hitbox[0], VAISSEAU.y - VAISSEAU.hitbox[2]], [VAISSEAU.x + VAISSEAU.hitbox[1], VAISSEAU.y + VAISSEAU.hitbox[3]]];
    // coin aliens
    // [[ coin gauche , coin haut ] , [ coin droite , coin bas ]] 
    var zoneAlien = [[ALIENS.x - ALIENS.hitbox[0], ALIENS.y - ALIENS.hitbox[0]], [ALIENS.x + ALIENS.hitbox[0], ALIENS.y + ALIENS.hitbox[0]]];

    // si (coin gauche vaisseau < coin droite alien) et (coin gauche vaisseau > coin gauche alien) et (coin haut vaisseau < coin bas alien) et (coin haut vaisseau > coin haut alien)
    if (zoneVaisseau[0][0] < zoneAlien[1][0] && zoneVaisseau[0][0] > zoneAlien[0][0] && zoneVaisseau[0][1] < zoneAlien[1][1] && zoneVaisseau[0][1] > zoneAlien[0][1]) {
        ALIENS.vie = false;
        VAISSEAU.vie = false;
    }

    // si (coin droite vaisseau > coin gauche alien) et (coin droite vaisseau < coin droite alien) et (coin haut vaisseau < coin bas alien) et (coin haut vaisseau > coin haut alien)
    else if (zoneVaisseau[1][0] > zoneAlien[0][0] && zoneVaisseau[1][0] < zoneAlien[1][0] && zoneVaisseau[0][1] < zoneAlien[1][1] && zoneVaisseau[0][1] > zoneAlien[0][1]) {
        ALIENS.vie = false;
        VAISSEAU.vie = false;
    }
    // si (coin droite vaisseau > coin gauche alien) et (coin droite vaisseau < coin droite alien) et (coin bas vaisseau < coin bas alien) et (coin bas vaisseau > coin haut alien)
    else if (zoneVaisseau[1][0] > zoneAlien[0][0] && zoneVaisseau[1][0] < zoneAlien[1][0] && zoneVaisseau[1][1] < zoneAlien[1][1] && zoneVaisseau[1][1] > zoneAlien[0][1]) {
        ALIENS.vie = false;
        VAISSEAU.vie = false;
    }
    // si (coin gauche vaisseau < coin droite alien) et (coin gauche vaisseau > coin droite alien) et (coin bas vaisseau < coin bas alien) et (coin bas vaisseau > coin haut alien)
    else if (zoneVaisseau[0][0] < zoneAlien[1][0] && zoneVaisseau[0][0] > zoneAlien[0][0] && zoneVaisseau[1][1] < zoneAlien[1][1] && zoneVaisseau[1][1] > zoneAlien[0][1]) {
        ALIENS.vie = false;
        VAISSEAU.vie = false;
    }
}

function CollisionMissile(VAISSEAU, MISSILES, context) {
    // zone Vaisseau
    // [[ coin gauche , coin haut ] , [ coin droite , coin bas ]] 
    var zoneVaisseau = [[VAISSEAU.x - VAISSEAU.hitbox[0], VAISSEAU.y - VAISSEAU.hitbox[2]]
	, [VAISSEAU.x + VAISSEAU.hitbox[1], VAISSEAU.y + VAISSEAU.hitbox[3]]];
    // verification d'une collision avec le vaisseau
    for (var i = 0; i < MISSILES.length; i++) {
        MISSILES[i].ptImpact = MISSILES[i].x + 1;
        if (MISSILES[i].ptImpact < zoneVaisseau[1][0] && MISSILES[i].ptImpact > zoneVaisseau[0][0] && MISSILES[i].y < zoneVaisseau[1][1] && MISSILES[i].y > zoneVaisseau[0][1]) {
            MISSILES[i].vie = false;
            VAISSEAU.vie = false;
            score += 1;
        }
    }
}

function afficheScore(context, score) {
    context.font = "30px Courier New";
    context.fillStyle = "white";
    context.fillText("Score : " + score, 10, 30);
}

function afficheVague(context, vague) {
    context.font = "30px Courier New";
    context.fillStyle = "white";
    context.fillText("Vague : " + vague, 420, 30);
}

function afficheMort(context, score) {
    context.font = "50px Courier New";
    context.textAlign = "center";
    context.fillStyle = "red";
    context.fillText("Game Over !", 310, 220);
    context.fillText("Score : " + score, 310, 270);
    context.fillText("Vague : " + vague, 310, 320);
}
