//
// Created by Justin on 05/11/18.
//

#include "../includes/SerialCom.h"

//==================================================
//================== CONSTRUCTORS ==================
//==================================================

SerialCom::SerialCom(){
    this->debugMode = true; //default value true;
    this->speed = 9600; //default value 9600
}

SerialCom::SerialCom(bool debugMode, int speed){
    this->debugMode = debugMode;
    this->speed = speed;
}

//==================================================
//================= GETTER - SETTER ================
//==================================================

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

//==================================================
//===================== METIER =====================
//==================================================

void SerialCom::sendMessage(String key, String message){
    String toSend = key + " : " + message;
    if(this->debugMode)
        toSend = " [debug] " + toSend;

    this->write(toSend);
}

void SerialCom::write(String message){
    Serial.write(String(message +"\n").c_str());
}

void SerialCom::initMessage(){
    String debugModeStr = String(debugMode);
    String initMessage  = String("Serial has been init (mode dev : " + debugModeStr + ")");

    this->sendMessage("Serial init",initMessage);
}

void SerialCom::init(){
    if(this->hasBeenInitialized){
        Serial.write("Fin de communication : cause redefinition");
        Serial.end();
    }
    Serial.begin(speed);

    this->initMessage();
    this->hasBeenInitialized = true;
}