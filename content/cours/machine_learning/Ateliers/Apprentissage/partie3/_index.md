+++
title = "Partie 3"
weight = 120
+++

## Passons à la phase d'apprentissage

Le problème que nous devons résoudre consiste à déterminer si lors d'un combat, un Pokémon a de grandes chances de gagner.

Comme nous disposons de données d'apprentissage, nous sommes donc dans un cas de Machine Learning dit "supervisé". C'est-à-dire que la machine va apprendre en fonction de ce qu'on lui fournit en entrée.

Dans ce type de cas, nous disposons alors de deux types d'algorithmes : ceux dédiés à la **classification** ou ceux dédiés à la **régression**.

La classification permet d'organiser les prédictions en groupe, quant à la régression elle permet de définir une valeur.

Dans notre cas, nous devons prédire le pourcentage de victoire, c'est donc une valeur et c'est naturellement que nous utiliserons les algorithmes de régression que nous avons découverts dans le chapitre Principaux algorithmes du machine learning, à savoir :
• **La régression linéaire**
• **Les arbres de décisions**
• **Les forêts aléatoires**

### Découpage des observations en jeu d'apprentissage et jeu de tests

La première étape avant tout apprentissage est de découper les observations dont nous disposons en un jeu d'apprentissage avec lequel la machine va réaliser son apprentissage et en jeu de tests avec lequel la machine va évaluer son apprentissage. Pour cela, nous allons utiliser le module Scikit-Learn que nous vous invitons à ajouter à votre projet (avec les packages).


Dans un nouveau fichier de script Python, nous allons donc dans un premier temps charger ce fichier et supprimer les lignes pour lesquelles des valeurs sont manquantes comme à la ligne 12 du fichier :

![alt text](image-4.png)

```python
#Chargement du dataset avec pour séparateur des tabulations
dataset = pnd.read_csv("datas/dataset.csv",delimiter='\t')

#Suppression des lignes ayant des valeurs manquantes
dataset = dataset.dropna(axis=0, how='any')
```

Puis nous allons ensuite extraire les features qui seront source d'apprentissage (données X), c'est-à-dire les colonnes :
POINTS_ATTAQUE;POINTS_DEFFENCE;POINTS_ATTAQUE_SPECIALE;
POINT_DEFENSE_SPECIALE;POINTS_VITESSE;NOMBRE_GENERATIONS.

```python
#X = on prend toutes les données, mais uniquement les features 5 à 12 
#(ne pas hésiter à ouvrir le fichier afin de bien visualiser les features concernées)
#POINTS_ATTAQUE;POINTS_DEFFENCE;POINTS_ATTAQUE_SPECIALE;POINT_DEFENSE_SPECIALE;POINTS_VITESSE;NOMBRE_GENERATIONS
X = dataset.iloc[:, 5:12].values
```

Et les features que nous devons prédire à partir de ces données d'apprentissage, c'est-à-dire les valeurs de la colonne POURCENTAGE_DE_VICTOIRE.

```python
#y = on prend uniquement la feature POURCENTAGE_DE_VICTOIRE (17ème feature)
y = dataset.iloc[:, 17].values
```

En d'autres termes, nous allons apprendre à la machine à prédire un pourcentage de victoire d'un Pokémon en fonction de ses points d'attaque (standards et spéciaux), de sa vitesse, de ses points de vie, de ses points de défense (standards et spéciaux), et de son nombre de générations. Nous venons donc de définir les **variables prédictives (X)** et la **variable à prédire (Y)**.

Chaque variable sera ensuite découpée en un groupe d'apprentissage (Train) et en un groupe de test (Test). Nous aurons donc un groupe X_APPRENTISSAGE, Y_APPRENTISSAGE permettant à la machine d'apprendre et un groupe X_VALIDATION,Y_VALIDATION lui permettant de valider son apprentissage.

Les tableaux ci-dessous vous permettront sans doute de mieux comprendre ces différents découpages.

Le jeu d'observation complet (réduit à dix observations pour l'exemple) :

