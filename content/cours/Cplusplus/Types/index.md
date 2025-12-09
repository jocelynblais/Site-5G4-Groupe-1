+++
title = "Types"
weight = 20
+++

En C++, on doit spécifier le type de données qu'une variable peut stocker. Il s'agit d'un langage typé, contrairement au Python. Chaque fois qu'une variable est définie en C++, le compilateur alloue une certaine quantité de mémoire à cette variable en fonction du type de données avec lequel elle est déclarée. Chaque type de données nécessite une quantité de mémoire différente.

La plupart des mécanismes du C++ relatifs aux types sont très similaires à ceux que vous avez croisés en Java, pour la simple raison que le C++ et le Java ont un ancêtre commun, le C.

![alt text](data_type.png)

## Les types de base

En C++ on retrouve les types habituels des autres langages typé :

| Type de Donnée   | Utilisation                             | Longueur  | Plage de valeurs                    |
|------------------|------------------------------------------|-----------|-------------------------------------|
| `char`           | Caractère unique                         | 8 bits    | De -128 à +128                      |
| `unsigned int`   | Entier, non signé               | 16 bits   | De 0 à 65535                        |
| `int`            | Entier signé       | 16 bits   | De -32768 à +32768                  |
| `unsigned long`  | Entier plus grand non signé  | 32 bits   | De 0 à 4,3E9                        |
| `long`           | Grand entier signé                       | 32 bits   | De -2,15E9 à +2,15E9                |
| `float`          | Nombre à virgule flottante               | 32 bits   | De 3,4E-38 à 3,4E+38                |
| `double`         | Nombre plus grand à virgule flottante    | 64 bits   | De 1,7E-308 à 1,7E+308              |

> [!tip]
> Le mot clef `const` peut être utilisé pour déclarer une variable comme constante. Cette variable doit être définie à sa création :
>```C++
> const int limite_vitesse_km_h = 110;
>```

## Conversion de types
La conversion de type en C++ est semblable au Java, hérité du langage C.

### Les conversions implicites
Les conversions implicites se font dans cet ordre :
> bool -> char -> short int -> int ->  unsigned int -> long -> unsigned -> long long -> float -> double -> long double

### Les conversions explicites

Comme en Java, il suffit de préciser le type voulu entre parenthèses `(int)var` pour faire une conversion explicite.

```C++
#include <iostream>
using namespace std;

int main() {
    double x = 1.2;

    int sum = (int)x + 1;
    cout << sum;

    return 0;
}
```

#### Les conversions C++
C++ a introduit sa propre méthode de transtypage à l'aide d'opérateurs. Il y a quatre types de transtypage possible :

- `static_cast` : utilisé pour les conversions de types standard lors de la compilation.
- `dynamic_cast` : utilisé pour les conversions de types lors de l'exécution dans le polymorphisme et l'héritage.
- `const_cast` : supprime ou ajoute les qualificatifs const ou volatile.
- `reinterpret_cast` : utilisée pour la réinterprétation de bas niveau des bits (par exemple, la conversion des pointeurs).

L'équivalent du code précédent avec un transtypage C++:
```C++
#include <iostream>
using namespace std;

int main() {
    double x = 1.2;

    int sum = static_cast<int>(x + 1);
    cout << sum;

    return 0;
}
```

L'avantage de cette technique, c'est que le transtypage est vérifié à la compilation, alors que la technique précédente, la vérification se fait à l'exécution.
## Les tableaux
Ici aussi, on retrouve un fonctionnement similaire au Java, on utilise les `[]` :

```C++
#include <iostream>
using namespace std;

int main() {
    // declaring and initializing an array of size 5
    int arr[5] = {2, 4, 8, 12, 16};

    // printing array elements
    for (int i = 0; i < 5; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}
```

> [!warning] Attention
> La taille total du tableau doit être définie au moment de la déclaration. La gestion de la taille des tableaux n'est pas dynamique. Le compilateur à besoin de connaitre à l'avance la taille de la mémoire consécutive à allouer.
>
> Nous verrons dans la partie [STL](../stl/) comment utiliser des tableaux dynamique.

> [!tip]
> Il existe la fonction `sizeof()` qui retourne la **taille du tableau en octets**.
>
> Pour obtenir le nombre d'éléments du tableau, il faut diviser cette taille par la taille d'un élément du tableau.

On peut également créer des tableaux à plusieurs dimensions, comme en Java :

```C++
float matrice_3D[100][100][100];
```

## Les chaînes de caractères

