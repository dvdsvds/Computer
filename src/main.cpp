#include "lg.hpp"
#include "dlc.hpp"
#include "op.hpp"
#include <functional>

using namespace std;

int main () {
    std::array<bool, 8> a = {1,0,1,0,0,0,0,0};
    std::array<bool, 8> b = {1,1,1,1,0,0,0,0};

    auto result = shift::SAR(a, 2);
    for(auto val : result.first) {
        cout << val;
    }
    cout << endl;
    cout << "CF " << result.second.C << endl;
    cout << "VF " << result.second.V << endl;
    cout << "NF " << result.second.N << endl;
    cout << "ZF " << result.second.Z << endl;

    return 0;
}
