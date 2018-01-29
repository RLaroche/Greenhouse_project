Let's start the PCB part ! 

We had many problems for a step that we did not think we would take us so much time.
First error: not having saved the PCB in several places.
Indeed, the first PCB realised was deleted when the USB had some problems. Now all the files inside the USB are not accessible.
Suddenly, it was necessary to find the necessary energy for this puzzle for the industrialization of our project.
Small detail that remains important, it is necessary that the connections are all at the bottom side of the PCB and that one establishes a plan of mass.

Once the courage found , we can do again the electronic scheme on ALTIUM as you can see below :

![alt tag](https://user-images.githubusercontent.com/35667679/35527856-60283a2c-052c-11e8-90d4-06787587e1f4.PNG)

It contains the sensors, the Nucleo card, the Sigfox module and the LCD screen.

We switch to the PCB's part, we loose so much time on it, but at the end we succed it. Once printed we test it ... and here is the drama.
The half NUCLEO card is reversed. We can also look at the diagram above. The left NUCLEO branch from 1 to 15 starting from the top, while the branch of the right 15 to 1 also from the top. What makes nothing work.
It was necessary to recover his mind, to repeat for the 3rd time the emergency PCB paying attention to all the connections.

Hallelujah the PCB is created, we can see it in the picture below:

![alt tag](https://user-images.githubusercontent.com/35667679/35523963-5b6e9596-0520-11e8-8cb2-76283c936e0f.PNG)

Everything was perfect, the welds made by Mr SamSmile were of incomparable beauty.
Too good to be true? Indeed, one and only problem:
![alt tag](https://user-images.githubusercontent.com/35667679/35528845-7263465c-052f-11e8-9565-026f43d3c3fb.PNG)

Zoom it in a little closer:
![alt tag](https://user-images.githubusercontent.com/35667679/35529344-0fe1cc9a-0531-11e8-84b0-87f097b13db4.PNG)

We see that on the map on the right on which the PCB is based on an SDA connection on D7 and an SCL on D8 (exactly what we need).
However when we tested with the components we did not understand the inconsistency of the information received, and suddenly when we looked again the documentation on the second documentation we notice that there is no specificity on D7 and D8.

As a result, our breadmaking works very well before adapting the connections on the PCB for easy routing.
But once on the PCB not modified we get to receive the information despite all the sensors except the light sensor in this version.
