#include "register.hpp"

void ACC::setControl(bool ls, bool ops) {
    load = ls;
    output = ops;
}

void ACC::LOAD(const Binary& data) {
    if(load) value = data;
}

Binary ACC::READ() const {
    if(output) {
        return value;
    }

    return {};
}

void ACC::CLEAR() {
    value = {};
}

void GR::setControl(bool ls, bool ops) {
    load = ls;
    output = ops;
}

void GR::LOAD(const Binary& data) {
    if(load) value = data;
}

Binary GR::READ() const {
    if(output) {
        return value;
    }

    return {};
}

void GR::CLEAR() {
    value = {};
}

void FR::setControl(bool ls) {
    load = ls;
}

void FR::LOAD(const Flags& f) {
    if(load) flag = f;
}

Flags FR::READ() const {
    return flag;
}

void FR::CLEAR() {
    flag = {};
}