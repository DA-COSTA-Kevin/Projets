/* Copyright Steve Chen 2020 <schen07@etud.u-pem.fr>
   Copyright Kévin Da Costa Moura 2020 <kdacos01@etud.u-pem.fr>
   Project in C : Image compress.
   Date : 22/11/2020. */

/* Math.h */
#ifndef __MATH__
#define __MATH__

/* Importation of modules. */ 
#include <math.h>
#include "Quadtree.h"

/* Prototypes of functions. */

/*
This function put the average color of one zone with coord pos in P.
@param  : P -> the pixel where we're storage the average color of the zone.
If the image is in B&W we set  for white 1 for black else the (rgba).
@param  : pos -> the position of the zone.
@param  : img -> the image where we're working. 
*/
void getAvgColorOfZone(union Pixel *p, Position pos, MLV_Image *img, int img_type);

/*
Return a double which represents the distance between 2 pixels.
@param  : p1 -> first pixel.
@param  : p2 -> second pixel.
@return : (double) the distance of the both pixel.
*/
double distPixel(union Pixel p1, union Pixel p2);

/*
Return the error of one zone by using the average color of the zone.
@param  : pos -> the zone where we're calculate the error.
@param  : img -> the image where we're working.
@return : (long) the error of the zone.
*/
long zoneError(Position pos, MLV_Image *img, int img_type);

/*
Return the distance between 2 trees.
@param  : Qtree1 -> the first tree.
@param  : Qtree2 -> the second tree.
@return : sum -> distance between Qtree1 and Qtree2.
*/
double distance(QuadTree Qtree1, QuadTree Qtree2);

#endif