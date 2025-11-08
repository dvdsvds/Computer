#include "alu.hpp"

namespace alu {
    ALUResult execute_core(OPCODE opcode, Binary& a, Binary& b = {}, bool is_signed = false, int count = 1) {
        switch (opcode)
        {
            case OPCODE::ADD:
                return arithmetics::ADD(a, b, is_signed);
                break;
            case OPCODE::SUB:
                return arithmetics::ADD(a, b, is_signed);
                break;
            case OPCODE::INC:
                return arithmetics::INC(a, is_signed);
                break;
            case OPCODE::DEC:
                return arithmetics::DEC(a, is_signed);
                break;
            case OPCODE::NEG:
                return arithmetics::NEG(a, is_signed);
                break;
            case OPCODE::CMP:
                Flags f = arithmetics::CMP(a, b, is_signed);
                Binary binary = {};
                return {binary, f};
                break;

            case OPCODE::AND:
                return logical::AND(a, b);
                break;
            case OPCODE::OR:
                return logical::OR(a, b);
                break;
            case OPCODE::XOR:
                return logical::XOR(a, b);
                break;
            case OPCODE::NOT:
                return logical::NOT(a);
                break;
            case OPCODE::TEST:
                Flags f = logical::TEST(a, b);
                Binary binary = {};
                return {binary, f};
                break;
            
            case OPCODE::SHL:
                return shift::SHL(a, count);
                break;
            
        }
    }

    ALUResult execute(OPCODE opcode, const Binary& a) {

    }
}