/* Copyright Steve Chen 2020 <schen07@etud.u-pem.fr>
   Copyright Kévin Da Costa Moura 2020 <kdacos01@etud.u-pem.fr>
   Project in C : Image compress.
   Date : 22/11/2020. */

/* Graphic.h */
#ifndef __GRAPHIC__
#define __GRAPHIC__

/* Importation of modules. */ 
#include <stdio.h>
#include "Position.h"

/* Defines. */
#define WIDTH 512
#define HEIGHT 512
#define MENU_WIDTH 300
#define MENU_HEIGHT HEIGHT

/* Prototypes of functions. */

/*
Display the final image on the window by browsing all the QuadTree.
@param  : Qtree -> the QuadTree which contains zones to display.
@param  : img_type -> type of image B&W or colors.
*/
void displayImage(QuadTree Qtree, int img_type);

/*
Display the menu on the right of the window.
*/
void displayMenu();

/*
Display window with image + menu.
@param  : img -> the image of the screen.
@param  : name -> name of the image.
*/
void displayWindow(MLV_Image **img, char *name);

#endif