/*!****************************************************************************************************************************************
* @file     vec2d_test.cc
*
* @author   Linus Crugnola <linus.crugnola@epfl.ch>     
*
* @version  1.0
*
* @date     28.09.2022
*****************************************************************************************************************************************/
 
#include <gtest/gtest.h>
#include "vec3d.h"
#include "vec2d.h"

TEST(Vec2dTest, BasicAssertions) {

    llib::vec2d<int> v;
    llib::vec2d<int> u;
    llib::vec2d<int> w(1,1);

    std::cout << u << std::endl;
}