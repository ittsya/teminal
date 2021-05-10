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

// MATRIX


template<class TYPE>
class Matrix
{
private:

    Int size_x, size_y;

    TYPE *Matrix_ptr;

public:

    Matrix(Int size_x, Int size_y)
    {
        this->size_x = size_x;
        this->size_y = size_y;

        this->Matrix_ptr = new TYPE[this->size_x * this->size_y];
    }

    ~Matrix()
    {
        delete[] this->Matrix_ptr;
    }

    // Objective value, need to be accurate here
    std::optional<TYPE> operator () (Int x, Int y) const
    {
        auto ret_val = Matrix_ptr[y * this->size_y + x];
        if(std::is_same_v<TYPE, decltype(ret_val)>)
            return ret_val;
        return std::nullopt;
    }

    void insert(TYPE var, Int x, Int y)
    {
        Matrix_ptr[y * this->size_y + x] = var;
    }
};


// TODO implement map w 2 keys

#endif //TERMINAL_DEBUG_HPP
