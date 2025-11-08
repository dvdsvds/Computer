#include "dlc.hpp"
#include "lg.hpp"

namespace adders {
    std::pair<bool, bool> HA(bool a, bool b) {
        bool sum = gate::XOR(a, b);
        bool carry = gate::AND(a, b);
        return {sum, carry};
    }   

    std::pair<bool, bool> FA(bool a, bool b, bool Cin) {
        std::pair<bool, bool> FHA = HA(a, b);
        std::pair<bool, bool> NHA = HA(FHA.first, Cin);

        return {NHA.first , (FHA.second || NHA.second)};
    }

    std::pair<Binary, bool> RCA(const Binary& a, const Binary& b) {
        std::pair<bool, bool> result;

        Binary sum;
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
    std::pair<bool, bool> HS(bool a, bool b) {
        bool D = gate::XOR(a, b);
        bool B_out = gate::AND(gate::NOT(a), b);

        return {D, B_out};
    }

    std::pair<bool, bool> FS(bool a, bool b, bool Bin) {
        std::pair<bool, bool> FHS = HS(a, b);
        std::pair<bool, bool> NHS = HS(FHS.first, Bin);

        return {NHS.first, (FHS.second || NHS.second)};
    }
    
    std::pair<Binary, bool> RBS(const Binary& a, const Binary& b) {
        std::pair<bool, bool> result;

        std::array<bool, BIT> sum;
        bool carry = false;

        for(int i = a.size() - 1; i >= 0; --i) {
            result = FS(a[i], b[i], carry); 
            sum[i] = result.first;
            carry = result.second;
        }

        return {sum, carry};
    }
}