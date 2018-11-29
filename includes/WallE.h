//
// Created by ubuntu on 22/11/18.
//

#ifndef WALL_E_WALLE_H
#define WALL_E_WALLE_H

#include <ArduinoSTL.h>
#include <Arduino.h>
#include <map>

#include "./EnumDirection.h"

#include "Sensor/SensorCollision.h"
#include "./SerialCom.h"
#include "Motor/MotorController.h"

#include "Positionnement/Position.h"

class WallE {
    public:
        WallE();
        static SerialCom serialCom;
        static RoboClaw robotClaw;
        static MotorController motorController;

        static Position position;

        int init(); //return 1 success else return 0;
        void run(); //lance le robot
    private :
        SoftwareSerial softwareSerial = SoftwareSerial(10,11);
        std::map<Direction, SensorInterface*> mapSensorCollision;
};
#endif //WALL_E_WALLE_H
