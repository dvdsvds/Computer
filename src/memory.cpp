#include "memory.hpp"

namespace memory {
    void setSeg(uint8_t code_size, uint8_t var_count) {
        MEMORYSEGMENT segment;
        MEMORYLAYOUT layout;

        layout.CODE.START = 0;
        layout.CODE.END = code_size - 1;

        layout.DATA.START = layout.CODE.END + 1;
        layout.DATA.END = layout.DATA.START + (var_count - 1);

        layout.HEAP.START = layout.DATA.END + 1;
        
        layout.STACK.START = 255;
        layout.STACK.END = layout.HEAP.START - 1;
    }

    Binary READ(uint8_t addr) {
        return MEMORY[addr];
    }

    void WRITE(uint8_t addr, const Binary& data) {

    }
}