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

	virtual off_t lseek(int d, off_t offset, int base);

	virtual size_t read(int d, void *buf, size_t nbytes);

private:
	char *m_pchRambuffer;
	size_t m_nBufferSize;
	off_t m_nFileoffset;   //I believe that off_t is 64 bit signed int.

	void ResetBuffer();
	bool isRequestLargerThanRemainingFileSize(size_t numberofbytes);
	bool isAtEndOfFile();
	size_t setNumberOfBytes(size_t numberofbytes);
};

#endif /* RAMBUFFERDRIVER_H_ */
