#include "IDCoef.hpp"



IDCoefficients::IDCoefficients() {
    this->buildPairs1();
    this->buildPairs2();
}



void IDCoefficients::buildPairs1() {
    this->pairs1[0] = 00;
    this->pairs1[1] = 00;
    this->pairs1[2] = 00;
    this->pairs1[3] = 01;
    this->pairs1[4] = 02;
    this->pairs1[5] = 05;
    this->pairs1[6] = 11;
    this->pairs1[7] = 23;
    this->pairs1[8] = 46;
}

void IDCoefficients::buildPairs2() {
    for (unsigned int i = 0; i < 9; ++i) {
        std::uint16_t p = static_cast<std::uint16_t>(2 << (i + 1));

        this->pairs2[i] = p - this->pairs1[i] * 11;
    }
}
