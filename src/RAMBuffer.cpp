/*
 * RAMBufferDriver.cpp
 *
 *  Created on: Nov 12, 2018
 *      Author: dan
 */

#include "RAMBuffer.h"

#include <cstring>


RAMBuffer::RAMBuffer()
{
	m_nBufferSize = nDEFAULT_BUFFER_SIZE;
	ResetBuffer();
}
RAMBuffer::RAMBuffer(int Buffersize)
{
	m_nBufferSize = Buffersize;
	ResetBuffer();
}


RAMBuffer::~RAMBuffer() {
	if(m_pchRambuffer != 0)
	{
		delete [] m_pchRambuffer;
		m_pchRambuffer = 0;
	}
}

int RAMBuffer::close( void )
{
	if(m_pchRambuffer != 0)
	{
		delete [] m_pchRambuffer;
		ResetBuffer();
	}
	return 0;
}

int RAMBuffer::open(const char *path, int flags)
{
	if(m_pchRambuffer == 0)
	{
		m_pchRambuffer = new char[m_nBufferSize];
		memset(m_pchRambuffer, 0, m_nBufferSize);
	}
	return 1;
}


size_t RAMBuffer::write(void *buf, size_t nbytes)
{
	size_t numberofbytes = nbytes;
	numberofbytes = setNumberOfBytes(numberofbytes);
	memcpy(m_pchRambuffer + m_nFileoffset, buf, numberofbytes);
	m_nFileoffset += numberofbytes;

	return numberofbytes;
}

size_t RAMBuffer::read(void *buf, size_t nbytes)
{
	size_t numberofbytes = nbytes;
	numberofbytes = setNumberOfBytes(numberofbytes);
	memcpy(buf, m_pchRambuffer + m_nFileoffset, numberofbytes);
	m_nFileoffset+=numberofbytes;

	return numberofbytes;
}
off_t RAMBuffer::lseek(off_t offset, int base)
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

	if((size_t)(offset + relativeoffset) <= m_nBufferSize)
	{
		ret = offset + relativeoffset;
	}

	if (ret != -1)
	{
		m_nFileoffset = ret;
	}
	return ret;

}

size_t RAMBuffer::setNumberOfBytes(size_t numberofbytes)
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

bool RAMBuffer::isAtEndOfFile()
{
	return (size_t)m_nFileoffset >= m_nBufferSize;
}

bool RAMBuffer::isRequestLargerThanRemainingFileSize(	size_t numberofbytes)
{
	return (size_t)m_nFileoffset + numberofbytes > m_nBufferSize;
}

void RAMBuffer::ResetBuffer() {
	m_pchRambuffer = 0;
	m_nFileoffset = 0;
}

