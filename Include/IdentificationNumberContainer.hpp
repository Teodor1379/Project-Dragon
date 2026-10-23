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
    inline std::uint16_t getLowerLimit(const std::string& place)    const noexcept  { return this->table.at(place)[0]; }
    inline std::uint16_t getUpperLimit(const std::string& place)    const noexcept  { return this->table.at(place)[1]; }



private:
    std::unordered_map<std::string, Pair> table;
};



#endif