Il existe 2 manières d'utiliser les chaînes de caractères en C++:
- La méthode C : qui n'est rien de plus qu'un tableau de `char` :
```C++
char str[] = "Bonjour";
```
- La classe `string` du C++ :
```C++
string str = "Bonjour";
```

Encore une fois, la classe `string` du C++ est très similaire à celle de Java. Vous retrouverez le même type de fonctions (`find`, `strncmp`, ...), opérateurs (`+`, `+=`) et l'utilisation des `[]` pour accéder à une lettre en particulier.

Vous pourrez trouver une liste exhaustive ici : https://cplusplus.com/reference/string/string/


## Inférence des types

Depuis C++11, on peut utiliser le mot clefs `auto` pour laisser le compilateur trouver le type de la variable.

Le compilateur déduit le type à partir de la valeur assignée à la déclaration de la variable.

Cette déclaration a été créée principalement pour alléger l'écriture quand on utilise les objets de la [STL](../stl). 

Voici un exemple avec les types de base :
```C++
#include <iostream>
#include <typeinfo>
using namespace std;

int main() {
    
    //Using auto to avoid explicitly
    //defining the data type
    auto x = 4;
    auto y = 3.37;
    auto z = 3.37f;
    auto c = 'a';
    auto ptr = &x;
    
    //pointer to a pointer
    auto pptr = &ptr; 
    cout << typeid(x).name() << endl
         << typeid(y).name() << endl
         << typeid(z).name() << endl
         << typeid(c).name() << endl
         << typeid(ptr).name() << endl
         << typeid(pptr).name() << endl;

    return 0;
}
```
Affichage :
```
i
d
f
c
Pi
PPi
```
Avec `i` pour entier, `d` pour flottant double précision, `f` pour flottant simple précision, `c` pour caractère, le préfixe `P` donne un pointeur : `Pi` pointeur vers un entier.


## Les types définis par l'usagé

Il existe plusieurs manières de créer des types pour nos besoins, vous avez déjà rencontré ce mécanisme. Lorsque que vous déclarez une nouvelle classe en Java, vous créez un nouveau type qui porte le nom de votre classe.

### Les structures et les unions
Les structures et les unions sont un héritage direct du C, on peut voir la structure comme une classe publique sans méthodes. Une simple collection de données.

```C++
struct point {
    int x, y, z;
    string couleur;
};

point pt1;
pt1.x = 10;
```

Une union ressemble à une structure, mais l'espace mémoire est partagé entre les membres. Son usage est assez rare.

{{% expand title="Exemple d'union" %}}
```C++
#include <iostream>
using namespace std;

// Declaration of union is same as the structures
union A {
    int i;
  	char c;
};

int main() {
    // A union variable t
    A a;
  
  	// Assigning value to c, i will also
  	// assigned the same
    a.c = 'A';
    
	cout << "a.i: " << a.i << endl;
  	cout << "a.c: " << a.c;

    return 0;
}
```
Résultat d'exécution :
```
a.i: 65
a.c: A
```
{{% /expand %}}

### Les énumérations
Principalement utilisé pour attribuer des noms à des constantes entières. Ces noms facilitent la lecture et la maintenance du programme.

{{% expand title="Exemple d'énumération" %}}
```C++
#include <iostream>
using namespace std;

// Declaring enum
enum Week { Mon, Tue, Wed, Thur, Fri, Sat, Sun };

int main() {
  
  	// Creating enum variable
    enum Week day;

  	// Assigning value to the variabe
    day = Wed;

    cout << day;
    return 0;
}
```
Résultat d'exécution :
```
2
```
{{% /expand %}}

### Typedef et using

Le langage C++ vous permet de définir explicitement de nouveaux noms de types de données à l'aide des mots-clés typedef ou using. Ceux-ci ne créent pas une nouvelle classe de données, mais définissent plutôt un nom pour un type existant.


{{% expand title="Exemple de `typdef` et `using`" %}}
```C++
#include <iostream>
using namespace std;

// Using typedef to define a new name for existing type
typedef float f;

// Using 'using' to define a new name for existing type
using integer = int;

int main() {
    // Declaring variables using new type names
    f x = 3.14;
    integer y = 42;

    cout << "Float Value: " << x << endl;
    cout << "Integer Value: " << y;

    return 0;
}
```
{{% /expand %}}

### Les classes

Ce que nous verrons en détails dans la partie [Programmation orienté objet](../poo)

## Sources
- https://www.geeksforgeeks.org/cpp/cpp-data-types/
- https://www.geeksforgeeks.org/cpp/user-defined-data-types-in-c/
- https://www.geeksforgeeks.org/cpp/cpp-arrays/
- https://cplusplus.com/reference/string/string/
