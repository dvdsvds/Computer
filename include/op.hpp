#pragma once
#include <array>
#include "types.hpp"

namespace arithmetics {
    constexpr Binary one = {0,0,0,0,0,0,0,1};

    ALUResult ADD(const Binary& a, const Binary& b, bool is_signed);
    ALUResult SUB(const Binary& a, const Binary& b, bool is_signed);
    ALUResult INC(const Binary& a, bool is_signed);
    ALUResult DEC(const Binary& a, bool is_signed);
    ALUResult NEG(const Binary& a, bool is_signed);
    Flags CMP(const Binary& a, const Binary& b, bool is_signed);
};

namespace logical {
    ALUResult AND(const Binary& a, const Binary& b);
    ALUResult OR(const Binary& a, const Binary& b);
    ALUResult XOR(const Binary& a, const Binary& b);
    ALUResult NOT(const Binary& a);
    Flags TEST(const Binary& a, const Binary& b);
}

namespace shift {
    ALUResult SHL(Binary& a, int count);
    ALUResult SHR(Binary& a, int count);
    ALUResult SAL(Binary& a, int count);
    ALUResult SAR(Binary& a, int count);
}

namespace rotate {
    ALUResult ROL(Binary& a, int count);
    ALUResult ROR(Binary& a, int count);
    ALUResult RCL(Binary& a, int count);
    ALUResult RCR(Binary& a, int count);
}