/*************************************************************
  Download latest Blynk library here:
    https://github.com/blynkkk/blynk-library/releases/latest
  Blynk is a platform with iOS and Android apps to control
  Arduino, Raspberry Pi and the likes over the Internet.
  You can easily build graphic interfaces for all your
  projects by simply dragging and dropping widgets.
    Downloads, docs, tutorials: http://www.blynk.cc
    Sketch generator:           http://examples.blynk.cc
    Blynk community:            http://community.blynk.cc
    Follow us:                  http://www.fb.com/blynkapp
                                http://twitter.com/blynk_app
  Blynk library is licensed under MIT license
  This example code is in public domain.
 *************************************************************
  This example runs directly on ESP8266 chip.
  Note: This requires ESP8266 support package:
    https://github.com/esp8266/Arduino
  Please be sure to select the right ESP8266 module
  in the Tools -> Board menu!
  Change WiFi ssid, pass, and Blynk auth token to run :)
  Feel free to apply it to any other example. It's simple!
 *************************************************************/



/*--------------------------------------------------------------
  Program:      Test  Blynk App 

  Description:   test  platform IoT Blynk, visualization
                Prueba plataforma IoT Blynk, 
  
  Hardware:     ESP8266 12E NodeMCU Lolin .                
             
                
  Software:     Arduino IDE v1.8.3 , Blynk App
  
  Date:         22 Feb 2018
   
  Modified or Created:       PDAControl   http://pdacontroles.com   http://pdacontrolen.com

  Complete Tutorial English:  http://pdacontrolen.com/meter-pzem-004-esp8266-platform-iot-blynk-app/
  
  Tutorial Completo Español:  http://pdacontroles.com/medidor-pzem-004-esp8266-plataforma-iot-blynk-app/

  Based:  Examples blynk virtual data : https://examples.blynk.cc/?board=ESP8266&shield=ESP8266%20WiFi&example=GettingStarted%2FVirtualPinWrite  

          Blynk Github https://github.com/blynkkk/blynk-library/blob/master/examples/Boards_WiFi/ESP8266_Standalone/ESP8266_Standalone.ino

       

 
--------------------------------------------------------------*/


/* Comment this out to disable prints and save space */
#define BLYNK_PRINT Serial


#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "**********************************************";

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "*************";
char pass[] = "***************************";


unsigned long lastMillis = 0;


///http://pdacontrolen.com/meter-pzem-004-esp8266-platform-iot-blynk-app/


void setup()
{
  // Debug console
  Serial.begin(9600);

  Blynk.begin(auth, ssid, pass);
}

void loop()
{
  Blynk.run();


      //Publish data every 10 seconds (10000 milliseconds). Change this value to publish at a different interval.
          if (millis() - lastMillis > 10000) {
            lastMillis = millis();

            
            Blynk.virtualWrite(V1, lastMillis);
            Blynk.virtualWrite(V2, 1.14  );
            
            Blynk.virtualWrite(V3, lastMillis);
            Blynk.virtualWrite(V4, 1.14  );

          }
  
}
