---
title: "Notes de cours"
weight: 2
---

## 1. Introduction
Rust est un langage qui se démarque principalement par sa manière de gérer la mémoire. Contrairement à la plupart des langages modernes qui utilisent un garbage collector, Rust adopte une approche différente : une gestion de mémoire sans garbage collector, mais entièrement sécurisée et performante. Son fonctionnement s’appuie sur des règles rigoureuses mises en place dès la compilation, ce qui élimine plusieurs classes d’erreurs classiques dans des langages comme C et C++.

L’objectif de Rust n’est pas de simplifier la programmation au point de cacher la complexité, mais plutôt d’offrir un environnement où la sécurité et la performance cohabitent. Il oblige à réfléchir à la manière dont les données circulent dans un programme, mais une fois maîtrisé, ce modèle permet d’écrire un code beaucoup plus robuste.

Dans cette première partie, nous allons nous concentrer sur les fondations du modèle mémoirielle de Rust : 
- **Le typage**
- **La séparation entre pile et tas**,
- **Le système d’ownership**
- **Les emprunts (borrowing)** 
- **les références** 

Ces concepts représentent la base qui permet au langage d'assurer sécurité et performance.

----

## 2. Le typage en Rust
Rust est un langage à typage statique, mais avec une inférence de type très avancée. Cela donne une combinaison intéressante : le compilateur connaît tous les types à la compilation, mais le code reste concis grâce à l'inférence.

### 2.1 Définition explicite vs inférence
Lorsqu’on travaille avec Rust, on peut définir un type de manière explicite ou laisser le compilateur le déduire de façon implicite.

#### Définition explicite
Une définition explicite signifie que c’est le programmeur qui indique directement le type. Il n’y a aucune interprétation à faire : le type est écrit dans le code.

Exemples :
```rust
let age: u32 = 29;
let nom: &str = "Aurélie" ;
```
Ici, on dit clairement au compilateur : « voici le type exact à utiliser ».

#### Définition implicite (inférence de type)

Une définition implicite signifie que le type n’est pas indiqué par le programmeur. C’est le compilateur qui l’infère à partir du contexte. Rust se base sur l’utilisation de la variable pour déterminer le type le plus logique et le plus sûr.

Exemples :
```rust
let score = 95;         // i32
let ville = "Québec";   // &str
```
Rust ne choisit jamais un type ambigu. Par exemple, les entiers sont automatiquement en ``i32``, car c’est un bon compromis de performance.
### 2.2 Typage strict pour éviter les erreurs silencieuses
Rust ne permet pas les conversions implicites. Par exemple :
```rust
let a: i32 = 10;
let b: u64 = 20;

let z = a + b // Erreur de compilation
```

Cette rigidité prévient les erreurs subtiles qui pourraient mener à des dépassements, pertes de précision ou bugs silencieux. Rust préfère que le développeur soit explicite :

```rust
let resultat = a as u64 + b;
```

C’est ce même principe qui s’applique au modèle mémoire complet : que ce soit explicite.

----

## 3. La gestion mémoire en Rust
Rust a une approche particulière : tout est décidé à la compilation. Le langage ne possède pas de garbage collector, mais ne demande jamais au développeur d’appeler ``free()``, ``delete`` ou tout autre mécanisme manuel.

La gestion de mémoire repose sur trois éléments :
1. La pile (stack)
1. Le tas (heap)
1. Le système d’ownership


Chaque élément joue un rôle distinct.

### 3.1 La pile (Stack)
La pile est une région de mémoire très performante. C’est une structure organisée en LIFO (last-in, first-out) où chaque nouvelle variable vient *se poser* au-dessus de la précédente. Comme tout est géré dans un ordre strict d’entrée et de sortie, les opérations d’allocation et de libération sont extrêmement rapides.

Rust y stocke les variables :
- simples (ex. : ``i32``, ``bool``, ``char``)
- de taille connue
- qui n’ont pas besoin d’une allocation dynamique

Exemple :
```rust
let x = 5;
```

