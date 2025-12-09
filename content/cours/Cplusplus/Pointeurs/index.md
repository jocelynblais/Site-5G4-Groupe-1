+++
title = "Gestion mémoire / Pointeurs"
weight = 60
+++

La gestion de la mémoire est manuelle avec le C++, ce qui peut être pratique en termes de performance, mais risqué en termes de sécurité.

## Organisation de la mémoire
Avant d'allouer de la mémoire, il faut savoir comment elle est organisée.

La mémoire d'un programme en cours d'exécution est organisée comme suit :
![alt text](mem_layout.png)
- High address : `0x7f ff ff ff ff ff` -> `2^48` (256 TB adressable)
- Low address : `0x0`

1. **Segment texte (segment code)** : 
    Le segment texte stocke le code machine compilé du programme (fonctions et méthodes). Il est généralement en lecture seule pour renforcer la sécurité. Sa taille varie en fonction de la complexité du code.
2. **Segment de données** : Le segment de données stocke les variables globales et statiques définies par le programmeur. Ce segment est situé juste au-dessus du segment de texte et est divisé en deux parties :
    1. **Segment de données initialisées** : Stocke les variables globales et statiques auxquelles une valeur est attribuée lors de la déclaration.
    2. **Segment de données non initialisées (BSS)** : Contient les variables globales et statiques qui n'ont pas été explicitement initialisées. Le système les définit automatiquement à zéro lors de l'exécution.
3. **Segment de tas (heap)** : Le tas est la région de mémoire utilisée pour l'allocation dynamique lors de l'exécution. La mémoire dans le tas est gérée manuellement à l'aide d'opérateurs tels que `new`/`delete` ou de fonctions telles que `malloc()`/`free()`.
4. **Segment de pile (stack)** : La pile est utilisée pour :
    - Les variables locales
    - Les paramètres de fonction
    - Les adresses de retour

    Chaque appel de fonction crée une zone mémoire, qui est poussé vers la pile. Lorsque la fonction se termine, cette zone est retirée.

### Exemple d'organisation du segment de données

![alt text](segment_donnees.png)

> [!tip]- Fonctionnement de la mémoire pendant l'exécution
> {{< youtube ioJkA7Mw2-U >}}


## Les pointeurs

Les pointeurs sont simplement des variables pour stocker une adresse mémoire.

Cette variable *pointe* vers une autre variable. 

Dans l'exemple ci-dessus, la variable `ptrSum` est de type `int*` et contient la valeur `0x90000000` qui correspond à l'adresse de la variable `sum` qui est une variable de type `int`.

Un pointeur est toujours associé à un type, on déclare un pointeur avec son type suivi d'une `*` :

```C++
int sum = 255;
int* ptrSum = &sum;
float* ptrAverage;
```

{{% expand title="Pointeurs sans type"%}}
Dans des cas rares, on peut avoir besoin d'un pointeur sans type, ce sont les void pointers `void*`. Pour plus d'informations : https://www.geeksforgeeks.org/c/void-pointer-c-cpp/
{{% /expand %}}

Ici, on déclare le pointeur de type `int` avec `int* ptrSum`, puis on l'initialise avec `= &sum`. Le `&` signifie que l'on veut l'adresse de la variable `sum`. On peut utiliser l'opérateur `&` sur toutes les variables.

```C++
#include <iostream>
using namespace std;

int main() {
    int var = 10;

    // declare pointer and store address of x
    int* ptr = &var;

    // print value and address
    cout << "Valeur de x: " << var << endl;
    cout << "Adresse de x: " << &var << endl;
    cout << "Valeur stockee dans le pointeur ptr: " << ptr << endl;
    cout << "Valeur pointé par ptr: " << *ptr << endl;

    return 0;
}
```
Affichage :
```
Valeur de x: 10
Adresse de x: 0x7fffa0757dd4
Valeur stockee dans le pointeur : 0x7fffa0757dd4
Valeur pointé par ptr: 10
```

Quand on accède à la variable `ptr`, on obtient une adresse. Un pointeur est une variable qui contient une adresse. Pour obtenir la valeur contenue à cette adresse (la valeur pointée par la variable `ptr`), on utilise la notation `*ptr`, cela s'appelle le déréférencement.

### Passage de paramètre par pointeurs

Voici un exemple de fonction qui effectue l'échange de deux variables en utilisant des pointeurs :

