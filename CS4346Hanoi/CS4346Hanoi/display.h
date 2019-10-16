#pragma once
#include <iostream>
#include "Tower.h"

/*

Various methods for printing game data to the screen

*/

using std::cout;
using std::endl;

void printTower(Tower t)
{
	cout << t.getName() << ": ";
	const int size = t.getSize();
	if (size > 0)
	{
		for (int i = 0; i < size; ++i)
		{
			cout << t.peekAt(i) << " ";
		}
	}
	else
	{
		cout << "empty!";
	}
	cout << endl;
}

void printLine(char ch = '-', int totalChar = 80)
{
	cout << string(ch, totalChar) << endl;
}