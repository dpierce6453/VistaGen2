/*
 * Cpputilities_test.cpp
 *
 *  Created on: Jan 18, 2019
 *      Author: dan
 */

#include <CppUTest/TestHarness.h>

#include "Cpputilities.h"

TEST_GROUP(cpputilties_test)
{
	void setup()
	{
	}
	void teardown()
	{
	}
};


TEST(cpputilties_test, strncmptest_fail)
{
	const char buf[] = {"The Quick Brown Fox"};
	string str("The Quick Brown Fox Jumped");
	Cpputilities *pCppu = new Cpputilities();
	CHECK_FALSE(pCppu->strncmp_equal(buf, str));

	delete pCppu;
}

TEST(cpputilties_test, strncmptest_success)
{
	const char buf[] = {"The Quick Brown Fox"};
	string str("The Quick Brown Fox");
	Cpputilities *pCppu = new Cpputilities();
	CHECK_TRUE(pCppu->strncmp_equal(buf, str));

	delete pCppu;
}

TEST(cpputilties_test, strncmptest_fail2)
{
	const char buf[] = {"The Quick Brown Fox Jumped"};
	string str("The Quick Brown Fox");
	Cpputilities *pCppu = new Cpputilities();
	CHECK_TRUE(pCppu->strncmp_equal(buf, str));

	delete pCppu;
}

