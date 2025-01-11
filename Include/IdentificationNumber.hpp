#ifndef IDENTIFICATION_NUMBER_HPP_INCLUDED
#define IDENTIFICATION_NUMBER_HPP_INCLUDED



#include <cstdint>

#include <vector>



class IdentificationNumber {
public:
    IdentificationNumber();

    inline bool getGender() const noexcept  { return this->gender; }

    inline std::uint16_t getBirthDay()      const noexcept  { return this->birthDay;    }
    inline std::uint16_t getBirthMonth()    const noexcept  { return this->birthMonth;  }
    inline std::uint16_t getBirthYear()     const noexcept  { return this->birthYear;   }

    inline std::uint8_t getBirthLocationLowerBorder()   const noexcept  { return this->birthLocationLowerBorder; }
    inline std::uint8_t getBirthLocationUpperBorder()   const noexcept  { return this->birthLocationUpperBorder; }

    void buildYearDigits()  ;
    void buildMonthDigits() ;
    void buildDayDigits()   ;


private:
    bool gender;

    std::uint16_t birthDay;
    std::uint16_t birthMonth;
    std::uint16_t birthYear;

    std::uint8_t birthLocationLowerBorder;
    std::uint8_t birthLocationUpperBorder;
};



#endif
