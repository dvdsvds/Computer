#pragma once
#include "types.hpp"
#include "cmregister.hpp"
#include <vector>

namespace memory {
    struct MEMORYSEGMENT {
        uint8_t START;
        uint8_t END;
    };

    struct MEMORYLAYOUT {
        MEMORYSEGMENT CODE;
        MEMORYSEGMENT DATA;
        MEMORYSEGMENT HEAP;
        MEMORYSEGMENT STACK;
    };

    std::vector<Binary> MEMORY(1 << BIT);

    void setSeg(uint8_t code_size, uint8_t var_count);
    Binary READ(uint8_t addr);
    void WRITE(uint8_t addr, const Binary& data);
};
