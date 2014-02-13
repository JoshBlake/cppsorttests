#include "gtest\gtest.h"
#include <vector>

bool returns_true()
{
	return true;
}

bool returns_false()
{
	return false;
}


TEST(TestingTheTester, Truth) {	
	EXPECT_EQ(true, returns_true());
}

TEST(TestingTheTester, False) {
	EXPECT_EQ(false, returns_false());
}