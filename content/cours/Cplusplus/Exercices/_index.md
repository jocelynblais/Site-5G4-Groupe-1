+++
title = "Exercices"
weight = 100

[params]
  menuPre = '<i class="fa-solid fa-dumbbell"></i> '
+++

> [!info]- **Conventions**
> - Dans les exemples quand on parle de `Entrée utilisateur` on sous entend d'utiliser un ou plusieurs `cin` et d'afficher quelle entrée est attendue.
>
> - Quand on parle de `Données`, on signifie des valeurs codées en dur dans le fichier `.cpp`.

## Q1.
**Écrivez un programme pour trouver le plus grand parmi 3 nombres.**

Dans ce problème, vous recevez 3 nombres, et vous devez déterminer lequel est le plus grand.

**Par exemple :**
```
Entrée utilisateur : a = 10, b = 21 et c = 4
Sortie : b est le plus grand.
```

## Q2.
**Convertisseur de température**
Créez un programme qui propose à l'utilisateur de convertir une température soit de Celsius vers Fahrenheit, soit de Fahrenheit vers Celsius.
Formule de conversion :
- `T(°C) = (T(°F) - 32) / 1,8`
- `T(°F) = T(°C) × 1,8 + 32`

**Exemple d'exécution** :
```
=== Convertisseur de température ===
Choisissez une option :
1. Celsius vers Fahrenheit
2. Fahrenheit vers Celsius
Votre choix : 1
Entrez la température en Celsius : 25
25°C = 77°F
```

## Q3.
**Écrivez un programme pour afficher la valeur ASCII d'un caractère.**

En C++, chaque caractère a une valeur ASCII associée. Dans ce problème, nous devons afficher la valeur ASCII du caractère dans la console.
**Par exemple :**
```
Entrée utilisateur : Caractère = A
Sortie : Valeur ASCII de 'A' = 65
```

## Q4.
**Écrivez un programme pour vérifier si un nombre est un palindrome ou non.**

Un nombre palindrome est un nombre qui est égal à lui-même même après avoir inversé ses chiffres. Dans ce programme, nous devons vérifier les nombres palindromes.
**Par exemple :**
```
Entrée utilisateur : Nombre à vérifier = 1231
Sortie : 1231 n'est pas un nombre palindrome.
```

## Q5.
**Écrivez un programme pour vérifier si deux tableaux sont égaux ou non.**

Un tableau est dit égal si les éléments à l'index donné sont égaux dans les deux tableaux. Dans ce programme, vous devez prendre deux tableaux, puis vérifier si les deux tableaux sont égaux.
**Par exemple :**
```
Données :
arr1[] = {5, 8, 3} 
arr2[] = {5, 8, 11, 2}
Sortie : arr1[] et arr2[] ne sont pas égaux.
```

## Q6.

**Écrivez un programme pour inverser un tableau.**

Dans ce problème, vous devez inverser l'ordre des éléments dans un tableau sans utiliser de tableau auxiliaire.

**Exemple :**

- Donnée : arr[] = {1, 2, 3, 4, 5}
- Sortie : Tableau inversé : {5, 4, 3, 2, 1}

## Q7.

**Écrivez un programme pour compter les voyelles et les consonnes dans une chaîne.**

Dans ce programme, vous devez compter le nombre de voyelles (a, e, i, o, u) et de consonnes dans une chaîne donnée.

**Exemple :**

- Entrée utilisateur : str = "Hello World"
- Sortie : Voyelles: 3, Consonnes: 7

## Q8.
**Écrivez un programme pour rechercher un élément dans un tableau (Recherche linéaire).**

Dans ce programme, vous devez rechercher l'élément donné dans un tableau. Si l'élément est trouvé, vous afficherez l'index de l'élément. Le tableau n'est pas trié.

**Par exemple :**
```
Données :
arr[] = {10, 11, 7, 8, 2, 9};
Élément à rechercher : 19
Sortie : 19 non trouvé dans arr[]
```

