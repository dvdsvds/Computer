#pragma once
#include <array>
#include "types.hpp"

namespace arithmetics {
    constexpr Binary one = {0,0,0,0,0,0,0,1};

    OResult ADD(const Binary& a, const Binary& b, bool is_signed);
    OResult SUB(const Binary& a, const Binary& b, bool is_signed);
    OResult INC(const Binary& a, bool is_signed);
    OResult DEC(const Binary& a, bool is_signed);
    OResult NEG(const Binary& a, bool is_signed);
    Flags CMP(const Binary& a, const Binary& b, bool is_signed);
};

namespace logical {
    OResult AND(const Binary& a, const Binary& b);
    OResult OR(const Binary& a, const Binary& b);
    OResult XOR(const Binary& a, const Binary& b);
    OResult NOT(const Binary& a);
    Flags TEST(const Binary& a, const Binary& b);
}

namespace shift {
    OResult SHL(Binary& a, int count);
    OResult SHR(Binary& a, int count);
    OResult SAL(Binary& a, int count);
    OResult SAR(Binary& a, int count);
}

namespace rotate {
    OResult ROL(Binary& a, int count);
    OResult ROR(Binary& a, int count);
    OResult RCL(Binary& a, int count);
    OResult RCR(Binary& a, int count);
}