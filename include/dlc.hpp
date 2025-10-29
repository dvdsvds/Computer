#pragma once

#include <iostream>
#include <array>

namespace adder {
    std::pair<bool, bool> HA(const bool& a, const bool& b);
    std::pair<bool, bool> FA(const bool& a, const bool& b, const bool& Cin);
    std::pair<std::array<bool, 8>, bool> RCA(const std::array<bool, 8>& a, const std::array<bool, 8>& b);
    
}