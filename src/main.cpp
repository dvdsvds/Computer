#include "adder.hpp"
#include <iostream>

using namespace std;

int main() {
	DigitalSignal A = ON;
	DigitalSignal B = ON; 
    DigitalSignal CARRY_IN = ON;

	DigitalSignal SUM, CARRY_OUT;
    Full_Adder(A, B, CARRY_IN, &SUM, &CARRY_OUT);

	cout << "       SUM:" << SUM << endl; 
    cout << " CARRY OUT:" << CARRY_OUT << endl;
} 
