#include "adder.h"

void Half_Adder(DigitalSignal A, DigitalSignal B, DigitalSignal* SUM, DigitalSignal* CARRY) {
	*SUM = XOR(A, B);
	*CARRY = AND(A, B);
}
