#ifndef AVL_H
#define AVL_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "film.h"
#include "complexite.h"

typedef struct AVL {
    t_film* film;
    int hauteur;
    struct AVL* gauche;
    struct AVL* droite;
} *TAVL;

// Prototypes
TAVL creerNoeud(t_film* pf);
void init_Tree(TAVL* arbre);
TAVL ajoutEnFeuille(TAVL arbre, t_film* pf);
bool recherche(TAVL arbre, int num);
void afficherAVL(TAVL arbre);


#endif
