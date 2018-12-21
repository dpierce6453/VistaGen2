/*
 * LoadCodePlugTestCreatorVistaAPX8000.h
 *
 *  Created on: Nov 12, 2018
 *      Author: dan
 */

#ifndef TESTCREATORVISTAAPX8000_H_
#define TESTCREATORVISTAAPX8000_H_

#include "iTestCreator.h"
#include "LoadCodePlug.h"
#include "TestCase.h"
#include "ActionZoneAndChannelChange.h"

class TestCreator_VistaAPX8000: public iTestCreator {
public:
	TestCreator_VistaAPX8000();
	virtual ~TestCreator_VistaAPX8000();

	virtual string &LoadCodeplug_creator(LoadCodePlug *lcp);
	virtual string &ActionZoneAndChannelChange_creator(ActionZoneAndChannelChange &azc);
	virtual string &TestCase_creator(TestCase &tc);

	void setlevel(int level);

	string &getString() {return m_ret;};
	void setString(const string &str) {m_ret = str;};

private:
	string m_ret;
	int findoccurrence(const char *, int number);


};

#endif /* TESTCREATORVISTAAPX8000_H_ */
