//
// Created by Alexandre on 29/11/2018.
//

#include "../../includes/Positionnement/Position.h"
//==================================================
//================== CONSTRUCTORS ==================
//==================================================
Position::Position(float posDepartX, float posDepartY, float angleDepart){
    this->x = posDepartX;
    this->y = posDepartY;
    this->angle = angleDepart;
}
//==================================================
//===================== METIER =====================
//============================= =====================

void Position::init(){

}

int Position::getPosX(){
    //TODO
    return this->x;
}

int Position::getPosxY){
    //TODO
    return this->y;
}

int Position::getRot() {
    //TODO
    return this->angle;
}

