//
// Created by Mike Mitterer on 13.01.18.
//
#include <Arduino.h>
#include "pins.h"

void onIRSensorOn() {
    digitalWrite(LED_PIN,HIGH);
}

void onIRSensorOff() {
    digitalWrite(LED_PIN,LOW);
}


