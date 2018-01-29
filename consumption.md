Un des points importants de notre projet est que le système doit être autonome en énergie. Pour cela, nous utilisons une batterie et une cellule solaire. La batterie peut délivrer un courant de __1050 mA en 1 heure__ avec une tension de 3,7 V : 3,885Wh. La cellule solaire permet de recharger la batterie, elle délivre une tension de 5,5 V sous 360 mA soit une puissance d'environ 2 W.

Calcul de la consommation théorique de notre système :
- Capteur de température DHT22 : au max 1,5 mA et au repos 0.05 mA
- Capteur de température Grove : au max 1.5 mA
- Capteur de luminosité : 0.5 mA
- Cart nucléo : + 100 mA
- Ecran LCD : 20 mA
- Module Sigfox TD1208 : envoi 24 mA (dans ce projet, on ne reçoit rien avec ce module) et au repos 1,5 µA

Au repos, la consommation est négligeable par rapport à la puissance de la batterie. Lorsque le système sort de veille (toutes les 10 minutes), tous les capteurs font des mesures, l'écran affiche le résultat et le module sigfox transmet ces résultats. On considère que tous les composants consomment un maximum à ce moment-là : on utilise environ 158 mA toutes les 10 minutes donc 6 * 158 = __948 mA en 1 heure__. La batterie pourra donc tenir un peu plus d'une heure avant de se décharger totalement.

Le but est de dépenser un minimum d'énergie pour avoir le moins possible besoin de recharger la batterie. Dan le cas contraire, si la cellule solaire ne reçoit pas de soleil pendant un certain temps, elle ne pourrait pas recharger la batterie qui se déchargerait et notre système s'éteindrait.


One of the most important point of our project is that the system must be autonomous in energy. For this we use a battery and a solar cell. The battery can deliver a current of 1050 mA in 1 hour with a voltage of 3.7 V : 3,885Wh. The solar cell is used to recharge the battery, it delivers a voltage of 5.5 V under 360 mA --> a power equal 2 W.

Calculating the theoretical consumption of our system :

Temperature sensor DHT22 : at max 1.5 mA and at rest 0.05 mA
Grove temperature sensor: max 1.5 mA
Light sensor: 0.5 mA
Nucleo Cart: + 100 mA
LCD display: 20 mA
Sigfox TD1208 module: sending 24 mA (in this project, nothing is received with this module) and at rest 1.5 μA
At rest, the consumption is negligible compared to the power of the battery. When the system goes out of sleep (every 10 minutes), all the sensors make measurements, the screen displays the result and the sigfox module transmits these results. It is considered that all components consume a maximum at this time: we use about 158 mA every 10 minutes so 6 * 158 = 948 mA in 1 hour. The battery can hold a little over an hour before discharging completely.

The goal is to spend a minimum of energy to have the least possible need to recharge the battery. Otherwise, if the solar cell does not receive sunshine for a while, it could not charge the battery that would discharge and our system would turn off.
