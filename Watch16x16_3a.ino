// http://arduino-kid.ru/blog/chasy-na-svetodiodakh-ws2812
// https://youtu.be/1oqfN3A-YfY
// v.1 - added clock adjustment by Nicu FLORICA (niq_ro)
// v.2 - added outside second line and moved numbers (regenerate others)
// v.2.a - changed to "classical" RTC library from https://github.com/adafruit/RTClib
// v.2.b - line for seconds changed in moving point
// v.3 - changed to ESP8266 -> NTP clock
// v.3.a - added real seconds (fron NTP server)
// v.3.a.1 - reduced flicker ar seconds = 0

#include "FastLED.h"
#include <NTPClient.h>
#include <ESP8266WiFi.h>
#include <WiFiUdp.h>

const char *ssid     = "niq_ro";
const char *password = "berelaburtica";

const long timezoneOffset = 2*3600; // GMT + seconds  (Romania)

// Define NTP Client to get time
WiFiUDP ntpUDP;
NTPClient timeClient(ntpUDP, "pool.ntp.org", timezoneOffset);

#define DSTpin   14 // GPIO14 = D5, see https://randomnerdtutorials.com/esp8266-pinout-reference-gpios/
#define DATA_PIN 12 // GPIO12 = D6;

const int NUM_LEDS = 256;
//const int photoPin = A0;             // Аналоговый вход с фоторезистором
CRGB leds[NUM_LEDS];

unsigned long tpschimbare;
unsigned long tpsecunda = 1000;

int a1;  // tens of hour
int b1; // units of hour
int c1; // tens of minute
int d1; // units of minute
int d10 = 60;   
int contor = 0;
int contor0 = 60;
int secunda;
int secunda0 = 60; 

int ora, minut;
byte DST = 0;
byte DST0;

