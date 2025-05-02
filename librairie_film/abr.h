#ifndef ABR_H
#define ABR_H

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "film.h"
#include "complexite.h"

typedef struct TABR {
    t_film* film;
    struct TABR* gauche;
    struct TABR* droite;
} *TABR;

void init_Tree(TABR* t);
TABR creerNoeud(t_film* pf);
TABR arbreVide();
void ajoutEnFeuille(TABR *abr, t_film* pf);
bool recherche(TABR abr, int num);
void afficher(TABR abr);

#endif
