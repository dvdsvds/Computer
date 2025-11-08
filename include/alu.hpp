#pragma once

#include <array>
#include "op.hpp"

enum class OPCODE {
    ADD, SUB, INC, DEC, NEG, CMP,
    AND, OR, XOR, NOT, TEST,
    SHL, SHR, SAL, SAR,
    ROL, ROR, RCL, RCR
};

namespace alu {
    ALUResult execute_core(OPCODE opcode, const Binary& a, const Binary& b = {}, bool is_signed = false, int count = 1);
    ALUResult execute(OPCODE opcode, const Binary& a, const Binary& b, bool is_signed);
    ALUResult execute(OPCODE opcode, const Binary& a, int count);
    ALUResult execute(OPCODE opcode, const Binary& a);
}