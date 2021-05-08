#ifndef TERMINAL_DEBUG_HPP
#define TERMINAL_DEBUG_HPP

template<typename contents>
void PrintVec(std::vector<contents> vec)
{
    typedef typename std::vector<contents>::const_iterator vec_t;
    for(vec_t i = vec.begin(); i != vec.end(); i++)
        std::cout << *i << std::endl;
}

#endif //TERMINAL_DEBUG_HPP