| NOM | POINTS_DE_VIE | NIVEAU_ATTAQUE | […] | VITESSE | POURCENTAGE_DE_VICTOIRE |
|-----|---------------|----------------|-----|---------|-------------------------|
| Bulbizarre | 45 | 49 | […] | 45 | 0.2781954887218045 |
| Herbizarre | 60 | 62 | […] | 60 | 0.38016528925619836 |
| Florizarre | 80 | 82 | […] | 80 | 0.6742424242424242 |
| Mega-Florizarre | 80 | 100 | […] | 80 | 0.56 |
| Salameche | 39 | 52 | […] | 65 | 0.49107142857142855 |
| Reptincel | 58 | 64 | […] | 80 | 0.5423728813559322 |
| Dracaufeu | 78 | 84 | […] | 100 | 0.8646616541353384 |
| Mega-Dracaufeu X | 78 | 130 | […] | 100 | 0.8561151079136691 |
| Mega-Dracaufeu Y | 78 | 104 | […] | 100 | 0.8444444444444444 |
| Carapuce | 44 | 48 | […] | 43 | 0.1623931623931624 |

Découpage en variables explicatives (X) et une variable expliquée (Y) :

| X | | | | | Y |
|---|---|---|---|---|---|
| NOM | POINTS_DE_VIE | NIVEAU_ATTAQUE | […] | VITESSE | POURCENTAGE_DE_VICTOIRE |
| Bulbizarre | 45 | 49 | […] | 45 | 0.2781954887218045 |

On prend 80 % des variables explicatives et des variables expliquées pour créer le jeu d'apprentissage (Train) :

| X_APPRENTISSAGE (80 %) | | | | | Y_APPRENTISSAGE (80 %) |
|-------------------------|---|---|---|---|------------------------|
| NOM | POINTS_DE_VIE | NIVEAU_ATTAQUE | […] | VITESSE | POURCENTAGE_DE_VICTOIRE |
| Bulbizarre | 45 | 49 | […] | 45 | 0.2781954887218045 |
| Herbizarre | 60 | 62 | […] | 60 | 0.38016528925619836 |
| Florizarre | 80 | 82 | […] | 80 | 0.6742424242424242 |
| Mega-Florizarre | 80 | 100 | […] | 80 | 0.56 |
| Salameche | 39 | 52 | […] | 65 | 0.49107142857142855 |
| Reptincel | 58 | 64 | […] | 80 | 0.5423728813559322 |
| Dracaufeu | 78 | 84 | […] | 100 | 0.8646616541353384 |
| Mega-Dracaufeu X | 78 | 130 | […] | 100 | 0.8561151079136691 |

Les 20 % restant des variables explicatives et des variables expliquées constitueront le jeu de tests permettant de valider l'apprentissage :

| X_VALIDATION (20 %) | | | | | Y_VALIDATION (20 %) |
|---------------------|---|---|---|---|---------------------|
| NOM | POINTS_DE_VIE | NIVEAU_ATTAQUE | […] | VITESSE | POURCENTAGE_DE_VICTOIRE |
| Mega-Dracaufeu Y | 78 | 104 | […] | 100 | 0.8444444444444444 |
| Carapuce | 44 | 48 | […] | 43 | 0.1623931623931624 |

Enfin, voici le code associé utilisant la fonction `train_test_split` du module Scikit-Learn, permettant de créer les jeux de données d'apprentissage et de tests :

```python
#X = on prend toutes les données, mais uniquement les features 4 à 11
# POINTS_ATTAQUE;POINTS_DEFFENCE;POINTS_ATTAQUE_SPECIALE;POINT_DEFENSE_SPECIALE;POINTS_VITESSE;NOMBRE_GENERATIONS
X = dataset.iloc[:, 5:12].values

#y = on prend uniquement la colonne POURCENTAGE_DE_VICTOIRE (16ème feature) 
#les : signifiant "Pour toutes les observations"
y = dataset.iloc[:, 16].values

#Construction du jeu d'entrainement et du jeu de tests
from sklearn.model_selection import train_test_split
X_APPRENTISSAGE, X_VALIDATION, Y_APPRENTISSAGE, Y_VALIDATION = train_test_split(X, y, test_size = 0.2, random_state = 0)
```

