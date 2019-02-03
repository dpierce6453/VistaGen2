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
	int ret = strncmp(buf, (const char *)str.c_str(), str.length());
	if (ret !=0)
	{
		cout << "Strings are not equal\n";
		cout << "Expected:  " << buf << '\n';
		cout << "But was:  " << str << '\n';
		ret = 0;
	}
	else
	{
		ret = 1;
	}

	return ret;
}