```C++

#include <iostream>
using namespace std;

void swap(int *x, int *y)
{
    int z = *x;
    *x = *y;
    *y = z;
}

int main()
{
    int a = 45, b = 35;
    cout << "Avant le swap\n";
    cout << "a = " << a << " b = " << b << "\n";

    swap(&a, &b);

    cout << "Après le swap\n";
    cout << "a = " << a << " b = " << b << "\n";
}
```
Affichage :
```
Avant le swap
a = 45 b = 35
Après le swap
a = 35 b = 45
```

### Les pointeurs et les tableaux

En C++ les tableaux et les pointeurs sont équivalant. Dans le code ci-dessous, si on considère le tableau `temp` sans les `[]`, il s'agit d'un pointeur vers le premier élément du tableau.

```C++
#include <iostream>
using namespace std;

int main()
{
    int size = 4;
    int temp[size] = { 25, 17, 23, 22};

    int* ptrTemp = temp;

    for (int i = 0; i < size; ++i) {
        cout << "Valeur a l'index " << i << ": " << *(ptrTemp + i)
             << endl;
    }

    return 0;
}
```
Affichage :
```
Valeur a l'index 0 : 25
Valeur a l'index 1 : 17
Valeur a l'index 2 : 23
Valeur a l'index 3 : 22
```

On remarque que `ptrTemp + i` est équivalent à `temp[i]`.


Représentation programme en mémoire :
![alt text](pointeur_tableau.png)


### Allocation mémoire dynamique

Jusqu'ici, on a vu les pointeurs vers des zones mémoires déjà allouées. Nous allons voir ici comment allouer de la mémoire dynamiquement dans le tas (*heap*) avec les instructions `new` et `delete`.

L'instruction `new data_type[size]` retourne un pointeur de type `data_type` vers la zone mémoire allouée de `size` éléments.

Lorsque vous allouez de la mémoire avec l'instruction `new`, il faut penser à la libérer une fois son utilisation terminée avec l'instruction `delete`.
 
> [!Warning] Problèmes courant
> La mémoire allouée avec `new` est persistante, si vous utilisez l'instruction dans une fonction, la mémoire sera toujours allouée une fois sortie de la fonction, contrairement aux variables locales.
>
> Cette fonctionnalités est pratique, mais elle rend la gestion de la mémoire délicate :
> - si vous perdez le pointeur qui alloue la mémoire, vous ne pourrez plus la libérer. Votre programme va grossir en RAM jusqu'à la fin de l'exécution, ou jusqu'à l'épuisement de la RAM. 
>
>   Les [smart pointers](#les-smart-pointers) ont été introduits pour limiter ces problèmes.
> - Si vous libérez l'espace, mais que vous gardez le pointeur, vous pouvez réutiliser ce pointeur par mégarde et écraser des valeurs en mémoire. Ce qui peut causer des crashs ou des failles sécurité.
>
>   Pensez à assigner la valeur `NULL` au pointeur tout de suite après sa libération.


Dans cet exemple, on alloue de l'espace pour un tableau de 5 entiers :

```C++
#include <iostream>
using namespace std;

int main() {
    int* ptr;
    
    ptr = new int[5]{10, 20, 30, 40, 50};

    for (int i = 0; i < 5; i++)
        cout << ptr[i] << " ";

    delete[] ptr;
    ptr = NULL;

    return 0;
}
```
Affichage :
```
10 20 30 40 50
```

## Les références

Une référence est un pointeur constant. Il **doit** être initialisé et il ne peut pas pointer ailleurs que vers l'adresse mémoire avec laquelle il a été initialisée. On ne peut pas réassigner une référence.

On peut voir aussi les références comme un alias à un nom de variable.

Leur usage principal, est le passage de paramètres à une fonction. Comme nous avons vu dans la partie [passage de paramètres](../fonctions#passage-par-adresse-mémoire-des-variables)

## Les smart pointers

Comme nous l'avons vu, les pointeurs sont des outils puissants, mais délicat à utiliser et risque d'apporter de nombreux problèmes.

C'est pour cette raison que l'on a développé les *smart pointers*. Il s'agit d'une surcouche autour des pointeurs qui va s'occuper de libérer la mémoire automatiquement, comme le font les langages utilisant le *garbage collection* (Java et Python entre autre).

---
Pour plus de détails sur les smart pointers :
https://www.geeksforgeeks.org/cpp/smart-pointers-cpp/



## Sources
- https://www.geeksforgeeks.org/cpp/memory-layout-of-cpp-program/
- https://www.geeksforgeeks.org/cpp/new-and-delete-operators-in-cpp-for-dynamic-memory/