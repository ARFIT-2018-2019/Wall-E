//
// Created by ubuntu on 07/11/18.
//

#include "../../includes/Motor/MotorController.h"
//==================================================
//================== CONSTRUCTORS ==================
//==================================================
MotorController::MotorController(Position* positionRobot){
    odometrie = Odometrie(positionRobot);
}

//==================================================
//===================== METIER =====================
//============================= =====================

int sign(double x) {
    return (x > 0) - (x < 0);
}

void MotorController::sendCommandToRoboClaw(float cmByS){
    MotorController::roboClaw->ForwardM1(MOTOR_ADRESSE,pwm); //start Motor1 forward at half speed
    MotorController::roboClaw->ForwardM2(MOTOR_ADRESSE,pwm); //start Motor2 backward at half speed
}

void MotorController::avancer(int pwm){
    MotorController::roboClaw->ForwardM1(MOTOR_ADRESSE,pwm); //start Motor1 forward at half speed
    MotorController::roboClaw->ForwardM2(MOTOR_ADRESSE,pwm); //start Motor2 backward at half speed
}

void MotorController::allerA(Position position) {
    /*while(!(odometrie.getPositionRobot().equals(position))){
        int* cmd =(int*) malloc(2*sizeof(int));
        odometrie.calcPWM(position, cmd);
        roboClaw->ForwardBackwardM1(MOTOR_ADRESSE, cmd[0]);
        roboClaw->ForwardBackwardM2(MOTOR_ADRESSE, cmd[1]);
    }*/
    //TODO Avancer
}

void MotorController::tournerDe(float deg) {
}

void MotorController::stop(){
    MotorController::roboClaw->SpeedAccelM2(MOTOR_ADRESSE, 0, 0);
    MotorController::roboClaw->SpeedAccelM1(MOTOR_ADRESSE, 0, 0);
}


Odometrie MotorController::getOdometrie(){
    return odometrie;
}

