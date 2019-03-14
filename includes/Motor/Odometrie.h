//
// Created by Phenixos on 31/01/19.
//

#ifndef WALL_E_ODOMETRIE_H
#define WALL_E_ODOMETRIE_H

#define ENCODEUR_ROUE_CODEUSE_GAUCHE_VA 24
#define ENCODEUR_ROUE_CODEUSE_GAUCHE_VB 25
#define ENCODEUR_ROUE_CODEUSE_DROITE_VA 28
#define ENCODEUR_ROUE_CODEUSE_DROITE_VB 29

#define DIAMETRE_ROUE_CODEUSE 6.2200
#define ENTRAXE_ROUE_CODEUSE 6.4000

#define COEFFGLONG 0.00017
#define COEFFDLONG 0.00017

#define COEFFGANGL 0.0008
#define COEFFDANGL 0.0008

#include <Arduino.h>
#include "../Position/Position.h"

class Odometrie {

    public:
        Odometrie();
        Odometrie(const Odometrie& odometrie);
        Odometrie(Position* positionRobot);
         
        static void updateCodeurGauche();
        static void updateCodeurDroit();
        //void calcPWM(Position positionCible, int *cmdReturn);

        Position* getPositionRobot();
        void setPosition(Position* positionRobot);
        
        static long CountEncodeurG; 
        static long CountEncodeurD;

        long CountEncodeurGTempsPrecedent; //dernière valeur de CountEncodeurG
        long CountEncodeurDTempsPrecedent; //dernière valeur de CountEncodeurG

        void reccurentTask();
    private:
        Position* positionRobot;
        double erreurPre;
    
        void init(); 
};
#endif //WALL_E_ODOMETRIE_H
