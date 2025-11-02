#include "dlc.hpp"
#include "lg.hpp"

#define BIT 8
namespace adders {
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

    std::pair<std::array<bool, BIT>, bool> RCA(const std::array<bool, BIT>& a, const std::array<bool, BIT>& b) {
        std::pair<bool, bool> result;

        std::array<bool, BIT> sum;
        bool carry = false;

        for(int i = a.size() - 1; i >= 0; --i) {
            result = FA(a[i], b[i], carry); 
            sum[i] = result.first;
            carry = result.second;
        }

        return {sum, carry};
    }
} 

namespace subtractors {
    std::pair<bool, bool> HS(const bool& a, const bool& b) {
        bool D = gate::XOR(a, b);
        bool B_out = gate::AND(gate::NOT(a), b);

        return {D, B_out};
    }

    std::pair<bool, bool> FS(const bool& a, const bool& b, const bool& Bin) {
        std::pair<bool, bool> FHS = HS(a, b);
        std::pair<bool, bool> NHS = HS(FHS.first, Bin);

        return {NHS.first, (FHS.second || NHS.second)};
    }
    
    std::pair<std::array<bool, BIT>, bool> RBS(const std::array<bool, BIT>& a, const std::array<bool, BIT>& b) {
        std::pair<bool, bool> result;

        std::array<bool, 8> sum;
        bool carry = false;

        for(int i = a.size() - 1; i >= 0; --i) {
            result = FS(a[i], b[i], carry); 
            sum[i] = result.first;
            carry = result.second;
        }

        return {sum, carry};
    }
}