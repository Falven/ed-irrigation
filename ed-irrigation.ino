// "Copyright 2021 Francisco Aguilera"

#include <Arduino.h>

#include "arduino_secrets.hpp"
#include "debug.hpp"
#include "http-server.hpp"
#include "motor-driver.hpp"
#include "wifi-module.hpp"

falven::ad::HttpServer
    irrigationServer(  // NOLINT(cppcoreguidelines-avoid-non-const-global-variables)
        SECRET_SERVER_PORT);
falven::ad::MotorDriver
    pumpDriver(  // NOLINT(cppcoreguidelines-avoid-non-const-global-variables)
        SECRET_MOTOR_IN1_PIN, SECRET_MOTOR_IN2_PIN, SECRET_MOTOR_PWM_PIN);
falven::ad::WifiModule
    wiFiModule(  // NOLINT(cppcoreguidelines-avoid-non-const-global-variables)
        SECRET_SSID, SECRET_PASSWORD, SECRET_HOSTNAME);

void setup() {
  DEBUG_BEGIN(9600U);
  DEBUG_LOCATION();

  pumpDriver.SetupPins();
  wiFiModule.Connect();
  irrigationServer.Start();
}

void loop() { irrigationServer.Listen(); }
