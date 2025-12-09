+++
title = "Les réseaux de neurones"
weight = 30
+++

## Biologie cognitive

Notre cerveau est composé de **86 à 100 milliards de neurones** dont le rôle est d'acheminer et de traiter des messages dans notre organisme.

## Le neurone

### Types de neurones :

- Certains neurones ont un rôle dédié aux **perceptions des sensations et aux mouvements**
- D'autres sont responsables des **fonctions automatiques** de notre corps (digestion, respiration…)

### Structure biologique d'un neurone :

Biologiquement, un neurone est une **cellule**, composée :

- **Noyau** : Le centre de contrôle de la cellule nerveuse
- **Corps cellulaire** : Contient le noyau et les organites cellulaires
- **Dendrites** : Les prolongements ramifiés qui reçoivent les signaux provenant d'autres neurones ou de l'environement.
- **Axone** : Le long prolongement qui transmet l'influx nerveux vers d'autres cellules
- **Gaine de myéline** : L'enveloppe isolante (en jaune) qui entoure l'axone et accélère la transmission de l'influx nerveux
- **Synapses** : Les zones de contact entre deux neurones où se fait la transmission du signal nerveux

![alt text](Pictures/100000000000024E0000013D84F6C950.png)

---


### Communication neuronale

La communication entre neurones s'opère par l'échange de **messages sous forme de variation de tension électrique**. Un neurone peut recevoir plusieurs messages de la part d'autres neurones auxquels il est connecté.

### Processus d'activation

Lorsqu'un neurone reçoit plusieurs messages, il effectue la **somme des influx nerveux reçus** puis, si cette somme dépasse un **certain seuil**, il **s'active** et transmet à son tour un message via son axone aux neurones connectés à celui-ci.

Pour une action donnée, un ensemble de neurones s'active alors que d'autres restent inactifs, car un **chemin s'est créé** entre l'action et l'activation neuronale.
![alt text](Pictures/100000010000024E00000121F906346B.png)

---

## Neurone et perceptron

En **1957**, **Frank Rosenblatt** propose un algorithme d'apprentissage supervisé nommé le **Perceptron**. Aujourd'hui appelé "neurone formel", cet algorithme permettait de classifier des données **linéairement séparables**.

### Correspondance biologique ↔ artificielle

|Neurone biologique|Neurone artificiel|
|---|---|
|**Dendrites**|Entrées (input)|
|**Synapses**|Poids|
|**Axone**|Sortie (output)|
|**Activation**|Fonction d'activation|

![alt text](Pictures/100000000000024E0000014C8F88D543.png)


### Données linéairement séparables

Le **perceptron simple couche** ou **neurone formel** n'est en mesure de classifier que des données **linéairement séparables**.

- Il faudra **plusieurs couches** pour traiter de données plus complexes
- Des données linéairement séparables sont celles pouvant être **séparées par une droite**

**Fonctions logiques ET et OU**

|A|B|A ET B|A OU B|
|---|---|---|---|
|0|0|FAUX|FAUX|
|0|1|FAUX|VRAI|
|1|0|FAUX|VRAI|
|1|1|VRAI|VRAI|

![alt text](Pictures/100000000000024E000000FA7831FADB.png)

**Statut :** ✅ **Linéairement séparables**

---

**Fonction logique XOR (OU exclusif)**

|A|B|A XOR B|
|---|---|---|
|0|0|FAUX|
|0|1|VRAI|
|1|0|VRAI|
|1|1|FAUX|

![alt text](Pictures/10000000000001850000014EED97E830.png)

**Statut :** ❌ **Non-linéairement séparable**

### Fonction d'activation

L'activation d'un neurone est déclenchée en fonction d'un **seuil**.

**Processus en deux étapes :**

1. **Préactivation :** Faire la somme des produits des poids qui arrivent au neurone
2. **Activation :** Une fonction d'activation va déterminer si le neurone s'active ou non

#### Fonction de seuil binaire

Cette fonction retourne une valeur égale à **0 ou 1**. Cette fonction est rarement utilisée aujourd'hui, on ne peut pas s'en servir pour la rétro propagation.

Exemple pratique :