## Q9.
**Écrivez un programme pour afficher le tableau après qu'il soit pivoté 
vers la droite K fois.**

La rotation de tableau signifie décaler les éléments n positions vers la gauche ou la droite. Dans ce problème, vous devrez faire pivoter le tableau dans la direction droite k nombre de fois.
**Par exemple :**
```
Données :
arr[] = {10, 11, 7, 33, 5, 1};
K = 3
Sortie : Tableau après rotation : {33, 5, 1, 10, 11, 7}
```

## Q9 bis
**Ecrivez une bibliothèque cpp**
Reprennez les exercices 5 6 8 et 9 pour créer une bibliothèque de traitement de tableaux d'entier. Vous devrez avoir 3 fichiers :
- libTableau.h
- libTableau.cpp
- main.cpp qui fait au moins un appel a chacune des fonctions de la lib.

## Q10.

**Écrivez un programme pour supprimer les doublons d'un tableau trié.**

Dans ce problème, vous devez supprimer tous les éléments dupliqués d'un tableau trié et retourner la nouvelle taille du tableau.

**Exemple :**

- Données : arr[] = {1, 1, 2, 2, 3, 4, 4, 5}
- Sortie : Tableau sans doublons : {1, 2, 3, 4, 5}, Nouvelle taille : 5


## Q11.
**Écrivez un programme pour convertir une chaîne en entier.**

Vous devez créer un programme pour convertir le nombre sous forme de chaîne en forme d'entier. Mais dans ce programme, au lieu du binaire, vous devez travailler avec un système de numération décimale.

**Par exemple :**
```
Entrée utilisateur : str = "69420"
Sortie : Nombre = 69420
```

## Q12.
**Écrivez un programme pour diviser une chaîne en plusieurs sous-chaînes.**

Dans ce problème, vous écrirez un programme pour diviser la chaîne donnée en sous-chaînes basées sur un délimiteur. Cela s'appelle aussi la tokenisation. Vous écrirez une fonction qui retourne un tableau de chaines de caractères.

**Par exemple :**
```
Donnée : str = "Welcome Geeks to the GeeksforGeeks portal."
Sortie : 
Welcome
Geeks
to
the
GeeksforGeeks
portal.
```

## Q13.
**Écrivez un programme pour créer une calculatrice simple.**

Dans ce problème, vous devez créer un programme qui peut effectuer l'addition, la soustraction, la multiplication et la division sur deux nombres saisis par l'utilisateur. Le type d'opération arithmétique peut également être sélectionné par l'utilisateur.
**Par exemple :**
```
Entrée utilisateur : 
Entrez le nombre : 10    25 
Entrez a pour addition, 
s pour soustraction, 
m pour multiplication, 
d pour division.
{{si m est saisi}}
Sortie : 250
```

## Q14.
**Écrivez un programme pour afficher un motif de pyramide complète simple.**

Dans ce problème, vous devez afficher le motif de pyramide simple montré ci-dessous :
```
Entrée utilisateur : 5
Sortie :

  *
 ***
***** 
```

## Q15.
**Écrivez un programme pour additionner deux nombres complexes.**

Dans ce problème, vous devez créer un type de données de nombre complexe (classe dans un fichier séparé, avec fichier d'entête) et créer une méthode pour additionner les deux nombres complexes.

**Par exemple :**
```
Données :
num1 = 2 + 3i
num2 = 5 + 11i
Sortie : 7 + 14i
```

## Q16.

**Écrivez un programme pour fusionner deux tableaux triés.**

Dans ce problème, vous devez fusionner deux tableaux triés en un seul tableau trié.

**Exemple :**

- Entrée :
    - arr1[] = {1, 3, 5, 7}
    - arr2[] = {2, 4, 6, 8}
- Sortie : Tableau fusionné : {1, 2, 3, 4, 5, 6, 7, 8}
