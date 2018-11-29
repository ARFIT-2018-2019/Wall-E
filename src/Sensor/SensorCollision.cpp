//
// Created by ubuntu on 07/11/18.
//

#include "../../includes/Sensor/SensorCollision.h"
#include <map>

#define DEFAULT_KEY_SENSOR_COLLISION
//==================================================
//================== CONSTRUCTORS ==================
//==================================================
SensorCollision::SensorCollision(){}
SensorCollision::SensorCollision(int pin, Direction::_enumType direction) {
    this->pin = pin;
    this->direction = Direction(direction);
}

//==================================================
//===================== METIER =====================
//============================= =====================

void SensorCollision::init() {
    pinMode(pin, INPUT);
    wallE::serialCom->sendMessage(DEFAULT_KEY_SENSOR_COLLISION, "SensorCollision " + this->direction.toString() + " on " + String(pin));
}
int SensorCollision::getValue() {
    return analogRead(this->pin);
/*    if (analogRead(this->pin) > DISTANCE_MIN_COLLISION) {
        return 1;
    } else {
        return 0;
    }*/
}

//==================================================
//================ GETTER - SETTER =================
//==================================================

Direction SensorCollision::getDirection() {
    return this->direction;
}
void SensorCollision::setDirection(Direction::_enumType direction) {
    this->direction = Direction(direction);
}
int SensorCollision::getPin() {
    return this->getPin();
}
void SensorCollision::setPin(int pin) {
    this->pin = pin;
}

SensorCollisionPair getSensorMappable(){
    return SensorCollisionPair(this->direction, this);
}