#include "adder.h"
#include <iostream>

using namespace std;

int main() {
	DigitalSignal A = ON; // 0
	DigitalSignal B = OFF; // 1
	DigitalSignal sum, carry;

	Half_Adder(A, B, &sum, &carry);
	cout << "A:"  << A << " B:" << B << " => SUM:"  << sum << " CARRY:" << carry << endl;
} 
