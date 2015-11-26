#include <Arduino.h>

#include "stepper.h"

Stepper::Stepper(int a, int b, int c, int d) {
    this->a = a;
    this->b = b;
    this->c = c;
    this->d = d;
}

void Stepper::init() {
    pinMode(this->a, OUTPUT);
    pinMode(this->b, OUTPUT);
    pinMode(this->c, OUTPUT);
    pinMode(this->d, OUTPUT);
}

void Stepper::rotate(enum Direction dir) {
    if (dir == RIGHT) {
        if (counter < 8) {
            counter++;
        } else {
            counter = 1;
        }
        this->makeMove(counter);
    } else if (dir == LEFT) {
        if (counter > 1) {
            counter--;
        } else {
            counter = 8;
        }
        this->makeMove(counter);
    } else if (dir == NONE) {
        digitalWrite(this->a, LOW);
        digitalWrite(this->b, LOW);
        digitalWrite(this->c, LOW);
        digitalWrite(this->d, LOW);
    }
    delay(this->t);
}

void Stepper::makeMove(int counter) {
    switch (counter) {
        case 1:
            digitalWrite(this->a, HIGH);
            break; //ad
        case 2:
            digitalWrite(this->d, LOW);
            break; //a
        case 3:
            digitalWrite(this->b, HIGH);
            break; // ab
        case 4:
            digitalWrite(this->a, LOW);
            break; //b
        case 5:
            digitalWrite(this->c, HIGH);
            break; //bc
        case 6:
            digitalWrite(this->b, LOW);
            break; //c
        case 7:
            digitalWrite(this->d, HIGH);
            break; //cd
        case 8:
            digitalWrite(this->c, LOW);
            break; //d
    }
}