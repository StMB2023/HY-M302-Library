/*
HYM302Library.h
Bibliothek für das Shield HY-M302

Version 1.1.2

(C) 2024 Stefan Muehlbauer

*/

// Verhindern dass die LIB merfach geladen wird
#ifndef HYM302Library_h
#define HYM302Library_h

#include "Arduino.h"

class HYM302Library {
private:
bool LED1State;
bool LED2State;


public:
    HYM302Library();

byte LED1Pin = 12;
byte LED2Pin = 13;
byte Button1Pin = 2;
byte Button2Pin = 3;
byte LM35Pin = A2;
byte DHT11Pin = 4;
byte BuzzerPin = 5;
byte FotowiderstandPin = A1;
byte PotiPin= A0;
byte RGBRotPin = 9;
byte RGBGruenPin = 10;
byte RGBBlauPin = 11;

	void getPins();

    // Funktionen zum Steuern einer LED
    void controlLED(int LED, bool state);
	void toggleLED(int LED);
	bool getLEDState(int LED);
	void testLEDs();

    // Funktion zur Lesung des Zustands eines Tasters
    int readButton(int Button);


    // Funktionen zur Messung der Temperatur und Luftfeuchtigkeit mit dem DHT11-Sensor
    void readDHT11(int* temperature, int* humidity);

    // Funktion zur Messung der Temperatur mit dem LM35-Sensor
    float readLM35();

    // Funktion zur Messung des Potentiometerwerts
    int readPotentiometer();

    // Funktion zur Messung des Fotowiderstandswerts
    int readPhotoresistor();


    // Funktion zur Steuerung einer RGB-LED (Rot, Grün, Blau)
    void controlRGBLED(int redStatet, int greenState, int blueState);
    
	// Funktion zur Steuerung der Heeligkeit einer RGB-LED (Rot, Grün, Blau)
    void controlBrightnessRGBLED(int redStatet, int greenState, int blueState);

    // Funktion zur Steuerung eines Buzzers
    void controlBuzzer(int frequency, int duration);

};

#endif