void setup() {
  Serial.begin(115200);
  Serial.println("Clock");
  
pinMode (DSTpin, INPUT);

  WiFi.begin(ssid, password);
  while ( WiFi.status() != WL_CONNECTED ) {
    delay ( 500 );
    Serial.print ( "." );
  }

  if (digitalRead(DSTpin) == LOW)
   DST = 0;
  else
   DST = 1;
  timeClient.setTimeOffset(timezoneOffset + DST*3600);
  timeClient.begin();
  DST0 = DST;
                             
  delay(2000);
  FastLED.addLeds<WS2812B, DATA_PIN, GRB>(leds, NUM_LEDS);
  FastLED.setBrightness(5); //Number 0-255
  FastLED.clear();

 timeClient.update();
 ora = timeClient.getHours();
 minut = timeClient.getMinutes();
 secunda = timeClient.getSeconds();

Serial.print(ora);
Serial.print(";");
Serial.println(minut);

a1 = ora/10;
b1 = ora%10;
c1 = minut/10;
d1 = minut%10;
  afisare_ora(a1, b1, c1, d1);
  FastLED.show(); 
  contor = secunda;
}

    const size_t len_0 = 28;
    const size_t len_1 = 17;
    const size_t len_2 = 23;
    const size_t len_3 = 23;
    const size_t len_4 = 22;
    const size_t len_5 = 25;
    const size_t len_6 = 27;
    const size_t len_7 = 20;
    const size_t len_8 = 28;
    const size_t len_9 = 27;
        
    const uint16_t h_d_0[] PROGMEM = {237,236,235,234,233,215,214,213,212,211,210,209,206,200,183,177,174,173,172,171,170,169,168,150,149,148,147,146};
    const uint16_t h_d_1[] PROGMEM = {215,210,206,205,204,203,202,201,200,183,182,181,180,179,178,177,168};
    const uint16_t h_d_2[] PROGMEM = {237,233,232,215,214,213,210,209,206,203,202,200,183,180,177,174,173,172,171,168,151,147,146};

    const uint16_t h_e_0[] PROGMEM = {18,19,20,21,22,40,41,42,43,44,45,46,49,55,72,78,81,82,83,84,85,86,87,105,106,107,108,109};

    const uint16_t h_e_1[] PROGMEM = {40,49,50,51,52,53,54,55,72,73,74,75,76,77,78,82,87};
    const uint16_t h_e_2[] PROGMEM = {18,19,23,40,43,44,45,46,49,52,55,72,74,75,78,81,82,85,86,87,104,105,109};
    const uint16_t h_e_3[] PROGMEM = {18,19,21,22,40,41,42,43,44,45,46,49,52,55,72,75,78,81,82,86,87,105,109};
    const uint16_t h_e_4[] PROGMEM = {17,18,19,20,21,22,23,40,41,42,43,44,45,46,52,75,81,82,83,84,107,108};
    const uint16_t h_e_5[] PROGMEM = {17,21,22,40,41,42,43,46,49,52,55,72,75,78,81,82,83,84,86,87,105,107,108,109,110};
    const uint16_t h_e_6[] PROGMEM = {18,21,22,40,41,42,43,45,46,49,52,55,72,75,78,81,82,83,84,85,86,87,105,106,107,108,109};
    const uint16_t h_e_7[] PROGMEM = {17,18,19,43,44,45,46,49,52,53,54,55,72,73,74,78,81,82,109,110};
    const uint16_t h_e_8[] PROGMEM = {18,19,21,22,40,41,42,43,44,45,46,49,52,55,72,75,78,81,82,83,84,85,86,87,105,106,108,109};
    const uint16_t h_e_9[] PROGMEM = {18,19,20,21,22,40,41,42,43,44,45,46,49,52,55,72,75,78,81,82,83,84,86,87,105,108,109};

    const uint16_t m_d_0[] PROGMEM = {153,154,155,156,157,161,162,163,164,165,166,167,184,190,193,199,216,217,218,219,220,221,222,226,227,228,229,230};
    const uint16_t m_d_1[] PROGMEM = {161,184,185,186,187,188,189,190,193,194,195,196,197,198,199,217,222};
    const uint16_t m_d_2[] PROGMEM = {153,154,158,161,164,165,166,167,184,187,190,193,195,196,199,216,220,221,222,225,226,230};
    const uint16_t m_d_3[] PROGMEM = {153,154,156,157,161,162,163,164,165,166,167,184,187,190,193,196,199,216,221,222,226,230};
    const uint16_t m_d_4[] PROGMEM = {152,153,154,155,156,157,158,161,162,163,164,165,166,167,187,196,216,217,218,219,228,229};
    const uint16_t m_d_5[] PROGMEM = {152,156,157,161,162,163,164,167,184,187,190,193,196,199,216,217,218,219,221,222,226,228,229,230,231};

    const uint16_t m_e_0[] PROGMEM = {25,26,27,28,29,33,34,35,36,37,38,39,56,62,65,71,88,89,90,91,92,93,94,98,99,100,101,102};
    const uint16_t m_e_1[] PROGMEM = {33,56,57,58,59,60,61,62,65,66,67,68,69,70,71,89,94};
    const uint16_t m_e_2[] PROGMEM = {25,26,30,33,36,37,38,39,56,59,62,65,67,68,71,88,92,93,94,97,98,102};
    const uint16_t m_e_3[] PROGMEM = {25,26,28,29,33,34,35,36,37,38,39,56,59,62,65,68,71,88,94,98,102}; 
    const uint16_t m_e_4[] PROGMEM = {24,25,26,27,28,29,30,33,34,35,36,37,38,39,59,68,88,89,90,91,100,101}; 
    const uint16_t m_e_5[] PROGMEM = {24,28,29,33,34,35,36,39,56,59,62,65,68,71,88,89,90,91,93,94,98,100,101,102,103}; 
    const uint16_t m_e_6[] PROGMEM = {25,28,29,33,34,35,36,39,56,59,62,65,68,71,88,89,90,91,92,93,94,98,99,100,101,102};
    const uint16_t m_e_7[] PROGMEM = {24,25,26,36,37,38,39,56,59,60,61,62,65,66,67,71,88,89,102,103};
    const uint16_t m_e_8[] PROGMEM = {25,26,28,29,33,34,35,36,37,38,39,56,59,62,65,68,71,88,89,90,91,92,93,94,98,99,101,102};  
    const uint16_t m_e_9[] PROGMEM = {25,26,27,28,29,33,34,35,36,37,38,39,56,59,62,65,68,71,88,89,90,91,93,94,98,101,102};

    const size_t len_sec = 60;
    const uint16_t sec_0[] PROGMEM = {112,111,80,79,48,47,16,15,14,13,12,11,10,9,8,7,6,5,4,3,2,1,0,31,32,63,64,95,96,127,
                                      128,159,160,191,192,223,224,255,254,253,252,251,250,249,248,247,246,245,244,243,242,241,
                                      240,239,208,207,176,175,144,143}; 

    
