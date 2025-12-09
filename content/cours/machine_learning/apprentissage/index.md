+++
title = "Apprentissage machine"
weight = 20
+++

### Définition

L'apprentissage machine (machine learning) se fonde sur des approches mathématiques et statistiques pour donner aux ordinateurs la capacité d'« apprendre » à partir de données. On cherche à améliorer leurs performances à résoudre des tâches sans être explicitement programmés pour.

**Deux phases :**

1. **Apprentissage ou entraînement** : On fournit un ensemble de données à un algorithme. L'algorithme développe un modèle qui résout une tâche pratique, telle que traduire un discours, estimer une probabilité, reconnaître la présence d'un chat dans une photographie ou participer à la conduite d'un véhicule autonome. Généralement avant l'utilisation pratique du modèle.

2. **Utilisation** : Selon le modèle déterminé, de nouvelles données peuvent alors être soumises afin d'obtenir le résultat correspondant à la tâche souhaitée. En pratique, certains systèmes peuvent poursuivre leur apprentissage une fois en production.

## Apprentissage supervisé ou non supervisé?

Réaliser un apprentissage supervisé consiste à fournir à la machine des données étiquetées (labellisées) et propices à l'apprentissage. C'est-à-dire que nous allons analyser et préparer les données et leur donner une signification. C'est à partir de cette signification que la machine va réaliser son apprentissage. L'objectif étant d'indiquer à la machine que pour une série de données et pour une observation précise, la valeur à prédire est un chat, un chien ou bien une autre valeur.

L'apprentissage non supervisé regroupe des méthodes qui découvrent des structures cachées dans les données sans étiquettes prédéfinies. 

Dans les cas ce que nous attendons d'un modèle :
- **Prédire une valeur : régression**. Par exemple : prédire le pourcentage de réussite d'une équipe de football lors d'un match
- **Classification**. Par exemple : déterminer que la photo affichée est un chat ou un chien est une classification.

## Principaux algorithmes supervisés d'apprentissage machine

L'apprentissage se fait à partie d'algorithmes de statistique ou d'optimisation.

Il ne s'agit pas ici d'en donner une description mathématique rigoureuse, mais bien une intuition de leur fonctionnement pour comprendre comment une machine "apprend".

### La régression linéaire univariée (linear regression)

Cet algorithme cherche à établir, sous forme d'une droite, une relation entre deux variables Par exemple, prédire une note à un examen en fonction du nombre d'heures de révision.

![alt text](Pictures/100000000000024E0000013C447389DC.png)

Ainsi, connaissant le nombre d'heures de révisions, il nous est possible de prédire approximativement la note que l'on obtiendra au prochain examen.

Ici, on pourrait prédire qu'en étudiant 4 heures, on aurait environ 8/20.

### La régression linéaire multiple (Multiple Linear Regression-MLR)

La régression linéaire n'utilise qu'une variable pour en expliquer une autre. Souvent, la réalité est plus complexe.

Par exemple, prédire la note à un examen peut dépendre du niveau de stress, du nombre d'heures de sommeil la veille de l'examen, des obtenus aux TPs, etc.

### Régression polynomiale

Il est parfois difficile de représenter un comportement avec une droite. En utilisant un polynôme (fonction avec des exposants, la courbe prédictive épouse mieux la forme des données)

L'exemple des notes d'examen avec une fonction polynomiale :

![alt text](Pictures/100000000000024E0000013C9DF6A8A7.png)

### Fonction sigmoïde (en S)

Lorsqu'on tente de faire une classification, une droite ou une courbe ne sont pas nécessairement utiles. On cherche plutôt la probabilité qu'un objet appartienne à une catégorie ou à une autre. Par exemple, la probabilité qu'un objet dans une image soit un chat ou un chien.

![alt text](Pictures/100000000000024E00000198E8F5800F.png)

### Arbre de décision

Représente un ensemble de choix sous la forme d'un arbre. Permet d'explorer plusieurs possibilités.

Peut être sous la forme de plusieurs tests exécutés.

![alt text](Pictures/100000000000024E000001276C7FC3B6.png)

#### Arbre de décision dans les jeux

On peut développer une branche pour chaque coup possible dans un jeu.

