/* Copyright Steve Chen 2020 <schen07@etud.u-pem.fr>
   Copyright Kévin Da Costa Moura 2020 <kdacos01@etud.u-pem.fr>
   Project in C : Image compress.
   Date : 22/11/2020. */

/* Quadtree.h */
#ifndef __QUADTREE__
#define __QUADTREE__

/* Importation of modules. */ 
#include <stdlib.h>
#include <MLV/MLV_all.h>

/* Structures. */
union Pixel {
    int bit; /* B&W image. */
    int color[4]; /* Colors image. */ 
};

typedef struct position {
    int x, y; /* Coord NW. */
    int x1, y1; /* Coord SE. */
} Position;

typedef struct quadtree {
    long error;
    Position pos;
    union Pixel pixel;
    struct quadtree *northWest;
    struct quadtree *northEast;
    struct quadtree *southWest;
    struct quadtree *southEast;
} Quad, *QuadTree;

/* Prototypes of functions. */

/*
Allocate the right memory for a new node.
@param  : pixel -> color of the new node.
@param  : pos -> position in the window of the new node.
@param  : error -> error of the area of the new node.
@return : cell -> new node.
*/
QuadTree allocateCell(union Pixel pixel, Position pos, long error);

/*
Recursive function which insert node in the QuadTree.
@param  : Qtree -> the QuadTree where the new node is inserting.
@param  : P -> the average color of the zone.
@param  : pos -> the position of the zone.
@param  : mid -> the mid position of the zone to know where we put the new zone.
@return : Qtree.
*/
QuadTree insertNode(QuadTree *Qtree, union Pixel pixel, Position pos, Position mid, long error);

/*
Return 1 if Qtree is leaf else 0.
@param  : Qtree -> the tree where we verify.
@return : 1 if Qtree is leaf else 0.
*/
int isLeaf(QuadTree Qtree);

#endif