Ici, ``x`` est placé dans la pile, car sa taille est connue dès la compilation.
La pile suit le modèle LIFO : quand un bloc se termine, toutes les variables créées dans ce bloc sont automatiquement libérées dans l’ordre inverse de leur création.

Ce fonctionnement rend la pile :
- extrêmement rapide
- sans fragmentation
- facile à libérer

Rust utilise la pile dès que possible pour optimiser la performance.

### 3.2 Le tas (Heap)
Le tas est une région de mémoire dynamique, utilisée pour stocker des données dont la taille peut changer ou qui doivent vivre plus longtemps que le bloc courant. C’est une mémoire flexible, à l’opposé de la pile qui est stricte et statique.

Contrairement à la pile, le tas permet d’allouer des données dont la taille peut varier, et dont la durée de vie est plus flexible.
Exemples typiques :
- ``String``
- ``Vec<T>``
- objets complexes
- structures dynamiques

```rust
let chaine = String::from("Rust");
```

Ici, seule la structure interne du ``String`` (pointeur, longueur, capacité) est stockée dans la pile. Le contenu réel (``"Rust"``) est dans le tas.`

Le tas est plus flexible, mais aussi plus complexe à gérer. Rust assure cette gestion automatiquement en combinant ownership et borrowing.

---- 

## 4. Ownership (propriété)
L’ownership est le mécanisme central de Rust. C’est lui qui contrôle l’accès aux données dans le tas, quand elles doivent être libérées et comment les valeurs se déplacent dans le programme.

Rust applique **trois règles simples**, mais très strictes.

### 4.1 Règle 1 : chaque valeur a un unique propriétaire
Quand une variable contient une valeur, elle en devient propriétaire.

```rust
let s = String::from("Bonjour");
```

La variable ``s`` est responsable de ce ``String``.
Cette responsabilité inclut :
- posséder la donnée
- décider quand elle est libérée
- empêcher d’autres variables d’en être propriétaire simultanément

Ce caractère exclusif est intentionnel : Rust doit toujours savoir qui libérera la mémoire plus tard.

### 4.2 Règle 2 : une valeur ne peut avoir qu’un seul propriétaire à la fois
Lorsqu’une variable est assignée à une autre, l’ownership est transféré.

```rust
let a = String::from("Salut");
let b = a;
```

Après cette opération :
- ``b`` devient propriétaire
- ``a`` devient invalide

Rust empêche alors toute utilisation de ``a`` :
```rust
println!("{a}"); // Erreur !
```

Ce mécanisme s’appelle un **move**. Il évite les double-libérations et les accès concurrents dangereux.

### 4.3 Règle 3 : quand le propriétaire sort de la portée, la valeur est libérée
Dès qu’un bloc de code se termine, Rust appelle automatiquement ``drop()`` sur chaque valeur dont le propriétaire sort de portée.
```rust
{
    let temp = String::from("Test");
} // ← Ici, le String est automatiquement libéré
```

Ce mécanisme est inspiré du RAII de C++, mais Rust rend ce comportement obligatoire et sécurisé.

----

## 5. Borrowing : prêter une valeur sans en transférer la propriété
L’ownership serait trop rigide si le propriétaire devait toujours transférer la propriété pour qu’une autre fonction puisse travailler sur ses données. C’est pourquoi Rust introduit les **emprunts** (*borrowing*).

Le *borrowing* permet :
- d’accéder à une donnée sans en perdre la propriété
- d’éviter les copies lourdes
- d’assurer la cohérence de mémoire
- de partager les données selon des règles strictes

Il existe deux types d’emprunts :
1. Emprunt immuable (``&T``)
1. Emprunt mutable (``&mut T``)

### 5.1 Emprunt immuable (``&T``)
Un emprunt **immuable** signifie que la donnée peut être lue, mais jamais modifiée.
Autrement dit, immuable = la valeur est accessible, mais figée.

Exemple:
```rust
let nom = String::from("Alice");
afficher(&nom);

