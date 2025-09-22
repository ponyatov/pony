#include "cli.hpp"

std::map<std::string, addr> label;

addr compile(byte b) {
    assert(Cp + sizeof(byte) < Msz);
    M[Cp] = b;
    Cp += sizeof(byte);
    return Cp;
}

addr compile(Op op) { return compile((byte)op); }

addr compile(addr a) {
    assert(Cp + sizeof(addr) < Msz);
    *(addr *)&M[Cp] = a;
    Cp += sizeof(addr);
    return Cp;
}

addr compile(cell n) {
    assert(Cp + sizeof(cell) < Msz);
    *(cell *)&M[Cp] = n;
    Cp += sizeof(cell);
    return Cp;
}

addr compile(fcell f) {
    assert(Cp + sizeof(fcell) < Msz);
    *(fcell *)&M[Cp] = f;
    Cp += sizeof(fcell);
    return Cp;
}
