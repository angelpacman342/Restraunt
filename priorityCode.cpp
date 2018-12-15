#include "pch.h"
#include <iostream>
#include <cstdlib>
#include <string>
#include <iomanip>
#include "priorityCode.h"

using namespace std;

priorityCode::priorityCode()//constructor
{
	head = NULL;
	vip = NULL;
	regular = NULL;
}

void priorityCode::menu()
{
	int order;
	bool flag;
	ptr temp = NULL;
	ptr newNode = new node;
	newNode->nextInLine = NULL;

	system("cls");

	cout << "Menu:\n";//menu items
	cout << left << setw(20) << "1 - Hamburger" << "4.50$\n";
	cout << left << setw(20) << "2 - Bacon & Eggs" << "3.50$\n";
	cout << left << setw(20) << "3 - French Fries" << "2.00$\n";
	cout << left << setw(20) << "4 - Tuna Sandwich" << "5.20$\n";

	do
	{
		do
		{
			cout << "\nId Number : ";//id number must from 1 - 9999
			cin >> newNode->id;

			flag = cin.fail();  //and makes sure its only intergers
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');//and if theres an error of integer or of id number the question will
		} while (flag == true);                                 //be asked again until there is no errors
	} while (newNode->id < 1 || newNode->id > 9999);

	do
	{
		do
		{
			cout << "\nOrder : ";//store your order
			cin >> order;

			flag = cin.fail();  //and makes sure its only intergers and the order number exist
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');//and if theres an error of integer the question will be asked until
		} while (flag == true);                                 //theres no error
	} while (order > 4 || order < 1);


	do
	{
		cout << "\nAmount : ";//stores the amount of food you want
		cin >> newNode->amount;

		flag = cin.fail();  //and makes sure its only intergers and the order number exist
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');//and if theres an error of integer the question will be asked until
	} while (flag == true);                                 //theres no error

	if (order == 1)//stores the info in the node
	{
		newNode->menu = "Hamburger";
		newNode->price = 4.50 * newNode->amount;
	}
	else if (order == 2)
	{
		newNode->menu = "Bacon & Eggs";
		newNode->price = 3.50 * newNode->amount;
	}
	else if (order == 3)
	{
		newNode->menu = "French Fries";
		newNode->price = 2.00 * newNode->amount;
	}
	else
	{
		newNode->menu = "Tuna Sandwich";
		newNode->price = 5.20 * newNode->amount;
	}

//rearanges the line 
//vips go before the regular clients (id numbers from 1 - 500 are considered vip)

	if (head == NULL)//checks if a line exist
	{
		head = newNode;
		vip = head;
		regular = newNode;
	}
	else//a line exist
	{
		if (newNode->id >= 500)//adds regular clients to the back of the line
		{
			regular->nextInLine = newNode;
			regular = newNode;
		}
		else//vip member
		{
			if (vip == head && newNode->id > 500)//when the line has regular clients and 
			{                                    //a vip member arrives we move the vip member 
				head = newNode;                  //to the front of the line because he/she has priority over the rest.
				head->nextInLine = vip;
				vip = head;
			}
			else                                 //when the line contains regular and vip member and a vip member arrrives
			{                                    //the vip member gets to move ahead of the line but must be
				temp = vip->nextInLine;          //behind the last vip member.
				newNode->nextInLine = temp;
				vip->nextInLine = newNode;
				vip = newNode;
				if (vip->nextInLine == NULL)
					regular = vip;
			}
		}
	}
}


void priorityCode::print()//prints the line
{
	int i = 0;
	ptr current = NULL;
	current = head;

	while (current != NULL)
	{
		cout << endl;
		cout << left << ++i << " Order : \n\n" << setw(16) << current->menu << "Id Number : " << current->id;
		
		if (current->id <= 500)
			cout << "    Vip Member" << endl;
		else
			cout << "    Regular Member" << endl;

		cout << showpoint << setprecision(4);
		cout << "Amount : " << current->amount << "\nPrice : " << current->price << "$" << endl;
		current = current->nextInLine;
		
		for (int i = 0; i < 25; i++) 
			cout << "-";//creates division -------
		cout << endl;
	}
}

priorityCode::~priorityCode()//deconstructor
{

}