// Only for debbuging.
namespace debug
{
    template<typename contents>
    void PrintVec(std::vector<contents> vec)
    {
        typedef typename std::vector<contents>::const_iterator vec_t;
        for(vec_t i = vec.begin(); i != vec.end(); i++)
            std::cout << *i << std::endl;
    }
}
