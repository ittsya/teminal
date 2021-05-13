
#ifndef PROJECT_COUNTER_HPP
#define PROJECT_COUNTER_HPP

#include <type_traits>

#include "Concepts.hpp"

template<_Countable_v _TYPE = signed int> struct Counter
{
private:
    _TYPE _COUNTER, _STARTVALUE;
public:

    inline void set(_TYPE StartValue = _TYPE()) {this->_STARTVALUE = StartValue;}
    
    inline void reset() {this->_STARTVALUE = this->_STARTVALUE;}
    
    inline void start(_TYPE StartNum = _TYPE()) {this->_COUNTER = StartNum; }

    inline void tick(_TYPE how_much = _TYPE() + (_TYPE)1) {this->_COUNTER += how_much;}

    _TYPE GetCount() {return this->_COUNTER;}
};

#endif //PROJECT_COUNTER_HPP
