---
title: "Veille technologique"
weight: 1
---

## Recherche et préparation
La veille technologique consiste à faire de la recherche sur Rust en profondeur afin de sortir les points qui différencient Rust des autres langages de programmation comme C et C++. L’objectif est de présenter un langage de programmation qui sort du lot à des élèves de cinquième session en technique de l’informatique. Il faut donc tenir compte qu’ils ne sont pas à leur premier langage. Ils connaissent déjà Java, JavaScript, HTML, CSS, PHP, C#, Python et C++, et ont une base de connaissance sur ce qu’est la gestion de mémoire et le typage statique.

La question est : en quoi Rust a-t-il plus à offrir dans la gestion de mémoire, le typage statique, la gestion d’erreurs et la performance ?

Voici le déroulement de cette veille technologique :  
La première partie utilise la puissance des outils de recherche modernes (LLM) avec un prompt.  
Ensuite, je vais analyser la réponse du LLM afin d’en tirer :  
- Est-ce que les données semblent complètes ?  
- Est-ce que le moteur de recherche offre déjà les données de la réponse de l’agent conversationnel ?  
- Est-ce que je connaissais Rust avant la réponse de l’agent ?  
- Est-ce que ces données peuvent être trouvées dans un site web ?  
- Je passerai ensuite en revue l’article de JetBrain sur l’efficacité de Rust.  
- Je vais aussi inclure les sources de quelques vidéos sur Rust.  

La veille technologique va être utilisée pour les notes de cours.

### Recherche avec LLM
#### Outils modernes vs. recherche classique
##### Prompts
« Contexte(ne pas mémoriser) : je suis un professeur qui enseigne Rust comme langage de programmation. Je dois faire une veille technologique sur Rust afin de le présenter à mes élèves de 5e session en technique de l'informatique. Rust est connue pour son typage dynamique, sa gestion de mémoire à bas niveau et être très performante. Fait une recherche approfondie sur Rust en utilisant les sources fiables comme le  livre officiel de Rust. »

##### Explication du prompt
Le prompt doit inclure le contexte afin de donner une situation réaliste à l’agent conversationnel. Cela permet d’augmenter la crédibilité des recherches, parce que le LLM va isoler les sources fréquemment utilisées par les professeurs, comme de la documentation et des sites de nouvelles ou de blogues reconnus. Indiquer au LLM que l’audience est un groupe d’élèves de 5e session permet l’utilisation de termes plus adaptés. Donner des pistes et des sources en exemple permet d’isoler sa recherche et d’améliorer son efficacité.
## Réponse de l’agent conversationnel

----

### Veille technologique : Rust en 2025

### Introduction
Le langage Rust est né en 2006 sous l’impulsion de Graydon Hoare. Mozilla Research a parrainé le projet en 2009 et la version 1.0 a été créée en mai 2015. Selon JetBrains, Rust est conçu comme un langage concurrent et sûr pouvant rivaliser avec C++ en termes de performance tout en offrant une meilleure sécurité et une meilleure sûreté des threads blog.jetbrains.com. La devise historique du site rust-lang.org décrivait Rust comme un langage système « blazingly fast », qui prévient les erreurs de segmentation et garantit la sûreté des threads blog.rust-lang.org. Depuis, la page Why Rust? met en avant trois axes : performance, fiabilité et productivité. Rust est « blazingly fast » et efficace en mémoire grâce à l’absence de garbage collector rust-lang.org; sa « rich type system and ownership model guarantee memory-safety and thread-safety »rust-lang.org; enfin il propose une documentation de qualité, un compilateur convivial et des outils intégrés rust-lang.org.

### Typage et système de type
Contrairement à une idée reçue, Rust n’est pas un langage à typage dynamique. Le chapitre sur les types précise que Rust est « un langage à typage statique » et que le compilateur doit connaître le type de toutes les variables à la compilation doc.rust-lang.org. Le compilateur peut inférer les types la plupart du temps, mais lorsque plusieurs types sont possibles il faut ajouter une annotation de type doc.rust-lang.org. Ainsi, Rust combine les avantages du typage statique (détection d’erreurs à la compilation, optimisation) avec une inférence de types pratique.

