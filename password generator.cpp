/*
Password Generator
by Haha TTpro
*/

#include <iostream>
#include <fstream>
#include <time.h>
#include <cstdlib> //for system("cls")
#include "CheckCondition.h"
#include "classRandom.h"
#include "PasswordGenerator.h"
using namespace std;



void PasswordGenerator::generator(char *A, int n)
{
	int dice;
	int dicechoice;



	Random CreateRandom;

	for (int i = 0; i < n; i++)
	{
		dicechoice = CreateRandom.random_integer(1, 3);
		if (dicechoice == 1)

			dice = CreateRandom.random_integer('A', 'Z');
		else
			if (dicechoice == 2)
				dice = CreateRandom.random_integer('a', 'z');
			else
				if (dicechoice == 3)
					dice = CreateRandom.random_integer('0', '9');



		A[i] = dice;
	}
	A[n] = '\0';
}

void PasswordGenerator::menu()
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


void PasswordGenerator::About()
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

void PasswordGenerator::Generateapassword()
{
	system("cls");
	int n;
	cout << "How long ? \n";
	cin >> n;

	char *A;//A is Pass
	A = new char[n + 1];
	generator(A, n);

	CheckCondition Check;
	while (!Check.CheckIt(A))
	{
		generator(A, n);
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

