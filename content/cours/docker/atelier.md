+++
title = "Atelier Docker"
weight = 10
+++

## Objectif

**Déploiement d'une Application Web**

Créer, configurer et déployer une application web simple avec Docker en utilisant les commandes de base.

## Scénario

Vous devez containeriser une application web Node.js qui est un compteur de visites et la déployer avec une base de données Redis.

## Étape 1 : Préparation des fichiers

Créer un répertoire pour cet atelier qui va contenir tous les fichiers suivants :

### 1.1 Créer le fichier `app.js`

```javascript
// Importation des modules nécessaires
const express = require('express');
const redis = require('redis');

// Création de l'application Express
const app = express();

// Configuration du client Redis
const client = redis.createClient({
    host: 'redis-server',  // Nom du conteneur Redis (résolution DNS Docker)
    port: 6379            // Port par défaut de Redis
});

// Route principale qui gère les visites
app.get('/', (req, res) => {
    // Récupération du compteur de visites depuis Redis
    client.get('visits', (err, visits) => {
        if (visits) {
            // Si le compteur existe, l'incrémenter
            client.set('visits', parseInt(visits) + 1);
            res.send(`Nombre de visites: ${visits}`);
        } else {
            // Première visite : initialiser le compteur à 1
            client.set('visits', 1);
            res.send('Première visite!');
        }
    });
});

// Démarrage du serveur sur le port 3000
app.listen(3000, () => {
    console.log('App listening on port 3000');
});
```

**Points clés d'app.js :**

- **Persistance des données** : Utilise Redis pour stocker le compteur de visites
- **Communication inter-conteneurs** : `host: 'redis-server'` fait référence au nom du conteneur Redis
- **Gestion d'état simple** : Incrémente un compteur à chaque visite de la page
- **Architecture microservices** : Séparation claire entre l'app web et la base de données

### 1.2 Créer le fichier `package.json`

```json
{
    "name": "docker-app",
    "version": "1.0.0",
    "main": "app.js",
    "dependencies": {
        "express": "^4.18.0",
        "redis": "^3.1.2"
    },
    "scripts": {
        "start": "node app.js"
    }
}
```

**Points clés du package.json :**

- **Gestion des dépendances** : Définit exactement quelles librairies installer
- **Versions avec ^** : `^4.18.0` accepte les mises à jour mineures (4.18.x, 4.19.x) mais pas majeures (5.x.x)
- **Script start** : Utilisé par `npm start` dans le Dockerfile - permet de changer facilement la commande de démarrage
- **Reproductibilité** : Assure que tous les environnements (dev, prod, Docker) utilisent les mêmes versions
- **Point d'entrée** : `main` indique le fichier principal de l'application
### 1.3 Créer le `Dockerfile`

```dockerfile
# Image de base : Node.js version 16 sur Alpine Linux (très légère)
FROM node:16-alpine

# Définit le répertoire de travail dans le conteneur
WORKDIR /app

# Copie seulement package.json d'abord (optimisation du cache Docker)
COPY package.json .

# Installation des dépendances npm
# Cette étape est mise en cache si package.json n'a pas changé
RUN npm install

# Copie le reste du code source
# Cette étape ne sera refaite que si le code change
COPY . .

# Indique que l'application écoute sur le port 3000
# (documentation, n'ouvre pas réellement le port)
EXPOSE 3000

# Commande par défaut à exécuter au démarrage du conteneur
CMD ["npm", "start"]
```

**Points clés du Dockerfile :**

- **Image Alpine** : Plus légère que la version standard Ubuntu (environ 5MB vs 100MB+)
- **Optimisation du cache** : `package.json` copié avant le code pour éviter de réinstaller les dépendances à chaque changement de code
- **Principe de responsabilité unique** : Une seule application par conteneur
- **WORKDIR** : Évite de polluer la racine du système de fichiers
- **EXPOSE** : Documentation des ports utilisés (n'ouvre pas le port automatiquement)
- **CMD vs RUN** : RUN s'exécute pendant la construction, CMD au démarrage du conteneur

## Étape 2 : Exercices avec les commandes Docker

### Commandes à exécuter (dans l'ordre)

**1. Construire l'image**

```bash
docker build -t mon-app-web .
```

_Cette commande lit le Dockerfile dans le répertoire courant (.) et crée une image nommée "mon-app-web". Le flag `-t` permet de donner un nom (tag) à l'image plutôt qu'un ID cryptique._

**2. Lister les images**

```bash
docker images
```

_Affiche toutes les images Docker présentes sur votre machine. Vous devriez voir votre image "mon-app-web" ainsi que les images de base (node:16-alpine) téléchargées automatiquement._

**3. Démarrer un conteneur Redis**

```bash
docker run --name redis-server -d redis:alpine
```

_Lance un conteneur Redis en arrière-plan. `--name` donne un nom au conteneur, `-d` (detached) le fait tourner en arrière-plan, et `redis:alpine` est l'image à utiliser (version légère d'Alpine Linux)._

