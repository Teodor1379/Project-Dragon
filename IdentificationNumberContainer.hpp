#ifndef IDENTIFICATION_NUMBER_CONTAINER_HPP_INCLUDED
#define IDENTIFICATION_NUMBER_CONTAINER_HPP_INCLUDED



#include <cstdint>

#include <string>

#include <unordered_map>



typedef std::pair<std::uint8_t, std::uint8_t> Pair;



class IdentificationNumberContainer {
public:
    IdentificationNumberContainer();


private:
    std::unordered_map<std::string, Pair> table;
};



#endif
