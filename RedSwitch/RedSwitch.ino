#include<SPI.h>
#include<Ethernet.h>
#include<EthernetUdp.h>
#include<FastLED.h>


//Mac Address for the Ethernet Sheild
byte mac[] = {0x05, 0xAG, 0x98, 0xE6, 0xER, 0x21};
//Ip address
IPAddress ip(10, 0, 100, 25);
//Port
const int localport = 80;
//Reply and receive buffers
char packetBuffer[UDP_TX_PACKET_MAX_SIZE];
char ReplyBuffer[] = "acknowledged";
//Instance of the EthernetUDP library
EthernetUDP Udp;
#define DATA_PIN 7
#define NUM_LEDS 110

CRGB leds[NUM_LEDS];


int fadeAmount = 8;
unsigned long fadeEvery = 10;
int brightness = 2;
unsigned long previousMillis;


void setup() {
  Ethernet.begin(mac, ip);
  Udp.begin(localport);
  Serial.begin(9600);
  Serial.println("Started Controller");

  Serial.println("Setup Led Config");
  FastLED.addLeds<WS2812B, DATA_PIN, GRB>(leds, NUM_LEDS);

  singleColor(CRGB::Black);
}
/*pulseColor(0xff, 0x00, 0x00);//Red
  delay(500);
  pulseColor(0x00, 0x00, 0xff);//Green
  delay(500);*/

void loop() {
  int packetSize = Udp.parsePacket();
  if (packetSize) {
    Udp.read(packetBuffer, UDP_TX_PACKET_MAX_SIZE);
    Serial.println(packetBuffer);

    if (packetBuffer[0] == 'G') {
      singleColor(CRGB::Green);
    }
    if (packetBuffer[0] == '1') { //LRL
      colorWipe(0x00, 0x00, 0xff, 50);
      singleColor(CRGB::Blue);
    }
    if (packetBuffer[0] == '2') { //RRR
      colorWipe(0xff, 0x00, 0x00, 50);
      singleColor(CRGB::Red);
    }
    if (packetBuffer[0] == '3') { //LLL
      colorWipe(0x00, 0x00, 0xff, 50);
      singleColor(CRGB::Blue);
    }
    if (packetBuffer[0] == '4') { //RLR
      colorWipe(0xff, 0x00, 0x00, 50);
      singleColor(CRGB::Red);
    }


    if (packetBuffer[0] == 'R') {
      singleColor(CRGB::Red);
    }
    if (packetBuffer[0] == 'B') {
      singleColor(CRGB::Blue);
    }
    if (packetBuffer[0] == 'N') {
      singleColor(CRGB::Teal);
    }
  }

  delay(10);


}

void colorWipe(byte red, byte green, byte blue, int SpeedDelay) {
  for (uint16_t i = 0; i < NUM_LEDS; i++) {
    setPixel(i, red, green, blue);
    FastLED.show();
    delay(SpeedDelay);
  }
}

void chase(CRGB color, int speed, int direction ) {
 for (int i = 0; i < NUM_LEDS; i++) {
    if (direction == 0) {
      leds[i] = color;
    }
    FastLED.show();
    delay(speed);
  }
}


void singleColor(CRGB color) {
  for (int i = 0; i < NUM_LEDS; i++) {
    leds[i] = color;
  }
  FastLED.show();
}



void setPixel(int Pixel, byte red, byte green, byte blue) {
  leds[Pixel].r = red;
  leds[Pixel].g = green;
  leds[Pixel].b = blue;
}

void setAll(byte red, byte green, byte blue) {
  for (int i = 0; i < NUM_LEDS; i++ ) {
    setPixel(i, red, green, blue);
  }
  FastLED.show();
}
