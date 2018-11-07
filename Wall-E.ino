#include <ArduinoSTL.h>
#include <Arduino.h>

#include <map>

#include "includes/SerialCom.h"
#include "includes/SensorInterface.h"
#include "includes/SensorCollision.h"

SerialCom serialCom;
SensorCollision sensorCollision;

void setup() {
    serialCom = SerialCom();
    serialCom.init();

    sensorCollision = SensorCollision(A0, Direction::Top, &serialCom);
    sensorCollision.init();
}

void loop() {
  int valueNoSafe = sensorCollision.getValue();
  int volt = map(valueNoSafe, 0, 1023, 0, 5000);

  int valueInCm = (21.16/(volt-0.1696))*1000;
  serialCom.sendMessage("Value",String(valueInCm));
  delay(1000);
}
