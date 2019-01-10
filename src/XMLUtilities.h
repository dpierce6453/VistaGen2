/*
 * XMLUtilities.h
 *	This is an interactor object that operates on the RAMBuffer to do useful things such as finding
 *	the indent level.
 *
 *  Created on: Jan 4, 2019
 *      Author: dan
 */

#ifndef XMLUTILITIES_H_
#define XMLUTILITIES_H_

#include "iTestDriver.h"

class XMLUtilities
{
public:

	XMLUtilities(iTestDriver &itd);
	virtual ~XMLUtilities();

	size_t setindentlocation(int indentlevel);

private:
	iTestDriver &m_itd;
};

#endif /* XMLUTILITIES_H_ */
