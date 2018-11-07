//
// Created by ubuntu on 07/11/18.
//

#ifndef WALL_E_SENSOR_COLLISION_H
#define WALL_E_SENSOR_COLLISION_H
#define DISTANCE_MIN_COLLISION 600

#include <Arduino.h>
#include "SerialCom.h"
#include "SensorInterface.h"
#include "EnumDirection.h"

class SensorCollision : public SensorInterface {

public:
    SensorCollision();
    SensorCollision(int pin, Direction::_enumType direction, SerialCom* serialCom);

    //get-set
    int getPin();
    Direction getDirection();
    SerialCom* getSerialCom();

    void setPin(int pin);
    void setDirection(Direction::_enumType direction);
    void setSerialCom(SerialCom* serialCom);


    int getValue();
    void init();

private:
    int pin;
    Direction direction;
    SerialCom* serialCom;
};


#endif //WALL_E_SENSOR_COLLISION_H
