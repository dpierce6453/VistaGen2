/*
 * LoadCodePlugTestCreatorVistaAPX8000_test.cpp
 *
 *  Created on: Nov 12, 2018
 *      Author: dan
 */

using namespace std;

#include <iostream>

#include <CppUTest/TestHarness.h>

#include "TestCreatorVistaAPX8000.h"


TEST_GROUP(TestCreatorVistaAPX8000Tests)
{
	void setup()
	{

	}

	void teardown()
	{

	}
};


const string testString4 = "\
      <Step Text=\"Load Radio 1 codeplug\">\n\
        <Action Id=\"LOADCODEPLUG\" ControllerId=\"Radio1\">\n\
          <Property Id=\"LOADCODEPLUG\" Value=\"AMP_IPS_TC1_TC2_SU1.pba\">\n\
            <Property Id=\"LOADTYPE\" Value=\"{PBA}\" />\n\
          </Property>\n\
        </Action>\n\
      </Step>\n";


extern const string testString1;
extern const string testString3;

TEST(TestCreatorVistaAPX8000Tests, LoadCodeplugTest)
{
	iTestCreator *tc = new TestCreator_VistaAPX8000();

	LoadCodePlug *lcp = new LoadCodePlug();
	lcp->setTitle("Load Radio 1 codeplug");
	lcp->setFileName("AMP_IPS_TC1_TC2_SU1.pba");
	lcp->setRadioId("Radio1");

	string vCP = tc->LoadCodeplug_creator(lcp);
	STRCMP_EQUAL(vCP.c_str(), testString1.c_str());

	delete lcp;
	delete tc;

}

TEST(TestCreatorVistaAPX8000Tests, TestCaseTest)
{
	iTestCreator *tc = new TestCreator_VistaAPX8000();

	string DataProject = "Astro";
	string DataParentId = "41234";
	TestCase *pTC = new TestCase();
	pTC->setDataProject(DataProject);
	pTC->setDataParentId(41234);

	string strTC = tc->TestCase_creator(*pTC);
	STRCMP_EQUAL(strTC.c_str(), testString3.c_str());

	delete pTC;
	delete tc;
}
TEST(TestCreatorVistaAPX8000Tests, setLevelTest)
{
	TestCreator_VistaAPX8000 *tc = new TestCreator_VistaAPX8000();

	tc->setString(testString1);
	tc->setlevel(3);
	STRCMP_EQUAL(tc->getString().c_str(), testString4.c_str());

	delete tc;
}
