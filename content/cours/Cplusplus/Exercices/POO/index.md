+++
title = "POO - Géométrie"
weight = 110

+++

Créez un système de formes géométriques utilisant l'héritage et le polymorphisme. Votre programme doit inclure :

### 1. Classe de base abstraite `Forme`

- Attributs protégés : `nom` (string), `couleur` (string)
- Constructeur avec paramètres
- Méthodes virtuelles pures : `calculerAire()` et `calculerPerimetre()`
- Méthode virtuelle : `afficher()` qui affiche les informations de base

### 2. Classes dérivées

Créez au moins 3 classes dérivées :

- **Rectangle** : largeur et hauteur
- **Cercle** : rayon
- **Triangle** : base et hauteur

Chaque classe doit :

- Implémenter les méthodes virtuelles pures
- Redéfinir la méthode `afficher()` pour inclure ses spécificités
- Avoir un constructeur approprié

### 3. Classe `GestionnaireFormes`

- Stocke un vecteur de pointeurs vers des `Forme`
- Méthodes :
    - `ajouterForme(Forme* forme)` : ajoute une forme
    - `afficherToutesLesFormes()` : affiche toutes les formes avec leurs détails
    - `calculerAireTotale()` : calcule la somme des aires de toutes les formes
    - Destructeur qui libère la mémoire

### 4. Programme principal

Créez un programme qui :

- Instancie plusieurs formes de types différents (utilisation de `new`)
- Les ajoute au gestionnaire
- Affiche toutes les formes
- Calcule et affiche l'aire totale
- Démontre l'utilisation du polymorphisme

## Contraintes techniques

- Gérez correctement la mémoire avec les `new` et les `delete`.
- Utilisez le mot-clé `override` pour les méthodes redéfinies
- Implémentez au moins un opérateur (par exemple `operator<<` pour l'affichage)

## Exemple de sortie attendue

```
=== Affichage de toutes les formes ===
Rectangle "Mon Rectangle" (Rouge)
  Largeur: 5, Hauteur: 3
  Aire: 15, Périmètre: 16

Cercle "Mon Cercle" (Bleu)
  Rayon: 4
  Aire: 50.2655, Périmètre: 25.1327

Triangle "Mon Triangle" (Vert)
  Base: 6, Hauteur: 4
  Aire: 12, Périmètre: [calcul dépendant de l'implémentation]

=== Statistiques ===
Aire totale de toutes les formes: 77.2655
```

## Questions bonus

1. Comment pourriez-vous ajouter une méthode pour comparer deux formes par aire ?
2. Comment implémenteriez-vous un système de sérialisation pour sauvegarder les formes ?
3. Que se passerait-il si vous essayiez d'instancier directement la classe `Forme` ?

## Solution 

> [!warning]- Solution
> [geometrie.cpp](geometrie.cpp)
