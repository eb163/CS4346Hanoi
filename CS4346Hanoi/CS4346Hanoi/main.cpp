#define TEST_UNIT_TOWER			false
#define TEST_SYS_BASIC_GAME		false
#define TEST_UNIT_GAMESTATE		false
#define TEST_SYS_GAMESTATE		false
#define TEST_UNIT_SEARCHNODE	false
#define TEST_UNIT_PRIORITYQUEUE	true
#define TEST_UNIT_SEARCHAI		true

#include <iostream>
#include "Tower.h"
#include "GameState.h"
#include "SearchNode.h"
#include "PriorityQueue.h"
#include "SearchAI.h"
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

#if TEST_UNIT_GAMESTATE == true
	unitTestGameState();
#endif

#if TEST_SYS_GAMESTATE == true
	short discsToTest = 10;
	systemTestGameState(discsToTest);
#endif

#if TEST_UNIT_SEARCHNODE == true
	unitTestSearchNode();
#endif

#if TEST_UNIT_PRIORITYQUEUE == true
	unitTestPriorityQueue();
#endif

#if TEST_UNIT_SEARCHAI == true
	unitTestSearchAI();
#endif

	return 0;
}