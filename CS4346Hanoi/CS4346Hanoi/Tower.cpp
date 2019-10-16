#include "Tower.h"

Tower::Tower()
{
}


Tower::~Tower()
{
}

string Tower::getName()
{
	return name;
}

void Tower::setName(string s)
{
	name = s;
}

bool Tower::isEmpty()
{
	return (discs.size() == 0);
}

bool Tower::isValidAction(short d)
{
	bool flag = false;
	if (d < discs.back())
	{
		flag = true;
	}
	return flag;
}

short Tower::getSize()
{
	return discs.size();
}

short Tower::peek()
{
	//return discs.top();
}

short Tower::peekAt(int index)
{
	return discs.at(index);
}

short Tower::takeDisc()
{
	//short d = discs.top();
	//discs.pop();
	short d = discs.back();
	discs.pop_back();
	return d;
}

void Tower::addDisc(short d)
{
	if (d < discs.back())
	{
		discs.push_back(d);;
		result = true;
	}
}


