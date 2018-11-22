//
// Created by ubuntu on 07/11/18.
//

#include "../includes/Motor.h"
//==================================================
//================== CONSTRUCTORS ==================
//==================================================
Motor::Motor(MotorName::_enumType motorName, RoboClaw* roboClaw){
  this->motorName = MotorName(motorName);
  this->roboClaw = roboClaw;
}
//==================================================
//===================== METIER =====================
//============================= =====================

void Motor::init(){
    this->roboClaw->begin(38400);
  //  this->serialCom->sendMessage("Motor init", "MotorName " + this->motorName.toString());
}

void Motor::avancer(int pwm){
  this->roboClaw->ForwardM1(0x80,pwm); //start Motor1 forward at half speed
  this->roboClaw->BackwardM2(0x80,pwm); //start Motor2 backward at half speed
}
