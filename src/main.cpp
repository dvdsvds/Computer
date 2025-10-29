#include "lg.hpp"
#include "dlc.hpp"
#include <functional>

using namespace std;

int main () {
    vector<pair<string, function<bool(const bool&, const bool&)>>> gates = {
        {"AND", gate::AND},
        {"OR", gate::OR},
        {"NAND", gate::NAND},
        {"NOR", gate::NOR},
        {"XOR", gate::XOR},
        {"XNOR", gate::XNOR},
    };

    bool inputs[2] = {false, true};

    for(auto& g : gates) {
        cout << endl << g.first << " Gate" << endl;
        cout << "A    B    F" << endl;
        cout << "-----------" << endl;

        for(bool a : inputs) {
            for(bool b : inputs) {
                cout << a << "    " << b << "    " << g.second(a, b) << endl;
            }
        }
    }

    vector<pair<string, function<bool(bool)>>> gates_1 = {
        {"NOT", gate::NOT},
        {"BUFFER", gate::BUFFER},
    };

    for(auto& g : gates_1) {
        cout << endl << g.first << " Gate" << endl;
        cout << "A    F" << endl;
        cout << "------" << endl;

        for(bool a : inputs) {
            cout << a << "    " << g.second(a)<< endl;
        }
    }

    vector<pair<string, function<pair<bool, bool>(bool, bool)>>> circuits = {
        {"HA", adders::HA}
    };

    for (auto& c : circuits) {
        cout << endl << c.first << " Circuit" << endl;
        cout << "A    B    Sum  Carry" << endl;
        cout << "--------------------" << endl;

        for (bool a : inputs) {
            for (bool b : inputs) {
                auto [sum, carry] = c.second(a, b); 
                cout << a << "    " << b << "     "
                    << sum << "     " << carry << endl;
            }
        }
    }

    cout << endl << "Full adders" << endl;
    cout << "A   B   Cin   Sum   Carry" << endl;
    cout << "-------------------------" << endl;

    for (bool a : inputs) {
        for (bool b : inputs) {
            for (bool cin : inputs) {
                auto result = adders::FA(a, b, cin);
                cout << a << "    " << b << "    " << cin << "      "
                    << result.first << "      " << result.second << endl;
            }
        }
    }
    cout << endl;

    std::array<bool, 8> a = {1,1,1,1,1,0,1,1};
    std::array<bool, 8> b = {1,1,1,1,1,1,0,1};
    auto result = adders::RCA(a, b);

    for(auto a1 : a) {
        cout << a1;
    }
    cout << endl;

    for(auto b1 : b) {
        cout << b1;
    }
    cout << endl;
    cout << "========" << endl;
    for(auto v : result.first) {
        cout << v;
    }
    cout << endl;

    cout << "Carry : ";
    cout << result.second << endl;


    cout << endl << "Full Subtrator" << endl;
    cout << "A    B   B_in   D   B_out" << endl;
    cout << "-------------------------" << endl;

    for (bool a : inputs) {
        for (bool b : inputs) {
            for (bool B_in : inputs) {
                auto result = subtractors::FS(a, b, B_in);
                cout << a << "    " << b << "    " << B_in << "     "
                    << result.first << "     " << result.second << endl;
            }
        }
    }
    cout << endl;
    auto result1 = subtractors::RBS(a, b);

    for(auto a1 : a) {
        cout << a1;
    }
    cout << endl;

    for(auto b1 : b) {
        cout << b1;
    }
    cout << endl;
    cout << "========" << endl;
    for(auto v : result1.first) {
        cout << v;
    }
    cout << endl;

    cout << "Borrow  : ";
    cout << result1.second << endl;
    return 0;
}
