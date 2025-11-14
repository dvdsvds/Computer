#pragma once

#include "alu.hpp"
#include "types.hpp"

class ACC {
    private:
        Binary value;
        bool load = false;
        bool output = false;
    public:
        void LOAD(const Binary& data);
        void CLEAR();
        Binary READ() const;
        void setControl(bool ls, bool ops);
};

class GR {
    private:
        Binary value;
        bool load = false;
        bool output = false;
    public:
        void LOAD(const Binary& data);
        void CLEAR();
        Binary READ() const;
        void setControl(bool ls, bool ops);
};

class FR {
    private:
        Flags flag;
        bool load = false;
    public:
        void LOAD(const Flags& flag);
        void CLEAR();
        Flags READ() const;
        void setControl(bool ls);
};