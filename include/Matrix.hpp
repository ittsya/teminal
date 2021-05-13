// stdlib styled header.Why? Because i can.
#pragma once
#ifndef PROJECT_MATRIX_H
#define PROJECT_MATRIX_H

#include<bits/c++config.h>

#include "Concepts.hpp"

typedef unsigned int _M_INT;

template<_Countable_v _TYPE = signed int, _Countable_v _NUM_TYPE = _M_INT> struct matrix
{
    _NUM_TYPE _m_Height, _m_Width, _m_Offset;
    _TYPE *_m_ptr;

    matrix(_NUM_TYPE Width, _NUM_TYPE Height) noexcept
    {
        _m_Width  = Width; _m_Height = Height; _m_Offset = _m_Width;
        _m_ptr = new _TYPE[_m_Width * _m_Height];
    } ~matrix() {delete[] _m_ptr;}

    _GLIBCXX20_CONSTEXPR _TYPE&
    operator () (_NUM_TYPE __n, _NUM_TYPE __m) noexcept
    {return _m_ptr[__m * __n + _m_Offset];}

    void insert(_TYPE f_VAR, _M_INT _P_x, _M_INT _P_y)
    {
        _m_ptr[_P_y * _m_Width + _P_x] = f_VAR;
    }

};

#endif //PROJECT_MATRIX_H
