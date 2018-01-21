#include "mbed.h"
#include <stdint.h>

#include "DHT.h"            //1.Temp & Hum Sensor White Block   -- DHT22    --> A3
#include "DS1820.h"         //2.One Wire Temperature Sensor     -- DS18B20  --> A1
                            //3.Grove Moisture :: no library                --> A0
#include "TSL2561_I2C.h"    //4.Flat Light Sensor               -- TSL2561  --> SDA : D4, SCL : D5

#include "bold_font.h"      // 6. lcd OLDE Display 128x64 
#include "standard_font.h"  // 6. lcd OLDE Display 128x64 
#include "ssd1306.h"        // 6. lcd OLDE Display 128x64 

Serial pc(SERIAL_TX, SERIAL_RX);

//1. White block
DHT sensor(A3,DHT22);
void task_DHT();
int air_hum, air_temp,farenheit;
float dp = 0.0f;

//6.OLED
//SSD1306 ecran(D3 /* cs */, D6/* reset */, A5 /* dc */, A4 /* clock */, D2 /* data */);
SSD1306 ecran(D7 /* cs */, D4/* reset */, A5 /* dc */, A4 /* clock */, D8 /* data */);

//2. One Wire Temperature DS18B20
#define DATA_PIN        A1
#define MAX_PROBES      16
DS1820* probe[MAX_PROBES];
float gnd_temp;

//3. Grove Moisture
AnalogIn moisture(A0);
float gnd_hum = 0.0f;

//4. Flat Light Sensor
TSL2561_I2C lum_sensor( D3, D2 );//SDA, SCL
float float_air_light;
int air_light ;

//5. Sigfox
Serial sigfox(A7, A2);
void txData(int a ,int b,int c,int d,int e)
{
    //air_light ; air_temp ; air_hum ; gnd_temp ; gnd_hum
    pc.printf("Envoie sur le Sigfox : AT$SS:%d %d %d %d %d\r\n",a,b,c,d,e);
    //sigfox.printf("AT$SS=%d",valeur);
    sigfox.printf("AT$SS=%02x %02x %02x %02x %02x\r\n", a,b,c,d,e);
}





int main(void)
{
    printf("\r\n\nHello World!\r\n");
        
    //1. Temp & Humidity sensor -- White block
    //No more init
    
    //2. Temperature Probe -- One Wire Temperature Sensor
    int num_devices = 0;
    while(DS1820::unassignedProbe(DATA_PIN)) {
        probe[num_devices] = new DS1820(DATA_PIN);
        num_devices++;
        if (num_devices == MAX_PROBES) break;
    }
    printf("%d probe found\r\n", num_devices);
    
    //3. Grove Moisture
    
    //4.
    lum_sensor.enablePower();
    
    //6.
/*      lcd.speed (SSD1306::Medium);  // set working frequency
      lcd.init();                   // initialize SSD1306
      lcd.cls();                    // clear frame buffer
      lcd.locate (3,1);             // set text cursor to line 3, column 1
      lcd.printf ("Hello, world!"); // print to frame buffer
      lcd.line (  6, 22, 114, 22, SSD1306::Normal); //
      lcd.line (114, 22, 114, 33, SSD1306::Normal); // Surrounds text with 
      lcd.line (114, 33,   6, 33, SSD1306::Normal); // a rectangle
      lcd.line (  6, 33,   6, 22, SSD1306::Normal); //
      lcd.fill (0, 0);              // fills screen outside rectangle
      lcd.redraw();                 // updates actual display transferring frame buffer over I2C bus
*/


    ecran.initialise();
    ecran.clear();
    ecran.set_contrast(255);
    ecran.set_font(bold_font, 8);    

    // Nothing else
    
    
    printf("Inits ended");
    while(1) {
        printf("\r\n\n\nNew loop\r\n\n");
        
        //1. Temp & Humidity sensor -- White block
        printf("DHT22 White Block : \r\n");
        task_DHT();
        
        //2. Temperature Probe -- One Wire Temperature Sensor
        printf("DS18B20 Probe : \r\n");
        probe[0]->convertTemperature(true, DS1820::all_devices);         //Start temperature conversion, wait until ready
        for (int i = 0; i<num_devices; i++){
            gnd_temp = probe[i]->temperature();
            printf("Temperature : %3.1f  oC\r\n\n", gnd_temp);
        }
        
        //3. Grove Moisture
        gnd_hum = moisture;
        gnd_hum *= 100 ; // resultat 
        printf("Grove Moisture : \r\nMoisture reading is %2.2f\r\n\n", gnd_hum);
        
        //4. TSL2561 Flat Light Sensor
        float_air_light = lum_sensor.getLux();
        air_light = (int)float_air_light ;
        printf( "TSL2561 :\r\nLuminosity: %4.2f\r\n\n", float_air_light );
        printf( "TSL2561 :\r\nLuminosity: %d int\r\n\n", air_light );
        //printf( "TSL2561 :\r\nLuminosity: %d\r\n\n", air_light );
        
        
        
        //5.Transmission data par Sigfox
        txData((int)air_light,(int)air_temp,(int)air_hum,(int)gnd_temp,(int)gnd_hum);
        
        //6.Ecriture sur lcd OLED
/*        unsigned char level = 255*moisture.read();  // reads pot. Scales to 0-255
        lcd.set_contrast (level);               // set contrast
        printf("\r\nWriting on lcd done!\r\n");
*/

        ecran.set_font(bold_font, 8);
        ecran.printf("Valeurs");
        ecran.printf("\r\n"); 
        ecran.update();
        ecran.set_font(standard_font, 6);
        ecran.printf("Air Lum = %d", (int)air_light);
        ecran.printf("\r\n");
        ecran.printf("Air Temp = %d", (int)air_temp);
        ecran.printf("\r\n");
        ecran.printf("Ait Hum = %d", (int)air_hum);
        ecran.printf("\r\n");
        ecran.printf("Gnd Temp = %d", (int)gnd_temp);
        ecran.printf("\r\n");
        ecran.printf("Gnd Hum = %d", (int)gnd_hum);
        ecran.printf("\r\n");
        ecran.update();
        ecran.clear();

        wait(10000); // 1 lecture toutes les 30 secondes
        
    }
    
    
}

/**********************************************
    Transmission max de la sigfox : 240 octets/jour
***********************************************/
        
        
        
        
//1.
void task_DHT(){
    int error = 0;
 
        wait(2.0f);
        error = sensor.readData();
        if (0 == error) {
            air_temp   = sensor.ReadTemperature(CELCIUS);
            farenheit   = sensor.ReadTemperature(FARENHEIT);
            air_hum  = sensor.ReadHumidity();
            dp  = sensor.CalcdewPoint(air_temp, air_hum);
    
            printf("Air Temperature : %d oC\r\n", air_temp);
            printf("Air Humidity %d /100\r\nDewpoint: %4.2f\r\n\n", air_hum, dp);
        } else {
            printf("Error: %d\r\n", error);
        }
}


