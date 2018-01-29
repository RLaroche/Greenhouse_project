Let's start the PCB part ! 

Nous avons eu de nombreux soucis pour une étape qui ne nous semblaient pas devoir prendre autant de temps que cela a été. 
Première erreur : ne pas avoir sauvegardé à plusieurs endroits le PCB. 
En effet, le premier PCB réalisé a été porté disparu lorsque la clé USB le comprenant a rendu l'âme. 
Du coup, il a fallu retrouver l'énergie nécessaire pour affronter ce casse-tête nécessaire à l'industrialisation de notre projet.
Petit détails qui restent important, il fallait que les connexions soient toutes sur le côté bottom du PCB et qu'on établisse un plan de masse ce qui a pour but de relier tous les GROUND des composants entre eux.

Une fois le courage retrouvé on refait le schéma electronique sur ALTIUM que l'on peut voir ci-desous :

![alt tag](https://user-images.githubusercontent.com/35667679/35527856-60283a2c-052c-11e8-90d4-06787587e1f4.PNG)

On y retrouve bien les quatres capteurs, la carte Nucléo, le module Sigfox ainsi que l'écran LCD.

On bascule sur la partie PCB, on y passe du temps, on la fini avec un seul coté utilisé, on essaie de l'imprimer car même avec l'aide de l'ingénieur responsable de l'impression la machine fait des siennes. Une fois imprimé on là test ... et là c'est le drame. 
On constate que la branche gauche de la carte NUCLEO est inversé. On peut d'ailleurs le remarquer en regarder le schéma électronique ci-dessus. La branche NUCLEO gauche va de 1 à 15 en commençant par le haut, alors que la branche de droite va de 15 à 1 en partant du haut également. Ce qui fait que rien ne fonctionne. 
Il a fallu repprendre ses esprits, recommencer encore pour la 3ème fois un PCB d'urgence en faisant attention à toutes les connexions.

Hallelujah le PCB est créé, on peut le voir sur l'image ci-dessous :

![alt tag](https://user-images.githubusercontent.com/35667679/35523963-5b6e9596-0520-11e8-8cb2-76283c936e0f.PNG)

Tout était parfait, les soudures faites par Mr SamSmile était d'une beauté incomparable.
Trop beau pour être vrai ? En effet, un seul et unique hic : 
![alt tag](https://user-images.githubusercontent.com/35667679/35528845-7263465c-052f-11e8-9565-026f43d3c3fb.PNG)

Zoomons d'un peu plus près : 
![alt tag](https://user-images.githubusercontent.com/35667679/35529344-0fe1cc9a-0531-11e8-84b0-87f097b13db4.PNG)

On constate que sur la carte à droite sur laquelle le PCB s'est basé a bien une connexion SDA sur D7 et une SCL sur D8 (exactement ce qu'il nous faut). Cependant lorsqu'on a testé avec les composant on ne comprenais pas l'incohérence des informations reçues, et du coup quand on a regardé à nouveau la documentation sur la deuxième documentation on remarque qu'il n'y a pas de spécificité sur D7 et D8. 

Résultat : notre montage sur le breadbord  fonctionnait très bien avant d'avoir adapté les connexions sur le PCB pour faciliter le routage.
Mais une fois sur le PCB non adapté on arrive a recevoir les informations malgré tout de tout les capteurs sauf du light sensor dans cette version.