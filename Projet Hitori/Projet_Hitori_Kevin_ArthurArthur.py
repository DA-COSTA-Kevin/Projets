from upemtk import *

def lire_grille (nom_fichier):
    """
    Fonction qui initialise la grille de jeu en le recupérent dans le fichier que l'on indique. La grille sera stoqué dans une liste de liste, chaque liste representera une ligne.
    
    : Param nom_fichier : str (nom du fichier ou il y a la grille)
    : return val : list (grille dans une liste de liste)
    """
    f = open(nom_fichier, 'r')
    lst_lignes = []
    lst_nb = ['0', '1', '2', '3', '4', '5', '6', '7', '8', '9']
    for ligne in f:
        ligne = ligne.replace('\n', '').split(' ')
        lst_lignes.append(ligne)
        if len(lst_lignes[0]) != len(lst_lignes[-1]):
            return None
        for elem in lst_lignes[-1]:
            if not(elem in lst_nb):
                return None
    return lst_lignes

def affiche_grille (grille):
    """
    Fonction qui vas afficher la grille sur une fenetre faite avec la bobliotheque upemtk.
    
    : Param grille : list (liste de la grille de jeu)
    """
    for ligne in range(len(grille)) :
        for elem in range(len(grille[ligne])) :
            rectangle(elem * taille_case, ligne * taille_case, elem * taille_case + taille_case - 1, ligne * taille_case + taille_case - 1, remplissage = 'lightgrey')
            texte(elem * taille_case + taille_case / 3, ligne * taille_case + taille_case / 4, grille[ligne][elem], couleur = 'black', police = 'Marker Felt', taille = 30)
            
## Note 8/20
# A MODIFIER SA SAUVEGARDE PAS BIEN :p et ta lecture de grille !!!!

def ecrir_grille(grille, nom_fichier):
    """
    Fonction qui ecrit les element de grille dans un fichier pour sauvegarder la grille de jeu.
    
    : Param grille : list (liste de la grille de jeu)
    : Param nom_fichier : str (nom du fichier ou il y a la grille)
    """
    f = open(nom_fichier, 'w')  
    for ligne in grille[:len(grille) - 1]:
        for elem in ligne[:len(ligne) - 1]:
            f.write(str(elem)+ ' ') 
        f.write(str(ligne[-1]))
        f.write('\n')
    ligne_d = grille[-1]
    for elem in ligne_d[:len(ligne) - 1]:
        f.write(str(elem)+ ' ')
    f.write(str(ligne_d[-1])) 
    f.close()

def ecrir_noircies(noircies, nom_fichier):
    f = open(nom_fichier, 'w')  
    for elem in noircies:
            f.write(str(elem)+ ' ') 
        f.write('\n')
    f.close()
    
def pixel_vers_case (x, y) :
    """
    Fonction qui reçoit  les coordonnées (x, y) d’un pixel et renvoie le numéro de la ligne et le numéro de la colonne de la case de la grille qui contient ce pixel.

    : Param x : int (coordonné du clique verticalement)
    : Param y : int (coordonné du clique horizontalement)
    : return val : tuple (coordonnés de la case ou on a cliqué)
    """
    pos_colonne = 0
    while x >= taille_case :
        x -= taille_case
        pos_colonne += 1
    pos_ligne = 0
    while y >= taille_case:
        y -= taille_case
        pos_ligne += 1 
    return pos_ligne, pos_colonne 

def  sans_voisines_noircies (grille, noircies):
    """
    Fonction qui teste si  aucune cellule noircie n’est voisine, car deux cases noirs ne peuvent pas se toucher. Si  aucune cellule noircie n’est voisine, on renvoi True, sinon on renvoi False.
    
    : Param grille : list (liste de la grille de jeu)
    : Param noircies : set (enssemble des coordonnés des cases noircies)
    : return val : bool (aucune cellule noircie n’est voisine)
    
    >>>sans_voisines_noircies([[1, 3, 2]], {(0, 0), (0, 1)})
    False
    >>>sans_voisines_noircies([[3, 1, 2]], {(0, 0), (0, 2)})
    True 
    """
    for (lig,col) in noircies :
        if (lig,(col +1)) in noircies :
            return False
    return True

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
    (lig,col) = case
    rectangle(taille_case * col,taille_case * lig, (taille_case * col) + taille_case - 1, (taille_case * lig) + taille_case - 1, remplissage = 'black')
    noircies.add(case)

def connexe (grille, noircies) :
    """
    Fonction qui test si toutes les cases visibles sont d'un seul tenant. Si elles sont toutes d'un seul tenant, on renvoi True, sinon on renvoi nb_boucles False.
    
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
    noircies.remove(case)

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
cree_fenetre(600 ,450)

while True :
    # fond du menu
    image(300,225,"Menu.png")
    # Bouton "grille standard" et "charger une partie"
    rectangle(150,145,370,190,couleur = 'firebrick',remplissage = "gold")
    texte(150, 150, 'Grille standard',couleur = 'firebrick')
    rectangle(150,290,425,340,couleur = 'firebrick',remplissage = "gold")
    texte(150, 300, 'Charger une partie',couleur = 'firebrick')
    # gestion du menu 
    x, y = attend_clic_gauche()
    # si on clique sur la case "grille standard" cela lance la suite
    if x >= 150 and x <= 370 and y >= 145 and y <= 190 :
        taille_case = 80
        grille = lire_grille('grille_1.txt')
        # on definie noircies
        noircies = set()
        ferme_fenetre()
    # si on clique sur la case "charger une partie" cela lance la suite avec la grille sauvegarder 
    elif x >= 150 and x <= 425 and y >= 290 and y <= 340 :
        taille_case = 80
        grille = lire_grille("grille_save.txt")
        noircies = lire_noircies('noircies_save')
        print(grille)
        ferme_fenetre()
    # sinon on recommence    
    else :
        continue
    # on passe à la suite
    break
    

# affichage de la grille 
cree_fenetre(len(grille[0]) * taille_case + 250, len(grille) * taille_case)

while True:
        affiche_grille(grille)
        # bouton de "sauvegarde" et pour "quitter" 
        
        # on crée une variable x1 pour que les boutons soit bien alignés quelque soit la taille de la grille 
        x1 = len(grille[0]) * taille_case + 25
        #'sauvegarder'
        texte(x1 ,100, 'Sauvegarder', couleur = 'green', police = 'Luminari', taille = 25)
        rectangle(x1 - 10, 100, x1 + 220 , 140, couleur = 'green', epaisseur = '3') 
        #'quitter'
        texte(x1,200, 'Quitter', couleur = 'red', police = 'Luminari', taille = 25)
        rectangle(x1 - 10, 200, x1 + 125, 240, couleur = 'red', epaisseur = '3') 
        # on vérifie si l'utilisateur clique sur l'un des boutons 
        x, y = attend_clic_gauche()
        if x >= (x1 - 10) and x <= (x1 + 220) and y <= 140 and y >= 100 :
            ecrir_grille(grille,"grille_save.txt")
            ecrir_noircies(noircies,"noircies_save.txt")
            print('sauvegardé')
            continue
        elif x >= (x1 - 10) and x <= (x1 + 125) and y <= 240 and y >= 200 :
            ferme_fenetre()
            break
        elif x <= len(grille[0]) * taille_case and y <= len(grille) * taille_case :
            lig,col = pixel_vers_case(x,y)
            case = (lig,col)
            if case in noircies :
                retire_noirs(noircies,case)
            else :
                if sans_voisines_noircies (grille, noircies) == True :
                    place_noirs (case, noircies)
        # suite ...
        # attend_fermeture()