#ifndef _IDENTIFICATION_NUMBER_HEADER_INCLUDED_
#define _IDENTIFICATION_NUMBER_HEADER_INCLUDED_



#include <cstdint>


#include <array>
#include <string>
#include <vector>



class IdentificationNumber {
public:
    IdentificationNumber();



public:
    inline bool getGender() const noexcept  { return this->gender; }
    
    inline bool isM()   const noexcept  { return this->gender == false  ;   }
    inline bool isF()   const noexcept  { return this->gender == true   ;   }



public:
    inline std::uint16_t getBirthD  ()  const noexcept  { return this->birthD   ;   }
    inline std::uint16_t getBirthM  ()  const noexcept  { return this->birthM   ;   }
    inline std::uint16_t getBirthY  ()  const noexcept  { return this->birthY   ;   }



public:
    inline std::uint8_t getLocLowerLimit()  const noexcept  { return this->locLowerLimit;   }
    inline std::uint8_t getLocUpperLimit()  const noexcept  { return this->locUpperLimit;   }



private:
    void buildYDigits   ()  ;
    void buildMDigits   ()  ;
    void buildDDigits   ()  ;



private:
    bool gender;



private:
    std::uint16_t birthD;
    std::uint16_t birthM;
    std::uint16_t birthY;



private:
    std::uint8_t locLowerLimit;
    std::uint8_t locUpperLimit;



private:
    std::array<std::uint8_t, 6> prefix;
    std::array<std::uint8_t, 6> suffix;



private:
    std::vector<std::string> options;
};



bool operator==(const IdentificationNumber&, const IdentificationNumber&);
bool operator!=(const IdentificationNumber&, const IdentificationNumber&);



#endif
