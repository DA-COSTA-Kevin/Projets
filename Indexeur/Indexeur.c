#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Structure.h"

/*************************************/
void afficheListe(Liste lst,Listepos lstpos){
    if(lst == NULL){
      printf("La liste est vide !\n");
      return;
    }
    while(lst != NULL){
      printf("le mot [%s] -> [%d]\n", lst->valeur->mot, lstpos->position);
      lstpos = lstpos->suivant;
      lst = lst->suivant;
    }
}

/*************************************/
Cellule *alloueCellule(Celmot *val){
  Cellule *cell = (Cellule *)malloc(sizeof(cell));
  if(cell != NULL){
    cell->valeur = val;
    cell->suivant = NULL;
  }
  return cell;
}

Celpos *alloueCellulePos(int x){
  Celpos *pos = (Celpos *)malloc(sizeof(x));
  if(pos != NULL){
  	pos->position = x;
  	pos->suivant = NULL;
  }
  return pos;
}

Celmot *alloueCelluleMot(char *res,Listepos pos){
  int taille = strlen(res);
  Celmot *val = (Celmot *)malloc((taille + 1)  * sizeof(res));
  val->mot = res;
  val->position = pos;
  return val;
}

Cellule *alloueCellulechar(char *res){ 
	int taille = strlen(res); 
	Celmot *val = (Celmot *)malloc((taille + 1) * sizeof(res)); 
	val->mot = res; Cellule *cell = (Cellule *)malloc(sizeof(cell)); 
	if(cell != NULL){ 
		cell->valeur = val; 
		cell->suivant = NULL; 
	} 
	return cell; 
}

/*************************************/
int insert(Liste *lst, Listepos *lstpos){
    int c = EOF, flag = 0, cpt = 0, i = 0, posph = 0;
    char temp[100];
    char *mot;

    Liste tmp;
    Listepos pos;
    Celmot *word;

    FILE *fichier = fopen("fichier.txt.ascii", "r");
    if(fichier != NULL){
        while((c = fgetc(fichier)) != EOF){
            if(c != '\n' && c != ' ' && c != '.' &&c != '?' && c != ';' && c != '!' && c != ',' && c != ':'){
                flag = 1;
                temp[cpt] = c;
                cpt ++;
                i++;
            }
            else{
                flag = 0;
            }
            if(flag == 0){
                cpt = 0;
                i++;
	        	mot = strdup(temp);
	        	memset(temp, 0, sizeof(temp));
	        	pos = alloueCellulePos(posph);
	        	if(*lstpos!= NULL){
	        		Listepos temp;
	        		temp = *lstpos;
	        		while(temp->suivant != NULL){
	        			temp = temp->suivant;
	        		}
	        	    temp->suivant = pos;
	        	    pos = temp;
	        	}
	        	else{
			    	pos->suivant = NULL;
			    	*lstpos = pos;
	        	}
	        	word = alloueCelluleMot(mot,pos);
                tmp = alloueCellule(word);
	        	if(*lst!= NULL){
	        		Liste elmt;
	        		elmt = *lst;
	        		while(elmt->suivant != NULL){
	        			elmt = elmt->suivant;
	        		}
	        		elmt->suivant = tmp;	
	        		tmp = elmt;
	        	}
	        	else{
			    	tmp->suivant = NULL;
			    	*lst = tmp;
	        	}
	        	
	            if(c == '!' || c == '?' || c =='.'){
	                posph = 1 + i;
	            }
            }
        }
    }
    fclose(fichier);
    return 0;
}

/* fonction pour sauvegarder la liste dans un fichier */
void Save(Liste lst,Listepos lstpos){
	FILE * fichier;
	fichier = fopen("fichier.DICO", "w");
	if(lst == NULL){
      fprintf(fichier,"La liste est vide !\n");
      return;
    }
    while(lst != NULL){
      fprintf(fichier,"mot [%s] -> [%d]\n", lst->valeur->mot, lstpos->position);
      lstpos = lstpos->suivant;
      lst = lst->suivant;
    }
	fclose(fichier);
}

/* fonction qui affiche la suite des positions du mot choisi dans le texte */
void affichePosMot(Liste lst,Listepos lstpos, char *rech){
	char *res;
	printf("La position du mot [%s] est ", rech);
	while(lst != NULL){
		res = lst->valeur->mot;
		if(strcmp(res,rech) == 0){
			printf("[%d]", lstpos->position);
			lstpos = lstpos->suivant;
			lst = lst->suivant;
		}
		else{
			lstpos = lstpos->suivant;
			lst = lst->suivant;
		}
	}
	printf("\n");
}