L'algorithme devient alors d'explorer tous les coups possibles et de déterminer s'il existe un chemin qui est toujours gagnant pour un joueur ou l'autre. Lorsqu'un tel chemin est déterminé, on dit que le jeu est résolu (pour une liste : https://fr.wikipedia.org/wiki/Jeu_r%C3%A9solu)

**Jeu résolu célèbre** : Tic-Tac-Toe. Un joueur peut forcer une partie, peu importe s'il commence ou joue deuxième.

Pour les jeux plus complexes, il est impossible d'explorer tous les coups possibles. Aux échecs par exemple, il prendrait au meilleur ordinateur des centaines de milliers d'années pour explorer tous les coups.

Les algorithmes vont utiliser une heuristique pour éliminer l'exploration de certains coups : par exemple déplacer son roi en deuxième, volontairement sacrifier une pièce, etc.

**Une heuristique** est un ensemble de critères qui guide la découverte.

#### Arbre du Tic-tac-toe

![alt text](Pictures/10000001000001A80000013AF2200417.gif)

Ce diagramme synthétise tous les chemins vers la victoire pour le joueur X, avec comme premier coup, la case en haut à gauche :

![alt text](Pictures/1000000100000400000004006EE0D88E.png)

#### Aux échecs...

![alt text](Pictures/10000000000007D0000005057FA883E0.png)

### Forêts aléatoires (Random Forest)

Consiste à apprendre en parallèle sur plusieurs arbres de décisions construits aléatoirement : 
1. Chaque arbre est construit en utilisant un sous ensemble des attributs. Par exemple, on pourrait imaginer que l'ensemble des attributs sont : 
    1. l'âge (moins de 30 ans, ou plus de 30 ans)
    1. un excès de glycémie (oui/non)
    1. le poids (moins de 90kg, plus de 90kg)
    1. buveur de café (oui/non)
    1. fumeur (oui/non)
    1. activité physique (oui/non)
    
    Sur ces attributs, on n'en sélectionne que q = 2 au hasard, par exemple l'âge et le fait d'être fumeur. 

2. On entraîne les arbres sur des sous-ensembles des données d'entrainement. 

3. Chaque arbre propose alors une prédiction et le résultat final consiste à réaliser la moyenne de toutes les prédictions.

![alt text](Pictures/100000000000024E0000012C16578E9F.png)

### Agrégation de modèle

L'union fait la force ! Comme pour la forêt aléatoire, on peut combiner plusieurs modèles pour prendre une décision.

- **Le bagging**: Consiste à découper les données d'apprentissage en échantillons et d'utiliser pour chaque échantillon un algorithme différent.
- **Le boosting**: Comme le bagging, mais les algorithmes sont notés selon leur prédiction. Plus l'algorithme prédit une bonne valeur, plus il obtient une bonne note.

### Machine à vecteur de support - Support Vector Machine (SVM)

La SVM peut faire à la fois de la régression et de la classification. Détermine une frontière afin de séparer les observations en groupes distincts tout en maximisant la marge de séparation.

![alt text](Pictures/100000000000024E000001BFF292D381.png)

La machine à vecteur de support, consiste à projeter les données dans un espace vectoriel de plus grande dimension à l'aide d'un élément appelé noyau, permettant alors la création de frontière plus simple.

![alt text](Pictures/100000000000024E0000012E5562D42D.png)

### KNN (K-Nearest Neighbours)

Algorithme de classification visant à déterminer pour le groupe d'appartenance d'une observation à partir du groupe d'appartenance de ses K plus proches voisins. K étant le nombre de voisins à considérer.

![alt text](Pictures/100000000000024E0000010092BAF846.png)

### Naive Bayes

Naive Bayes se base sur le Théorème de Bayes fondé sur les probabilités conditionnelles : la probabilité qu'un évènement se produise en fonction d'un évènement qui s'est déjà produit.

Par exemple, dans un jeu de cartes, la probabilité de piger une reine est de 4/52.

Par contre, si on sait d'avance que la carte est un personnage, la question devient : Probabilité que la carte soit une reine SACHANT que c'est un personnage. Puisqu'il n'y a que roi, valet ou reine, la probabilité est de 1/3.

**Algorithme utilisé pour la classification de spam :**
- Au lieu de se demander : Quelle est la probabilité que ce courriel soit du spam ?
- On se demande plutôt : Quelle est la probabilité que ce courriel soit du spam, SACHANT qu'il y a déjà 1000 courriels identifiés comme spam qui ont déjà été reçus de cette adresse ?

