#include "dlc.hpp"
#include "lg.hpp"

namespace adder {
    std::pair<bool, bool> HA(const bool& a, const bool& b) {
        bool sum = gate::XOR(a, b);
        bool carry = gate::AND(a, b);
        return {sum, carry};
    }   

    std::pair<bool, bool> FA(const bool& a, const bool& b, const bool& Cin) {
        std::pair<bool, bool> FHA = HA(a, b);
        std::pair<bool, bool> NHA = HA(FHA.first, Cin);

        return {NHA.first , (FHA.second || NHA.second)};
    }
} 
