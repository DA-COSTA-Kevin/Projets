/* Copyright Steve Chen 2020 <schen07@etud.u-pem.fr>
   Copyright Kévin Da Costa Moura 2020 <kdacos01@etud.u-pem.fr>
   Project in C : Image compress.
   Date : 22/11/2020. */

/* Importation of modules. */ 
#include "Quadtree.h"

/* Functions. */
QuadTree allocateCell(union Pixel pixel, Position pos, long error) {
    QuadTree cell;
    
    cell = (QuadTree) malloc(sizeof(Quad));

    if(cell != NULL) {
        cell->error = error;
        cell->pos = pos;
        cell->pixel = pixel;
        cell->northWest = NULL;
        cell->northEast = NULL;
        cell->southWest = NULL;
        cell->southEast = NULL;
    }
    return cell;
}

QuadTree insertNode(QuadTree *Qtree, union Pixel pixel, Position pos, Position mid, long error) {
    if(*Qtree == NULL) {
        *Qtree = allocateCell(pixel, pos, error);
        return *Qtree;
    }
    mid.x1 /= 2;
    mid.y1 /= 2;
    if(pos.x < mid.x && pos.y < mid.y) {
        mid.x -= mid.x1;
        mid.y -= mid.y1;
        return insertNode(&(*Qtree)->northWest, pixel, pos, mid, error);
    }
    if(pos.x >= mid.x && pos.y < mid.y) {
        mid.x += mid.x1;
        mid.y -= mid.y1;
        return insertNode(&(*Qtree)->northEast, pixel, pos, mid, error);
    }
    if(pos.x < mid.x && pos.y >= mid.y) {
        mid.x -= mid.x1;
        mid.y += mid.y1;
        return insertNode(&(*Qtree)->southWest, pixel, pos, mid, error);
    }
    if(pos.x >= mid.x && pos.y >= mid.y) {
        mid.x += mid.x1;
        mid.y += mid.y1;
        return insertNode(&(*Qtree)->southEast, pixel, pos, mid, error);
    }
    return *Qtree;
}

int isLeaf(QuadTree Qtree) {
    if(Qtree->northWest == NULL || Qtree->northEast == NULL || Qtree->southWest == NULL || Qtree->southEast == NULL) {
        return 1;
    }
    return 0;
}