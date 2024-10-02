#pragma once
#include<iostream>
using namespace std;
class MainMenu
{
private:
	string name;
	int choice;
public:
	MainMenu(){}
	MainMenu(const string& name, const int choice);
	
	string GetName()const { return name; }
	void SetName(const string& n) { name = n; }


	void StartMessage();
	void LinePrint();
	void GameExit();
	void Storymessage();
	void ErrMessage();

	string PlayerNameSet();
	void GameInfo();
	void InDunPrint(class PlayerClass& p);
	void PlayerInfo(class PlayerClass& p);

};
