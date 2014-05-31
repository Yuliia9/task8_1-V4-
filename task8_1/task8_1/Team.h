
/**
*@file		Team.h
*@brief		Header file that describes class team that defines fields and methods for team in championship
*/

#ifndef TEAM_H_	
#define TEAM_H_

#include "stdafx.h"


class Team
{
public:
	/*life cycle*/
	Team(void);
	~Team(void);

	bool Plays(void) const;
	void setPlay(bool value);
	void changeScore(unsigned int val);
	unsigned int getScrore(void) const;
	string getName(void) const;
	void setName(string val);

private:
	/*fields*/
	string name;
	unsigned int score;
	bool isPlaying;
};

#endif