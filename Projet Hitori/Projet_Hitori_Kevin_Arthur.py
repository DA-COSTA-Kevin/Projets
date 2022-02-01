from upemtk import *

def lire_grille (nom_fichier):
    """
    Fonction qui initialise la grille de jeu en le recupérent dans le fichier que l'on indique. La grille sera stoqué dans une liste de liste, chaque liste representera une ligne.
    
    : Param nom_fichier : str (nom du fichier ou il y a la grille)
    : return val : list (grille dans une liste de liste)
    """
    f = open(nom_fichier, 'r')
    lst_lignes = []
    for ligne in f:
        ligne = ligne.replace('\n', '').split(' ')
        lst_lignes.append(ligne)
    return lst_lignes

def affiche_grille (grille):
    """
    Fonction qui vas afficher la grille sur une fenetre faite avec la bobliotheque upemtk.
    
    : Param grille : list (liste de la grille de jeu)
    """
    for ligne in range(len(grille)) :
        for elem in range(len(grille[ligne])) :
            rectangle(elem * taille_case, ligne * taille_case, elem * taille_case + taille_case - 1, ligne * taille_case + taille_case - 1, remplissage = 'white')
            texte(elem * taille_case, ligne * taille_case, grille[ligne][elem], couleur = 'black', police = 'Marker Felt', taille = 30)
            

def ecrir_grille(grille, nom_fichier):
    """
    Fonction qui ecrit les element de grille dans un fichier pour sauvegarder la grille de jeu.
    
    : Param grille : list (liste de la grille de jeu)
    : Param nom_fichier : str (nom du fichier ou il y a la grille)
    """
    pass

def pixel_vers_case (x, y) :
    """
    Fonction qui reçoit  les coordonnées (x, y) d’un pixel et renvoie le numéro de la ligne et le numéro de la colonne de la case de la grille qui contient ce pixel.

    : Param x : int (coordonné du clique verticalement)
    : Param y : int (coordonné du clique horizontalement)
    : return val : tuple (coordonnés de la case ou on a cliqué)
    """
    pass

def  sans_voisines_noircies (grille, noircies):
    """
    Fonction qui teste si  aucune cellule noircie n’est voisine, car deux cases noirs ne peuvent pas se toucher. Si  aucune cellule noircie n’est voisine, on renvoi True, sinon on renvoi False.
    
    : Param grille : list (liste de la grille de jeu)
    : Param noircies : set (enssemble des coordonnés des cases noircies)
    : return val : bool (aucune cellule noircie n’est voisine)
    
    >>>sans_voisines_noircies([[1, 3, 2]], {(0, 0), [(0, 1)})
    False
    >>>sans_voisines_noircies([[3, 1, 2]], {(0, 0), (0, 2)})
    True 
    """
    pass

def place_noirs (case, noircies):
    """
    Fonction qui place une case noire à l'endroit où on a cliqué. Les coordonnés de la case seront mises dans un ensemble.
    
    : Param case : tuple (coordonés de la case)
    : Param noircies : set (enssemble des coordonnés des cases noircies) 
    
    >>>noircies = {(0, 1), (0, 2)}
    >>>place_noirs((0, 3), noircies)
    >>>print(noircies)
    {(0, 1), (0, 2), (0, 3)}
    """
    pass

def connexe (grille, noircies) :
    """
    Fonction qui test si toutes les cases visibles sont d'un seul tenant. Si elles sont toutes d'un seul tenant, on renvoi True, sinon on renvoinb_boucles False.
    
    : Param grille : list (liste de la grille de jeu)  
    : Param noircies : set (enssemble des coordonnés des cases noircies)
    : return val : bool (les cases visibles sont d'un seul tenant)
    
    >>> connexe([[1, 2, 3], [1, 2, 3]], {(0, 1)})
    True
    >>> connexe([[1, 2, 3], [1, 2, 3]], {(1, 0), (0, 1)})
    False
    """
    pass

def retire_noirs (noircies, case):
    """
    Fonction qui vas retirer une case noire et qui vas remettre le numéro à la place. On vas retirer les coordonnés de la case de l'enssemble noircies.
    
    : Param case : tuple (coordonés de la case)
    : Param noircies : set (enssemble des coordonnés des cases noircies) 
    
    >>>noircies = {(0, 1), (0, 2)}
    >>>retire_noirs(noircies, (0, 1))
    >>>print(noircies)
    {(0, 2)}
    """
    pass

def sans_conflit (grille, noircies):
    """
    Fonction qui vas tester  si aucune des cases visibles de la grille ne contient le même nombre qu’une autre case visible située sur la même ligne ou la même colonne. Si cette condition est respectée, on renvoit True, sinon on renvoit False.
    
    : Param grille : list (liste de la grille de jeu)  
    : Param noircies : set (enssemble des coordonnés des cases noircies) 
    : return val : bool (aucune case ne contient le meme nombre qu une autre case sur la meme ligne ou la meme colonne)
    
    >>>sans_conflit([[1, 2, 3], [1, 3, 2]], {(0, 0)})
    True
    >>>sans_conflit([[1, 2, 3], [1, 3, 2]], {(0, 1), (1, 2)})
    False 
    """
    pass

## Programme principale

#creation du menu d'accueil 
cree_fenetre(800 ,450)

while True :
    # fond du menu
    image(400,225,"hitori.png")
    # gestion du menu 
    x, y = attend_clic_gauche()
    # si on clique sur la case "play" cela lance la suite
    if x >= 190 and x <= 620 and y >= 300 and y <= 410 :
        ferme_fenetre()
    # sinon on recommence 
    else :
        continue
    # on passe à la suite
    break

#creation du menu secondaire 
cree_fenetre(400 ,400)

while True :
    texte(100, 100, 'Grille standard',couleur = 'firebrick') 
    texte(100, 250, 'Charger une partie',couleur = 'firebrick')
    # gestion du menu 
    x, y = attend_clic_gauche()
    print(x,y)
    # si on clique sur la case "play" cela lance la suite
    if x >= 100 and x <= 300 and y >= 100 and y <= 120 :
        taille_case = 80
        ferme_fenetre()
    # sinon on recommence 
    elif x >= 100 and x <= 350 and y >= 250 and y <= 270 :
        continue
    else :
        continue
    # on passe à la suite
    break
    

# affichage de la grille 
grille = lire_grille('grille_1.txt')
cree_fenetre(len(grille[0]) * taille_case, len(grille) * taille_case)
while True:
        affiche_grille(grille)
        attend_fermeture()