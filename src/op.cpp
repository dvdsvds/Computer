#include "lg.hpp"
#include "op.hpp"
#include "dlc.hpp"

namespace arithmetics {
    std::pair<std::array<bool, BIT>, Flags> ADD(const std::array<bool, BIT>& a, const std::array<bool, BIT>& b, const bool& is_signed) {
        auto [result, carry] = adders::RCA(a, b);

        Flags f{};
        f.C = carry;
        if(is_signed) {
            f.V = (a[MSB] == b[MSB]) && (result[MSB] != a[MSB]);
        } else {
            f.V = false;
        }

        f.N = result[MSB];
        f.Z = true;
        for(bool bit : result) {
            if(bit) {
                f.Z = false;
                break;
            }
        }

        return {result, f};
    }

    std::pair<std::array<bool, BIT>, Flags> SUB(const std::array<bool, BIT>& a, const std::array<bool, BIT>& b, const bool& is_signed) {
        auto [result, carry] = subtractors::RBS(a, b);

        Flags f{};
        f.C = !carry;
        if(is_signed) {
            f.V = (a[MSB] != b[MSB]) && (result[MSB] != a[MSB]);
        } else {
            f.V = false;
        }
        f.N = result[MSB];
        f.Z = true;
        for(bool bit : result) {
            if(bit) {
                f.Z = false;
                break;
            }
        }

        return {result, f};
    }

    std::pair<std::array<bool, BIT>, Flags> INC(const std::array<bool, BIT>& a, const bool& is_signed) {
        auto [result, carry] = adders::RCA(a, one);

        Flags f{};
        f.C = carry;
        f.N = result[MSB];
        f.Z = true;
        for(bool bit : result) {
            if(bit) {
                f.Z = false;
                break;
            }
        }
        f.V = is_signed && (a[MSB] == 0 && result[MSB] == 1);

        return {result, f};
    }

    std::pair<std::array<bool, BIT>, Flags> DEC(const std::array<bool, BIT>& a, const bool& is_signed) {
        auto [result, carry] = subtractors::RBS(a, one);

        Flags f{};
        f.C = carry;
        f.N = result[MSB];
        f.Z = true;
        for(bool bit : result) {
            if(bit) {
                f.Z = false;
                break;
            }
        }
        f.V = is_signed && (a[MSB] == 1 && result[MSB] == 0);

        return {result, f};
    }

    std::pair<std::array<bool, BIT>, Flags> NEG(const std::array<bool, BIT>& a, const bool& is_signed) {
        std::array<bool, BIT> zero = {0,0,0,0,0,0,0,0};
        auto [result, carry] = subtractors::RBS(zero, a);

        Flags f{};
        f.C = carry;
        f.N = result[MSB];
        f.Z = true;
        for(bool bit : result) {
            if(bit) {
                f.Z = false;
                break;
            }
        }
        
        f.V = std::equal(result.begin(), result.end(), std::array<bool, BIT>{1,0,0,0,0,0,0,0}.begin());

        return {result, f};
    }

    Flags CMP(const std::array<bool, BIT>& a, const std::array<bool, BIT>& b, const bool& is_signed) {
        auto [result, carry] = subtractors::RBS(a, b);

        Flags f{};
        f.C = carry;
        f.N = result[MSB];
        f.Z = true;
        for(bool bit : result) {
            if(bit) {
                f.Z = false;
                break;
            }
        }
        f.V = is_signed && (a[MSB] == 1 && result[MSB] == 0);

        return f;
    }
};

namespace logical {
    std::pair<std::array<bool, BIT>, Flags> AND(const std::array<bool, BIT>& a, const std::array<bool, BIT>& b) {
        std::array<bool, 8> result;
        for(size_t i = MSB; i <= LSB; ++i) {
            result[i] = gate::AND(a[i], b[i]);
        }

        Flags f{};
        f.N = result[MSB];
        f.Z = true;
        for(bool bit : result) {
            if(bit) {
                f.Z = false;
                break;
            }
        }

        f.C = false;
        f.V = false;
        return {result, f};
    }

    std::pair<std::array<bool, BIT>, Flags> OR(const std::array<bool, BIT>& a, const std::array<bool, BIT>& b) {
        std::array<bool, 8> result;
        for(size_t i = MSB; i <= LSB; ++i) {
            result[i] = gate::OR(a[i], b[i]);
        }

        Flags f{};
        f.N = result[MSB];
        f.Z = true;
        for(bool bit : result) {
            if(bit) {
                f.Z = false;
                break;
            }
        }

        f.C = false;
        f.V = false;
        return {result, f};
    }

    std::pair<std::array<bool, BIT>, Flags> XOR(const std::array<bool, BIT>& a, const std::array<bool, BIT>& b) {
        std::array<bool, 8> result;
        for(size_t i = MSB; i <= LSB; ++i) {
            result[i] = gate::XOR(a[i], b[i]);
        }

        Flags f{};
        f.N = result[MSB];
        f.Z = true;
        for(bool bit : result) {
            if(bit) {
                f.Z = false;
                break;
            }
        }

        f.C = false;
        f.V = false;
        return {result, f};
    }

    std::pair<std::array<bool, BIT>, Flags> NOT(const std::array<bool, BIT>& a) {
        std::array<bool, 8> result;
        for(size_t i = MSB; i <= LSB; ++i) {
            result[i] = gate::NOT(a[i]);
        }

        Flags f{};
        f.N = result[MSB];
        f.Z = true;
        for(bool bit : result) {
            if(bit) {
                f.Z = false;
                break;
            }
        }

        f.C = false;
        f.V = false;
        return {result, f};
    }

    Flags TEST(const std::array<bool, BIT>& a, const std::array<bool, BIT>& b) {
        std::array<bool, 8> result;
        for(size_t i = MSB; i <= LSB; ++i) {
            result[i] = gate::AND(a[i], b[i]);
        }

        Flags f{};
        f.N = result[MSB];
        f.Z = true;
        for(bool bit : result) {
            if(bit) {
                f.Z = false;
                break;
            }
        }

        f.C = false;
        f.V = false;
        return f;
    }
}