**4. Lancer votre application**

```bash
docker run --name app-web --link redis-server -p 3000:3000 -d mon-app-web
```

_Lance votre application. `--link redis-server` connecte les deux conteneurs (ancienne méthode, remplacée par les networks), `-p 3000:3000` redirige le port 3000 de votre machine vers le port 3000 du conteneur._

**5. Vérifier les conteneurs en cours**

```bash
docker ps
```

_Affiche tous les conteneurs en cours d'exécution avec leurs informations : ID, image, commande, statut, ports exposés, noms._

**6. Tester l'application**

```bash
curl http://localhost:3000
```

_Teste votre application depuis l'extérieur du conteneur. Grâce au mapping de port (-p), localhost:3000 redirige vers le conteneur._

**7. Voir les logs de l'application**

```bash
docker logs app-web
```

_Affiche tous les logs produits par votre application (console.log, erreurs, etc.). Très utile pour le débogage._

**8. Entrer dans le conteneur**

```bash
docker exec -it app-web sh
```

_Ouvre un shell interactif à l'intérieur du conteneur. `-i` garde STDIN ouvert, `-t` alloue un pseudo-TTY. Permet d'explorer le système de fichiers du conteneur._

**9. Arrêter les conteneurs**

```bash
docker stop app-web redis-server
```

_Arrête proprement les conteneurs (envoie SIGTERM puis SIGKILL après timeout). Les conteneurs restent sur le système mais ne consomment plus de ressources._

**10. Supprimer les conteneurs**

```bash
docker rm app-web redis-server
```

_Supprime définitivement les conteneurs arrêtés. Libère l'espace disque occupé par les conteneurs (mais pas les images)._

**11. Supprimer l'image créée**

```bash
docker rmi mon-app-web
```

_Supprime l'image de votre machine. Attention : impossible si des conteneurs basés sur cette image existent encore._

## Étape 3 : Version avec Docker Compose

### 3.1 Créer le fichier `docker-compose.yml`

```yaml
# Version du format Docker Compose (3.8 est stable et moderne)
version: '3.8'

# Définition des services (conteneurs) de l'application
services:
  # Service de l'application web
  web:
    build: .                    # Construit l'image depuis le Dockerfile du répertoire courant
    ports:
      - "3000:3000"            # Mapping port hôte:conteneur (accessible depuis l'extérieur)
    depends_on:
      - redis                  # Démarre redis avant web (dépendance de démarrage)
  
  # Service de base de données Redis
  redis:
    image: redis:alpine        # Utilise l'image officielle Redis Alpine (pas de build)
    hostname: redis-server     # Nom d'hôte du conteneur (pour la résolution DNS)
```

**Points clés du docker-compose.yml :**

- **Orchestration multi-conteneurs** : Gère plusieurs services comme une seule application
- **Réseau automatique** : Docker Compose crée un réseau privé pour tous les services
- **Résolution DNS intégrée** : Les services peuvent se contacter par leur nom
- **Dépendances** : `depends_on` assure l'ordre de démarrage (mais pas que Redis soit prêt)
- **Déclaratif** : Décrit l'état souhaité plutôt que les commandes à exécuter

### Commandes Docker Compose à tester

**1. Démarrer tous les services**

```bash
docker-compose up -d
```

_Lance tous les services définis dans le fichier YAML. `-d` (detached) les fait tourner en arrière-plan. Docker Compose :_

- _Crée automatiquement un réseau privé pour les services_
- _Construit l'image 'web' si elle n'existe pas_
- _Télécharge l'image Redis si nécessaire_
- _Démarre les conteneurs dans l'ordre des dépendances_

**2. Voir le statut des services**

```bash
docker-compose ps
```

_Affiche l'état de tous les services du projet Docker Compose. Plus pratique que `docker ps` car ne montre que les conteneurs de ce projet spécifique. Indique si les services sont "Up" ou "Exit"._

**3. Voir les logs**

```bash
docker-compose logs web
```

_Affiche les logs du service 'web' spécifiquement. Alternatives utiles :_

- `docker-compose logs` : _logs de tous les services_
- `docker-compose logs -f web` : _suit les logs en temps réel (follow)_
- `docker-compose logs --tail=50 web` : _affiche seulement les 50 dernières lignes_

**4. Arrêter et supprimer**

```bash
docker-compose down
```

_Arrête tous les services ET supprime les conteneurs, mais conserve les images et volumes. Plus radical que `docker-compose stop` qui ne fait qu'arrêter sans supprimer._

**Commandes supplémentaires utiles :**

**Redémarrer un service spécifique**

```bash
docker-compose restart web
```

_Redémarre seulement le service web sans affecter Redis._

**Reconstruire les images**

```bash
docker-compose up --build
```

_Force la reconstruction des images même si elles existent déjà._

**Scaling (plusieurs instances)**

```bash
docker-compose up --scale web=3 -d
```

_Lance 3 instances du service web (attention aux conflits de ports !)_

