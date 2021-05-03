// "Copyright 2021 Francisco Aguilera"

#ifndef INCLUDE_MOTOR_DRIVER_HPP_
#define INCLUDE_MOTOR_DRIVER_HPP_

#include <Arduino.h>

namespace falven {
namespace ad {

/**
 * @brief Object used to drive a <a
 * href="https://wiki.dfrobot.com/15A_Single_DC_Motor_Driver_SKU__DRI0042">DRI0042
 * 15A Single DC Motor Driver</a> from an Arduino.
 *
 * Control Method
 * IN1 IN2 PWM  OUT1, OUT2 Motor Behavior
 * 0   0   x    Stop
 * 1   1   x    Vacant
 * 1   0   1    Forward 100%
 * 0   1   1    Reverse 100%
 * 1   0   PWM  Forward at PWM speed
 * 0   1   PWM  Reverse at PWM speed
 *
 */
class MotorDriver {
 public:
  static const uint32_t kMinBrakeTime = 100UL;

  /**
   * @brief Construct a new Motor Driver object
   *
   * @param in1 Motor steering control signal input 1 pin
   * @param in2 Motor steering control signal input 2 pin
   * @param pwm Speed control signal input pin
   * @param brake_time How long to brake the motor before switching directions.
   * Note: To protect your motor, before switching the motor steering direction,
   * make sure firstly to BRAKE motor by setting IN1 - 0 & IN2 - 0, especially
   * when the PWM was set as 100%, full speed. And the suggestion time to brake
   * is >0.1S, depending on your motor.Tutorial
   */
  MotorDriver(pin_size_t in1, pin_size_t in2, pin_size_t pwm,
              uint32_t brake_time = kMinBrakeTime);

  void SetupPins();

  /**
   * @brief Stops the motor.
   *
   */
  void Stop();

  /**
   * @brief Moves the motor in the forward direction.
   * Note: To protect your motor, before switching the motor steering direction,
   * make sure to first call stop().
   * @param speed Integer between 0 and 255 for how fast the motor should spin.
   */
  void DriveForward(int speed);

  /**
   * @brief Moves the motor in the reverse direction.
   * Note: To protect your motor, before switching the motor steering direction,
   * make sure to first call stop().
   * @param speed Integer between 0 and 255 for how fast the motor should spin.
   */
  void DriveReverse(int speed);

 private:
  typedef enum MotorDirection { STOPPED, FORWARD, REVERSE } MotorDirection;

  const pin_size_t kIn1;
  const pin_size_t kIn2;
  const pin_size_t kPwm;
  const uint32_t kBraketime;

  bool pins_are_set_up_;
  MotorDriver::MotorDirection current_motor_direction_;
};

}  // namespace ad
}  // namespace falven

#endif  // INCLUDE_MOTOR_DRIVER_HPP_
