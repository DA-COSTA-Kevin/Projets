"use strict";
// Missile
function Missile(x,y) {
    this.x = x - 5;
    this.y = y - 5;
	this.departY = y;
	this.distance = 0;
	this.dy = 2;
	this.ptImpact = this.distance;
	this.vie = true;
    this.image = new Image();
    (this.image).src = "Missile.png";
}

// Fait avancer le missile avec une vitesse de 99% et une durée de vie de moitié de l'arène
Missile.prototype.update = function() {
	this.distance = this.departY - this.y;
	if (this.distance < 300) {
		this.y = (this.y - this.dy) * 0.99;
	}
}

Missile.prototype.draw = function(context) {
	context.drawImage(this.image, this.x, this.y);
}
