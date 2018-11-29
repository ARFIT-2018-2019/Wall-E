//
// Created by Justin on 05/11/18.
//

#include "../includes/SerialCom.h"

#define DEFAULT_SPEED 9600
#define DEFAULT_KEY_SERIAL "Serial"
//==================================================
//================== CONSTRUCTORS ==================
//==================================================

SerialCom::SerialCom(){
    this->speed = DEFAULT_SPEED; //default value 9600
}

SerialCom::SerialCom(int speed){
    this->speed = speed;
}

//==================================================
//===================== METIER =====================
//==================================================

void SerialCom::sendMessage(String key, String message){
    String toSend = key + ":" + message;
    this->write(toSend);
}

void SerialCom::write(String message){
    Serial.write(String(message +"\n").c_str());
}

void SerialCom::initMessage(){
    String initMessage  = String("Serial has been init");
    this->sendMessage(DEFAULT_KEY_SERIAL,initMessage);
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

//==================================================
//================= GETTER - SETTER ================
//==================================================

int SerialCom::getSpeed(){
    return this->speed;
}

void SerialCom::setSpeed(int speed){
    this->speed = speed;
}