fn afficher(s: &String) {
    println!("{s}");
}
```

Rust autorise :
- **plusieurs emprunts immuables simultanés**
- **tant qu'aucun emprunt mutable n’existe au même moment**

Cette règle permet une lecture sécuritaire des données tout en garantissant qu’aucune modification conflictuelle ne puisse arriver.

### 5.2 Emprunt mutable (``&mut T``)
Une valeur **mutable** est une valeur que l’on peut modifier après sa création. Autrement dit, mutable = la donnée peut changer dans le temps.

Un emprunt mutable accorde une permission exclusive de modification :
```rust
let mut compteur = 0;
incrementer(&mut compteur);

fn incrementer(c: &mut i32) {
    *c += 1;
}
```

Rust impose deux règles fortes :
- **Un seul emprunt mutable à la fois.**
- **Aucun emprunt immuable ne peut exister en même temps qu’un emprunt mutable.**

Ces règles empêchent les data races et les écritures concurrentes.

----

## 6. Références : des pointeurs sécurisés
Une référence en Rust est un **pointeur contrôlé**, c’est-à-dire un accès indirect vers une valeur, mais encadré par les règles d’ownership et d’emprunt.

Contrairement aux pointeurs classiques en C/C++, une référence ne peut jamais être:
- **nulle**
- ***dangling* (pointant vers une donnée détruite)**
- **non initialisée**
- **utilisée en violation des règles de mutabilit**

**Définition d'un référence**

Une référence est un moyen d’accéder à une donnée sans en prendre la possession, tout en garantissant que cette donnée est encore valide et respectée (immutabilité ou mutabilité exclusive).

Exemple valide : emprunt immuable
```rust
fn main() {
    let nom = String::from("Rust");
    afficher_longueur(&nom);  // on emprunte nom sans le déplacer

    println!("Nom toujours utilisable : {nom}");
}

fn afficher_longueur(s: &String) {
    println!("Longueur : {}", s.len());
}
```
Ici :
- ``&nom`` crée une référence immuable vers ``nom``.
- La fonction lit la valeur mais ne peut pas la modifier.
- ``nom`` reste valide et accessible après l’appel, car l’ownership ne change pas.

Exemple invalide : référence qui ne vit pas assez longtemps
```rust 
let r;

{
    let x = 10;
    r = &x; // Erreur : x ne vivra pas assez longtemps
}
```

Rust refuse ce code, car après la fin du bloc, ``x`` est libéré :
la référence ``r`` pointerait vers une zone de mémoire qui n’existe plus.
Le compilateur détecte ce problème avant même l’exécution.

## 7. Lifetimes : mieux comprendre la durée de vie d'une référence
Les lifetimes font souvent peur au début, mais dans les faits, ils ne rendent rien plus compliqué. Ils rendent le comportement du programme explicite.

**Définition d’un lifetime** :

Un lifetime est une annotation qui décrit la durée pendant laquelle une référence reste valide, c’est-à-dire la période où la donnée empruntée existe encore et peut être utilisée sans danger.
Autrement dit : un lifetime indique “jusqu’à quand” une référence a le droit d’exister.

Rust génère automatiquement les lifetimes la plupart du temps, mais il y a des situations où il doit nous demander de clarifier. Ce n’est pas un mécanisme qui agit au runtime : c’est entièrement un outil de vérification statique.

### 7.1 Pourquoi Rust a besoin des lifetimes ?

Les références (``&T`` ou ``&mut T``) pointent vers des données possédées par quelqu’un d’autre.

Rust doit donc garantir :
- **que la référence ne survit pas plus longtemps que la donnée pointée**
- **que la mémoire n’est pas libérée trop tôt**
- **que toutes les règles d’ownership restent respectées**

Si Rust s’appuyait uniquement sur les règles d’emprunts, il manquerait une dimension : la durée de vie effective de la donnée.

### 7.2 Exemple typique d’erreur évitée
```rust
let r;

