//
// Created by ubuntu on 07/11/18.
//

#ifndef WALL_E_SENSOR_COLLISION_H
#define WALL_E_SENSOR_COLLISION_H
#define DISTANCE_MIN_COLLISION 600

#include <Arduino.h>
#include "SensorInterface.h"
#include "../EnumDirection.h"
#include <map>
typedef std::pair<Direction, SensorInterface*> SensorCollisionPair;

class SensorCollision : public SensorInterface {
    public:
        SensorCollision();
        SensorCollision(int pin, Direction::_enumType direction);

        //get-set
        int getPin();
        Direction getDirection();

        void setPin(int pin);
        void setDirection(Direction::_enumType direction);

        int getValue();
        void init();
        SensorCollisionPair getSensorMappable();

    private:
        int pin;
        Direction direction;
};


#endif //WALL_E_SENSOR_COLLISION_H
