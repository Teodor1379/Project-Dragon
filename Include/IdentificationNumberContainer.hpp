#ifndef _IDENTIFICATION_NUMBER_CONTAINER_HPP_INCLUDED_
#define _IDENTIFICATION_NUMBER_CONTAINER_HPP_INCLUDED_



#include <cstddef>
#include <cstdint>
#include <cstdlib>


#include <array>

#include <string>

#include <unordered_map>



typedef std::array<std::uint16_t, 2> Pair;



class IdentificationNumberContainer {
public:
    IdentificationNumberContainer();



public:
    static inline std::uint16_t getLowerLimit(const std::string& place) noexcept  { return IdentificationNumberContainer::table.at(place)[0]; }
    static inline std::uint16_t getUpperLimit(const std::string& place) noexcept  { return IdentificationNumberContainer::table.at(place)[1]; }



private:
    static std::unordered_map<std::string, Pair> table;
};



#endif