{
    let x = String::from("Bonjour");
    r = &x; // Erreur : x sort du scope avant r
}

println!("{r}");
```

Rust rejette ce code non pas pour faire *le difficile*, mais parce qu’il aurait causé une référence vers une donnée libérée. C’est exactement la classe d’erreurs que Rust élimine complètement.

### 7.3 Cas où les lifetimes doivent être explicités
Exemple classique :
```rust
fn choisir<'a>(a: &'a str, b: &'a str) -> &'a str {
    a
}
```
Ici, ``'a`` indique :

*la valeur retournée doit vivre au moins aussi longtemps que les deux paramètres.*

Rust a besoin d’être sûr que la valeur retournée n’est pas un emprunt d’une valeur qui n’existe plus.

### 7.4 Lifetimes comme système de preuves

Les lifetimes ne changent rien au fonctionnement du programme.

Ils servent uniquement à prouver au compilateur que :
- **les règles d’emprunt sont valides**
- **aucune référence ne devient invalide**
- **aucune donnée n'est libérée trop tôt**

C’est un système de preuves pour garantir la sûreté mémoire.

----

## 8. Mutabilité, immuabilité et logique derrière leurs règles

Rust pousse très loin la notion d’immuabilité. Il préfère rendre tout immuable par défaut.

**Pourquoi ?**
Parce que la mutabilité est souvent la source de comportements indéterminés, d’effets secondaires indésirables, et de bugs subtils.

### 8.1 Immuble par défaut

```rust
let x = 10;
```

Impossible de modifier ``x`` sans utiliser ``mut`` :
```rust
let mut x = 10;
x = 20;
```

### 8.2 Mutabilité contrôlée

Rust sépare clairement chaque niveau de mutabilité :
1. Variable mutable : ``let mut x = ...``
1. Référence mutable : ``&mut x``
1. Mutabilité interne via ``RefCell``, ``Cell`` (cas avancé)


### 8.3 Pourquoi la mutabilité est exclusive ?
Rust ne permet pas des emprunts immuables et mutables en même temps :
```rust
let mut s = String::from("Salut");

