/*
 * RAMBufferDriver.cpp
 *
 *  Created on: Nov 12, 2018
 *      Author: dan
 */

#include "RAMBufferDriver.h"

RAMBufferDriver::RAMBufferDriver() {
	m_rambuffer=0;

}

RAMBufferDriver::~RAMBufferDriver() {
	if(m_rambuffer != 0)
	{
		delete [] m_rambuffer;
		m_rambuffer = 0;
	}
}

// This function is called once when the test ends.
	// It will be a signal to write and close XML for XML based tests.
int RAMBufferDriver::close(int d)
{
	if(m_rambuffer != 0)
	{
		delete [] m_rambuffer;
		m_rambuffer =0;
	}
	return 0;
}

	// This function is called once before the test starts to allow for setup.
	// In the case of XML it will create the buffer and or open the file
int RAMBufferDriver::open(const char *path, int flags)
{
	if(m_rambuffer == 0)
		m_rambuffer = new char[1024];
	return 1;
}

void RAMBufferDriver::write(int d, void *buf, size_t nbytes)
{
	char * pch = (char *)buf;
	for(unsigned int i=0; i<nbytes; i++)
	{
		m_rambuffer[i] = pch[i];
	}
}

void RAMBufferDriver::lseek(int d, off_t offset, int base)
{

}

void RAMBufferDriver::read(int d, void *buf, size_t nbytes)
{
	char *pch = (char *)buf;
	for(unsigned int i=0; i<nbytes; i++)
	{
		pch[i] = m_rambuffer[i];
	}
}
