//
// Created by ubuntu on 07/11/18.
//

#include "../includes/SensorCollision.h"

//==================================================
//================== CONSTRUCTORS ==================
//==================================================
SensorCollision::SensorCollision(){}

SensorCollision::SensorCollision(int pin, Direction::_enumType direction, SerialCom* serialCom) {
    this->pin = pin;
    this->direction = Direction(direction);
    this->serialCom = serialCom;
}

//==================================================
//================ GETTER - SETTER =================
//==================================================

int SensorCollision::getPin() {
    return this->getPin();
}

SerialCom* SensorCollision::getSerialCom() {
    return this->serialCom;
}

Direction SensorCollision::getDirection() {
    return this->direction;
}


void SensorCollision::setDirection(Direction::_enumType direction) {
    this->direction = Direction(direction);
}

void SensorCollision::setPin(int pin) {
    this->pin = pin;
}

void SensorCollision::setSerialCom(SerialCom *serialCom) {
    this->serialCom = serialCom;
}

//==================================================
//===================== METIER =====================
//============================= =====================

void SensorCollision::init(){
    pinMode(pin, INPUT);
    this->serialCom->sendMessage("Sensor init", "SensorCollision " + this->direction.toString() + " on " + String(pin));
}

int SensorCollision::getValue() {
    return analogRead(this->pin);
/*    if (analogRead(this->pin) > DISTANCE_MIN_COLLISION) {
        return 1;
    } else {
        return 0;
    }*/
}


