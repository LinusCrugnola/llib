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
#include "llibStddef.h"

#include <iostream>
#include <math.h>

namespace llib {

    /**
     * @brief General type: two dimension vector
     * 
     * @param _x change of x direction
     * @param _y change of y direciton
     */
    template<class T>
    struct vec2d final {
        T _x;
        T _y;

        vec2d(T x, T y) : _x(x), _y(y) {}
        vec2d(T x) : _x(x), _y(x) {}
        vec2d() : _x(), _y() {}
        ~vec2d() {}

        // disable the copy constructor
        vec2d(const vec2d&) = delete;

        /**
         * @brief overload operators for vec2d
         */
        _NODISC vec2d<T> operator+(const vec2d<T>& v);
        _NODISC vec2d<T> operator-(const vec2d<T>& v);
        _NODISC bool operator==(const vec2d<T>& v) const;
        _NODISC bool operator!=(const vec2d<T>& v) const;
        /**
         * @brief get the length of the vector
         * 
         * @return float length
         */
        _NODISC float len() const;

        /**
         * @brief get the angle of the vector
         * 
         * @return float angle
         */
        _NODISC float ang() const;

        void setLen(const float& length);

        void setAng(const float& angle);

        void rotate(const float& angle);

        void preciseE8();

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

    template<class T>
    std::ostream& operator<<(std::ostream& os, const vec2d<T>& v){
        os << "( " << v._x << ", " << v._y << " )";
        return os;
    }
}