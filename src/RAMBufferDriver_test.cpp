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

const string fullbufferteststring = "ABCDEFGHIJKLMNOPQRSTU";  // 21 characters

TEST(RAMBufferDriverTests, FullBufferTest)
{
	const int nRamBufferSize = 1024;
	int fd;
	char *buf = new char[fullbufferteststring.length()];

	RAMBufferDriver *rb = new RAMBufferDriver(nRamBufferSize);
	fd = rb->open("MyRamBuffer", O_RDWR | O_CREAT);

	unsigned int loops = nRamBufferSize / fullbufferteststring.length();
	unsigned int numbytes = 0;
	for(unsigned int i=0; i < loops; i++)
	{
		numbytes = rb->write(fd, (void *)fullbufferteststring.c_str(), fullbufferteststring.length());
		CHECK_TRUE(numbytes == fullbufferteststring.length());
	}

	// write the last partial buffer.
	numbytes = rb->write(fd, (void *)fullbufferteststring.c_str(), fullbufferteststring.length());
	CHECK_TRUE(numbytes == nRamBufferSize % fullbufferteststring.length());

	// finally make sure a write after this gets a 0
	numbytes = rb->write(fd, (void *)fullbufferteststring.c_str(), fullbufferteststring.length());
	CHECK_TRUE(numbytes == 0);

	// Now let's read it all back
	for(unsigned int i=0; i < loops; i++)
	{
		memset(buf, '.', fullbufferteststring.length());
		numbytes = rb->read(fd, buf, fullbufferteststring.length());
		CHECK_TRUE(numbytes == fullbufferteststring.length());
		CHECK_TRUE(strncmp((const char *)buf, (const char *)fullbufferteststring.c_str(), fullbufferteststring.length()) == 0);
	}
	// read the last partial buffer
	memset(buf, '.', fullbufferteststring.length());
	numbytes = rb->read(fd, buf, fullbufferteststring.length());
	CHECK_TRUE(numbytes == nRamBufferSize % fullbufferteststring.length());
	CHECK_TRUE(strncmp((const char *)buf, (const char *)fullbufferteststring.c_str(), nRamBufferSize % fullbufferteststring.length()) == 0);

	// finally make sure a write after this gets a 0
	numbytes = rb->read(fd, buf, fullbufferteststring.length());
	CHECK_TRUE(numbytes == 0);

	rb->close(fd);
	delete rb;
	delete [] buf;

}
