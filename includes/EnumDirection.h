//
// Created by ubuntu on 07/11/18.
//

#ifndef WALL_E_ENUM_DIRECTION_H
#define WALL_E_ENUM_DIRECTION_H
#include "Arduino.h"

class Direction  {
public:
    enum _enumType {
        TopRight,
        Top,
        TopLeft,
        Left,
        BotLeft,
        Bot,
        BotRight,
        Right
    };

    Direction() {}
    Direction(_enumType value) : m_value(value) { }
    // For switch to work
    operator _enumType () const {
        return (int)m_value;
    }
    // This operator provides conversion to int
    explicit operator int() const {
        return (int)m_value;
    }
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
    _enumType m_value;
};
#endif //WALL_E_ENUMDIRECTION_H
