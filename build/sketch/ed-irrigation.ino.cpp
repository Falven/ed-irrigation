#line 1 "c:\\source\\repos\\ed-irrigation\\ed-irrigation.ino"
// "Copyright 2021 Francisco Aguilera"

#include <Arduino.h>

#include "src/arduino_secrets.hpp"
#include "src/debug.hpp"
#include "src/http-server.hpp"
#include "src/wifi-module.hpp"
#include "src/motor-driver.hpp"

using namespace falven::ad;

MotorDriver pumpDriver(SECRET_MOTOR_IN1_PIN, SECRET_MOTOR_IN2_PIN,
                       SECRET_MOTOR_PWM_PIN);
WifiModule wiFiModule(SECRET_SSID, SECRET_PASSWORD, SECRET_HOSTNAME);
HttpServer irrigationServer(SECRET_SERVER_PORT);

#line 18 "c:\\source\\repos\\ed-irrigation\\ed-irrigation.ino"
void setup();
#line 27 "c:\\source\\repos\\ed-irrigation\\ed-irrigation.ino"
void loop();
#line 18 "c:\\source\\repos\\ed-irrigation\\ed-irrigation.ino"
void setup() {
  DEBUG_BEGIN(9600u);
  DEBUG_LOCATION();

  pumpDriver.SetupPins();
  wiFiModule.Connect();
  irrigationServer.Start();
}

void loop() { irrigationServer.Listen(); }

