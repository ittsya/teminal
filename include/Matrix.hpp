// stdlib styled header.Why? Because i can.
#pragma once
#ifndef PROJECT_MATRIX_H
#define PROJECT_MATRIX_H

#include<bits/c++config.h>

#include "Concepts.hpp"
#include <stdio.h>
typedef unsigned int _M_INT;

template<_Countable_v _TYPE = signed int, _Countable_v _NUM_TYPE = _M_INT> struct matrix
{
    _NUM_TYPE _m_Height, _m_Width;
    _TYPE *_m_ptr = nullptr;

    matrix(_NUM_TYPE Width, _NUM_TYPE Height) noexcept
    {
        _NUM_TYPE _size = Width * Height;
        _m_Width  = Width; _m_Height = Height;
        _m_ptr = new _TYPE[_size];
        std::fill_n(_m_ptr, _size, 0x00);

    } ~matrix() {(_m_ptr == nullptr) ? (void)0 : delete[] _m_ptr;}

    _GLIBCXX20_CONSTEXPR _TYPE&
    get (_NUM_TYPE __n, _NUM_TYPE __m) noexcept
    {return _m_ptr[__m * _m_Width + __n];}

    void
    insert(_TYPE f_VAR, _M_INT _P_x, _M_INT _P_y)
    {_m_ptr[_P_y * _m_Width + _P_x] = f_VAR;}

};

#endif //PROJECT_MATRIX_H
