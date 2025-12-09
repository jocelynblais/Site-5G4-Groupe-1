+++
title = "Fonctions"
weight = 50
+++


## Les fonctions en C++

En C++, on a également le concept de fonction. La définition d'une fonction suit le même principe qu'en Java :

```C++
return_type function_name(parameter_list){
    // body of the function
}
```

La liste de paramètre est optionnelle. Si on n'utilise pas de paramètres, on laisse les parenthèses vide, on déclare donc une méthode.

Exemples de méthodes et fonctions :
```C++
#include <iostream>
using namespace std;

// Definition d'une méthode
void hello() {
    cout << "Bonjour" << endl;
}

// Definition d'une fonction
int square(int x) {
    return x * x;
}

int main() {

    // Appel de la méthode
    hello();

    // Appel de la fonction
    int result = square(5);
    cout << "Le carré de 5 est : " << result << endl;

    return 0;
}
```
Affichage :
```
Bonjour
25
```

> [!warning] Attention
> **Vous devez déclarer/définir vos fonctions avant de les utiliser en C++.**
> 
> Le compilateur lit le fichier de la première à la dernière ligne, dans cet ordre. S'il rencontre un appel à une fonction avant sa déclaration, il va considérer que cette fonction n'existe pas et génèrera une erreur de compilation.


### Déclaration et définition de fonctions

Définir une fonction avant son utilisation n'est pas toujours la meilleure solution pour la lisibilité du code, par exemple quand le corps de la fonction est long.

Le C++ autorise la déclaration de la fonction avant sa définition :

```C++
// Declaration
int add(int, int);
```

La déclaration de fonction ne contient que la signature, il n'y a pas d'accolade `{}` et la ligne termine par un `;`. 

Le corps de la fonction peut être défini plus loin dans le code :
```C++
int add(int a, int b) {
    return a + b;
}
```

En d'autres termes, la déclaration présente la fonction au compilateur, alors que la définition donne l'implémentation.

## Les passages de paramètres

### Passage par valeur

Le passage de paramètre de type simple se fait par copie de valeur : 

```C++
#include <iostream>
using namespace std;

void change(int a) {
    a = 22;
}

int main() {
    int x = 5;

    change(x);
    
    cout << x;
    return 0;
}
```
Affichage :
```
5
```

Ici, la valeur de la variable `x` est copié dans la variable de la fonction `a`. Littéralement `a = x`, donc toute modification de `a` n'a aucun impact sur la variable `x`.

> [!tip]- Paramètres par défaut
> Comme en python, on peut définir une valeur par défaut à un paramètre de fonction :
> ```C++
> void func(int x, int y = 20);
> ```

### Passage par adresse mémoire des variables

Le C++ offre aussi deux manières de passer les paramètres qui autorise la modification de la valeur originale, les **références** et les **pointeurs**.

Voici exemple d'utilisation de passage par **référence** :

```C++
#include <iostream>
using namespace std;

void change(int& a) {
    a = 22;
}

int main() {
    int x = 5;

    change(x);
    
    cout << x;
    return 0;
}
```
Affichage :
```
22
```

Ici, le changement principal se passe au niveau de la déclaration du type du paramètre `int&`, ce qui veut dire référence à un entier.

Lorsque la fonction est appelée, ce n'est pas la valeur de `x` qui est copié, mais l'adresse de la variable `x`. Maintenant `x` et `a` désignent la même adresse mémoire, ce qui fait que la modification de `a` implique une modification de `x`.

