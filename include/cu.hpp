#pragma once
#include "cmregister.hpp"
#include "types.hpp"


namespace cu {
    Binary FETCH(const Binary& mem_addr);

    struct DATAINFO {
        std::array<bool, 4> opcode;
        std::array<bool, 4> operand;
        bool decoded = false;
        bool executing = false;
    };

    DATAINFO DECODE(const Binary& data);
    OResult Execute(const DATAINFO& di, ACC& acc, GR& gr, FR& fr, PC& pc, MAR& mar, MDR& mdr, IR& ir);

}