void loop() {
//Serial.println(analogRead(photoPin));
// Яркость свечения
  //if(analogRead(photoPin) < 270) FastLED.setBrightness(50); 
  //else if(analogRead(photoPin) < 470) FastLED.setBrightness(50);
  //else if(analogRead(photoPin) < 700)FastLED.setBrightness(50);
  //else FastLED.setBrightness(2);

  
if (digitalRead(DSTpin) == LOW)
   DST = 0;
  else
   DST = 1;
  
timeClient.update();
 ora = timeClient.getHours();
 minut = timeClient.getMinutes();
 secunda = timeClient.getSeconds();

Serial.print(ora);
Serial.print(":");
Serial.print(minut);

a1 = ora/10;
b1 = ora%10;
c1 = minut/10;
d1 = minut%10;
/*
Serial.print(" -> ");
Serial.print(c1);
Serial.print(d1);
Serial.print(":");
Serial.print(a1);
Serial.println(b1);
*/
if (secunda != secunda0)
{
if (secunda >= 1) leds[pgm_read_byte(&sec_0[secunda-1])] = CRGB(0,0,0);
if (secunda == 0) leds[pgm_read_byte(&sec_0[len_sec-1])] = CRGB(0,0,0);

leds[pgm_read_byte(&sec_0[secunda])] = CRGB(255,255,0);
FastLED.show(); 
}
secunda0 = secunda;

Serial.print(secunda);
Serial.print(" / ");
Serial.println(len_sec);


if (millis() - tpschimbare > tpsecunda)
{
if (secunda == 0)
  {
  FastLED.clear();
  leds[pgm_read_byte(&sec_0[secunda])] = CRGB(255,255,0);
  FastLED.show(); 
  afisare_ora(a1, b1, c1, d1); 
  }
tpschimbare = millis();
}

if (DST != DST0)
{
  timeClient.setTimeOffset(timezoneOffset + DST*3600);
  timeClient.begin();
  timeClient.update();
  ora = timeClient.getHours();
  minut = timeClient.getMinutes();
  secunda = timeClient.getSeconds();
Serial.print(ora);
Serial.print(";");
Serial.println(minut);

a1 = ora/10;
b1 = ora%10;
c1 = minut/10;
d1 = minut%10;
  FastLED.clear();
  afisare_ora(a1, b1, c1, d1);
  FastLED.show();  
DST0 = DST;
}
delay(50);
}  // end main loop


