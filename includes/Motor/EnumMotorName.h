//
// Created by ubuntu on 07/11/18.
//

#ifndef WALL_E_ENUM_MOTOR_H
#define WALL_E_ENUM_MOTOR_H
#include "Arduino.h"

class EnumMotorName {
    public:
        enum _enumType {
            MOTOR_DROITE,
            MOTOR_GAUCHE // 2
        };

        EnumMotorName() {}
        EnumMotorName(_enumType value) : m_value(value) { }
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
                case MOTOR_DROITE:
                    return String("Motor droite");
                case MOTOR_GAUCHE:
                    return String("Motor gauche");
                default:
                    return "";
            }
        }

    private:
        _enumType m_value;
};
#endif //WALL_E_ENUM_MOTOR_H
