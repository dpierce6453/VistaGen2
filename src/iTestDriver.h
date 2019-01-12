/*
 * iCreateTest.h
 *
 *  Created on: Nov 9, 2018
 *      Author: dan
 */

#ifndef ITESTDRIVER_H_
#define ITESTDRIVER_H_

#include <fcntl.h>
#include <sys/types.h>

class iTestDriver {
public:
	iTestDriver();
	virtual ~iTestDriver();

	virtual int close(void) = 0;

	virtual int open(const char *path, int flags) = 0;

	virtual size_t write(void *buf, size_t nbytes) = 0;

	virtual off_t lseek(off_t offset, int base) = 0;

	virtual size_t read(void *buf, size_t nbytes) = 0;

};
#endif /* ITESTDRIVER_H_ */
