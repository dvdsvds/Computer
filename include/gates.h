#pragma once
#ifndef GATES_H
#define GATES_H

#include <stdexcept>

typedef enum {
	OFF = 0,
	ON = 1
} DigitalSignal;

DigitalSignal AND(DigitalSignal A, DigitalSignal B);
DigitalSignal OR(DigitalSignal A, DigitalSignal B);
DigitalSignal NOT(DigitalSignal A);
DigitalSignal NAND(DigitalSignal A, DigitalSignal B);
DigitalSignal NOR(DigitalSignal A, DigitalSignal B);
DigitalSignal XOR(DigitalSignal A, DigitalSignal B);
DigitalSignal XNOR(DigitalSignal A, DigitalSignal B);

#endif
