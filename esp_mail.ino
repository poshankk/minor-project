#define BLINK_PRINT Serial
#include<SPI.h>
#include<ESP8266WiFi.h>
#include<BlynkSimpleEsp8266.h>

char auth[] = "ce2ca3aac8544817b4cac40638943821";

char ssid[] = "POSHAN";
char pass[] = "57894563";

void email()
   {
      int button = digitalRead(2);
      if(button==HIGH)
        {
          Blynk.email("poshankk43@gmail.com" , "Subject: Fire Detected" , "Button is Pressed");
          Blynk.notify("Hello Poshan"); 
        }

        /*else if(button==LOW)
        {
          //Blynk.email("diwanpatle1@gmail.com" , "Subject: Fire Detected" , "Button is Pressed");
          Blynk.email("poshankk43@gmail.com" , "Subject: Fire Detected" , "Button is Pressed"); 
        }*/
   }

void setup() {
     Serial.begin(9600);
     pinMode(2,INPUT);
     Blynk.begin(auth, ssid, pass);
      //Blynk.notify("Hello Poshan"); 
     Blynk.email("poshankk43@gmail.com", "Subject: Alert", "Wifi is online..");
      attachInterrupt(digitalPinToInterrupt(2), email, CHANGE);
}

void loop()
{
      Blynk.run();
      

}
