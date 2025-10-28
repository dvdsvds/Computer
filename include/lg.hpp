#pragma once

#include <iostream>

namespace gate {
    bool AND(const bool& a, const bool& b);
    bool OR(const bool& a, const bool& b);
    bool NOT(const bool& a);
    bool NAND(const bool& a, const bool& b);
    bool NOR(const bool& a, const bool& b);
    bool XOR(const bool& a, const bool& b);
    bool XNOR(const bool& a, const bool& b);
    bool BUFFER(const bool& a);
}