/*
 * RAMBufferDriver_test.cpp
 *
 *  Created on: Nov 12, 2018
 *      Author: dan
 */


#include <CppUTest/TestHarness.h>

#include "RAMBufferDriver.h"


TEST_GROUP(RAMBufferDriverTests)
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

TEST(RAMBufferDriverTests, OpenTest)
{
	int fd;
	char *buf = new char[sizeof(testString1)];

	RAMBufferDriver *rb = new RAMBufferDriver();
	fd = rb->open("MyRamBuffer", O_RDWR | O_CREAT);

	rb->write(fd, (void *)testString1, sizeof(testString1));

	rb->read(fd, buf, sizeof(testString1));

	STRCMP_EQUAL((const char *)buf, (const char *)testString1);

	rb->close(fd);
	delete rb;
	delete [] buf;

}
