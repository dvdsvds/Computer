#pragma once

#include <iostream>
#include <array>

#define BIT 8
namespace adders {
    std::pair<bool, bool> HA(const bool& a, const bool& b);
    std::pair<bool, bool> FA(const bool& a, const bool& b, const bool& Cin);
    std::pair<std::array<bool, BIT>, bool> RCA(const std::array<bool, BIT>& a, const std::array<bool, BIT>& b);
}

namespace subtractors {
    std::pair<bool, bool> HS(const bool& a, const bool& b);
    std::pair<bool, bool> FS(const bool& a, const bool& b, const bool& Bin);
    std::pair<std::array<bool, BIT>, bool> RBS(const std::array<bool, BIT>& a, const std::array<bool, BIT>& b);
}