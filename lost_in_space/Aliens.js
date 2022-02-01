"use strict";
// Alien
function Alien(x,y) {
        this.x = x;
        this.y = y;
        this.dx = 1;
        this.dy = 2;
		this.hitbox = [5,5,5,5];
		this.vie = true;
        this.image = new Image();
        (this.image).src = "Alien.png";
    }

Alien.prototype.update = function() {
	this.x = this.x + this.dx;
	this.y = this.y + this.dy;
	if (this.dx >= 10 || this.dx <= -10) {
		if (this.x <= 0 || this.x >= 600 - 6) {
			this.dx = -this.dx;
		};
	} else {
		if (this.x <= 0 || this.x >= 600 - 6) {
			this.dx = -this.dx * 1.10;
		}
	}
	if (this.dy >= 10 || this.dy <= -10) {
		if (this.y <= 0 || this.y >= 600 - 6) {
			this.dy = -this.dy;
		}
	} else {
		if (this.y <= 0 || this.y >= 600 - 6) {
			this.dy = -this.dy * 1.10;
		}
	}
}


Alien.prototype.draw = function(context) {
    context.drawImage(this.image, this.x, this.y);
}