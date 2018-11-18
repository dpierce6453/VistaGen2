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


const char * codeplug1 = "\
      <Step Text=\"Load Radio 1 codeplug\">\n\
        <Action Id=\"LOADCODEPLUG\" ControllerId=\"Radio1\">\n\
          <Property Id=\"LOADCODEPLUG\" Value=\"AMP_IPS_TC1_TC2_SU1.pba\">\n\
            <Property Id=\"LOADTYPE\" Value=\"{PBA}\" />\n\
          </Property>\n\
        </Action>\n\
      </Step>\n";

TEST(LoadCodePlugTests, LoadSimpleCodePlug)
{
	string title = "Load Radio 1 codeplug";
	string filename = "AMP_IPS_TC1_TC2_SU1.pba";
	string radioid = "Radio1";
	LoadCodePlug *lcp = new LoadCodePlug();
	lcp->setTitle(title);
	lcp->setFileName(filename);
	lcp->setRadioId(radioid);
	STRCMP_EQUAL(title.c_str(), lcp->getTitle());
	STRCMP_EQUAL(filename.c_str(), lcp->getFileName());
	STRCMP_EQUAL(radioid.c_str(), lcp->getRadioId());

	delete lcp;
}
