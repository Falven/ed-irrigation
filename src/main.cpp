// "Copyright 2021 Francisco Aguilera"

#include <Arduino.h>

#include "arduino_secrets.h"
#include "src/motor-driver.hpp"
#include "src/wifi-module.hpp"
#include "src/http-server.hpp"
#include "src/debug.hpp"

using namespace falven::ad;

MotorDriver pumpDriver(SECRET_MOTOR_IN1_PIN, SECRET_MOTOR_IN2_PIN,
                       SECRET_MOTOR_PWM_PIN);
WifiModule wiFiModule(SECRET_SSID, SECRET_PASSWORD, SECRET_HOSTNAME);
HttpServer irrigationServer(SECRET_SERVER_PORT);

void setup() {
  DEBUG_BEGIN(9600u);
  DEBUG_LOCATION();

  pumpDriver.SetupPins();
  wiFiModule.Connect();
  irrigationServer.Start();
}

void loop() { irrigationServer.Listen(); }
