
#ifndef PROJECT_COUNTER_HPP
#define PROJECT_COUNTER_HPP

#include <type_traits>

#define ZERO (_TYPE)0
#define ZERO_f(x) (_TYPE)x

template<typename T>
concept Countable =
    !std::is_same<T, unsigned char>::value &&
    !std::is_same<T, char>::value &&
    std::is_arithmetic<T>::value;

template<Countable _TYPE = signed int>
struct Counter {
private:
    _TYPE _COUNTER, _STARTVALUE;
public:

    inline void set(_TYPE StartValue = ZERO) {this->_STARTVALUE = StartValue;}
    
    inline void reset() {this->_STARTVALUE = this->_STARTVALUE;}
    
    inline void start(_TYPE StartNum = ZERO) {this->_COUNTER = StartNum; }

    inline void tick(_TYPE how_much = ZERO + ZERO_f(1)) {this->_COUNTER += how_much;}

    _TYPE GetCount() {return this->_COUNTER;}

};

#undef ZERO
#undef ZERO_f
#endif //PROJECT_COUNTER_HPP
