//
// Created by ubuntu on 07/11/18.
//

#include "../includes/SensorCollision.h"

SensorCollision::SensorCollision() {}

SensorCollision::SensorCollision(int pin, Direction direction) {
    this->pin = pin;
    this->direction = direction;

    this->init();
}

void SensorCollision::init(){
    pinMode(pin, INPUT);
    serialCom->sendMessage("Sensor init", "SensorCollision "+toString(direction)+ "on "+String(pin));
}

Direction SensorCollision::getDirection() {
    return this->direction;
}

int SensorCollision::getPin() {
    return this->getPin();
}

void SensorCollision::setDirection(Direction direction) {
    this->direction = direction;
}

void SensorCollision::setPin(int pin) {
    this->pin = pin;
}

int SensorCollision::getValue() {
    if (analogRead(this->pin) > DISTANCE_MIN_COLLISION) {
        return 1;
    } else {
        return 0;
    }
}


