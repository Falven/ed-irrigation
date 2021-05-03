#line 1 "c:\\source\\repos\\ed-irrigation\\src\\wifi-module.cpp"
// "Copyright 2021 Francisco Aguilera"

#include "wifi-module.hpp"

#include <Arduino.h>
#include <SPI.h>
#include <WiFi.h>
#include <WiFiNINA.h>

#include "debug.hpp"

namespace falven {
namespace ad {

void WifiModule::PollModule() {
  DEBUG_LOCATION();
  if (WiFi.status() == WL_NO_MODULE) {
    while (true) {
    }
  }
}

void WifiModule::CheckFirmware() {
  DEBUG_LOCATION();
  arduino::String fv = WiFi.firmwareVersion();
  arduino::String latestFv = WIFI_FIRMWARE_LATEST_VERSION;
  if (fv < latestFv) {
  }
}

void WifiModule::SetHostname() {
  DEBUG_LOCATION();
  WiFi.setHostname(kHostName);
}

void WifiModule::PrintMacAddress() {
  byte mac[6];
  WiFi.macAddress(mac);
  Serial.print("MAC ADDRESS: ");
  Serial.print(mac[5], HEX);
  Serial.print(":");
  Serial.print(mac[4], HEX);
  Serial.print(":");
  Serial.print(mac[3], HEX);
  Serial.print(":");
  Serial.print(mac[2], HEX);
  Serial.print(":");
  Serial.print(mac[1], HEX);
  Serial.print(":");
  Serial.println(mac[0], HEX);
  // create mac address class that inherits from printable.
}

WifiModule::WifiModule(const char *ssid, const char *pass, const char *hostName,
                       const uint32_t connectionDelay)
    : kSsid(ssid),
      kPass(pass),
      kHostName(hostName),
      kConnectionDelay(connectionDelay),
      status_(WL_IDLE_STATUS) {}

void WifiModule::Configure() {
  DEBUG_LOCATION();
  PollModule();
  CheckFirmware();
  SetHostname();
}

void WifiModule::Connect() {
  Configure();
  DEBUG_PRINTLN("Connecting to: " << kSsid);
  while (status_ != WL_CONNECTED) {
    status_ = WiFi.begin(kSsid, kPass);
    delay(kConnectionDelay);
  }
  DEBUG_PRINTLN("Connected.");
  DEBUG_PRINTLN("Signal strength: " << WiFi.RSSI() << " dBm");
  DEBUG_PRINTLN("IP: " << WiFi.localIP());
}

}  // namespace ad
}  // namespace falven
