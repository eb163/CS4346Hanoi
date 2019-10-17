#pragma once

//TESTING PARAMETERS
#define DEBUG_FULL			false
#define DEBUG_PARTIAL		false

#include "Tower.h"
#include "display.h"
#include <iostream>

using std::cout;
using std::endl;

//tests the Tower data structure
void unitTestTower()
{
	cout << "Unit Test Tower" << endl;

	Tower t;
	t.setName("T");

	short d1 = 1, d2 = 2, d3 = 3;

	cout << "Drawing an empty Tower named T!" << endl;
	printLine();
	printTower(t);
	printLine();

	cout << "\nLoading discs 1 and 2 into T! (Order: 2, 1)" << endl;
	t.addDisc(d2);
	t.addDisc(d1);

	cout << "\nPrinting T!" << endl;
	printLine();
	printTower(t);
	printLine();

	cout << "\nAttempting to load 3 into T! (Order: 2, 1, 3)\nThis is wrong and should not work!" << endl;
	t.addDisc(d3);

	printLine();
	printTower(t);
	printLine();

	cout << "\nEmptying T!" << endl;
	int r1 = t.takeDisc();
	int r2 = t.takeDisc();
	cout << "Results: r1 = " << r1 << " | r2 = " << r2 << endl;

	printLine();
	printTower(t);
	printLine();

	cout << "\nLoading discs 3, 2, 1 into T!" << endl;
	t.addDisc(d3);
	t.addDisc(d2);
	t.addDisc(d1);

	printLine();
	printTower(t);
	printLine();

	cout << "Unit Test Tower complete!" << endl;
	pause();
}


void recursiveHanoi(int discNum, Tower& source, Tower& dest, Tower& spare, int depth, int move)
{
	++depth;
	++move;
#if DEBUG_FULL == true
	cout << "Move number: " << move << endl;
	cout << "Recursion depth: " << depth << endl;
	printGameStateCalcScores(source, spare, dest);
#elif DEBUG_PARTIAL == true
	printGameState(tA, tB, tC);
#endif
	short curDisc = 0;
	if (discNum == 1) //base case
	{
		curDisc = source.takeDisc();
		dest.addDisc(curDisc);
	}
	else
	{
		recursiveHanoi(discNum - 1, source, spare, dest, depth, move);
		curDisc = source.takeDisc();
		dest.addDisc(curDisc);
		recursiveHanoi(discNum - 1, spare, dest, source, depth, move);
	}
	--depth;
}

void recursiveHanoiStarter(Tower &a, Tower &b, Tower &c) //called on an initial game state where Tower A holds all discs
{
	int totalDiscs = a.getSize();
	recursiveHanoi(totalDiscs, a, c, b, 0, 0);
}

//tests the game system with a basic set of 3 discs and 3 towers
void systemTestBasicGame(short discTotal)
{
	cout << "\nSystem Test Basic Game (3 Towers and 3 Disks)" << endl;
	//short discTotal = 3;
	Tower tA, tB, tC;
	tA.setName("Tower A");
	tB.setName("Tower B");
	tC.setName("Tower C");
	tA.init(discTotal);
	tB.init(0);
	tC.init(0);

#if DEBUG_FULL == true
	printGameStateCalcScores(tA, tB, tC);
#else
	printGameState(tA, tB, tC);
#endif

	cout << "\nAttempting to complete a game w/ recursive solution for " << discTotal << " discs!" << endl;
	recursiveHanoiStarter(tA, tB, tC);
	cout << "Recursion complete!" << endl;

#if DEBUG_FULL == true
	printGameStateCalcScores(tA, tB, tC);
#else
	printGameState(tA, tB, tC);
#endif

	cout << "\nSystem Test Basic Game completed!" << endl;

	pause();
}