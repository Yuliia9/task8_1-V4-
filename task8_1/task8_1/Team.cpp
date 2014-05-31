
/**
*@file		Team.cpp
*@brief		Implements methods for team class
*/

#include "stdafx.h"
#include "Team.h"


/**
* @brief				Constructor without parameters to set fields in class to their default values
* @param	void
*/
Team::Team(void) : score(0), isPlaying(false)
{
}


/**
* @brief				Destructor
* @param	void
*/
Team::~Team(void)
{
}


/**
* @brief				Function that defines if a team is already playing in this tour
* @param	void
* @return	bool		Returns the value of boolean field isPlaying: returns false if team isn't playing
						return true if team is playing in this tour
*/
bool Team::Plays(void) const
{
	return isPlaying;
}



/**
* @brief				Function that sets the value of boolean field isPlaying to parameter
* @param	bool		value - boolean value that defines if  team is already playing  in this tour:
								false - isn't playing, true -  is playing
* @return	void		
*/
void Team::setPlay(bool value)
{
	isPlaying = value;
}


/**
* @brief					Function for changing the score of team
* @param	unsigned int	val - value that defines how to change score
* @return	void
*/
void Team::changeScore(unsigned int val)
{
	score += val;
}


/**
* @brief				Function for getting the name of team
* @param	void		
* @return	string		Returns the name of team
*/
string Team::getName(void) const
{
	return name;
}


/**
* @brief					Function for getting the score of team
* @param	void
* @return	unsigned int	Returns the present score of team
*/
unsigned int Team::getScrore(void) const
{
	return score;
}


/**
* @brief				Function for changing the name of team
* @param	string		val - name of team
* @return	void
*/
void Team::setName(string val)
{
	name = val;
}
