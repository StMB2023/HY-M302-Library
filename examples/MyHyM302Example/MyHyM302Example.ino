/*
  Beispiel für die Bibliothek HYM302Library
  Version 1.1.2
  (C) 2023 Stefan Muehlbauer
*/

#include <HyM302Library.h>

HYM302Library MyHYM302;

void setup() {
  Serial.begin(9600);
  Serial.println("Setup");

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

}

void loop() {
  Serial.println("Loop");
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

  Serial.println("RGB LEDs");
  MyHYM302.controlRGBLED( 1, 0, 0);
  delay(100);
  MyHYM302.controlRGBLED(  0, 1, 0);
  delay(100);
  MyHYM302.controlRGBLED(  0, 0, 1);
  delay(100);
  MyHYM302.controlRGBLED(  1, 1, 1);
  delay(100);
  MyHYM302.controlRGBLED(  0, 0, 0);
    
  // Buzzer mit 1000 Hz Frequenz für 1 Sekunde aktivieren
  Serial.println("Buzzer");
  //MyHYM302.controlBuzzer(1000, 500);
  //delay(100); // Pause von 1 Sekunde
  
  Serial.print("Status LED 1 : ");
  Serial.println(MyHYM302.getLEDState(1));
  Serial.print("Status LED 2 : ");
  Serial.println(MyHYM302.getLEDState(2));
  Serial.println("toggle LEDs");
  
  MyHYM302.toggleLED(1);
  MyHYM302.toggleLED(2);

  Serial.print("Status LED 1 : ");
  Serial.println(MyHYM302.getLEDState(1));
  Serial.print("Status LED 2 : ");
  Serial.println(MyHYM302.getLEDState(2));

  delay(100);

}