Au-delà d'autoriser la modification de la variable, le gros avantage de cette méthode est qu'on n'effectue pas de copie de valeurs. Si vous voulez donner accès à un gros volume de données à une fonction, vous fournissez seulement l'adresse de début des données au lieu de faire une copie locale volumineuse (ce qui couterait beaucoup d'espace RAM et aussi du temps pour la copie). C'est de cette manière qu'on passe les objets (`class`) en paramètre.

Nous verrons plus en détails le fonctionnement des **pointeurs**  [ici](../pointeurs). Mais le principe est le même avec une syntaxe un peu différente.

## Les expressions lambdas
C++ 11 a introduit les expressions lambdas afin de permettre l'utilisation de fonctions courtes qui ne seront pas réutilisées. Elles ne nécessitent donc pas de nom. 

Elles sont principalement utilisées dans les algorithmes [STL](../stl) en tant que fonctions de rappel.

---

Cette notion dépasse la portée du cours, pour plus de détails :
https://www.geeksforgeeks.org/cpp/lambda-expression-in-c/

## Travailler avec plusieurs fichiers sources

À la différence du Java ou du python, en C++ il existe de deux types de fichiers contenant du code :
- `.cpp` : fichier contenant le code du programme, la définition des fonctions (l'implémentation).
- `.h` : fichier d'entête (`header file`) contenant les déclarations des fonctions.

En java ou en python, on va utiliser l'instruction `import` pour préciser quels sont les librairies, ou modules qu'on souhaite utiliser. On fournit le nom du fichier qui contient l'implémentation. 

En C++, on utilise la fonction `#include` et on passe le fichier d'entête.

> [!warning] Attention
> Le C++ distingue les librairies standards (celles installées dans le système) des librairies que vous développez pour votre projet.
> - On utilise la forme `#include <iostream>` pour les librairies standard. (`<>`)
> - On utilise la forme `#include "mon_fichier.h"` pour les librairies que vous développez. (`""`)

> [!info]- Les librairies standard
> Ce sont les librairies installées de base dans votre OS. On y trouve par exemple : `iostream`, `string`, `cmath`, `vector`, ...
>
> Vous trouverez les fichiers :
> - `.h` -> `/usr/include/c++/13/`
> - `.o` -> `/usr/lib/gcc/x86_64-linux-gnu/13/`
>
> `/13`parce qu'on utilise la version 13 de `gcc`

### Exemple

Voici un simple exemple d'une fonction faisant l'addition de 2 nombres entiers qu'on utilise dans un autre fichier contenant la fonction `main`.

- `utils.cpp` : définis la fonction.
- `utils.h` : déclare la fonction, c'est ce fichier qu'on inclut lorsque l'on souhaite utiliser la fonction `sommeDe2Entiers`.
- `main.cpp` : programme principal, où on va appeler la fonction définie dans `utils.h`

{{< tabs >}}
{{% tab title="utils.cpp" %}}
```C++
int sommeDe2Entiers(int a, int b){
    return a+b;
}
```
{{% /tab %}}

{{% tab title="utils.h" %}}
```C++
int sommeDe2Entiers(int a, int b);
```
{{% /tab %}}

{{% tab title="main.cpp" %}}
```C++
#include <iostream>
using namespace std;

#include "utils.h"

int main(){
    int a = 13, b = 22;

    // Fonction declaree dans le fichier d'entete
    cout << "La somme est : " << sommeDe2Entiers(a, b) << endl;
}
```
{{% /tab %}}
{{< /tabs >}}

Commandes pour la compilation du projet :
```bash
$ g++ -c utils.cpp
$ g++ -c main.cpp 
$ g++ -o main main.o utils.o
$ ./main
```

Les 2 premières lignes avec l'option `-c` servent à compiler les fichiers `.cpp` et générer le code binaire `.o`. Ces fichiers ne sont pas exécutables, ils doivent lier entre eux pour former un unique exécutable. Ici, la 3ieme ligne : `-o main` précise le nom de l'exécutable, `main.o utils.o` désigne les fichiers binaires à assembler. La dernière ligne exécute le programme.


### Makefile

La compilation de gros projet peut rapidement devenir fastidieuse, c'est pour cette raison que des outils d'aide à la compilation de projets ont été développés.

L'outil `make` a été développé pour résoudre ce problème. On déclare les fichiers sources et les différentes options de compilation dans un fichier `Makefile`. 

La complexité des projets allant toujours en augmentant, `Makefile` a atteint ses limites, la complexité des Makefiles pouvait être complexe que le code lui-même. On a alors développé une nouvelle suite d'outils permettant de générer automatiquement des `Makefile`.

---

Les détails des `Makefile` dépassent la portée du cours, si vous souhaitez un point de départ pour approfondir vos connaissances : https://www.geeksforgeeks.org/cpp/makefile-in-c-and-its-applications/

### Cmake

`Cmake` est l'outil le plus largement utilisé aujourd'hui pour construire des projets.

Voici un exemple de `CMakeLists.txt` pour l'exemple précédent :
{{% tab title="CMakeLists.txt" %}}
```cmake
cmake_minimum_required(VERSION 3.21)
project(addition)

file(GLOB SOURCES "*.cpp")
add_executable(${PROJECT_NAME} ${SOURCES})
```
{{% /tab %}}

Le fichier `CMakeLists.txt` se trouve généralement à la racine de votre projet.

Voici la suite de commande pour construire votre projet : 

```bash
$ mkdir build
$ cd build
$ cmake ..
$ make
$ ./addition
```

On commence par créer un répertoire où va être compilé notre code, ici `build`. On invoque la commande `cmake ..` qui va créer le fichier `Makefile` en utilisant le fichier `CMakeLists.txt`. On invoque ensuite la commande `make` qui va compiler notre code. Le fichier exécutable se trouve à la racine du répertoire `build`.

> [!tip]
> Cette suite de commande est standard. Avec ces 4 lignes vous pourrez construire une majorité de projets open source.

## Source
- https://keasigmadelta.com/blog/compiling-multi-file-c-source-code-with-cmake/
- https://www.geeksforgeeks.org/cpp/passing-by-pointer-vs-passing-by-reference-in-cpp/
- https://www.geeksforgeeks.org/cpp/when-do-we-pass-arguments-by-reference-or-pointer/
