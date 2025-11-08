#pragma once

#include <iostream>
#include <array>
#include "types.hpp"

namespace adders {
    std::pair<bool, bool> HA(bool a, bool b);
    std::pair<bool, bool> FA(bool a, bool b, bool Cin);
    std::pair<Binary, bool> RCA(const Binary& a, const Binary& b);
}

namespace subtractors {
    std::pair<bool, bool> HS(bool a, bool b);
    std::pair<bool, bool> FS(bool a, bool b, bool Bin);
    std::pair<Binary, bool> RBS(const Binary& a, const Binary& b);
}