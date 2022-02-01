/* Copyright Steve Chen 2020 <schen07@etud.u-pem.fr>
   Copyright Kévin Da Costa Moura 2020 <kdacos01@etud.u-pem.fr>
   Project in C : Image compress.
   Date : 22/11/2020. */

/* Importation of modules. */ 
#include "File.h"

/* Functions. */
FILE *tryOpenFile(char *name, char *mode) {
    FILE *file;

    if((file = fopen(name, mode)) == NULL) {
        fprintf(stderr, "Image not found please verify the name.\n");
        exit(0);
    }
    return file;
}

void saveBW(QuadTree Qtree, FILE *file) {
    if(Qtree == NULL){
        return;
    }
    if(isLeaf(Qtree)) {
        fprintf(file, "1%d", Qtree->pixel.bit);
    } else {
        fprintf(file, "0");
    }
    saveBW(Qtree->northWest, file);
    saveBW(Qtree->northEast, file);
    saveBW(Qtree->southWest, file);
    saveBW(Qtree->southEast, file);
}

void saveRGBA(QuadTree Qtree, FILE *file) {
    if(Qtree == NULL){
        return;
    }
    if(isLeaf(Qtree)) {
        fprintf(file, "1 %d %d %d %d ", Qtree->pixel.color[0], Qtree->pixel.color[1], Qtree->pixel.color[2], Qtree->pixel.color[3]);
    } else {
        fprintf(file, "0 ");
    }
    saveRGBA(Qtree->northWest, file);
    saveRGBA(Qtree->northEast, file);
    saveRGBA(Qtree->southWest, file);
    saveRGBA(Qtree->southEast, file);
}

void saveGraphBW(QuadTree Qtree, FILE *file) {
    return;
}

void saveGraphColor(QuadTree Qtree, FILE *file) {
    return;
}

void savePos(QuadTree Qtree, FILE *file) {
    if(Qtree == NULL) {
        return;
    }
    if(isLeaf(Qtree)) {
        fprintf(file, "%d %d %d %d ", Qtree->pos.x, Qtree->pos.y, Qtree->pos.x1, Qtree->pos.y1);
    }
    savePos(Qtree->northWest, file);
    savePos(Qtree->northEast, file);
    savePos(Qtree->southWest, file);
    savePos(Qtree->southEast, file);
}

void readBW(QuadTree *Qtree, FILE *file, FILE *fpos) {
    union Pixel p;
    Position pos;
    char c;
    int i, tmp[4];

    if((c = fgetc(file)) != EOF) {
        if(atoi(&c) == 1) {
            if((c = fgetc(file)) != EOF) {
                p.bit = atoi(&c);
                for(i = 0; i < 4; i++) {
                    fscanf(fpos, "%d", &tmp[i]);
                }
                getPosition(&pos, tmp[0], tmp[1], tmp[2], tmp[3]);
                *Qtree = allocateCell(p, pos, 0);
                return;
            }
        }
        p.bit = 0;
        *Qtree = allocateCell(p, pos, 0);
        readBW(&((*Qtree)->northWest), file, fpos);
        readBW(&((*Qtree)->northEast), file, fpos);
        readBW(&((*Qtree)->southWest), file, fpos);
        readBW(&((*Qtree)->southEast), file, fpos);
    }
}

void readColor(QuadTree *Qtree, FILE *file, FILE *fpos) {
    union Pixel p;
    Position pos;
    int i, value, tmp[4];

    fscanf(file, "%d", &value);

    if(value == 1) {
        for(i = 0; i < 4; i++) {
            fscanf(file, "%d", &value);
            p.color[i] = value;
        }
        for(i = 0; i < 4; i++) {
            fscanf(fpos, "%d", &tmp[i]);
        }
        getPosition(&pos, tmp[0], tmp[1], tmp[2], tmp[3]);
        *Qtree = allocateCell(p, pos, 0);
        return;
    }
    for(i = 0; i < 4; i++) {
        p.color[i] = 0;
    }
    getPosition(&pos, 0, 0, 0, 0);
    *Qtree = allocateCell(p, pos, 0);
    readColor(&((*Qtree)->northWest), file, fpos);
    readColor(&((*Qtree)->northEast), file, fpos);
    readColor(&((*Qtree)->southWest), file, fpos);
    readColor(&((*Qtree)->southEast), file, fpos);
}

void readGraphBW(QuadTree *Qtree, FILE *file) {
    return;
}

void readGraphColor(QuadTree *Qtree, FILE *file) {
    return;
}

void fileExt(char ext[4], char *name) {
    int i, ind;

    ind = 0;
    for(i = strlen(name) - 3; i < strlen(name); i++) {
        ext[ind++] = name[i];
    }
}

int openByExt(QuadTree *Qtree, MLV_Image **img, char ext[4], char *name) {
    FILE *file, *fpos;
    char path[32] = "img/";

    if(strcmp(ext, "qtn") == 0) {
        file = tryOpenFile(strcat(path, name), "r");
        fpos = tryOpenFile("img/pos.txt", "r");
        readBW(Qtree, file, fpos);
        fclose(file);
        fclose(fpos);
        return 0;
    }
    else if(strcmp(ext, "qtc") == 0) {
        file = tryOpenFile(strcat(path, name), "r");
        fpos = tryOpenFile("img/pos.txt", "r");
        readColor(Qtree, file, fpos);
        fclose(file);
        fclose(fpos);
        return 0;
    }
    else if(strcmp(ext, "gmn") == 0) {
        file = tryOpenFile(strcat(path, name), "r");
        readGraphBW(Qtree, file);
        return 0;
    }
    else if(strcmp(ext, "gmc") == 0) {
        file = tryOpenFile(strcat(path, name), "r");
        readGraphColor(Qtree, file);
        return 0;
    }
    else {
        displayWindow(img, name);
        return 1;
    }
    return 1;
}