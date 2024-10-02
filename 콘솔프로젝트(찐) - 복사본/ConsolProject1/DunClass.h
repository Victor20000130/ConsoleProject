#pragma once
#include<conio.h>
#include<Windows.h>
#include<iostream>
#include<random>
using namespace std;
class DunClass
{
private:
	int MAXARR = 625;
	int ARRLINE = 25;
	string square = "¡á";
	string player = "¡Ù";
	string dungeon = "¡Ý";
	string box1 = "¢È";
	string box2 = "¢Ç";
	string monster = "¥÷";
	string statue = "¢±";
	string* tile = new string[MAXARR];
	
public:
	DunClass(){}
	DunClass(const int maxarr, const int arrline, const string& square, const string& player, const string& dungeon, const string& box1, const string& box2, const string& monster, const string& statue, const string& tile);

	void DisPlay();
	void Obstacle();
	int Move(class DunClass& map, class PlayerClass& player);
	int MoveUp(DunClass& map);
	int MoveDown(DunClass& map);
	int MoveRight(DunClass& map);
	int MoveLeft(DunClass& map);
	void Random(const string& temp);
	void Respawn(const string& temp);
	int Stage(DunClass& map, class BattleClass& B, class PlayerClass& p, const int stagecount);
	void StoneStatue(class PlayerClass& p);
};