Notons l'usage de la fonction `iloc` qui permet de sélectionner les features par leur numéro d'index et la valeur 0.2 utilisée dans la fonction `train_test_split` indiquant que nous consacrons 20 % des observations au jeu de tests.

### Algorithme de régression linéaire

Comme nous l'avons vu dans le chapitre Des statistiques pour comprendre les données (encore lui), l'algorithme de régression linéaire modélise les relations entre une variable prédictive et une variable cible.

Dans notre cas, les variables prédictives sont :
• les points de vie
• le niveau d'attaque
• le niveau de défense
• le niveau d'attaque spéciale
• le niveau de défense spécial
• la vitesse et la génération du Pokémon

Et la variable cible (la prédiction) est :
• le pourcentage de victoire

Dans notre cas, nous avons plusieurs variables prédictives pour une prédiction. Nous sommes donc dans le cas d'une régression linéaire multiple. Voici comment utiliser l'algorithme de régression linéaire pour réaliser notre apprentissage à l'aide du module Scikit-Learn :

```python
#---- ALGORITHME 1: REGRESSION LINEAIRE -----
from sklearn.metrics import r2_score
from sklearn.linear_model import LinearRegression

#Choix de l'algorithme
algorithme = LinearRegression()

#Apprentissage à l'aide de la fonction fit
#Apprentisage effectué sur le jeu de données d'apprentissage
algorithme.fit(X_APPRENTISSAGE, Y_APPRENTISSAGE)

#Realisation de prédictions sur le jeu de tests (validation)
predictions = algorithme.predict(X_VALIDATION)

#Calcul de la précision de l'apprentissage à l'aide de la
#fonction r2_score en comparant les valeurs prédites
#(predictions) et les valeurs attendues (Y_VALIDATION)
precision = r2_score(Y_VALIDATION, predictions)

print(">> ----------- REGRESSION LINEAIRE -----------")
print(">> Precision = "+str(precision))
print("------------------------------------------")
```

Le calcul de la précision d'apprentissage (accuracy) se réalise sur les prédictions réalisées à partir des données de tests. En effet, nous souhaitons valider le niveau d'efficacité de l'algorithme. Pour cela, il faut le mesurer sur des données qu'il ne connaît pas. Notons qu'il est parfois également intéressant de calculer la précision sur les données d'apprentissage et de la comparer avec celle obtenue sur les données de tests afin de déterminer si nous sommes en présence d'un surapprentissage ou non. Mais nous aurons l'occasion de revenir sur ce point.

