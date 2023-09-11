/*
HYM302Library.cpp
Bibliothek für das Shield HY-M302
Version 1.1.2

(C) 2024 Stefan Muehlbauer

*/

#include "HYM302Library.h"
#include "DHT.h"

HYM302Library::HYM302Library() {
    // Konstruktor, falls erforderlich
	pinMode(LED1Pin, OUTPUT);
	pinMode(LED2Pin, OUTPUT);
	
	pinMode(Button1Pin, INPUT);
	pinMode(Button2Pin, INPUT);

	Serial.begin(9600);
/*
	Serial.println(LED1Pin);
	Serial.println(LED2Pin);
	Serial.println(Button1Pin);
	Serial.println(Button2Pin);
	Serial.println(BuzzerPin);
	Serial.println(LM35Pin);
	Serial.println(DHT11Pin);
	Serial.println(PotiPin);
	Serial.println(FotowiderstandPin);
	
*/
	Serial.end();
	
}

void HYM302Library::controlLED(int LED, bool state) {
	int Pin;
	if (LED == 1) 
	{	
		Pin = LED1Pin;
		LED1State = state;
	}	
	if (LED == 2) 
			{	
		Pin = LED2Pin;
		LED2State = state;
	}	
    digitalWrite(Pin, state ? HIGH : LOW); // LED entsprechend dem Zustand ein- oder ausschalten
}

bool HYM302Library::getLEDState(int LED)
{
	int state;
	if (LED == 1) 
	{	
		state = LED1State;
	}	
	
	if (LED == 2) 
			{	
		state = LED2State;	
		
	}	
	return state;
}

void HYM302Library::toggleLED(int LED)
{
	int Pin;
	bool state;
	if (LED == 1) 
	{	
		Pin = LED1Pin;
		state = not(LED1State);		
		LED1State = state;
	}	

	if (LED == 2) 
	{	
		Pin = LED2Pin;
		state = not(LED2State);		
		LED2State = state;
	}	

digitalWrite(Pin, state ? HIGH : LOW); // LED entsprechend dem Zustand ein- oder ausschalten
	
}

void HYM302Library::testLEDs() {

	this->controlLED(1,1); 
   delay(1000);
   this->controlLED(1,0); 

   this->controlLED(2,1); 
   delay(1000);
   this->controlLED(2,0); 

   this->controlLED(1,1); 
   this->controlLED(2,1); 
   delay(1000);
   this->controlLED(1,0); 
   this->controlLED(2,0); 
   
   delay(1000);
   this->controlLED(1,1); 
   this->controlLED(2,1); 
}


int HYM302Library::readButton(int BUTTON) {
	int Pin;
	if (BUTTON == 1) Pin = Button1Pin;
	if (BUTTON == 2) Pin = Button2Pin;
    return digitalRead(Pin); // Zustand des Tasters lesen
}

void HYM302Library::getPins() {
	
	Serial.print("LED Rot Pin : ");
	Serial.println(LED1Pin);
	Serial.print("LED Blau Pin : ");
	Serial.println(LED2Pin);
	Serial.print("Button 1 Pin : ");
	Serial.println(Button1Pin);
	Serial.print("Button 2 Pin : ");
	Serial.println(Button2Pin);	
		
	Serial.print("LM35 Pin : ");
	Serial.println(LM35Pin);	

	Serial.print("DHT11 Pin : ");
	Serial.println(DHT11Pin);	

	Serial.print("Poti Pin : ");
	Serial.println(PotiPin);	

	Serial.print("Fotowiderstand Pin : ");
	Serial.println(FotowiderstandPin);	

	Serial.print("Buzzer Pin : ");
	Serial.println(BuzzerPin);	
	
	Serial.print("RGB Rot Pin : ");
	Serial.println(RGBRotPin);	
	Serial.print("RGB Gruen Pin : ");
	Serial.println(RGBGruenPin);	
	Serial.print("RGB Blau Pin : ");
	Serial.println(RGBBlauPin);	

}

void HYM302Library::readDHT11(int* temperature, int* humidity) {
    int Pin = DHT11Pin;
	DHT dht(Pin, DHT11);
    dht.begin();
    delay(2000); // Wartezeit für die Stabilisierung des Sensors

    *temperature = dht.readTemperature(); // Temperatur ablesen
    *humidity = dht.readHumidity();       // Luftfeuchtigkeit ablesen
}

float HYM302Library::readLM35() {    
	int Pin = LM35Pin;
	int LM35Temperatur = 0;
	int sensorwert;
	int t = 200;
    sensorwert=analogRead(Pin); //Auslesen des Sensorwertes.
	LM35Temperatur = map(sensorwert, 0, 307, 0, 150); //Umwandeln des Sensorwertes mit Hilfe des "map" Befehls.
	delay(t); // Nach jeder Messung ist je eine kleine Pause mit der Dauer „t“ in Millisekunden.
    return LM35Temperatur;              // Temperatur in Grad Celsius
}

int HYM302Library::readPotentiometer() {
    int Pin = PotiPin;
	return analogRead(Pin); // Potentiometerwert ablesen
}

int HYM302Library::readPhotoresistor() {
    int Pin = FotowiderstandPin;
	return analogRead(Pin); // Fotowiderstandswert ablesen
}


void HYM302Library::controlRGBLED(int redState, int greenState, int blueState) {
    digitalWrite(RGBRotPin, redState);     // Roter Kanal
    digitalWrite(RGBGruenPin, greenState); // Grüner Kanal
    digitalWrite(RGBBlauPin, blueState);   // Blauer Kanal
}


void HYM302Library::controlBrightnessRGBLED(int redState, int greenState, int blueState) {
    analogWrite(RGBRotPin, redState);     // Roter Kanal
    analogWrite(RGBGruenPin, greenState); // Grüner Kanal
    analogWrite(RGBBlauPin, blueState);   // Blauer Kanal

}

void HYM302Library::controlBuzzer(int frequency, int duration) {
    tone(BuzzerPin, frequency); // Buzzer aktivieren mit Frequenz
    delay(duration);      // Eine bestimmte Zeit aktiviert lassen
    noTone(BuzzerPin);          // Buzzer ausschalten
}
