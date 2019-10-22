#pragma once

//TESTING PARAMETERS
#define DEBUG_FULL			false
#define DEBUG_PARTIAL		false

#include "Tower.h"
#include "SearchNode.h"
#include "PriorityQueue.h"
#include "SearchAI.h"
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

	cout << "Creating a second Tower named T2!" << endl;
	Tower t2; t2.setName("T2");
	cout << "Copying discs from T to T2! (T2 should still be named T2)" << endl;
	t2.copyDiscs(t);
	printLine();
	printTower(t);
	printTower(t2);
	printLine();

	cout << "Now setting T2 = T (T2 should be exactly the same as T)" << endl;
	t2 = t;
	printLine();
	printTower(t);
	printTower(t2);
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

//confirm the basic operations of GameState work
void unitTestGameState()
{
	cout << "Unit Test GameState" << endl;
	short totalDiscs = 5;
	cout << "Initializing GameState w/" << totalDiscs << "discs...";
	GameState gstate; gstate.init(totalDiscs);
	cout << "done." << endl;
	printGameState(gstate);

	cout << "Moving top disc from Tower A to Tower C" << endl;
	gstate.move(TOWER_A, TOWER_C);

	printGameState(gstate);

	cout << "Creating an empty GameState gstate2...";
	GameState gstate2;
	cout << "Done!" << endl;
	cout << "Attempting to set gState2 = gstate...";
	gstate2 = gstate;
	cout << "Done!" << endl;

	printLine();
	cout << "gstate2 contents: " << endl;
	printGameState(gstate2);

	cout << "Unit Test GameState complete!" << endl;
	pause();
}

void recursiveHanoiGameState(GameState& gs, int discNum, TowerSelection src, TowerSelection dest, TowerSelection spare)
{
	if (discNum == 1) // base case
	{
		bool flag = gs.move(src, dest); //move top disc from src to dest
		if (flag == false)
		{
			cout << "ERROR: Invalid move attempt made!" << endl;
		}
	}
	else
	{
		recursiveHanoiGameState(gs, discNum - 1, src, spare, dest);
		bool flag = gs.move(src, dest); //move top disc from src to dest
		if (flag == false)
		{
			cout << "ERROR: Invalid move attempt made!" << endl;
		}
		recursiveHanoiGameState(gs, discNum - 1, spare, dest, src);
	}
}

void recursiveHanoiGameStateStarter(GameState& gs)
{
	int totalDiscs = gs.getTower(TOWER_A).getSize();
	recursiveHanoiGameState(gs, totalDiscs, TOWER_A, TOWER_B, TOWER_C);
}

//try to play a full game of Hanoi using the GameState construct
void systemTestGameState(short totalDiscs)
{
	cout << "System test GameState" << endl;
	cout << "Initializing GameState w/ " << totalDiscs << " discs...";
	GameState gstate; gstate.init(totalDiscs);
	cout << "done." << endl;
	printGameState(gstate);

	cout << "Attemtping to play a game of hanoi with " << totalDiscs << " discs by recursion!" << endl;
	cout << "Start Tower = A, End Tower = B" << endl;

	recursiveHanoiGameStateStarter(gstate);

	cout << "Done!" << endl;

	printGameState(gstate);

	pause();
}

void unitTestSearchNode()
{
	cout << "Unit Test Search Node" << endl;

	cout << "\nCreating an empty Search Node..";
	SearchNode n1;
	cout << " Done!" << endl;

	GameState state; state.init(3);
	cout << "Test data GameState: " << endl;
	printGameState(state);
	int g1 = 0, h1 = 10;
	cout << "\nTest data G = " << g1 << ", H = " << h1 << endl;
	cout << "\nSetting SearchNode g and h vals to test data!" << endl;
	n1.setG(g1); n1.setH(h1);
	cout << "\nSetting SearchNode to Test data GameState!" << endl;
	n1.setState(state);
	cout << "\nSearchNode contents:" << endl;
	cout << "G = " << n1.getG() << " H = " << n1.getH() << endl;
	printGameState(n1.getState());

	pause();

	cout << "Creating a child node...";
	int g2 = g1 + 1;
	int h2 = 5;
	GameState state2; state2 = state; state2.move(TOWER_A, TOWER_C);
	SearchNode n2; n2.setH(h2); n2.setG(g2); n2.setState(state2);
	cout << " Done." << endl;

	printGameState(n1.getState());
	printGameState(n2.getState());

	cout << "Unit Test Search Node complete!" << endl;
	pause();
}

