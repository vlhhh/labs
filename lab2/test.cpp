#include "pch.h"
#include "../lab2/nephroid.h"
#define _USE_MATH_DEFINES 
#include <math.h>

TEST(nephroid, testConstructor) {
	nephroid n(5);
	ASSERT_EQ(n.Get_rad(), 5);
	nephroid n1;
	ASSERT_EQ(n1.Get_rad(), 0);
	nephroid n2(5);
	n2.radius(20);
	ASSERT_EQ(n2.Get_rad(), 20);
	EXPECT_THROW(nephroid(-10), std::exception);
	EXPECT_THROW(nephroid(-8), std::exception);
}

TEST(nephroid, testGet_L) {
	nephroid n(5);
	ASSERT_NEAR(n.Get_L(), 120, nephroid::ABS_ERROR);
	nephroid n2(8);
	ASSERT_NEAR(n2.Get_L(), 192, nephroid::ABS_ERROR);
	nephroid n3(45);
	ASSERT_NEAR(n3.Get_L(), 1080, nephroid::ABS_ERROR);
}

TEST(nephroid, testGet_S) {
	nephroid n(5);
	ASSERT_NEAR(n.Get_S(), 942.47779607693792, nephroid::ABS_ERROR);
	nephroid n1(10);
	ASSERT_NEAR(n.GET_S(), 3769,91118439077518, nephroid::ABS_ERROR);
	nephroid n1(20);
	ASSERT_NEAR(n.GET_S(), 15079,64473723100754, nephroid::ABS_ERROR);
}

TEST(nephoroid, testGet_R) {
	nephroid n(5);
	ASSERT_NEAR(n.Get_R(M_PI), 0, nephroid::ABS_ERROR);
	ASSERT_NEAR(n.Get_R(M_PI / 2), 20, nephroid::ABS_ERROR);
	ASSERT_NEAR(n.Get_R(M_PI * 3 / 2), -20, nephroid::ABS_ERROR);
	ASSERT_NEAR(n.Get_R(M_PI / 6), 10, nephroid::ABS_ERROR);
}

TEST(nephroid, testGet_x) {
	nephroid n(5);
	ASSERT_NEAR(n.Get_x(M_PI), -10, nephroid::ABS_ERROR);
	ASSERT_NEAR(n.Get_x(M_PI / 2), 0, nephroid::ABS_ERROR);
	ASSERT_NEAR(n.Get_x(M_PI / 3), 12.5, nephroid::ABS_ERROR);
}

TEST(nephroid, testGet_y) {
	nephroid n(5);
	ASSERT_NEAR(n.Get_y(M_PI), 0, nephroid::ABS_ERROR);
	ASSERT_NEAR(n.Get_y(M_PI / 2), 20, nephroid::ABS_ERROR);
	ASSERT_NEAR(n.Get_y(M_PI / 6), 2.5, nephroid::ABS_ERROR);
}

TEST(nephroid, test_radius) {
	nephroid n(5);
	n.radius(20);
	ASSERT_NEAR(n.Get_rad(), 20, nephroid::ABS_ERROR);
	n.radius(41);
	ASSERT_NEAR(n.Get_rad(), 41, nephroid::ABS_ERROR);
	EXPECT_THROW(n.radius(-8), std::exception);
}