Rust possède un système de génériques et de traits permettant de définir des comportements partagés indépendamment des types concrets. Le livre explique que les génériques servent de « stand-ins » pour des types concrets et permettent d’exprimer des relations entre ceux-ci doc.rust-lang.org. Les traits définissent des comportements génériques et peuvent être associés à des types génériques pour restreindre les types acceptés doc.rust-lang.org. Cette combinaison permet d’obtenir des abstractions sans surcoût, de factoriser du code et de garantir à la compilation que certains comportements sont implémentés.

### Modèle d’ownership et gestion de mémoire
Rust propose un modèle inédit de gestion de mémoire basé sur l’ownership. Les règles de base stipulent : chaque valeur a un propriétaire unique ; il ne peut y avoir qu’un seul propriétaire à la fois ; et lorsque le propriétaire sort de portée, la valeur est automatiquement détruite doc.rust-lang.org. Ce mécanisme est illustré à travers la variable : elle est valide dans la portée où elle est déclarée et devient invalide dès que cette portée se termine doc.rust-lang.org.

Pour les types sur la pile comme les entiers, la copie se fait naturellement, mais pour les types stockés sur le tas (, vecteurs, etc.), l’assignation transfère la propriété au lieu de copier les données. Lorsque l’on écrit , devient invalide et seule reste propriétaire du buffer ; cette politique évite les double libérations et rend les erreurs de gestion mémoire impossibles doc.rust-lang.orgdoc.rust-lang.org.

La gestion mémoire est donc automatique. Lorsqu’une variable propriétaire sort de portée, le compilateur insère un appel à la fonction spéciale afin de libérer la mémoire doc.rust-lang.org. Ce mécanisme s’inspire du paradigme RAII et ne nécessite ni garbage collector ni appel manuel à total used free shared buff/cache available  
Mem: 10413356 410636 9927564 44 185588 10002720  
Swap: 0 0 0.  

Le concept d’emprunt (borrowing) permet de prêter une référence à des données sans en transférer la propriété. Les références peuvent être immutables (lecture seule) ou mutables. Le compilateur vérifie que l’on ne possède pas deux références mutables ou une référence mutable et des références immuables simultanément, éliminant ainsi les data races.

### Gestion des erreurs
Rust gère deux catégories d’erreurs : les erreurs irrécupérables via la macro et les erreurs récupérables via l’énumération générique . Le livre explique que la plupart des erreurs n’exigent pas l’arrêt du programme et qu’il est souvent préférable de les interpréter et d’y répondre doc.rust-lang.org. L’énumération possède deux variantes, pour la réussite et pour l’erreur doc.rust-lang.org. Comme est générique, correspond au type retourné en cas de succès et au type de l’erreur doc.rust-lang.org. Le type force ainsi le développeur à traiter explicitement les erreurs (à l’aide d’un ou de méthodes comme ) et empêche l’utilisation accidentelle de valeurs invalides.

### Concurrence et multithreading : « fearless concurrency »
L’un des objectifs majeurs de Rust est de faciliter la programmation concurrente sans sacrifier la sûreté. L’introduction du chapitre 16 du livre rappelle que la concurrence et le parallélisme deviennent cruciaux à mesure que les processeurs multiplient leurs cœurs et que la programmation concurrente a traditionnellement été source d’erreurs doc.rust-lang.org. Rust associe les garanties d’ownership et de typage pour faire de nombreuses erreurs de concurrence des erreurs de compilation plutôt que des erreurs d’exécution doc.rust-lang.org. Cette approche, surnommée « fearless concurrency », permet de refactorer ou d’ajouter des threads sans craindre de cacher des bogues subtils doc.rust-lang.org.

