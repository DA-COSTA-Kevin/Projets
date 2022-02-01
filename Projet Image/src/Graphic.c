/* Copyright Steve Chen 2020 <schen07@etud.u-pem.fr>
   Copyright Kévin Da Costa Moura 2020 <kdacos01@etud.u-pem.fr>
   Project in C : Image compress.
   Date : 22/11/2020. */

/* Importation of modules. */ 
#include "Graphic.h"

/* Functions. */
void displayImage(QuadTree Qtree, int img_type) {
    if(Qtree == NULL) {
        return;
    }
    if(isLeaf(Qtree)) {
        if(img_type == 0) {
            if(Qtree->pixel.bit == 0) {
                MLV_draw_filled_rectangle(Qtree->pos.x, Qtree->pos.y, Qtree->pos.x1 -Qtree->pos.x, Qtree->pos.y1 - Qtree->pos.y, MLV_convert_rgba_to_color(255, 255, 255, 255));
            } else {
                MLV_draw_filled_rectangle(Qtree->pos.x, Qtree->pos.y, Qtree->pos.x1 -Qtree->pos.x, Qtree->pos.y1 - Qtree->pos.y, MLV_convert_rgba_to_color(0, 0, 0, 255));
            }
        }
        else {
            MLV_draw_filled_rectangle(Qtree->pos.x, Qtree->pos.y, Qtree->pos.x1 -Qtree->pos.x, Qtree->pos.y1 - Qtree->pos.y, MLV_convert_rgba_to_color(Qtree->pixel.color[0], Qtree->pixel.color[1], Qtree->pixel.color[2], Qtree->pixel.color[3]));
        }
    }
    displayImage(Qtree->northWest, img_type);
    displayImage(Qtree->northEast, img_type);
    displayImage(Qtree->southWest, img_type);
    displayImage(Qtree->southEast, img_type);
}

void displayMenu() {
    int i;
    char array[7][20] = {"Run", "Save (B&W)", "Save (rgba)", "Minimisation", "Graph (B&W)", "Graph (rgba)", "Open image"};

    for(i = 1; i <= 7; i++) {
        MLV_draw_text_box(WIDTH + 20, i * 60, MENU_WIDTH - 40, 50, "%s", 1, MLV_COLOR_DARKGREEN, MLV_COLOR_DARKGREEN, MLV_COLOR_DARK_GRAY, MLV_TEXT_CENTER, MLV_HORIZONTAL_CENTER, MLV_VERTICAL_CENTER, array[i - 1]);
    }
}

void displayWindow(MLV_Image **img, char *name) {
    char path[32] = "img/";

    if((*img = MLV_load_image(strcat(path, name))) == NULL) {
        printf("Image not found\n");
        exit(0);
    }
    MLV_draw_image(*img, 0, 0);

    displayMenu();

    MLV_actualise_window();
}