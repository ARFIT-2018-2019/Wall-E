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

    void init();

    int getPosX();
    int getPosY();

private:

};

#endif //WALL_E_POSITION_H
