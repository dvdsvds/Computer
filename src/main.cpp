#include "lg.hpp"
#include "circuit.hpp"
#include <iostream>
#include <vector>
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
        {"HA", circuit::HA}
    };

    for (auto& c : circuits) {
    cout << endl << c.first << " Circuit" << endl;
    cout << "A   B   Sum  Carry" << endl;
    cout << "------------------" << endl;

    for (bool a : inputs) {
        for (bool b : inputs) {
            auto [sum, carry] = c.second(a, b); // pair 분해 구조
            cout << a << "    " << b << "     "
                 << sum << "     " << carry << endl;
        }
    }
}

    return 0;
}
