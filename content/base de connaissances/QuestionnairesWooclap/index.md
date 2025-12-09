+++
title = "Questionnaires Wooclap"
weight = 100

[params]
  menuPre = '<i class="fa-solid fa-dumbbell"></i> '
+++

## Questionnaire Docker
### 1 
**Différence entre un container et une image**
- image : description de l'application
- container : exécution de l'application

### 2
**Quelle est la différence entre une VM et un conteneur ?**
- [cours](../../cours/docker/_index.md#différence-conteneur---vm)

### 3
**Où sont stockés les containers ?**
- localement : les containers sont le résultat d'une exécution, et l'exécution se fait localement
- docker hub : contient des images
- sur le cloud : au mieux peu contenir des images

### 4
**Comment lister tous les containers (en cours d'exécution et arrêté) ?**
- `docker ps -a`

### 5
**Peut on connecter un conteneur à un réseau ?**
- oui

### 6
**Que se passe-t-il lorsqu'on exécute la commande : $ docker run hello-world**
- [cours](../../cours/docker/_index.md#hello-world)