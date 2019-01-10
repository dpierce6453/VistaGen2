/*
 * XMLUtilities.cpp
 *
 *  Created on: Jan 4, 2019
 *      Author: dan
 */

using namespace std;
#include <string>

#include "XMLUtilities.h"

XMLUtilities::XMLUtilities(iTestDriver &itd) :
m_itd(itd)
{
}

XMLUtilities::~XMLUtilities()
{
}

size_t XMLUtilities::setindentlocation(int indentlevel)
{
	// Remember the current location
	off_t currentoffset = m_itd.lseek(1, 0, SEEK_CUR);
	size_t filesize = m_itd.lseek(1,0,SEEK_END);

	char *buf = new char[filesize];
	m_itd.lseek(1,0,SEEK_SET);
	m_itd.read(1, buf, filesize);

	//string file(buf, filesize);
	//string match("</");
	size_t pos = string::npos;
	//for(int i=0; i<indentlevel; i++)
	//{
	//	pos = file.rfind(match, pos);
	//}

	m_itd.lseek(1,currentoffset, SEEK_SET);  // restore the i/o index.
	return pos;
}
