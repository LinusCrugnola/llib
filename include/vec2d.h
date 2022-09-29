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

        vec2d(T x, T y);
        vec2d();
        ~vec2d(){};

        // disable the copy constructor
        //vec2d(const vec2d&) = delete;

        vec2d<T> operator+(const vec2d<T>& v);
        vec2d<T> operator-(const vec2d<T>& v);
        vec2d<T> operator=(const vec2d<T>& v);
        vec2d<T> operator*(const float& n);
        bool operator==(const vec2d<T>& v) const;
        bool operator!=(const vec2d<T>& v) const;
        float scalProd(const vec2d<T>& v1, const vec2d<T>& v2);
        float abs(const vec2d<T>& v) const;
        vec2d<T> setLen(const float& length);
        vec2d<T> setAng(const float& angle);

        void rotate(const float& angle);

        //pol2d to_polar(const vec2d& v) const;

    };

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

    void printTest();
}