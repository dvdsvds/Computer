#pragma once

#include <iostream>
#include <vector>

namespace adder {
    std::pair<bool, bool> HA(const bool& a, const bool& b);
    std::pair<bool, bool> FA(const bool& a, const bool& b, const bool& Cin);
    std::pair<std::vector<bool>, bool> RCA(const std::vector<bool>& a, const std::vector<bool>& b);
}