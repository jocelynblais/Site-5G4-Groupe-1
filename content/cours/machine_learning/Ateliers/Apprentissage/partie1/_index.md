+++
title = "Partie 1"
weight = 110
+++

## L'univers des Pokémons

Un Pokémon est un animal issu du monde des jeux vidéo. Chaque Pokémon possède des caractéristiques qui lui sont propres, à savoir son type (Pokémon d'herbe, Pokémon de feu…) lui donnant alors des facultés spéciales. Ainsi, le Pokémon nommé Dracofeu, de type Feu est capable de cracher du feu.

De plus, on note l'existence de Pokémons légendaires très rares et très puissants faisant référence à un mythe en relation avec la création et l'organisation du monde (Pokémon diamant, Pokémon platine…).

Les Pokémons sont également de différentes générations faisant référence à l'évolution de l'univers des Pokémons. Les Pokémons de première génération sont ceux ayant pris naissance au tout début de la création de l'univers (création de 151 Pokémons) pour arriver à nos jours à la huitième génération avec plus de 800 Pokémons !

Dans cet univers viennent ensuite les dresseurs de Pokémons. Les dresseurs les collectionnent et les élèvent dans le but de les faire combattre entre eux jusqu'au KO. Lors d'un combat de Pokémons, opposant deux dresseurs, l'un choisit l'animal qui sera le premier à entrer dans l'arène. En fonction de ce premier Pokémon, le second dresseur choisit un animal dans sa collection qui sera en mesure de battre le premier Pokémon. Si le premier Pokémon présent dans l'arène est de type feu, il y a de fortes chances que le Pokémon choisi par l'adversaire soit de type eau afin de contrer les attaques du premier.

Cela nécessite pour le dresseur d'avoir une bonne connaissance de chaque Pokémon pour choisir celui qui pourra devenir vainqueur du combat. Pour l'aider dans son choix, les caractéristiques des Pokémons sont répertoriées dans un document appelé **Pokédex**.

## Notre mission : choisir le bon Pokémon !

En tant que dresseurs de Pokémon du 21e siècle, nous allons faire appel au Machine Learning pour nous aider à faire le bon choix de Pokémon et ainsi gagner nos combats. Pour cela, nous allons nous appuyer sur des données en provenance du Pokédex, mais aussi sur des données issues des différents combats afin de trouver le bon modèle de prédiction qui pourra alors nous assurer une victoire lors de chaque bataille !

---

## Des données pour un apprentissage supervisé

### Des données basées sur l'expérience

Le Machine Learning est basé sur l'utilisation de données afin de permettre à notre ordinateur d'apprendre et de pouvoir réaliser des prédictions. Ces données doivent être en relation avec la mission qui nous est confiée et basée sur l'expérience.

Dans notre cas, l'expérience consiste à connaître les issues de combats de Pokémons.

### Disposer d'un grand nombre de données d'apprentissage

Une machine n'est pas capable d'apprendre sur un petit jeu de données, car elle doit pouvoir étudier toutes les possibilités pour réaliser ses prédictions. Par conséquent, plus le nombre de cas d'études pour résoudre un problème est important, plus les prédictions seront précises.

### Des données d'apprentissage et des données de tests

Tout comme l'être humain, il est nécessaire de valider l'apprentissage de la machine afin de pouvoir corriger les écarts d'apprentissage (appelés biais) et ajuster ou modifier le modèle d'apprentissage. Pour cela, nous avons besoin de données d'apprentissage et de données de tests.

---

## Les étapes à réaliser pour mener à bien un projet de Machine Learning

Mener à bien un projet de Machine Learning consiste à réaliser six étapes consécutives :

1. **Définition du problème à résoudre**
2. **Acquisition des données d'apprentissages et de tests**
3. **Préparer et nettoyer les données**
4. **Analyser, explorer les données**
5. **Choisir un modèle d'apprentissage**
6. **Visualiser les résultats, et ajuster ou modifier le modèle d'apprentissage**

La phase de préparation des données est la plus importante dans un projet de Machine Learning, car en tant qu'humains, nous devons essayer de trouver les données les plus intéressantes qui nous permettront de répondre au problème donné.

Bien plus qu'une simple analyse des données, il faut déterminer comment il nous est possible de résoudre manuellement le problème, à partir des informations dont nous disposons, avant de le confier à la machine.

Ainsi, un même jeu de données peut être exploité différemment en fonction du problème donné.

---

### Modules python utilisés

Un module peut être assimilé à une boîte à outils offrant des fonctions complémentaires dans un domaine dédié, nous évitant ainsi de les coder nous-mêmes. Concernant notre sujet, il existe des modules spécialisés dans l'analyse de données et l'intelligence artificielle, c'est donc tout naturellement que nous allons utiliser certains d'entre eux pour notre projet.

En voici la liste et leur rôle :

| Module | Rôle |
|---------|------|
| Numpy | Permet la manipulation de tableaux et matrices |
| Pandas | Permet la manipulation et l'analyse de données |

### Utilisation des modules dans un script Python

L'utilisation d'un module dans un script Python s'effectue par l'usage de la commande import comme le montre le code ci-dessous :

```python
import numpy as nmp
```

Cette ligne de code peut être interprétée comme "Importer le module numpy et l'utiliser sous le nom nmp". Ce nom est ce que l'on appelle un alias faisant référence au module importé. C'est cet alias que nous utiliserons par la suite dans notre script pour accéder aux fonctions proposées par le module.

### Référencement des fichiers de données dans notre projet

La dernière étape de création du projet consiste à importer les fichiers de données d'apprentissage et de tests.

Pour ce faire, créez un nouveau répertoire dans la structure du projet en faisant un clic droit sur le nom du projet puis choisissez l'option New et la sous-option Directory. Donnez-lui ensuite le nom de **datas**.

Déposez à présent dans le répertoire datas nouvellement créé les deux fichiers : 
- [**pokedex.csv**](pokedex.csv)
- [**combats.csv**](combats.csv)

Notre projet est à présent créé et correctement configuré. Nous allons pouvoir commencer l'analyse des données.

## Définir le problème à résoudre

Comme évoqué en début de chapitre, la problématique à laquelle nous devons répondre consiste à préconiser au dresseur de Pokémon l'animal à utiliser lors d'un combat afin d'être le vainqueur.

---

## Préparation des données

Dans cette étape, nous allons réaliser une lecture approfondie de nos données afin de comprendre leur rôle et les impacts qu'elles peuvent avoir dans l'objectif de prédiction que nous nous sommes fixé. Nous allons en quelque sorte essayer de résoudre le problème "manuellement" en formulant des hypothèses et en essayant de sélectionner les données qui répondront à celles-ci.

L'étude des données passe notamment par leur description (nom, type…), ainsi que par divers processus de traitement tels que le nettoyage (suppression des données inutiles, recherche des données manquantes) et enfin la combinaison entre elles, aussi appelée agrégation, dans le but de disposer d'un jeu de connaissances (observations) utilisables et appropriées à l'apprentissage et à l'atteinte de notre objectif.

### De quelles données disposons-nous ?

Les fichiers de données dont nous disposons portent l'extension CSV (Comma Separated Value). C'est-à-dire que les données contenues dans ces fichiers sont séparées par des virgules. Pour vous donner une petite idée du contenu de ces fichiers, vous pouvez les ouvrir à l'aide du logiciel Excel ou via un simple éditeur de texte tel que Notepad ou bien encore directement dans vscode avec csv edit.

Dans notre exemple, les fichiers sont de petite taille, pouvant être ouverts et exploités par des logiciels. Mais dans la plupart des cas liés au Machine Learning, les fichiers contiennent énormément de données, ne pouvant alors plus être exploités par des logiciels traditionnels.

La démarche de préparation des données sera donc réalisée en supposant que les fichiers dont nous disposons sont trop volumineux pour être ouverts dans Excel ou dans l'outil NotePad de Windows. Nous travaillerons donc à l'aveugle et procéderons donc à la découverte progressive de nos données.

Nous allons utiliser le module Pandas, disposant d'une fonction de lecture de fichiers CSV (read_csv), capable de découper le contenu du fichier et de le stocker dans un tableau, appelé **Dataframe**, afin de pouvoir facilement analyser et manipuler les données. Nous ajoutons quelques configurations pour une meilleure mise en forme avec les notebooks.

```python
import pandas as pd

pd.set_option('display.max_columns', None)  # Show all columns
pd.set_option('future.no_silent_downcasting', True)
```

Un Dataframe est, au sens Python du terme, un dictionnaire dont les clés sont les noms des features et les valeurs sont les données contenues dans chaque caractéristique.

Maintenant que les données sont stockées dans un Dataframe, il est important de connaître les libellés des colonnes pour avoir une idée des données dont nous disposons et de leur sémantique :

```python
nosPokemons = pd.read_csv("data/pokedex.csv")

#Affichage des colonnes du Dataframe
print(nosPokemons.columns.values)
```

Ce script donnant le résultat suivant, soit au total 12 colonnes :

```
['NUMERO' 'NOM' 'TYPE_1' 'TYPE_2' 'POINTS_DE_VIE'
'NIVEAU_ATTAQUE'
'NIVEAU_DEFENSE' 'NIVEAU_ATTAQUE_SPECIALE'
'NIVEAU_DEFENSE_SPECIALE'
'VITESSE' 'GENERATION' 'LEGENDAIRE']
```

| Colonne | Signification |
|---------|---------------|
| NUMERO | Identifiant du Pokémon |
| NOM | Nom du Pokémon |
| TYPE_1 | Type primaire (Herbe, Feu, Acier…) |
| TYPE_2 | Type secondaire (Herbe, Feu, Acier…) |
| POINTS_DE_VIE | Points de vie du Pokémon |
| NIVEAU_ATTAQUE | Le niveau d'attaque du Pokémon |
| NIVEAU_DEFENSE | Le niveau de défense du Pokémon |
| NIVEAU_ATTAQUE_SPECIALE | Le niveau d'attaque spéciale du Pokémon |
| NIVEAU_DEFENSE_SPECIALE | Le niveau de défense spéciale du Pokémon |
| VITESSE | Vitesse du Pokémon |
| GENERATION | Numéro de génération à laquelle appartient le Pokémon |
| LEGENDAIRE | Le Pokémon est-il légendaire ? Il s'agit d'une donnée booléenne (Vrai ou Faux) |

### Affichage des dix premières lignes de nos données

Nous connaissons à présent les types de données propres à nos Pokémons, il nous faut à présent visualiser leur contenu.

Pour afficher les dix premières lignes de nos données, nous allons utiliser la fonction Head du Dataframe nosPokemons que nous avons créé.

```python
print(nosPokemons.head(10))
```

Voici le résultat de ce script :

```
NUMERO NOM TYPE_1 TYPE_2 POINTS_DE_VIE NIVEAU_ATTAQUE
0 1 Bulbizarre Herbe Poison 45 49
1 2 Herbizarre Herbe Poison 60 62
2 3 Florizarre Herbe Poison 80 82
3 4 Mega Florizarre Herbe Poison 80 100
4 5 Salameche Feu NaN 39 52
5 6 Reptincel Feu NaN 58 64
6 7 Dracaufeu Feu Vol 78 84
7 8 Mega Dracaufeu X Feu Dragon 78 130
8 9 Mega Dracaufeu Y Feu Vol 78 104
9 10 Carapuce Eau NaN 44 48

NIVEAU_DEFFENCE NIVEAU_ATTAQUE_SPECIALE NIVEAU_DEFENSE_SPECIALE VITESSE
0 49 65 65 45
1 63 80 80 60
2 83 100 100 80
3 123 122 120 80
4 43 60 50 65
5 58 80 65 80
6 78 109 85 100
7 111 130 85 100
8 78 159 115 100
9 65 50 64 43

GENERATION LEGENDAIRE
0 1 FAUX
1 1 FAUX
2 1 FAUX
3 1 FAUX
4 1 FAUX
5 1 FAUX
6 1 FAUX
7 1 FAUX
8 1 FAUX
9 1 FAUX
```

Il est à présent possible d'analyser plus en détail les données. En Data Science, chaque ligne de notre fichier est appelée une **observation** et chaque colonne une **feature** (caractéristique).

### Quelles sont les features de catégorisation ?

Des features dites de catégorisation permettent de classer les données dans différents groupes à l'aide de caractéristiques communes.

Ainsi, les features pouvant nous aider à catégoriser ou à classer nos Pokémons dans des groupes différents sont :
• TYPE_1
• TYPE_2
• LEGENDAIRE
• GENERATION

En effet, il est possible de regrouper les Pokémons par type, par génération et par le fait qu'ils soient légendaires ou non. Les autres features ne peuvent pas être utilisées dans la catégorisation, car elles sont différentes par Pokémon.

Il est encore possible de classer ces features de catégorisation, en tant que feature de catégorisation catégorielle ou ordinale.

Une donnée de catégorisation ordinale est une donnée chiffrée. Dans notre cas, il s'agit de la génération du Pokémon. Pour les autres données de catégorisation, il s'agit de données de catégorisation catégorielle.

| DONNEES DE CATEGORISATION |
|---------------------------|
| **CATEGORIELLE** | **ORDINALE** |
| TYPE_1 | GENERATION |
| TYPE_2 | |
| LEGENDAIRE | |

Connaître les données de catégorisation nous permet de définir des données qui peuvent nous servir dans la résolution de notre problème. Par exemple, il se peut que si le Pokémon est de génération 2 ou bien de type Herbe ou bien encore légendaire, il est alors le vainqueur du combat. Cela permet donc d'optimiser l'algorithme de prise de décision.

De par leur importance, lors de la phase de nettoyage des données, ces features ne devront pas être supprimées.

### Quelles données sont de type numérique ?

Dans le traitement des données, il est difficile de s'appuyer sur des données non numériques. Par conséquent, il est important de connaître les données numériques qui pourront être le socle de nos analyses.

En observant les dix premières données, on peut constater que les données numériques sont :
• NUMERO
• POINT_DE_VIE
• NIVEAU_ATTAQUE
• NIVEAU_DEFENSE
• NIVEAU_ATTAQUE_SPECIALE
• NIVEAU_DEFENSE_SPECIALE
• VITESSE

Là encore, il est possible de classer les données numériques en deux types : Les données numériques discrètes et les données numériques continues.

Une donnée numérique discrète est une donnée ayant une valeur dénombrable et énumérable (le nombre de pattes d'un Pokémon…).

Une donnée numérique continue, est une donnée ayant un nombre infini de valeurs formant un ensemble continu. Par exemple, le temps d'un combat de Pokémon peut être compris entre 1 et 60 minutes et peut prendre la valeur de 1 minute et 30 secondes, 3 minutes et 34 secondes… La taille et le poids d'un Pokémon sont également des données numériques continues, car un Pokémon peut peser 10,5 kg 10,6 kg, 12 kg…

Dans notre jeu d'observation, les données numériques dont nous disposons sont de type numérique discret.

### Que faut-il penser de la feature LEGENDAIRE ?

Nous avons vu que la feature LEGENDAIRE est de type booléen et qu'être un Pokémon légendaire est une chose rare et permet de disposer de force supplémentaire.

Cependant, si nous utilisons la feature dans son état actuel, elle sera considérée comme une chaîne de caractères et ne sera pas exploitable, car n'oublions pas que seules les données numériques sont appréciées du Machine Learning.

Il nous faut alors transformer cette donnée pour qu'elle devienne utilisable. Si la feature possède la valeur VRAI, elle sera alors transformée en 1, sinon elle prendra la valeur 0.

Pour ce faire, utilisons l'instruction suivante :

```python
# remplacement de VRAI FAUX par 1 0
nosPokemonsClean = nosPokemons
nosPokemonsClean["LEGENDAIRE"] = nosPokemonsClean["LEGENDAIRE"].replace("VRAI", 1)
nosPokemonsClean["LEGENDAIRE"] = nosPokemonsClean["LEGENDAIRE"].replace("FAUX", 0)
nosPokemonsClean["LEGENDAIRE"] = nosPokemonsClean["LEGENDAIRE"].astype(int)
print(nosPokemonsClean.head())
```

### Manque-t-il des données ?

Maintenant que nous avons classé nos observations et transformé la feature LEGENDAIRE, la question à se poser est "Combien avons-nous d'observations ?"

Pour cela, nous allons utiliser la fonction shape du Dataframe :

```python
#Comptage du nombre d'observations et de features
print(nosPokemonsClean.shape)
```

Voici le résultat :
```
(800,12)
```

Cela signifie que notre jeu de données comporte 800 observations (Pokémons) comportant 12 caractéristiques (correspondant au nombre de colonnes déterminées dans la partie "De quelles données disposons-nous ?" dans ce chapitre).

Regardons à présent si des observations sont manquantes. Pour cela, nous pouvons utiliser la fonction info() du Dataframe nous donnant, entre autres, le nombre d'éléments par feature :

```python
#Informations sur notre jeu de données
print(nosPokemonsClean.info())
```

```
#Résultat de l'exécution :
<class 'pandas.core.frame.DataFrame'>
RangeIndex: 800 entries, 0 to 799
Data columns (total 12 columns):
NUMERO 800 non-null int64
NOM 799 non-null object
TYPE_1 800 non-null object
TYPE_2 413 non-null object
POINTS_DE_VIE 800 non-null int64
NIVEAU_ATTAQUE 800 non-null int64
NIVEAU_DEFFENCE 800 non-null int64
NIVEAU_ATTAQUE_SPECIALE 800 non-null int64
NIVEAU_DEFENSE_SPECIALE 800 non-null int64
VITESSE 800 non-null int64
GENERATION 800 non-null int64
LEGENDAIRE 800 non-null int32
dtypes: int64(8), object(4)
memory usage: 75.1+ KB
None
```

À la lecture de ce résultat, nous pouvons constater :
• Que nous disposons de 800 observations (800 entries).
• Que nous disposons de 12 features.
• Qu'il manque 1 nom (799 éléments sur 800 éléments attendus).
• Qu'il manque 387 Type_2 (413 éléments sur 800 éléments attendus).

On note en complément de ces informations que le type des différentes données est spécifié. Ainsi, les données numériques sont précisées par l'indication int64 (int signifiant entier). Pour les autres, ce sont des données de type Object pouvant alors prendre la forme de chaîne de caractères (cas des features NOM, TYPE_1 et TYPE_2).

### À la recherche des features manquantes

Comme nous venons de le constater, il manque quelques données. En ce qui concerne la feature TYPE_2, cela peut s'expliquer par le fait qu'un Pokémon peut ne pas avoir de type secondaire. Les manques pour cette feature sont donc normaux et acceptables.

Concentrons-nous à présent sur le nom manquant. Pour le moment, nous ne savons pas si le nom du Pokémon a une incidence forte sur la résolution de notre problème. Est-ce que le fait de s'appeler Dracofeu fait que l'on gagne à chaque fois les combats ? Ne pouvant pas répondre à cette question de façon positive ou négative, nous ne pouvons donc pas laisser cette observation manquante.

La première chose à faire est de trouver l'observation ayant le nom manquant.

L'instruction ci-dessous permet de rechercher et d'afficher l'observation du Dataframe nosPokemon, ayant la feature NOM non renseignée (isNull) :

```python
print(nosPokemonsClean[nosPokemonsClean['NOM'].isnull()])
```

Ce qui nous permet de déterminer qu'il s'agit de l'observation 62 :

```
NUMERO NOM TYPE_1 TYPE_2 POINTS_DE_VIE NIVEAU_ATTAQUE
62 63 NaN Combat NaN 65 105
```

Il existe deux façons de traiter les observations manquantes :
• La suppression pure et simple de l'observation,
• Le remplacement de la valeur par une valeur artificielle, c'est-à-dire calculée, ou par une valeur réelle.

Comme nous l'avons évoqué, l'ensemble des Pokémons et leurs caractéristiques sont référencés dans le Pokédex. Ce document est accessible à cette adresse :
https://www.pokepedia.fr/Liste_des_Pok%C3%A9mon_dans_l%27ordre_du_Pok%C3%A9dex_National.

Les Pokémons contenus dans notre fichier sont classés dans l'ordre de ce Pokédex. Il nous suffit donc de connaître le nom du Pokémon précédent et le nom du Pokémon suivant pour ensuite pouvoir réaliser une recherche dans le Pokédex et trouver le nom du Pokémon manquant.

Le Pokémon ayant le numéro d'observation 62 se trouve entre les observations 61 et 63, soit les Pokémons Férosinge et Caninos :

```python
print(nosPokemonsClean['NOM'][61])
print(nosPokemonsClean['NOM'][63])
```

```
Ferosinge
Caninos
```

En consultant à présent le Pokédex, on peut en déduire que le nom du Pokémon manquant est **Colossinge** !

Il ne nous reste plus qu'à renseigner la feature NOM de l'observation n°62 comme suit :

```python
nosPokemonsClean['NOM'][62] = "Colossinge"
```

Cette modification peut être à l'origine d'un avertissement de type "A value is trying to be set on a copy of a slice from a Dataframe" lors de l'exécution du script. Cet avertissement peut être ignoré.

Nous pouvons vérifier la bonne prise en compte de cette modification à l'aide de l'instruction :

```python
print(nosPokemonsClean['NOM'][62])
```

```
Colossinge
```

**Attention**, la modification apportée par cette instruction ne concerne que le Dataframe et ne met pas à jour le fichier de données original. La mise à jour du fichier Pokedex.csv situé dans le répertoire Datas de notre projet peut se faire en réalisant un double clic sur le fichier ayant pour action d'ouvrir le fichier dans l'éditeur, nous permettant alors de renseigner la feature manquante.

Avant la modification :
```
63,,Combat,,65,105,60,60,70,95,1,FAUX
```

Après la modification :
```
63,Colossinge,Combat,,65,105,60,60,70,95,1,FAUX
```

### Place aux observations des combats

Nous venons d'analyser les observations relatives aux Pokémons. Nous devons à présent nous concentrer sur celles des combats, répertoriées dans le fichier combats.csv en procédant par la même démarche d'analyse :

• Chargement du fichier
• Affichage des features
• Affichage des dix premières observations
• Classement des features : donnée catégorielle, numérique continue ou numérique discrète
• Comptage du nombre d'observations et recherche d'éventuelles données absentes

```python
#Chargement des données des combats
combats = pd.read_csv("datas/combats.csv")

#Affichage des colonnes du Dataframe
print(combats.columns.values)

#Affichage des 10 premières lignes du Dataframe
print(combats.head(10))

#Comptage du nombre de lignes et de colonnes
print (combats.shape)

#Informations sur notre jeu de données
print (combats.info())
```

Voici le résultat de cette analyse :

• Le jeu de données comporte 50 000 observations et 3 features.
• Les features sont "Premier_Pokemon", "Second_Pokemon" et "Pokemon_Gagnant".
• La caractéristique "Pokemon_Gagnant" contient le numéro du Pokémon gagnant à l'issue du combat.
• Chaque feature est de type numérique.
• Il ne manque aucune information.

### Assemblage des observations

Nous disposons de deux jeux d'observations. L'un consacré aux caractéristiques des Pokémons, l'autre aux combats. Il nous faut à présent réunir ces informations afin de savoir pour chaque Pokémon le nombre de combats menés ainsi que le nombre de victoires.

Pour avoir cette vision, qui nous permettra de connaître les Pokémons ayant une probabilité de victoire plus importante que les autres, nous devons assembler (agréger) les deux Dataframe Pokedex et Combats.

#### Nombre de combats menés

Avant de réaliser cette agrégation, nous allons réaliser quelques actions sur le Dataframe combats, afin de calculer le nombre de combats menés par chaque Pokémon.

Lors d'un combat, le Pokémon peut être utilisé en première position ou en seconde position. Cette position à une importance car elle permet de savoir qui va donner le premier coup. Dans le cas où notre pokemon à peu de points de vie, s'il joue en seconde position, on risque de perdre avant de donner notre premier coup.

| COMBAT | PREMIER POKEMON | SECOND POKEMON |
|---------|-----------------|----------------|
| 1 | BULBIZARRE | DRACAUFEU |
| 2 | DRACAUFEU | COLOSSINGE |
| 3 | DRACAUFEU | PIKACHU |

Donnant alors le nombre de combats par Pokémon :

| POKEMON | NOMBRE DE COMBATS |
|---------|-------------------|
| BULBIZARRE | 1 |
| DRACAUFEU | 3 |
| COLOSSINGE | 1 |
| PIKACHU | 1 |

Pour connaître le nombre de combats menés par un Pokémon, il faut donc connaître le nombre de fois où il a été en première position auquel on ajoute le nombre de fois où il a été en seconde position.

Mettons cela en pratique, en utilisant l'instruction suivante :

```python
nbFoisPremierePosition = combats.groupby('Premier_Pokemon').count()
print(nbFoisPremierePosition)
```

Si l'on reprend notre exemple, les données que nous obtenons seraient :

| POKEMON | NOMBRE PREMIERE_POSITION |
|---------|--------------------------|
| BULBIZARRE | 1 |
| DRACAUFEU | 2 |
| COLOSSINGE | 0 |
| PIKACHU | 0 |

Il s'agit donc de compter le nombre de fois où le Pokémon est en première position via l'instruction `count()` puis de regrouper le résultat via l'instruction `groupBy()`.

Exécutons le code saisi et observons le résultat :

À la première lecture, ce tableau est difficile à comprendre et semble peu cohérent.

En effet, on s'attendrait à obtenir en intitulé de première colonne "NUMERO" puis une autre colonne "NOMBRE_DE_FOIS_EN_PREMIERE_POSITION". Mais cela n'est pas le cas.

La première colonne est notre critère de regroupement, c'est-à-dire la feature "PREMIER_POKEMON". Les données correspondent au numéro de Pokémon.

Lorsque l'on réalise un regroupement à l'aide de la fonction `groupBy()`, l'ensemble des features du jeu de données prennent la valeur de ce regroupement. C'est donc pour cela que les features SECOND_POKEMON et POKEMON_GAGNANT ont la même valeur.

| PREMIER_POKEMON | SECOND_POKEMON | POKEMON_GAGNANT |
|-----------------|----------------|------------------|
| 1 | 70 | 70 |
| 2 | 55 | 55 |
| 3 | 68 | 68 |
| … | … | … |

Si nous voulions donner plus de sens au résultat, nous pourrions le faire en changeant le nom des colonnes, les deuxième et troisième colonnes ayant le même intitulé :

| NUMERO DU POKEMON | NOMBRE DE FOIS EN PREMIERE POSITION | NOMBRE DE FOIS EN PREMIERE POSITION |
|-------------------|--------------------------------------|--------------------------------------|
| 1 | 70 | 70 |
| 2 | 55 | 55 |
| 3 | 68 | 68 |
| … | … | … |

Procédons à présent de la même façon pour connaître le nombre de fois où chaque Pokémon a combattu en seconde position.

```python
nbFoisSecondePosition = combats.groupby('Second_Pokemon').count()
print(nbFoisSecondePosition)
```

Puis réalisons la somme des deux calculs pour connaître le nombre total de combats.

```python
nombreTotalDeCombats = nbFoisPremierePosition + nbFoisSecondePosition
print(nombreTotalDeCombats)
```

Là encore, ne pas tenir compte des noms de colonnes affichés dans la réponse. La première correspond au numéro de Pokémon, la seconde au nombre de combats menés.

Remarquez la force du module Pandas, qui par un simple + a réussi à agréger l'ensemble des deux tableaux. Si nous avions codé cette fonctionnalité, nous aurions dû parcourir la liste des Pokémon tout en parcourant les deux tableaux de résultats afin de faire la somme du nombre de combats menés en première et seconde position.

#### Nombre de combats gagnés

Passons à présent au nombre de combats gagnés par chaque Pokémon. Connaître cette information nous permettra de savoir si certains Pokémons n'ont jamais gagné de combats, ce qui nous permettra déjà de savoir qu'il faudra éviter de les utiliser lors d'un combat :

```python
nombreDeVictoires = combats.groupby('Pokemon_Gagnant').count()
print(nombreDeVictoires)
```

| POKEMON | NOMBRE DE COMBATS GAGNES |
|---------|--------------------------|
| 1 | 37 |
| 2 | 46 |
| 3 | 89 |
| 4 | 70 |
| … | … |
| 228 | 104 |

En agrégeant les deux tableaux que nous venons de constituer, on constate que le Pokémon 228 a gagné 104 combats, alors qu'il en a mené 150 (cf. tableau précédent) alors que les quatre premiers Pokémons ont gagné tous leurs combats.

En utilisant la fonction `info()`, nous constatons que nous disposons que de 783 observations. Cela signifie qu'il existe des Pokémons n'ayant jamais gagné ! Charge à présent de les découvrir.

#### Agrégation des données avec le Pokédex

Le moment est maintenant venu d'agréger nos données avec le Pokédex. Cette agrégation va nous permettre d'avoir une vue centralisée des données et de permettre une analyse plus approfondie.

Dans un premier temps, nous allons créer une liste comportant :
• Les numéros des Pokémons
• Le nombre de combats menés
• Le nombre de combats gagnés
• Le pourcentage de victoires par rapport au nombre de combats menés

```python
listeAAgreger = combats.groupby('Pokemon_Gagnant').count()
listeAAgreger.sort_index()

#On ajoute le nombre de combats
listeAAgreger['NBR_COMBATS'] = nbFoisPremierePosition.Pokemon_Gagnant + nbFoisSecondePosition.Pokemon_Gagnant

#On ajoute le nombre de victoires
listeAAgreger['NBR_VICTOIRES'] = nombreDeVictoires.Premier_Pokemon

#On calcule le pourcentage de victoires
listeAAgreger['POURCENTAGE_DE_VICTOIRES'] = nombreDeVictoires.Premier_Pokemon / (nbFoisPremierePosition.Pokemon_Gagnant + nbFoisSecondePosition.Pokemon_Gagnant)

#On affiche la nouvelle liste
print(listeAAgreger)
```

La première étape du code consiste à créer une liste dont le contenu sera une extraction qui nous permet d'obtenir les numéros des Pokémons.

Pour cette extraction, nous avons choisi celle indiquant le nombre de victoires par Pokémon, mais nous aurions pu également choisir celle indiquant le nombre de fois où le Pokémon se trouve en première position, ou bien encore celle précisant le nombre de fois où il a combattu en seconde position. L'important est que nous obtenions la liste des numéros de Pokémon qui nous servira de clé permettant l'agrégation avec le Pokédex (cf. figure suivante).

Notons également l'usage de la fonction `sort_index()` qui permet de trier par ordre croissant les numéros des Pokémons, correspondant à l'ordre du Pokédex.

Une fois le code exécuté, voici la nouvelle liste que nous obtenons :

| Pokemon_Gagnant | Premier_Pokemon | Second_Pokemon | NBR_COMBATS | NBR_VICTOIRES | POURCENTAGE_DE_VICTOIRES |
|-----------------|-----------------|----------------|-------------|---------------|--------------------------|
| 1 | 37 | 37 | 133 | 37 | 0.278195 |
| 2 | 46 | 46 | 121 | 46 | 0.380165 |
| 3 | 89 | 89 | 132 | 89 | 0.674242 |
| 4 | 70 | 70 | 125 | 70 | 0.560000 |
| … | … | … | … | … | … |

Il ne nous reste plus qu'à agréger cette liste avec le Dataframe nosPokemons représentant le Pokédex. Cela se fait à l'aide la fonction `merge()` du Dataframe.

```python
nouveauPokedex = nosPokemonsClean.merge(listeAAgreger, left_on='NUMERO', right_index = True, how='left')
print(nouveauPokedex.describe())
```

Le résultat de ce code est la création d'un nouveau Dataframe que nous avons nommé `nouveauPokedex`, issu de l'agrégation du Dataframe `nosPokemons` avec la liste `listeAAgreger`.

Cette agrégation fut possible en utilisant comme clé d'agrégation l'index de la liste (right_index=True) lié à la feature Numero du Dataframe nosPokemons.
