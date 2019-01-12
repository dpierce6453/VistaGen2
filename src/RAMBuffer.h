/*
 * RAMBufferDriver.h
 *
 *  Created on: Nov 12, 2018
 *      Author: dan
 */

#ifndef RAMBUFFER_H_
#define RAMBUFFER_H_

#include "iTestDriver.h"

class RAMBuffer: public iTestDriver {
public:
	static const int nDEFAULT_BUFFER_SIZE = 1024;

	RAMBuffer();
	RAMBuffer(int Buffersize);
	virtual ~RAMBuffer();

	virtual int close();

	virtual int open(const char *path, int flags);

	virtual size_t write(void *buf, size_t nbytes);

	virtual off_t lseek(off_t offset, int base);

	virtual size_t read(void *buf, size_t nbytes);

private:
	char *m_pchRambuffer;
	size_t m_nBufferSize;
	off_t m_nFileoffset;   //I believe that off_t is 64 bit signed int.
	bool m_bOpen;

	void ResetBuffer();
	bool isRequestLargerThanRemainingFileSize(size_t numberofbytes);
	bool isAtEndOfFile();
	size_t setNumberOfBytes(size_t numberofbytes);
};

#endif /* RAMBUFFER_H_ */
