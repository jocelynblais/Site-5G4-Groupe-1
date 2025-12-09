# Clonez le dépot

Ce site utilise de le thème relearn. Cette dépendance est mise comme un sous module.

`$ git clone --recurse-submodules <url>`

Autrement après un clone simple :

`$ git submodule init`

`$ git submodule update`

Si vous oubliez cette étape, la commande `$ hugo serve` retournera une erreur.

# Testez vos changements

Ce site Hugo a besoin de la version 148.1 minimum à cause de sa dépendance au thème relearn. 

Créez un dev container avec vscode en utilisant le Dockerfile fourni.

Faites vos modifications dans la partie `content` du site.

> [!warning]
> N'ajoutez pas de fichiez volumineux au dépot. Maximum 1Mo pour une image.
>
> Git est fait pour gérer du texte, les gros fichiers binaire endommage les performances du dépot.
>
> Si vous devez joindre un fichier volumineux, stockez le quelque part en ligne, et faite un lien vers votre fichier.

Dans un terminal du dev container, vous pouvez taper la commande suivante :
`$ hugo serve`

Vous aurez un serveur web de test disponible à l'adresse http://127.0.0.1:1313

> [!TIP]
> Le script `start_hugo.sh` peut vous servir d'inspiration si vous souhaitez exécuter votre container manuellement (hors de vscode).
> L'image du script à été construite avec `docker build -t hugo_relearn .`