/*
 * RAMBufferDriver.cpp
 *
 *  Created on: Nov 12, 2018
 *      Author: dan
 */

#include "RAMBufferDriver.h"

RAMBufferDriver::RAMBufferDriver()
{
	nBufferSize = nDEFAULT_BUFFER_SIZE;
	ResetBuffer();
}
RAMBufferDriver::RAMBufferDriver(int Buffersize)
{
	nBufferSize = Buffersize;
	ResetBuffer();
}


RAMBufferDriver::~RAMBufferDriver() {
	if(m_pchRambuffer != 0)
	{
		delete [] m_pchRambuffer;
		m_pchRambuffer = 0;
	}
}

void RAMBufferDriver::ResetBuffer() {
	m_pchRambuffer = 0;
	m_nWriteindex = 0;
	m_nReadindex = 0;
}

// This function is called once when the test ends.
	// It will be a signal to write and close XML for XML based tests.
int RAMBufferDriver::close(int d)
{
	if(m_pchRambuffer != 0)
	{
		delete [] m_pchRambuffer;
		ResetBuffer();
	}
	return 0;
}

	// This function is called once before the test starts to allow for setup.
	// In the case of XML it will create the buffer and or open the file
int RAMBufferDriver::open(const char *path, int flags)
{
	if(m_pchRambuffer == 0)
		m_pchRambuffer = new char[nBufferSize];
	return 1;
}

size_t RAMBufferDriver::write(int d, void *buf, size_t nbytes)
{
	char * pch = (char *)buf;
	unsigned int numberofbytes = nbytes;
	if (m_nWriteindex + numberofbytes > nBufferSize)
	{
		numberofbytes = nBufferSize - m_nWriteindex;
	}
	else if (m_nWriteindex >= nBufferSize)
	{
		return 0;
	}

	for(unsigned int i=0; i<numberofbytes; i++)
	{
		m_pchRambuffer[m_nWriteindex] = pch[i];
		m_nWriteindex++;
	}

	return numberofbytes;
}

void RAMBufferDriver::lseek(int d, off_t offset, int base)
{

}

size_t RAMBufferDriver::read(int d, void *buf, size_t nbytes)
{
	char *pch = (char *)buf;
	unsigned int numberofbytes = nbytes;
	if (m_nReadindex + numberofbytes > nBufferSize)
	{
		numberofbytes = nBufferSize - m_nReadindex;
	}
	else if (m_nReadindex >= nBufferSize)
	{
		return 0;
	}

	for(unsigned int i=0; i<numberofbytes; i++)
	{
		pch[i] = m_pchRambuffer[m_nReadindex++];
	}

	return numberofbytes;
}
