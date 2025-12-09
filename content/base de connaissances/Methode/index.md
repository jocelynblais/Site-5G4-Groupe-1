+++
title = "Méthode de travail"
weight = 1
+++

Nous ferons une utilisation intensive de [**git**](../git), [**docker**](../../cours/docker) et [**vscode**](../vscode).

Voici un exemple de méthode qui vous sera utile tous le long du cours : 

1. Créez votre répertoire de travail (`mkdir`).
2. Clonez le code du projet sur lequel vous travaillez, ou initialisez un nouveau repos git (`git clone`, `git init`). 
3. Créez votre branche de travail dans le repos (`git checkout -b `).
4. Créez votre Dockerfile pour votre projet, ou utilisez celui fourni avec le projet (cours sur [Dockerfile](../../cours/docker/#les-dockerfile)).
5. Ouvrez votre repertoire de travail dans un dev container de [vscode](../vscode).
6. Ajoutez votre nouvelle feature / Corrigez un bug / refactor du code / etc
7. Publiez vos modifications (`commit` + `push`). 

> [!tip] 
> La dernière étape est plus simple a faire hors du conteneur, normalement vos autorisations github sont déjà faites sur la machine hôte. Mais rien ne vous empêche de donner ces authorisations dans le conteneur.

Vous trouverez une vidéo de démonstration [ici](../vscode/#dev-container-de-base)