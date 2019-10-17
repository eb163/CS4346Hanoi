#include "scoreFunctions.h"

/*

Implementations for the score function declarations in scoreFunctions.h

*/

int scoreTower(Tower t)
{
	int size = t.getSize();
	int score = 0;
	if (size > 0)
	{
		for (int index = 0; index < size; ++index)
		{
			short discVal = t.peekAt(index);
			short weight = size - index; //an ideal score will have t ordered such that (size - index) == discVal
			score += (discVal * weight);
		}
	}
	return score;
}

int scoreGameState(GameState state)
{
	//TODO
	return -1;
}