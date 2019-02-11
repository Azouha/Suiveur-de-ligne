#include <ChainableLED.h> 
#define NUM_LEDS 1
int signalPin1 = 2; // déclaration du capteur de gauche
int signalPin2 = 3; // déclaration du capteur milieu
int signalPin3 = 4; // déclaration du capteur de droite
ChainableLED leds(7, 8, NUM_LEDS); // déclaration de la LED RGB

#include <Wire.h> // Déclaration de la bibliothèque moteurs arduino
#include <MotorI2C.h> // déclaration de la bibliothèque pour moteurs I2C récupérée ici : http://www.duinoedu.com/dl/lib/grove/EDU_Motor_I2C.zip
MotorI2C mesMoteurs; //initialisation des moteurs

void setup(){
Serial.begin(115200); // initialiser le moniteur série à 115200 bps
mesMoteurs.branch(); // définition de la classe des moteurs
mesMoteurs.reglerVitesse(1000,1000); // etalonage de la vitesse des moteurs

pinMode(signalPin1, INPUT); // initialise le capteur de gauche en entrée
pinMode(signalPin2, INPUT); // initialise le capteur du milieu en entrée
pinMode(signalPin3, INPUT); // initialise le capteur de droite en entrée
Serial.println("Setup Done"); // signaler que l'initialisation s'est bien déroulée
leds.init(); // initialiser la LED
}

void loop()
{
if(HIGH == digitalRead(signalPin1)) // si le capteur de gauche (seul) reçoit un signal
{
leds.setColorRGB(0, 255, 0, 0); // faire clignoter la LED en rouge
Serial.println(" RED "); // afficher la couleur de la LED dans le moniteur série

mesMoteurs.avancer("gauche"); delay(200); // faire tourner le robot à gauche

}
else
{
leds.setColorRGB(0, 0, 0, 0);
Serial.println(" BLACK ");
delay(100);

}
if(HIGH == digitalRead(signalPin2)) // si le capteur du milieu reçoit un signal
{
leds.setColorRGB(0, 0, 0, 255); // faire clignoter la LED en bleu
Serial.println(" BLUE "); // afficher la couleur de la LED dans le moniteur série

mesMoteurs.avancer(); delay (100); // faire avancer le robot

}
else
{
leds.setColorRGB(0, 0, 0, 0);
Serial.println(" BLACK ");
delay(100);

}
if(HIGH == digitalRead(signalPin3)) // si le capteur de droite (seul) reçoit un signal
{
leds.setColorRGB(0, 0, 255, 0); // faire clignoter la LED en vert
Serial.println(" GREEN "); // afficher la couleur de la LED dans le moniteur série

mesMoteurs.avancer("droite"); delay(200); // faire tourner le robot à droite

}
else
{
leds.setColorRGB(0, 0, 0, 0);
Serial.println(" BLACK ");
delay(100);

}

mesMoteurs.stopper(); delay(200); // stopper les moteurs

}
