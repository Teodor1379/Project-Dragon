#ifndef IDENTIFICATION_NUMBER_COEFFICIENTS_HEADER_INCLUDED
#define IDENTIFICATION_NUMBER_COEFFICIENTS_HEADER_INCLUDED



#include <cstdint>

#include <unordered_map>



class IdentificationNumberCoefficients {
public:
    IdentificationNumberCoefficients();


private:
    std::unordered_map<std::uint16_t, std::uint16_t> pairs;
};



#endif
