/*** ====== CONSTANTES ====== ***/
#define SERIAL_SPEED 9600
#define MOTOR_SERIAL_SPEED 10000
#define ENCODEUR_ROUE_CODEUSE_GAUCHE_VA 2
#define ENCODEUR_ROUE_CODEUSE_DROITE_VA 3


#define TECOMMANDE 10 //ms


void initSensors();

/*** ===== INCLUDES LIB ===== ***/
#include <ArduinoSTL.h>
#include <RoboClaw.h>
#include <map>
//Lib Thread
#include "Thread.h"
#include "ThreadController.h"
#include <DueTimer.h>
/*** ===== INCLUDES OWN CLASS ===== ***/
#include "./includes/EnumDirection.h"
#include "./includes/Sensor/SensorCollision.h"
#include "./includes/Motor/MotorController.h"
#include "./includes/Position/Position.h" 

typedef std::pair<DirectionEnum, SensorCollision*> PairSensorElement;

/*** ======= DECLARATION ====== ***/
RoboClaw roboclaw(&Serial2,MOTOR_SERIAL_SPEED); //Serial on 17,16 RX,TX
std::map<DirectionEnum, SensorCollision*> mapSensorCollision;
//SensorCollision sensorCollisionTop = SensorCollision(A5, DirectionEnum::Top);   

RoboClaw* MotorController::roboClaw = &roboclaw;
Position positionRobot = Position();
MotorController motor = MotorController(&positionRobot);
ThreadController controller = ThreadController();

// This is the callback for the Timer
void timerCallback(){
  controller.run();
}

void setup() {
  pinMode(2, OUTPUT);
  SerialUSB.begin(9600);
  roboclaw.begin(38400);
  SensorCollision sensorCollisionTop = SensorCollision(A5, DirectionEnum::Top);
  sensorCollisionTop.setInterval(3000);
  sensorCollisionTop.init();

  //controller.add(&sensorCollisionTop);
  mapSensorCollision.insert(PairSensorElement(DirectionEnum::Top, &sensorCollisionTop));

  attachInterrupt(ENCODEUR_ROUE_CODEUSE_GAUCHE_VA, timerOdemetrieCodeurGauche, RISING);
  attachInterrupt(ENCODEUR_ROUE_CODEUSE_DROITE_VA, timerOdemetrieCodeurDroit, RISING);


  Timer5.getAvailable().attachInterrupt(timerOdometrieCalcReccurent).setFrequency(1000.0/TECOMMANDE).start();
  //Timer1.attachInterrupt(timerCallback).start(1000);
}

void timerOdometrieCalcReccurent(){
  motor.getOdometrie().reccurentTask();
}

void timerOdemetrieCodeurDroit(){
  motor.getOdometrie().updateCodeurDroit();
}
void timerOdemetrieCodeurGauche(){
  motor.getOdometrie().updateCodeurGauche();
}



void loop() {
  /*  Serial.print("Analog1 Thread: ");
    SensorCollision* sensorCollisionTop = mapSensorCollision[DirectionEnum::Top];
    Serial.println(sensorCollisionTop->getValue());
    // Do more complex-crazy-timeconsuming-tasks her
    */

//  motor.avancer(45);
  //motor.allerA(Position(100,100,0));
  delay(5000);
  positionRobot.debug();
  /*roboclaw.ForwardM1(0x80,92); //start Motor1 forward at half speed
  delay(2000);
  roboclaw.ForwardM1(0x80,0); //start Motor1 forward at half speed
  //motor.avancer(0);
  delay(2000);*/
}
