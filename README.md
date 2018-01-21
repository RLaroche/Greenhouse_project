# Greenhouse_project
This project proposes to monitor the temperature, luminosity et humidity of the air, as well as the temperature et humidity of the grove. It proposes too to network this measures which are so readable on the website Actoborad.com

To do, we connect 4 sensors to the Nucleo microcontroller L432KC :
  - a luminosity sensor TLS2561 by Adafruit ;
  - a humidity and temperature sensor DHT22 by Gotronic ;
  - a tempearture probe DS1820 ;
  - a humidity sensor Grove - Moisture sensor by Seeed Studio
  
  Measurerrs are done each 10 minutes and are networked via a Breakout TD1208 by Sigfox. As said higher, this one are readable on the website Actoboard.com
On this microcontroller is also plugged an OLED Display 128x64 screen which will permanently display the last measures done.
Finally, the system is electrically self-sufficent thanks to a 8x20cm photovoltaïc cell and a 1.5Ah battery. They are connected to the Nulceo with a LiPo Rider Pro by Seeed Studio.
The system is put in a 3D printed box.

Here is the synoptic of the project :
![alt tag](https://user-images.githubusercontent.com/22792781/35197159-e7b649e0-fedb-11e7-82ea-f0fbacf0a8a4.png)

The code compiled in the microcontroller via os.mbed.com is named 'main.cpp'.
The used libraries are in the repository 'libraries'.

