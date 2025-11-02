#include "lg.hpp"
#include "dlc.hpp"
#include "op.hpp"
#include <functional>

using namespace std;

int main () {
    std::array<bool, 8> a = {1,0,0,0,0,0,0,0};
    std::array<bool, 8> b = {0,1,1,1,1,1,1,1};

    bool is_signed = true;
    auto result = operators::CMP(a,b,is_signed);
    cout << " -> "
     << "C:" << result.C << " "
     << "Z:" << result.Z << " "
     << "N:" << result.N << " "
     << "V:" << result.V << endl;
    // vector<pair<string, function<bool(const bool&, const bool&)>>> gates = {
    //     {"AND", gate::AND},
    //     {"OR", gate::OR},
    //     {"NAND", gate::NAND},
    //     {"NOR", gate::NOR},
    //     {"XOR", gate::XOR},
    //     {"XNOR", gate::XNOR},
    // };

    // bool inputs[2] = {false, true};

    // for(auto& g : gates) {
    //     cout << endl << g.first << " Gate" << endl;
    //     cout << "A    B    F" << endl;
    //     cout << "-----------" << endl;

    //     for(bool a : inputs) {
    //         for(bool b : inputs) {
    //             cout << a << "    " << b << "    " << g.second(a, b) << endl;
    //         }
    //     }
    // }

    // vector<pair<string, function<bool(bool)>>> gates_1 = {
    //     {"NOT", gate::NOT},
    //     {"BUFFER", gate::BUFFER},
    // };

    // for(auto& g : gates_1) {
    //     cout << endl << g.first << " Gate" << endl;
    //     cout << "A    F" << endl;
    //     cout << "------" << endl;

    //     for(bool a : inputs) {
    //         cout << a << "    " << g.second(a)<< endl;
    //     }
    // }

    // vector<pair<string, function<pair<bool, bool>(bool, bool)>>> circuits = {
    //     {"HA", adders::HA}
    // };

    // for (auto& c : circuits) {
    //     cout << endl << c.first << " Circuit" << endl;
    //     cout << "A    B    Sum  Carry" << endl;
    //     cout << "--------------------" << endl;

    //     for (bool a : inputs) {
    //         for (bool b : inputs) {
    //             auto [sum, carry] = c.second(a, b); 
    //             cout << a << "    " << b << "     "
    //                 << sum << "     " << carry << endl;
    //         }
    //     }
    // }

    // cout << endl << "Full adders" << endl;
    // cout << "A   B   Cin   Sum   Carry" << endl;
    // cout << "-------------------------" << endl;

    // for (bool a : inputs) {
    //     for (bool b : inputs) {
    //         for (bool cin : inputs) {
    //             auto result = adders::FA(a, b, cin);
    //             cout << a << "    " << b << "    " << cin << "      "
    //                 << result.first << "      " << result.second << endl;
    //         }
    //     }
    // }
    // cout << endl;

    // auto result = adders::RCA(a, b);

    // for(auto a1 : a) {
    //     cout << a1;
    // }
    // cout << endl;

    // for(auto b1 : b) {
    //     cout << b1;
    // }
    // cout << endl;
    // cout << "========" << endl;
    // for(auto v : result.first) {
    //     cout << v;
    // }
    // cout << endl;

    // cout << "Carry : ";
    // cout << result.second << endl;


    // cout << endl << "Full Subtrator" << endl;
    // cout << "A    B   B_in   D   B_out" << endl;
    // cout << "-------------------------" << endl;

    // for (bool a : inputs) {
    //     for (bool b : inputs) {
    //         for (bool B_in : inputs) {
    //             auto result = subtractors::FS(a, b, B_in);
    //             cout << a << "    " << b << "    " << B_in << "     "
    //                 << result.first << "     " << result.second << endl;
    //         }
    //     }
    // }
    // cout << endl;
    // auto result1 = subtractors::RBS(a, b);

    // for(auto a1 : a) {
    //     cout << a1;
    // }
    // cout << endl;

    // for(auto b1 : b) {
    //     cout << b1;
    // }
    // cout << endl;
    // cout << "========" << endl;
    // for(auto v : result1.first) {
    //     cout << v;
    // }
    // cout << endl;

    // cout << "Borrow  : ";
    // cout << result1.second << endl;

    // cout << "Result(false)" << endl;
    // cout << "============" << endl;

    // array<bool, 8> a_ = {0,1,1,1,1,0,0,0};
    // array<bool, 8> b_ = {1,1,1,1,1,0,1,1};

    // auto result_ = operators::ADD(a_, b_, false); 

    // for(auto val : result_.first) {
    //     cout << val;
    // }
    // cout << endl;
    // cout << " -> "
    //  << "C:" << result_.second.C << " "
    //  << "Z:" << result_.second.Z << " "
    //  << "N:" << result_.second.N << " "
    //  << "V:" << result_.second.V << endl;

    // cout << "Result(true)" << endl;
    // cout << "===========" << endl;

    // auto result__1 = operators::ADD(a_, b_, true);
    // for(auto val : result__1.first) {
    //     cout << val;
    // }
    // cout << " -> "
    //  << "C:" << result__1.second.C << " "
    //  << "Z:" << result__1.second.Z << " "
    //  << "N:" << result__1.second.N << " "
    //  << "V:" << result__1.second.V << endl;

    // cout << "Result(true)" << endl;
    // cout << "============" << endl;
    // auto result__2 = operators::SUB(a_, b_, true);
    // for(auto val : result__2.first) {
    //     cout << val;
    // }
    // cout << " -> "
    //  << "C:" << result__2.second.C << " "
    //  << "Z:" << result__2.second.Z << " "
    //  << "N:" << result__2.second.N << " "
    //  << "V:" << result__2.second.V << endl;

    // cout << "Result(false)" << endl;
    // cout << "============" << endl;
    // auto result__3 = operators::SUB(a_, b_, false);
    // for(auto val : result__3.first) {
    //     cout << val;
    // }
    // cout << " -> "
    //  << "C:" << result__3.second.C << " "
    //  << "Z:" << result__3.second.Z << " "
    //  << "N:" << result__3.second.N << " "
    //  << "V:" << result__3.second.V << endl;

    // cout << "Result(true)" << endl;
    // cout << "============" << endl;
    // auto result__4 = operators::INC(a_, true);
    // for(auto val : result__4.first) {
    //     cout << val;
    // }
    // cout << " -> "
    //  << "C:" << result__4.second.C << " "
    //  << "Z:" << result__4.second.Z << " "
    //  << "N:" << result__4.second.N << " "
    //  << "V:" << result__4.second.V << endl;

    // cout << "Result(false)" << endl;
    // cout << "============" << endl;
    // auto result__5 = operators::INC(a_, false);
    // for(auto val : result__5.first) {
    //     cout << val;
    // }
    // cout << " -> "
    //  << "C:" << result__5.second.C << " "
    //  << "Z:" << result__5.second.Z << " "
    //  << "N:" << result__5.second.N << " "
    //  << "V:" << result__5.second.V << endl;
    return 0;
}
