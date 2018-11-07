//
// Created by ubuntu on 07/11/18.
//

#ifndef WALL_E_SENSOR_COLLISION_H
#define WALL_E_SENSOR_COLLISION_H
#define DISTANCE_MIN_COLLISION 600

#include <Arduino.h>
#include "SensorInterface.h"
#include "EnumDirection.h"

class SensorCollision : public SensorInterface {

public:
    SensorCollision();
    SensorCollision(int pin, Direction direction);

    //get-set
    int getPin();
    Direction  getDirection();

    void setPin(int pin);
    void setDirection(Direction direction);

    int getValue();
    void init();

private:
    int pin;
    Direction direction;
};


#endif //WALL_E_SENSOR_COLLISION_H
