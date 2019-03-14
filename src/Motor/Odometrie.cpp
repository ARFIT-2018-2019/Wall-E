#include "../../includes/Motor/Odometrie.h"
//==================================================
//================== CONSTRUCTORS ==================
//==================================================
Odometrie::Odometrie(){
    positionRobot = new Position(0.0,0.0,0.0);
    init();
}

Odometrie::Odometrie(const Odometrie& odometrie){
    positionRobot = odometrie.positionRobot;
    init();
}

Odometrie::Odometrie(Position* positionRobot){
    this->positionRobot = positionRobot;
    init();
}

void Odometrie::init(){
    this->erreurPre = 0.0;
}


void Odometrie::updateCodeurGauche(){
    if(digitalRead(ENCODEUR_ROUE_CODEUSE_GAUCHE_VA) == digitalRead(ENCODEUR_ROUE_CODEUSE_GAUCHE_VB))
        CountEncodeurG--;
    else
        CountEncodeurG++;
}

void Odometrie::updateCodeurDroit(){
    if(digitalRead(ENCODEUR_ROUE_CODEUSE_DROITE_VA) ==  digitalRead(ENCODEUR_ROUE_CODEUSE_DROITE_VB))
        CountEncodeurD--;
    else
        CountEncodeurD++;
}


void Odometrie::calcPWM(Position positionCible, int *cmdReturn){
    double coeffP = 5.0;
    double coeffD = 3.0;
    int cmdD = 0, cmdG = 0;
    int signe=0;
    double dDist = 0.0, dAngl = 0.0;
    double distanceCible=0.0, consigneOrientation=0.0;

    double erreurAngle = 0.0;
    double  deltaErreur = 0.0;

    //On commence par calculer les variations de position en distance et en angle

    dDist = (COEFFGLONG*comptG + COEFFDLONG*comptD)/2.0;
    dAngl = COEFFDANGL*comptD - COEFFGANGL*comptG;

    //Actualisation de la position du robot en xy et en orientation
    positionRobot.setX(positionRobot.getX() +dDist*cos(dAngl));
    positionRobot.setY(positionRobot.getY() +dDist*sin(dAngl));
    positionRobot.setAngle(positionRobot.getAngle() +dAngl);

    //On calcule la distance séparant le robot de sa cible
    distanceCible = sqrt(
            (positionCible.getX()-positionRobot.getX())*(positionCible.getX()-positionRobot.getX())+
            (positionCible.getY()-positionRobot.getY())*(positionCible.getY()-positionRobot.getY())
    );

    //On regarde si la cible est à gauche ou à droite du robot
    if(positionRobot.getY() > positionCible.getY())
        signe = 1;
    else
        signe = -1;

    //On calcule l'angle entre le robot et la cible
    consigneOrientation = signe * acos(
            ((positionCible.getX()-positionRobot.getX())/(positionCible.getX()-positionRobot.getX()))*
            ((positionCible.getX()-positionRobot.getX())*(positionCible.getY()-positionRobot.getY()))*
            (positionCible.getY()-positionRobot.getY())
    );

    //On détermine les commandes à envoyer aux moteurs
    cmdD = abs((int)distanceCible);
    if(cmdD>255)
    {
        cmdD = 255;
    }
    cmdG = cmdD;

    //Calcul de l'erreur
    erreurAngle =  consigneOrientation - positionRobot.getAngle();

    //Calcul de la différence entre l'erreur au coup précédent et l'erreur actuelle.
    deltaErreur = erreurAngle - erreurPre;

    //Mise en mémoire de l'erreur actuelle
    erreurPre = erreurAngle;

    //Calcul de la valeur à envoyer aux moteurs pour tourner
    int deltaCommande = coeffP*erreurAngle + coeffD * deltaErreur;

    cmdG += deltaCommande;
    cmdD -= deltaCommande;

    if(cmdD>255)
    {
        cmdD = 255;
    }else if(cmdD < 0)
    {
        cmdD = 0;
    }

    if(cmdG>255)
    {
        cmdG = 255;
    }else if(cmdG < 0)
    {
        cmdG = 0;
    }

    cmdReturn[0] = cmdD;
    cmdReturn[1] = cmdG;
}

void Odometrie::reccurentTask(){
    //Fonction executée toutes les TECOMMANDE ms sur interruption.
    // Afin de faciliter l'odométrie, veuillez mettre en commentaire la commande des moteurs dans la boucle asservissement

    int CountEncodeurCGTempsCourant = CountEncodeurG - CountEncodeurCGTempsPrecedent;
    int CountEncodeurCDTempsCourant = CountEncodeurD - CountEncodeurCDTempsPrecedent;


    float DRG = (3.1416*DIAMETRE_ROUE_CODEUSE*CountEncodeurCGTempsCourant)/1024.0000;
    float DRD = (3.1416*DIAMETRE_ROUE_CODEUSE*CountEncodeurCDTempsCourant)/1024.0000;
    float DC = (DRG+DRD)*0.5;

    float xtETdt = xt + DC*cos(thetat);
    float ytETdt = yt + DC*sin(thetat);
    float thetatETdt = (thetat + ((DRD-DRG)/ENTRAXE_ROUE_CODEUSE));

    this->positionRobot->setX(xtETdt);
    this->positionRobot->setX(ytETdt);

    this->positionRobot->setAngle(thetatETdt);

    CountEncodeurCGTempsPrecedent = CountEncodeurG;
    CountEncodeurCDTempsPrecedent = CountEncodeurD;
}

//==================================================
//================= GETTER/SETTER ==================
//==================================================
Position* Odometrie::getPositionRobot(){
    return positionRobot;
}

void Odometrie::setPosition(Position* positionRobot){
    this->positionRobot = positionRobot;
}





