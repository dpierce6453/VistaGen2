/*
 * XMLUtilities_test.cpp
 *
 *  Created on: Jan 4, 2019
 *      Author: dan
 */

using namespace std;
#include <iostream>
#include <string>

#include <CppUTest/TestHarness.h>


#include "XMLUtilities.h"

TEST_GROUP(XMLUtilitiesTest)
{
	void setup()
	{

	}

	void teardown()
	{

	}
};

extern const string testString3;
extern const string testString1;

TEST(XMLUtilitiesTest, FirstTest)
{
	string test = testString3;
	test.insert(test.find_last_of('<'), testString1);
	cout << test;
	CHECK_TRUE(1==1);
}
