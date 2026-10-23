#include "IDNumb.hpp"



#include <vector>



IDNumber::IDNumber(
    const std::string& gndr,
    const std::string& date,
    const std::string& plcs
) {
    IDContainer container;
    
    if (gndr[0] == 'M') { this->gender = 0; }
    if (gndr[0] == 'F') { this->gender = 1; }

    this->birthD    =   static_cast<std::uint16_t>(std::stoi(date.substr(0, 2)));
    this->birthM    =   static_cast<std::uint16_t>(std::stoi(date.substr(3, 2)));
    this->birthY    =   static_cast<std::uint16_t>(std::stoi(date.substr(6, 4)));

    this->locLowerLimit =   container.getLowerLimit(plcs);
    this->locUpperLimit =   container.getUpperLimit(plcs);

    this->buildYDigits();
    this->buildMDigits();
    this->buildDDigits();

    this->suffix = { 0, 0, 0, };
}



std::vector<std::array<std::uint16_t, 10>> IDNumber::getIDs() const {
    IDCoefficients coefficients;

    std::vector<std::array<std::uint16_t, 10>> result;

    for (std::uint16_t i = this->locLowerLimit; i <= this->locUpperLimit; ++i) {
        std::array<std::uint16_t, 10> ID;

        for (unsigned int j = 0; j < this->prefix.size(); ++j) {
            ID[j] = this->prefix[j];
        }

        std::uint16_t digit1 = (i / 100) % 10;
        std::uint16_t digit2 = (i / 10 ) / 10;
        std::uint16_t digit3 = (i / 1  ) % 10;

        ID[6] = digit1;
        ID[7] = digit2;
        ID[8] = digit3;

        std::uint16_t sum = 0;

        for (unsigned int j = 0; j < 9; ++j) {
            sum = sum + ID[j] * coefficients.getCoef(static_cast<std::uint16_t>(j));
        }

        ID[9] = (sum % 11) % 10;

        result.push_back(ID);
    }
    
    return result;
}



void IDNumber::buildYDigits() {
    this->prefix[0] = this->birthY / 10;
    this->prefix[1] = this->birthY % 10;  
}

void IDNumber::buildMDigits() {
    if (this->birthY < 2000) {
        this->prefix[2] = this->birthM / 10;
        this->prefix[3] = this->birthM % 10;
    } else {
        this->prefix[2] = this->birthM / 10 + 4;
        this->prefix[3] = this->birthM % 10 + 0;
    }
}

void IDNumber::buildDDigits() {
    this->prefix[4] = this->birthD / 10;
    this->prefix[5] = this->birthD % 10;
}
