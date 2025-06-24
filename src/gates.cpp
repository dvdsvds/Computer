#include "gates.hpp"

// 둘 다 1일 때만 1
DigitalSignal AND(DigitalSignal A, DigitalSignal B) {
	if (A == ON) {
		if (B == ON) {
			return ON;
		}
		else if(B == OFF) {
			return OFF;
		}
	}
	else if (A == OFF) {
		if (B == ON) {
			return OFF;
		}
		else if (B == OFF) {
			return OFF;
		}
	}
  throw std::invalid_argument("Invalid DigitalSingal input to AND function.");
}

// 둘 중 하나라도 1이면 1
DigitalSignal OR(DigitalSignal A, DigitalSignal B) {
	if (A == ON) {
		if (B == ON) {
			return ON;
		}
		else if(B == OFF) {
			return ON;
		}
	}
	else if(A == OFF) {
		if (B == ON) {
			return ON;
		}
		else if (B == OFF) {
			return OFF;
		}
	}
  throw std::invalid_argument("Invalid DigitalSingal input to OR function.");
}

// 입력의 반댓값
DigitalSignal NOT(DigitalSignal A) {
	if (A == OFF) {
		return ON;
	}
	else {
		return OFF;
	}
}

// AND의 결과가 OFF면 ON 
DigitalSignal NAND(DigitalSignal A, DigitalSignal B) {
	return NOT(AND(A, B));
} 

// 둘 중 하나라도 1이면 0
DigitalSignal NOR(DigitalSignal A, DigitalSignal B) {
	return NOT(OR(A, B));
}

// 둘이 다르면 1
DigitalSignal XOR(DigitalSignal A, DigitalSignal B) {
	if (A != B) {
		return ON;
	}
	else {
		return OFF;
	}
}

// 둘이 같으면 1
DigitalSignal XNOR(DigitalSignal A, DigitalSignal B) {
	if (A == B) {
		return ON;
	}
	else {
		return OFF;
	}

} 