void unitTestPriorityQueue()
{
	cout << "Unit Test PriorityQueue" << endl;

	//test data
	//ORDER: sn4, sn1, sn3, sn2
	int sn1G = 0, sn2G = 1, sn3G = 1, sn4G = 2;
	int sn1H = 5, sn2H = 9, sn3H = 7, sn4H = 2;
	SearchNode* sn1 = new SearchNode; sn1->setG(sn1G); sn1->setH(sn1H);
	SearchNode* sn2 = new SearchNode; sn2->setG(sn2G); sn2->setH(sn2H);
	SearchNode* sn3 = new SearchNode; sn3->setG(sn3G); sn3->setH(sn3H);
	SearchNode* sn4 = new SearchNode; sn4->setG(sn4G); sn4->setH(sn4H);

	cout << "Test data: sn1.F() = " << sn1->getF() << " sn2.F() = " << sn2->getF() << " sn3.F() = " << sn3->getF() << " sn4.F() = " << sn4->getF() << endl;

	PriorityQueue pq;
	cout << "Initial PriorityQueue size: " << pq.getSize() << endl;

	cout << "Adding SearchNodes to PriorityQueue...";
	cout << "\nAdding sn1..."; pq.add(sn1);
	cout << "\nAdding sn2..."; pq.add(sn2);
	cout << "\nAdding sn3..."; pq.add(sn3);
	cout << "\nAdding sn4..."; pq.add(sn4);
	cout << "...All done!" << endl;

	int pqSize = pq.getSize();
	cout << "PriorityQueue size: " << pqSize << endl;
	cout << "PriorityQueue contents: ";
	for (int i = 0; i < pqSize; ++i)
	{
		SearchNode* n = pq.pop();
		cout << n->getF() << " ";
	}
	cout << endl;

	cout << "Attempting to clear an empty PriorityQueue...";
	pq.clear();
	cout << "Done." << endl;

	cout << "Reloading data and attempting to clear PriorityQueue...";
	pq.add(sn1);
	pq.add(sn2);
	pq.add(sn3);
	pq.add(sn4);
	pq.clear();
	cout << "Done." << endl;

	cout << "Unit Test PriorityQueue completed!" << endl;
	pause();
}

void unitTestSearchAI()
{
	cout << "Unit Test SearchAI" << endl;

	SearchAI sai;

	GameState gs1; gs1.init(3);
	GameState gs2 = gs1;
	GameState gs3 = gs1; gs3.move(TowerSelection::TOWER_A, TowerSelection::TOWER_C);
	GameState gsOther; gsOther.init(1);

	SearchNode* sn1 = new SearchNode; sn1->setState(gs1); sn1->setH(scoreGameState(gs1)); sn1->setG(0);
	SearchNode* sn2 = new SearchNode; sn2->setState(gs2); sn2->setH(scoreGameState(gs2)); sn2->setG(0);
	SearchNode* sn3 = new SearchNode; sn3->setState(gs3); sn3->setH(scoreGameState(gs3)); sn3->setG(1);
	SearchNode* snOther = new SearchNode; snOther->setState(gsOther); snOther->setH(scoreGameState(gsOther)); snOther->setG(0);

	cout << "Game State 1:" << endl;
	printGameState(gs1);

	cout << "\nGameState 2:" << endl;
	printGameState(gs2);

	cout << "\nGame State 3: " << endl;
	printGameState(gs3);

	bool res1 = sai.compareNode(sn1, sn2);
	bool res2 = sai.compareNode(sn1, sn3);

	cout << "Comparing SearchNode1(GameState1) to SearchNode2(GameState2). Result: " << res1 << endl;
	cout << "Comparing SearchNode1(GameState1) to SearchNode3(GameState3). Result: " << res2 << endl;

	cout << "Adding SearchNode1 to SearchAI.openNodes list...";
	sai.addNodeToOpen(sn1);
	cout << "Done. \nCalling SearchAI.isOpen(SearchNode1). Result: " << sai.isOpen(sn1) << endl;

	cout << "Adding SearchNode3 to SearchAI.closedNodes list...";
	sai.addNodeToClosed(sn3);
	cout << "Done. \nCalling SearchAI.isClosed(SearchNode3). Result: " << sai.isClosed(sn3) << endl;

	cout << "\nSearching open and closed for a SearchNode that is not in either list..." << endl;
	cout << "Open result: " << sai.isOpen(snOther) << endl;
	cout << "Closed result: " << sai.isClosed(snOther) << endl;

	pause();

	cout << "Generating a set of possible moves from an initial GameState" << endl;
	cout << "Initial GameState:" << endl;
	printGameState(sn1->getState());

	vector<SearchNode*> moves = sai.generateMoves(sn1);

	printMoves(moves);

	cout << "Attempting to clear SearchAI...";
	sai.clear();
	cout << "Done." << endl;

	cout << "Attempting to clear an already cleared SearchAI...";
	sai.clear();
	cout << "Done." << endl;

	//clean up move ptrs to avoid memory leak
	if (moves.empty() == false)
	{
		int mvSize = moves.size();
		for (int i = 0; i < mvSize; ++i)
		{
			SearchNode* curptr = moves.at(i);
			if (curptr != nullptr) { delete curptr; }
		}
		moves.clear();
	}

	cout << "Unit Test SearchAI completed!" << endl;
	pause();
}