## Principaux algorithmes non supervisés

Lors de la phase d'apprentissage, les données ne sont pas étiquetées. Cela veut dire que la machine doit apprendre sans savoir à quel groupe (i.e. Chien ou chat) appartient une donnée).

L'algorithme doit déterminer des groupes d'appartenance (cluster) elle-même.

Pour cela les données doivent être transformées en vecteur pour être positionné dans un espace sur lequel on pourra déterminer ces clusters.

### K-Moyennes (K-Means)

On indique à l'algorithme le nombre de clusters à trouver et celui-ci détermine des centroïdes (un par cluster) autour desquels il est possible de regrouper les données. Ces regroupements s'effectuant en calculant la distance de chaque observation par rapport à un point central de regroupement appelé centroïde et permettant ainsi de classer les observations en plusieurs groupes de façon automatique.

Ici, on a demandé 2 clusters.
![alt text](Pictures/100000000000024E000000EA6D4A37B3.png)

Exemple de déroulement de l'algorithme : [K-Means](https://claude.ai/public/artifacts/033251f5-8feb-4580-814b-5c6298e5d3a4)

Prenons la classification de documents :

**Problème** : Grouper automatiquement 5000 articles de presse par sujet.

**Approche** :
 1. Convertir chaque article en vecteur numérique (TF-IDF ou embeddings)
 2. Appliquer K-means avec K=10 thèmes

Exemple de résultats :
```
Cluster 1 : Articles sur la technologie (IA, smartphones, etc.)
Cluster 2 : Articles sportifs (football, JO, etc.)
Cluster 3 : Articles politiques
Cluster 4 : Articles économiques
...
```
> [!info] TF-IDF
> TF-IDF mesure l'importance d'un mot dans un document par rapport à une collection de documents.
> - TF (Term Frequency) : Fréquence du mot dans le document
> - IDF (Inverse Document Frequency) : Rareté du mot dans tous les documents.
>
> Plus de détails [ici](https://www.geeksforgeeks.org/machine-learning/understanding-tf-idf-term-frequency-inverse-document-frequency/)

### Mean-Shift

Basé sur une notion de "fenêtre coulissante" parcourant le jeu d'observations à la recherche de zones ayant une densité d'observations concentrée autour du centre de la fenêtre. Voici son fonctionnement dans un jeu d'observations.

L'algorithme analyse ensuite les observations contenues dans son rayon d'analyse et déplace la fenêtre vers des régions de densité plus élevée. Ce déplacement se réalise en positionnant le point central de la fenêtre vers la moyenne des points qu'elle contient.

Ce processus est répété jusqu'à ce que le nombre d'observations (la densité) contenues dans la fenêtre d'analyse soit fixe, définissant ainsi un cluster.

La principale différence avec l'algorithme du K-Mean vu précédemment est que nous n'avons pas besoin d'indiquer à la machine combien de clusters elle doit trouver. Ces groupes étant créés de façon automatique par la notion de densité.

![alt text](Pictures/100000000000024E0000017A1376E1ED.png)

### DBSCAN (Density Based Spatial Clustering of Application with Noise)
![alt text](Pictures/100000000000024E00000145145395BF.png)

## Résumé

| Algorithme | Apprentissage supervisé - regression | Apprentissage supervisé - catégorisation | Apprentissage non supervisé |
|------------|-------------------------------------|------------------------------------------|----------------------------|
| Regression linéaire univariée | X | | |
| Régression linéaire multiple | X | | |
| Régression polynomiale | X | | |
| Régression logistique | | X | |
| Arbres de décision | X | X | |
| Forêt aléatoire | X | X | |
| Machine à vecteurs de support | | X | |
| KNN | | X | |
| Naive Bayes | | X | |
| K-moyennes | | | X |
| Mean-shift | | | X |
| DBSCAN | | | X |

>[!info]
> - Ce n'est qu'une petite partie des algorithmes qui existent.
> - Il faut développer une intuition des algorithmes qui sont le plus adaptés à son problème.


## Bibliographie

- Vannieuwenhuyze, Aurélien. Intelligence artificielle vulgarisée, ENI, 2019. 434 p.
- Wikipédia