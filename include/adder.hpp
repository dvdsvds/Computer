#pragma once

#include "gates.hpp"

void Half_Adder(DigitalSignal A, DigitalSignal B, DigitalSignal* SUM, DigitalSignal* CARRY);
void Full_Adder(DigitalSignal A, DigitalSignal B, DigitalSignal CARRY_IN, DigitalSignal* SUM, DigitalSignal* CARRY_OUT);
void nbitAdder(DigitalSignal A, DigitalSignal B, DigitalSignal CARRY_IN, DigitalSignal* SUM, DigitalSignal* CARRY_OUT);