Pour mesurer cette précision (aussi appelé score), nous utilisons la méthode `r2_score` comme le préconise la documentation du module SciKit-Learn dans le cas de problèmes de régression (https://scikit-learn.org/stable/modules/model_evaluation.html).

![alt text](image-5.png)
Documentation du module Scikit-Learn concernant les fonctions à
utiliser pour mesurer la précision d’un algorithme.

Nous laisserons pour le moment de côté les autres indicateurs de mesure, notamment la MSE (Mean Square Error) dont l'utilité sera expliquée dans le chapitre Un neurone pour prédire.

La compréhension du code permettant l'apprentissage et l'évaluation de l'algorithme est assez simple. Les commentaires présents dans le code vous ont sans doute permis de comprendre qu'il s'agissait en premier lieu de choisir un algorithme en concordance avec notre problème à résoudre (dans notre cas un problème de régression), puis de réaliser l'apprentissage à l'aide de la méthode `fit` tout en veillant à passer en paramètres de cette fonction les données d'apprentissage (X_APPRENTISSAGE et Y_APPRENTISSAGE).

Des prédictions sont ensuite réalisées sur les données de tests (X_TEST) et sont comparées à celles attendues (Y_TEST) à l'aide la méthode `r2_Score` chargée de calculer la précision de l'algorithme.

Ce qui nous permet d'en déduire qu'à l'aide de la régression linéaire multivariée, nous obtenons un score de 90 %, ce qui est plutôt bon.

```
>> ----------- REGRESSION LINEAIRE -----------
>> Precision = 0.9043488485570964
```

### L'arbre de décision appliqué à la régression

Passons à présent à l'utilisation des arbres de décisions en faisant attention à bien utiliser l'algorithme destiné aux problèmes de régression : `DecisionTreeRegressor` et non celui destiné aux problèmes de classification : `DecisionTreeClassifier`.

```python
#Choix de l'algorithme
from sklearn.tree import DecisionTreeRegressor
algorithme = DecisionTreeRegressor()
algorithme.fit(X_APPRENTISSAGE, Y_APPRENTISSAGE)
predictions = algorithme.predict(X_VALIDATION)
precision = r2_score(Y_VALIDATION, predictions)

print(">> ----------- ARBRES DE DECISIONS -----------")
print(">> Precision = "+str(precision))
print("------------------------------------------")
```

On constate qu'en utilisant l'arbre de décisions le résultat est moins bon…

```
>> ----------- ARBRE DE DECISIONS -----------
>> Precision = 0.8812980947158535
```

### La random forest

Testons à présent l'algorithme des forêts aléatoires (toujours appliqué à la régression) :

```python
#Choix de l'algorithme
from sklearn.ensemble import RandomForestRegressor
algorithme = RandomForestRegressor()
algorithme.fit(X_APPRENTISSAGE, Y_APPRENTISSAGE)
predictions = algorithme.predict(X_VALIDATION)
precision = r2_score(Y_VALIDATION, predictions)

print(">> ----------- FORETS ALEATOIRES -----------")
print(">> Precision = "+str(precision))
print("------------------------------------------")
```

Et nous obtenons cette fois-ci une précision de 93 % !

```
>> ----------- FORETS ALEATOIRES -----------
>> Precision = 0.9328013851258918
```

Nous avons donc trouvé notre challenger. Cependant, nous tenons à préciser que les algorithmes sont ici utilisés dans leur forme la plus simple, c'est-à-dire sans optimisation de leurs paramètres. Il se peut qu'en les torturant un peu nous obtenions d'autres résultats, peut-être encore plus prometteurs, avec l'un des trois algorithmes.

### Sauvegarde du modèle d'apprentissage

Afin de pouvoir utiliser le modèle de prédiction fraîchement entraîné dans une application sans devoir réitérer la phase d'apprentissage, nous devons le sauvegarder.

Pour ce faire, après avoir créé un nouveau répertoire **modele** dans notre projet, nous allons utiliser le sous-module `joblib` du module Scikit-learn pour sauvegarder notre modèle d'apprentissage.

```python
import joblib
fichier = 'modele/modele_pokemon.mod'
joblib.dump(algorithme, fichier)
```

Le fichier porte l'extension .mod pour modèle. Mais libre à vous d'utiliser l'extension que vous souhaitez.

---

## Phénomènes de surapprentissage (overfitting) et de sous-apprentissage (underfitting)

Lorsque l'on cherche une solution à un problème en Machine Learning, nous souhaitons que celle-ci soit généralisable. C'est-à-dire que la solution trouvée doit être applicable sur des données inconnues de celles utilisées lors de l'apprentissage.

Pour cela, il faut que les données utilisées lors de la phase d'apprentissage soient les plus proches possible de la réalité et du problème à résoudre.

Le **surapprentissage (overfitting)** est un phénomène se traduisant par le fait que la solution est trop adaptée aux données d'apprentissage et ne se généralise pas à de nouvelles données qui lui sont inconnues. Ainsi, si pour un algorithme nous obtenons une précision 99 % sur les données d'apprentissage et que nous obtenons une valeur de 20 % sur les données de tests, il y fort à parier que nous sommes en présence d'un surapprentissage. C'est pourquoi il est conseillé de mesurer la précision à la fois sur les données d'apprentissage et sur les données de validation :

```python
predictions = algorithme.predict(X_VALIDATION)
precision_apprentissage = algorithme.score(X_APPRENTISSAGE,Y_APPRENTISSAGE)
precision = r2_score(Y_VALIDATION, predictions)
```

Quant au phénomène de **sous-apprentissage**, ce dernier se produit lorsque l'algorithme n'arrive pas à trouver une corrélation entre les données d'apprentissage et n'arrive donc pas à réaliser de bonnes prédictions.

La notion d'overfitting est souvent rencontrée lors de l'utilisation des réseaux de neurones. En effet, lors de l'apprentissage nous allons chercher à minimiser les erreurs de prédictions en réalisant un certain nombre de boucles d'apprentissage (itérations) où, à chaque boucle, l'algorithme va apprendre de ses erreurs et se corriger.

Plus nous réalisons d'itérations, plus l'algorithme apprend et moins il se trompe. Si trop d'itérations sont réalisées, l'algorithme aura une très bonne précision sur les données d'apprentissage, mais il se sera spécialisé sur celles-ci et aura une mauvaise précision sur les données de tests. La généralisation n'est donc plus possible.

---

## Utiliser le modèle d'apprentissage dans une application

Nous disposons d'un modèle d'apprentissage capable de nous prédire le pourcentage de victoire de chaque Pokémon. Nous allons à présent créer une application utilisant ce modèle d'apprentissage et ayant pour objectif de prédire le vainqueur d'un combat opposant deux Pokémons choisis dans le Pokédex.

La première étape consiste à créer un nouveau fichier Python dans notre projet que l'on nommera `partie3_predictions.ipynb`.

Dans ce fichier, nous allons tout d'abord importer les modules dont nous avons besoin.

```python
#Module de lecture de fichiers CSV
import csv
#Module de chargement du modèle d'apprentissage
import joblib
```

Nous allons ensuite écrire une première fonction qui sera chargée de chercher les informations d'un Pokémon dans le Pokédex à partir de son numéro et utiles à notre modèle de prédiction.

```python
def rechercheInformationsPokemon(numPokemon,Pokedex):
    infosPokemon = []
    for pokemon in Pokedex:
        if (int(pokemon[0])==numPokemon):
            infosPokemon = [pokemon[0],pokemon[1],pokemon[4],pokemon[5],pokemon[6],pokemon[7],pokemon[8],pokemon[9],pokemon[10]]
            break
    return infosPokemon
```

On crée tout d'abord une liste (`infosPokemon`) permettant de stocker toutes les informations du Pokémon nécessaires à la prédiction de sa victoire ou de sa défaite. On parcourt ensuite le Pokédex à la recherche du Pokémon ayant le même numéro que celui que nous cherchons. Il est important de noter que le numéro du Pokémon correspondant à la première colonne du Pokédex est transformé en entier (`int(pokemon[0])`) afin de pouvoir le comparer avec le numéro du Pokémon recherché, passé en paramètre de la fonction.

Si lors de la boucle de parcours du Pokédex, le numéro lu correspond au numéro du Pokémon recherché, on extrait alors les informations nécessaires pour pouvoir ensuite les renvoyer à la fonction appelante de notre fonction de recherche.

Le tableau ci-dessous reprend l'information nécessaire à la prédiction de victoire ou de défaite et sa position dans le Pokédex (le numéro se trouve dans la première colonne (pokemon[0]), le nom dans la deuxième (pokemon[1])…).

| INFORMATION | INDICE DE COLONNE DANS LE POKEDEX |
|-------------|-----------------------------------|
| Numéro | 0 |
| Nom | 1 |
| Points de vie | 4 |
| Niveau d'attaque | 5 |
| Niveau de défense | 6 |
| Niveau d'attaque spécial | 7 |
| Niveau de défense spécial | 8 |
| Vitesse | 9 |
| Génération | 10 |

Vient ensuite la fonction principale de notre application, permettant de prédire qui des deux Pokémons combattants sera le vainqueur.

```python
def prediction (numeroPokemon1, numeroPokemon2,Pokedex):
    pokemon1 = rechercheInformationsPokemon(numeroPokemon1, Pokedex)
    pokemon2 = rechercheInformationsPokemon(numeroPokemon2, Pokedex)
    
    modele_prediction = joblib.load('modele/modele_pokemon.mod')
    
    prediction_Pokemon_1 = modele_prediction.predict([[pokemon1[2],pokemon1[3],pokemon1[4],pokemon1[5],pokemon1[6],pokemon1[7],pokemon1[8]]])
    
    prediction_Pokemon_2 = modele_prediction.predict([[pokemon2[2], pokemon2[3], pokemon2[4], pokemon2[5], pokemon2[6], pokemon2[7], pokemon2[8]]])
    
    print ("COMBAT OPPOSANT : ("+str(numeroPokemon1)+") "+pokemon1[1]+" à ("+str(numeroPokemon2)+") "+pokemon2[1])
    print (" "+pokemon1[1]+": "+str(prediction_Pokemon_1[0]))
    print(" " +pokemon2[1] + ": " + str(prediction_Pokemon_2[0]))
    print ("")
    
    if prediction_Pokemon_1>prediction_Pokemon_2:
        print(pokemon1[1].upper()+" EST LE VAINQUEUR !")
    else:
        print(pokemon2[1].upper() + " EST LE VAINQUEUR !")
```

Cette fonction prend en paramètres :
• le numéro du premier Pokémon
• le numéro du second Pokémon
• le Pokédex

La première action de notre fonction est de rechercher les informations sur les deux Pokémons.

Viennent ensuite le chargement du modèle et la prédiction pour chaque Pokémon :

```python
modele_prediction = joblib.load('modele/modele_pokemon.mod')
```

On compare ensuite le pourcentage de victoire prédit pour en déduire le vainqueur du combat.

Vient enfin le moment de saisir les dernières lignes de code, en chargeant le fichier Pokédex, en excluant sa première ligne contenant les noms des différentes colonnes (`next(pokedex)`) et en appelant la fonction de prédiction.

```python
#Chargement du Pokédex et lancement d'un combat
with open("datas/pokedex.csv", newline='') as csvfile:
    pokedex = csv.reader(csvfile)
    next(pokedex)
    prediction(368,598,pokedex)
```

Voici le résultat de ce script :

```
COMBAT OPPOSANT : (368) Mangriff à (598) Crapustule
Mangriff: 0.7008019808073136
Crapustule: 0.5924562022360302

MANGRIFF EST LE VAINQUEUR !
```

Il vous est à présent possible de prédire le vainqueur de chaque combat de Pokémons ! N'hésitez pas à utiliser le contenu du fichier combat.csv comme source d'inspiration et surtout de vérification de la bonne prédiction.

---

## Fin du cas d'étude

Nous voici à présent au terme du cas d'étude dédié au Pokémon. Celui-ci nous a permis dans sa première partie de découvrir les étapes de préparation de données pour la résolution d'un problème lié au Machine Learning supervisé.

Dans la seconde partie, nous nous sommes attardés sur l'analyse plus fine des données afin de pouvoir déterminer celles ayant une incidence forte (corrélation) sur la résolution de notre problème. Une fois cette étape réalisée, nous avons émis des hypothèses sur la prédiction de la victoire d'un Pokémon par rapport à son adversaire et vérifié celles-ci.

Nous avons ensuite testé divers algorithmes de prédiction, liés à la régression (car nous cherchions à prédire une valeur) afin de déterminer celui qui nous permettra d'obtenir un modèle de prédiction fiable. Modèle que nous avons ensuite utilisé dans une application.

Ce qu'il faut retenir de cette expérience est que la préparation et l'analyse des données est une phase, si ce n'est **la phase la plus importante** d'un projet de Machine Learning. Des données bien préparées et de bonne qualité permettront de réaliser de bonnes prédictions.

Gardez également en tête les notions de **surapprentissage** et de **sous-apprentissage** qui vous seront utiles dans vos recherches d'algorithmes pouvant répondre à vos problèmes de Machine Learning. Un bon algorithme est un algorithme qui produit des résultats généralisables.
