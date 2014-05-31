
/**
*@file		championship.h
*@brief		Header file that describes class Championship that defines fields and methods for simulating footbal championship
*/


#ifndef CHAMPIONSHIP_H_
#define CHAMPIONSHIP_H_

#include "stdafx.h"
#include "Team.h"

/*Points for victory in game*/
const unsigned int VICTORY = 3;


class Championship
{
public:
	//life cycle
	Championship(unsigned int n);
	~Championship(void);

	void tourney(time_t timer);
	void sorted_print(Team* teams, unsigned int len) const;
	string buffer(Team** pteams, unsigned int size) const;
	unsigned char output(string buffer) const;

private:
	//prohibit
	Championship(void);

	//Fields
	unsigned int number;
	Team* teams;
	bool** table;
};

#endif