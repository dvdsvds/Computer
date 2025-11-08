#include "lg.hpp"
#include "op.hpp"
#include "dlc.hpp"

namespace arithmetics {
    ALUResult ADD(const Binary& a, const Binary& b, bool is_signed) {
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

    ALUResult SUB(const Binary& a, const Binary& b, bool is_signed) {
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

    ALUResult INC(const Binary& a, bool is_signed) {
        auto [result, carry] = adders::RCA(a, one);

        Flags f{};
        f.C = carry;
        if(is_signed) {
            f.V = is_signed && (a[MSB] == 0 && result[MSB] == 1);
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

    ALUResult DEC(const Binary& a, bool is_signed) {
        auto [result, carry] = subtractors::RBS(a, one);

        Flags f{};
        f.C = carry;
        if(is_signed) {
            f.V = is_signed && (a[MSB] == 0 && result[MSB] == 1);
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

    ALUResult NEG(const Binary& a, bool is_signed) {
        const Binary zero = {0,0,0,0,0,0,0,0};
        auto [result, carry] = subtractors::RBS(zero, a);

        Flags f{};
        f.C = carry;
        if(is_signed) {
            f.V = is_signed && (a[MSB] == 0 && result[MSB] == 1);
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
        
        f.V = std::equal(result.begin(), result.end(), Binary{1,0,0,0,0,0,0,0}.begin());

        return {result, f};
    }

    Flags CMP(const Binary& a, const Binary& b, bool is_signed) {
        auto [result, carry] = subtractors::RBS(a, b);

        Flags f{};
        f.C = carry;
        if(is_signed) {
            f.V = is_signed && (a[MSB] == 0 && result[MSB] == 1);
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

        return f;
    }
};

namespace logical {
    ALUResult AND(const Binary& a, const Binary& b) {
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

    ALUResult OR(const Binary& a, const Binary& b) {
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

    ALUResult XOR(const Binary& a, const Binary& b) {
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

    ALUResult NOT(const Binary& a) {
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

    Flags TEST(const Binary& a, const Binary& b) {
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

namespace shift {
    ALUResult SHL(Binary& a, int count) {
        Binary result;
        bool temp;
        Flags f{};

        for(int i = 0; i < count; ++i) {
            temp = a[MSB];
            f.C = temp;
            for(size_t j = MSB; j < LSB; ++j) result[j] = a[j + 1]; 
            result[LSB] = false;
            a = result;
        }

        f.N = result[MSB];
        f.Z = true;
        for(bool bit : result) {
            if(bit) {
                f.Z = false;
                break;
            }
        }
        f.V = false;
        return {result, f};
    }

    ALUResult SHR(Binary& a, int count) {
        Binary result;
        bool temp;
        Flags f{};

        for(int i = 0; i < count; ++i) {
            temp = a[LSB];
            f.C = temp;
            for(size_t j = MSB; j < LSB; ++j) result[j + 1] = a[j]; 
            result[MSB] = false;
            a = result;
        }

        f.N = result[MSB];
        f.Z = true;
        for(bool bit : result) {
            if(bit) {
                f.Z = false;
                break;
            }
        }
        f.V = false;
        return {result, f};
    }

    ALUResult SAL(Binary& a, int count) {
        Binary result;
        Flags f{};

        for(int i = 0; i < count; ++i) {
            f.C = a[MSB];
            for(size_t j = LSB; j > MSB; --j) result[j] = a[j - 1]; 
            result[MSB] = false;
            a = result;
        }

        f.N = result[MSB];
        f.Z = true;
        for(size_t i = MSB; i <= LSB; ++i) {
            if(result[i]) {
                f.Z = false;
                break;
            }
        }
        f.V = (a[MSB] != result[MSB]);
        return {result, f};

    }

    ALUResult SAR(Binary& a, int count) {
        Binary result;
        bool sign = a[MSB];
        Flags f{};

        for(int i = 0; i < count; ++i) {
            f.C = a[LSB];
            for(size_t j = LSB; j > MSB; --j) result[j] = a[j - 1]; 
            result[MSB] = sign;
            a = result;
        }

        f.N = result[MSB];
        f.Z = true;
        for(size_t i = MSB; i <= LSB; ++i) {
            if(result[i]) {
                f.Z = false;
                break;
            }
        }
        f.V = false;
        return {result, f};
    }
}

namespace rotate {
    ALUResult ROL(Binary& a, int count) {
        Binary result;
        bool temp;
        Flags f{};

        for(int i = 0; i < count; ++i) {
            temp = a[MSB];
            f.C = temp;
            for(size_t j = MSB; j < LSB; ++j) result[j] = a[j + 1]; 
            result[LSB] = temp;
            a = result;
        }

        f.N = result[MSB];
        f.Z = true;
        for(bool bit : result) {
            if(bit) {
                f.Z = false;
                break;
            }
        }
        f.V = false;
        return {result, f};
    }

    ALUResult ROR(Binary& a, int count) {
        Binary result;
        bool temp;
        Flags f{};

        for(int i = 0; i < count; ++i) {
            temp = a[LSB];
            f.C = temp;
            for(size_t j = MSB; j < LSB; ++j) result[j + 1] = a[j]; 
            result[MSB] = temp;
            a = result;
        }

        f.N = result[MSB];
        f.Z = true;
        for(bool bit : result) {
            if(bit) {
                f.Z = false;
                break;
            }
        }
        f.V = false;
        return {result, f};
    }

    ALUResult RCL(Binary& a, int count) {
        Binary result;
        bool temp;
        Flags f{};

        f.C = false;
        for(int i = 0; i < count; ++i) {
            temp = a[MSB];
            for(size_t j = MSB; j < LSB; ++j) result[j] = a[j + 1]; 
            result[LSB] = f.C;
            f.C = temp;
            a = result;
        }

        f.N = result[MSB];
        f.Z = true;
        for(bool bit : result) {
            if(bit) {
                f.Z = false;
                break;
            }
        }
        f.V = false;
        return {result, f};
    }

    ALUResult RCR(Binary& a, int count) {
        Binary result;
        bool temp;
        Flags f{};

        f.C = false;  
        for (int i = 0; i < count; ++i) {
            temp = a[LSB];                       
            for (size_t j = LSB; j > MSB; --j) result[j] = a[j - 1];
            result[MSB] = f.C;                   
            f.C = temp;                          
            a = result;                          
        }

        f.N = result[MSB];
        f.Z = true;
        for(bool bit : result) {
            if(bit) {
                f.Z = false;
                break;
            }
        }
        f.V = false;
        return {result, f};
    }
}