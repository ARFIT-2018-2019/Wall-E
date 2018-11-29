//
// Created by ubuntu on 22/11/18.
//
#include "../includes/WallE.h"
#define PIN_SS1 10
#define PIN_SS2 11
#define X_DEPART 50
#define Y_DEPART 60
#define ANGLE_DEPART 90


WallE::WallE() {

    this->mapSensorCollision.insert(SensorCollision(A0, Direction::Top).getSensorMappable());

    this->softwareSerial = SoftwareSerial(PIN_SS1, PIN_SS2);
    this->robotClaw = RoboClaw(this->softwareSerial, 10000);
    this->motorController = MotorController(EnumMotorName::MOTOR_DROITE, robotClaw);
    this->motorController = MotorController(EnumMotorName::MOTOR_GAUCHE, robotClaw);

    this->position = Position(X_DEPART, Y_DEPART, ANGLE_DEPART);
};


int WallE::init() {
    this->serialCom.init();
    this->sensorCollision.init();
}

void WallE::run() {
    //todo algo loop
}