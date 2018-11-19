#include <FastLED.h>
#include <Ethernet.h>
#include <SPI.h>
#define DATA_PIN_1 3
#define CLOCK_PIN_1 4
#define DATA_PIN_2 5
#define CLOCK_PIN_2 6
#define NUM_LEDS 114
#define MAX_BRIGHTNESS 255

CRGB Scoring[NUM_LEDS];
CRGB Audience[NUM_LEDS];

byte mac[] = {0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED};
IPAddress ip(10,0,0,200);
unsigned int port = 5555;
//Buffer for reading data
char packetBuffer[UDP_TX_PACKET_MAX_SIZE];

Ethernet udp;

void setup() {
FastLED.addLeds<WS2801, DATA_PIN_1, CLOCK_PIN_1>(Scoring, NUM_LEDS);
FastLED.addLeds<WS2801, DATA_PIN_2, CLOCK_PIN_2>(Audience, NUM_LEDS);
Ethernet.begin(mac, ip);
Serial.begin(9600);
while(!Serial){
  }
  ;
}
udp.begin;


void loop() {
   int packetSize = Udp.parsePacket();
   Udp.read(packetBuffer, UDP_TX_PACKET_MAX_SIZE);
   if packetBuffer = "LLL"{
    
    }

    if packetBuffer = "RRR"{}

    if packetBuffer = "RLR"{}

    if packetBuffer = "LRL"{}
   
 
}



//Force Mode
void ForceModeAudience(uint32_t color){
  int wait = 5;
  FastLED.clear();
  FastLED.setBrightness(MAX_BRIGHTNESS);

  for(int i = 0; i < NUM_LEDS; i++){
    Audience[i] = color;
    FastLED.show();
    delay(wait);
    Audience[i] = CRGB::Black;
    }
    return;
  }

//Static Color Mode
void SingleColorAudience(uint32_t color){
  FastLED.clear();
  FastLED.setBrightness(MAX_BRIGHTNESS);
  Audience[NUM_LEDS] = color;
  }

//Ownership Mode
void OwnershipModeAudience(uint32_t color){
  
  }

//Not Ownend Mode
void NotOwnedModeAudience(uint32_t color){}

//Blue Warmup Mode
void BlueWarmUpAudience(){
  int speed = 5;
  int direction = 0;

  for(int i = 0; i < NUM_LEDS; i++){
    if(direction == 0){
      Audience[i] = CRGB::Blue;
      }
      FastLED.show();
      delay(speed);
    }
  }

//Red Warmup Mode
void RedWarmUpAudience(){
  int speed = 5;
  int direction = 0;

  for(int i = 0; i < NUM_LEDS; i++){
    if(direction == 0){
      Audience[i] = CRGB::Red;
      }
      FastLED.show();
      delay(speed);
    }
  }



  //Force Mode
void ForceModeAudience(uint32_t color){
  int wait = 5;
  FastLED.clear();
  FastLED.setBrightness(MAX_BRIGHTNESS);

  for(int i = 0; i < NUM_LEDS; i++){
    Audience[i] = color;
    FastLED.show();
    delay(wait);
    Audience[i] = CRGB::Black;
    }
    return;
  }

//Static Color Mode
void SingleColorAudience(uint32_t color){
  FastLED.clear();
  FastLED.setBrightness(MAX_BRIGHTNESS);
  Audience[NUM_LEDS] = color;
  }

//Ownership Mode
void OwnershipModeAudience(uint32_t color){
  
  }

//Not Ownend Mode
void NotOwnedModeAudience(uint32_t color){}

//Blue Warmup Mode
void BlueWarmUpAudience(){
  int speed = 5;
  int direction = 0;

  for(int i = 0; i < NUM_LEDS; i++){
    if(direction == 0){
      Audience[i] = CRGB::Blue;
      }
      FastLED.show();
      delay(speed);
    }
  }

//Red Warmup Mode
void RedWarmUpScoring(){
  int speed = 5;
  int direction = 0;

  for(int i = 0; i < NUM_LEDS; i++){
    if(direction == 0){
      Audience[i] = CRGB::Red;
      }
      FastLED.show();
      delay(speed);
    }
  }
