/*
 * TestCase_test.cpp
 *
 *  Created on: Nov 25, 2018
 *      Author: dan
 */

#include <CppUTest/TestHarness.h>

#include "TestCase.h"

TEST_GROUP(TestCaseTests)
{
	void setup()
	{

	}

	void teardown()
	{

	}
};

TEST(TestCaseTests, FirstTest)
{
	CHECK_TRUE(1==1);
}
