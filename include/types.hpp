#pragma once

#include <iostream>
#include <array>

struct Flags {
    bool C; // carry
    bool Z; // zero
    bool N; // nagative
    bool V; // overflow
};

constexpr size_t BIT = 8;
constexpr size_t MSB = 0;
constexpr size_t LSB = BIT - 1;

using Binary = std::array<bool, BIT>;
using ALUResult = std::pair<Binary, Flags>;