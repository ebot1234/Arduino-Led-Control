#include <SPI.h>
#include <Ethernet.h>

byte MAC[] = {
  0x4A, 0x52, 0x79, 0xD8, 0xCE, 0x9F};

IPAddress ip(10, 0, 0, 23);
unsigned int local_port = 5555;

EthernetUDP Udp;

char packetBuffer[UDP_TX_PACKET_MAX_SIZE];


void setup() {
 Ethernet.begin(MAC, ip);
 Udp.begin(local_port);
 
}

void loop() {
 int packetSize = Udp.parsePacket();
 if(packetSize){
  Serial.print("Received Packet of size:");
  Serial.print(packetSize);
  Serial.print("from:");
  IPAddress remote = Udp.remoteIP();
  for(int i = 0; i < 4; i++){
    Serial.print(remote[i], DEC);
    if(i < 3){
      Serial.print(".");
      }
    }
    Serial.print(", port");
    Serial.println(Udp.remotePort());

    Udp.read(packetBuffer, UDP_TX_PACKET_MAX_SIZE);
    Serial.print("Contents:");
    Serial.print(packetBuffer);
  }

}
