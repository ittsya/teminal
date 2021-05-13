
#ifndef PROJECT_COUNTER_HPP
#define PROJECT_COUNTER_HPP

#include <type_traits>

#include "Concepts.hpp"

template<_Countable_v _TYPE = signed int> struct Counter
{
    _TYPE _COUNTER, _STARTVALUE;

    inline void set(_TYPE StartValue) {_STARTVALUE = StartValue;}
    
    inline void reset(_TYPE x) {_COUNTER = x;}
    
    inline void start(_TYPE StartNum) {_COUNTER = StartNum; }

    inline void tick(_TYPE how_much) {_COUNTER += how_much;}

    _TYPE GetCount() {return _COUNTER;}
};

#endif //PROJECT_COUNTER_HPP
