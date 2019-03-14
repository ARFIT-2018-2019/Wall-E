//
// Created by ubuntu on 07/11/18.
//

#include "../../includes/Sensor/SensorCollision.h"
#include <map>
#include "../../includes/Motor/MotorController.h"

//==================================================
//================== CONSTRUCTORS ==================
//==================================================
SensorCollision::SensorCollision(){}
SensorCollision::SensorCollision(int pin, DirectionEnum directionEnum) {
    this->pin = pin;
    this->direction = Direction(directionEnum);
    this->value = -1;
}

//==================================================
//===================== METIER =====================
//============================= =====================

void SensorCollision::init() {
    pinMode(pin, INPUT);
    /*Serial.print("SensorCollision ");
    Serial.print(this->direction.toString());
    Serial.print(" on ");
    Serial.println(String(pin));*/
}
int SensorCollision::getValue() {
    return this->value;
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
void SensorCollision::setDirection(DirectionEnum directionEnum) {
    this->direction = Direction(directionEnum);
}
int SensorCollision::getPin() {
    return this->pin;
}
void SensorCollision::setPin(int pin) {
    this->pin = pin;
}

int SensorCollision::readValue() {
    return analogRead(this->pin);
}

void SensorCollision::run(){
    int valueNoSafe = this->readValue();
    int volt = map(valueNoSafe, 0, 1023, 0, 5000);
    int valueCm = (21.16/(volt-0.1696))*1000;
    value = valueCm;
    if(value <= 5)
        MotorController::stop();
    runned();
}