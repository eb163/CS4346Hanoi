#pragma once

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

//tests the game system with a basic set of 3 discs and 3 towers
void systemTestBasicGame()
{
	cout << "\nSystem Test Basic Game (3 Towers and 3 Disks)" << endl;
	short discTotal = 3;
	Tower tA, tB, tC;
	tA.setName("Tower A");
	tB.setName("Tower B");
	tC.setName("Tower C");
	tA.init(discTotal);
	tB.init(0);
	tC.init(0);

	printGameState(tA, tB, tC);

	cout << "Testing copying Tower states with '=' operator!\n(tC = tA)" << endl;

	tC = tA;
	printGameState(tA, tB, tC);

	cout << "\nSystem Test Basic Game completed!" << endl;

	pause();
}