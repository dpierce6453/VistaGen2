/*
 * Cpputilities.h
 *
 *  Created on: Jan 18, 2019
 *      Author: dan
 */

#ifndef CPPUTILITIES_H_
#define CPPUTILITIES_H_

using namespace std;

#include <string>

class Cpputilities {
public:
	Cpputilities();
	virtual ~Cpputilities();


	int strncmp_equal(const char *buf, string str);
	int strncmp_equal(const char *buf, string str, size_t num);
	int strncmp_equal(const char *buf, const char *buf1, size_t num);

};

#endif /* CPPUTILITIES_H_ */
