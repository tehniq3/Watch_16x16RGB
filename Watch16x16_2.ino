// http://arduino-kid.ru/blog/chasy-na-svetodiodakh-ws2812
// https://youtu.be/1oqfN3A-YfY
// v.1 - added clock adjustment by Nicu FLORICA (niq_ro)
// v.2 - added outside second line and moved numbers (regenerate others)

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
unsigned long tpsecunda = 1000;

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


  rtc.begin();                         
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
