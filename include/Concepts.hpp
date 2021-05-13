#ifndef PROJECT_CONCEPTS_HPP
#define PROJECT_CONCEPTS_HPP

template<typename _Type>
concept _Countable_v =
!std::is_same<_Type, unsigned char>::value &&
!std::is_same<_Type, char>::value &&
std::is_arithmetic<_Type>::value;


#endif //PROJECT_CONCEPTS_HPP
