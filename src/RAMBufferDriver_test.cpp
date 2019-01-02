/*
 * RAMBufferDriver_test.cpp
 *
 *  Created on: Nov 12, 2018
 *      Author: dan
 */

using namespace std;

#include <cstring>

#include <CppUTest/TestHarness.h>

#include "RAMBufferDriver.h"

extern const string testString6;

TEST_GROUP(RAMBufferDriverTests)
{
	void setup()
	{

	}

	void teardown()
	{

	}
};



TEST(RAMBufferDriverTests, OpenTest)
{
	int fd;
	char *buf = new char[testString6.length()];

	RAMBufferDriver *rb = new RAMBufferDriver();
	fd = rb->open("MyRamBuffer", O_RDWR | O_CREAT);

	rb->write(fd, (void *)testString6.c_str(), testString6.length());

	rb->read(fd, buf, testString6.length());

	CHECK_TRUE(strncmp((const char *)buf, (const char *)testString6.c_str(), testString6.length()) == 0);

	rb->close(fd);
	delete rb;
	delete [] buf;

}

TEST(RAMBufferDriverTests, TwoStringTest)
{
	int fd;
	char *buf = new char[testString6.length() * 2];

	RAMBufferDriver *rb = new RAMBufferDriver();
	fd = rb->open("MyRamBuffer", O_RDWR | O_CREAT);

	rb->write(fd, (void *)testString6.c_str(), testString6.length());
	rb->write(fd, (void *)testString6.c_str(), testString6.length());

	rb->read(fd, buf, (testString6.length() * 2));
	string check = testString6 + testString6;

	CHECK_TRUE(strncmp((const char *)buf, (const char *)check.c_str(), check.length()) == 0);

	rb->close(fd);
	delete rb;
	delete [] buf;

}
