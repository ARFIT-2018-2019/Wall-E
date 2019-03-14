//
// Created by ubuntu on 07/11/18.
//

#ifndef WALL_E_SENSOR_COLLISION_H
#define WALL_E_SENSOR_COLLISION_H
#define DISTANCE_MIN_COLLISION 600

#include <Arduino.h>
#include "Thread.h"
#include <DueTimer.h>
#include "../EnumDirection.h"

class SensorCollision : public Thread {
    public:
        SensorCollision();
        SensorCollision(int pin, DirectionEnum directionEnum);

        //get-set
        int getPin();
        Direction getDirection();

        void setPin(int pin);
        void setDirection(DirectionEnum directionEnum);

        int getValue();
        int readValue();
        void init();

        void run();
    private:
        int pin;
        Direction direction;
        int value;
};


#endif //WALL_E_SENSOR_COLLISION_H
