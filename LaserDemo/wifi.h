//#include <WiFiEsp.h>
//#include <WiFiEspClient.h>
//#include <WiFiEspServer.h>
//#include <WiFiEspUdp.h>

#include <ESPmDNS.h>
//#include <WiFiUdp.h>
#include <ArduinoOTA.h>

const char *ssid = "ELTEX-05A2";
//const char *password = "TG1B009912";
const char *password = "TG1B009900";
void wifiSetup() {  

  WiFi.begin ( ssid, password );
  
  while ( WiFi.status() != WL_CONNECTED ) {
   Serial.print (".");
    delay ( 500 );
    Serial.print("WiFi wait...");
  }

//  MDNS.begin ( "laser" );

ArduinoOTA.setHostname("laser");
ArduinoOTA.begin();
// addd some more service text
MDNS.addServiceTxt("_arduino", "_tcp", "service", "MHC");
MDNS.addServiceTxt("_arduino", "_tcp", "type", "TestBoard");
MDNS.addServiceTxt("_arduino", "_tcp", "id", "ESP32-Test");

//  ArduinoOTA.setHostname("laser");
//  ArduinoOTA.begin();

  Serial.println("WiFi started...");
}
