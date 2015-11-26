#include <Arduino.h>

#include "stepper.h"

int buttonL = 12;
int buttonR = 13;

Stepper *stepper;

void setup() {
    pinMode(buttonL, INPUT);
    pinMode(buttonR, INPUT);

    stepper = new Stepper(8, 9, 10, 11);
    stepper->init();
}

void loop() {
    int left = digitalRead(buttonL);
    int right = digitalRead(buttonR);

    if (right == HIGH) {
        stepper->rotate(Stepper::RIGHT);
    } else if (left == HIGH) {
        stepper->rotate(Stepper::LEFT);
    } else {
        stepper->rotate(Stepper::NONE);
    }
}
