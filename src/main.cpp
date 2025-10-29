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
        cout << "A   B   F" << endl;
        cout << "---------" << endl;

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
        cout << "---------" << endl;

        for(bool a : inputs) {
            cout << a << "    " << g.second(a)<< endl;
        }
    }

    vector<pair<string, function<pair<bool, bool>(bool, bool)>>> circuits = {
        {"HA", adder::HA}
    };

    for (auto& c : circuits) {
        cout << endl << c.first << " Circuit" << endl;
        cout << "A    B    Sum  Carry" << endl;
        cout << "------------------" << endl;

        for (bool a : inputs) {
            for (bool b : inputs) {
                auto [sum, carry] = c.second(a, b); 
                cout << a << "    " << b << "     "
                    << sum << "     " << carry << endl;
            }
        }
    }

    cout << endl << "Full Adder" << endl;
    cout << "A   B   Cin   Sum   Carry" << endl;
    cout << "-------------------------" << endl;

    for (bool a : inputs) {
        for (bool b : inputs) {
            for (bool cin : inputs) {
                auto result = adder::FA(a, b, cin);
                cout << a << "    " << b << "    " << cin << "      "
                    << result.first << "      " << result.second << endl;
            }
        }
    }
    cout << endl;

    std::array<bool, 8> a = {0,0,0,0,0,0,1,0};
    std::array<bool, 8> b = {0,0,0,0,1,0,0,0};
    auto result = adder::RCA(a, b);

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
    return 0;
}
