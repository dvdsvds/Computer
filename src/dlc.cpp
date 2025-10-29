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

    std::pair<std::array<bool, 8>, bool> RCA(const std::array<bool, 8>& a, const std::array<bool, 8>& b) {
        std::pair<bool, bool> result;
        std::array<bool, 8> sum;
        bool carry = false;

        for(int i = a.size() - 1; i >= 0; --i) {
            result = FA(a[i], b[i], carry); 
            sum[i] = result.first;
            carry = result.second;
        }

        return {sum, carry};
    }
} 
