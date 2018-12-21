/*
 * LoadCodePlugTestCreatorVistaAPX8000.cpp
 *
 *  Created on: Nov 12, 2018
 *      Author: dan
 */

#include <iostream>
#include <cstring>
#include <stdio.h>


#include "TestCreatorVistaAPX8000.h"

string str1("<Step Text=\"%s\">\n");
string str2("<Action Id=\"LOADCODEPLUG\" ControllerId=\"%s\">\n");
string str3("<Property Id=\"LOADCODEPLUG\" Value=\"%s\">\n");
string str4("<Property Id=\"LOADTYPE\" Value=\"{PBA}\" />\n");
string str5("</Property>\n");
string str6("</Action>\n");
string str7("</Step>\n");
string str8("<TestCase>\n");
string str9("<DataProject>%s</DataProject>\n");
string str10("<DataParentId>%s</DataParentId>\n");
string str11("</TestCase>\n");

TestCreator_VistaAPX8000::TestCreator_VistaAPX8000() {
	// TODO Auto-generated constructor stub

}

TestCreator_VistaAPX8000::~TestCreator_VistaAPX8000() {
	// TODO Auto-generated destructor stub
}

string &TestCreator_VistaAPX8000::LoadCodeplug_creator(LoadCodePlug *lcp)
{
	int pos;
	m_ret.clear();
	m_ret.assign(str1 + str2 + str3 + str4 + str5 + str6 + str7);
	pos = findoccurrence("%s",1);
	m_ret.replace(pos,2,lcp->getTitle());
	pos = findoccurrence("%s",1);
	m_ret.replace(pos,2,lcp->getRadioId());
	pos = findoccurrence("%s",1);
	m_ret.replace(pos,2,lcp->getFileName());

	//setlevel(3);

	return m_ret;

}
string &TestCreator_VistaAPX8000::TestCase_creator(TestCase &tc)
{
	int pos;
    m_ret.clear();
	m_ret.assign(str8 + str9 + str10 + str11);
	pos = findoccurrence("%s",1);
	m_ret.replace(pos,2, tc.getDataProject());
	pos = findoccurrence("%s",1);
	m_ret.replace(pos,2, tc.getDataParentId());
	return m_ret;
}

string &TestCreator_VistaAPX8000::ActionZoneAndChannelChange_creator(ActionZoneAndChannelChange &azc)
{
	return m_ret;
}

const string spaces("                              "); // 30 spaces - enough for 15 levels

int TestCreator_VistaAPX8000::findoccurrence(const char *str, int number)
{
	int ret;
	for(int j=0, position = 0; j<number; j++)
	{
		ret = m_ret.find(str, position);
		position = ret+1;
	}
	return ret;
}
void TestCreator_VistaAPX8000::setlevel(int level)
{
		int numlevels = 0;

		// find the number of strings we are dealing with.
		size_t position = 0;
		size_t location;
		while((location = m_ret.find("<", position)) != string::npos)
		{
			position = location+1;
			numlevels++;
		}
		for(int i=0; i<numlevels; i++)
		{
			location = findoccurrence("<", i+1);
			m_ret.insert(location, spaces.substr(0, level*2));
			if (i< (numlevels/2) )
			{
				level++;
			}
			else
			{
				level--;
			}
		}
}


