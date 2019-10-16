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
	for (int i = 0; i < size; ++i)
	{
		cout << t.peekAt(i) << " ";
	}
	cout << endl;
}