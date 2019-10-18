#pragma once
#include <iostream>
#include "Tower.h"
#include "scoreFunctions.h"

/*

Various methods for printing game data to the screen

*/

using std::cout;
using std::endl;
using std::cin;

void pause()
{
	char ch;
	cout << "Paused! Press any key to continue." << endl;
	cin >> ch;
}

void printTower(Tower t, int score = -1)
{
	cout << t.getName();
	if (score != -1)
	{
		cout << "(" << score << ")";
	}
	cout << " : ";
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
	cout << string(totalChar, ch) << endl;
}

void printGameState(Tower a, Tower b, Tower c)
{
	printLine();
	printTower(a);
	printTower(b);
	printTower(c);
	printLine();
}

void printGameStateCalcScores(Tower a, Tower b, Tower c) //use the score function to generate scores and print on screen
{
	int aScore = scoreTower(a);
	int bScore = scoreTower(b);
	int cScore = scoreTower(c);
	printLine();
	printTower(a, aScore);
	printTower(b, bScore);
	printTower(c, cScore);
	printLine();
}

void printGameStateWScores(Tower a, int aScore, Tower b, int bScore, Tower c, int cScore)
{//print Towers with already generated scores (to use with AI)

	//TODO
	cout << "ERROR: printGameWScores() is not defined yet!" << endl;
}

void printGameState(GameState gs)
{
	printLine();
	printTower(gs.getTower(TowerSelection::TOWER_A));
	printTower(gs.getTower(TowerSelection::TOWER_B));
	printTower(gs.getTower(TowerSelection::TOWER_C));
	printLine();
}