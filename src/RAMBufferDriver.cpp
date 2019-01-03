/*
 * RAMBufferDriver.cpp
 *
 *  Created on: Nov 12, 2018
 *      Author: dan
 */

#include <cstring>

#include "RAMBufferDriver.h"

RAMBufferDriver::RAMBufferDriver()
{
	m_nBufferSize = nDEFAULT_BUFFER_SIZE;
	ResetBuffer();
}
RAMBufferDriver::RAMBufferDriver(int Buffersize)
{
	m_nBufferSize = Buffersize;
	ResetBuffer();
}


RAMBufferDriver::~RAMBufferDriver() {
	if(m_pchRambuffer != 0)
	{
		delete [] m_pchRambuffer;
		m_pchRambuffer = 0;
	}
}

int RAMBufferDriver::close(int d)
{
	if(m_pchRambuffer != 0)
	{
		delete [] m_pchRambuffer;
		ResetBuffer();
	}
	return 0;
}

int RAMBufferDriver::open(const char *path, int flags)
{
	if(m_pchRambuffer == 0)
	{
		m_pchRambuffer = new char[m_nBufferSize];
		memset(m_pchRambuffer, 0, m_nBufferSize);
	}
	return 1;
}


size_t RAMBufferDriver::write(int d, void *buf, size_t nbytes)
{
	size_t numberofbytes = nbytes;
	numberofbytes = setNumberOfBytes(numberofbytes);
	memcpy(m_pchRambuffer + m_nFileoffset, buf, numberofbytes);
	m_nFileoffset += numberofbytes;

	return numberofbytes;
}

size_t RAMBufferDriver::read(int d, void *buf, size_t nbytes)
{
	size_t numberofbytes = nbytes;
	numberofbytes = setNumberOfBytes(numberofbytes);
	memcpy(buf, m_pchRambuffer + m_nFileoffset, numberofbytes);
	m_nFileoffset+=numberofbytes;

	return numberofbytes;
}
off_t RAMBufferDriver::lseek(int d, off_t offset, int base)
{
	off_t ret = -1;
	off_t relativeoffset;
	switch (base)
	{
	case SEEK_SET:
		relativeoffset = 0;
		break;
	case SEEK_CUR:
		relativeoffset = m_nFileoffset;
		break;
	case SEEK_END:
		relativeoffset = m_nBufferSize;
		break;
	default:
		return ret;  //I don't handle any other cases.
	}

	if((size_t)(offset + relativeoffset) < m_nBufferSize)
	{
		ret = offset + relativeoffset;
	}

	if (ret != -1)
	{
		m_nFileoffset = ret;
	}
	return ret;

}

size_t RAMBufferDriver::setNumberOfBytes(size_t numberofbytes)
{
	if (isRequestLargerThanRemainingFileSize(numberofbytes))
	{
		numberofbytes = m_nBufferSize - m_nFileoffset;
	}
	else if (isAtEndOfFile())
	{
		numberofbytes = 0;
	}

	return numberofbytes;
}

bool RAMBufferDriver::isAtEndOfFile()
{
	return (size_t)m_nFileoffset >= m_nBufferSize;
}

bool RAMBufferDriver::isRequestLargerThanRemainingFileSize(	size_t numberofbytes)
{
	return (size_t)m_nFileoffset + numberofbytes > m_nBufferSize;
}

void RAMBufferDriver::ResetBuffer() {
	m_pchRambuffer = 0;
	m_nFileoffset = 0;
}

