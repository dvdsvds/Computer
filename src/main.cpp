#include <iostream>
#include <array>
#include "op.hpp"  // 너가 올려둔 파일

using namespace std;

int main() {
    // ---- [1] ADD / SUB / INC / DEC / NEG / CMP ----
    {
        cout << "[Arithmetic Tests]\n";
        array<bool, 8> a = {0,0,0,0,1,0,1,0}; // 10
        array<bool, 8> b = {0,0,0,0,0,1,0,1}; // 5

        auto add_res = arithmetics::ADD(a, b, true);
        auto sub_res = arithmetics::SUB(a, b, true);
        auto inc_res = arithmetics::INC(a, true);
        auto dec_res = arithmetics::DEC(a, true);
        auto neg_res = arithmetics::NEG(a, true);
        auto cmp_res = arithmetics::CMP(a, b, true);

        cout << "ADD: ";
        for (auto bit : add_res.first) cout << bit;
        cout << "  C:" << add_res.second.C << " Z:" << add_res.second.Z
             << " N:" << add_res.second.N << " V:" << add_res.second.V << endl;

        cout << "SUB: ";
        for (auto bit : sub_res.first) cout << bit;
        cout << "  C:" << sub_res.second.C << " Z:" << sub_res.second.Z
             << " N:" << sub_res.second.N << " V:" << sub_res.second.V << endl;

        cout << "INC: ";
        for (auto bit : inc_res.first) cout << bit;
        cout << "  C:" << inc_res.second.C << " Z:" << inc_res.second.Z
             << " N:" << inc_res.second.N << " V:" << inc_res.second.V << endl;

        cout << "DEC: ";
        for (auto bit : dec_res.first) cout << bit;
        cout << "  C:" << dec_res.second.C << " Z:" << dec_res.second.Z
             << " N:" << dec_res.second.N << " V:" << dec_res.second.V << endl;

        cout << "NEG: ";
        for (auto bit : neg_res.first) cout << bit;
        cout << "  C:" << neg_res.second.C << " Z:" << neg_res.second.Z
             << " N:" << neg_res.second.N << " V:" << neg_res.second.V << endl;

        cout << "CMP -> C:" << cmp_res.C << " Z:" << cmp_res.Z
             << " N:" << cmp_res.N << " V:" << cmp_res.V << endl;
    }

    // ---- [2] AND / OR / XOR / NOT / TEST ----
    {
        cout << "\n[Logical Tests]\n";
        array<bool, 8> a = {1,0,1,0,1,0,1,0};
        array<bool, 8> b = {0,1,0,1,0,1,0,1};

        auto and_res = logical::AND(a, b);
        auto or_res  = logical::OR(a, b);
        auto xor_res = logical::XOR(a, b);
        auto not_res = logical::NOT(a);
        auto test_res = logical::TEST(a, b);

        cout << "AND: "; for (auto bit : and_res.first) cout << bit;
        cout << "  Z:" << and_res.second.Z << endl;

        cout << "OR : "; for (auto bit : or_res.first) cout << bit;
        cout << "  Z:" << or_res.second.Z << endl;

        cout << "XOR: "; for (auto bit : xor_res.first) cout << bit;
        cout << "  Z:" << xor_res.second.Z << endl;

        cout << "NOT: "; for (auto bit : not_res.first) cout << bit;
        cout << "  Z:" << not_res.second.Z << endl;

        cout << "TEST -> Z:" << test_res.Z << " N:" << test_res.N << endl;
    }

    // ---- [3] SHL / SHR / SAL / SAR ----
    {
        cout << "\n[Shift Tests]\n";
        array<bool, 8> a = {0,1,0,1,0,1,0,1};

        auto shl_res = shift::SHL(a, 1);
        auto shr_res = shift::SHR(a, 1);
        auto sal_res = shift::SAL(a, 1);
        auto sar_res = shift::SAR(a, 1);

        cout << "SHL: "; for (auto bit : shl_res.first) cout << bit;
        cout << "  C:" << shl_res.second.C << endl;

        cout << "SHR: "; for (auto bit : shr_res.first) cout << bit;
        cout << "  C:" << shr_res.second.C << endl;

        cout << "SAL: "; for (auto bit : sal_res.first) cout << bit;
        cout << "  C:" << sal_res.second.C << endl;

        cout << "SAR: "; for (auto bit : sar_res.first) cout << bit;
        cout << "  C:" << sar_res.second.C << endl;
    }

    // ---- [4] ROL / ROR / RCL / RCR ----
    {
        cout << "\n[Rotate Tests]\n";
        array<bool, 8> a = {1,0,0,0,0,0,0,1};

        auto rol_res = rotate::ROL(a, 1);
        auto ror_res = rotate::ROR(a, 1);
        auto rcl_res = rotate::RCL(a, 1);
        auto rcr_res = rotate::RCR(a, 1);

        cout << "ROL: "; for (auto bit : rol_res.first) cout << bit;
        cout << "  C:" << rol_res.second.C << endl;

        cout << "ROR: "; for (auto bit : ror_res.first) cout << bit;
        cout << "  C:" << ror_res.second.C << endl;

        cout << "RCL: "; for (auto bit : rcl_res.first) cout << bit;
        cout << "  C:" << rcl_res.second.C << endl;

        cout << "RCR: "; for (auto bit : rcr_res.first) cout << bit;
        cout << "  C:" << rcr_res.second.C << endl;
    }

    return 0;
}
