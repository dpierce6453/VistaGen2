/*
 * Cpputilities.cpp
 *
 *  Created on: Jan 18, 2019
 *      Author: dan
 */

#include <iostream>
#include <cstring>

#include "Cpputilities.h"

Cpputilities::Cpputilities() {
	// TODO Auto-generated constructor stub

}

Cpputilities::~Cpputilities() {
	// TODO Auto-generated destructor stub
}
int Cpputilities::strncmp_equal(const char *buf, string str)
{
	return(strncmp_equal(buf, str, str.length()));
}

int Cpputilities::strncmp_equal(const char *buf, string str, size_t num)
{
	return(strncmp_equal(buf, (const char *)str.c_str(), num));
}
int Cpputilities::strncmp_equal(const char *buf, const char* buf1, size_t num)
{
	int ret = strncmp(buf, buf1, num);
	if (ret !=0)
	{
		cout << "Strings are not equal\n";
		cout << "Expected:  " << buf << '\n';
		cout << "But was:  " << buf1 << '\n';
		ret = 0;
	}
	else
	{
		ret = 1;
	}

	return ret;
}

