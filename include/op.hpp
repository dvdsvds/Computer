#pragma once
#include <array>

#define BIT 8

namespace operators {

    constexpr size_t MSB = 0;
    constexpr size_t LSB = BIT - 1;
    constexpr std::array<bool, BIT> one = {0,0,0,0,0,0,0,1};

    struct Flags {
        bool C; // carry
        bool Z; // zero
        bool N; // nagative
        bool V; // overflow
    };

    std::pair<std::array<bool, BIT>, Flags> ADD(const std::array<bool, BIT>& a, const std::array<bool, BIT>& b, const bool& is_signed);
    std::pair<std::array<bool, BIT>, Flags> SUB(const std::array<bool, BIT>& a, const std::array<bool, BIT>& b, const bool& is_signed);
    std::pair<std::array<bool, BIT>, Flags> INC(const std::array<bool, BIT>& a, const bool& is_signed);
    std::pair<std::array<bool, BIT>, Flags> DEC(const std::array<bool, BIT>& a, const bool& is_signed);
    std::pair<std::array<bool, BIT>, Flags> NEG(const std::array<bool, BIT>& a, const bool& is_signed);
    std::pair<std::array<bool, BIT>, Flags> CMP(const std::array<bool, BIT>& a, const std::array<bool, BIT>& b, const bool& is_signed);
    
};
