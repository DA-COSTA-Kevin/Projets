/* Copyright Steve Chen 2020 <schen07@etud.u-pem.fr>
   Copyright Kévin Da Costa Moura 2020 <kdacos01@etud.u-pem.fr>
   Project in C : Image compress.
   Date : 22/11/2020. */

/* Importation of modules. */ 
#include "User.h"

int waitChoice() {
    int i;
    int click_x, click_y;

    MLV_wait_mouse(&click_x, &click_y);
    
    for(i = 1; i <= 7; i++) {
        if(click_x >= WIDTH + 20 && click_x <= WIDTH + 280 && click_y >= i * 60 && click_y <= (i * 50) + (60 + (i - 1) * 10)) {
            return i;
        }
    }
    return -1;
}