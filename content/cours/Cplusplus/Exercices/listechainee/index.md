+++
title = "Construction d'une Liste Chaînée"
weight = 100

# [params]
#  menuPre = '<i class="fa-solid fa-dumbbell"></i> '
+++

## Introduction

Cet exercice vous guide étape par étape dans la création d'une structure de données fondamentale : la liste chaînée. Vous allez construire progressivement toutes les fonctionnalités nécessaires pour manipuler cette structure.

> [!tip]- Conseils de développement
> ### Gestion mémoire :
> 
> - Toujours utiliser `new` pour créer des nœuds
> - Toujours utiliser `delete` pour libérer la mémoire
> - Vérifier que l'allocation a réussi
> 
> ### Cas particuliers à gérer :
> 
> - Liste vide (tête = `NULL`)
> - Liste à un seul élément
> - Opération sur le premier élément
> - Opération sur le dernier élément
> 
> ### Débogage :
> 
> - Ajoutez des `cout` pour tracer l'exécution
> - Vérifiez les pointeurs avant de les utiliser
> - Dessinez la liste sur papier pour visualiser les opérations
> 
> ### Test recommandé pour chaque étape :
> 
> ```cpp
> // Test avec liste vide
> // Test avec un élément
> // Test avec plusieurs éléments
> // Test des cas limites
> ```
> 


---

## Étape 1 : Utilisation de la classe Noeud

**Objectif :** Utiliser la structure de base d'un nœud de liste chaînée

### À faire :

1. Dans la fonction `main()`, créez manuellement 3 nœuds avec les valeurs 10, 20, 30
    
2. Reliez ces nœuds entre eux pour former une chaîne
    
3. Parcourez la liste en partant du premier nœud et affichez toutes les valeurs. 
    
### Code de départ :

```cpp
#include <iostream>
using namespace std;

class Noeud {
	public:
	    int valeur;
	    Noeud* suivant;
	    
	    // Constructeur pour faciliter la création
	    Noeud(int val) : valeur(val), suivant(nullptr) {}
	    
	    // Destructeur (optionnel, mais bonne pratique)
	    ~Noeud() {}
};

int main() {
    // TODO: Créer 3 nœuds et les relier
    // TODO: Parcourir et afficher la liste
    return 0;
}
```

### Sortie attendue :

```
Liste: 10 -> 20 -> 30 -> NULL
```

---

## Étape 2 : Fonction d'ajout en début de liste

**Objectif :** Créer une fonction pour ajouter un élément au début

### À faire :

1. Créez une fonction `ajouterDebut(Noeud*& tete, int valeur)` qui :
    - Crée un nouveau nœud avec la valeur donnée
    - Place ce nœud au début de la liste
    - Met à jour le pointeur de tête
2. Créez une fonction `afficherListe(Noeud* tete)` pour afficher proprement la liste
    
3. Testez en créant une liste vide puis en ajoutant les valeurs 30, 20, 10 (dans cet ordre)
    

### Prototype des fonctions :

```cpp
void ajouterDebut(Noeud*& tete, int valeur);
void afficherListe(Noeud* tete);
```

### Sortie attendue :

```
Liste après ajout de 30: 30 -> NULL
Liste après ajout de 20: 20 -> 30 -> NULL
Liste après ajout de 10: 10 -> 20 -> 30 -> NULL
```

---

## Étape 3 : Fonction d'ajout en fin de liste

**Objectif :** Ajouter des éléments à la fin de la liste

### À faire :

1. Créez une fonction `ajouterFin(Noeud*& tete, int valeur)` qui :
    
    - Gère le cas où la liste est vide
    - Parcourt jusqu'au dernier nœud
    - Ajoute le nouveau nœud à la fin
2. Testez avec une liste contenant [10, 20] et ajoutez 30, 40, 50 à la fin
    

### Prototype :

```cpp
void ajouterFin(Noeud*& tete, int valeur);
```

### Sortie attendue :