Le livre illustre la création d’un nouveau thread via . On passe à une closure contenant le code à exécuter. L’exemple du Listing 16-1 montre un thread principal qui imprime des messages pendant qu’un thread secondaire en imprime d’autres doc.rust-lang.org. Il rappelle que si le thread principal se termine avant le thread secondaire, celui-ci est interrompu et l’ordre d’exécution n’est pas garanti doc.rust-lang.org. Pour attendre qu’un thread se termine, on récupère la valeur de retour de , un ****, puis on appelle dessus : cela bloque le thread appelant jusqu’à la fin du thread engendré doc.rust-lang.org. Le modèle de concurrence de Rust propose également le passage de messages via des canaux () et un partage d’état sécurisé via des primitives comme , le tout contrôlé par les traits et . Grâce à ces outils, la concurrence sûre devient plus simple qu’en C++ ou en C.

### Performance et abstractions zéro coût
Rust est conçu pour offrir la meilleure performance possible sans surcoût indu par des abstractions de haut niveau. La section 13.4 du livre compare les performances d’une fonction de recherche écrite avec une boucle et avec des itérateurs. Un benchmark effectué sur le texte des Aventures de Sherlock Holmes montre que les deux versions ont des temps d’exécution très similaires doc.rust-lang.org. Les itérateurs sont donc considérés comme des abstractions zéro coût : ils offrent une syntaxe concise tout en étant compilés en un code aussi efficace qu’un code de bas niveau doc.rust-lang.org. Cette philosophie (« zero-cost abstractions ») s’applique à d’autres fonctionnalités, comme les traits, les closures et les macros. Le site officiel rappelle aussi que Rust est « blazingly fast and memory-efficient » rust-lang.org et convient autant aux services critiques qu’aux appareils embarqués.

### Autres caractéristiques clés
- **Énumérations et pattern matching** : Les énumérations () permettent de définir des types algébriques. L’expression fournit un contrôle de flux exhaustif et ergonomique.

- **Fonctions anonymes (closures)** et itérateurs pour exprimer des suites d’opérations de manière fonctionnelle et sûre.

- **Macros** ( et macros procédurales) pour générer du code à la compilation, réduire le boilerplate et créer des DSLs internes.

- **Programmation asynchrone avec / et le trait** (stable depuis l’édition 2018). Le chapitre 17 du livre décrit l’utilisation de / pour exécuter des tâches non bloquantes.

- **Interopérabilité C** : Rust expose des liaisons et permet d’écrire des bibliothèques sûres appelables depuis C ou d’appeler du code C tout en profitant de la sûreté des types et du contrôle de la mémoire.

### Nouveautés de l’édition 2024 (Rust 1.85, février 2025)
La version 1.85.0 stabilise l’édition 2024. Les éditions permettent d’introduire des changements qui améliorent le langage tout en préservant la compatibilité du code existant. Le billet d’annonce résume les principales nouveautésblog.rust-lang.org :

- **Nouvelles règles de capture de durée de vie pour** (RPIT lifetime capture). La capture implicite change lorsque la clause n’est pas présente blog.rust-lang.org.

- **Modification de la portée des temporaires** dans les expressions et dans l’expression de queue d’un bloc blog.rust-lang.org. Cela clarifie la durée de vie des valeurs temporaires.

- **Amélioration de l’ergonomie du** en réservant certaines combinaisons de motifs blog.rust-lang.org.

- **Bloc et attributs** : les blocs requièrent désormais explicitement le mot clé et plusieurs attributs (, , ) doivent être marqués comme blog.rust-lang.org. Cette clarification renforce la sécurité des appels externes.

- **Durcissement de l’usage de** (références interdites) blog.rust-lang.org et du type (never type) blog.rust-lang.org.

- **Préfixe réservé** en prévision de futures structures génératrices et réservations de syntaxe pour des littéraux protégés blog.rust-lang.org.

- **Ajout dans la préface** de la bibliothèque standard des traits et blog.rust-lang.org.

