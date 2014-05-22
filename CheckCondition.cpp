/*
Password Generator
by Haha TTpro
*/

#include <iostream>
using namespace std;
#include "CheckCondition.h"


::CheckCondition::CheckCondition()
{
	numofChar = 0;
	numofDigit = 0;
	lower = false;
	upper = false;
	digit = false;
	halfcharacter = false;
	word = NULL;

}

bool ::CheckCondition::IsUpper(char x)
{
	if ((x >= 'A') && (x <= 'Z')) return true;
	else return false;
}

bool ::CheckCondition::IsLower(char x)
{
	if ((x >= 'a') && (x <= 'z')) return true;
	else return false;
}

bool ::CheckCondition::IsDisgit(char x)
{
	if ((x >= '0') && (x <= '9')) return true;
	else return false;
}
bool ::CheckCondition::isCharacter(char x)
{
	if (IsUpper(x) || IsLower(x))
	{
		return true;
	}
	return false;
}

void::CheckCondition::in(char Pass[])
{
	reset();
	word = Pass;

}

bool  ::CheckCondition::process()
{
	int couting = 0;
	int tar = strlen(word) / 2;
	for (int i = 0; i < strlen(word); i++)
	{
		if (IsDisgit(word[i])) digit = true;
		if (IsUpper(word[i])) upper = true;
		if (IsLower(word[i])) lower = true;

		if (isCharacter(word[i])) couting++;
		if (couting >= tar) halfcharacter = true;

		if (digit&&upper&&lower&&halfcharacter) return true;
	}

	return false;
	


}

bool ::CheckCondition::CheckIt(char Pass[])
{
	in(Pass);
	bool x;
	x=process();
	return x;
}

void ::CheckCondition::showStat()
{
	for (int i = 0; i < strlen(word); i++)
	{
		if (IsDisgit(word[i])) numofDigit++;
		if (isCharacter(word[i])) numofChar++;
	}

	cout << "\n";
	cout << "Password Stat  \n"
		<< "Digit : " << numofDigit << endl
		<< "Character : " << numofChar << endl;
	numofChar = 0;
	numofDigit = 0;

}

::CheckCondition::~CheckCondition()
{
	numofChar = 0;
	numofDigit = 0;
	lower = false;
	upper = false;
	digit = false;
	halfcharacter = false;
		word = NULL;

}

void ::CheckCondition::reset()
{

	numofChar = 0;
	numofDigit = 0;
	lower = false;
	upper = false;
	digit = false;
	halfcharacter = false;
		word = NULL;
	

}