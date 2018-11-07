//
// Created by Justin on 05/11/18.
//

#ifndef PROJECT_SENSOR_INTERFACE_H
#define PROJECT_SENSOR_INTERFACE_H

class SensorInterface {
    public:
        // pure virtual function providing interface framework.
        virtual int getValue() = 0;
};


#endif //PROJECT_SENSOR_INTERFACE_H