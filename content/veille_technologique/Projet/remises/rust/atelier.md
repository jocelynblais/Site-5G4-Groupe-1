---
title: Atelier
---

## To-do list en ligne de commande avec Rust

### Objectif de l’atelier

Dans cet atelier, on va construire une petite application de to-do list en ligne de commande avec Rust.

L’idée n’est pas de faire l’appli parfaite, mais de :

* manipuler des **`String`** et un **`Vec<String>`**
* utiliser le **système d’ownership**
* pratiquer les **emprunts mutables et immuables**
* travailler avec des **références** et la **mutabilité contrôlée**
* comprendre *ce qui se passe en mémoire* à chaque étape (pile vs tas)

On reste dans le cadre des concepts vus dans les notes :
**pas de traits, pas de `struct`, pas de modules avancés, pas de magie.**
Juste des fonctions, des `String`, un `Vec<String>` et le modèle mémoire de Rust. 

L’atelier est prévu pour **2 à 3 heures** pour quelqu’un qui découvre Rust en pratique.

---

### 0. Prérequis

* Tu as cloné le dépôt GitHub fourni (avec le devcontainer Rust déjà prêt). https://github.com/jocelynblais/atelier_rust.git

* Tu as Docker et qu'il est lancé.
* Tu as VS Code et tu sais :

  * ouvrir le projet dans le devcontainer,
  * ouvrir un terminal intégré.

---

### 1. Lancer le devcontainer et vérifier l’environnement

