/*!****************************************************************************************************************************************
* @file     vec2d.cc
*
* @author   Linus Crugnola <linus.crugnola@epfl.ch>     
*
* @version  1.0
*
* @date     28.09.2022
*****************************************************************************************************************************************/

#include "vec2d.h"
#include <iostream>
#include <math.h>

using namespace llib;

template<class T>
vec2d<T>::vec2d(T x, T y) : _x(x), _y(y){}

template<class T>
vec2d<T>::vec2d() {}

template<class T>
vec2d<T> vec2d<T>::operator+(const vec2d<T>& v){
    return vec2d<T>(_x + v._x, _y + v._y);
}

template<class T>
vec2d<T> vec2d<T>::operator-(const vec2d<T>& v){
    return vec2d<T>(_x - v._x, this->_y - v._y);
}

template<class T>
vec2d<T> vec2d<T>::operator=(const vec2d<T>& v){
    return vec2d<T>(v._x, v._y);
}

template<class T>
vec2d<T> vec2d<T>::operator*(const float& n){
    return vec2d<T>(_x * n, _y * n);
}

template<class T>
bool vec2d<T>::operator==(const vec2d<T>& v) const {
    return (_x == v._x) and (_y == v._y);
}

template<class T>
bool vec2d<T>::operator!=(const vec2d<T>& v) const {
    return (_x != v._x) or (_y != v._y);
}

template<class T>
float vec2d<T>::scalProd(const vec2d<T>& v1, const vec2d<T>& v2){
    return v1._x * v2._x + v1._y * v2._y;
}

template <class T>
float vec2d<T>::abs(const vec2d<T>& v) const {
    return sqrt(v._x * v._x + v._y * v._y);
}

template<class T>
vec2d<T> vec2d<T>::setLen(const float& length){
    return vec2d<T>(2,2);
}

template<class T>
vec2d<T> vec2d<T>::setAng(const float& length){
    return vec2d<T>(3,3);
}

template <class T>
void vec2d<T>::rotate(const float& angle){
    this->_x = 3;
    this->_y = 3;
}

void llib::printTest(){ std::cout << "test" << std::endl; }

namespace llib{
    template class vec2d<int>;
}