/* fonction pour l'afficher les mot commençant par le prefixe donnée*/
void afficheMotPrefixe(Liste lst,char *rech){
	int taille = strlen(rech);
	int flag = 0;
	char prefixe_M[taille];
	char *res;
	int cpt = 0;
	while(lst != NULL){
		res = lst->valeur->mot;
		while(cpt < taille){
			prefixe_M[cpt] = res[cpt];
			cpt ++;
		}
		if(strcmp(rech,prefixe_M) != 0){
			cpt = 0;
			lst = lst->suivant;
		}
		else{
			cpt = 0;
			printf("Mot : [%s]\n", res);
			lst = lst->suivant;
			flag = 1;
		}
	}
	if(flag == 0){
		printf("Il n'y a pas de mot commençant avec le prefixe [%s] \n",rech);
	}
}

/* fonction pour l'appartenance de mot au texte */
int appartenance(Liste lst, char *rech){
	char *res;
	while(lst != NULL){
		res = lst->valeur->mot;
		if(strcmp(res, rech) != 0){
			/*printf("[%s] != %s \n",res,rech);*/
			lst = lst->suivant;
		}
		else {
			printf("le mot [%s] est bien dans le texte !\n",rech);
			return 1;
		}
	}
	printf("le mot [%s] n'est pas dans le texte!\n",rech);
	return 0;
}

/* fonction qui affiche les phrases contenant mot*/
void AffichePhrase(Liste lst,Liste lst2, char *mot){
	int tmp,test;
	char *temp;
	char *res;
	Liste exemple;
	if(appartenance(lst, mot)){
		printf("Phrase obtenue avec le mot [%s] :\n",mot);
		while(lst != NULL){
		    res = lst->valeur->mot;
		    if(strcmp(res, mot) == 0){
			    tmp = lst->valeur->position->position;
			    exemple = lst2;
			    while(exemple != NULL){
			    	test = exemple->valeur->position->position;
			    	if(tmp == test){
			    		temp = exemple->valeur->mot; 
			        	exemple = exemple->suivant;
			        	printf("%s ",temp);
			    	}
			    	else{
			    		exemple = exemple->suivant;
			    	}
			    }
			    printf("\n");
			    lst = lst->suivant;
			}
			else{
				lst = lst->suivant;
			}
		}
	}
  else{
  	printf("Aucune phrase ne contient votre mot !\n");
	}
}

/*fonction qui affiche la liste trié*/
void AfficheTrie(Liste lst){
  Liste lst2 = lst;
  char *res;
  int ordre;
  if(lst == NULL){
    printf("La liste est vide \n");
  }
  else{
    while(lst2 != NULL){
      res = lst2->valeur->mot;
      while(lst != NULL){
        ordre = strcmp(res, lst->valeur->mot);
        if(ordre > 0){
          printf("[%s] \n", lst->valeur->mot);
          lst = lst->suivant;
        }
        else{
          lst = lst->suivant;
        }
      }
      lst2 = lst2->suivant;
    }
  }
}

