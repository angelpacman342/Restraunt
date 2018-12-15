#include "pch.h"
#include <iostream>
#include <cstdlib>
#include <string>
#include "priorityCode.h"

using namespace std;

int main()
{
	priorityCode restruant;
	char answer;

	do
	{
		restruant.menu();
		do
		{
			cout << "\nDo you want to see the line? {Yy,Nn} : ";
			cin >> answer;
		}while((answer != 'Y') && (answer != 'y') && (answer != 'N') && (answer != 'n'));
		
	} while (answer == 'n' || answer == 'N');

	restruant.print();
}