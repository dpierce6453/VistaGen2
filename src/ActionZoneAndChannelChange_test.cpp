/*
 * ActionZoneAndChannelChange_test.cpp
 *
 *  Created on: Nov 20, 2018
 *      Author: dan
 */

#include <CppUTest/TestHarness.h>


#include "ActionZoneAndChannelChange.h"

TEST_GROUP(ZoneAndChannelChangeTests)
{
	void setup()
	{
	}
	void teardown()
	{
	}
};

TEST(ZoneAndChannelChangeTests, FirstTest)
{
	ActionZoneAndChannelChange *pAZC = new ActionZoneAndChannelChange();

	pAZC->setChannel(0x45);
	pAZC->setZone(0x78);

	CHECK_TRUE(pAZC->getChannel() == 0x45);
	CHECK_TRUE(pAZC->getZone() == 0x78);

	delete pAZC;
}
