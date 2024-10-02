#pragma once
#include <iostream>
using namespace std;
class BattleClass
{
private:
	string pName;
public:
	BattleClass(){}
	BattleClass(const string& pName);
	string GetpName()const { return pName; }
	void SetpName(const string& pN) { pName = pN; }

	void BattleRun(class PlayerClass& p, const int stagecount);
	int Fight(class PlayerClass& p, class MonsterClass& m);
	
	void MpLess();
	void ErrMessage();
};