void afisare_ora(int x, int y, int z, int w) {
  //tens of hours
    if(x==0){
                for (int i = 0; i < len_0; i++){           
                      leds[pgm_read_byte(&h_d_0[i])] = CRGB::Red;
                }
                FastLED.show();    
    }
    else if(x==1){
               for (int i = 0; i < len_1; i++){  
                      leds[pgm_read_byte(&h_d_1[i])] = CRGB::Red;
                }
                FastLED.show();
      
    }
    else if(x==2){
              for (int i = 0; i < len_2; i++){  
                      leds[pgm_read_byte(&h_d_2[i])] = CRGB::Red;
                }
                FastLED.show();
    }

//units of hour
     if(y==0){  
                for (int i = 0; i < len_0; i++){
                      leds[pgm_read_byte(&h_e_0[i])] = CRGB::Red;
                }
               FastLED.show();
     }
     else if(y==1){  
                for (int i = 0; i < len_1; i++){
                      leds[pgm_read_byte(&h_e_1[i])] = CRGB::Red;
                }
               FastLED.show();
     }
     else if(y==2){  
                  for (int i = 0; i < len_2; i++){
                        leds[pgm_read_byte(&h_e_2[i])] = CRGB::Red;
                  }
                 FastLED.show();
       }
      else if(y==3){  
                  for (int i = 0; i < len_3; i++){
                        leds[pgm_read_byte(&h_e_3[i])] = CRGB::Red;
                  }
                 FastLED.show();
       }
      else if(y==4){  
                  for (int i = 0; i < len_4; i++){
                        leds[pgm_read_byte(&h_e_4[i])] = CRGB::Red;
                  }
                 FastLED.show();
       }
       else if(y==5){  
                  for (int i = 0; i < len_5; i++){
                        leds[pgm_read_byte(&h_e_5[i])] = CRGB::Red;
                  }
                 FastLED.show();
       }
      else if(y==6){  
                  for (int i = 0; i < len_6; i++){
                        leds[pgm_read_byte(&h_e_6[i])] = CRGB::Red;
                  }
                 FastLED.show();
       }
      else if(y==7){  
                  for (int i = 0; i < len_7; i++){
                        leds[pgm_read_byte(&h_e_7[i])] = CRGB::Red;
                  }
                 FastLED.show();
       }
      else if(y==8){  
                  for (int i = 0; i < len_8; i++){
                        leds[pgm_read_byte(&h_e_8[i])] = CRGB::Red;
                  }
                 FastLED.show();
       }
      else if(y==9){  
                  for (int i = 0; i < len_9; i++){
                        leds[pgm_read_byte(&h_e_9[i])] = CRGB::Red;
                  }
                 FastLED.show();
       }

 
 //tens of minutes
    if(z==0){
                for (int i = 0; i < len_0; i++){
                      leds[pgm_read_byte(&m_d_0[i])] = CRGB::Blue;
                }
                FastLED.show();      
    }
    else if(z==1){
                for (int i = 0; i < len_1; i++){
                      leds[pgm_read_byte(&m_d_1[i])] = CRGB::Blue;
                }
                FastLED.show();     
    }
    else if(z==2){
                for (int i = 0; i < len_2; i++){
                      leds[pgm_read_byte(&m_d_2[i])] = CRGB::Blue;
                }
                FastLED.show();      
    }
    else if(z==3){
                for (int i = 0; i < len_3; i++){
                      leds[pgm_read_byte(&m_d_3[i])] = CRGB::Blue;
                }
                FastLED.show();     
    }
    else if(z==4){
                for (int i = 0; i < len_4; i++){
                      leds[pgm_read_byte(&m_d_4[i])] = CRGB::Blue;
                }
                FastLED.show();      
    }
    else if(z==5){
                for (int i = 0; i < len_5; i++){
                      leds[pgm_read_byte(&m_d_5[i])] = CRGB::Blue;
                }
                FastLED.show();     
    }

 //units of minutes
    if(w==0){
                for (int i = 0; i < len_0; i++){
                      leds[pgm_read_byte(&m_e_0[i])] = CRGB::Blue;
                }
                FastLED.show();      
    }
    else if(w==1){
                for (int i = 0; i < len_1; i++){
                      leds[pgm_read_byte(&m_e_1[i])] = CRGB::Blue;
                }
                FastLED.show();      
    }
    else if(w==2){                   
                for (int i = 0; i < len_2; i++){
                      leds[pgm_read_byte(&m_e_2[i])] = CRGB::Blue;
                }
                FastLED.show();     
    }
    else if(w==3){
                for (int i = 0; i < len_3; i++){
                      leds[pgm_read_byte(&m_e_3[i])] = CRGB::Blue;
                }
                FastLED.show();      
    }
    else if(w==4){   
                for (int i = 0; i < len_4; i++){
                      leds[pgm_read_byte(&m_e_4[i])] = CRGB::Blue;
                }
                FastLED.show();      
    }
    else if(w==5){
                for (int i = 0; i < len_5; i++){
                      leds[pgm_read_byte(&m_e_5[i])] = CRGB::Blue;
                }
                FastLED.show();      
    }
    else if(w==6){
                for (int i = 0; i < len_6; i++){
                      leds[pgm_read_byte(&m_e_6[i])] = CRGB::Blue;
                }
                FastLED.show();      
    }
    else if(w==7){
                for (int i = 0; i < len_7; i++){
                      leds[pgm_read_byte(&m_e_7[i])] = CRGB::Blue;
                }
                FastLED.show();     
    }
    else if(w==8){
                for (int i = 0; i < len_8; i++){
                      leds[pgm_read_byte(&m_e_8[i])] = CRGB::Blue;
                }
                FastLED.show();      
    }
    else if(w==9){    
                for (int i = 0; i < len_9; i++){
                      leds[pgm_read_byte(&m_e_9[i])] = CRGB::Blue;
                }  
                FastLED.show();       
    }
}
