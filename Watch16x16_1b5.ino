// http://arduino-kid.ru/blog/chasy-na-svetodiodakh-ws2812
// https://youtu.be/1oqfN3A-YfY
// v.1 - added clock adjustment by Nicu FLORICA (niq_ro)

#include "FastLED.h"
#include <DS3231.h>                    // Подключаем библиотеку Wire  
DS3231  rtc(SDA, SCL);                 // Инициализация DS3231

const int NUM_LEDS = 256;
const int DATA_PIN = 6;
//const int photoPin = A0;             // Аналоговый вход с фоторезистором
CRGB leds[NUM_LEDS];

unsigned long timing;                  // Переменная для хранения точки отсчета
Time t;

#define hplus 2    // pin for increment the hour
#define mplus 3    // pin for increment the minute

byte ora, minut;

unsigned long tpschimbare;
unsigned long tpsecunda = 1825;

int x1;  // tens of hour
int y1; // units of hour
int z1; // tens of minute
int w1; // units of minute
int w10 = 60;   
int contor = 0;
int contor0 = 60;


void setup() {
  Serial.begin(9600);
  Serial.println("Clock");
/*
pinMode(hplus, INPUT_PULLUP);
pinMode(hplus, INPUT_PULLUP);
*/

  pinMode (hplus, INPUT);
  pinMode (mplus, INPUT);
  digitalWrite (hplus, HIGH);
  digitalWrite (mplus, HIGH);


  rtc.begin();                         // Инициализировать rtc
  delay(2000);
  FastLED.addLeds<WS2812B, DATA_PIN, GRB>(leds, NUM_LEDS);
  FastLED.setBrightness(2); //Number 0-255
  FastLED.clear();

  //Установка даты и времени
  //rtc.setDOW(SUNDAY);     // День недели по английски MONDAY  TUESDAY  WEDNESDAY  THURSDAY  FRIDAY  SATURDAY  SUNDAY
  //rtc.setTime(10, 41, 0);     // Установка часов 12:00:00 (24часовой формат)
  //rtc.setDate(30, 10, 2022);   // Установка даты число, месяц, год  

// red the time
  t = rtc.getTime();
int x1 =(t.hour%100)/10;  // tens of hour
int y1 =t.hour%10;        // units of hour
int z1 =(t.min%100)/10;   // tens of minute
int w1 = t.min%10;        // units of minute
 FastLED.clear();
  afisare_ora(x1, y1, z1, w1);
  contor = 0;
}

    const uint16_t h_d_0[] PROGMEM = {238,237,236,235,234,214,213,212,211,210,209,208,207,201,182,176,175,174,173,172,171,170,169,145,146,147,148,149};
    const uint16_t h_d_1[] PROGMEM = {182,207,206,205,204,203,202,201,208,209,210,211,212,213,214,233,238};
    const uint16_t h_d_2[] PROGMEM = {238,234,233,214,213,212,209,208,207,204,203,201,182,179,176,175,174,173,172,169,150,146,145};

    const uint16_t h_e_0[] PROGMEM = {17,18,19,20,21,41,42,43,44,45,46,47,48,54,73,79,80,81,82,83,84,85,86,106,107,108,109,110};
    const uint16_t h_e_1[] PROGMEM = {22,41,42,43,44,45,46,47,48,49,50,51,52,53,54,73,78};
    const uint16_t h_e_2[] PROGMEM = {17,18,22,41,44,45,46,47,48,51,54,73,75,76,79,80,81,84,85,86,105,106,110};
    const uint16_t h_e_3[] PROGMEM = {17,18,20,21,41,42,43,44,45,46,47,48,51,54,73,76,79,80,81,85,86,106,110};
    const uint16_t h_e_4[] PROGMEM = {16,17,18,19,20,21,22,41,42,43,44,45,46,47,52,75,80,81,82,83,84,108,109,110,111};
    const uint16_t h_e_5[] PROGMEM = {16,19,20,21,41,42,43,44,45,47,48,50,54,73,77,79,80,81,82,85,86,106,109,110,111};
    const uint16_t h_e_6[] PROGMEM = {17,20,21,41,42,43,44,46,47,48,51,54,73,76,79,80,81,82,83,84,85,86,106,107,108,109,110};
    const uint16_t h_e_7[] PROGMEM = {16,17,45,46,47,48,50,51,52,53,54,73,74,75,76,79,80,111};
    const uint16_t h_e_8[] PROGMEM = {17,18,20,21,41,42,43,44,45,46,47,48,51,54,73,76,79,80,81,82,83,84,85,86,106,107,109,110};
    const uint16_t h_e_9[] PROGMEM = {17,18,19,20,21,41,42,43,44,45,46,47,48,51,54,73,76,79,80,81,82,83,85,86,106,109,110};

    const uint16_t m_d_0[] PROGMEM = {229,228,227,226,225,217,218,219,220,221,222,223,198,192,191,185,160,161,162,163,164,165,166,158,157,156,155,154};
    const uint16_t m_d_1[] PROGMEM = {229,224,223,222,221,220,219,218,217,198,197,196,195,194,193,192,191};
    const uint16_t m_d_2[] PROGMEM = {229,225,224,223,222,221,218,217,198,195,194,192,191,188,185,166,165,164,163,160,159,155,154};
    const uint16_t m_d_3[] PROGMEM = {229,225,223,222,218,217,198,195,192,191,188,185,166,165,164,163,162,161,160,158,157,155,154};
    const uint16_t m_d_4[] PROGMEM = {230,229,228,227,221,220,219,218,217,194,189,166,165,164,163,162,161,160,159,158,157,156,155,154,153};
    const uint16_t m_d_5[] PROGMEM = {230,229,228,225,223,222,219,218,217,198,196,192,191,187,185,166,164,163,162,161,160,158,157,156,153};

    const uint16_t m_e_0[] PROGMEM = {26,27,28,29,30,32,33,34,35,36,37,38,57,63,64,70,89,90,91,92,93,94,95,97,98,99,100,101};
    const uint16_t m_e_1[] PROGMEM = {31,32,33,34,35,36,37,38,57,58,59,60,61,62,63,64,69};
    const uint16_t m_e_2[] PROGMEM = {26,27,31,32,35,36,37,38,57,60,63,64,66,67,70,89,90,93,94,95,96,97,101};
    const uint16_t m_e_3[] PROGMEM = {26,27,29,30,32,33,34,35,36,37,38,57,60,63,64,67,70,89,90,94,95,97,101}; 
    const uint16_t m_e_4[] PROGMEM = {25,26,27,28,29,30,31,32,33,34,35,36,37,38,61,66,89,90,91,92,93,99,100,101,102}; 
    const uint16_t m_e_5[] PROGMEM = {25,28,29,30,32,33,34,35,36,38,57,59,63,64,68,70,89,90,91,94,95,97,100,101,102}; 
    const uint16_t m_e_6[] PROGMEM = {26,29,30,32,33,34,35,37,38,57,60,63,64,67,70,89,90,91,92,93,94,95,97,98,99,100,101};
    const uint16_t m_e_7[] PROGMEM = {25,26,36,37,38,57,59,60,61,62,63,64,65,66,67,70,89,102};
    const uint16_t m_e_8[] PROGMEM = {26,27,29,30,32,33,34,35,36,37,38,57,60,63,64,67,70,89,90,91,92,93,94,95,97,98,100,101};  
    const uint16_t m_e_9[] PROGMEM = {26,27,28,29,30,32,33,34,35,36,37,38,57,60,63,64,67,70,89,90,91,92,94,95,97,100,101};

    const uint16_t sec_0[] PROGMEM = {247,232,215,200,183,168,151,136,119,104,87,72,55,40,23,8,248,231,216,199,184,167,152,135,120,103,88,71,56,39,24,7}; 

    
