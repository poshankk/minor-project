#define BLYNK_PRINT Serial
#include<SPI.h>
#include<ESP8266WiFi.h>
#include<BlynkSimpleEsp8266.h>
 BlynkTimer timer;

 char auth[] = "5c611392491949dcbc5e3343b1956e47";

 char ssid[] = "POSHAN";
 char pass[] = "57894563";

 int led = 13;
 int pin = 2;
 //int analog = A0;
 int val;
 

 
 
 void flame()
     {

    
        
         long uptime = millis() / 1000L;
         
          val = digitalRead(pin);
         if(val==HIGH)
         {

           
           digitalWrite(led,HIGH);
           Blynk.notify("Fire detected");
           Blynk.email("poshankk43@gmail.com", "Subject: FIRE DETECTION", "Fire Detected at NIT RAIPUR");
          }
          else
          {
            Serial.println("Fire not detected");
            digitalWrite(led,LOW);
          }
          delay(500);
     }

     void setup() 
     {
      
       pinMode(led,OUTPUT);
       pinMode(pin,INPUT);
      // pinMode (analog, INPUT) ;
       Blynk.begin(auth, ssid, pass);
       Blynk.notify("wifi connected");
       Blynk.email("poshankk43@gmail.com", "Subject: WIFI STATUS", "Wifi is online...");
       attachInterrupt(digitalPinToInterrupt(pin), flame, CHANGE);
       timer.setInterval(1000L, flame);

}
     


void loop() 
{
  Blynk.run();
  timer.run();
  
}
