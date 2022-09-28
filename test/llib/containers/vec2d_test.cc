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
#include "vec2d.h"
#include "vec3d.h"

TEST(Vec2dTest, BasicAssertions) {
    // Expect equalitys.
    EXPECT_EQ(1, 1);
    EXPECT_EQ(0, 1);

    llib::printTest();

    //llib::vec2d<int>();

    // test testobj;
    // testobj.printText();

    lol();
}