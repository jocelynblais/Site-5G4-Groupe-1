+++
title = "Enoncé"
weight = 1
[params]
  menuPre = '<i class="fa-solid fa-scroll"></i> '
+++

## Énoncé

Pour développer les compétences nécessaires à la recherche de nouvelles solutions, la rédaction de notes de cours sur une technologie émergente constitue un excellent exercice pratique. Cette démarche permet de travailler la synthèse d'informations techniques et leur transmission pédagogique.

Vous trouverez [ici](#exemple-de-technologies-a-explorer) une liste de choix possibles, mais vous pouvez choisir le sujet que vous désirez (me contacter avant). Il est possible de faire le travail sur une technologie qui n'est pas émergente, mais que vous n'avez pas vue dans vos cours.

Vous devrez rédiger des notes de cours, écrire un laboratoire pratique et mettre en place une veille technologique.

> Le travail se fait seul ou en équipes de **2 à 3** personnes.

## Évaluation

Ce travail compte pour **40%** de votre session et sera corrigé selon la grille suivante:

|Critère|Pourcentage|
|---|---|
|Veille technologique | **5%** |
|Notes de cours       | **10%**|
|Laboratoire pratique | **10%**|
|Demo en classe       | **15%**|
|**Total**            | **40%**|

## Étapes de remise

- **Validation du sujet** : après validation avec votre professeur, au plus tard 28/11 sur [moodle](https://cmontmorency.moodle.decclic.qc.ca/mod/feedback/view.php?id=482751).
- **Démonstration** : 8/12 9/12 (possibilité de l'avancée au 1/12 et 2/12 si le projet est remis ou quasi terminé)

---

## Exemple de technologies à explorer
- **Langages**: Rust, Go, GLSL...
- **Moteurs de jeux**: Unreal, Godot, unity...
- **stack cloud**: open stack, nextcloud, proxmox...
- **live coding**: graphique, musique...
- **IA**: utilisation/configuration de llms locaux, voice to text, les agents, les chain of thought..
- **sujet théorique**: cryptographie, blockchain, l'émergence, informatique quantique, techniques de compression... 

---

## Spécifications détaillées

Tout ce travail sera réaliser sur ce site même. 
- Vous allez travailler avec la plateforme `Hugo` qui permet de créer un site web statique grâce à de simple fichier markdown. 
- Vous utiliserez `git` pour récupérer le site existant, contribuer à l'ajout de nouvelles pages avec vos collaborateurs. 
- Vous utiliserez également de `docker` pour tester vos ajouts au site.

> [!warning] Attention
> Assurez vous que votre site est fonctionnel après chaque push. 
> 
> Pour une garantie maximale, clonez votre site dans un nouveau répertoire et connectez vous a votre site en local.

Référez-vous à la section [Méthode de travail](../../base-de-connaissances/methode/) pour une vision plus détaillée.

---

Insérez votre contribution dans la partie [remise](remises) du site : `content->veille_technologique->Projet->remises->VOTRESUJET`. 

Vous pouvez vous inspirer de l'exemple [Sujet A](remises/sujeta) pour les 3 parties de votre projet. 
- Notes de cours
- Atelier
- Veille technologique

Regardez comment est formaté le reste du site si vous souhaitez faire des choses un peu plus avancées (hiérarchie des répertoires, fichiers `index.md` et `_index.md`)

![alt text](remise_hugo.png)

### Veille technologique

Afin de ne pas présenter du matériel désuet à vos étudiants, vous désirez toujours être au courant des nouveautés. Et par où commencer ?

Ici, on va commencer par interroger les outils modernes, les llms. La première partie de votre veille technologique doit être le premier prompt que vous ayez formulé pour votre sujet, ainsi que la réponse fournie par le llm de votre choix.

Ensuite, discutez de la réponse : vous semble-t-elle complète ? comment ça se compare à un moteur de recherche ? à un autre llm ? à ce que vous connaissez déjà du sujet ? Avez-vous trouvez une page web qui contient déjà toutes ces informations ou suffisamment proche ? (justifier avec des liens vers des sources et qualité des sources)

Une fois que vous avez établi votre plan de recherche (étendue / profondeur du sujet), 

Vous devez mettre en place une veille technologique sur le sujet que vous avez choisi. Cette veille contiendra, minimalement, les éléments suivants :

- Premier prompt et réponse avec un llm (précisez le modèle et la version), et discussion.
- Discuter ici les sources que vous avez choisi pour vos notes de cours. 
- Vous devez un fournir un article récent traitant du sujet que vous avez sélectionné.
- quelques sources réseaux sociaux / chaine youtube, pas seulement des relais de produits commerciaux.

### Notes de cours

Vous expliquez le sujet choisi comme si vous vous adressiez à des étudiants de cinquième session, donc qui ont un bon bagage en informatique, mais qui ne connaissent pas la technologie que vous avez choisie.

Je m'attends à un minimum de 2000 mots (ce que contient environ la page de cours sur docker). Avec vos notes, un étudiant devrait être en mesure de comprendre les fondements théoriques de la technologie et d'avoir des exemples de cas d'utilisation.

Faites attention à la clarté de vos propos et au français, utilisez des outils de corrections automatiques si nécessaire.

Il est nécessaire de citer vos sources en fin de page. 

### Laboratoire
Vous créez une série d'exercices / démonstration qui permettent d'expérimenter la technologie choisie. Les exercices ne doivent pas être trop compliqués et être réalisables pour un néophyte en 2 à 3 heures. Pour estimer le temps que prendront les étudiants, les professeurs multiplient par 2 à 4 le temps qu'il leur faut pour le faire eux-mêmes. Ainsi, si vous êtes capables de faire le laboratoire en 45 minutes, il faudrait normalement de 1h30 à 3h00 pour quelqu'un qui l'essaie pour une première fois.

Les instructions doivent être claires et inclure l'installation, de préférence, fournissez un dockerfile pour l'atelier. N'hésitez à ajouter des images. Écrivez un laboratoire de la manière que vous auriez aimé que vos professeurs le fassent.

Vous devez inclure un corrigé des exercices.

### Démo

Vous devrez également faire une démonstration technique de votre projet. S'il s'agit d'une veille technologique plus théorique, cela prendra la forme d'une présentation.

Dans le cas où le projet est fait en groupe, tous les membres du groupe doivent être en mesure de faire la démo. La personne faisant la démo sera tirée au hasard le jour j. Soyez tous prêts !

Vous pouvez utiliser votre atelier comme base de présentation, mais attention, la démonstration sera beaucoup plus courte, environ 5 minutes avec les questions.

Vous pouvez aussi monter une démonstration plus ambitieuse que votre atelier, mais on doit rester dans les limites de temps.

**La démonstration aura lieu en classe.**

---

## Ressources pour l'utilisation de Hugo
- Documentation Hugo : https://gohugo.io/documentation/
- Documentation Theme Hugo Relearn: https://mcshelby.github.io/hugo-theme-relearn/index.html
- Le Dockerfile pour Hugo v148.1 et Relearn v8 est fourni sur le dépôt du site.
- Dépôt du site : 
  - groupe 1 : 
  - groupe 2 : 

## Utilisation du dépôt git

Nous allons travailler hors de classroom pour le projet, tout le monde contribuera sur le même dépôt.

Vous allez donc devoir faire une branche pour votre projet contenant vos initials et nom du sujet, par exemple : `TP_hierarchie_memoire`.

> [!warning] Attention
> Ne pas ajouter de **fichiers trop volumineux**. Si vous avez besoin de joindre une vidéo, des données d'entrainement, utilisez des liens vers l'extérieur : *youtube*, *onedrive* etc...

Votre dernier commit devra contenir `[REMISE]`, et vous ferez ensuite une pull-request dans la branche principale du site `main`.