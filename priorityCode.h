#pragma once
#include <iostream>
#include <cstdlib>
#include <string>
#include "priorityCode.h"

using namespace std;

class priorityCode
{
public:
	priorityCode();
	void createNode();
	void menu();
	void rearrange();
	void print();
	~priorityCode();

private:

	typedef struct node
	{
		int id;
		string menu;
		double price;
		int amount;
		node* nextInLine;
	}*ptr;

	ptr head, vip, regular;
};
