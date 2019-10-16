#pragma once
#include <stack>
#include <string>
/*
	The Tower class is the primary interactable game element. It is a container of shorts representing discs.
	The value of the short is the "size" of the disc by which the discs must be sorted.
	Each Tower can hold discs.
	No duplicate discs may exist in a Tower.
	The tower will only accept a new disc if the sie of the disc is smaller than the current top of the disc.
*/

using std::stack;
using std::string;

class Tower
{
private:
	string name;
	short size;
	stack<short> discs;

protected:

public:
	Tower();
	~Tower();
	string getName();
	void setName(string s);
	bool isEmpty();
	short getSize();
	short peek();
	short takeDisc();
	bool addDisc(short d);
};

