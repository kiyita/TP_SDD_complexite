#include "abr.h"

TABR creerNoeud(t_film* pf) {
    TABR noeud = (TABR)allouer(sizeof(struct TABR));
    noeud->film = pf;
    noeud->gauche = NULL;
    noeud->droite = NULL;
    return noeud;
}

TABR arbreVide() {
    return NULL;
}

void init_Tree(TABR* t) {
    *t = NULL;
}

void ajoutEnFeuille(TABR *abr, t_film* pf) {
    operation_elementaire();
    if (*abr == NULL) {
        *abr = creerNoeud(pf);
    } else if (pf->num < (*abr)->film->num) {
        operation_elementaire();
        ajoutEnFeuille(&(*abr)->gauche, pf);
    } else if (pf->num > (*abr)->film->num) {
        operation_elementaire();
        ajoutEnFeuille(&(*abr)->droite, pf);
    }
}

bool recherche(TABR abr, int num) {
    operation_elementaire();
    if (abr == NULL) {
        return false;
    } else if (num < abr->film->num) {
        operation_elementaire();
        return recherche(abr->gauche, num);
    } else if (num > abr->film->num) {
        operation_elementaire();
        return recherche(abr->droite, num);
    } else {
        return true;
    }
}

void afficher(TABR abr) {
    if (abr == NULL) {
        printf("\\");
        return;
    }
    printf("(%d, ", abr->film->num);
    afficher(abr->gauche);
    printf(", ");
    afficher(abr->droite);
    printf(")");
}