```
Liste initiale: 10 -> 20 -> NULL
Après ajout de 30: 10 -> 20 -> 30 -> NULL
Après ajout de 40: 10 -> 20 -> 30 -> 40 -> NULL
Après ajout de 50: 10 -> 20 -> 30 -> 40 -> 50 -> NULL
```

---

## Étape 4 : Fonction de recherche

**Objectif :** Rechercher un élément dans la liste

### À faire :

1. Créez une fonction `rechercher(Noeud* tete, int valeur)` qui :
    - Retourne `true` si la valeur est trouvée
    - Retourne `false` sinon
2. Créez une fonction `obtenirPosition(Noeud* tete, int valeur)` qui :
    - Retourne la position de l'élément (commence à 0)
    - Retourne -1 si l'élément n'est pas trouvé
3. Testez avec une liste [10, 20, 30, 40, 50] en recherchant 30, 60, et 10
    
### Prototypes :

```cpp
bool rechercher(Noeud* tete, int valeur);
int obtenirPosition(Noeud* tete, int valeur);
```

### Sortie attendue :

```
Recherche de 30: Trouvé à la position 2
Recherche de 60: Non trouvé (position -1)
Recherche de 10: Trouvé à la position 0
```

---

## Étape 5 : Fonction de suppression

**Objectif :** Supprimer des éléments de la liste

### À faire :

1. Créez une fonction `supprimerElement(Noeud*& tete, int valeur)` qui :
    
    - Supprime la première occurrence de la valeur
    - Gère le cas où l'élément à supprimer est en tête
    - Gère le cas où l'élément n'existe pas
    - Libère correctement la mémoire
    - Retourne `true` si la suppression a réussi, `false` sinon
2. Testez en supprimant différents éléments d'une liste
    

### Prototype :

```cpp
bool supprimerElement(Noeud*& tete, int valeur);
```

### Sortie attendue :

```
Liste initiale: 10 -> 20 -> 30 -> 40 -> 50 -> NULL
Suppression de 30: 10 -> 20 -> 40 -> 50 -> NULL (Réussi)
Suppression de 10: 20 -> 40 -> 50 -> NULL (Réussi)
Suppression de 60: 20 -> 40 -> 50 -> NULL (Échec - élément non trouvé)
```

---

## Étape 6 : Fonctions utilitaires

**Objectif :** Ajouter des fonctionnalités pratiques

### À faire :

1. Créez une fonction `compterElements(Noeud* tete)` qui retourne le nombre d'éléments
    
2. Créez une fonction `viderListe(Noeud*& tete)` qui :
    
    - Supprime tous les nœuds de la liste
    - Libère toute la mémoire
    - Met le pointeur de tête à `NULL`
3. Créez une fonction `inverserListe(Noeud*& tete)` qui inverse l'ordre des éléments
    

### Prototypes :

```cpp
int compterElements(Noeud* tete);
void viderListe(Noeud*& tete);
void inverserListe(Noeud*& tete);
```

### Sortie attendue :

```
Liste: 10 -> 20 -> 30 -> 40 -> NULL
Nombre d'éléments: 4
Liste inversée: 40 -> 30 -> 20 -> 10 -> NULL
Liste vidée: (liste vide)
```

---

## Étape 7 : Programme complet avec menu

**Objectif :** Créer un programme interactif utilisant toutes les fonctions

### À faire :

Créez un programme avec un menu qui permet à l'utilisateur de :

1. Ajouter un élément au début
2. Ajouter un élément à la fin
3. Rechercher un élément
4. Supprimer un élément
5. Afficher la liste
6. Compter les éléments
7. Inverser la liste
8. Vider la liste
9. Quitter

### Structure du menu :

```
=== GESTIONNAIRE DE LISTE CHAÎNÉE ===
1. Ajouter au début
2. Ajouter à la fin
3. Rechercher élément
4. Supprimer élément
5. Afficher liste
6. Compter éléments
7. Inverser liste
8. Vider liste
9. Quitter
Votre choix : _
```
## Solution 

> [!warning]- Solution
> [liste_chainee.cpp](liste_chainee.cpp)
