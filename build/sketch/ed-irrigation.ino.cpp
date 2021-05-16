#line 1 "c:\\source\\repos\\ed-irrigation\\ed-irrigation.ino"
// "Copyright 2021 Francisco Aguilera"

#include <Arduino.h>

#include "include/arduino_secrets.hpp"
#include "include/debug.hpp"
#include "include/http-server.hpp"
#include "include/motor-driver.hpp"
#include "include/wifi-module.hpp"

falven::ad::HttpServer
    irrigationServer(  // NOLINT(cppcoreguidelines-avoid-non-const-global-variables)
        SECRET_SERVER_PORT);
falven::ad::MotorDriver
    pumpDriver(  // NOLINT(cppcoreguidelines-avoid-non-const-global-variables)
        SECRET_MOTOR_IN1_PIN, SECRET_MOTOR_IN2_PIN, SECRET_MOTOR_PWM_PIN);
falven::ad::WifiModule
    wiFiModule(  // NOLINT(cppcoreguidelines-avoid-non-const-global-variables)
        SECRET_SSID, SECRET_PASSWORD, SECRET_HOSTNAME);

#line 21 "c:\\source\\repos\\ed-irrigation\\ed-irrigation.ino"
void setup();
#line 30 "c:\\source\\repos\\ed-irrigation\\ed-irrigation.ino"
void loop();
#line 21 "c:\\source\\repos\\ed-irrigation\\ed-irrigation.ino"
void setup() {
  DEBUG_BEGIN(9600U);
  DEBUG_LOCATION();

  pumpDriver.SetupPins();
  wiFiModule.Connect();
  irrigationServer.Start();
}

void loop() { irrigationServer.Listen(); }

