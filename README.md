Note : attention aux petits changements à faire sur mainHelp.c quand on veut passer des tests sur les AVLs aux tests sur les ABRs
Liste des changement :
- le include
- ajoutEnFeuille(t, pfilm); pour AVL et ajoutEnFeuille(&t, pfilm); pour ABR

Pour compiler et exécuter :
gcc -Wall    librairie_film/mainHelp.c     librairie_film/film.c     librairie_film/complexite.c     librairie_film/avl.c     -o test_abr
./tester_abr.sh
python3 courbe.py