void loop() {
//Serial.println(analogRead(photoPin));
// Яркость свечения
  //if(analogRead(photoPin) < 270) FastLED.setBrightness(50); 
  //else if(analogRead(photoPin) < 470) FastLED.setBrightness(50);
  //else if(analogRead(photoPin) < 700)FastLED.setBrightness(50);
  //else FastLED.setBrightness(2);

  
// red the time
  t = rtc.getTime();
  
int x1 =(t.hour%100)/10;  // tens of hour
int y1 =t.hour%10;        // units of hour
int z1 =(t.min%100)/10;   // tens of minute
int w1 = t.min%10;        // units of minute

 minut = 10*z1+w1;
 ora = 10*x1+y1;

citirebutoane();

if (contor  != contor0)
leds[pgm_read_byte(&sec_0[contor])] = CRGB(255,255, 0);
FastLED.show(); 

contor0 = contor;
if (millis() - tpschimbare > tpsecunda)
{
contor++;
if (contor > sizeof(sec_0) / sizeof(int *)-1)
{
  FastLED.clear();
  afisare_ora(x1, y1, z1, w1);
  contor = 0;
}
tpschimbare = millis();
}

delay(50);
}  // end main loop

void citirebutoane() {
if (digitalRead(hplus) == LOW)
{
  Serial.print(ora);
  Serial.print("-> ");
  ora  = ora + 1;
  if (ora > 23) ora = 0;
  Serial.println(ora);
  rtc.setTime(ora, minut, 0);
  Serial.println("H+");
  delay(500);
  FastLED.clear();
  afisare_ora(ora/10, ora%10, minut/10, minut%10);
  contor = 0;
  contor0 = 60;
}

if (digitalRead(mplus) == LOW)
{
  Serial.print(minut);
  Serial.print("-> ");
  minut = minut + 1;
  if (minut > 59) minut = 0;
  Serial.println(minut);
  rtc.setTime(ora, minut, 0);
  Serial.println("M+");
  delay(500);
  FastLED.clear();
  afisare_ora(ora/10, ora%10, minut/10, minut%10);
  contor = 0;
  contor0 = 60;
}
}

