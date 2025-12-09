+++
title = "Les opérateurs"
weight = 30
+++

Le C++ offre la panoplie habituelle des opérations nécessaire. Ici aussi, peu de différences avec le java.

## Les opérateurs arithmétique

| Nom                | Symbole | Description                                         |
|--------------------|---------|-----------------------------------------------------|
| **Addition**        | `+`     | Additionne deux opérandes.                         |
| **Soustraction**    | `-`     | Soustrait le deuxième opérande du premier.         |
| **Multiplication**  | `*`     | Multiplie deux opérandes.                          |
| **Division**        | `/`     | Divise le premier opérande par le second.          |
| **Modulo**          | `%`     | Retourne le reste d'une division entière.          |
| **Incrémentation**  | `++`    | Augmente la valeur de l'opérande de 1.             |
| **Décrémentation**  | `--`    | Diminue la valeur de l'opérande de 1.              |

## Les opérateurs de comparaison

| Nom                         | Symbole | Description                                                      |
|-----------------------------|---------|------------------------------------------------------------------|
| **Est égal à**              | `==`    | Vérifie si les deux opérandes sont égaux                         |
| **Supérieur à**             | `>`     | Vérifie si le premier opérande est supérieur au second           |
| **Supérieur ou égal à**     | `>=`    | Vérifie si le premier opérande est supérieur ou égal au second   |
| **Inférieur à**             | `<`     | Vérifie si le premier opérande est inférieur au second           |
| **Inférieur ou égal à**     | `<=`    | Vérifie si le premier opérande est inférieur ou égal au second   |
| **Différent de**            | `!=`    | Vérifie si les deux opérandes sont différents                    |


## Les opérateurs logique

| Nom             | Symbole | Description                                                                       |
|------------------|---------|-----------------------------------------------------------------------------------|
| **ET logique**   | `&&`    | Retourne vrai seulement si tous les opérandes sont vrais ou non nuls.             |
| **OU logique**   | `\|\|`    | Retourne vrai si l’un des opérandes est vrai ou non nul.                         |
| **NON logique**  | `!`     | Retourne vrai si l’opérande est faux ou égal à zéro.                             |

## Les opérateurs bit à bit

| Nom                  | Symbole | Description                                                                 |
|-----------------------|---------|-----------------------------------------------------------------------------|
| **ET binaire**        | `&`     | Copie un bit dans le résultat si ce bit existe dans les deux opérandes.    |
| **OU binaire**        | `\|`     | Copie un bit dans le résultat si ce bit existe dans l’une des opérandes.   |
| **XOR binaire**       | `^`     | Copie un bit dans le résultat si ce bit existe dans l’une des opérandes, mais pas les deux. |
| **Décalage à gauche** | `<<`    | Décale la valeur vers la gauche selon le nombre de bits spécifié par l’opérande de droite. |
| **Décalage à droite** | `>>`    | Décale la valeur vers la droite selon le nombre de bits spécifié par l’opérande de droite. |
| **Complément à un**   | `~`     | Inverse les chiffres binaires : transforme les 1 en 0 et les 0 en 1.       |

## Les opérateurs d'assignation

| Nom                         | Symbole | Description                                                                 |
|------------------------------|---------|-----------------------------------------------------------------------------|
| **Affectation**              | `=`     | Assigne la valeur de droite à la variable de gauche.                        |
| **Addition et affectation**  | `+=`    | Ajoute d'abord la valeur de droite à celle de gauche, puis assigne le résultat à gauche. |
| **Soustraction et affectation** | `-=` | Soustrait d'abord la valeur de droite à celle de gauche, puis assigne le résultat à gauche. |
| **Multiplication et affectation** | `*=` | Multiplie d'abord la valeur de droite par celle de gauche, puis assigne le résultat à gauche. |
| **Division et affectation**  | `/=`    | Divise d'abord la valeur de gauche par celle de droite, puis assigne le résultat à gauche. |

## Opérateur ternaire

Il s'agit d'un opérateur de condition.

```C++
#include <iostream>
using namespace std;

int main() {
    int a = 3, b = 4;

    // Conditional Operator
    int result = (a < b) ? b : a;
    cout << "The greatest number "
          "is " << result;

    return 0;
}
```

## Précédence des opérations

Le C++ suit les règles mathématique usuelle.

{{% expand title="Référence complète de l'ordre précédence" %}}
Organiser par ordre d'importance (1ere ligne évaluée en premier, dernière ligne dernier).
| Operator                     | Name                                 | Associativity |
|-----------------------------|--------------------------------------|----------------|
| `()` `[]` `->` `.`           | Function call, Subscript, Member access | Left         |
| `++` `--`                    | Increment/Decrement                  | Right          |
| `!` `~` `+` `-`              | Logical/Bitwise NOT, Unary plus/minus | Right         |
| `*` `/` `%`                  | Multiplication, Division, Modulus   | Left           |
| `+` `-`                      | Addition, Subtraction               | Left           |
| `<<` `>>`                    | Bitwise shift                       | Left           |
| `<` `<=` `>` `>=`            | Relational operators                | Left           |
| `==` `!=`                    | Equality operators                  | Left           |
| `&`                          | Bitwise AND                         | Left           |
| `^`                          | Bitwise XOR                         | Left           |
| `\|`                          | Bitwise OR                          | Left           |
| `&&`                         | Logical AND                         | Left           |
| `\|\|`                         | Logical OR                          | Left           |
| `?:`                         | Ternary conditional                 | Right          |
| `=` `+=` `-=` `*=` `/=` `%=` `&=` `^=` `\|=` `<<=` `>>=` | Assignment and compound assignment | Right |
| `,`                          | Comma                               | Left           |

{{% /expand %}}


## Sources
- https://www.geeksforgeeks.org/cpp/operators-in-cpp/
- https://en.cppreference.com/w/cpp/language/expressions.html#Operators
- https://www.geeksforgeeks.org/cpp/operator-precedence-and-associativity-in-cpp/