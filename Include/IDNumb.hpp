#ifndef _ID_NUMBER_HEADER_INCLUDED_
#define _ID_NUMBER_HEADER_INCLUDED_



#include <cstddef>
#include <cstdint>
#include <cstdlib>


#include <array>

#include <string>
#include <vector>



#include "IDCoef.hpp"
#include "IDCont.hpp"



class IDNumber {
public:
    IDNumber(const std::string&, const std::string&, const std::string& );



public:
    inline bool getGender() const noexcept  { return this->gender; }



public:
    inline bool isM()   const noexcept  { return this->gender == 0  ;   }
    inline bool isF()   const noexcept  { return this->gender == 1  ;   }



public:
    inline std::uint16_t getBirthD  ()  const noexcept  { return this->birthD   ;   }
    inline std::uint16_t getBirthM  ()  const noexcept  { return this->birthM   ;   }
    inline std::uint16_t getBirthY  ()  const noexcept  { return this->birthY   ;   }



public:
    inline std::uint16_t getLocLowerLimit()  const noexcept  { return this->locLowerLimit;   }
    inline std::uint16_t getLocUpperLimit()  const noexcept  { return this->locUpperLimit;   }



public:
    std::vector<std::array<std::uint16_t, 10>> getIDs() const;



private:
    void buildYDigits();
    void buildMDigits();
    void buildDDigits();



private:
    bool gender;



private:
    std::uint16_t birthD;
    std::uint16_t birthM;
    std::uint16_t birthY;



private:
    std::uint16_t locLowerLimit;
    std::uint16_t locUpperLimit;



private:
    std::array<std::uint16_t, 6> prefix;
    std::array<std::uint16_t, 3> suffix;



private:
    std::vector<std::string> options;
};



bool operator==(const IDNumber&, const IDNumber&);
bool operator!=(const IDNumber&, const IDNumber&);



#endif
