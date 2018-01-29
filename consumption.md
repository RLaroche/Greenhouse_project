One of the most important point of our project is that the system must be autonomous in energy. For this we use a battery and a solar cell. The battery can deliver a current of 1050 mA in 1 hour with a voltage of 3.7 V : 3,885Wh. The solar cell is used to recharge the battery, it delivers a voltage of 5.5 V under 360 mA --> a power equal 2 W.

Theoretical consumption of our system :
- Temperature sensor DHT22 : at max 1.5 mA and at rest 0.05 mA
- Grove temperature sensor: max 1.5 mA
- Light sensor : 0.5 mA
- Nucleo Cart : + 100 mA
- LCD display : 20 mA
- Sigfox TD1208 module : sending 24 mA (in this project, nothing is received with this module) and at rest 1.5 μA

At rest, the consumption is negligible compared to the power of the battery. When the system goes out of sleep (every 10 minutes), all the sensors make measurements, the screen displays the result and the sigfox module transmits these results. It is considered that all components consume a maximum at this time : we use about 158 mA every 10 minutes so 6 * 158 = 948 mA in 1 hour. The battery can hold a little over an hour before discharging completely.

The goal is to spend a minimum of energy to have the least possible need to recharge the battery. Otherwise, if the solar cell does not receive sunshine for a while, it could not charge the battery that would discharge and our system would turn off.
