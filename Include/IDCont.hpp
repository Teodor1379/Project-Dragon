#ifndef _ID_CONTAINER_HEADER_INCLUDED_
#define _ID_CONTAINER_HEADER_INCLUDED_



#include <cstddef>
#include <cstdint>
#include <cstdlib>


#include <array>

#include <string>

#include <unordered_map>



class IDContainer {
public:
    IDContainer();



public:
    inline std::uint16_t getLowerLimit(const std::string& place)    const noexcept  { return this->table.at(place)[0]; }
    inline std::uint16_t getUpperLimit(const std::string& place)    const noexcept  { return this->table.at(place)[1]; }



private:
    std::unordered_map<std::string, std::array<std::uint16_t, 2>> table;
};



#endif
