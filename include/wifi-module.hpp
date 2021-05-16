// "Copyright 2021 Francisco Aguilera"

#ifndef SRC_WIFI_MODULE_HPP_
#define SRC_WIFI_MODULE_HPP_

#include <Arduino.h>
#include <SPI.h>
#include <WiFiNINA.h>

namespace falven {
namespace ad {

/**
 * @brief Object used to setup the WiFi module on an Arduino UNO WiFi Rev.2,
 * Arduino NANO 33 IoT, Arduino MKR 1010 or Arduino MKR VIDOR 4000 WiFi.
 *
 */
class WifiModule {
 public:
  constexpr static const uint32_t kDefaultConnectionDelay = 10000UL;

  WifiModule(const char *ssid, const char *pass, const char *host_name,
             const uint32_t connection_delay = kDefaultConnectionDelay);

  void Configure();
  void Connect();

 private:
  const char *kSsid;
  const char *kPass;
  const char *kHostName;
  const uint32_t kConnectionDelay;

  int status_;

  void PollModule();
  void CheckFirmware();
  void SetHostname();
  void PrintMacAddress();
};

}  // namespace ad
}  // namespace falven

#endif  // SRC_WIFI_MODULE_HPP_
