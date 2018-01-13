#include <Arduino.h>
#include <OneButton.h>
#include "callbacks.h"
#include "pins.h"

//#define USE_SERIAL

int status;

OneButton irSensor(8, true); // NOLINT

void setup() {
    #ifdef USE_SERIAL
        Serial.begin(9600);

        // wait for serial port to connect. Needed for Leonardo only
        while (!Serial);
    #endif

    irSensor.setPressTicks(50);

    //pinMode (SIGNAL_PIN, INPUT); // Sensor output
    pinMode (LED_PIN, OUTPUT); // LED

    irSensor.attachDuringLongPress(onIRSensorOn);
    irSensor.attachLongPressStop(onIRSensorOff);
}

void loop() {
    irSensor.tick();
    //status = digitalRead(SIGNAL_PIN);
    //digitalWrite(LED_PIN,status == LOW ? HIGH : LOW);

    #ifdef USE_SERIAL
        Serial.println(String("Sensor: ") + (status == LOW ? "HIGH" : "LOW"));
    #endif

    delay (50); //wait half a second
}

