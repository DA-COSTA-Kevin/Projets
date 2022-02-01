/* Copyright Steve Chen 2020 <schen07@etud.u-pem.fr>
   Copyright Kévin Da Costa Moura 2020 <kdacos01@etud.u-pem.fr>
   Project in C : Image compress.
   Date : 22/11/2020. */

/* Importation of modules. */ 
#include "User.h"

int main(int argc, char *argv[]) {    
    MLV_Image *img;
    QuadTree Qtree;
    FILE *file;
    int choice, img_type, error;
    char name[64];
    static char ext[4];

    Qtree = NULL;
    img_type = 1;

    MLV_create_window("Image", "Image", WIDTH + MENU_WIDTH, HEIGHT);

    displayWindow(&img, "img1.jpg");

    while(1) {
        choice = waitChoice();

        if(choice == 1) {
            printf("How much do you want as error for the image : ");
            scanf("%d", &error);
            buildQuadTree(&Qtree, img, img_type, error);
            displayImage(Qtree, img_type);
            MLV_actualise_window();
            printf("Quadtree end !\n");
            free(Qtree);
        }
        if(choice == 2 && img_type == 0) {
            printf("How much do you want as error for the image : ");
            scanf("%d", &error);
            buildQuadTree(&Qtree, img, img_type, error);
            file = tryOpenFile("img/img.qtn", "w");
            saveBW(Qtree, file);
            fclose(file);
            file = tryOpenFile("img/pos.txt", "w");
            savePos(Qtree, file);
            fclose(file);
            printf("Image saved\n");
            free(Qtree);
        }
        if(choice == 3 && img_type == 1) {
            printf("How much do you want as error for the image : ");
            scanf("%d", &error);
            buildQuadTree(&Qtree, img, img_type, error);
            file = tryOpenFile("img/img.qtc", "w");
            saveRGBA(Qtree, file);
            fclose(file);
            file = tryOpenFile("img/pos.txt", "w");
            savePos(Qtree, file);
            fclose(file);
            printf("Image saved\n");
            free(Qtree);
        }
        if(choice == 7) {
            printf("Image name : ");
            scanf("%s", name);
            printf("Enter : 1 for color image 0 for black and white image : ");
            scanf("%d", &img_type);
            fileExt(ext, name);
            if(!openByExt(&Qtree, &img, ext, name)) {
                displayImage(Qtree, img_type);
                MLV_actualise_window();
            }
            printf("Image load\n");
        }
    }
    return 0;
}