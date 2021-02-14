#include <ESPmDNS.h>
#include <ArduinoOTA.h>

const char *ssid = "ELTEX-05A2";
const char *password = "TG1B009912";

void wifiSetup() {  

  WiFi.begin ( ssid, password );
  
  while ( WiFi.status() != WL_CONNECTED ) {
   Serial.print (".");
    delay ( 500 );
    Serial.print("WiFi wait...");
  }

ArduinoOTA.setHostname("laser");
ArduinoOTA.begin();
MDNS.addServiceTxt("_arduino", "_tcp", "service", "MHC");
MDNS.addServiceTxt("_arduino", "_tcp", "type", "TestBoard");
MDNS.addServiceTxt("_arduino", "_tcp", "id", "ESP32-Test");

  Serial.println("WiFi started...");
}
