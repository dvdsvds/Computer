#include "lg.hpp"
#include "op.hpp"
#include "dlc.hpp"

namespace operators {
    std::pair<std::array<bool, BIT>, Flags> ADD(const std::array<bool, BIT>& a, const std::array<bool, BIT>& b) {
        auto [sum, carry] = adders::RCA(a, b);

        Flags f{};
        f.C = carry;
        f.N = sum[0];
        f.Z = true;
        for(bool bit : sum) {
            if(bit) {
                f.Z = false;
                break;
            }
        }
        f.V = (a[0] == b[0]) && (sum[0] != a[0]);

        return {sum, f};
    }

    std::pair<std::array<bool, BIT>, Flags> SUB(const std::array<bool, BIT>& a, const std::array<bool, BIT>& b) {
        auto [sum, carry] = subtractors::RBS(a, b);

        Flags f{};
        f.C = !carry;
        f.N = sum[0];
        f.Z = true;
        for(bool bit : sum) {
            if(bit) {
                f.Z = false;
                break;
            }
        }
        f.V = (a[0] != b[0]) && (sum[0] != a[0]);

        return {sum, f};
    }
}