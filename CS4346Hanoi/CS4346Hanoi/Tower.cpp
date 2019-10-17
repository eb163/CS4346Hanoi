#include "Tower.h"

Tower::Tower()
{
}


Tower::~Tower()
{
}

void Tower::init(short totalDiscs) //loads discs into tower in ascending order, largest at the bottom, smallest at the top
{
	if (totalDiscs > 0)
	{
		for (int curDisc = totalDiscs; curDisc > 0; --curDisc)
		{
			this->addDisc(curDisc);
		}
	}
	else if (totalDiscs == 0)
	{
		discs.clear();
	}
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
	return discs.back();
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
	if (discs.empty() == false)
	{
		if (d < discs.back())
		{
			discs.push_back(d);
		}
	}
	else
	{
		discs.push_back(d);
	}
}


