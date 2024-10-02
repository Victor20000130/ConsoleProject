#pragma once
#include<string>
using namespace std;
class Item
{
private:
	string name;
	string type;
	int attack;
	int defense;

	bool equipped;
public:
	Item(const string& name, const string type, int attack, int defense);

	string GetName()const { return name; }
	string GetType()const { return type; }
	int GetAttack()const { return attack; }
	int GetDefense()const { return defense; }

	bool isEquipped()const { return equipped; }
	void SetEquipped(bool value) { equipped = value; }
};