- **Diverses améliorations de cargo**, notamment un résolveur de dépendances sensible au champ , une fusion des doctests qui améliore la performance de la documentation et l’introduction des « style editions » pour rustfmt.

Ces changements visent à renforcer la sécurité (contrats explicites), améliorer l’ergonomie du langage et préparer l’arrivée de nouvelles fonctionnalités.

### Adoption et cas d’usage en 2025
Rust connaît une adoption croissante. Le **rapport JetBrains 2024** fait état d’environ 2,27 millions de développeurs utilisant Rust, dont 709 000 comme langue principale blog.jetbrains.com. JetBrains souligne que Rust est particulièrement adapté au développement système, aux objets connectés (IoT), au WebAssembly, à la blockchain, à l’infrastructure cloud, à la programmation réseau et aux interfaces en ligne de commande blog.jetbrains.com.

L’un des exemples de déploiement de Rust les plus médiatisés est celui d’Android. En novembre 2025, Google annonçait que l’adoption de Rust dans le système Android avait réduit la part des vulnérabilités de sécurité liées à la mémoire à moins de 20 % pour la première fois thehackernews.com. Jeff Vander Stoep, ingénieur chez Google, a indiqué que Rust a permis une réduction de la densité de vulnérabilités de plus de 1000 fois par rapport au code C/C++ et a entraîné une baisse de 25 % du temps passé en revue de code thehackernews.com. L’article note également que le code Rust nécessite 20 % de révisions en moins par rapport à son équivalent en C++ thehackernews.com. Google prévoit d’étendre l’usage de Rust au noyau Android, au firmware et à des applications critiques comme Nearby Presence et Chromium thehackernews.com.

D’autres grandes entreprises utilisent Rust pour des composants critiques :

- Meta emploie Rust dans des services réseau et pour des bibliothèques partagées.
- Amazon Web Services (AWS) a développé le moteur de calcul Firecracker en Rust pour faire tourner des micro-VM destinées aux fonctions Lambda.
- Microsoft contribue à l’intégration de Rust dans le noyau Windows et dans le projet Rust for Windows pour créer des API Windows idiomatiques en Rust.

Le succès de Rust se mesure également à son utilisation dans des projets open source tels que Servo (navigateur expérimental), Bevy (moteur de jeu), ripgrep (outil de recherche), tauri (création d’applications de bureau) et Oxide pour l’assemblage de data centers.

### Conclusion
Rust est un langage de programmation moderne qui vise à concilier performance de bas niveau et sécurité de haut niveau. Il adopte un typage statique avec inférence, un modèle d’ownership original pour la gestion de la mémoire et des outils de concurrence sûrs. Les abstractions génériques, les traits, les macros et la programmation asynchrone permettent d’écrire du code expressif sans pénalité de performance. Les évolutions de l’édition 2024 renforcent la sécurité et préparent l’avenir du langage.

L’adoption rapide de Rust par des organisations comme Google et son utilisation dans des domaines variés démontrent sa pertinence pour former des étudiantes et étudiants en techniques informatiques. Comprendre Rust, c’est non seulement apprendre un langage performant, mais aussi assimiler des concepts de gestion de mémoire, de typage et de concurrence qui sont devenus essentiels pour la programmation moderne.

---

## Analyse critique
### Est-ce que les données semblent complètes?
Oui, je trouve que les données sont complètes, mais il y a un désalignement dans cette veille technologique. Les données sont condensées et entassées, avec un manque de structure évolutive. Dans l’introduction, on passe du tout à rien, parce que ça commence avec l’histoire et l’origine de Rust pour ensuite aller directement à un fait de JetBrains. Selon moi, l’introduction manque de structure. Pour le reste, l’agent parle des fonctions qui font la différence de Rust selon mon prompt. Un petit problème apparaît dans le deuxième paragraphe du typage, car l’agent répond à une question au lieu de rester objectif dans la veille technologique. Dans l’ensemble, il sort les informations pertinentes sur Rust en un résumé condensé.

