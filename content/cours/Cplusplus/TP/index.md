+++
title = "TP C++"
weight = 110

[params]
  menuPre = '<i class="fa-solid fa-flask"></i> '
+++

![alt text](alexandrie.png?width=20vw)
## Énoncé

Vous prenez la suite d'un autre stagiaire dans le département informatique d'une bibliothèque.

Il s'agit de reprendre un logiciel de gestion des usagers et des livres. C'est un code ancien qui a besoin d'un peu de maintenance et de nouvelles fonctionnalités.

Il y a un binaire fonctionnel utilisé par les agents de la bibliothèque, mais le code est incomplet sur le repos.
Binaire disponnible : [bibliotheque](bibliotheque)


**Voici les fonctionnalités principales du binaire** :
- Ajouter/supprimer des livres de la bibliothèque
- Rechercher des livres par titre ou auteur
- Emprunter/retourner des livres
- Afficher les livres disponibles
- Sauvegarder l'état de la bibliothèque dans un fichier et recharger au démarrage

## Évaluation

Ce travail compte pour **20%** de votre session et sera corrigé selon la grille suivante :

|Critère|Pourcentage|
|---|---|
| Completion du code manquant | **25%** |
| Ajout de nouvelles fonctionalitées | **50%** |
| Veille technologique | **25%** |
|**Total**| **100%** |

> Le travail se fait seul.

## Spécifications détaillées

- Utilisez le dev container par défaut C++ de vscode. Comme vu [ici](../introduction/#un-premier-programme).
- Ce projet utilise cmake, pensez à créer un répertoire `build`. Comme vu [ici](../fonctions/#cmake)
- Le code est disponible sur git

[<i class="fa-brands fa-github"></i> Repos Github](https://classroom.github.com/a/c3m8ThN0) classroom du projet

> [!warning] **Remise**
> Le dernier commit pour la remise doit être fais avant :
> - **Groupe 1** : Remise le 28/10 23h59
> - **Groupe 2** : Remise le 27/10 23h59

### Combler les trous dans le code

Il y a une erreur de faite avant le premier commit, et une partie du code a été perdu, le fichier `book.cpp` est manquant. Servez-vous du fichier d'entête pour le compléter.

> [!tip]
> Pour les fonctions relative à la sauvegarde de fichier, pensez a utiliser les fichiers d'exemple fournis `books.txt`.
>
> Vous devrez être capable de lire ce fichiers une fois `books.cpp`complété.

### Ajout de nouvelles fonctionnalités

Vous devez ajouter 2 nouvelles fonctionnalités tirée du backlog du projet : 
- 1 fonctionnalité au choix dans *Interface et Expérience Utilisateur*
- 1 fonctionnalité au choix dans *Gestion des Données*
- La fonctionnalité bonus n'est pas obligatoire, mais c'est un défi intéressant. Elle compte pour 10% de plus. Si jamais vous obtenez une note supérieure à 100%, points au-dessus de 100 seront reportés proportionnelement pour la note suivante.

#### Interface et Expérience Utilisateur

- Confirmation avant suppression de livres.
- numérotation automatique des ID utilisateurs.
- Validation robuste des entrées (ISBN format, nom utilisateur, etc.)
- Détection des doublons plus intelligente (même titre, auteur, ISBN).

#### Gestion des Données

- Tri des résultats par titre, auteur pour l'affichage (utilisation de la fonction de tri de la STL).
- Import/Export CSV pour faciliter la gestion en lot (en plus du format actuel).

#### Bonus
- Logs d'activité (qui a emprunté quoi et quand) avec sauvegarde dans un fichier.

### Veille technologique
Donnez ces explications dans le README.md à la racine du dépôt. Un paragraphe par questions est suffisant.

#### Question 1 : C++
Expliquez en détails une fonctionnalité / notion dans le code que ne nous avons pas ou peu vu en cours.

#### Question 2 : Options de développement possible
Proposez une solution plus adaptée pour la gestion de bibliothèque et faisant appel éventuellement à une technologie autre que le C++, et expliquez comment vous interfaceriez ça avec le C++. Pensez au futur de cette bibliothèque à Alexandrie qui pourrait éventuellement contenir des millions de livres.