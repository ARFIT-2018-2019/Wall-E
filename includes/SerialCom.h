//
// Created by Justin on 05/11/18.
//

#ifndef PROJECT_SERIAL_COM_H
#define PROJECT_SERIAL_COM_H

#include <Arduino.h>
#include <string>

using namespace std;

class SerialCom {

    public:
        SerialCom();
        SerialCom(bool debugMode, int speed);

        //get-set
        int getSpeed();
        bool isDebugMode();

        void setDebugMode(bool debugMode);
        void setSpeed(int speed);

        void sendMessage(string key, string message);

    private:
        bool debugMode;
        int speed;
        bool hasBeenInitialized = false;
        void write(string message);
};

#endif //PROJECT_SERIAL_COM_H
