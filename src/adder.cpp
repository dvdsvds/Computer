#include "adder.hpp"

void Half_Adder(DigitalSignal A, DigitalSignal B, DigitalSignal* SUM, DigitalSignal* CARRY) {
	*SUM = XOR(A, B);
	*CARRY = AND(A, B);
}

void Full_Adder(DigitalSignal A, DigitalSignal B, DigitalSignal CARRY_IN, DigitalSignal* SUM, DigitalSignal* CARRY_OUT) {
    DigitalSignal sum1, carry1, carry2;

    Half_Adder(A, B, &sum1, &carry1);
    Half_Adder(sum1, CARRY_IN, SUM, &carry2);

    *CARRY_OUT = OR(carry1, carry2);
}
