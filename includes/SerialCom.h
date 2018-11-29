//
// Created by Justin on 05/11/18.
//

#ifndef PROJECT_SERIAL_COM_H
#define PROJECT_SERIAL_COM_H

#include <Arduino.h>

class SerialCom {

    public:
        SerialCom();
        SerialCom(int speed);

        //get-set
        int getSpeed();
        void setSpeed(int speed);

        void init();
        void sendMessage(String key, String message);

    private:
        int speed;
        bool hasBeenInitialized = false;
        void write(String message);
        void initMessage();
};

#endif //PROJECT_SERIAL_COM_H