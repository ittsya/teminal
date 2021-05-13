#ifndef TERMINAL_DEBUG_HPP
#define TERMINAL_DEBUG_HPP

#define TYPE_INT 0
#define TYPE_FLOAT 0.0f

#include <optional>

typedef unsigned int Int;

template<typename contents>
void PrintVec(std::vector<contents> vec)
{
    typedef typename std::vector<contents>::const_iterator vec_t;
    for(vec_t i = vec.begin(); i != vec.end(); i++)
        std::cout << *i << std::endl;
}


// From boost
template<typename T1, typename T2>
T1 lexical_cast(T2 &t1)
{
    T1 output;
    std::stringstream stream;
    stream << t1;
    stream >> output;
    return output;
}

#endif //TERMINAL_DEBUG_HPP
