// "Copyright 2021 Francisco Aguilera"

#include "../include/motor-driver.hpp"

#include <Arduino.h>

#include "debug.hpp"

namespace falven {
namespace ad {

MotorDriver::MotorDriver(pin_size_t in1, pin_size_t in2, pin_size_t pwm,
                         uint32_t brake_time)
    : kIn1(in1),
      kIn2(in2),
      kPwm(pwm),
      kBraketime(brake_time < kMinBrakeTime ? kMinBrakeTime : brake_time),
      pins_are_set_up_(false) {}

void MotorDriver::SetupPins() {
  DEBUG_LOCATION();
  pinMode(kIn1, PinMode::OUTPUT);
  pinMode(kIn2, PinMode::OUTPUT);
  pinMode(kPwm, PinMode::OUTPUT);
  pins_are_set_up_ = true;
  Stop();
}

void MotorDriver::Stop() {
  if (pins_are_set_up_) {
    DEBUG_LOCATION();
    digitalWrite(kIn1, PinStatus::LOW);
    digitalWrite(kIn2, PinStatus::LOW);
    analogWrite(kPwm, 0u);
    current_motor_direction_ = MotorDriver::MotorDirection::STOPPED;
  }
}

void MotorDriver::DriveForward(int speed) {
  DEBUG_LOCATION();
  if (pins_are_set_up_) {
    if (current_motor_direction_ == MotorDriver::MotorDirection::REVERSE) {
      Stop();
      delay(kBraketime);
    }
    digitalWrite(kIn2, PinStatus::LOW);
    digitalWrite(kIn1, PinStatus::HIGH);
    analogWrite(kPwm, speed);
    current_motor_direction_ = MotorDriver::MotorDirection::FORWARD;
  }
}

void MotorDriver::DriveReverse(int speed) {
  DEBUG_LOCATION();
  if (pins_are_set_up_) {
    if (current_motor_direction_ == MotorDriver::MotorDirection::FORWARD) {
      Stop();
      delay(kBraketime);
    }
    digitalWrite(kIn1, PinStatus::LOW);
    digitalWrite(kIn2, PinStatus::HIGH);
    analogWrite(kPwm, speed);
    current_motor_direction_ = MotorDriver::MotorDirection::REVERSE;
  }
}

}  // namespace ad
}  // namespace falven
