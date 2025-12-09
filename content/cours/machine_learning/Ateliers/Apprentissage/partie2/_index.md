+++
title = "Partie 2"
weight = 120
+++


## Ce que nous allons découvrir et les prérequis

Dans le chapitre précédent, nous avons constitué un jeu d'observations qui va nous permettre d'entamer la démarche d'analyse et de recherche de solution à notre problème, à savoir déterminer le Pokémon à utiliser lors d'un combat dans le but de le gagner.

Nous allons commencer ce chapitre par un peu de statistiques, mais n'ayez crainte, cela reste simple de compréhension.

> [!info]
> Continuez à travailler dans le même fichier `ipynb` que la première partie.

---

## Un peu de statistiques

Avant d'entrer dans le vif du sujet, nous allons faire un peu de statistiques sur notre jeu d'observations à l'aide de la fonction `describe()` du module Pandas.

```python
print(nouveauPokedex.describe())
```

Cette fonction a pour but d'expliquer statistiquement chaque feature de notre ensemble d'observations dans le but d'en dégager quelques caractéristiques intéressantes.

À titre d'exemple, prenons le résultat de l'analyse statistique de la feature NIVEAU_ATTAQUE.

| Module | Définition | Valeur |
|---------|------------|---------|
| Count | Nombre d'observations | 800 |
| Mean | La moyenne des observations | 79.001250 |
| Std | L'écart type | 32.457366 |
| min | La valeur minimale des observations | 5 |
| 25% | | 55 |
| 50% | | 75 |
| 75% | | 100 |
| Max | La valeur maximale des observations | 190 |

### Le nombre de données (count)

On constate que 800 observations ont été renseignées pour la feature NIVEAU_ATTAQUE. Cela signifie qu'il ne manque pas de données.

### La moyenne (mean)

Le niveau d'attaque moyen des Pokémons est de 79, c'est-à-dire qu'en dessous de cette moyenne, on peut considérer que le Pokémon a un niveau faible, et au-dessus qu'il a un niveau fort, pouvant alors aider à gagner le combat. Nous disposons donc d'une première information intéressante.

### L'écart type (Std pour Standard Deviation)

L'écart type est une valeur statistique, permettant de montrer la répartition des données autour de la moyenne. Plus sa valeur est petite, plus les données sont proches de la moyenne, dans le cas contraire, elles sont éloignées.

Dans notre cas, l'écart type est de 32, signifiant que les données de la feature NIVEAU_ATTAQUE semblent être assez éloignées de la moyenne. Cela signifie qu'il existe de nombreux cas différents de niveaux d'attaque et que les observations ne sont pas homogènes. C'est un point que nous devrons vérifier lors de la visualisation des données.

### Les valeurs minimales et maximales

Les attributs min et max correspondent à la valeur minimale et à celle maximale des observations de la feature.

Ainsi, on note l'existence d'un ou plusieurs Pokémons ayant un niveau d'attaque à 5 et un ou plusieurs autres ayant un niveau d'attaque à 190.

Là encore, cette information peut nous servir dans notre choix du Pokémon, car plus son niveau maximal d'attaque est fort, plus il a de chances de remporter le combat.

### Les quartiles

Les quartiles sont utilisés en statistiques pour séparer les observations en quatre groupes homogènes.

Pour comprendre la notion de quartiles, prenons l'ensemble des observations de notre feature NIVEAU_ATTAQUE et découpons-les en quatre parties égales :

En observant la figure, on constate que :
• 25 % des Pokémons ont un niveau d'attaque inférieur à 55,
• 50 % des Pokémons ont un niveau d'attaque inférieur à 75,
• 75 % des Pokémons ont un niveau d'attaque inférieur à 100.

Ces informations nous permettent d'affirmer que peu de Pokémons ont un taux d'attaque supérieur à 100 (seulement 25 %). Là encore, cette donnée est importante, car si nous voulons gagner un combat, il faut que nous utilisions un Pokémon présent dans ce dernier quartile.

### Description de notre jeu d'observations

