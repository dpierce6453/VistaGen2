/*
 * RAMBufferDriver_test.cpp
 *
 *  Created on: Nov 12, 2018
 *      Author: dan
 */

using namespace std;

#include <cstring>

#include <CppUTest/TestHarness.h>

#include "RAMBuffer.h"
#include "Cpputilities.h"

extern const string testString6;

Cpputilities *pCppu;

TEST_GROUP(RAMBufferDriverTests)
{
	void setup()
	{
		pCppu = new Cpputilities();

	}

	void teardown()
	{
		delete pCppu;
	}
};


TEST(RAMBufferDriverTests, OpenTest2)
{
	// make sure file has to be open before it is used.
	RAMBuffer *rb = new RAMBuffer();

	CHECK_TRUE(rb->write((void *)testString6.c_str(), testString6.length()) == 0);
	CHECK_TRUE(rb->lseek(0, SEEK_SET) == -1);  //seek to beginning of file
	rb->open("MyRamBuffer", O_RDWR | O_CREAT);
	CHECK_TRUE(rb->write((void *)testString6.c_str(), testString6.length()) == testString6.length());
	CHECK_TRUE(rb->lseek(0, SEEK_CUR) == (off_t)testString6.length());  //seek to beginning of file

	delete rb;

}
TEST(RAMBufferDriverTests, OpenTest)
{
	char *buf = new char[testString6.length()];

	RAMBuffer *rb = new RAMBuffer();
	rb->open("MyRamBuffer", O_RDWR | O_CREAT);

	rb->write((void *)testString6.c_str(), testString6.length());
	rb->lseek(0, SEEK_SET);  //seek to beginning of file

	rb->read(buf, testString6.length());

	CHECK_TRUE(pCppu->strncmp_equal(buf, testString6));

	rb->close();
	delete rb;
	delete [] buf;

}

TEST(RAMBufferDriverTests, TwoStringTest)
{
	char *buf = new char[testString6.length() * 2];

	RAMBuffer *rb = new RAMBuffer();
	rb->open("MyRamBuffer", O_RDWR | O_CREAT);

	rb->write((void *)testString6.c_str(), testString6.length());
	rb->write((void *)testString6.c_str(), testString6.length());

	rb->lseek(0, SEEK_SET);  //seek to beginning of file
	rb->read(buf, (testString6.length() * 2));
	string check = testString6 + testString6;


	CHECK_TRUE(pCppu->strncmp_equal(buf, check));

	rb->close();
	delete rb;
	delete [] buf;

}

const string fullbufferteststring = "ABCDEFGHIJKLMNOPQRSTU";  // 21 characters

TEST(RAMBufferDriverTests, FullBufferTest)
{
	const int nRamBufferSize = 1024;
	char *buf = new char[fullbufferteststring.length()];

	RAMBuffer *rb = new RAMBuffer(nRamBufferSize);
	rb->open("MyRamBuffer", O_RDWR | O_CREAT);

	unsigned int loops = nRamBufferSize / fullbufferteststring.length();
	unsigned int numbytes = 0;
	for(unsigned int i=0; i < loops; i++)
	{
		numbytes = rb->write((void *)fullbufferteststring.c_str(), fullbufferteststring.length());
		CHECK_TRUE(numbytes == fullbufferteststring.length());
	}

	// write the last partial buffer.
	numbytes = rb->write((void *)fullbufferteststring.c_str(), fullbufferteststring.length());
	CHECK_TRUE(numbytes == nRamBufferSize % fullbufferteststring.length());

	// finally make sure a write after this gets a 0
	numbytes = rb->write((void *)fullbufferteststring.c_str(), fullbufferteststring.length());
	CHECK_TRUE(numbytes == 0);

	// Now let's read it all back
	rb->lseek(0, SEEK_SET);  //seek to beginning of file

	for(unsigned int i=0; i < loops; i++)
	{
		memset(buf, '.', fullbufferteststring.length());
		numbytes = rb->read(buf, fullbufferteststring.length());
		CHECK_TRUE(numbytes == fullbufferteststring.length());
		CHECK_TRUE(pCppu->strncmp_equal(buf, fullbufferteststring));
	}
	// read the last partial buffer
	memset(buf, '.', fullbufferteststring.length());
	numbytes = rb->read(buf, fullbufferteststring.length());
	CHECK_TRUE(numbytes == nRamBufferSize % fullbufferteststring.length());
	CHECK_TRUE(pCppu->strncmp_equal(buf, fullbufferteststring, nRamBufferSize % fullbufferteststring.length()));

	// finally make sure a write after this gets a 0
	numbytes = rb->read(buf, fullbufferteststring.length());
	CHECK_TRUE(numbytes == 0);

	rb->close();
	delete rb;
	delete [] buf;

}
TEST(RAMBufferDriverTests, lseekTest1)
{
	size_t numberofbytes;
	char *buf = new char[testString6.length() * 2];

	RAMBuffer *rb = new RAMBuffer();
	rb->open("MyRamBuffer", O_RDWR | O_CREAT);

	rb->write((void *)testString6.c_str(), testString6.length());
	rb->write((void *)testString6.c_str(), testString6.length());
	rb->lseek(100, SEEK_SET);  //seek to at point 100 characters offset into the file
	string check = testString6 + testString6;

	numberofbytes = rb->read(buf, testString6.length());

	CHECK_TRUE(pCppu->strncmp_equal(buf, (const char *)(check.c_str()+100), numberofbytes));

	rb->close();
	delete rb;
	delete [] buf;
}

TEST(RAMBufferDriverTests, lseekTest2)
{
	size_t numberofbytes;
	char *buf = new char[testString6.length()];

	RAMBuffer *rb = new RAMBuffer();
	rb->open("MyRamBuffer", O_RDWR | O_CREAT);

	rb->write((void *)testString6.c_str(), testString6.length());
	rb->lseek(10, SEEK_SET);  //seek to at point 10 characters offset into the file

	numberofbytes = rb->read(buf, testString6.length());

	CHECK_TRUE(pCppu->strncmp_equal(buf, (const char *)(testString6.c_str()+10), numberofbytes));

	rb->close();
	delete rb;
	delete [] buf;
}

TEST(RAMBufferDriverTests, lseekTestEndOfFile)
{
	off_t offset;

	RAMBuffer *rb = new RAMBuffer(256);
	rb->open("MyRamBuffer", O_RDWR | O_CREAT);

	offset = rb->lseek(0, SEEK_END);
	CHECK_TRUE(offset == 256);

	offset = rb->lseek(1, SEEK_END);  // deliberately seek past the end of the file
	CHECK_TRUE(offset == -1);

	offset = rb->lseek(1, SEEK_CUR);  // deliberately seek past the end of the file
	CHECK_TRUE(offset == -1);

	offset = rb->lseek(125, SEEK_SET);
	CHECK_TRUE(offset == 125);

	offset = rb->lseek(5, SEEK_CUR);
	CHECK_TRUE(offset = 130);

	offset = rb->lseek(-10, SEEK_CUR);
	CHECK_TRUE(offset = 120);

	offset = rb->lseek(300, SEEK_SET);  // deliberately seek past the end of the file
	CHECK_TRUE(offset = -1);

	rb->close();
	delete rb;

}

