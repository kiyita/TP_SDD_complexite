import os
import re
import matplotlib.pyplot as plt

# Dossier contenant les fichiers résultats
folder_path = os.path.join(os.path.dirname(__file__), "resultats_abr")

# Listes pour stocker les données
elements = []
load_times_us = []
search_times_us = []

# Regex pour extraire les données
regex_load = r"Temps de chargement de (\d+) elements.*?(\d+):(\d+):(\d+)"
regex_search_time = r"Temps cumulé pour \d+ recherches.*?(\d+):(\d+):(\d+)"

# Parcours des fichiers
for filename in sorted(os.listdir(folder_path)):
    if filename.endswith(".txt"):
        filepath = os.path.join(folder_path, filename)
        with open(filepath, "r", encoding="utf-8") as file:
            content = file.read()

            # Extraction du nombre d'éléments et du temps de chargement
            match_load = re.search(regex_load, content)
            match_search = re.search(regex_search_time, content)

            if match_load and match_search:
                n_elements = int(match_load.group(1))
                load_us = int(match_load.group(2)) * 1_000_000 + int(match_load.group(3)) * 1_000 + int(match_load.group(4))
                search_us = int(match_search.group(1)) * 1_000_000 + int(match_search.group(2)) * 1_000 + int(match_search.group(3))

                elements.append(n_elements)
                load_times_us.append(load_us)
                search_times_us.append(search_us)

# Affichage des résultats sous forme de courbes
plt.figure(figsize=(12, 5))

# Temps de chargement
plt.subplot(1, 2, 1)
plt.scatter(elements, load_times_us, marker='o', label="Chargement")
plt.xlabel("Nombre d'éléments")
plt.ylabel("Temps (µs)")
plt.title("Temps de chargement vs Nombre d'éléments")
plt.grid(True)

# Temps de recherche
plt.subplot(1, 2, 2)
plt.scatter(elements, search_times_us, marker='s', color='green', label="Recherche")
plt.xlabel("Nombre d'éléments")
plt.ylabel("Temps de recherche total (µs)")
plt.title("Temps de recherche vs Nombre d'éléments")
plt.grid(True)

plt.tight_layout()
plt.show()
