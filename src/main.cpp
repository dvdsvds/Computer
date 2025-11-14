#include <iostream>
#include "alu.hpp"
#include "register.hpp"

int main() {
    ACC acc;
    GR gr;
    FR fr;

    // ---- [1] 입력값 준비 ----
    Binary a = {0,0,0,0,1,0,1,0}; // 10
    Binary b = {0,0,0,0,0,1,0,1}; // 5

    // GR에 피연산자 저장
    gr.setControl(true, false);
    gr.LOAD(b);

    // ACC에 피연산자 저장
    acc.setControl(true, false);
    acc.LOAD(a);

    gr.setControl(false, true);
    acc.setControl(false, true);
    // ---- [2] alu 연산 (ADD 예시) ----
    auto [result, flags] = alu::execute(OPCODE::ADD, acc.READ(), gr.READ(), true);


    // ---- [3] 결과를 ACC와 FR에 저장 ----
    acc.setControl(true, false);
    acc.LOAD(result);

    fr.setControl(true);
    fr.LOAD(flags);

    // ---- [4] 출력 ----
    acc.setControl(false, true);
    std::cout << "[alu ADD RESULT] ";
    for (bool bit : acc.READ()) std::cout << bit;
    std::cout << "\n";

    auto f = fr.READ();
    std::cout << "[FLAGS] "
              << "C:" << f.C << " "
              << "Z:" << f.Z << " "
              << "N:" << f.N << " "
              << "V:" << f.V << "\n";

    // ---- [5] CLEAR 테스트 ----
    acc.CLEAR();
    gr.CLEAR();
    fr.CLEAR();

    std::cout << "[ACC CLEAR] ";
    for (bool bit : acc.READ()) std::cout << bit;
    std::cout << "\n";
    auto f2 = fr.READ();
    std::cout << "[FR CLEAR] "
              << "C:" << f2.C << " Z:" << f2.Z << " N:" << f2.N << " V:" << f2.V << "\n";

    return 0;
}
