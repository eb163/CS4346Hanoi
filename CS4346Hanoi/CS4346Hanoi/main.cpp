#define TEST_UNIT_TOWER			true
#define TEST_SYS_BASIC_GAME		true
#define TEST_UNIT_GAMESTATE		true

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
#if TEST_UNIT_TOWER == true
	unitTestTower();
#endif

#if TEST_SYS_BASIC_GAME == true
	short discsToTest = 5;
	systemTestBasicGame(discsToTest);
#endif

	return 0;
}