+++
title = "Programation orienté objet"
weight = 60
+++

Les objets en C++ utilisent la plupart des concepts que vous avez vu avec d'autres langages, comme l'encapsulation, l'abstraction, le polymorphisme, l'héritage.

> Petit rappel des avantages de la POO :
> - **Modularité et réutilisabilité** : La POO favorise la modularité grâce aux classes et aux objets, permettant la réutilisabilité du code.
> - **Encapsulation** : La POO encapsule les données et les fonctions dans les objets, améliorant la sécurité et l'intégrité des données.
> - **Héritage** : La POO prend en charge l'héritage, réduisant la redondance en réutilisant le code existant.
> - **Polymorphisme** : La POO permet le polymorphisme, rendant le code flexible et dynamique grâce à la surcharge de méthodes.
> - **Abstraction** : La POO permet l'abstraction, cachant les détails complexes et exposant uniquement les fonctionnalités essentielles.

## Les classes en C++

Voici un exemple de base de classe C++ :
```C++
#include <iostream>
using namespace std;

class Voiture {
private:
    string marque;
    int vitesse;

public:
    // Constructeur
    Voiture(string m){
        this->marque = m; 
        this->vitesse = 0; 
    }

    // Destructeur
    ~Voiture(){
        cout << "Destruction de la voiture : " << this->marque << endl;
    }
    
    // Méthodes
    void accelerer(int increment){ 
        vitesse += increment; 
    }

    void afficherInfo() {
        cout << "Marque: " << marque << ", Vitesse: " << vitesse << endl;
    }
};

int main() {
    Voiture maVoiture("Toyota");
    maVoiture.accelerer(10);
    maVoiture.afficherInfo();
    
    return 0;
}
```

On définit une classe avec le mot clef `class` suivi de de son nom, ici `Voiture`. À la fin d'une instruction de `class` un nouveau type est maintenant disponible. 

La ligne :
```C++
Voiture maVoiture("Toyota");
```
Instancie la variable `maVoiture` du type `Voiture`, on fait appel au constructeur de la classe qui prend un paramètre `m` pour initialiser la marque de la voiture. Comme en Java et Python les objets C++ ont besoin de **constructeur pour initialiser la classe**, et d'un **destructeur pour libérer les ressources**. 