### Est-ce que le moteur de recherche offre déjà les données de la réponse de l’agent conversationnel ?
Oui, le moteur de recherche offre déjà les données fournies par l’agent conversationnel. L’agent se fie aux données de l’internet, dont le moteur de recherche se sert également. Un utilisateur peut faire ses recherches sur Rust et trouver les mêmes informations que le LLM, car son modèle est entraîné sur des données que nous possédons aussi. Certes, la recherche peut être plus longue qu’un simple prompt auquel l’agent répond en quelques secondes.

### Est-ce que je connaissais Rust avant la réponse de l’agent ?
Non, je n’avais aucune base de connaissance en Rust. Je pensais que Rust rimait avec le jeu vidéo. J’ai d’ailleurs fait mes recherches avant la réponse de l’agent, donc j’avais acquis quelques connaissances avant sa réponse. Celle-ci m’a permis d’ancrer davantage les informations apprises.

### Est-ce que ces données peuvent être trouvées dans un site web ?
Oui, toutes les informations sur Rust se retrouvent sur un site web, notamment le site officiel de la communauté Rust. Ils ont créé un livre pour apprendre Rust en 21 chapitres avec des ateliers intéressants. Voici le lien du livre : https://doc.rust-lang.org/book/. Pour conclure, je préfère lire le livre de Rust, car les informations y sont complètes et structurées.

### Article de JetBrain
#### Rust vs Go
Dans la réponse, on peut voir que l’agent s’appuie beaucoup sur l’article de JetBrain pour son introduction et pour les cas d’usage. En survol, l’article discute la question : quel langage de programmation utiliser dans certains cas d’utilisation ? Go et Rust sont comparés par leur performance, leur communauté, leurs bibliothèques et leur gestion de mémoire. JetBrain présente les cas d’utilisation suivants pour Rust : développement système, objets connectés, WebAssembly, infrastructure cloud (Cloudflare). D’ailleurs, dans l’article, Cloudflare est un exemple parfait de l’utilisation de Rust, car dans leurs systèmes critiques, ils utilisent Rust pour sa performance.  
(https://blog.jetbrains.com/rust/2025/06/12/rust-vs-go/#challenges-and-benefits-of-learning-rust)

### Article de The Hacker News
#### Adoption de Rust pour la gestion mémoire d’Android
L’entreprise Google a décidé d’adopter le langage de programmation Rust au lieu de C++/C et a observé une diminution de 20 % des vulnérabilités liées à la sécurité de la mémoire. Ils dépensent 25 % moins de temps en développement grâce à la simplicité de Rust. Ils précisent qu’ils vont continuer à remplacer les systèmes critiques afin d’améliorer la sécurité et la performance.  
(https://thehackernews.com/2025/11/rust-adoption-drives-android-memory.html#:~:text=Google%20has%20disclosed%20that%20the,vulnerabilities%20for%20the%20first%20time)

### Rust for Dummies in 12 Minutes
Dans cette vidéo, on apprend pourquoi Rust est plus sécuritaire en développement. L’un des concepts est l’ownership, où une donnée est seulement reconnue par une variable. Par exemple, si la variable `user1` est égale à un objet `user` nommé Alice, et que la variable `user2` prend la valeur de `user1`, alors `user1` n’a plus l’objet, mais `user2` possède désormais l’objet `user`. Les références permettent de déterminer si une variable est modifiable ou non. Enfin, les types null n’existent pas dans Rust : à la place, c’est une énumération (`Option`).  
https://www.youtube.com/watch?v=0y6RKiIk6cs

### Where is Rust being used?
Dans cette vidéo, on apprend que Rust est adopté par des compagnies de services cloud, des projets blockchain et dans le développement backend. Les entreprises commencent aussi à utiliser Rust pour la sécurité, comme 1Password. Grok a utilisé Rust pour son infrastructure, donc dans le domaine de l’apprentissage machine.  
https://www.youtube.com/watch?v=42FhQWQ6SVA