À présent que nous venons d'analyser une caractéristique précise, nous devons réaliser l'analyse complète des observations afin d'avoir une vue globale des données tout en gardant en tête le problème à résoudre.

L'analyse statistique nous permet-elle d'identifier des données singulières ?

Tout d'abord, on constate que les résultats des combats se basent sur les données numériques (VITESSE, NIVEAU_ATTAQUE…), nous pouvons donc exclure les features NOM, TYPE_1,TYPE_2.

Est-il important de s'intéresser au numéro du Pokémon ? Non, car il s'agit d'un identifiant, par conséquent cela n'a pas de lien dans le fait de gagner ou non un combat.

Certains Pokémons n'ont qu'un point de vie ! Ce sont les Pokémons que nous devrons éviter d'utiliser lors d'un combat.

25 % des Pokémons ont une vitesse supérieure à 90 (dernier quartile). Être rapide lors d'un combat peut être un avantage !

On constate un écart type de 11 pour la feature nombre de combats. Cet écart type est le plus bas de l'ensemble des données. Cela signifie que les Pokémons ont tous réalisé un nombre de combats proche de la moyenne, c'est-à-dire proche de 127.

Cette valeur nous permet de dire que les observations contenues dans le jeu de données sont assez qualitatives, car il n'y a pas de Pokémon ayant davantage combattu par rapport aux autres, ce qui ne nous permettrait pas d'avoir un jeu d'apprentissage reflétant la réalité.

En effet, si seuls les Pokémons Bulbizarre et Dracaufeu avaient réalisé des combats, nous n'aurions aucune information sur ceux réalisés par Pikachu et nous aurions peut-être considéré que Bulbizarre ou Dracaufeu sont plus forts que Pikachu, alors que ce n'est peut-être pas le cas.

---

## Quels sont les types de Pokémons qu'un dresseur doit posséder ?

Répondre à notre problématique, c'est se mettre à la place d'un dresseur de Pokémons. Afin de maximiser les chances de gagner, il faut que le dresseur de Pokémons dispose des principaux Pokémons du Pokédex dans sa collection.

