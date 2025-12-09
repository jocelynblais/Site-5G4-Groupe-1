+++
title = "Introduction au C++"
weight = 10
+++

C++ est un langage de programmation polyvalent développé par Bjarne Stroustrup afin d'améliorer le langage C et d'y ajouter le paradigme orienté objet.
- Il est considéré comme un langage de niveau intermédiaire, car il combine les caractéristiques des langages de haut niveau et de bas niveau.
- Il est utilisé pour créer des systèmes embarqués, des moteurs de jeux, des navigateurs web, des compilateurs et des systèmes d'exploitation.

> "I have always wished for my computer to be as easy to use as my telephone; my wish has come true because I can no longer figure out how to use my telephone"
> **Bjarne Stroustrup**

## Pourquoi le C++ en 2025

- Le C++ reste l'un des langages de programmation les plus utilisés et les plus populaires pour la création de systèmes d'exploitation, de systèmes embarqués, d'interfaces utilisateur graphiques et, de nos jours, de logiciels de trading à haute fréquence (HFT).
- Il prend en charge à la fois des fonctionnalités de bas niveau et de haut niveau, telles que la gestion manuelle de la mémoire et la programmation orienté objet.
- La similitude de syntaxe avec C, Java et C# facilite le passage d'un langage à l'autre.
- Le C++ offre l'une des vitesses d'exécution les plus rapides parmi les langages de haut niveau, ce qui peut être un facteur décisif dans la programmation compétitive ou les applications hautes performances.

Bien que la première version de C++ date de 1983, sa dernière mise à jour date d'octobre 2024.

Chaque mise à jour apporte des modifications inspirées par d'autre langage par exemple, les fonctions lambda, déduction de type...


### Caractéristiques du C++

Les principales caractéristiques du langage de programmation C++ sont les suivantes :

- **Indépendance vis-à-vis de la machine** : le code C++ peut être exécuté sur n'importe quelle machine à condition de disposer d'un compilateur adapté.
- **Accès bas niveau** : le C++ offre un accès bas niveau aux ressources système, ce qui en fait un choix approprié pour la programmation système et l'écriture de code efficace.
- **Vitesse d'exécution rapide** : le C++ est l'un des langages de haut niveau les plus rapides. Il n'y a pas de surcharge de traitement supplémentaire en C++, il est extrêmement rapide.
- **Orienté objet** : l'un des points forts du langage qui le distingue du C. La prise en charge orientée objet aide le C++ à créer des programmes faciles à maintenir et extensibles, c'est-à-dire qu'il permet de créer des applications à grande échelle.
- **Une communauté active** : en plus du développement du langage, la librairie standard (STL) du C++ est en continuel avancement grâce à la librairie [boost](https://www.boost.org/).


## Un langage compilé

Contrairement au Java et au Python, le programme généré par du code C++ est exécuté directement par le système d'exploitation, il n'y a pas de machine virtuelle qui prend en charge l'exécution.

![alt text](compilation_interpretation.png)

Pour arriver à ce résultat, on doit passer par 3 étapes :
- Pour chaque fichier `.cpp` du projet :
    1. **Le Pre-processing** : On vérifie que la syntaxe est bonne, et on applique les modifications au fichier à compiler (les instructions commençant par `#`).
    2. **La compilation** : On traduit les instructions C++ en langage machine et on applique des optimisations si nécessaire. On obtient alors un fichier objet `.o`
- Pour l'ensemble des fichiers `.o` :

    3. **Le link** : On assemble tous les objets compilés en un seul fichier exécutable.

![alt text](process_compilation.png)

## Une gestion de la mémoire manuelle

Contrairement au Java ou au python, il n'y a pas de mécanisme de `garbage collection` en C++. C'est-à-dire que vous devez gérer vous-même les requêtes d'allocation mémoire (création d'un grand tableau, charger une image en mémoire etc...), et aussi libérer l'espace une fois l'utilisation terminée.

Si on n'est pas méticuleux, c'est avec ces mécanismes qu'on fait des fuites mémoires (l'utilisation de la RAM augmente avec le temps et fini par ne plus pouvoir s'exécuter.), des pointeurs corrompus qui peuvent donner accès à des zones mémoires pour des attaquants etc...

Heureusement avec les évolutions du langage, ces problèmes sont minimisés grâce à l'utilisation des smart pointer.