> [!warning] Les destructeurs en C++
> On déclare un destructeur de classe avec le signe `~` suivi du nom de la classe, ici `~Voiture()`. 
>
> En C++ un destructeur est particulièrement important pour libérer la [mémoire allouée dynamiquement](../pointeurs/#allocation-mémoire-dynamique). C'est un bon endroit pour appeler la fonction `delete` pour éviter les fuites mémoire.

On peut ensuite appeler les fonctions de la classe de la même manière qu'en Java ou Python, avec un `.`

#### Anatomie du constructeur

```C++
Voiture(string m){
    this->marque = m; 
    this->vitesse = 0; 
}
```

Pour accéder aux membres d'une classe à l'intérieur de celle-ci, on peut utiliser le pointeur `this` comme en Java ou en Python avec `self`. Il s'agit d'un pointeur, on doit donc le déréférencer pour y accéder : `*this`. Si on veut accéder à un membre, on devrait écrire : `(*this).marque`. Le C++ a introduit une écriture équivalente, plus légère : `this->marque` 

> [!tip]- Autre écriture du constructeur
> On peut aussi écrire le constructeur de la manière suivante :
> ```C++
> Voiture(string m) : marque(m), vitesse(0) {}
> ```

### Abstraction
#### Visibilité des membres
Comme en Java, on peut définir ce qui est visible hors de l'objet avec les attributs public et privé, pour les fonctions et les variables.

En C++, les membres d'une classe sont par défaut public (variables et fonctions). Pour déclarer des membres privés, on utilise le mot clef `private:` suivi de toutes les déclarations que l'on souhaite garder privée.

Dans notre exemple, les 2 variables sont déclarées après le mot clef `private`, ce qui les rend inaccessibles à l'extérieur de l'objet : `maVoiture.vitesse` génère une erreur de compilation.

Après ces 2 déclarations, l'instruction `public:` signale que les déclarations suivantes seront publics.

> [!info]
> Il existe un troisième mode, qui est `protected` son usage est plus rare et dépasse le cadre du cours.

#### Membres static

On peut également définir une variable de classe comme `static`. Comme en Java, cette variable devient commune à toutes les instances de la classe. 

Cette variable doit être initialisée hors de la classe :

```C++
class classA {
public:
    static int i;

    classA(){
        i++;
    };
};

// initialisation du membre statique
int classA::i = 1;

int main(){
    ...
}
```

#### Sous classes

Il est possible de déclarer des classes à l'intérieur d'une autre :

```C++
class A{
    private:
        class B{
            ...
        };
        B varB();
};
```

### passage des objets en paramètres

La meilleure solution pour passer un objet en paramètre est d'utiliser une référence, ou un pointeur.

```C++
void fonction(A &varA){
    varA.varDynamic = ...
}
```

Si on utilise une variable simple, une opération de copie va avoir lieu. Il existe 2 manières de faire ces copies :
- **Copie en surface** : C'est le mode de copie par défaut, les valeurs sont copiées tel quel, c'est-à-dire que si vous utilisez un pointeur dans votre classe les 2 instances vont partager le même espace en mémoire. Ce qui peut être une source de bugs inombrables.
- **Copie en profondeur** : Cette copie doit être implémentée par le développeur, on prend charge les pointeurs et on gère l'allocation mémoire pour copier les valeurs etc. La copie en profondeur peut être implémenté pour 2 raisons : copie à la construction, copie avec le signe `=`.

### Polymorphisme

Le concept de polymorphisme est le même qu'en Java, c'est-à-dire qu'on peut surcharger une même fonction pour qu'elle effectue différentes actions en fonction de la classe qui l'appelle, ou des paramètres passés.

Pour continuer avec la copie des objets, on peut surcharger le constructeur d'une classe pour qu'il prenne une référence à cette même classe, ou encore l'opérateur `=` :

```C++
class Voiture {
private:
    string marque;
    int vitesse;

public:
    // Constructeur
    Voiture(string m){
        this->marque = m; 
        this->vitesse = 0; 
    }

    // Constructeur par copie
    Voiture(Voiture &other){
        this->marque = other.marque;
        this->vitesse = other.vitesse;
    }

    // surcharge de l'opérateur =
    Voiture& operator=(const Voiture& other){
        this->marque = other.marque;
        this->vitesse = other.vitesse;
        return *this;
    }

    // Destructeur
    ~Voiture(){
        cout << "Destruction de la voiture : " << this->marque << endl;
    }
    
};
```

### Héritage

L´héritage en C++ défini les relations entre classes, comme pour les autres langages orienté objet. Cependant, le C++ autorise l'héritage multiple, ce qui peut sembler une bonne idée, mais en pratique amène à des problèmes difficiles a debuger. C'est une mauvaise pratique, c´est pour cette raison que beaucoup de langage apparu après n'autorisent pas cette fonctionnalité.

```C++
class classeDerivee : mode_heritage classeBase{
    // corps de la classe
};
```

| Mode                        | Description                                                                                                                                                                                                   |
| --------------------------- | ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| **Mode d'Héritage Public**  | Les membres publics de la classe de base deviendront publics dans la classe dérivée et les membres protégés de la classe de base deviendront protégés dans la classe dérivée.                                 |
| **Mode d'Héritage Protégé** | Les membres publics et protégés de la classe de base deviendront tous protégés dans la classe dérivée.                                                                                                        |
| **Mode d'Héritage Privé**   | Les membres publics et les membres protégés de la classe de base deviendront tous privés dans la classe dérivée. Le mode privé est le mode par défaut qui est appliqué lorsque nous ne spécifions aucun mode. |

> [!tip]
>Pour rappel les membres privé de la classe de base ne sont pas accessible à la classe dérivée. Si vous souhaitez utiliser les variables privée de votre classe de base dans votre classe dérivée, vous devez avoir créé des accesseurs publique dans votre classe de base.

#### Surchage des fonctions

Pour surcharger une fonction de classe lors d'un héritage en C++, il utilise le mot clef `virtual` :

```C++
#include <iostream>
using namespace std;

class Base {
public:
    // Virtual function
    virtual void display() {
        cout << "Fonction de la classe de base" << endl;
    }
};

class Derived : public Base {
public:
    void display() override {
        cout << "Fonction de la classe dérivée" << endl;
    }
};

int main() {
    Derived derivedObj;
    Base* basePtr;

    basePtr = &derivedObj;
    
    basePtr->display();
    return 0;
}
```
Affichage :
```
Fonction de la classe dérivée
```

#### Classe virtuelle pure

Dans certain cas, on peut vouloir créer des classe virtuelles pure, à l'instar des interfaces en java. C'est à dire des classes qu'on ne peut pas instancier, seulement s'en servir comme base d'héritage pour d'autres classes.

Pour obtenir une classe virtuelle pure, il suffit de déclarer une fonction virutelle pure dans le corps de la classe:
```C++
virtual void draw() = 0;  // Pure virtual function
```

#### Surcharge des opérateurs

Comme en Java ou en python, on peut surcharger les opérateurs.
Voici tous les opérateurs disponnible en C++ :
`+ - * / % ^ & | ~ ! = < > += -= *= /= %= ^= &= |= << >> >>= <<= == != <= >= <=>(since C++20) && || ++ -- , ->* -> () []`

En C++ on a certains opérateur qu'on va déclarer comme fonction membre de la classe, et d'autre à l'extérieur de la classe.

**Directives Clés**
- Opérateurs de flux (`<<`, `>>`): Toujours non-membre
- Opérateurs d'affectation: Toujours membre (exigence du langage)
- Opérateurs d'indice, d'appel de fonction, d'accès aux membres: Toujours membre (exigence du langage)
- Opérateurs arithmétiques binaires: Généralement non-membre pour la symétrie
- Opérateurs d'affectation composée: Généralement membre
- Opérateurs unaires: Généralement membre
- Opérateurs de comparaison: Souvent non-membre pour la symétrie (surtout avec le moderne <=> de C++20)

Voici un exemple de surcharge de l'opérateur `<<` :

```C++
class MyClass {
private:
    int value;
    string name;
    
public:
    MyClass(int v, const string& n) : value(v), name(n) {}
    
    // Provide public getters
    int getValue() const { return value; }
    const string& getName() const { return name; }
};

// Non-member function using public interface
ostream& operator<<(ostream& os, const MyClass& obj) {
    os << "MyClass{value: " << obj.getValue() << ", name: " << obj.getName() << "}";
    return os;
}
```

## Les fichiers d'entête et les classes

La modularité du C++ vient avec l'utilisation de la commande `#include` comme nous l'avons vu [précédemment](../fonctions/#travailler-avec-plusieurs-fichiers-sources).

Nous allons voir ici comment séparer l'interface des objets avec leur implémentation :


{{< tabs >}}
{{% tab title="Personne.h" %}}
```C++
#ifndef PERSONNE_H
#define PERSONNE_H

#include <string>

class Personne {
private:
    std::string nom;
    std::string prenom;
    int age;

public:
    // Constructeurs
    Personne();
    Personne(const std::string& nom, const std::string& prenom, int age);
    
    // Destructeur
    ~Personne();
    
    // Méthodes d'accès (getters)
    std::string getNom() const;
    std::string getPrenom() const;
    int getAge() const;
    
    // Méthodes de modification (setters)
    void setNom(const std::string& nom);
    void setPrenom(const std::string& prenom);
    void setAge(int age);
    
    // Autres méthodes
    void afficher() const;
    void anniversaire();
    std::string getNomComplet() const;
};

#endif // PERSONNE_H
```
{{% /tab %}}

{{% tab title="Personne.cpp" %}}
```C++
#include "Personne.h"
#include <iostream>

// Constructeur par défaut
Personne::Personne() : nom(""), prenom(""), age(0) {
    // Constructeur vide avec liste d'initialisation
}

// Constructeur avec paramètres
Personne::Personne(const std::string& nom, const std::string& prenom, int age) 
    : nom(nom), prenom(prenom), age(age) {
    // Validation de l'âge
    if (age < 0) {
        this->age = 0;
    }
}

// Destructeur
Personne::~Personne() {
    // Nettoyage si nécessaire (ici pas besoin)
}

// Méthodes d'accès (getters)
std::string Personne::getNom() const {
    return nom;
}

std::string Personne::getPrenom() const {
    return prenom;
}

int Personne::getAge() const {
    return age;
}

// Méthodes de modification (setters)
void Personne::setNom(const std::string& nom) {
    this->nom = nom;
}

void Personne::setPrenom(const std::string& prenom) {
    this->prenom = prenom;
}

void Personne::setAge(int age) {
    if (age >= 0) {
        this->age = age;
    }
}

// Méthode d'affichage
void Personne::afficher() const {
    std::cout << "Nom: " << nom << " " << prenom 
              << ", Age: " << age << " ans" << std::endl;
}

// Méthode pour incrémenter l'âge
void Personne::anniversaire() {
    age++;
    std::cout << "Joyeux anniversaire ! " << prenom 
              << " a maintenant " << age << " ans." << std::endl;
}

// Méthode pour obtenir le nom complet
std::string Personne::getNomComplet() const {
    return prenom + " " + nom;
}
```
{{% /tab %}}

{{% tab title="main.cpp" %}}
```C++
#include "Personne.h"

int main() {
    Personne p("Dupont", "Jean", 25);
    p.afficher();
    p.anniversaire();
    return 0;
}
```
{{% /tab %}}

{{% tab title="CMakelists.txt" %}}
```cmake
cmake_minimum_required(VERSION 3.21)
project(personnes)

file(GLOB SOURCES "*.cpp")
add_executable(${PROJECT_NAME} ${SOURCES})
```
{{% /tab %}}

{{< /tabs >}}

## Références
- https://www.geeksforgeeks.org/cpp/shallow-copy-and-deep-copy-in-c/
- https://www.geeksforgeeks.org/cpp/cpp-polymorphism/
- https://www.geeksforgeeks.org/cpp/inheritance-in-c/

Surcharge des opérateurs : 
- https://en.cppreference.com/w/cpp/language/operators.html
- https://intellipaat.com/blog/operator-overloading-in-cpp/