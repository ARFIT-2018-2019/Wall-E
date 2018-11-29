//
// Created by ubuntu on 07/11/18.
//

#ifndef WALL_E_MOTOR_CONTROL_H
#define WALL_E_MOTOR_CONTROL_H


#include <Arduino.h>
#include "../SerialCom.h"
#include <SoftwareSerial.h>
#include <RoboClaw.h>
#include "EnumEnumMotorName.h"
#include "Positionnement/Position.h"

class MotorController {

    public:
        MotorController();
        MotorController(EnumMotorName::_enumType EnumMotorName, RoboClaw* roboClaw);

        void init();
        void avancer(int pwm);
        void reculer(int pwm);
        void allerA(int x, int y);
        void TournerDe(float deg);

    private:
        RoboClaw* roboClaw;
        EnumMotorName EnumMotorName;
};


#endif //WALL_E_MOTOR_CONTROL_H