int main(int argc, char *argv[]){
	Liste MyListe = NULL;
	Liste lsttest = NULL;
	Listepos MyListePos = NULL;
	Listepos lsttestpos = NULL;
	char *mot = "et";
	char *rechercher = "je";
	int ch = 1;
	
	int c;
	FILE*in,*out;
	char *s;

	if (2!=argc && 4!=argc){
	  fprintf(stderr,"usage %s fichier\n",argv[0]);
	  return 1;
	}
	if((in = fopen(argv[1], "r")) == NULL){
		fprintf(stderr, "Ouverture de %s en lecture impossible\n", argv[1]);
		return 1;
	}
	if((s = (char *)malloc(strlen(argv[1]) + 6)) == NULL){
		fprintf(stderr, "probleme memoire\n");
		return 1;
	}
	strcpy(s, argv[1]);
	strcat(s, ".ascii");
	if((out = fopen(s, "w")) == NULL){
		fprintf(stderr, "Ouverture de %s en écriture impossible\n", argv[1]);
		return 1;
	}
	while((c = fgetc(in)) != EOF){
		switch(c){
			case 192 : c = 'a'; break;
			case 193 : c = 'a'; break;
			case 194 : c = 'a'; break;
			case 195 : c = 'a'; break;
			case 196 : c = 'a'; break;
			case 197 : c = 'a'; break;
			case 198 : c = 'a'; break;
			case 199 : c = 'c'; break; /*C cedille*/
			case 200 : c = 'e'; break;
			case 201 : c = 'e'; break;
			case 202 : c = 'e'; break;
			case 203 : c = 'e'; break;
			case 204 : c = 'i'; break;
			case 205 : c = 'i'; break;
			case 206 : c = 'i'; break;
			case 207 : c = 'i'; break;
			case 208 : c = 'd'; break;
			case 209 : c = 'n'; break;
			case 210 : c = 'o'; break;
			case 211 : c = 'o'; break;
			case 212 : c = 'o'; break;
			case 213 : c = 'o'; break;
			case 214 : c = 'o'; break;
			case 216 : c = 'o'; break;
			case 217 : c = 'u'; break;
			case 218 : c = 'u'; break;
			case 219 : c = 'u'; break;
			case 220 : c = 'u'; break;
			case 221 : c = 'y'; break;
			case 224 : c = 'a'; break;
			case 225 : c = 'a'; break;
			case 226 : c = 'a'; break;
			case 227 : c = 'a'; break;
			case 228 : c = 'a'; break;
			case 229 : c = 'a'; break;
			case 230 : c = 'a'; break;
			case 231 : c = 'c'; break;
			case 232 : c = 'e'; break;
			case 233 : c = 'e'; break;
			case 234 : c = 'e'; break;
			case 235 : c = 'e'; break;
			case 236 : c = 'i'; break;
			case 237 : c = 'i'; break;
			case 238 : c = 'i'; break;
			case 239 : c = 'i'; break;
			case 241 : c = 'n'; break; 
			case 242 : c ='o'; break;
			case 243 : c ='o'; break;
			case 244 : c ='o'; break;
			case 245 : c ='o'; break;
			case 246 : c ='o'; break;
			case 248 : c ='o'; break;
			case 249 : c = 'u'; break;
			case 250 : c = 'u'; break;
			case 251 : c = 'u'; break;
			case 252 : c = 'u'; break;
			case 253 : c = 'y'; break;
			case 255 : c = 'y'; break;
		}
		fputc(c, out);
	}
	fclose(in);
	fclose(out);

	if(argc == 2){
		insert(&MyListe, &MyListePos);
	    afficheListe(MyListe, MyListePos);
	    appartenance(MyListe, mot);
	    printf("\n");
	    affichePosMot(MyListe, MyListePos, mot);
	    printf("\n");
	    afficheMotPrefixe(MyListe,rechercher);
	    insert(&lsttest,&lsttestpos);
	    AffichePhrase(MyListe,lsttest,mot);
	    printf("\n");
	    printf("Sauvegarde effectuer !\n");
	    Save(MyListe, MyListePos);
	    printf("Fin des démonstration des fonctions\n");
	    return 0;
	}
	else{
		if(argv[2][0] == '-'){
		while(argv[2][ch] != '\0'){
			switch(argv[2][ch]){
				case 'a' :
					insert(&MyListe, &MyListePos);
					/*afficheListe(MyListe,MyListePos);*/
					mot = argv[3];
					appartenance(MyListe, mot);
					ch++;
					break;
				case 'p' :
					insert(&MyListe, &MyListePos);
					/*afficheListe(MyListe,MyListePos);*/
					mot = argv[3];
					affichePosMot(MyListe, MyListePos, mot);
					ch++;
					break;
				case 'P' :
					insert(&MyListe,&MyListePos);
					insert(&lsttest,&lsttestpos);
					/*afficheListe(MyListe,MyListePos);*/
					mot = argv[3];
					AffichePhrase(MyListe,lsttest,mot);
					ch++;
					break;
				case 'l' :
					insert(&MyListe,&MyListePos);
					/*afficheListe(MyListe,MyListePos);*/
					printf("Fonction trié ne fonctionne pas\n");
					ch++;
					break;
				case 'd' :
					insert(&MyListe,&MyListePos);
					/*afficheListe(MyListe,MyListePos);*/
					mot = argv[3];
					afficheMotPrefixe(MyListe,mot);
					ch++;
					break;
				case 'D' :
					insert(&MyListe,&MyListePos);
					/*afficheListe(MyListe,MyListePos);*/
					printf("sauvegarde effectuer!\n");
					Save(MyListe,MyListePos);
					ch++;
					break;
				default:
					printf("Erreur, veuillez réessayer !\n");
					return -1;
				}
			}
		}
	}
	return 0;
}
