# so_long

so_long est un projet du cursus 42 qui consiste à créer un petit jeu en 2D en utilisant la bibliothèque MiniLibX. Le joueur doit se déplacer sur une carte, collecter tous les objets et atteindre la sortie pour gagner.

## Description

- **Parsing** : Vérifie la validité de la carte (format `.ber`), sa forme rectangulaire, et la présence obligatoire d'éléments (player, exit, collectibles).
- **Mouvement** : Le joueur peut se déplacer avec les touches du clavier.
- **Graphismes** : Affichage de la carte et des éléments du jeu à l'aide de la MiniLibX.
- **Gestion d'événements** : Déplacement du joueur et fermeture correcte de la fenêtre.

## Installation

```bash
git clone https://github.com/sbr93z/so_long.git
cd so_long
make
```
## Utilisation
```bash
Lancer le jeu avec une carte :

./so_long maps/test.ber
```
Les déplacements se font au clavier (W, A, S, D).

## Fichiers

includes/so_long.h : Header principal du projet.

src/so_long.c : Fonction principale, initialisation et lancement du jeu.

src/parsing.c : Vérifie la validité de la carte.

src/parsing_utils.c : Fonctions utilitaires pour le parsing.

src/parsing_utils2.c : Fonctions supplémentaires pour le parsing.

src/floodfill.c : Vérifie si la carte est accessible avec un algorithme de remplissage.

src/mlx_utils.c : Fonctions pour l'affichage avec MiniLibX.

src/mlx_utils2.c : Fonctions supplémentaires pour l'affichage.

src/mouvement.c : Gestion du mouvement du joueur.

img/ : Contient les fichiers .xpm utilisés pour le rendu graphique (Background, Char, Coin, Exit, Wall).

maps/ : Dossier contenant des exemples de cartes (.ber).

libft/ : Ma bibliothèque personnelle (libft incluse avec ft_printf et get_next_line).

Makefile : Fichier pour compiler et nettoyer le projet.

## Commandes Makefile
```bash
make : Compile les programmes.

make clean : Supprime les fichiers objets.

make fclean : Supprime les fichiers objets et les exécutables.

make re : fclean puis make.
```
## Fonctionnement

Le programme charge la carte en mémoire.

Chaque déplacement du joueur est traité et le nombre de mouvements est affiché.

Le joueur doit récupérer tous les collectibles avant d'atteindre la sortie.

Si le joueur atteint la sortie sans avoir tout collecté, il ne peut pas gagner.

La fenêtre peut être fermée proprement avec la touche ESC ou la croix.
