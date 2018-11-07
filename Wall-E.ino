#include <ArduinoSTL.h>
#include <Arduino.h>

#include <map>

#include "includes/SerialCom.h"
#include "includes/SensorInterface.h"
#include "includes/SensorCollision.h"


typedef std::map<String, SensorInterface*> mapSensor;
SerialCom serialCom;

void setup() {
    serialCom = SerialCom();
    serialCom.init();
}

void loop() {

}
