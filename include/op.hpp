#pragma once
#include <array>

#define BIT 8

namespace operators {
    struct Flags {
        bool C;
        bool Z;
        bool N;
        bool V;
    };

    std::pair<std::array<bool, BIT>, Flags> ADD(const std::array<bool, BIT>& a, const std::array<bool, BIT>& b);
    std::pair<std::array<bool, BIT>, Flags> SUB(const std::array<bool, BIT>& a, const std::array<bool, BIT>& b);
    std::pair<std::array<bool, BIT>, Flags> INC(const std::array<bool, BIT>& a);
    std::pair<std::array<bool, BIT>, Flags> DEC(const std::array<bool, BIT>& a);
    std::pair<std::array<bool, BIT>, Flags> NEG(const std::array<bool, BIT>& a);
    std::pair<std::array<bool, BIT>, Flags> CMP(const std::array<bool, BIT>& a, const std::array<bool, BIT>& b);
    
};