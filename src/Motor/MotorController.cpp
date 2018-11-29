//
// Created by ubuntu on 07/11/18.
//

#include "../../includes/Motor/MotorController.h"
#include <math.h>
//==================================================
//================== CONSTRUCTORS ==================
//==================================================
MotorController::MotorController(EnumMotorName::_enumType EnumMotorName, RoboClaw* roboClaw){
  this->EnumMotorName = EnumMotorName(EnumMotorName);
  this->roboClaw = roboClaw;
}
//==================================================
//===================== METIER =====================
//============================= =====================

int sign(double x) {
    return (x > 0) - (x < 0);
}

void MotorController::init(){
    this->roboClaw->begin(38400);
  //  this->serialCom->sendMessage("Motor init", "EnumMotorName " + this->EnumMotorName.toString());
}

void MotorController::avancer(int pwm){
  this->roboClaw->ForwardM1(0x80,pwm); //start Motor1 forward at half speed
  this->roboClaw->BackwardM2(0x80,pwm); //start Motor2 backward at half speed
}

void MotorController::allerA(float *x, float *y, Position *position) {
    float xDebut = position->getPosX();
    float yDebut = position->getPosY();
    float rotDebut = position->getRot();

    //TODO Calcul vecteur

    //TODO Rotation du robot
    double Xa = 0.0;
    double Ya = 1.0;
    double Xb = 1.0;
    double Yb = 0.0;

    double Na = sqrt(Xa*Xa+Ya*Ya);
    double Nb = sqrt(Xb*Xb+Yb*Yb);
    double C = (Xa*Xb+Ya*Yb)/(Na*Nb);
    double S = (Xa*Yb-Ya*Xb);
    double angle = ((double) sign(S)) * acos(C);



    //TODO Avancer
}

void MotorController::TournerDe(float deg) {

}

