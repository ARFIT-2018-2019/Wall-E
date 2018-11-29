//
// Created by Alexandre on 29/11/2018.
//

#ifndef WALL_E_POSITION_H
#define WALL_E_POSITION_H

#include <Arduino.h>
#include "../SerialCom.h"
#include <SoftwareSerial.h>
#include <RoboClaw.h>
#include "EnumMotor.h"

class Position {

public:
    Position();
    Position(float posDepartX, float posDepartY);

    void init();

    float getPosX();
    float getPosY();
    float getRot();

private:
    float x;
    float y;
    float angle;

};

#endif //WALL_E_POSITION_H
