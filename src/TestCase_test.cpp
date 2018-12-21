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
	string DataProject = "Astro";
	string DataParentId = "41234";

	TestCase *pTC = new TestCase();
	pTC->setDataProject(DataProject);
	pTC->setDataParentId(41234);

	STRCMP_EQUAL(DataProject.c_str(), pTC->getDataProject().c_str());
	STRCMP_EQUAL(DataParentId.c_str(), pTC->getDataParentId().c_str());

	delete pTC;
}
