/*** ===== INCLUDES LIB ===== ***/
#include <ArduinoSTL.h>
#include <Arduino.h>
#include <map>

/*** ===== INCLUDES OWN CLASS ===== ***/
#include "./includes/EnumDirection.h"
#include "./includes/Sensor/SensorCollision.h"
#include "./includes/SerialCom.h"

/*** ====== CONSTANTES ====== ***/
#define SERIAL_SPEED 9600

#define SOFTWARE_SERIAL_MOTOR_CONTROLLER_1 10
#define SOFTWARE_SERIAL_MOTOR_CONTROLLER_2 11
#define SOFTWARE_SERIAL_SPEED 10000
  
#define SERIAL_MOTOR_SS_1_GAUCHE 
#define SERIAL_MOTOR_SS_2_GAUCHE

/*** ======= DECLARATION ====== ***/
extern static SerialCom serialCom = SerialCom(SERIAL_SPEED);
SoftwareSerial serial(SOFTWARE_SERIAL_MOTOR_CONTROLLER_1,SOFTWARE_SERIAL_MOTOR_CONTROLLER_2);
RoboClaw roboclaw(&serial,SOFTWARE_SERIAL_SPEED);

std::map<Direction, SensorCollision*> mapSensorCollision

// todo change function Motor design Code

//MotorController motor = MotorController(EnumMotorName::MOTOR_DROITE, &roboclaw);

void setup() {
    serialCom.init();
    initSensors();    
    //motor.init();
}

void initSensors(){
    sensorCollision = SensorCollision(A0, Direction::Top, &serialCom);
    sensorCollision.init();

    mapSensorCollision.insert(std::pair<Direction, SensorCollision*>(Direction::Top, &sensorCollision);
    //todo declare all, add the Collision escape
}

void loop() {
  /*int valueNoSafe = sensorCollision.getValue();
  int volt = map(valueNoSafe, 0, 1023, 0, 5000);

  int valueInCm = (21.16/(volt-0.1696))*1000;
  serialCom.sendMessage("Value",String(valueInCm));
  delay(1000);
*/
 // motor.avancer(92);
  //delay(2000);
}
