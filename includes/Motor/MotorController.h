//
// Created by ubuntu on 07/11/18.
//

#ifndef WALL_E_MOTOR_CONTROL_H
#define WALL_E_MOTOR_CONTROL_H
#define MOTOR_ADRESSE 0x80

#include <Arduino.h>
#include <RoboClaw.h>
#include "../Position/Position.h"
#include "Odometrie.h"

class MotorController {

    public:
        MotorController(Position* positionRobot);
      
        static void stop();
        void avancer(int pwm);
        void reculer(int pwm);
        void allerA(Position position);
        void tournerDe(float deg);

        Odometrie getOdometrie();
        void sendCommandToRoboClaw(float cmByS);   

        static RoboClaw* roboClaw;
    
    private : 
        Odometrie odometrie;
};
#endif //WALL_E_MOTOR_CONTROL_H
