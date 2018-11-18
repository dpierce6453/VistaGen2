//============================================================================
// Name        : Vista.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <cstring>
using namespace std;

#include "CppUTest/TestHarness.h"
#include "CppUTest/CommandLineTestRunner.h"

#include "TestCreatorVistaAPX8000.h"
#include "RAMBufferDriver.h"

int main(int ac, char** av) {
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!

	return CommandLineTestRunner::RunAllTests(ac,av);
}

TEST_GROUP(End2EndTests)
{
	void setup()
	{
	}
	void teardown()
	{
	}
};

const char  testString1[] = "\
      <Step Text=\"Load Radio 1 codeplug\">\n\
        <Action Id=\"LOADCODEPLUG\" ControllerId=\"Radio1\">\n\
          <Property Id=\"LOADCODEPLUG\" Value=\"AMP_IPS_TC1_TC2_SU1.pba\">\n\
            <Property Id=\"LOADTYPE\" Value=\"{PBA}\" />\n\
          </Property>\n\
        </Action>\n\
      </Step>\n";
TEST(End2EndTests, LoadCodePlug)
{
	// create the test creator
	iTestCreator *ptc = new TestCreator_VistaAPX8000();

	// create the test driver and open for reading and writing
	iTestDriver *ptd = new RAMBufferDriver();
	int fd = ptd->open("MyRamBuffer", O_RDWR | O_CREAT);

	LoadCodePlug *lcp = new LoadCodePlug();
	lcp->setTitle("Load Radio 1 codeplug");
	lcp->setFileName("AMP_IPS_TC1_TC2_SU1.pba");
	lcp->setRadioId("Radio1");

	// Create the test and write it
	string vCP = ptc->LoadCodeplug_creator(lcp);
	ptd->write(fd, (void *)vCP.c_str(), strlen(vCP.c_str()));

	// Check the answer
	char *buf = new char[sizeof(testString1)];
	ptd->read(fd, buf, sizeof(testString1));
	STRCMP_EQUAL((const char *)buf, (const char *)testString1);

	delete [] buf;
	delete lcp;
	delete ptd;
	delete ptc;


}