En effet, en ayant les Pokémons les plus fréquemment rencontrés, cela signifie que les adversaires ont de grandes chances de posséder les mêmes. Sachant que deux Pokémons de même type peuvent contrer les attaques, cela peut donc éviter de perdre le combat (https://pokemondb.net/type/dual).

Pour connaître ces Pokémons indispensables à tout dresseur, nous allons utiliser un graphique qui nous permettra de visualiser rapidement leur nombre en fonction de leur type. Voici le code à utiliser :

On note l'import du module matplotlib, et l'utilisation du module seaborn, tous deux nécessaires à la représentation graphique des données.

```python
import matplotlib.pyplot as plt
import seaborn as sns

axe_X = sns.countplot(x="TYPE_1", hue="LEGENDAIRE", data=nouveauPokedex)
plt.xticks(rotation= 90)
plt.xlabel('TYPE_1')
plt.ylabel('Total ')
plt.title("POKEMONS DE TYPE_1")
plt.show()
```

![alt text](./image.png)

Idem pour les Pokémons de type 2 :

```python
axe_X = sns.countplot(x="TYPE_2", hue="LEGENDAIRE", data=nouveauPokedex)
plt.xticks(rotation= 90)
plt.xlabel('TYPE_2')
plt.ylabel('Total ')
plt.title("POKEMONS DE TYPE_2")
plt.show()
```
![](image-1.png)

Ce qui nous permet d'affirmer qu'un dresseur doit posséder dans sa collection des Pokémons ayant pour premier type "Herbe", "Eau", "Insecte" et "Normal". Puis "Vol", "Poison" et "Sol" en second type pour pouvoir contrer les attaques, car ce sont ces Pokémons qui ont une barre d'histogramme plus importante que les autres.

Voilà une première information intéressante !

Maintenant, essayons de déterminer les Pokémons ayant un taux de victoire supérieur aux autres.

---

## Les types de Pokémons gagnants et perdants

Il est à notre sens important de connaître les types de Pokémons gagnants. En effet, en s'assurant de les avoir dans sa collection et de les utiliser dans les combats, le dresseur a de fortes chances de gagner.

Pour obtenir cette information, on calcule la moyenne des pourcentages de victoires de chaque Pokémon. Cette moyenne, calculée et groupée par type de Pokémon, est ensuite triée par ordre croissant :

```python
print(nouveauPokedex.groupby('TYPE_1').agg({"POURCENTAGE_DE_VICTOIRES": "mean"}).sort_values(by = "POURCENTAGE_DE_VICTOIRES"))
```

![alt text](image-2.png)

On peut donc en déduire que les Pokémons gagnants sont de type :
• **Obscur**
• **Électrique**
• **Dragon**
• **Vol**

Nous pouvons également affirmer que les types de Pokémons suivants sont souvent voués à perdre leur combat :
• **Fée**
• **Eau**
• **Roche**
• **Acier**
• **Poison**

Peut-on déjà en déduire quelque chose ? Si l'on prend le Pokémon, héros de la série, nommé Pikachu, de type électrique et qu'on le compare à un Pokémon Fée, on peut en déduire que Pikachu a de grandes chances de remporter le combat.

Si vous jouez personnellement aux Pokémons, possédez-vous la majorité des Pokémons du Pokédex ? Avez-vous également des Pokémons de types électrique, obscur, dragon et vol ?

Si ce n'est pas le cas, il faut d'urgence vous en procurer. Ce sont les statistiques qui l'affirment !

---

## Essayons de trouver une corrélation entre les données

Une corrélation entre deux données signifie que celles-ci ont un lien fort entre elles. Exemple le statut d'adulte et l'âge de 18 ans, le fait de savoir voler et d'être pourvu d'ailes…

Dans notre cas, il s'agit de déterminer l'existence de features ayant un lien fort avec la capacité à gagner un combat. Faut-il être rapide ? Faut-il avoir un grand niveau d'attaque ? C'est ce que nous allons découvrir.

Avant toute chose, nous devons nous questionner sur l'utilité de l'ensemble des données en nous posant la question : "Cette feature peut-elle avoir un impact sur le fait de gagner ou non le combat ?"

• **Le numéro** : non, car différent pour chaque Pokémon.
• **Le nom** : non, car différent pour chaque Pokémon.
• **Le type_1** : oui, car nous venons de voir que certains types de Pokémons sont propices à la victoire.
• **Le type_2** : non, car tous les Pokémons n'ont pas de second type.
• **Les points de vie** : oui, car plus on a de points de vie, plus on a de chance de gagner.
• **Les différents niveaux** (attaque, défense, attaque spéciale, défense spéciale) : oui, car ce sont des caractéristiques propres au combat.
• **La vitesse** : oui, car c'est aussi une caractéristique de combat.
• **Légendaire** : oui, car un Pokémon légendaire disposerait d'une force supplémentaire.

Pour permettre de visualiser la corrélation entre les features, nous allons utiliser un graphique appelé HeatMap se construisant comme suit :
• Calcul de la corrélation des différentes features
• Création du graphique à partir de la corrélation calculée

```python
corr = nouveauPokedex.loc[:,['POINTS_DE_VIE','NIVEAU_ATTAQUE',
'NIVEAU_DEFENSE','NIVEAU_ATTAQUE_SPECIALE','NIVEAU_DEFENSE_SPECIALE',
'VITESSE','LEGENDAIRE','POURCENTAGE_DE_VICTOIRES']].corr()

sns.heatmap(corr,
xticklabels=corr.columns,
yticklabels=corr.columns, annot=True)
plt.show()
```

![alt text](image-3.png)

Si vous rencontrez un problème d'exécution du script à cette étape, supprimez la colonne POURCENTAGE_DE_VICTOIRES dans le code que vous venez de saisir, puis après avoir exécuté une première fois le code, vous pouvez à nouveau l'ajouter. Le souci provient du fait que la colonne n'est pas correctement indexée.

À la lecture de ce graphique créé à l'aide du module Seaborn, on constate que la feature Type_1 n'est pas présente. Cela vient du fait que ce n'est pas une valeur numérique et elle se trouve donc exclue !

### Comment lire ce graphique ?

La corrélation se faisant entre deux features, il faut prendre la feature située à gauche du graphique (axe des ordonnées) et la croiser avec celle située en bas (axe des abscisses). Le chiffre se situant à l'intersection des deux features correspond au pourcentage de corrélation. Plus il se rapproche de 1, plus la corrélation est forte.

Si l'on considère la feature qui nous intéresse, à savoir le pourcentage de victoires, le taux de corrélation est égal à 1 lorsqu'elle est comparée à elle-même ce qui est tout à fait normal. S'en suit la feature Vitesse montrant une corrélation de 0,94 ! Puis celle de la feature Niveau d'attaque s'élevant quant à elle à 0.50.

Par conséquent, nous pouvons en déduire que la victoire est quasi acquise lors d'un combat pour le Pokémon le plus rapide des deux et ayant un niveau d'attaque supérieur à son adversaire.

Une petite déception tout de même sur la feature LEGENDAIRE qui s'avérait prometteuse. Car dans la littérature, il est indiqué qu'un Pokémon légendaire possède une force supérieure aux autres, ce qui lui permettrait de gagner facilement les combats. Cependant, on constate que sa valeur de corrélation est seulement de 0.33.

---

## Résumé de nos observations

Si l'on résume les observations que nous avons effectuées, nous pouvons dire que pour remporter la victoire lors d'un combat, le dresseur de Pokémons doit :

• Posséder des Pokémons de type herbe, eau, insecte et normal, ce qui lui permet de contrer les attaques,
• Posséder des Pokémons de type obscur, électrique, dragon et vol, car ce sont eux qui ont un taux supérieur de victoire,
• Utiliser un Pokémon ayant une grande vitesse,
• Utiliser un Pokémon ayant un bon niveau d'attaque.

---

## Vérifions nos hypothèses

Il nous faut à présent vérifier nos hypothèses en sélectionnant quelques combats dans le fichier combats.csv.

```
155,321,155
101,583,583
404,32,32
```

Au vu de ces résultats, nos hypothèses semblent donc vérifiées.

| NUMERO | NOM | TYPE | NIVEAU ATTAQUE | VITESSE | VAINQUEUR |
|---------|-----|------|----------------|---------|-----------|
| 275 | Jungko | Herbe | 85 | 120 | |
| 155 | Méga-Ptéra | Roche | 135 | 150 | OUI |

| NUMERO | NOM | TYPE | NIVEAU ATTAQUE | VITESSE | VAINQUEUR |
|---------|-----|------|----------------|---------|-----------|
| 404 | Rosabyss | Eau | 84 | 52 | |
| 32 | Raichu | Électrique | 90 | 110 | OUI |

| NUMERO | NOM | TYPE | NIVEAU ATTAQUE | VITESSE | VAINQUEUR |
|---------|-----|------|----------------|---------|-----------|
| 155 | Méga-Ptéra | Roche | 135 | 150 | OUI |
| 321 | Makuhita | Combat | 60 | 25 | |

| NUMERO | NOM | TYPE | NIVEAU ATTAQUE | VITESSE | VAINQUEUR |
|---------|-----|------|----------------|---------|-----------|
| 101 | Spectrum | Spectre | 50 | 95 | |
| 583 | Zéblitz | Électrique | 100 | 116 | OUI |

---

Afin d'éviter de rexécuter les différentes tâches d'analyse de données et de préparation de celles-ci avant chaque apprentissage, nous allons sauvegarder le Dataframe dans un fichier nommé dataset.csv avec pour séparateur des tabulations (sep='\t').

```python
#Sauvegarde du Dataframe Pokedex
dataset = nouveauPokedex
dataset.to_csv("datas/dataset.csv", sep='\t')
```