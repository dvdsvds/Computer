#include "lg.hpp"
#include "dlc.hpp"
#include "op.hpp"
#include <functional>

using namespace std;

int main () {
    std::array<bool, 8> a = {0,0,0,0,1,1,1,1};
std::array<bool, 8> b = {1,1,1,1,0,0,0,0};

    bool is_signed = true;
    auto result = logical::TEST(a, b);
    // for(auto val : result.first) {
    //     cout << val;
    // }
    // cout << endl;
    cout << " -> "
     << "C:" << result.C << " "
     << "Z:" << result.Z << " "
     << "N:" << result.N << " "
     << "V:" << result.V << endl;
    return 0;
}
