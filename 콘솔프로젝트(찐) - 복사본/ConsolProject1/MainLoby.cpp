#include"MainMenu.h"//menu
#include"DunClass.h"//map
#include"BattleClass.h"//player&monster
#include"PlayerClass.h"
#include"MonsterClass.h"
#include"ItemInventory.h"


int main() {
	MainMenu M;
	BattleClass B;
	string pName;
	PlayerClass* p = new PlayerClass({}, 100, 10, 50, 0, 100, 50, 1, 0, 1000, 0, 0, 0, 0, 0, 0, 0);
	int StageCount = 1;	

	M.StartMessage();
	p->SetName(M.GetName());
	

	while (true)
	{
	DunClass D;
	M.InDunPrint(*p);
	cout << "제 '" << StageCount << "' 스테이지" << endl;
	Sleep(1500);
	system("cls");
	D.Stage(D, B, *p, StageCount);
	system("cls");
	StageCount++;
	}

}

