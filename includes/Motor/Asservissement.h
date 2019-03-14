//
// Created by Phenixos on 31/01/19.
//

#ifndef WALL_E_ASSERVISSEMENT_H
#define WALL_E_ASSERVISSEMENT_H

#include <Arduino.h>
#include "../Position/Position.h"

class Asservissement {

    public:
        Asservissement();
        Asservissement(const Asservissement& asservissement);
     
        static void updateCodeurGauche();
        static void updateCodeurDroit();
        void calcPWM(Position positionCible, int *cmdReturn);

        Position getPositionRobot();
        void setPosition(Position positionRobot);
        
        static long CountEncodeurG; 
        static long CountEncodeurD;

    private:
        Position positionRobot;
        double erreurPre;
    
        void init(); 
};
#endif //WALL_E_ASSERVISSEMENT_H
