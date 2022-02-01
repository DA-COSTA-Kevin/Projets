/* Copyright Steve Chen 2020 <schen07@etud.u-pem.fr>
   Copyright Kévin Da Costa Moura 2020 <kdacos01@etud.u-pem.fr>
   Project in C : Image compress.
   Date : 22/11/2020. */

/* Importation of modules. */ 
#include "Position.h"

/* Functions. */
void getPosition(Position *pos, int x, int y, int x1, int y1) {
    pos->x = x;
    pos->y = y;
    pos->x1 = x1;
    pos->y1 = y1;
}

void findZone(QuadTree Qtree, Position *pos, long *error, MLV_Image *img) {
    if(Qtree == NULL) {
        return;
    }
    if(isLeaf(Qtree)) {
        if(Qtree->error > *error) {
            *error = Qtree->error;
            *pos = Qtree->pos;
        }
    }
    findZone(Qtree->northWest, pos, error, img);
    findZone(Qtree->northEast, pos, error, img);
    findZone(Qtree->southWest, pos, error, img);
    findZone(Qtree->southEast, pos, error, img);
}

void splitZone(QuadTree *Qtree, Position pos, MLV_Image *img, int img_type) {
    Position tmp, mid;
    union Pixel p;
    int i, j;

    tmp = pos;

    getPosition(&mid, 256, 256, 256, 256);

    /* Split the zone at the position pos in 4. */
    for(i = 0; i < 2; i++) {
        for(j = 0; j < 2; j++) {
            getPosition(&pos, (pos.x * (1 - j)) + (((pos.x + pos.x1) / 2) * j), (pos.y * (1 - i)) + (((pos.y + pos.y1) / 2) * i), (pos.x1 * j) + ((pos.x + pos.x1) / 2) * (1 - j), (pos.y1 * i) + (((pos.y + pos.y1) / 2) * (1 - i)));
            getAvgColorOfZone(&p, pos, img, img_type);
            insertNode(Qtree, p, pos, mid, zoneError(pos, img, 1));
            pos = tmp;
        }
    }
}

void buildQuadTree(QuadTree *Qtree, MLV_Image *img, int img_type, int min_error) {
    Position pos;
    union Pixel p;
    long error;

    error = 0;

    getPosition(&pos, 0, 0, 512, 512);
    getAvgColorOfZone(&p, pos, img, img_type);
    insertNode(Qtree, p, pos, pos, zoneError(pos, img, 1));
    splitZone(Qtree, pos, img, img_type);

    /* Verify if the position with the less higher error is > min_error. */
    while(zoneError(pos, img, img_type) > min_error) {
        getPosition(&pos, 0, 0, 0, 0);
        findZone(*Qtree, &pos, &error, img);
        splitZone(Qtree, pos, img, img_type);
        error = 0;
    }
}