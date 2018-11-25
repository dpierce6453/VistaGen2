/*
 * ActionZoneAndChannelChange.h
 *
 *  Created on: Nov 20, 2018
 *      Author: dan
 */

#ifndef ACTIONZONEANDCHANNELCHANGE_H_
#define ACTIONZONEANDCHANNELCHANGE_H_

using namespace std;
#include <string>


class ActionZoneAndChannelChange {
public:
	ActionZoneAndChannelChange();
	virtual ~ActionZoneAndChannelChange();

	void setChannel(int channel) {m_nChannel = channel;};
	void setZone(int zone) {m_nZone = zone;} ;

	int getChannel(void) {return m_nChannel;};
	int getZone( void ) {return m_nZone;};

	private:
	int m_nChannel;
	int m_nZone;
};

#endif /* ACTIONZONEANDCHANNELCHANGE_H_ */
