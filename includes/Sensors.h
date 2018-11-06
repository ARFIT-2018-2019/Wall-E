//
// Created by Justin on 05/11/18.
//

#ifndef PROJECT_SENSORS_H
#define PROJECT_SENSORS_H

#include "SensorInterface.h"
#include "SerialCom.h"

#include <map>
#include <string>

using namespace std;

typedef std::map<string, SensorInterface*> mapSensor;

class Sensors {

    public:
        Sensors();
        Sensors(SerialCom* serialCom);

        //get-set
        SerialCom* getSerialCom();
        void setSerialCom(SerialCom* serialCom);

        void init();

    private:
        void addSensor(string key, SensorInterface* sensor);
        mapSensor listSensors;
        SerialCom* serialCom;
};

#endif //PROJECT_SENSORS_H
