//
// Created by Justin on 05/11/18.
//

#include "../includes/Sensors.h"

Sensors::Sensors(){ 
}

Sensors::Sensors(SerialCom* serialCom) {
    this->serialCom = serialCom;
}

SerialCom* Sensors::getSerialCom() {
    return this->serialCom;
}

void Sensors::setSerialCom(SerialCom* serialCom) {
    this->serialCom = serialCom;
}

void Sensors::addSensor(string key, SensorInterface* sensor) {
    this->listSensors.insert(std::pair<string , SensorInterface*>(key,sensor));
}

void Sensors::init() {}