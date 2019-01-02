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
	static const int nDEFAULT_BUFFER_SIZE = 1024;

	RAMBufferDriver();
	RAMBufferDriver(int Buffersize);
	virtual ~RAMBufferDriver();

	virtual int close(int d);

	virtual int open(const char *path, int flags);

	virtual size_t write(int d, void *buf, size_t nbytes);

	virtual void lseek(int d, off_t offset, int base);

	virtual size_t read(int d, void *buf, size_t nbytes);

private:
	char *m_pchRambuffer;
	unsigned int m_nWriteindex;
	unsigned int m_nReadindex;
	unsigned int nBufferSize;

	void ResetBuffer();
};

#endif /* RAMBUFFERDRIVER_H_ */
