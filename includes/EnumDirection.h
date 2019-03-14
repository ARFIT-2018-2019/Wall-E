//
// Created by ubuntu on 07/11/18.
//

#ifndef WALL_E_ENUM_DIRECTION_H
#define WALL_E_ENUM_DIRECTION_H

#include "Arduino.h"

enum DirectionEnum {
    TopRight,
    Top,
    TopLeft,
    Left,
    BotLeft,
    Bot,
    BotRight,
    Right
};

class Direction  {
    public:
        Direction() {}
        Direction(DirectionEnum value) : m_value(value) { }

        String toString() const {
            switch(m_value) {
                case TopRight:
                    return String("TopRight");
                case Top:
                    return String("Top");
                case TopLeft:
                    return String("TopLeft");
                case Left:
                    return String("Left");
                case BotLeft:
                    return String("BotLeft");
                case Bot:
                    return String("Bot");
                case BotRight:
                    return String("BotRight");
                case Right:
                    return String("Right");
                default:
                    return "";
            }
        }

    private:
        DirectionEnum m_value;
};
#endif //WALL_E_ENUMDIRECTION_H
