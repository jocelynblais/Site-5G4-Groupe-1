+++
title = "Git"
weight = 20
+++

Voici un ensemble de lien qui vous permettrons de résoudre les problèmes courant que vous pourrez rencontrer avec git.


| Technique | | liens |
| --- | --- | --- |
| **Gestion des branches** | ![alt text](branches.png) | https://www.atlassian.com/git/tutorials/using-branches |
| **Sauvegarde temporaire des changements** | ![alt text](stash.png)| https://www.atlassian.com/git/tutorials/saving-changes/git-stash|
| **Défaire les erreurs** | ![alt text](reset.png) | https://www.atlassian.com/git/tutorials/resetting-checking-out-and-reverting|
| **Intégrer les changements** | ![alt text](merging.png) | https://www.atlassian.com/git/tutorials/merging-vs-rebasing |

## Cheat Sheet
[Cheat Sheet de Atlassian](git_cheat_sheet.pdf) (pdf imprimable)


### Git Basics
| Command                          | Description                                                                                   |
|----------------------------------|-----------------------------------------------------------------------------------------------|
| `git init <directory>`           | Crée un dépôt Git vide dans le répertoire spécifié. Exécutez sans arguments pour initialiser le répertoire actuel en tant que dépôt Git. |
| `git clone <repo>`               | Clone le dépôt situé à `<repo>` sur la machine locale. Le dépôt d'origine peut être situé sur le système de fichiers local ou sur une machine distante via HTTP ou SSH. |
| `git config user.name <name>`    | Définit le nom de l'auteur à utiliser pour tous les commits dans le dépôt actuel. Les développeurs utilisent généralement le flag `--global` pour définir les options de configuration pour l'utilisateur actuel. |
| `git add <directory>`            | Prépare tous les changements dans `<directory>` pour le prochain commit. Remplacez `<directory>` par `<file>` pour changer un fichier spécifique. |
| `git commit -m "<message>"`      | Engage l'instantané préparé, mais au lieu de lancer un éditeur de texte, utilisez `<message>` comme message de commit. |
| `git status`                     | Affiche les fichiers qui sont préparés, non préparés et non suivis.                             |
| `git log`                        | Affiche l'historique complet des commits avec le format par défaut. Pour personnaliser, consultez les options supplémentaires. |
| `git diff`                       | Affiche les changements non préparés entre votre index et votre répertoire de travail.        |

### Réécriture de l'historique Git

| Command                         | Description                                                                                        |
|---------------------------------|----------------------------------------------------------------------------------------------------|
| `git commit --amend`            | Remplace le dernier commit avec les changements préparés et le dernier commit combinés. Utilisez sans rien préparer pour modifier le message du dernier commit. |
| `git rebase <base>`             | Réapplique la branche actuelle sur `<base>`. `<base>` peut être un identifiant de commit, un nom de branche, un tag, ou une référence relative à HEAD. |
| `git reflog`                    | Affiche un journal des changements de HEAD dans le dépôt local. Ajoutez le flag `--relative-date` pour afficher les informations de date ou `--all` pour afficher toutes les références. |

### Branches Git

| Command                         | Description                                                                                        |
|---------------------------------|----------------------------------------------------------------------------------------------------|
| `git branch`                    | Affiche toutes les branches dans votre dépôt. Ajoutez un argument `<branch>` pour créer une nouvelle branche avec le nom `<branch>`. |
| `git checkout -b <branch>`      | Crée et vérifie une nouvelle branche nommée `<branch>`. Supprimez le flag `-b` pour vérifier une branche existante. |
| `git merge <branch>`            | Fusionne `<branch>` dans la branche actuelle.                                                      |

### Dépôts distants

| Command                         | Description                                                                                        |
|---------------------------------|----------------------------------------------------------------------------------------------------|
| `git remote add <name> <url>`   | Crée une nouvelle connexion à un dépôt distant. Après avoir ajouté un dépôt distant, vous pouvez utiliser `<name>` comme raccourci pour `<url>` dans d'autres commandes. |
| `git fetch <remote> <branch>`   | Récupère un `<branch>` spécifique du dépôt. Laissez `<branch>` vide pour récupérer toutes les références distantes. |
| `git pull <remote>`             | Récupère la copie de la branche actuelle du dépôt distant et la fusionne immédiatement dans la copie locale. |
| `git push <remote> <branch>`    | Pousse la branche vers `<remote>`, avec les commits et objets nécessaires. Crée une branche nommée dans le dépôt distant si elle n'existe pas. |

### Annulation des changements

| Command                         | Description                                                                                        |
|---------------------------------|----------------------------------------------------------------------------------------------------|
| `git revert <commit>`           | Crée un nouveau commit qui annule tous les changements effectués dans `<commit>`, puis l'applique à la branche actuelle. |
| `git reset <file>`              | Supprime `<file>` de la zone de staging, mais laisse le répertoire de travail inchangé. Cela déstaging un fichier sans écraser les changements. |
| `git clean -n`                  | Affiche les fichiers qui seraient supprimés du répertoire de travail. Utilisez le flag `-f` à la place du flag `-n` pour exécuter le nettoyage. |

