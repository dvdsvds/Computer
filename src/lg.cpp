#include "lg.hpp"

namespace gate {
    bool AND(const bool& a, const bool& b) {
        if(a) return b; 
        else return false;
    }

    bool OR(const bool& a, const bool& b) {
        if(a) return true; 
        else return b;
    }

    bool NOT(const bool& a) {
        if(a) return false; 
        else return true;
    }

    bool NAND(const bool& a, const bool& b) {
        if(a) 
            if(b) return false; 
            else return true;
        else return true;
    }

    bool NOR(const bool& a, const bool& b) {
        if(a) return false;
        else if(b) return false;
        else return true;
    }

    bool XOR(const bool& a, const bool& b) {
        if(a) 
            if(b) return false;
            else return true;
        else 
            if(b) return true;
            else return false;
    }

    bool XNOR(const bool& a, const bool& b) {
        if(a) 
            if(b) return true;
            else return false;
        else 
            if(b) return false;
            else return true;
    }

    bool BUFFER(const bool& a) {
        return a;
    }
}
