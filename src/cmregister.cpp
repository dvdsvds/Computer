#include "cmregister.hpp"

void PC::setControl(bool ls, bool incs) {
    load = ls;
    inc = incs;
}

void PC::LOAD(const Binary& addr) {
    if(load) mem_address = addr;
}

Binary PC::INC() {
    if(inc) {
        auto [result, flag] = arithmetics::INC(mem_address, false);
        mem_address = result;
    }

    return mem_address;
}

Binary PC::READ() const {
    return mem_address;
}

void PC::CLEAR() {
    mem_address = {};
}

void MAR::setControl(bool ls) {
    load = ls;    
}

void MAR::LOAD(const Binary& addr) {
    if(load) mem_address = addr;
}

Binary MAR::READ() const {
    return mem_address;
}

void MAR::CLEAR() {
    mem_address = {};
}

void MDR::setControl(bool ls, bool ops) {
    load = ls;
    output = ops;
}

void MDR::LOAD(const Binary& value) {
    if(load) data = value;
}

Binary MDR::READ() const {
    return data;
}

void MDR::CLEAR() {
    data = {};
}

void IR::setControl(bool ls, bool ops) {
    load = ls;
    output = ops;
}

void IR::LOAD(const Binary& value) {
    if(load) data = value;
}

Binary IR::READ() const {
    return data;
}

void IR::CLEAR() {
    data = {};
}