- **Somme pondérée :** 0,8
- **Seuil défini :** 0,5
- **Résultat :** Comme 0,8 > 0,5, la fonction renvoie **1** (le neurone s'active)
- Si la valeur était < 0,5, la fonction d'activation renverrait **0**

![alt text](Pictures/10000000000002150000016B9EC57066.png)

Calcul détaillé :

|Valeur en entrée|Poids lié à l'entrée|Valeur de l'entrée × valeur du poids|
|---|---|---|
|2|0,2|0,4|
|1|0,1|0,1|
|3|0,1|0,3|
||**Total :**|**0,8**|

![alt text](Pictures/100000000000024E0000014C8F88D543.png)

#### Fonction sigmoïde

La prédiction que nous obtenons est rarement égale à 0 ou 1, mais plutôt à des **valeurs numériques comprises entre 0 et 1** (0,50, 0,99…) exprimant un **pourcentage de probabilité**. On peut interpréter sa sortie comme une probabilité, et on peut s'en servir pour faire de la rétro propagation.

La **fonction Sigmoïde** a des **changements de valeurs entre 0 et 1 progressifs**.

![alt text](Pictures/100000000000024E0000017209426B5A.png)

#### La fonction ReLU (Rectified Linear Unit)

L'apprentissage d'un neurone consiste en la **mise à jour des poids sur plusieurs itérations**.

La **fonction ReLU**, sans rentrer dans les détails, **facilite cette mise à jour** en palliant certains problèmes des autres fonctions.

#### La fonction softMax

La **fonction softMax** permet de faire un **classement entre plus de deux classes**.

Exemple :

|Classe|Probabilité|
|---|---|
|Animal|0,01|
|Fruit|**0,95**|
|Véhicule|0,04|


### La rétropropagation de l'erreur

La particularité des réseaux de neurones est qu'ils **apprennent de leurs erreurs**.

- **Phase de propagation** :
L'étape consistant à réaliser la *somme pondérée des entrées* et à utiliser une *fonction d'activation* pour obtenir une valeur de prédiction est appelée la *phase de propagation*. Car nous partons des points d'entrées du neurone artificiel vers son point de sortie pour réaliser ces calculs.

- **Calcul de l'erreur** :
Une fois la prédiction réalisée, nous allons *comparer la prédiction réalisée* par le neurone artificiel avec la *prédiction attendue* en faisant la différence entre la valeur attendue et la valeur prédite. En faisant cela, nous venons de calculer l'*erreur de prédiction*.

- **Rétropropagation** :
Une fois cette erreur obtenue, nous allons à présent *parcourir le neurone en sens inverse* (de la sortie vers les entrées) afin de prendre en compte l'erreur commise lors de la prédiction dans l'apprentissage en *ajustant les valeurs des différents poids*. Cette phase est appelée la *rétropropagation de l'erreur*.


#### Les fonctions de perte (Loss function)

Une **fonction de perte**, ou **Loss function**, est une fonction qui évalue l'**écart entre les prédictions réalisées** par le réseau de neurones et les **valeurs réelles** des observations utilisées pendant l'apprentissage.

Principe d'optimisation :

- Plus le résultat de cette fonction est **minimisé**, plus le réseau de neurones est **performant**
- Sa minimisation se fait en **ajustant les différents poids** du réseau de neurones
- L'objectif est de **réduire au minimum l'écart** entre la valeur prédite et la valeur réelle pour une observation donnée

Exemple de fonction de perte :
1. **Mean Squared Error (MSE) - Erreur Quadratique Moyenne**:

    Formule : L = (1/n) × Σ(yᵢ - ŷᵢ)²
2. **Mean Absolute Error (MAE) - Erreur Absolue Moyenne** :

    Formule : L = (1/n) × Σ|yᵢ - ŷᵢ|

#### Le biais

Le biais (ou bias en anglais, noté souvent b) est un paramètre supplémentaire ajouté à la somme pondérée d'un perceptron. C'est une constante qui s'ajoute indépendamment des entrées.

Il aide à obtenir un meilleur ajustement des données et à apprendre des motifs complexes. Le biais permet au perceptron d'effectuer des ajustements sur sa sortie indépendamment des entrées. Le biais est comme l'ordonnée à l'origine ajoutée dans une équation linéaire, ce qui aide le modèle de telle manière qu'il peut s'ajuster au mieux aux données données. Il permet au réseau d'apprendre et de représenter des relations plus complexes entre les variables d'entrée et de sortie.

Sans biais, un perceptron serait comme un thermostat qu'on ne pourrait pas régler : il s'allumerait toujours à 0°C

![alt text](Pictures/100000010000024E000001BC3EDAF424.png)

### Exemple pratique : Prédire l'admission

L'admission dans une université dépend de la **réussite ou non de certains examens d'entrée**. Le tableau ci-dessous regroupe différents cas d'admissions et de refus en fonction de la réussite ou non aux examens en mathématiques et informatique.

Le neurone tentera de **prédire si oui ou non un étudiant est accepté** selon ses résultats d'examen.

**L'exemple est simple :** c'est au bout du compte la **fonction ET**

Données d'entraînement :

|Réussite à l'examen de mathématiques|Réussite à l'examen d'informatique|Admis|
|---|---|---|
|OUI|NON|NON|
|OUI|OUI|OUI|
|NON|OUI|NON|
|NON|NON|NON|

---

#### Initialisation du perceptron

Nous allons initialiser les entrées de notre perceptron avec :

- **Deux features** correspondant chacun à la réussite aux examens
- **Un biais :** pour contrôler la prédisposition du neurone à s'activer ou non et qui prendra toujours la **valeur 1**

#### Notation des poids :

**W** ayant pour signification **Weight (Poids)** suivi du numéro de la feature et du numéro de la couche
- **W11** : poids de la premiere feature de la première couche
- **W21** : poids de la deuxième feature de la première couche
- **Wb** : poids (Weight) du biais (bias en anglais)

![alt text](Pictures/100000000000024E000001E33F5E0E12.png)

---

#### Initialisation des poids

La première étape consiste à **initialiser les poids**. Cette initialisation se fait de façon **aléatoire dans un intervalle compris entre -1 et 1** sauf pour le biais qui prendra la **valeur 0**.

![alt text](Pictures/100000000000024E000001D497FC4B56.png)

On constate dans notre cas que le **poids W21 est plus important** que les autres, cela signifie donc que la valeur contenue dans le neurone X2 a plus d'importance que les autres dans la prédiction.

**Attention :** Ce qui est peut-être faux, car cette valeur est uniquement **choisie au hasard**. Cela ne signifie pas non plus que c'est cette valeur qui sera à la fin de l'apprentissage considérée comme importante, car comme nous l'avons vu, le neurone va **apprendre de ses erreurs** et ce poids va s'ajuster au fur et à mesure de l'apprentissage.

#### Chargement des données :

On "fait passer" la **première observation** dans le neurone.

- X1 = 1
- X2 = 0

Calcul des sommes pondérées (préactivation) :

![alt text](Pictures/100000000000035B000000BB7065A364.png)

![alt text](Pictures/100000000000024E000001ACC621C5D8.png)

#### Utilisation d'une fonction d'activation

La fonction d'activation que nous allons utiliser est la **sigmoïde**.

La fonction est appliquée à la **somme de la préactivation**.

![alt text](Pictures/100000000000024E0000019B4E03C0DE.png)


#### Calcul de l'erreur commise lors de l'apprentissage

- **Prédiction réalisée :** 0.45860596
- **Valeur attendue :** 0
- **Calcul de l'erreur :** Différence entre la valeur attendue et la prédiction réalisée

```
Erreur = 0 - 0.45860596
Erreur = -0.45860596
```

#### Ajustement des poids

Le perceptron va **apprendre de ses erreurs** en ajustant les différents poids de chaque entrée jusqu'à atteindre une **convergence**.

**Calcul du gradient :**

La rétropropagation s'effectue en calculant le **gradient** :

```
Gradient = -1 × Erreur × Prediction × (1-Prediction) × Valeur_entree
```

Avec nos valeurs :

- **Erreur** = -0.45860596
- **Prédiction** = 0.45860596
- **Valeur d'entrée X1** = 1

```
Gradient = -1 × (-0.45860596) × 0.45860596 × (1-0.45860596) × 1
Gradient = 0,11386568
```

**Utilisation du taux d'apprentissage** :

Une fois le gradient déterminé, nous utilisons le **taux d'apprentissage** qui va nous permettre de progresser.

Règle de mise à jour : w_nouveau = w_ancien - α × gradient

α petit → petits pas, apprentissage lent mais stable
α grand → grands pas, apprentissage rapide mais risque d'instabilité

0.1 est un bon compromis utilisé habituellement. Pour un réglage plus fin, il existe des algorithme permettant de faire varier ce paramètre au fur a mesure de l'apprentissage (par exemple le learning range test)

```
Valeur_ajustement_W11 = 0.11386568 × 0,1 = 0,01138657
Nouveau_W11 = W11 - Valeur_ajustement_W11
Nouveau_W11 = -0.165955990594852 - 0,01138657 = -0.15456942
```

**Ajustement de tous les poids** :

Nous devons procéder de la même façon pour ajuster le **poids W21** et le **poids du biais**.

|Paramètre|X1|X2|BIAIS|
|---|---|---|---|
|**VALEUR**|1|0|1|
|**POIDS**|-0,16595599|0,44064899|0|
|**ERREUR**|-0,45860596|-0,45860596|-0,45860596|
|**PREDICTION**|0,45860596|0,45860596|0,45860596|
|**GRADIENT**|-0,11386568|0|-0,11386568|
|**TAUX APPRENTISSAGE**|0,1|0,1|0,1|
|**VALEUR_AJUSTEMENT**|-0,01138657|0|-0,01138657|
|**NOUVEAU POIDS**|-0,15456942|0,44064899|0,01138657|

#### Itérations

Ceci constituait une **première itération** du processus d'apprentissage.

Une itération s'appel une epoch.

- Il faut **recommencer tant et aussi longtemps** que l'erreur n'a pas été minimisée
- Si la sortie prévue est 0, on doit obtenir un nombre **le plus près possible de 0**

> [!info] Code python d'un perceptron
> Cette exemple est codé dans [Codage_du_perceptron.py](Codage_du_perceptron.py).
>
> Vous pouvez utilisez ce fichier [devcontainer.json](devcontainer.json) pour vscode. Dans le repertoire de votre projet python créez un repertoire `.devcontainer` et copiez le fichier `devcontainer.json` à l'intérieur.

---

## Bibliographie

**Vannieuwenhuyze, Aurélien.** _Intelligence artificielle vulgarisée_, ENI, 2019. 434 p.