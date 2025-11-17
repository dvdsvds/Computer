#pragma once

#include <array>
#include "op.hpp"

namespace alu {
    enum class OPCODE {
        ADD, SUB, INC, DEC, NEG, CMP,
        AND, OR, XOR, NOT, TEST,
        SHL, SHR, SAL, SAR,
        ROL, ROR, RCL, RCR
    };

    OResult execute_al(OPCODE opcode, const Binary& a, const Binary& b = {}, bool is_signed = false);
    OResult execute_sr(OPCODE opcode, Binary& a, int count = 1);

    OResult execute(OPCODE opcode, const Binary& a, const Binary& b, bool is_signed);
    OResult execute(OPCODE opcode, const Binary& a, int count);
    OResult execute(OPCODE opcode, const Binary& a, int count);
    OResult execute(OPCODE opcode, const Binary& a);
}