
/**
*@file		championship.cpp
*@brief		Implements methods for championship class that defines fields and methods for simulating footbal championship
*/

#include "stdafx.h"
#include "championship.h"
#include "TeamsNames.h"
using namespace std;


unsigned int objsize = 40;
extern unsigned char SUCCESS;
extern unsigned char ERROR;

/**
* @brief			Constructor without parameters to set fields in class to their default values
* @param	void
*/
Championship::Championship(void) : teams(NULL), table(NULL)
{
}


/**
* @brief					Constructor for creating an array of teams which will be playing in championship
* @param	unsigned int	n - the number of teams in championship
*/
Championship::Championship(unsigned int n) : number(n)
{
	teams = new Team[n];
	table = new bool*[n];
	for (unsigned int i = 0; i < n; ++i)
	{
		table[i] = new bool[n];
		for (unsigned int j = 0; j < n; ++j)
		{
			table[i][j] = false;
		}
	}
	unsigned int count = clubs->length();
	unsigned int i, j, index = 0;
	for (i = 0, j = 0; i < n; ++i, ++j)
	{
		if (j == count)
		{
			j = 0;
		}
		teams[i].setName(clubs[j]);
	}
}


/**
* @brief				Destructor for release memory
* @param	void
*/
Championship::~Championship()
{
	if (teams != NULL)
	{
		delete[] teams;
	}
	if (table != NULL)
	{
		delete[] table;
	}
}



/*
* @brief					Function for playing tourney (creating games and choosing winner)
* @param	[in]			time_t timer - time when the game starts
*
*@return	void
*/
void Championship::tourney(time_t timer)
{
		unsigned int seconds;
		seconds = difftime(timer, 0);

		string results;
		results.reserve(objsize * (number / 2));

		for (unsigned int i = 0; i < number; ++i)
		{
			if (teams[i].Plays())
			{
				continue;
			}
			for (unsigned int j = i + 1; j < number; ++j)
			{
				if (j == i || table[i][j] || teams[j].Plays())
				{
					continue;
				}
				else 
				{
					cout << "Players: " << teams[i].getName() << " and " << teams[j].getName() << endl;
					results.append("\ntour : \nPlayers: ");
					results.append(teams[i].getName());
					results.append("  ");
					results.append(teams[j].getName());
					results.append("\nWinner: ");

					teams[i].setPlay(true);
					teams[j].setPlay(true);
					table[i][j] = true;
					
					if (seconds % 2 == 0)
					{
						cout << "Winner -  " << teams[i].getName() << "\n" << "\n";
						teams[i].changeScore(VICTORY);
						results.append(teams[i].getName());
					}
					else
					{
						cout << "Winner -  " << teams[j].getName() << "\n" << "\n";
						teams[j].changeScore(VICTORY);
						results.append(teams[j].getName());
					}
					break;
 				}

			}
		}
		for (unsigned int i = 0; i < number; ++i)
		{
			teams[i].setPlay(false);
		}

		unsigned int retCode;
		retCode = output(results);
		if (retCode == ERROR)
		{
			cout << "Error occurs while trying to write information into file";
		}
		sorted_print(teams, number);
}


/*
* @brief					Function for sorting teams in table and print tournament table on the screen
* @param	[in]			Team* teams - pointers to list of teams
*			[in]			unsigned int len - the number of teams in tourney
*
*@return	void
*/
void Championship::sorted_print(Team* teams, unsigned int len) const
{
	if (teams == NULL)
	{
		return;
	}
	Team** temp = (Team**)malloc(sizeof(Team*)*len);
	Team* max = (Team*)malloc(sizeof(Team));
	unsigned int i, j;
	cout << endl << "\t\tTournament table " << endl<<endl;
	for (i = 0; i < len; ++i)
	{
		temp[i] = &teams[i];
	}

	for (i = 0; i < len; ++i)
	{
		for (j = i + 1; j < len; ++j)
		{
			if (temp[j]->getScrore() > temp[i]->getScrore())
			{
				max = temp[i];
				temp[i] = temp[j];
				temp[j] = max;
				break;
			}
		}
		cout << i + 1 << " place \t" << temp[i]->getName() << "\t";
		cout <<"\t"<< temp[i]->getScrore();
		cout << endl;
	}
	cout << endl;
	string results;
	results = buffer(temp, number);
	if (results != "0")
	{
		unsigned int retCode;
		retCode = output(results);
		if (retCode == ERROR)
		{
			cout << "Error occurs while trying to write information into file";
		}
	}
	free(temp);
	
}



/*
* @brief					Function for creating string with sorted tournament table
* @param	[in]			Team** pteams - pointers to sorted list of teams 
*			[in]			unsigned int size - the number of teams in tourney
*
*@return	string			Return NULL if pointers to teams are null pointers
							Return created string 
*/
string Championship::buffer(Team** pteams, unsigned int size) const
{
	if (teams == NULL)
	{
		return NULL;
	}
	string results;
	results.reserve(objsize * size);
	results.append("\n\n\tTournament table \n");
	for (unsigned int i = 0; i < size; ++i)
	{
		results.append(teams[i].getName());
		results.append("  - score: ");
		char temp[5];
		_itoa_s(teams[i].getScrore(), temp, 10);
		results.append(temp);
		results.append("\n");
	}
	return results;
}




/*
* @brief					Function for writing information into txt file
* @param	[in]			string buffer - string for writing
*
*@return	unsigned char	Return ERROR if error occurs while trying to open file 
							Return SUCCESS if string was writed into file
*/
unsigned char Championship::output(string buffer) const
{
	ofstream pfile;
	pfile.open("myfile.txt", ios::app);
	if (pfile.is_open())
	{
		pfile << buffer;
	}
	else
	{
		pfile.close();
		return ERROR;
	}
	pfile.close();
	return SUCCESS;
}


