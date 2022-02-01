/* Copyright Steve Chen 2020 <schen07@etud.u-pem.fr>
   Copyright Kévin Da Costa Moura 2020 <kdacos01@etud.u-pem.fr>
   Project in C : Image compress.
   Date : 22/11/2020. */

/* Position.h */
#ifndef __POSITION__
#define __POSITION__

/* Importation of modules. */ 
#include "Math.h"

/* Prototypes of functions. */

/*
Put in pos the position of rectangle.
@param  : pos -> the position where we attribute the position.
@param  : (x, y) -> the cord in North-West of a zone.
@param  : (x1, y1) -> the coord in South-East of a zone. 
*/
void getPosition(Position *pos, int x, int y, int x1, int y1);

/*
Find in the QuadTree the zone where the error is the most important,
by using the function "zoneError". Then pos get the position of this
zone.
@param  : Qtree -> the QuadTree where we are looking for the zone.
@param  : pos -> the position where we storage the position of the zone (by adress).
@param  : keep the last value error to compare it with the next one.
@param  : img -> the image where we're working.
*/
void findZone(QuadTree Qtree, Position *pos, long *error, MLV_Image *img);

/*
Split a zone in 4 and add every of this 4 new zone in the QuadTree Qtree.
@param  : Qtree -> the QuadTree where the new zones are add.
@param  : pos -> the position split in 4.
*/
void splitZone(QuadTree *Qtree, Position pos, MLV_Image *img, int img_type);

/*
Build the QuadTree while the we already have area as non null error.
First we're looking for the good area thank's to "findZone".
Then we split this zone in 4 by using the function "splitZone", which
also add in the QuadTree the 4 new zones.
@param  : Qtree -> the QuadTree that we build.
@param  : img -> the image on which the QuadTree is build.
@param  : img_type -> allows us to know if the image is in B&W or in colors.
*/
void buildQuadTree(QuadTree *Qtree, MLV_Image *img, int img_type, int min_error);

#endif