# HYM302 Library

Eine Arduino-Bibliothek für das HY-M302 Shield.

## Version

1.1

## Autor

(C) 2024 Stefan Mühlbauer

## Inhaltsverzeichnis

- [Über die Bibliothek](#über-die-bibliothek)
- [Installation](#installation)
- [Verwendung](#verwendung)
- [Beispiel](#beispiel)
- [Funktionen](#funktionen)
- [Lizenz](#lizenz)

## Über die Bibliothek

Die HYM302 Library ist eine Arduino-Bibliothek, die entwickelt wurde, um das HY-M302 Shield zu steuern. Dieses Shield bietet verschiedene Funktionen zur Steuerung von LEDs, Tastern, Sensoren und anderen Komponenten. Mit dieser Bibliothek können Sie das Shield effizient nutzen und auf einfache Weise auf die verschiedenen Funktionen zugreifen.

## Installation

1. Laden Sie die HYM302 Library von [hier](https://github.com/StMB2023/HYM302Library/archive/refs/heads/main.zip) herunter.

2. Entpacken Sie das Archiv und verschieben Sie den Ordner in das "libraries"-Verzeichnis Ihres Arduino-Projekts.

3. Starten Sie die Arduino-IDE neu.

4. Wählen Sie "Sketch" -> "Include Library" -> "HYM302 Library" aus, um die Bibliothek in Ihrem Projekt zu verwenden.

## Verwendung

Um die HYM302 Library in Ihrem Arduino-Projekt zu verwenden, fügen Sie die `#include`-Anweisung am Anfang Ihres Sketches hinzu:

```
#include <HYM302Library.h>

Erstellen Sie dann eine Instanz der HYM302Library-Klasse:

HYM302Library hym302;

Verwenden Sie die verschiedenen Funktionen der Bibliothek, um auf die Funktionen des HY-M302 Shields zuzugreifen.
Beispiel

Hier ist ein einfaches Beispiel, wie Sie die LED1 des HY-M302 Shields steuern können:

#include <HYM302Library.h>

HYM302Library hym302;

void setup() {
  hym302.getPins();
  pinMode(hym302.LED1Pin, OUTPUT);
}

void loop() {
  hym302.controlLED(hym302.LED1Pin, HIGH); // LED1 einschalten
  delay(1000);
  hym302.controlLED(hym302.LED1Pin, LOW); // LED1 ausschalten
  delay(1000);
}

```

Funktionen
Die HYM302 Library bietet verschiedene Funktionen zur Steuerung der Komponenten des HY-M302 Shields, darunter:
*Steuerung von LEDs
*Lesen des Zustands von Tastern
*Messung der Temperatur und Luftfeuchtigkeit mit dem DHT11-Sensor
*Messung der Temperatur mit dem LM35-Sensor
*Messung des Potentiometerwerts
*Messung des Fotowiderstandswerts
*Steuerung einer RGB-LED (Rot, Grün, Blau)
*Steuerung eines Buzzers

Funktionen
void getPins()
Diese Funktion gibt die Konfiguration der Pin-Belegungen für das HY-M302 Shield zurück.

void controlLED(int LED, bool state)
Diese Funktion ermöglicht die Steuerung einer LED auf dem HY-M302 Shield.
    LED: Der Pin der zu steuernden LED.
    state: Der Zustand, den die LED haben soll (HIGH für Ein, LOW für Aus).

void toggleLED(int LED)
Diese Funktion ändert den Zustand einer LED (von Ein auf Aus oder umgekehrt).
    LED: Der Pin der zu steuernden LED.

bool getLEDState(int LED)
Diese Funktion gibt den aktuellen Zustand einer LED zurück.
    LED: Der Pin der zu überprüfenden LED.

int readButton(int Button)
Diese Funktion liest den Zustand eines Tasters und gibt den Wert zurück (HIGH oder LOW).
    Button: Der Pin des Tasters.

void readDHT11(int* temperature, int* humidity)
Diese Funktion liest die Temperatur und Luftfeuchtigkeit von einem DHT11-Sensor aus und gibt die Werte in den übergebenen Zeigern zurück.
    temperature: Ein Zeiger auf eine Variable zur Speicherung der Temperatur.
    humidity: Ein Zeiger auf eine Variable zur Speicherung der Luftfeuchtigkeit.

float readLM35()
Diese Funktion liest die Temperatur von einem LM35-Sensor aus und gibt den Wert als Gleitkommazahl zurück.

int readPotentiometer()
Diese Funktion liest den Wert eines Potentiometers und gibt ihn zurück.

int readPhotoresistor()
Diese Funktion liest den Wert eines Fotowiderstands und gibt ihn zurück.

void controlRGBLED(int redPin, int greenPin, int bluePin, int redState, int greenState, int blueState)
Diese Funktion ermöglicht die Steuerung einer RGB-LED (Rot, Grün, Blau).

    redPin, greenPin, bluePin: Die Pins für Rot, Grün und Blau der RGB-LED.
    redState, greenState, blueState: Die Zustände (HIGH oder LOW) für Rot, Grün und Blau.

void controlBuzzer(int pin, int frequency, int duration)
Diese Funktion ermöglicht die Steuerung eines Buzzers.
    pin: Der Pin des Buzzers.
    frequency: Die Frequenz des Signals.
    duration: Die Dauer des Signals.


Weitere Informationen zu diesen Funktionen finden Sie in der Dokumentation der Bibliothek.
Lizenz

Diese Bibliothek ist unter der MIT-Lizenz lizenziert.
