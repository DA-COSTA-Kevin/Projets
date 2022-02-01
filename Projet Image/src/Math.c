/* Copyright Steve Chen 2020 <schen07@etud.u-pem.fr>
   Copyright Kévin Da Costa Moura 2020 <kdacos01@etud.u-pem.fr>
   Project in C : Image compress.
   Date : 22/11/2020. */

/* Importation of modules. */ 
#include "Math.h"

/* Functions. */
void getAvgColorOfZone(union Pixel *p, Position pos, MLV_Image *img, int img_type) {
    int i, j, k;
    int nb_pixel;
    int pixel[4], tmp[4];
    double res;

    nb_pixel = 0;

    for(k = 0; k < 4; k++) {
        pixel[k] = 0;
    }

    for(i = pos.x; i < pos.x1; i++) {
        for(j = pos.y; j < pos.y1; j++) {
            MLV_get_pixel_on_image(img, i, j, &tmp[0], &tmp[1], &tmp[2], &tmp[3]);
            for(k = 0; k < 4; k++) {
                pixel[k] += tmp[k];
            }
            nb_pixel++;
        }
    }
    res = (double) 1 / nb_pixel;

    for(k = 0; k < 4; k++) {
        pixel[k] *= res;
    }

    if(img_type == 0) {
        if((pixel[0]) > 127) {
            p->bit = 0;
        } else {
            p->bit = 1;
        }
    }
    else {
        for(k = 0; k < 4; k++) {
            p->color[k] = pixel[k];
        }
    }
}

double distPixel(union Pixel p1, union Pixel p2) {
    int i, sum;

    sum = 0;

    for(i = 0; i < 4; i++) {
        sum += pow(p1.color[i] - p2.color[i], 2);
    }
    return sqrt(sum);
}

long zoneError(Position pos, MLV_Image *img, int img_type) {
    union Pixel p1, p2;
    int i, j, k;
    int tmp[4];
    long sum;

    sum = 0;

    getAvgColorOfZone(&p2, pos, img, img_type);
    
    for(i = pos.x; i < pos.x1; i++) {
        for(j = pos.y; j < pos.y1; j++) {
            MLV_get_pixel_on_image(img, i, j, &tmp[0], &tmp[1], &tmp[2], &tmp[3]);
            for(k = 0; k < 4; k++) {
                p1.color[k] = tmp[k];
            }
            sum += distPixel(p1, p2);
        }
    }
    return sum;
}

double distance(QuadTree Qtree1, QuadTree Qtree2) {
    double sum;

    sum = 0;

    if(isLeaf(Qtree1) && isLeaf(Qtree2)) {
        return distPixel(Qtree1->pixel, Qtree2->pixel);
    }
    else if(isLeaf(Qtree1) && !isLeaf(Qtree2)) {
        sum += distPixel(Qtree1->pixel, Qtree2->northWest->pixel) / 4;
        sum += distPixel(Qtree1->pixel, Qtree2->northEast->pixel) / 4;
        sum += distPixel(Qtree1->pixel, Qtree2->southWest->pixel) / 4;
        sum += distPixel(Qtree1->pixel, Qtree2->southEast->pixel) / 4;
        return sum;
    }
    else if(!isLeaf(Qtree1) && isLeaf(Qtree2)) {
        sum += distPixel(Qtree1->northWest->pixel, Qtree2->pixel) / 4;
        sum += distPixel(Qtree1->northEast->pixel, Qtree2->pixel) / 4;
        sum += distPixel(Qtree1->southWest->pixel, Qtree2->pixel) / 4;
        sum += distPixel(Qtree1->southEast->pixel, Qtree2->pixel) / 4;
        return sum;
    }
    else {
        sum += distPixel(Qtree1->northWest->pixel, Qtree2->northWest->pixel) / 4;
        sum += distPixel(Qtree1->northEast->pixel, Qtree2->northEast->pixel) / 4;
        sum += distPixel(Qtree1->southWest->pixel, Qtree2->southWest->pixel) / 4;
        sum += distPixel(Qtree1->southEast->pixel, Qtree2->southEast->pixel) / 4;
        return sum;
    }
    return 0;
}