1. Ouvre le projet dans VS Code.
2. Laisse le devcontainer Rust se lancer.
3. Ouvre un terminal dans VS Code (ex. `Ctrl+` `).
4. Vérifie que `cargo` est accessible :

   ```bash
   cargo --version
   ```

   Tu devrais voir une version de `cargo` s’afficher.
   Si c’est bon, on est prêts.

---

### 2. Créer le projet Rust

Dans le terminal du devcontainer, crée un nouveau projet binaire :

```bash
cargo new todo_cli
```

Puis entre dans le dossier :

```bash
cd todo_cli
```

Tu as maintenant :

* un fichier `Cargo.toml`
* un répertoire `src/`
* un fichier `src/main.rs` avec un `fn main()` minimal.

Teste que tout compile :

```bash
cargo run
```

Tu dois voir le `Hello, world!` par défaut.

---

### 3. Petit échauffement : String, ownership et emprunts

Avant de coder la to-do list, on va juste s’assurer que tu es à l’aise avec :

* **un `String` dans le tas**
* **un emprunt mutable pour le modifier**
* **un emprunt immuable pour l’afficher**

On va remplacer le `main` par ce code simple.

Dans `src/main.rs`, mets :

```rust
fn main() {
    let mut phrase = String::from("Ma première todo");

    ajouter_point_exclamation(&mut phrase);
    afficher(&phrase);

    println!("Final : {phrase}");
}

fn ajouter_point_exclamation(texte: &mut String) {
    texte.push_str(" !");
}

fn afficher(t: &String) {
    println!("Affichage : {t}");
}
```

#### Analyse mémoire rapide

En appliquant les notes de cours : 

* `phrase` est une variable dans la **pile** qui possède un `String`.
* Le contenu `"Ma première todo"` est dans le **tas**.
* Quand on appelle `ajouter_point_exclamation(&mut phrase)` :

  * on **emprunte mutablement** le `String` (type `&mut String`),
  * la fonction peut modifier le contenu dans le tas,
  * mais elle ne possède pas la donnée (l’ownership reste à `phrase`).
* Quand on appelle `afficher(&phrase)` :

  * on **emprunte immuablement** le `String` (type `&String`),
  * la fonction ne peut que lire.
* En fin de `main`, `phrase` sort de portée alors Rust appelle automatiquement `drop` = le buffer dans le tas est libéré.

Compile et lance :

```bash
cargo run
```

Tu dois voir l’affichage intermédiaire et la phrase finale.

Si ça fonctionne, tu as déjà tous les outils nécessaires pour construire ta to-do list.

---

### 4. Concevoir notre to-do list : `Vec<String>`

On va maintenant stocker nos tâches dans un **vecteur de chaînes** :

* chaque tâche est un `String` dans le tas,
* le vecteur est un `Vec<String>` qui vit dans la pile et gère :

  * un pointeur vers un buffer dans le tas,
  * la longueur,
  * la capacité.

On va commencer simple :

1. Déclarer un `Vec<String>` dans `main`.
2. Ajouter quelques tâches "en dur" pour tester.
3. Écrire des fonctions qui prennent des **références** vers le `Vec` pour le lire/modifier.

Remplace `main` par ceci :

```rust
fn main() {
    let mut todos: Vec<String> = Vec::new();

    ajouter_tache(&mut todos, String::from("Apprendre Rust"));
    ajouter_tache(&mut todos, String::from("Écrire une to-do list en CLI"));
    ajouter_tache(&mut todos, String::from("Boire un café"));

    afficher_taches(&todos);
}

fn ajouter_tache(liste: &mut Vec<String>, tache: String) {
    liste.push(tache);
}

fn afficher_taches(liste: &Vec<String>) {
    println!("--- Mes tâches ---");
    let mut index: usize = 1;
    for t in liste {
        println!("{index}. {t}");
        index += 1;
    }
}
```

#### Ce qu’on vient de faire (en version "modèle mémoire")

* `todos` est dans la **pile**, c’est un `Vec<String>`.
* Quand on appelle `ajouter_tache(&mut todos, String::from(...))` :

  * on crée un `String` dans le tas,
  * on **déplace** ce `String` dans le `Vec` (move de l’ownership),
  * `liste: &mut Vec<String>` est un **emprunt mutable** du vecteur :

    * on ne prend pas l’ownership du vecteur,
    * on a le droit de le modifier (ajouter des éléments).
* `afficher_taches(&todos)` reçoit `&Vec<String>` :

  * emprunt immuable = lecture seulement,
  * pas de copie des `String`, on lit la vraie donnée dans le tas.

Compile et lance :

```bash
cargo run
```

Tu dois voir la liste des trois tâches.

---

### 5. Ajouter la notion de "tâche complétée" (version LIFO)

On va rester simples :
au lieu de supprimer une tâche par index, on va **marquer la dernière tâche comme complétée** et la retirer, un peu comme une pile de travail (LIFO).

On va :

* ajouter une fonction `completer_derniere_tache` qui prend `&mut Vec<String>`.
* utiliser `pop()` pour retirer la dernière tâche.

Ajoute ceci en bas du fichier :

```rust
fn completer_derniere_tache(liste: &mut Vec<String>) {
    let tache = liste.pop();

    if let Some(t) = tache {
        println!("Tâche complétée : {t}");
    } else {
        println!("Aucune tâche à compléter.");
    }
}
```

> Oui, `pop()` renvoie une `Option<String>`, mais on ne va pas détailler ce type ici. Tu peux voir ça comme : "soit j’ai une tâche, soit je n’en ai pas".

Modifie `main` pour tester :

```rust
fn main() {
    let mut todos: Vec<String> = Vec::new();

    ajouter_tache(&mut todos, String::from("Apprendre Rust"));
    ajouter_tache(&mut todos, String::from("Écrire une to-do list en CLI"));
    ajouter_tache(&mut todos, String::from("Boire un café"));

    afficher_taches(&todos);

    println!("\nOn complète la dernière tâche...");
    completer_derniere_tache(&mut todos);

    println!("\nListe mise à jour :");
    afficher_taches(&todos);
}
```

Lance :

```bash
cargo run
```

Tu dois voir :

* la liste des 3 tâches,
* le message de tâche complétée,
* la liste mise à jour (2 tâches).

Ici encore, les règles d’emprunt s’appliquent :

* `completer_derniere_tache(&mut todos)` : emprunt mutable exclusif.
* `afficher_taches(&todos)` : emprunt immuable.

Rust empêche les deux en même temps, ce qui évite les data races. 

---

### 6. Interaction en ligne de commande : menu simple

Maintenant qu’on a les briques de base, on va :

* garder un `Vec<String>` dans `main`,
* tourner dans une boucle,
* afficher un menu,
* lire le choix de l’utilisateur,
* appeler les bonnes fonctions.

On va utiliser `std::io::stdin()` pour lire des lignes.

Remplace complètement le contenu de `src/main.rs` par :

```rust
use std::io::{self, Write};

fn main() {
    let mut todos: Vec<String> = Vec::new();

    loop {
        println!();
        println!("=============================");
        println!("        To-do CLI Rust       ");
        println!("=============================");
        println!("1) Ajouter une tâche");
        println!("2) Afficher les tâches");
        println!("3) Compléter la dernière tâche");
        println!("4) Quitter");
        print!("Ton choix : ");
        // On flush pour que le texte s'affiche avant la lecture
        io::stdout().flush().expect("Erreur de flush");

        let mut choix = String::new();
        io::stdin()
            .read_line(&mut choix)
            .expect("Erreur de lecture");

        let choix = choix.trim();

        if choix == "1" {
            ajouter_tache_interactive(&mut todos);
        } else if choix == "2" {
            afficher_taches(&todos);
        } else if choix == "3" {
            completer_derniere_tache(&mut todos);
        } else if choix == "4" {
            println!("Au revoir !");
            break;
        } else {
            println!("Choix invalide, réessaie.");
        }
    }
}

fn ajouter_tache_interactive(liste: &mut Vec<String>) {
    println!();
    println!("--- Ajouter une nouvelle tâche ---");
    print!("Description de la tâche : ");
    io::stdout().flush().expect("Erreur de flush");

    let mut saisie = String::new();
    io::stdin()
        .read_line(&mut saisie)
        .expect("Erreur de lecture");

    let saisie = saisie.trim();

    if saisie.is_empty() {
        println!("La tâche est vide, rien n'a été ajouté.");
    } else {
        // On crée un String à partir de la saisie &str
        let tache = String::from(saisie);
        ajouter_tache(liste, tache);
        println!("Tâche ajoutée !");
    }
}

fn ajouter_tache(liste: &mut Vec<String>, tache: String) {
    liste.push(tache);
}

fn afficher_taches(liste: &Vec<String>) {
    println!();
    println!("--- Mes tâches ---");

    if liste.is_empty() {
        println!("(aucune tâche pour l'instant)");
        return;
    }

    let mut index: usize = 1;
    for t in liste {
        println!("{index}. {t}");
        index += 1;
    }
}

fn completer_derniere_tache(liste: &mut Vec<String>) {
    let tache = liste.pop();

    if let Some(t) = tache {
        println!("Tâche complétée : {t}");
    } else {
        println!("Aucune tâche à compléter.");
    }
}
```

#### Ce qu’on applique ici de les notes

On reste dans le même cadre conceptuel : 

* `todos` possède un `Vec<String>` :

  * le vecteur vit dans la pile,
  * les `String` qu’il contient vivent dans le tas.
* `ajouter_tache_interactive(&mut todos)` :

  * emprunt mutable = permet de modifier le vecteur,
  * Rust garantit qu’il n’y a pas d’autre emprunt en même temps.
* `afficher_taches(&todos)` :

  * emprunt immuable = lecture sécuritaire, aucune modification possible.
* `completer_derniere_tache(&mut todos)` :

  * emprunt mutable exclusif pour retirer la dernière tâche.
* À la fin du programme :

  * `todos` sort de portée,
  * Rust appelle `drop` sur le `Vec<String>`,
  * qui appelle `drop` sur chaque `String`,
  * tout le tas est libéré proprement, sans fuite, sans double libération.

Tu peux tester :

```bash
cargo run
```

Joue avec les options :

* ajoute plusieurs tâches,
* affiche-les,
* complète la dernière plusieurs fois,
* quitte.

---

### 7. Analyse mémoire de la to-do list

Pour ancrer le modèle mémoire, on prend un scénario concret :

1. Tu lances le programme : `cargo run`.
2. Tu choisis `1` et ajoutes la tâche `"Finir l’atelier Rust"`.

Ce qui se passe :

1. `main` crée `let mut todos: Vec<String> = Vec::new();`

   * `todos` est en **pile**.
   * Le `Vec` pointe vers un buffer vide dans le tas (ou ne pointe vers rien tant qu’il est vide, selon l’implémentation).
2. Tu appelles `ajouter_tache_interactive(&mut todos)` :

   * la fonction reçoit une **référence mutable** vers `todos`,
   * l’ownership du `Vec` ne change pas.
3. Tu saisis `"Finir l’atelier Rust"` :

   * `saisie` est un `String` dans le tas,
   * `let tache = String::from(saisie)` crée un nouveau `String` (en pratique ici on passe par un `&str` trimé, mais l’idée reste : un nouveau buffer dans le tas).
4. `ajouter_tache(liste, tache)` :

   * `tache` est déplacé dans le `Vec` :

     * **move** : `tache` n’est plus utilisable après le `push`.
   * le vecteur agrandit sa capacité si nécessaire et stocke le nouveau `String` dans son buffer du tas.
5. Quand `ajouter_tache_interactive` se termine :

   * la référence mutable `&mut Vec<String>` est rendue à `main`,
   * `todos` reste le seul propriétaire du vecteur et de toutes les tâches qu’il contient.
6. Quand le programme se termine :

   * `todos` sort de portée,
   * Rust détruit le `Vec`,
   * chaque `String` est libéré exactement une fois.

Ce scénario illustre exactement les règles que tu as dans les notes :

* **1 seul propriétaire** par ressource,
* emprunts mutables exclusifs,
* emprunts immuables multiples,
* aucune fuite, aucun pointeur pendant, aucune double libération. 

