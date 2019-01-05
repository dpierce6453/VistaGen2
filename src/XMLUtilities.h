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

#include "iTestCreator.h"

class XMLUtilities
{
public:

	XMLUtilities(iTestCreator &itc);
	virtual ~XMLUtilities();

	int setindentlocation(int indentlevel);

private:
	iTestCreator &m_itc;
};

#endif /* XMLUTILITIES_H_ */