Mais c'est justement cette capacité à accéder directement à la mémoire qui rend ce langage important pour l'écriture d'un système d'exploitation, de drivers. C'est également cette gestion de la mémoire qui lui sa rapidité d'exécution.

## Un premier programme

Voici un exemple de programme `main.cpp` qu'on va exécuter dans un container :

```C++
#include <iostream>
using namespace std;

int main() {
    // affiche dans le terminal
    cout << "Hello, World!" << endl ;
    return 0;
}
```

On commence par créer un nouveau `dev container` dans vscode. Ici, nous allons utiliser un container C++ par défaut de vscode.

![alt text](image.png)

Vous pouvez selectionner les options par défaut.
![alt text](image-1.png)

Vous pouvez compiler le code avec la commande suivante :
```bash
$ g++ -o prog main.cpp
```
- `g++` est compilateur c++
- `-o prog` option qui donne le nom de l'exécutable, ici `prog`
- `main.cpp` le nom du fichier à compiler

Dans le cas où on ne compile qu'un seul fichier qui contient une fonction `main`, le compilateur fait automatiquement les 3 étapes nécessaires pour obtenir un exécutable.

![alt text](comp_exec_demo.png)

### Explication du code


```C++
#include <iostream>
```
Ici, on indique que l'on va utiliser la librairie standard d'entrée/sortie du C++. Cette instruction commence par un `#` ce qui informe au pré-processeur d'insérer ici le contenu du fichier `iostream.h` pour son utilisation plus loin dans le code. Dans notre cas les objet [`std::cout`](https://en.cppreference.com/w/cpp/io/cout.html) et [`std::endl`](https://en.cppreference.com/w/cpp/io/manip/endl).


```C++
using namespace std;
```
Instruction qui nous permet d'alléger l'utilisation du code de la librairie standard (STL). On indique qu'on utilise l'espace de nom `std`. Cette instruction nous permet de réduire l'écriture de `std::cout` à `cout`.


```C++
int main() {
    cout << "Hello, World!" << endl ;
    return 0;
}
```

Comme dans tous les langages de programmation, on doit avoir un point d'entrée au programme. En C++ comme souvent, ce point d'entrée s'appelle `main`. Comme en Java, on utilise les `{}` pour délimiter les blocs de code (fonctions, structure de contrôle), et le `;` est obligatoire pour signaler la fin d'une instruction.

```C++
    cout << "Hello, World!" << endl ;
```

`cout` est un objet de sortie de la librairie standard, un peu comme la fonction `print` en java ou python. 

On utilise l'opérateur `<<` avec `cout` pour donner la chaine de caractère que l'on souhaite afficher. Cet opérateur peut s'enchainer, un peu comme une concaténation de chaîne, ici termine avec un retour à la ligne `<< endl`.

### Les entrées / sorties en C++

En C++, l'entrée et la sortie s'effectuent sous la forme d'une séquence d'octets, plus communément appelée flux (`streams`).

- **Flux d'entrée** : si le flux d'octets va du périphérique (par exemple, le clavier) vers la mémoire principale, ce processus est appelé entrée. `std::cin`.
- **Flux de sortie** : si le flux d'octets est inverse, c'est-à-dire qu'il va de la mémoire principale vers le périphérique (écran d'affichage), ce processus est appelé sortie. `std::cout` et `std::cerr`.

```C++
#include <iostream>
using namespace std;
int main() {
    int age;
    string name;

    cout << "Entrez votre age: " << endl;
    cin >> age;

    cout << "Entrez votre prénom: " << endl;
  	cin >> name;
  
    cout << "Votre prénom : " << name << " | votre age : " << age;
    return 0;
}
```
> [!warning] Attention
> Le type de données saisies doit être identique à celui de la variable utilisée pour les stocker. Sinon, cela peut entraîner une erreur indéfinie ou un échec de la saisie.
>
>De plus, lorsque nous utilisons `cin` pour lire du texte en entrée, nous devons garder à l'esprit que cin cesse de lire l'entrée dès qu'il rencontre un espace blanc (espace, tabulation ou saut de ligne).


## Sources

- https://en.cppreference.com/index.html
- https://fr.wikipedia.org/wiki/C%2B%2B
- https://www.geeksforgeeks.org/cpp/c-plus-plus/
- https://ocw.mit.edu/courses/6-s096-introduction-to-c-and-c-january-iap-2013/resources/mit6_s096_iap13_lec1/