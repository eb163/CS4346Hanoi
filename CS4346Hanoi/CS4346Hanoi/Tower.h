#pragma once
#include <vector>
#include <string>
/*
	The Tower class is the primary interactable game element. It is a container of shorts representing discs.
	The value of the short is the "size" of the disc by which the discs must be sorted.
	Each Tower can hold discs.
	No duplicate discs may exist in a Tower.
	The tower will only accept a new disc if the sie of the disc is smaller than the current top of the disc.
*/
using std::string;
using std::vector;

class Tower
{
private:
	string name;
	vector<short> discs;

protected:

public:
	Tower();
	~Tower();
	string getName();
	void setName(string s);
	bool isEmpty();
	bool isValidAction(short d);
	short getSize();
	short peek();
	short peekAt(int index);
	short takeDisc();
	void addDisc(short d);
};

