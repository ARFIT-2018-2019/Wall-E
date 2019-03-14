//
// Created by Alexandre on 29/11/2018.
//

#ifndef WALL_E_POSITION_H
#define WALL_E_POSITION_H

#include <Arduino.h>

class Position {

public:
    Position();
    Position(double departX, double departY, double departAngle);

    void init();

    double getX();
    double getY();
    double getAngle();

    void setX(double x);
    void setY(double y);
    void setAngle(double angle);

    bool equals(Position b);
    void debug();
private:
    double x;
    double y;
    double angle;
};

#endif //WALL_E_POSITION_H
