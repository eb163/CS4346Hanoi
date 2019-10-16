#include <iostream>
#include "Tower.h"
#include "display.h"
#include "tests.h"
using std::cout;
using std::cin;

int main()
{
	///////////////////////////////////
	//TESTS
	//////////////////////////////////
	printLine('=');
	cout << "TESTS" << endl;
	printLine('=');
	unitTestTower();

	return 0;
}