/* Copyright Steve Chen 2020 <schen07@etud.u-pem.fr>
   Copyright Kévin Da Costa Moura 2020 <kdacos01@etud.u-pem.fr>
   Project in C : Image compress.
   Date : 22/11/2020. */

/* File.h */

/* Importation of modules. */ 
#include <stdlib.h>
#include <string.h>
#include "Graphic.h"

/* Prototypes of functions. */

/*
try to open file if it's possible return the file else
exit the program.
@param  : name -> nae of the file.
@param  : mode -> which mode we open the file.
@return : file if it's possible else exit.
*/
FILE *tryOpenFile(char *name, char *mode);

/*
Save Qtree in .qtn file intern nodes are coding by 0 and
sheets are coding by 1 following by 1 for black and 0 for white.
@param : QuadTree Qtree (the qtree of image)
@param : FILE * file (the file of image)
*/
void saveBW(QuadTree Qtree, FILE * file);

/*
Save Qtree in .qtc file intern nodes are coding by 0 and
sheets are coding by 1 following by 4 bytes which represents rgba.
@param : QuadTree Qtree (the qtree of image)
@param : FILE * file (the file of image)
*/
void saveRGBA(QuadTree Qtree, FILE *file);

/*
Save the position of the quadtree zone in pos.txt
*/
void savePos(QuadTree Qtree, FILE *file);
/*
This function allows to read a .qtn file which corresponds to a black and white image,
according to the values ​​encountered in this file the nodes of the qtree are create.
@param : QuadTree Qtree (the qtree product by the save of image)
@param : FILE * file (the save of image)
*/
void readBW(QuadTree *Qtree, FILE *file, FILE *fpos);

/*
This function allows to read a .qtc file which corresponds to a color image,
according to the values ​​encountered in this file the nodes of the qtree are create.
@param : QuadTree Qtree (the qtree product by the save of image)
@param : FILE * file (the save of image)
*/
void readColor(QuadTree *Qtree, FILE *file, FILE *fpos);

/*
This function allows to read a .qtn file which corresponds to a black & white image minimalize,
according to the values ​​encountered in this file the nodes of the qtree are create.
*/
void readGraphBW();

/*
This function allows to read a .qtn file which corresponds to a color image minimalize,
according to the values ​​encountered in this file the nodes of the qtree are create.
*/
void readGraphColor();

/*
Allows to retrieve the extension of a file.
@param : char ext[4] (the extention of image)
@param : char *name (the name of extention)
*/
void fileExt(char ext[4], char *name);

/*
Depending on the file extension given as a parameter to this function, perform the corresponding operation : 
if it's a .qtc or .qtn launches the loading of the image otherwise for all other types launches the main program.
@param : QuadTree Qtree (the qtree of image)
@param : MLV_Image *img (the image)
@param : char ext[4] (the extention of image)
@param : char *name (the name of extention)
*/
int openByExt(QuadTree *Qtree, MLV_Image **img, char ext[4], char *name);