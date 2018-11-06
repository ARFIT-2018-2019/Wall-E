//
// Created by Justin on 05/11/18.
//

#include "../includes/SerialCom.h";


SerialCom::SerialCom(){
    this->debugMode = true; //default value true;
    this->speed = 9600; //default value 9600

    if(this->hasBeenInitialized){
        Serial.write("Fin de communication : cause redefinition");
        Serial.end();
    }
    Serial.begin(speed);

    string debugModeStr = debugMode ? "true" : "false";
    string initMessage  = "Serial has been init (mode dev : " + debugModeStr + ")\n";

    this->write(initMessage);
    this->hasBeenInitialized = true;
}

SerialCom::SerialCom(bool debugMode, int speed){
    this->debugMode = debugMode;
    this->speed = speed;

    if(this->hasBeenInitialized){
        Serial.write("Fin de communication : cause redefinition");
        Serial.end();
    }
    Serial.begin(speed);

    string debugModeStr = debugMode ? "true" : "false";
    string initMessage  = "Serial has been init (mode dev : " + debugModeStr + ")\n";

    this->write(initMessage);
    this->hasBeenInitialized = true;
}

int SerialCom::getSpeed(){
    return this->speed;
}

bool SerialCom::isDebugMode(){
    return this->debugMode;
}

void SerialCom::setDebugMode(bool debugMode){
    this->debugMode = debugMode;
}

void SerialCom::setSpeed(int speed){
    this->speed = speed;
}

void SerialCom::sendMessage(string key, string message){
    string toSend = key + " : " + message + "\n";
    if(this->debugMode)
        toSend = "debug -> " + toSend;

    this->write(toSend);
}

void SerialCom::write(string message){
    Serial.write(message.c_str());
}