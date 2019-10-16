#include "Tower.h"

Tower::Tower()
{
}


Tower::~Tower()
{
}

bool Tower::isEmpty()
{
	return (size == 0);
}

short Tower::getSize()
{
	return size;
}

short Tower::peek()
{
	return discs.top();
}

short Tower::takeDisc()
{
	short d = discs.top();
	discs.pop();
	--size;
	return d;
}

bool Tower::addDisc(short d)
{
	bool result = false;
	if (d < discs.top())
	{
		discs.push(d);
		++size;
		result = true;
	}
	return true;
}


