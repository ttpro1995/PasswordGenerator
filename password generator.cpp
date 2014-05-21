/*
Password Generator
by Haha TTpro
*/

#include <iostream>
#include <fstream>
#include <time.h> 
#include <stdlib.h> 
#include "CheckCondition.h"


using namespace std;

void generator(char *A, int n, int choice);
void Generateapassword();
void menu();
void About();
int main()
{
	menu();

}

void generator(char *A, int n,int choice)
{
	int dice;
	int getornot;
	srand(time(NULL));
	for (int i = 0; i < n; i++)
	{
		
		dice = rand() % 74 + 48;
		if (choice!= 1)
		{
			if ((dice >57) && (dice < 65))
			{
				i--;
				continue;
			}
			if ((dice >90) && (dice < 97))
			{
				i--;
				continue;
			}
		}
		A[i] = dice;
	}
	A[n] = '\0';
}

void menu()
{
	int x;
	while (true)
	{
		system("cls");
		cout << "   PASSWORD GENERATOR  \n"
			<< "1. Generate a password \n"
			<< "2. About \n"
			<< "3. exit \n";
		cin >> x;

		if (x == 1)
		
			Generateapassword();
		
		else
			if (x == 3)
			{
				system("cls");
				cout << "Good bye \n\n";
				break;
			}
			else
				About();
	}
}


void About()
{
	system("cls");
	cout << "PASSWORD GENERATOR \n"
		<< "by Haha TTpro \n"
		<< endl << endl
		<< "You can use this software to create powerful password for your wifi \n"
		<< "don't use for facebook , youtube, e-mail \n \n"
		<< "Password are output in file Result.txt \n"
		<< "that you can copy easily \n\n\n";
	system("pause");
 }

void Generateapassword()
{
	system("cls");
	int n;
	cout << "How long ? \n";
	cin >> n;
	int choice;
	cout << "Do you want special character ? \n"
		<<"1. yes (a-z, A-Z,0-9, @#$%^&()_+=-`[]{},./<>?, more secure but more confuse ) \n"
		<<"0. no (a-z, A-Z,0-9) (recommended) \n";
	cin >> choice;
	char *A;//A is Pass
	A = new char[n + 1];
	generator(A, n,choice);

	CheckCondition Check;
	while (!Check.CheckIt(A))
	{
		generator(A, n, choice);
	}

	cout << "result :\n";
	cout << A << endl;
	Check.showStat();
	ofstream fout;
	fout.open("Result.txt");
	fout << "Result \n";
	fout << A << endl << endl;
	cout << "result also output in text file Result.txt in same folder \n" ;
	fout << "Thanks for using Password generator \n\n\n";
	delete[]A;
	fout.close();
	system("pause");
}