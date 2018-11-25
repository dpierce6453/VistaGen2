/*
 * ActionSendXCMPMessageRequest_test.cpp
 *
 *  Created on: Nov 20, 2018
 *      Author: dan
 */

#include <CppUTest/TestHarness.h>

#include "ActionSendXCMPMessageRequest.h"

TEST_GROUP(SendXCMPMessageRequestTests)
{
	void setup()
	{
	}
	void teardown()
	{
	}
};

TEST(SendXCMPMessageRequestTests, FirstTest)
{
	ActionSendXCMPMessageRequest *pASXM = new ActionSendXCMPMessageRequest();


	delete pASXM;
}
