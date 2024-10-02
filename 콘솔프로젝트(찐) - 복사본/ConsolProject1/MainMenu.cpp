#include"MainMenu.h"
#include<conio.h>
#include<Windows.h>
#include"PlayerClass.h"
#include<iomanip>
#include<iostream>
#include<stdio.h>
#include<stralign.h>
#include<stdlib.h>
#include"ItemInventory.h"
MainMenu::MainMenu(const string& name, const int choice)
	:name(name), choice(choice) {}

void CursorView(char show)
{
	HANDLE hConsole;
	CONSOLE_CURSOR_INFO ConsoleCursor;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	ConsoleCursor.bVisible = show;
	ConsoleCursor.dwSize = 1;
	SetConsoleCursorInfo(hConsole, &ConsoleCursor);
}

void gotoxy(int x, int y)
{
	COORD pos = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
void LineBox()
{
	cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
}

void ViewTemplete()
{
	LineBox();
	for (int i = 0; i < 28; i++)
	{
		puts("■\t\t\t\t\t\t\t  ■");
	}
	LineBox();
}

void MainMenu::StartMessage()
{
	while (true)
	{
		system("mode con: cols=60 lines=31");
		ViewTemplete();
		gotoxy(23, 4); cout << "모험가의 여행";
		gotoxy(20, 22); cout << "게임 시작 - 1 입력";
		gotoxy(20, 23); cout << "게임 설명 - 2 입력";
		gotoxy(20, 24); cout << "게임 종료 - 0 입력" << endl;
		
		gotoxy(28, 26); cin >> choice;
		switch (choice)
		{
		case 0:
			GameExit();
		case 1:
			system("cls");
			SetName(PlayerNameSet());
			Storymessage();
			Sleep(1500);
			system("cls");
			//여기에 던전 들어가는 모션 추가예정
			break;
		case 2:
			system("cls");
			GameInfo();
			continue;
		default:
			cout << "\t잘못된 입력입니다." << endl;
			continue;
		}
		break;
	}
	return;
}



void MainMenu::LinePrint()
{
	cout << "===========================================================" << endl;
}

void MainMenu::GameExit()
{
	while (true)
	{
		int a;
		system("cls");
		ViewTemplete();
		gotoxy(15, 10); cout << "게임을 종료하시려면 0을 입력해주세요.";
		gotoxy(18, 12); cout << "돌아가기 - 1";
		gotoxy(18, 15); cin >> a;
		system("cls");
		if (a == 0)
		{
			cout << "게임을 종료합니다." << endl;
			exit(0);
		}
		else if (a == 1)
		{
			return;
		}
		else
		{
			ErrMessage();
		}
	}
}

void MainMenu::Storymessage()
{
	gotoxy(15,14); cout << "심심한데 던전이나 들어가볼까?" << endl;
}

void MainMenu::ErrMessage()
{
	cout << "잘못된 입력입니다." << endl;
	system("pause");
}

string MainMenu::PlayerNameSet()
{
	string temp;
	while (true)
	{
		ViewTemplete();
		gotoxy(15, 5); cout << "캐릭터의 이름을 입력해주세요.";
		gotoxy(28, 8);
		cin >> temp;
		
		cin.clear();
		system("cls");
		gotoxy(15, 13); cout << "당신의 이름은 " << temp << "이(가) 맞음?" << endl;
		gotoxy(10, 15); cout << "다시 입력하기 - 1\t이름 확정하기 - 2" << endl;
		gotoxy(28, 17); cin >> choice;
		system("cls");
		if (choice == 2) { return temp; }
		else
		{
			cin.clear();
			cin.ignore(1000, '\n');
			continue;
		}
	}
}

void MainMenu::GameInfo()
{

	ViewTemplete();
	gotoxy(20, 2); cout << "게임 플레이 방법";
	gotoxy(10, 4); cout << "게임 시작 시 던전에 진입하게 됩니다.";
	gotoxy(10, 5); cout << "던전에는 몬스터와 장애물, 다음 스테이지로";
	gotoxy(10, 6); cout << "가는 입구가 있습니다.";
	gotoxy(10, 7); cout << "몬스터와 조우하게 되면";
	gotoxy(10, 8); cout << "몬스터와의 전투가 일어나게 됩니다.";
	gotoxy(10, 9); cout << "몬스터와의 전투 승리 시";
	gotoxy(10, 10); cout << "경험치와 골드를 획득합니다.";
	gotoxy(10, 11); cout << "경험치가 100에 도달하면 레벨이 오르며,";
	gotoxy(10, 12); cout << "최대 체력과 공격력, 최대 마나가 오릅니다.";
	gotoxy(10, 13); cout << "HP, MP관리를 하여 최대한 많이 돌파해보세요!";
	gotoxy(10, 15); cout << "석상에게 골드를 바쳐 회복할 수 있습니다.";
	gotoxy(10, 16); cout << "석상은 스테이지마다 랜덤으로 등장합니다.";
	gotoxy(10, 17); cout << "10스테이지 마다 몬스터가 강화됩니다.";
	gotoxy(10, 18); cout << "분노한 몬스터 중 드래곤을 처치하면 게임승리!";

	gotoxy(20, 20); cout << "☆ - 플레이어 위치";
	gotoxy(20, 21); cout << "◎ - 다음 스테이지";
	gotoxy(20, 22); cout << "▥▤ - 장애물";
	gotoxy(20, 23); cout << "ψ - 몬스터";
	gotoxy(20, 24); cout << "∮ - 신비로운 석상";
	gotoxy(10, 26); system("pause");
	system("cls");
}

void MainMenu::InDunPrint(class PlayerClass& p)
{
	ItemInventory inven;
	while (true)
	{
		gotoxy(18, 10); cout << "플레이어 정보 보기 - 1 입력" << endl;
		gotoxy(18, 11); cout << "스테이지로 이동 - 2 입력" << endl;
		gotoxy(18, 12); cout << "인벤토리 - 3 입력" << endl;
		gotoxy(18, 13);cout << "포션 상점 - 4 입력" << endl;
		gotoxy(18, 14);cout << "게임 종료 - 0" << endl;
		gotoxy(20, 16);cin >> choice;
		system("cls");
		switch (choice)
		{
		case 0:
			GameExit();
		case 1:
			PlayerInfo(p);
			cin.clear();
			continue;
		case 2:
			cout << "다음 스테이지로 이동합니다." << endl;
			system("pause");
			system("cls");
			return;
		case 3:
			inven.InventoryRun(p);
			break;
		case 4:
			p.Potionmap();
			break;
		default:
			ErrMessage();
			continue;
		}
	}
}

void MainMenu::PlayerInfo(class PlayerClass& p)
{
	int count = p.GetGoblin() + p.GetCobolt() + p.GetTroll() + p.GetOgre() + p.GetGoldgoblin();
	cout << "이름 : " << p.GetName() << endl;
	cout << "체력 : " << p.GetHealth() << "/" << p.GetFullHP() << endl;
	cout << "공격력 : " << p.GetDamage() << endl;
	cout << "방어력 : " << p.GetDefense() << endl;
	cout << "마나 : " << p.GetMP() << "/" << p.GetFullMP() << endl;
	cout << "레벨 : " << p.GetLev() << endl;
	cout << "경험치 : " << p.GetExp() << endl;
	cout << "보유골드 : " << p.GetMoney() << endl;
	LinePrint();
	cout << "고블린을 잡은 횟수 : " << p.GetGoblin() << endl;
	cout << "코볼트를 잡은 횟수 : " << p.GetCobolt() << endl;
	cout << "트롤을 잡은 횟수 : " << p.GetTroll() << endl;
	cout << "오우거를 잡은 횟수 : " << p.GetOgre() << endl;
	cout << "황금고블린을 잡은 횟수 : " << p.GetGoldgoblin() << endl;
	LinePrint();
	cout << "몬스터를 잡은 총 횟수 : " << count << endl;
	LinePrint();
	system("pause");
	system("cls");
}