### Configuration Git

| Command                                      | Description                                                                                      |
|---------------------------------------------|--------------------------------------------------------------------------------------------------|
| `git config --global user.name <name>`      | Définit le nom de l'auteur à utiliser pour tous les commits de l'utilisateur actuel.              |
| `git config --global user.email <email>`    | Définit l'email de l'auteur à utiliser pour tous les commits de l'utilisateur actuel.             |
| `git config --global alias.<alias-name> <git-command>` | Crée un raccourci pour une commande Git. Par exemple, `alias.glog "log --graph --oneline"` définira `git log` équivalent à `git log --graph --oneline`. |
| `git config --system core.editor <editor>`  | Définit l'éditeur de texte utilisé par les commandes pour tous les utilisateurs de la machine. `<editor>` doit être la commande qui lance l'éditeur souhaité (par exemple, vi). |
| `git config --global --edit`                | Ouvre le fichier de configuration global dans un éditeur de texte pour une édition manuelle.      |

### Journal Git

| Command                                      | Description                                                                                      |
|---------------------------------------------|--------------------------------------------------------------------------------------------------|
| `git log <limit>`                           | Limite le nombre de commits à `<limit>`. Par exemple, `git log -5` limitera à 5 commits.          |
| `git log --oneline`                         | Condense chaque commit en une seule ligne.                                                        |
| `git log -p`                                | Affiche le diff complet de chaque commit.                                                         |
| `git log --stat`                            | Inclut les fichiers modifiés et le nombre relatif de lignes ajoutées ou supprimées dans chaque fichier. |
| `git log --author="<pattern>"`              | Recherche les commits par un auteur particulier.                                                  |
| `git log --grep="<pattern>"`                | Recherche les commits avec un message de commit qui correspond à `<pattern>`.                    |
| `git log <since>..<until>`                  | Affiche les commits effectués entre `<since>` et `<until>`. Les arguments peuvent être un identifiant de commit, un nom de branche, HEAD, ou toute autre référence de révision. |
| `git log -- <file>`                         | Affiche uniquement les commits qui ont le fichier spécifié.                                       |
| `git log --graph --decorate`                | Le flag `--graph` dessine un graphique textuel des commits sur le côté gauche des messages de commit. Le flag `--decorate` ajoute les noms des branches ou des tags des commits. |

### Diff Git

| Command                                | Description                                                                                     |
|---------------------------------------|-------------------------------------------------------------------------------------------------|
| `git diff HEAD`                       | Affiche la différence entre le répertoire de travail et le dernier commit.                       |
| `git diff --cached`                   | Affiche la différence entre les changements préparés et le dernier commit.                       |

### Réinitialisation Git

| Command                                      | Description                                                                                      |
|---------------------------------------------|--------------------------------------------------------------------------------------------------|
| `git reset`                                | Réinitialise la zone de staging pour correspondre au commit le plus récent, mais laisse le répertoire de travail inchangé. |
| `git reset --hard`                         | Réinitialise la zone de staging et le répertoire de travail pour correspondre au commit le plus récent et écrase tous les changements dans le répertoire de travail. |
| `git reset <commit>`                        | Déplace le pointeur de la branche actuelle vers `<commit>`, réinitialise la zone de staging pour correspondre, mais laisse le répertoire de travail inchangé. |
| `git reset --hard <commit>`                | Identique à la précédente, mais réinitialise à la fois la zone de staging et le répertoire de travail pour correspondre. Supprime les changements non validés et tous les commits après `<commit>`. |

### Rebase Git

| Command                                      | Description                                                                                      |
|---------------------------------------------|--------------------------------------------------------------------------------------------------|
| `git rebase -i <base>`                     | Réapplique de manière interactive la branche actuelle sur `<base>`. Lance un éditeur pour entrer les commandes sur la façon dont chaque commit sera transféré vers la nouvelle base. |

### Git Pull

| Command                                      | Description                                                                                      |
|---------------------------------------------|--------------------------------------------------------------------------------------------------|
| `git pull --rebase <remote>`                | Récupère la copie du dépôt distant de la branche actuelle et la réapplique dans la copie locale. Utilise `git rebase` au lieu de `merge` pour intégrer les branches. |

### Push Git

| Command                                      | Description                                                                                      |
|---------------------------------------------|--------------------------------------------------------------------------------------------------|
| `git push <remote> --force`                 | Force le push Git même s'il résulte en une fusion non linéaire. Ne pas utiliser le flag `--force` à moins d'être absolument certain de ce que vous faites. |
| `git push <remote> --all`                   | Pousse toutes vos branches locales vers le dépôt distant spécifié.                               |
| `git push <remote> --tags`                  | Les tags ne sont pas automatiquement poussés lorsque vous poussez une branche ou utilisez le flag `--all`. Le flag `--tags` envoie tous vos tags locaux vers le dépôt distant. |


## Sources
1. https://www.atlassian.com/git/tutorials/atlassian-git-cheatsheet
