/*
 * TestCase.h
 *
 *  Created on: Nov 25, 2018
 *      Author: dan
 */

#ifndef TESTCASE_H_
#define TESTCASE_H_

using namespace std;

#include <string>

class TestCase {
public:
	TestCase();
	virtual ~TestCase();

	void setDataProject( string str) {m_DataProject = str;};
	void setDataParentId(int n) {m_DataParentId = n;};

	string getDataProject( void ) {return m_DataProject;};
	string getDataParentId( void ) {return to_string(m_DataParentId);};

private:
	string m_DataProject;
	unsigned int m_DataParentId;
};

#endif /* TESTCASE_H_ */
