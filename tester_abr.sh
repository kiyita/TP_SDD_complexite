#!/bin/bash

EXE=./test_abr
DOSSIER=extraits
RESULTATS=resultats_abr

mkdir -p $RESULTATS

# Liste les fichiers TSV dans l'ordre croissant de taille
for fichier in $(ls $DOSSIER/title_*.tsv | sort -V); do
    nom=$(basename "$fichier" .tsv)  # Ex: title_1000
    echo "=== Test avec $fichier ==="
    $EXE "$fichier" | tee "$RESULTATS/$nom.txt"
done
