/*!****************************************************************************************************************************************
* @file     vec2d.h
*
* @author   Linus Crugnola <linus.crugnola@epfl.ch>     
*
* @version  1.0
*
* @date     28.09.2022
*****************************************************************************************************************************************/
 
#pragma once

#include <iostream>
#include <math.h>

namespace llib {

    /**
     * @brief General type: two dimension vector
     * 
     * @param dx change of x direction
     * @param dy change of y direciton
     */
    template<class T>
    class vec2d final {
    public:
        T _x;
        T _y;

        vec2d(T x, T y) : _x(x), _y(y) {}
        vec2d(T x) : _x(x), _y(x) {}
        vec2d() : _x(), _y() {}
        ~vec2d(){};

        // disable the copy constructor
        //vec2d(const vec2d&) = delete;

        vec2d<T> operator+(const vec2d<T>& v) {
            return vec2d<T>(_x + v._x, _y + v._y);
        }
        vec2d<T> operator-(const vec2d<T>& v){
            return vec2d<T>(_x - v._x, _y - v._y);
        }
        bool operator==(const vec2d<T>& v) const {
            return (_x == v._x) and (_y == v._y);
        }
        bool operator!=(const vec2d<T>& v) const{
            return (_x != v._x) or (_y != v._y);
        }
        float len() const {
            return sqrt(_x * _x + _y * _y);
        }
        float ang() const {
            return atanf(_y / _x);
        }
        //TODO:
        vec2d<T> setLen(const float& length){
            return vec2d<T>(2,2);
        }
        //TODO:
        vec2d<T> setAng(const float& angle){
            return vec2d<T>(3,3);
        }
        //TODO:
        void rotate(const float& angle){
            _x = 3;
            _y = 3;
        }

        //pol2d to_polar(const vec2d& v) const;

    };

    template<class T>
    vec2d<T> operator*(const float& n, const vec2d<T>& vr){
        return vec2d<T>(vr._x * n, vr._y * n);
    }

    template<class T>
    vec2d<T> operator*(const vec2d<T>& vl, const float& n){
        return vec2d<T>(vl._x * n, vl._y * n);
    }

    template<class T>
    float scalProd(const vec2d<T>& v1, const vec2d<T>& v2){
        return v1._x * v2._x + v1._y * v2._y;
    }

    /**
     * @brief Pretty-print vector to the console
     * 
     * @tparam T 
     * @param os 
     * @param v 
     * @return std::ostream& 
     */
    template<class T>
    std::ostream& operator<<(std::ostream& os, const vec2d<T>& v){
        os << "( " << v._x << ", " << v._y << " )";
        return os;
    }
}