void afisare_ora(int x, int y, int z, int w) {
  //tens of hours
    if(x==0){
                for (int i = 0; i <=sizeof(h_d_0) / sizeof(int *)-1; i++){
                      leds[pgm_read_byte(&h_d_0[i])] = CRGB::Red;
                }
                FastLED.show();    
    }
    else if(x==1){
                for (int i = 0; i <=sizeof(h_d_1) / sizeof(int *)-1; i++){
                      leds[pgm_read_byte(&h_d_1[i])] = CRGB::Red;
                }
                FastLED.show();
      
    }
    else if(x==2){
                for (int i = 0; i <=sizeof(h_d_2) / sizeof(int *)-1; i++){
                      leds[pgm_read_byte(&h_d_2[i])] = CRGB::Red;
                }
                FastLED.show();
    }

//units of hour
     if(y==0){  
                for (int i = 0; i <=sizeof(h_e_0) / sizeof(int *)-1; i++){
                      leds[pgm_read_byte(&h_e_0[i])] = CRGB::Red;
                }
               FastLED.show();
     }
     else if(y==1){  
                for (int i = 0; i <=sizeof(h_e_1) / sizeof(int *)-1; i++){
                      leds[pgm_read_byte(&h_e_1[i])] = CRGB::Red;
                }
               FastLED.show();
     }
     else if(y==2){  
                  for (int i = 0; i <=sizeof(h_e_2) / sizeof(int *)-1; i++){
                        leds[pgm_read_byte(&h_e_2[i])] = CRGB::Red;
                  }
                 FastLED.show();
       }
      else if(y==3){  
                  for (int i = 0; i <=sizeof(h_e_3) / sizeof(int *)-1; i++){
                        leds[pgm_read_byte(&h_e_3[i])] = CRGB::Red;
                  }
                 FastLED.show();
       }
      else if(y==4){  
                  for (int i = 0; i <=sizeof(h_e_4) / sizeof(int *)-1; i++){
                        leds[pgm_read_byte(&h_e_4[i])] = CRGB::Red;
                  }
                 FastLED.show();
       }
       else if(y==5){  
                  for (int i = 0; i <=sizeof(h_e_5) / sizeof(int *)-1; i++){
                        leds[pgm_read_byte(&h_e_5[i])] = CRGB::Red;
                  }
                 FastLED.show();
       }
      else if(y==6){  
                  for (int i = 0; i <=sizeof(h_e_6) / sizeof(int *)-1; i++){
                        leds[pgm_read_byte(&h_e_6[i])] = CRGB::Red;
                  }
                 FastLED.show();
       }
      else if(y==7){  
                  for (int i = 0; i <=sizeof(h_e_7) / sizeof(int *)-1; i++){
                        leds[pgm_read_byte(&h_e_7[i])] = CRGB::Red;
                  }
                 FastLED.show();
       }
      else if(y==8){  
                  for (int i = 0; i <=sizeof(h_e_8) / sizeof(int *)-1; i++){
                        leds[pgm_read_byte(&h_e_8[i])] = CRGB::Red;
                  }
                 FastLED.show();
       }
      else if(y==9){  
                  for (int i = 0; i <=sizeof(h_e_9) / sizeof(int *)-1; i++){
                        leds[pgm_read_byte(&h_e_9[i])] = CRGB::Red;
                  }
                 FastLED.show();
       }

 
 //tens of minutes
    if(z==0){
                for (int i = 0; i <=sizeof(m_d_0) / sizeof(int *)-1; i++){
                      leds[pgm_read_byte(&m_d_0[i])] = CRGB::Blue;
                }
                FastLED.show();      
    }
    else if(z==1){
                for (int i = 0; i <=sizeof(m_d_1) / sizeof(int *)-1; i++){
                      leds[pgm_read_byte(&m_d_1[i])] = CRGB::Blue;
                }
                FastLED.show();     
    }
    else if(z==2){
                for (int i = 0; i <=sizeof(m_d_2) / sizeof(int *)-1; i++){
                      leds[pgm_read_byte(&m_d_2[i])] = CRGB::Blue;
                }
                FastLED.show();      
    }
    else if(z==3){
                for (int i = 0; i <=sizeof(m_d_3) / sizeof(int *)-1; i++){
                      leds[pgm_read_byte(&m_d_3[i])] = CRGB::Blue;
                }
                FastLED.show();     
    }
    else if(z==4){
                for (int i = 0; i <=sizeof(m_d_4) / sizeof(int *)-1; i++){
                      leds[pgm_read_byte(&m_d_4[i])] = CRGB::Blue;
                }
                FastLED.show();      
    }
    else if(z==5){
                for (int i = 0; i <=sizeof(m_d_5) / sizeof(int *)-1; i++){
                      leds[pgm_read_byte(&m_d_5[i])] = CRGB::Blue;
                }
                FastLED.show();     
    }

 //units of minutes
    if(w==0){
                for (int i = 0; i <=sizeof(m_e_0) / sizeof(int *)-1; i++){
                      leds[pgm_read_byte(&m_e_0[i])] = CRGB::Blue;
                }
                FastLED.show();      
    }
    else if(w==1){
                for (int i = 0; i <=sizeof(m_e_1) / sizeof(int *)-1; i++){
                      leds[pgm_read_byte(&m_e_1[i])] = CRGB::Blue;
                }
                FastLED.show();      
    }
    else if(w==2){                   
                for (int i = 0; i <=sizeof(m_e_2) / sizeof(int *)-1; i++){
                      leds[pgm_read_byte(&m_e_2[i])] = CRGB::Blue;
                }
                FastLED.show();     
    }
    else if(w==3){
                for (int i = 0; i <=sizeof(m_e_3) / sizeof(int *)-1; i++){
                      leds[pgm_read_byte(&m_e_3[i])] = CRGB::Blue;
                }
                FastLED.show();      
    }
    else if(w==4){   
                for (int i = 0; i <=sizeof(m_e_4) / sizeof(int *)-1; i++){
                      leds[pgm_read_byte(&m_e_4[i])] = CRGB::Blue;
                }
                FastLED.show();      
    }
    else if(w==5){
                for (int i = 0; i <=sizeof(m_e_5) / sizeof(int *)-1; i++){
                      leds[pgm_read_byte(&m_e_5[i])] = CRGB::Blue;
                }
                FastLED.show();      
    }
    else if(w==6){
                for (int i = 0; i <=sizeof(m_e_6) / sizeof(int *)-1; i++){
                      leds[pgm_read_byte(&m_e_6[i])] = CRGB::Blue;
                }
                FastLED.show();      
    }
    else if(w==7){
                for (int i = 0; i <=sizeof(m_e_7) / sizeof(int *)-1; i++){
                      leds[pgm_read_byte(&m_e_7[i])] = CRGB::Blue;
                }
                FastLED.show();     
    }
    else if(w==8){
                for (int i = 0; i <=sizeof(m_e_8) / sizeof(int *)-1; i++){
                      leds[pgm_read_byte(&m_e_8[i])] = CRGB::Blue;
                }
                FastLED.show();      
    }
    else if(w==9){    
                for (int i = 0; i <=sizeof(m_e_9) / sizeof(int *)-1; i++){
                      leds[pgm_read_byte(&m_e_9[i])] = CRGB::Blue;
                }  
                FastLED.show();       
    }
}
