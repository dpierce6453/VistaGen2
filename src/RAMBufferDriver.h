/*
 * RAMBufferDriver.h
 *
 *  Created on: Nov 12, 2018
 *      Author: dan
 */

#ifndef RAMBUFFERDRIVER_H_
#define RAMBUFFERDRIVER_H_

#include "iTestDriver.h"

class RAMBufferDriver: public iTestDriver {
public:
	RAMBufferDriver();
	virtual ~RAMBufferDriver();

		virtual int close(int d);

		virtual int open(const char *path, int flags);

		virtual void write(int d, void *buf, size_t nbytes);

		virtual void lseek(int d, off_t offset, int base);

		virtual void read(int d, void *buf, size_t nbytes);

private:
		char *m_rambuffer;
};

#endif /* RAMBUFFERDRIVER_H_ */
