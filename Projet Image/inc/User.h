/* Copyright Steve Chen 2020 <schen07@etud.u-pem.fr>
   Copyright Kévin Da Costa Moura 2020 <kdacos01@etud.u-pem.fr>
   Project in C : Image compress.
   Date : 22/11/2020. */

/* User.h */
#ifndef __USER__
#define __USER__

/* Importation of modules. */ 
#include "File.h"

/* Prototypes of functions. */

/*
Return int to know what option the user choosed if
the user click on no option the function return -1.
@return : int -> between 1-7 if the user click on option else -1.
*/
int waitChoice();

#endif