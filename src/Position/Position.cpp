//
// Created by Alexandre on 29/11/2018.
//

#include "../../includes/Position/Position.h"
//==================================================
//================== CONSTRUCTORS ==================
//==================================================
Position::Position(){
    this->x = 0.0;
    this->y = 0.0;
    this->angle = 0.0;
}

Position::Position(double departX, double departY, double departAngle){
    this->x = departX;
    this->y = departY;
    this->angle = departAngle;
}
//==================================================
//===================== METIER =====================
//============================= =====================

void Position::init(){

}

double Position::getX(){
    //TODO
    return this->x;
}

double Position::getY(){
    //TODO
    return this->y;
}

double Position::getAngle() {
    //TODO
    return this->angle;
}

void Position::setX(double x){
    //TODO
    this->x = x;
}

void Position::setY(double posY){
    this->y = y;
}

void Position::setAngle(double angle) {
    this->angle = angle;
}

bool Position::equals(Position b){
    return( (this->x == b.x) &&
            (this->y == b.y) &&
            (this->angle == b.angle));
}

void Position::debug(){
    SerialUSB.println("x : "+this->x);
    SerialUSB.println("y : "+this->x);
    SerialUSB.println("Th : "+this->x);
    SerialUSB.println("-------------");
}