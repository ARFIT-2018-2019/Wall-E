//
// Created by ubuntu on 07/11/18.
//

#include "../../includes/Motor/MotorController.h"
#include <Arduino.h>

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

    Position* positionActuelle =  this->odometrie.getPositionRobot();

    double xDebut = positionActuelle->getX();
    double yDebut = positionActuelle->getY();
    double angleDebut = positionActuelle->getAngle();

    double xCible = positionActuelle->getX();
    double yCible = positionActuelle->getY();
    double angleCible = positionActuelle->getAngle();

    double distX = positionActuelle->getX();
    double distY = positionActuelle->getY();
    double distAngle = positionActuelle->getAngle();

    //TODO Calcul angleAvantDeplacementCible
    double scal = yCible;
    double norme = sqrt((xCible * xCible) + (yCible * yCible));

    double anglePourDeplacement = acos(scal / norme);
    double angleAvantDeplacement = CalculAngleRotation(angleDebut, anglePourDeplacement);

    //TODO Calcul angleRotationAvantDeplacement


    //TODO Calcul angleRotationApresDeplacement

    //TODO Calcul distance

    //TODO Tourner

    //TODO Avancer

    //TODO Tourner

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

private double CalculAngleRotation (double angle1, double angle2)
{
    double angleRotation = 0;
    if(angle1 != angle2)
    {
        if(angle2 < angle1) {
            if (angle1 <= 180) {
                return angle2 - angle1;
            } else {
                if (angle1 - 180 <= angle2) {
                    return angle2 - angle1;
                } else {
                    return -((360 + angle2) - angle1);
                }
            }
        }else{
            if(angle2 - 180 <= angle1)
            {
                return angle2 - angle1;
            }else{
                return -((360 + angle1) - angle2);
            }
        }
    }

    return angleRotation;
}

private double asin(double c)
{

    double out;

    out= ((c+(c*c*c)/6+(3*c*c*c*c*c)/40+(5*c*c*c*c*c*c*c)/112+

           (35*c*c*c*c*c*c*c*c*c)/1152 +(c*c*c*c*c*c*c*c*c*c*c*0.022)+

           (c*c*c*c*c*c*c*c*c*c*c*c*c*.0173)+(c*c*c*c*c*c*c*c*c*c*c*c*c*c*c*.0139)+

           (c*c*c*c*c*c*c*c*c*c*c*c*c*c*c*c*c*0.0115)+(c*c*c*c*c*c*c*c*c*c*c*c*c*c*c*c*c*c*c*0.01)

    ));

    //asin

    if(c>=.96 && c<.97){
        out=1.287+(3.82*(c-.96));
    }

    if(c>=.97 && c<.98){
        out=(1.325+4.5*(c-.97));
    }

    if(c>=.98 && c<.99){
        out=(1.37+6*(c-.98));
    }

    if(c>=.99 && c<=1){
        out=(1.43+14*(c-.99));
    }

    return out;
}

private double acos(double c)
{
    double out;

    out=asin(sqrt(1-c*c));

    return out;
}

private double atan(double c)

{
    double out;

    out=asin(c/(sqrt(1+c*c)));

    return out;
}

