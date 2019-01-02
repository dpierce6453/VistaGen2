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

extern const string testString1;

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
	ptd->write(fd, (void *)vCP.c_str(), vCP.length());

	// Check the answer
	char *buf = new char[testString1.length()];
	ptd->read(fd, buf, testString1.length());

	CHECK_TRUE(strncmp((const char *)buf, (const char *)testString1.c_str(), testString1.length()) == 0);

	delete [] buf;
	delete lcp;
	delete ptd;
	delete ptc;


}
