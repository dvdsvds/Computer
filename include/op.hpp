#pragma once
#include <array>

#define BIT 8

struct Flags {
    bool C; // carry
    bool Z; // zero
    bool N; // nagative
    bool V; // overflow
};

constexpr size_t MSB = 0;
constexpr size_t LSB = BIT - 1;

namespace arithmetics {
    constexpr std::array<bool, BIT> one = {0,0,0,0,0,0,0,1};

    std::pair<std::array<bool, BIT>, Flags> ADD(const std::array<bool, BIT>& a, const std::array<bool, BIT>& b, const bool& is_signed);
    std::pair<std::array<bool, BIT>, Flags> SUB(const std::array<bool, BIT>& a, const std::array<bool, BIT>& b, const bool& is_signed);
    std::pair<std::array<bool, BIT>, Flags> INC(const std::array<bool, BIT>& a, const bool& is_signed);
    std::pair<std::array<bool, BIT>, Flags> DEC(const std::array<bool, BIT>& a, const bool& is_signed);
    std::pair<std::array<bool, BIT>, Flags> NEG(const std::array<bool, BIT>& a, const bool& is_signed);
    Flags CMP(const std::array<bool, BIT>& a, const std::array<bool, BIT>& b, const bool& is_signed);
};

namespace logical {
    std::pair<std::array<bool, BIT>, Flags> AND(const std::array<bool, BIT>& a, const std::array<bool, BIT>& b);
    std::pair<std::array<bool, BIT>, Flags> OR(const std::array<bool, BIT>& a, const std::array<bool, BIT>& b);
    std::pair<std::array<bool, BIT>, Flags> XOR(const std::array<bool, BIT>& a, const std::array<bool, BIT>& b);
    std::pair<std::array<bool, BIT>, Flags> NOT(const std::array<bool, BIT>& a);
    Flags TEST(const std::array<bool, BIT>& a, const std::array<bool, BIT>& b);
}
