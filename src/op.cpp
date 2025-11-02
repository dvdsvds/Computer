#include "lg.hpp"
#include "op.hpp"
#include "dlc.hpp"

namespace operators {
    std::pair<std::array<bool, BIT>, Flags> ADD(const std::array<bool, BIT>& a, const std::array<bool, BIT>& b, const bool& is_signed) {
        auto [sum, carry] = adders::RCA(a, b);

        Flags f{};
        f.C = carry;
        if(is_signed) {
            f.V = (a[MSB] == b[MSB]) && (sum[MSB] != a[MSB]);
        } else {
            f.V = false;
        }

        f.N = sum[MSB];
        f.Z = true;
        for(bool bit : sum) {
            if(bit) {
                f.Z = false;
                break;
            }
        }

        return {sum, f};
    }

    std::pair<std::array<bool, BIT>, Flags> SUB(const std::array<bool, BIT>& a, const std::array<bool, BIT>& b, const bool& is_signed) {
        auto [sum, carry] = subtractors::RBS(a, b);

        Flags f{};
        f.C = !carry;
        if(is_signed) {
            f.V = (a[MSB] != b[MSB]) && (sum[MSB] != a[MSB]);
        } else {
            f.V = false;
        }
        f.N = sum[MSB];
        f.Z = true;
        for(bool bit : sum) {
            if(bit) {
                f.Z = false;
                break;
            }
        }

        return {sum, f};
    }

    std::pair<std::array<bool, BIT>, Flags> INC(const std::array<bool, BIT>& a, const bool& is_signed) {
        auto [sum, carry] = adders::RCA(a, one);

        Flags f{};
        f.C = carry;
        f.N = sum[MSB];
        f.Z = true;
        for(bool bit : sum) {
            if(bit) {
                f.Z = false;
                break;
            }
        }
        f.V = is_signed && (a[MSB] == 0 && sum[MSB] == 1);

        return {sum, f};
    }
    std::pair<std::array<bool, BIT>, Flags> DEC(const std::array<bool, BIT>& a, const bool& is_signed) {
        auto [sum, carry] = subtractors::RBS(a, one);

        Flags f{};
        f.C = carry;
        f.N = sum[MSB];
        f.Z = true;
        for(bool bit : sum) {
            if(bit) {
                f.Z = false;
                break;
            }
        }
        f.V = is_signed && (a[MSB] == 1 && sum[MSB] == 0);

        return {sum, f};
    }
    std::pair<std::array<bool, BIT>, Flags> NEG(const std::array<bool, BIT>& a, const bool& is_signed);
    std::pair<std::array<bool, BIT>, Flags> CMP(const std::array<bool, BIT>& a, const std::array<bool, BIT>& b, const bool& is_signed);
}