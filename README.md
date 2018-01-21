# Greenhouse_project
Ce projet propose de monitorer la température, la luminosité et l'humidité ambiante, ainsi que la température et l'humidité de la terre d'une serre. Il propose aussi de mettre ces mesures en réseau et de les lire via le site web Actoboard.com

Pour ce faire, nous connectons 4 capteurs à la carte Nucleo LK32KC :
  - un capteur de luminosité numérique TSL2561 d'Adafruit,
  - un capteur d'humidité et de température ambiante DHT22 de gotronic,
  - une sonde de température analogique DS1820,
  - et un capteur d'humidité Grove - Moisture Sensor de Seeed Studio

Les mesures sont faites toutes les 10 min et sont mis en réseau via une Sigfox TD1208. Ils sont récupérables comme dit plus haut sur le site Actobard.com
A cette Nucleo sera aussi branché un écran OLED Display 128x64 qui affichera en permanence les dernières valeurs récupérées.
Enfin, l'ensemble sera énergétiquement autonome à l'aide d'une cellule photovoltaïque et d'une batterie de 1.5Ah. Ceux-ci sont branchés au microcontrolleur via un LiPo Rider Pro de Seeed Studio.


