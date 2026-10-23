#ifndef _ID_COEFFICIENTS_HEADER_INCLUDED_
#define _ID_COEFFICIENTS_HEADER_INCLUDED_



#include <cstddef>
#include <cstdint>
#include <cstdlib>


#include <array>



class IDCoefficients {
public:
    IDCoefficients();



public:
    inline std::uint16_t getNumb(std::uint16_t index)   const noexcept  { return this->pairs1[index];   } 
    inline std::uint16_t getCoef(std::uint16_t index)   const noexcept  { return this->pairs2[index];   }




private:
    void buildPairs1();
    void buildPairs2();



private:
    std::array<std::uint16_t, 9> pairs1;
    std::array<std::uint16_t, 9> pairs2;
};



#endif
