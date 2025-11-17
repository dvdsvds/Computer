#include "alu.hpp"

namespace alu {
    OResult execute_al(OPCODE opcode, const Binary& a, const Binary& b, bool is_signed) {
        switch (opcode)
        {
            case OPCODE::ADD: return arithmetics::ADD(a, b, is_signed);
            case OPCODE::SUB: return arithmetics::SUB(a, b, is_signed);
            case OPCODE::INC: return arithmetics::INC(a, is_signed);
            case OPCODE::DEC: return arithmetics::DEC(a, is_signed);
            case OPCODE::NEG: return arithmetics::NEG(a, is_signed);
            case OPCODE::CMP: {
                Flags f = arithmetics::CMP(a, b, is_signed);
                Binary binary = {};

                return {binary, f};
            }

            case OPCODE::AND: return logical::AND(a, b);
            case OPCODE::OR: return logical::OR(a, b);
            case OPCODE::XOR: return logical::XOR(a, b);
            case OPCODE::NOT: return logical::NOT(a);
            case OPCODE::TEST: {
                Flags f = logical::TEST(a, b);
                Binary binary = {};

                return {binary, f};
            }

            default:
                Binary zero{}; 
                Flags f{};

                return {zero, f};
        }
    }

    OResult execute_sr(OPCODE opcode, Binary& a, int count) {
        switch (opcode)
        {
            case OPCODE::SHL: return shift::SHL(a, count);
            case OPCODE::SHR: return shift::SHR(a, count);
            case OPCODE::SAL: return shift::SAL(a, count);
            case OPCODE::SAR: return shift::SAR(a, count);
            
            case OPCODE::ROL: return rotate::ROL(a, count);
            case OPCODE::ROR: return rotate::ROR(a, count);
            case OPCODE::RCL: return rotate::RCL(a, count);
            case OPCODE::RCR: return rotate::RCR(a, count);
                

            default:
                Binary zero{}; 
                Flags f{};
                return {zero, f};
        }

    }
    // ADD, SUB, AND, OR, XOR, CMP, TEST
    OResult execute(OPCODE opcode, const Binary& a, const Binary& b, bool is_signed) {
        return execute_al(opcode, a, b, is_signed);
    }

    // SHL, SHR, SAL, SAR, ROL, ROR, RCL, RCR
    OResult execute(OPCODE opcode, Binary& a, int count) {
        return execute_sr(opcode, a, count);
    }

    OResult execute(OPCODE opcode, const Binary& a, int count) {
        Binary temp = a;
        return execute_sr(opcode, temp, count);
    }

    // INC, DEC, NEG, NOT
    OResult execute(OPCODE opcode, const Binary& a) {
        return execute_al(opcode, a);
    }
}