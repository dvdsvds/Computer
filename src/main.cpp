#include <iostream>
#include <bitset>
#include "alu.hpp"

// 8비트 출력을 보기 좋게 표시하기 위한 헬퍼
void print_binary(const Binary& bin) {
    for (bool b : bin) std::cout << b;
}

void print_flags(const Flags& f) {
    std::cout << "  C:" << f.C
              << " Z:" << f.Z
              << " N:" << f.N
              << " V:" << f.V;
}

int main() {
    // 테스트용 데이터
    Binary a = {0,0,0,0,1,0,1,0}; // 10
    Binary b = {0,0,0,0,0,1,0,1}; // 5

    std::cout << "============================\n";
    std::cout << "[Arithmetic Tests]\n";

    auto add = alu::execute(OPCODE::ADD, a, b, true);
    std::cout << "ADD: "; print_binary(add.first); print_flags(add.second); std::cout << "\n";

    auto sub = alu::execute(OPCODE::SUB, a, b, true);
    std::cout << "SUB: "; print_binary(sub.first); print_flags(sub.second); std::cout << "\n";

    auto inc = alu::execute(OPCODE::INC, a);
    std::cout << "INC: "; print_binary(inc.first); print_flags(inc.second); std::cout << "\n";

    auto dec = alu::execute(OPCODE::DEC, a);
    std::cout << "DEC: "; print_binary(dec.first); print_flags(dec.second); std::cout << "\n";

    auto neg = alu::execute(OPCODE::NEG, a);
    std::cout << "NEG: "; print_binary(neg.first); print_flags(neg.second); std::cout << "\n";

    auto cmp = alu::execute(OPCODE::CMP, a, b, true);
    std::cout << "CMP: (no result)"; print_flags(cmp.second); std::cout << "\n";


    std::cout << "\n============================\n";
    std::cout << "[Logical Tests]\n";

    auto _and = alu::execute(OPCODE::AND, a, b, false);
    std::cout << "AND: "; print_binary(_and.first); print_flags(_and.second); std::cout << "\n";

    auto _or = alu::execute(OPCODE::OR, a, b, false);
    std::cout << "OR : "; print_binary(_or.first); print_flags(_or.second); std::cout << "\n";

    auto _xor = alu::execute(OPCODE::XOR, a, b, false);
    std::cout << "XOR: "; print_binary(_xor.first); print_flags(_xor.second); std::cout << "\n";

    auto _not = alu::execute(OPCODE::NOT, a);
    std::cout << "NOT: "; print_binary(_not.first); print_flags(_not.second); std::cout << "\n";

    auto test = alu::execute(OPCODE::TEST, a, b, false);
    std::cout << "TEST: (no result)"; print_flags(test.second); std::cout << "\n";


    std::cout << "\n============================\n";
    std::cout << "[Shift Tests]\n";

    Binary sh = a;
    auto shl = alu::execute(OPCODE::SHL, sh, 1);
    std::cout << "SHL: "; print_binary(shl.first); print_flags(shl.second); std::cout << "\n";

    sh = a;
    auto shr = alu::execute(OPCODE::SHR, sh, 1);
    std::cout << "SHR: "; print_binary(shr.first); print_flags(shr.second); std::cout << "\n";

    sh = a;
    auto sal = alu::execute(OPCODE::SAL, sh, 1);
    std::cout << "SAL: "; print_binary(sal.first); print_flags(sal.second); std::cout << "\n";

    sh = a;
    auto sar = alu::execute(OPCODE::SAR, sh, 1);
    std::cout << "SAR: "; print_binary(sar.first); print_flags(sar.second); std::cout << "\n";


    std::cout << "\n============================\n";
    std::cout << "[Rotate Tests]\n";

    Binary ro = a;
    auto rol = alu::execute(OPCODE::ROL, ro, 1);
    std::cout << "ROL: "; print_binary(rol.first); print_flags(rol.second); std::cout << "\n";

    ro = a;
    auto ror = alu::execute(OPCODE::ROR, ro, 1);
    std::cout << "ROR: "; print_binary(ror.first); print_flags(ror.second); std::cout << "\n";

    ro = a;
    auto rcl = alu::execute(OPCODE::RCL, ro, 1);
    std::cout << "RCL: "; print_binary(rcl.first); print_flags(rcl.second); std::cout << "\n";

    ro = a;
    auto rcr = alu::execute(OPCODE::RCR, ro, 1);
    std::cout << "RCR: "; print_binary(rcr.first); print_flags(rcr.second); std::cout << "\n";

    std::cout << "============================\n";
}