let r1 = &s;
let r2 = &mut s; // Erreur
```
Cette règle existe pour prévenir des situations comme :
- **lire pendant que quelqu’un écrit**
- **écrire pendant qu’un autre écrit**
- **lire une donnée au milieu d’une mutation partielle**

Ce sont exactement les scénarios qui causent des bugs imprévisibles en C++.

Rust préfère interdire ces situations plutôt que de laisser courir un risque.

----

## 9. Analyse mémoire étape par étape : du code aux opérations réelles

Dans cette section, on va analyser ce que Rust fait réellement pour quelques cas concrets.
L’objectif est de comprendre comment les mécanismes abstraits se traduisent en opérations mémoire réelles.

### 9.1 Exemple 1 — création d’un String

```rust
let texte = String::from("Rust");
```

En arrière-plan :
- Rust alloue un buffer dans le tas (heap) pour y stocker les 4 caractères : R, u, s, t.
- Ce buffer contient exactement le contenu dynamique du ``String``.
- Dans la pile (stack), Rust place une petite structure légère contenant :
    - un pointeur vers le buffer du tas
    - la longueur actuelle (4 octets pour "Rust")
    - la capacité (souvent identique à la longueur au moment de la création, mais peut être plus grande si Rust anticipe une croissance)

Cette structure tient en 24 octets sur la plupart des architectures modernes (3 champs de type usize).

Le propriétaire de la donnée est la variable ``texte``.
Cela signifie deux choses fondamentales :
1. ``texte`` contrôle l'accès au buffer du tas (personne d'autre ne peut le libérer).
1. Quand ``texte`` sort de portée, Rust appelle automatiquement le ``drop`` du ``String``, ce qui :
    - libère le buffer dans le tas ;
    - nettoie la structure dans la pile ;
    - garantit qu’aucune fuite mémoire n’est possible.

Cet exemple montre bien la séparation stack/heap :
la structure du ``String`` vit dans la pile, mais son contenu dynamique vit dans le tas.

### 9.2 Exemple 2 — move sémantique
```rust
let a = String::from("Données");
let b = a;
```
Ce qui se passe réellement :
- Rust ne copie pas la chaîne "Données" dans le tas.
- Il copie seulement les trois champs du ``String`` (pointeur, longueur, capacité) de ``a`` vers ``b`` — une petite structure dans la pile.
- Après ce move, ``a`` devient invalide : il ne peut plus être utilisé.
- Seul ``b`` possède désormais l’ownership et pourra libérer la mémoire quand il sortira de portée.
- Ce modèle est performant (pas de copie inutile) et sécuritaire (un seul propriétaire de la ressource).

### 9.3 Exemple 3 — emprunt immuable
```rust
let s = String::from("Salut");
let r1 = &s;
let r2 = &s;
```

Rust autorise plusieurs **références immuables** :
- ``r1`` et ``r2`` pointent vers le même buffer.
- Aucune des deux ne peut modifier la donnée.
- Aucune copie mémoire n’est effectuée.

### 9.4 Exemple 4 — emprunt mutable exclusif
```rust
let mut s = String::from("Rust");
let r = &mut s;
r.push_str(" Pro");
```

Rust empêche toute autre référence pendant l’emprunt mutable :
- ``r`` reçoit un accès exclusif
- aucune lecture parallèle n’est autorisée
- aucune autre écriture n'est permise

Ce modèle prévient les race conditions.

### 9.5 Exemple 5 — libération automatique
```rust
{
    let data = String::from("Test");
} // drop() automatique
```
Rust génère un appel à ``drop(data)`` automatiquement en fin de bloc.
 Il n’est pas possible de “oublier” de libérer une ressource.

C’est une sécurité qui couvre toutes les ressources, pas seulement la mémoire :
- fichiers
- sockets
- verrous
- buffers réseau

À la fin d’un bloc, Rust libère tout.

---- 

## 10. Erreurs rendues impossibles par Rust

Rust élimine automatiquement plusieurs erreurs classiques :

##### 10.1 Pointeurs nuls
Impossible sans ``Option<T>``, car Rust exige que toute référence soit toujours valide et non nulle.

##### 10.2 Pointeurs pendants
Impossible, car Rust vérifie la durée de vie des références et refuse toute référence pointant vers une donnée déjà libérée.

##### 10.3 Double libération
Impossible, car seul le propriétaire libère la mémoire et l’ownership empêche qu’une ressource soit libérée deux fois.

##### 10.4 Use-after-free
Rust bloque le code avant compilation dès qu’une référence pourrait accéder à une donnée libérée.

##### 10.5 Data races
Impossible, car les emprunts empêchent deux écritures simultanées ou une écriture pendant une lecture.

##### 10.6 Modification concurrente
Impossible, car un emprunt mutable est exclusif : une seule référence peut modifier la donnée à la fois.

##### 10.7 Fuites mémoire involontaires
Très rares, puisque Rust libère automatiquement la mémoire. Elles n’apparaissent que si le développeur utilise volontairement des patterns explicites comme ``Rc<RefCell<T>>``.

Rust n’élimine pas seulement les erreurs courantes :
il élimine surtout les erreurs critiques qui compromettent la stabilité, la sûreté et la sécurité du programme.

---- 

## 11. Comparaison avec C++ pour comprendre la valeur de Rust

Rust n’a pas été créé pour “remplacer C++”, mais il corrige plusieurs de ses faiblesses.

Voici un portrait simple :

| Problème | C++ | Rust |
| :-------- | :---: | :----: |
| Pointeurs non initialisés | Oui | Non |
| Null pointer | Oui | Non |
| use-after-free | Oui | Non |
| Double free | Oui | Non |
| Gestion manuelle | Souvent | Jamais |
| Concurrence sécurisée | Difficile | Native |
| Prédictibilité | Moyenne | Forte |
| Sécurité | Dépend du développeur | Automatique |


Rust force la discipline. C++ part du principe que “le développeur fera attention”.
Rust part du principe que “le développeur est humain”.

----

## 12. Combinaison de tous les concepts dans un exemple complet
Voici un exemple qui combine typage, ownership, borrowing, mutabilité, références et lifetimes :
```rust
fn main() {
    let mut phrase = String::from("Rust est");

    ajouter(&mut phrase, " puissant");
    afficher(&phrase);

    println!("Final : {phrase}");
}

