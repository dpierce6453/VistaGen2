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
#include "RAMBufferDriver.h"

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
	// Now write this to a RAMBuffer
	iTestDriver *pitd = new RAMBufferDriver();

	pitd->open("MyRamBuffer", O_RDWR | O_CREAT);

	pitd->write(1, (void *)test.c_str(), test.length());
	//pitd->lseek(fd, 0, SEEK_SET);  //seek to beginning of file
	//pitd->read(fd, buf, test.length());


	XMLUtilities *xmlu = new XMLUtilities(*pitd);

	size_t pos = xmlu->setindentlocation(1);

	CHECK_TRUE(1==1);
	delete pitd;
	delete xmlu;

}
