/*
Password Generator
by Haha TTpro
*/

class CheckCondition
{
private:
	bool upper;
	bool lower;
	bool digit;
	bool halfcharacter;
	char *word;

	int numofChar;
	int numofDigit;

	bool IsUpper(char x);
	bool IsLower(char x);
	bool IsDisgit(char x);
	bool isCharacter(char x);


	void in(char Pass[]);
	bool process();


public:
	CheckCondition();
	bool CheckIt(char Pass[]);

	void showStat();


};