"use strict";

class Vaisseau {
    constructor(x, y) {
        this.x = x;
        this.y = y;
        this.image = new Image();
        (this.image).src = "vaisseau.png";
        this.move = [false, false, false, false, false];
        this.vie = true;
        this.hitbox = [5, 5, 5, 5];
    }
    // deplacement du vaisseau
    update() {
        if (this.move[0] == true) {
            if (this.x > 0) {
                this.x -= 5;
            }
        }
        if (this.move[1] == true) {
            if (this.x < 600 - 32) {
                this.x += 5;
            }
        }
        if (this.move[2] == true) {
            if (this.y > 0) {
                this.y -= 5;
            }
        }
        if (this.move[3] == true) {
            if (this.y < 600 - 32) {
                this.y += 5;
            }
        }
    }


    draw(context) {
        context.drawImage(this.image, this.x, this.y);
    }

}
