*/
  Beispiel für die Bibliothek HYM302Library
  Version 1.1.0
  (C) 2024 Stefan Muehlbauer
*/

#include <HyM302Library.h>

HYM302Library MyHYM302;

const int buttonPin1 = 2; // Pin für den Taster
const int ledPin1 = 13;   // Pin für die LED

const int buttonPin2 = 3; // Pin für den Taster
const int ledPin2 = 12;   // Pin für die LED

const int redPin = 9;    // Pin für die rote LED
const int greenPin = 10; // Pin für die grüne LED
const int bluePin = 11;  // Pin für die blaue LED

const int buzzerPin = 5; // Pin für den Buzzer

void setup() {
  Serial.begin(9600);
  //pinMode(buttonPin1, INPUT_PULLUP); // Taster-Pin als Eingang mit Pull-Up-Widerstand
  //pinMode(ledPin1, OUTPUT);          // LED-Pin als Ausgang 
  MyHYM302.getPins();

  MyHYM302.controlLED(1,1); 
  Serial.print("Status LED 1 : ");
  Serial.println(MyHYM302.getLEDState(1));
  delay(1000);
  MyHYM302.controlLED(1,0); 
  Serial.print("Status LED 1 : ");
  Serial.println(MyHYM302.getLEDState(1));
  MyHYM302.controlLED(2,1); 
  Serial.print("Status LED 2 : ");
  Serial.println(MyHYM302.getLEDState(2));
  delay(1000);
  MyHYM302.controlLED(2,0); 
  Serial.print("Status LED 2 : ");
  Serial.println(MyHYM302.getLEDState(2));

  MyHYM302.controlLED(1,1); 
  MyHYM302.controlLED(2,1); 
  delay(1000);
  MyHYM302.controlLED(1,0); 
  MyHYM302.controlLED(2,0); 

  Serial.print("Status LED 1 : ");
  Serial.println(MyHYM302.getLEDState(1));
  Serial.print("Status LED 2 : ");
  Serial.println(MyHYM302.getLEDState(2));

  MyHYM302.toggleLED(1);
  MyHYM302.toggleLED(2);

  Serial.print("Status LED 1 : ");
  Serial.println(MyHYM302.getLEDState(1));
  Serial.print("Status LED 2 : ");
  Serial.println(MyHYM302.getLEDState(2));

  MyHYM302.testLEDs();

  //pinMode(buttonPin2, INPUT_PULLUP); // Taster-Pin als Eingang mit Pull-Up-Widerstand
  //pinMode(ledPin2, OUTPUT);          // LED-Pin als Ausgang
  //MyHYM302.controlLED(ledPin2, 0); 
  //delay(200);
  //MyHYM302.controlLED(ledPin2, 1); 

}

void loop() {
  float LM35Temperature = MyHYM302.readLM35();
  Serial.print("LM35 Temperature: ");
  Serial.println(LM35Temperature);
  //delay(200);

  int DHTTemperature, DHTHumidity;
  MyHYM302.readDHT11( &DHTTemperature, &DHTHumidity);
  Serial.print("DHT11 Temperature: ");
  Serial.print(DHTTemperature);
  Serial.println(" °C");
  Serial.print("DHT11 Humidity: ");
  Serial.print(DHTHumidity);
  Serial.println(" %");
  //delay(500);

  int lightValue = MyHYM302.readPhotoresistor();
  Serial.print("Photoresistor Value: ");
  Serial.println(lightValue);
  //delay(200);

  int potValue = MyHYM302.readPotentiometer();
  Serial.print("Potentiometer Value: ");
  Serial.println(potValue);
  //delay(200);

  int buttonState1 = MyHYM302.readButton(1); // Tasterzustand auslesen
  MyHYM302.controlLED(1, buttonState1);         // LED steuern

  Serial.print("Button 1 State: ");
  Serial.println(buttonState1);

  int buttonState2 = MyHYM302.readButton(2); // Tasterzustand auslesen
  MyHYM302.controlLED(2, buttonState2);         // LED steuern

  Serial.print("Button 2 State: ");
  Serial.println(buttonState2);

  MyHYM302.controlRGBLED(redPin, greenPin, bluePin, 1, 0, 0);
  delay(100);
  MyHYM302.controlRGBLED(redPin, greenPin, bluePin, 0, 1, 0);
  delay(100);
  MyHYM302.controlRGBLED(redPin, greenPin, bluePin, 0, 0, 1);
  delay(100);
  MyHYM302.controlRGBLED(redPin, greenPin, bluePin, 1, 1, 1);
  delay(100);
  MyHYM302.controlRGBLED(redPin, greenPin, bluePin, 0, 0, 0);
    
    // Buzzer mit 1000 Hz Frequenz für 1 Sekunde aktivieren
    //MyHYM302.controlBuzzer(buzzerPin, 1000, 500);
    //delay(100); // Pause von 1 Sekunde
  
  MyHYM302.toggleLED(1);
  MyHYM302.toggleLED(2);
  delay(100);

}
