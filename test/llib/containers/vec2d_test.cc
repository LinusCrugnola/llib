/*!****************************************************************************************************************************************
* @file     vec2d_test.cc
*
* @author   Linus Crugnola <linus.crugnola@epfl.ch>     
*
* @version  1.0
*
* @date     28.09.2022
*****************************************************************************************************************************************/
 
#include "llibStddef.h"
#include <gtest/gtest.h>
#include "vec3d.h"
#include "vec2d.h"

#define _TEST_RD(x) (int(1000000 * x))

class vec2dTest : public ::testing::Test {

};

TEST_F(vec2dTest, Construction){
    llib::vec2d<int> u;
    llib::vec2d<int> v(1);
    llib::vec2d<float> w(1.0f, 2.0f);
    EXPECT_EQ(u._x, 0);
    EXPECT_EQ(u._y, 0);
    EXPECT_EQ(v._x, 1);
    EXPECT_EQ(v._y, 1);
    EXPECT_EQ(w._x, 1.0f);
    EXPECT_EQ(w._y, 2.0f);
}

TEST_F(vec2dTest, Addition){
    llib::vec2d<int> u(1);
    llib::vec2d<int> v(1);
    u = u + v;
    EXPECT_EQ(u._x, 2);
    EXPECT_EQ(u._y, 2);
}

TEST_F(vec2dTest, Subtraction){
    llib::vec2d<int> u(3);
    llib::vec2d<int> v(1);
    u = u - v;
    EXPECT_EQ(u._x, 2);
    EXPECT_EQ(u._y, 2);
}

TEST_F(vec2dTest, TrueFalse){
    llib::vec2d<int> u(1);
    EXPECT_TRUE(u == u);
    EXPECT_FALSE(u != u);
}

TEST_F(vec2dTest, Multiplication){
    llib::vec2d<int> v(1);
    v = 3 * v;
    EXPECT_EQ(v._x, 3);
    EXPECT_EQ(v._y, 3);
    v = v * 2;
    EXPECT_EQ(v._x, 6);
    EXPECT_EQ(v._y, 6);
}

TEST_F(vec2dTest, ScalarProduct){
    llib::vec2d<int> u(1, 2);
    llib::vec2d<int> v(4, 3);
    EXPECT_EQ(llib::scalProd(u, v), 10);
}

TEST_F(vec2dTest, Length){
    llib::vec2d<int> v(4, 3);
    EXPECT_EQ(v.len(), 5);
    v = {3, 4};
    EXPECT_EQ(v.len(), 5);
}

TEST_F(vec2dTest, Angle){
    llib::vec2d<float> v(3.0f, 3.0f);
    EXPECT_EQ(v.ang(), M_PI_4f32);
    v = {1.0f, 2.0f - sqrtf32(3.0f)};
    // Take rounded values for verification
    EXPECT_EQ(_TEST_RD(v.ang()), _TEST_RD(M_PIf32/12));
}

TEST_F(vec2dTest, SetLength){
    llib::vec2d<float> v(1.0f, 1.0f);
    v.setLen(5);
    EXPECT_EQ(v.len(), 5);
    v.setLen(2.445);
    EXPECT_EQ(_TEST_RD(v.len()), _TEST_RD(2.445));
}

TEST_F(vec2dTest, SetAngle){
    llib::vec2d<float> v(1.0f, 1.0f);
    v.setAng(0);
    EXPECT_EQ(v._x , v.len());
    EXPECT_EQ(v._y , 0);
    v.setAng(M_PI_2f32);
    EXPECT_LE(v._x, _QUAS_0);
    EXPECT_EQ(v._y, v.len());
    v = {1, 0};
    v.setAng(M_PIf32 / 6);
    EXPECT_EQ(1.0 / 2 , v._y);
    EXPECT_EQ(sqrtf32(3) / 2 , v._x);
}

TEST_F(vec2dTest, Rotate){
    llib::vec2d<float> v(1.0f, 0.0f);
    v.rotate(M_PI);
    EXPECT_EQ(v._x, -1);
    EXPECT_LE(v._y, _QUAS_0);
    v.rotate(M_PI_4f32);
    EXPECT_EQ(_TEST_RD(v._x), _TEST_RD(-M_SQRT1_2f32));
    EXPECT_EQ(_TEST_RD(v._y), _TEST_RD(-M_SQRT1_2f32));
    v.rotate(M_PI_4f32 + M_PIf32 / 6);
    EXPECT_EQ(v._x, 1.0f/2);
    EXPECT_EQ(_TEST_RD(v._y), _TEST_RD(-sqrtf32(3)/2));
}

TEST_F(vec2dTest, Precise8){
    llib::vec2d<float> v(1.0f, 0.0f);
    v.rotate(M_PI_4f32);
    v.preciseE8();
    EXPECT_EQ(v._x, llib::preciseE8(M_SQRT1_2f32));
    EXPECT_LE(v._y, llib::preciseE8(M_SQRT1_2f32));
}