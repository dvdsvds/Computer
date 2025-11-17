#pragma once

namespace isa {
    enum class OPCODE {
        ADD, SUB, INC, DEC, NEG, CMP,
        AND, OR, XOR, NOT,
        SHL, SHR,
        ROL, ROR,
        MOV, LOAD, STORE,
        PUSH, POP,
        CALL, RET,
        JMP, JZ, JNZ, JC, JNC, HALT
    };
}