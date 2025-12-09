+++
title = "STL"
weight = 70
+++

La STL (*standard template library*) est une collection de classes et de fonctions qui facilitent le développement en utilisant des structures de données courantes comme les vecteurs, les `stacks` ou `maps`. Elle fournit également des algorithmes prêts à l'emploi et efficaces pour trier, trouver des éléments etc.

La STL C++ est basé autour du mécanisme des [templates](https://www.geeksforgeeks.org/cpp/templates-cpp/). Ce mécanisme permet d'écrire des classes avec des algorithmes génériques qui s'adapte à tout type de variable. C'est-à-dire qu'un vecteur peut contenir des entiers, des chaines de caractères ou encore n'importe quel type d'objet.

Les avantages à utiliser la STL :
- Économise temps et efforts.
- Fiable et testé
- Rapide et efficace
- Réutilisabilité
- Algorithmes intégrés

## Les structures de données

Vous trouverez ici une liste des différentes structures de données fournie par la STL : https://www.geeksforgeeks.org/cpp/containers-cpp-stl/

Nous détaillerons ici seulement les vecteurs, les autres structures de données sont similaires à ce que vous avez déjà utilisé dans d'autres langages.

### Les vecteurs

Les vecteurs sont des **tableaux dynamiques**, qui peuvent augmenter ou réduire leur taille, de la même manière que les tableaux en python. On peut accéder aux éléments d'un vecteur de la manière qu'un tableau avec les `[]`.

Comme les vecteurs sont des templates, on doit préciser le type de données que va contenir le vecteur : 

```C++
vector<char> tableau_de_caracteres;
vector<int> tableau_d_entier;
vector<vector<int>> matrix; // Tableau d'entier à 2 dimensions
```

Voici un exemple d'utilisation d'un vecteur de caractères :

```C++
#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<char> v = {'a', 'f', 'd'};
  
  	// Inserting 'z' at the back
  	v.push_back('z');
  
  	// Inserting 'c' at index 1
  	v.insert(v.begin() + 1, 'c');

  	for (int i = 0; i < v.size(); i++)
        cout << v[i] << " ";
    return 0;
}
```

Ici, on voit comment ajouter un élément à la fin du tableau avec la fonction `v.push_back('z')`. Pas besoin se soucier de la taille du tableau, il s'agrandira au besoin. Quant à la fonction `v.insert(v.begin() + 1, 'c')` on insère un caractère à la position `1` du vecteur. La librairie s'occupe de déplacer les éléments et d'allouer la mémoire si besoin.

--- 
Pour une liste exhaustive des fonctions disponible sur vecteur : https://en.cppreference.com/w/cpp/container/vector.html

## Les algorithmes

La STL fourni également des algorithmes optimisés pour les problèmes les plus courants en informatique. On peut les classifier en 4 catégories :
- Recherche
- Tri et réarrangement
- Manipulation (remplir, remplacer...)
- Comptage et comparaison

Voici un exemple d'utilisation d'un algorithme de tri sur un vecteur d'entier :
```C++
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> numbers = {42, 15, 8, 23, 4, 16, 99, 1};
    
    std::cout << "Original: ";
    for (const auto num : numbers) {
        std::cout << num << " ";
    }
    std::cout << "\n";
    
    std::sort(numbers.begin(), numbers.end(), [](int a, int b) {
        return a < b;
    });
    
    std::cout << "Ascending: ";
    for (const auto num : numbers) {
        std::cout << num << " ";
    }
    std::cout << "\n";
    
    return 0;
}
```

Les algorithmes étant générique, il faut fournir une méthode de comparaison pour les objets qu'on souhaite ordonner. C'est dans ce cas de figure que l'utilisation des [expressions lambda](../fonctions/#les-expressions-lambdas) est pratique.
```C++
std::sort(numbers.begin(), numbers.end(), [](int a, int b) {
    return a < b;
});
```

Ici `numbers.begin()` et `numbers.end()` spécifie quelle partie du tableau, on souhaite trier, et l'argument suivant est l'expression lambda qui va être utilisé pour savoir si un élément du vecteur est plus grand que l'autre, on est dans un cas simple où l'on compare des entiers.

```C++
[](int a, int b) {
    return a < b;
}
```

Dans le cas d'un objet ayant plusieurs attributs, comme une voiture avec un attribut longueur, largeur et poids par exemple. C'est avec l'expression lambda qu'on va définir si on souhaite trier par la longueur ou par le poids.

```C++
[](Voiture a, Voiture b) {
    return a.poids < b.poids;
}
```

> [!tip]-
> On peut voir dans cette exemple que les vecteurs peuvent utiliserla strucute de [for sur un interval](../structure_control/#for-sur-un-intervalle) comme pour un simple tableau.
> ```C++
> for (const auto num : numbers) {
> ```

## Boost

Boost est une librairie C++ un peu plus avancée que la STL, mais avec la même rigueur sur fiabilité. De nombreuses parties de la STL étaient de projet de boost avant d'y être intégré.

https://www.boost.org/

Vous allez pouvoir trouver des librairies pour traiter des nombres avec des valeurs au delà de 2^64, la gestion d'évènement asynchrones, des interfaces avec python, des algorithmes de tri plus récent...

Cependant, cette librairie est extérieure à la distribution de base de C++, vous devez l'installez avant de vous en servir.

Pour une distribution type Debian :
```bash
$ sudo apt install libboost-all-dev
```

## Sources
- https://www.geeksforgeeks.org/cpp/c-magicians-stl-algorithms/
- https://www.geeksforgeeks.org/cpp/containers-cpp-stl/
- https://en.cppreference.com/w/cpp/container/vector.html