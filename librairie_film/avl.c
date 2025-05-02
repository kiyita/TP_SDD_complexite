#include "avl.h"

int max(int a, int b) {
    return (a > b) ? a : b;
}

int hauteur(TAVL arbre) {
    if (arbre == NULL) return 0;
    return arbre->hauteur;
}

int calculEquilibre(TAVL arbre) {
    if (!arbre) return 0;
    return hauteur(arbre->gauche) - hauteur(arbre->droite);
}

TAVL creerNoeud(t_film* pf) {
    TAVL noeud = (TAVL) allouer(sizeof(struct AVL));
    noeud->film = pf;
    noeud->gauche = NULL;
    noeud->droite = NULL;
    noeud->hauteur = 1;
    return noeud;
}

void init_Tree(TAVL* t) {
    *t = NULL;
}

TAVL rotationDroite(TAVL y) {
    operation_elementaire();
    TAVL x = y->gauche;
    TAVL T2 = x->droite;

    x->droite = y;
    y->gauche = T2;

    y->hauteur = max(hauteur(y->gauche), hauteur(y->droite)) + 1;
    x->hauteur = max(hauteur(x->gauche), hauteur(x->droite)) + 1;

    return x;
}

TAVL rotationGauche(TAVL x) {
    operation_elementaire();
    TAVL y = x->droite;
    TAVL T2 = y->gauche;

    y->gauche = x;
    x->droite = T2;

    x->hauteur = max(hauteur(x->gauche), hauteur(x->droite)) + 1;
    y->hauteur = max(hauteur(y->gauche), hauteur(y->droite)) + 1;

    return y;
}

TAVL ajoutEnFeuille(TAVL arbre, t_film* pf) {
    operation_elementaire();
    if (arbre == NULL)
        return creerNoeud(pf);

    if (pf->num < arbre->film->num) {
        operation_elementaire();
        arbre->gauche = ajoutEnFeuille(arbre->gauche, pf);
    } else if (pf->num > arbre->film->num) {
        operation_elementaire();
        arbre->droite = ajoutEnFeuille(arbre->droite, pf);
    } else {
        return arbre; // Doublon
    }

    arbre->hauteur = 1 + max(hauteur(arbre->gauche), hauteur(arbre->droite));
    int balance = calculEquilibre(arbre);

    // Cas gauche gauche
    if (balance > 1 && pf->num < arbre->gauche->film->num)
        return rotationDroite(arbre);

    // Cas droite droite
    if (balance < -1 && pf->num > arbre->droite->film->num)
        return rotationGauche(arbre);

    // Cas gauche droite
    if (balance > 1 && pf->num > arbre->gauche->film->num) {
        arbre->gauche = rotationGauche(arbre->gauche);
        return rotationDroite(arbre);
    }

    // Cas droite gauche
    if (balance < -1 && pf->num < arbre->droite->film->num) {
        arbre->droite = rotationDroite(arbre->droite);
        return rotationGauche(arbre);
    }

    return arbre;
}

bool recherche(TAVL arbre, int num) {
    operation_elementaire();
    if (!arbre) return false;
    if (num == arbre->film->num) return true;
    if (num < arbre->film->num) {
        operation_elementaire();
        return recherche(arbre->gauche, num);
    } else {
        operation_elementaire();
        return recherche(arbre->droite, num);
    }
}

void afficherAVL(TAVL arbre) {
    if (arbre == NULL) {
        printf("\\");
        return;
    }
    printf("(%d, ", arbre->film->num);
    afficherAVL(arbre->gauche);
    printf(", ");
    afficherAVL(arbre->droite);
    printf(")");
}
