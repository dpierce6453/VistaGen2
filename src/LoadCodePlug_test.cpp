/*
 * LoadCodePlug_test.cpp
 *
 *  Created on: Nov 9, 2018
 *      Author: dan
 */

#include <CppUTest/TestHarness.h>

#include "LoadCodePlug.h"


TEST_GROUP(LoadCodePlugTests)
{
	void setup()
	{
	}
	void teardown()
	{
	}
};


TEST(LoadCodePlugTests, LoadSimpleCodePlug)
{
	string title = "Load Radio 1 codeplug";
	string filename = "AMP_IPS_TC1_TC2_SU1.pba";
	string radioid = "Radio1";
	LoadCodePlug *lcp = new LoadCodePlug();
	lcp->setTitle(title);
	lcp->setFileName(filename);
	lcp->setRadioId(radioid);
	STRCMP_EQUAL(title.c_str(), lcp->getTitle().c_str());
	STRCMP_EQUAL(filename.c_str(), lcp->getFileName().c_str());
	STRCMP_EQUAL(radioid.c_str(), lcp->getRadioId().c_str());

	delete lcp;
}