fn ajouter(texte: &mut String, ajout: &str) {
    texte.push_str(ajout);
}

fn afficher(t: &String) {
    println!("Affichage : {t}");
}
```

**Analyse complète**
- **``phrase`` possède son buffer**
- **La variable détient l’ownership du ``String``, donc elle contrôle la libération de la mémoire.**
- **La fonction ajouter reçoit un emprunt mutable (&mut ``String``)**
    - Cela lui donne la permission exclusive de modifier le contenu sans prendre possession de la ressource.
- **La fonction afficher reçoit un emprunt immuable (``&String``)**
    - Elle peut lire le contenu librement, mais ne peut pas le modifier.
- **Rust garantit l’ordre correct des emprunts**
    - L’emprunt mutable se termine avant que l’emprunt immuable ne commence. 
    - Rust refuse tout chevauchement illégal.
- **Aucun ownership n’est transféré**
    - Les fonctions travaillent uniquement avec des références. ``phrase`` reste le seul propriétaire.
- **Aucune copie du buffer n’est faite**
    - Les opérations manipulent le même espace mémoire dans le tas, sans coût supplémentaire.
- **Aucune fuite possible**
    - Avec l’ownership, Rust assure que la mémoire sera libérée exactement une fois.
- **Aucune libération manuelle**
    - Rust détruit automatiquement phrase à la fin du main via son mécanisme de drop.

Cet exemple illustre une structure typique en Rust :
on passe des références à des fonctions, on évite la copie, on modifie et lit selon des règles strictes, et on laisse Rust gérer la mémoire de manière sécuritaire et performante.

----

## 13. Pourquoi Rust est adopté partout aujourd’hui
La raison est simple : Rust règle des problèmes que les autres langages ignorent depuis trop longtemps. Dans des systèmes critiques, un seul bug de mémoire peut causer :
- une faille de sécurité
- un crash
- une corruption de données
- un comportement imprévisible.

C’est pourquoi Rust est utilisé dans :
- Android (Google)
- Windows (Microsoft)
- AWS (Firecracker)
- Cloudflare
- 1Password
- Discord (certaines parties réécrites en Rust)

Le fait que Rust évite entièrement les erreurs mémoire les plus courantes est un argument majeur pour ces entreprises.

----

## 14. Conclusion générale
Dans Rust, chaque concept comme typage, ownership, borrowing, mutabilité et références forme un tout cohérent. Aucun mécanisme n’est isolé. Le langage mise sur :
- la clarté
- la prévention des erreurs
- la sécurité
- la performance
- la gestion automatique et prévisible des ressources

Rust ne tire pas sa puissance d’un runtime massif ou d’un Garbage Collection sophistiqué.
Il la tire d’un modèle logique et structuré qui impose la sécurité dès la compilation.

Cette approche est exigeante au début, mais elle mène à un code beaucoup plus robuste, stable, lisible et performant. Rust n’est pas seulement un langage moderne : c’est une façon structurée et fiable de penser la mémoire et la sécurité logicielle.

## Source
- https://doc.rust-lang.org/book/
- https://blog.jetbrains.com/rust/2025/06/12/rust-vs-go/#challenges-and-benefits-of-learning-rust
- https://thehackernews.com/2025/11/rust-adoption-drives-android-memory.html#:~:text=Google%20has%20disclosed%20that%20the,vulnerabilities%20for%20the%20first%20time
- https://www.youtube.com/watch?v=0y6RKiIk6cs
- https://www.youtube.com/watch?v=42FhQWQ6SVA
