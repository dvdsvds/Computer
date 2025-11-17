#pragma once
#include "register.hpp"
#include "op.hpp"

class PC {
    private:
        Binary mem_address = {};
        int count = 1;
        bool load = false;
        bool inc = false;
    public:
        void LOAD(const Binary& addr);
        Binary INC();
        Binary READ() const;
        void CLEAR();
        void setControl(bool ls, bool incs);
};

class MAR {
    private:
        Binary mem_address = {};
        bool load = false;
    public:
        void LOAD(const Binary& addr);
        Binary READ() const;
        void CLEAR();
        void setControl(bool ls);
};
   
class MDR {
    private:
        Binary data = {};
        bool load = false;
        bool output = false;
    public:
        void LOAD(const Binary& value);
        Binary READ() const;
        void CLEAR();
        void setControl(bool ls, bool ops);
};

class IR {
    private:
        Binary data = {};
        bool load = false;
        bool output = false;
    public:
        void LOAD(const Binary& value);
        Binary READ() const;
        void CLEAR();
        void setControl(bool ls, bool ops);
};

class SP {
    private:
        uint8_t top = 255;
    public:
        void inc();
        void dec();
        uint8_t read() const; 
};