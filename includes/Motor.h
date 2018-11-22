//
// Created by ubuntu on 07/11/18.
//

#ifndef WALL_E_MOTOR_CONTROL_H
#define WALL_E_MOTOR_CONTROL_H


#include <Arduino.h>
#include "SerialCom.h"
#include <SoftwareSerial.h>
#include <RoboClaw.h>
#include "../includes/Motor.h"
#include "../includes/EnumMotor.h"

class Motor {

public:
    Motor(MotorName::_enumType motorName, RoboClaw* roboClaw);

    void init();
    void avancer(int pwm);
    void reculer(int pwm);

private:
    RoboClaw* roboClaw;
    MotorName motorName;
};


#endif //WALL_E_MOTOR_CONTROL_H
