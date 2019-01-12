/*
 * XMLUtilities_test.cpp
 *
 *  Created on: Jan 4, 2019
 *      Author: dan
 */

using namespace std;
#include <iostream>
#include <cstring>

#include <CppUTest/TestHarness.h>


#include "XMLUtilities.h"
#include "RAMBuffer.h"


extern const string testString3;
extern const string testString1;

namespace utilities_ns
{

string *pTest;
iTestDriver *pitd;
XMLUtilities *xmlu;

TEST_GROUP(XMLUtilitiesTest)
{
	void setup()
	{
		pTest = new string(testString3);
		pTest->insert(pTest->find_last_of('<'), testString1);
		pitd = new RAMBuffer();
		pitd->open("MyRamBuffer", O_RDWR | O_CREAT);
		pitd->write((void *)pTest->c_str(), pTest->length());
		xmlu = new XMLUtilities(*pitd);
	}

	void teardown()
	{
		delete pTest;
		delete pitd;
		delete xmlu;
	}
};


const string testStringXML1 = "</TestCase>\n";
const string testStringXML2 = "</Step>\n";
const string testStringXML3 = "</Action>\n";
const string testStringXML4 = "</Property>\n";


void CheckIndent(string str, size_t position)
{
	char *buf = new char[str.length()];
	pitd->lseek(position, SEEK_SET);
	pitd->read(buf, str.length());

	CHECK_TRUE(strncmp( (const char *)buf , (const char *)(str.c_str()) , str.length()) == 0);

	delete [] buf;
}

TEST(XMLUtilitiesTest, FirstTest)
{
	size_t pos = xmlu->setindentlocation(1);
	CHECK_TRUE(pos == 296);
	CheckIndent(testStringXML1, pos);
}

TEST(XMLUtilitiesTest, SecondTest)
{
	size_t pos = xmlu->setindentlocation(2);
	CHECK_TRUE(pos == 288);
	CheckIndent(testStringXML2, pos);
}

TEST(XMLUtilitiesTest, ThirdTest)
{
	size_t pos = xmlu->setindentlocation(3);
	CHECK_TRUE(pos == 278);
	CheckIndent(testStringXML3, pos);
}

TEST(XMLUtilitiesTest, FourthTest)
{
	size_t pos = xmlu->setindentlocation(4);
	CHECK_TRUE(pos == 266);
	CheckIndent(testStringXML4, pos);
}

} //end namespace
