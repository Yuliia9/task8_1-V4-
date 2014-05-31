/**
* @file			task8_1.cpp
* @brief		Program simulates the championship of ukrainian football teams

* Copyright 2014 by Yuliia Lyubchik Inc.,
*
* This software is the confidential and proprietary information
* of Yuliia Lyubchik. ("Confidential Information").  You
* shall not disclose such Confidential Information and shall use
* it only with permission from Yuliia.
*
*/

#include "stdafx.h"
#include "championship.h"
#include "SmartPointer.h"
#include "task8_1.h"
#include <ctype.h>



extern unsigned char ERROR = 0;
extern unsigned char SUCCESS = 1;


int main( void )
{
	Championship* tournir;
	time_t timer;
	char comand;
	unsigned int n;
	char str[10];
	int count = 0;

	Interface();

	do
	{
		unsigned int retCode;

		do
		{
			cout << "Enter how many teams will take part in championship (at least 2): ";
			cin >> str;
			retCode = Is_posit_digit(str);
			if (!retCode)
			{
				puts("Please check if you entered positive digit number.");
			}
		} 
		while (!retCode);
		n = atoi(str);
		SmartPointer<Championship> t(new Championship(n));

		if (n % 2 != 0)
		{
			++n;
		}
		while (count < n - 1)
		{
			do
			{
			cout << "Enter next comand ( e - exit program, g - play next tour): ";
			cin >> comand;
			time(&timer);
			} 
			while (comand != 'e' && comand != 'g');

			if (comand == 'e')
			{
				return 0;
			}

			if (comand == 'g')
			{
				++count;
				cout << endl<< "tour " << count << " :" << endl;
				t.get()->tourney(timer);
			}
		}

		do 
		{
			cout << "There are no more games. " << "Type 'e' to exit or 'g' to start new game: ";
			cin >> comand;

			if (comand == 'e')
			{
				getchar();
				return 0;
			}

			else if (comand == 'g')
			{
				break;
			}
		} 
		while (true);
	} 
	while (true);

	return 0;
}

void Interface(void)
{
	puts("------------------------------------------------------------------------");
	puts("Welcome to the first console football championship! ");
	puts("Let the game begin!");
	puts("Program made by Yuliia Lyubchik.");
	puts("------------------------------------------------------------------------\n");
}

bool Is_posit_digit(char* str)
{
	if (str == NULL)
	{
		return ERROR;
	}
	char* psubstr;
	char key[] = "0123456789";
	psubstr = strpbrk(str, key);
	if (psubstr == NULL)
	{
		return ERROR;
	}
	int shift = 0;
	while (psubstr != NULL)
	{
		if (psubstr != (str + shift))
		{
			return ERROR;
		}
		psubstr = strpbrk(psubstr + 1, key);
		shift++;
	}
	return 1;
}
