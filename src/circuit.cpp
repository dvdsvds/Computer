#include "circuit.hpp"
#include "lg.hpp"

namespace circuit {
    std::pair<bool, bool> HA(const bool& a, const bool& b) {
        bool sum = gate::XOR(a, b);
        bool carry = gate::AND(a, b);
        return {sum, carry};
    }   
} 
