


#include <Ethernet.h>
#include <EthernetClient.h>
#include <EthernetServer.h>


#include <FastLED.h>
#include <EthernetUdp.h>
#include <SPI.h>
#include <Udp.h>

//Led Configuration Varibles
#define DATA_PIN_1 3
#define CLOCK_PIN_1 4
#define DATA_PIN_2 5
#define CLOCK_PIN_2 6
#define NUM_LEDS 114
#define MAX_BRIGHTNESS 255

//2018 led modes as enum values
enum LedModes{Red_Force, Blue_Force, Blue_Boost, Red_Boost, Green, Awards, WarmUp_1, WarmUp_2};
EthernetUDP udp;
//Led string arrays
CRGB Scoring[NUM_LEDS];
CRGB Audience[NUM_LEDS];

byte mac[] = {0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED};
IPAddress ip(10,0,0,200);
unsigned int port = 5555;
//Buffer for reading data
char packetBuffer[UDP_TX_PACKET_MAX_SIZE];

EthernetUdp* EthernetUdp;


void setup() {
FastLED.addLeds<WS2801, DATA_PIN_1, CLOCK_PIN_1>(Scoring, NUM_LEDS);
FastLED.addLeds<WS2801, DATA_PIN_2, CLOCK_PIN_2>(Audience, NUM_LEDS);
Ethernet.begin(mac, ip);
Serial.begin(9600);
EthernetUdp.begin(port);

while(!Serial){
  }
  ;
}



void loop() {
  
   if (packetBuffer == "LLL"){
    updateLedModes(WarmUp_1);
    }
    else if (packetBuffer == "RedForce"){
      }
      else if (packetBuffer == "BlueForce"){
        };
     

    if (packetBuffer == "RRR"){
      };

    if (packetBuffer == "RLR"){
     
      };

    if (packetBuffer == "LRL"){
      updateLedModes(WarmUp_1);
      };

    if (packetBuffer == "Awards"){
      updateLedModes(Awards);
      };
   
 
}

void updateLedModes(LedModes){
  switch (LedModes){
    case WarmUp_1:
   //Red on left, Blue on right
   break;
   case WarmUp_2:
   //Red on right, Blue on left
   break;
   case Awards:
   SingleColorAudience(CRGB::Red);
   SingleColorScoring(CRGB::Blue);
   break;
   case Red_Force
   break;
   default:
   LedModes = LedModes.Awards;
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

void SingleColorScoring(uint32_t color){
  FastLED.clear();
  FastLED.setBrightness(MAX_BRIGHTNESS);
  Scoring[NUM_LEDS] = color;
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
      Scoring[i] = CRGB::Red;
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
