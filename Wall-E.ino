#include <ArduinoSTL.h>
#include <Arduino.h>
#include "includes/SerialCom.h"

extern  SerialCom serialCom; //error view scope in Sensor
#include "includes/SensorInterface.h"
#include <map>
#include "includes/SensorCollision.h"

typedef std::map<String, SensorInterface*> mapSensor;

void setup() {
    serialCom = SerialCom();
    serialCom.init();
}

void loop() {

}
