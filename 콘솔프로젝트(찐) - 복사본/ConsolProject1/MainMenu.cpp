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
	cout << "�������������������������������" << endl;
}

void ViewTemplete()
{
	LineBox();
	for (int i = 0; i < 28; i++)
	{
		puts("��\t\t\t\t\t\t\t  ��");
	}
	LineBox();
}

void MainMenu::StartMessage()
{
	while (true)
	{
		system("mode con: cols=60 lines=31");
		ViewTemplete();
		gotoxy(23, 4); cout << "���谡�� ����";
		gotoxy(20, 22); cout << "���� ���� - 1 �Է�";
		gotoxy(20, 23); cout << "���� ���� - 2 �Է�";
		gotoxy(20, 24); cout << "���� ���� - 0 �Է�" << endl;
		
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
			//���⿡ ���� ���� ��� �߰�����
			break;
		case 2:
			system("cls");
			GameInfo();
			continue;
		default:
			cout << "\t�߸��� �Է��Դϴ�." << endl;
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
		gotoxy(15, 10); cout << "������ �����Ͻ÷��� 0�� �Է����ּ���.";
		gotoxy(18, 12); cout << "���ư��� - 1";
		gotoxy(18, 15); cin >> a;
		system("cls");
		if (a == 0)
		{
			cout << "������ �����մϴ�." << endl;
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
	gotoxy(15,14); cout << "�ɽ��ѵ� �����̳� ������?" << endl;
}

void MainMenu::ErrMessage()
{
	cout << "�߸��� �Է��Դϴ�." << endl;
	system("pause");
}

string MainMenu::PlayerNameSet()
{
	string temp;
	while (true)
	{
		ViewTemplete();
		gotoxy(15, 5); cout << "ĳ������ �̸��� �Է����ּ���.";
		gotoxy(28, 8);
		cin >> temp;
		
		cin.clear();
		system("cls");
		gotoxy(15, 13); cout << "����� �̸��� " << temp << "��(��) ����?" << endl;
		gotoxy(10, 15); cout << "�ٽ� �Է��ϱ� - 1\t�̸� Ȯ���ϱ� - 2" << endl;
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
	gotoxy(20, 2); cout << "���� �÷��� ���";
	gotoxy(10, 4); cout << "���� ���� �� ������ �����ϰ� �˴ϴ�.";
	gotoxy(10, 5); cout << "�������� ���Ϳ� ��ֹ�, ���� ����������";
	gotoxy(10, 6); cout << "���� �Ա��� �ֽ��ϴ�.";
	gotoxy(10, 7); cout << "���Ϳ� �����ϰ� �Ǹ�";
	gotoxy(10, 8); cout << "���Ϳ��� ������ �Ͼ�� �˴ϴ�.";
	gotoxy(10, 9); cout << "���Ϳ��� ���� �¸� ��";
	gotoxy(10, 10); cout << "����ġ�� ��带 ȹ���մϴ�.";
	gotoxy(10, 11); cout << "����ġ�� 100�� �����ϸ� ������ ������,";
	gotoxy(10, 12); cout << "�ִ� ü�°� ���ݷ�, �ִ� ������ �����ϴ�.";
	gotoxy(10, 13); cout << "HP, MP������ �Ͽ� �ִ��� ���� �����غ�����!";
	gotoxy(10, 15); cout << "���󿡰� ��带 ���� ȸ���� �� �ֽ��ϴ�.";
	gotoxy(10, 16); cout << "������ ������������ �������� �����մϴ�.";
	gotoxy(10, 17); cout << "10�������� ���� ���Ͱ� ��ȭ�˴ϴ�.";
	gotoxy(10, 18); cout << "�г��� ���� �� �巡���� óġ�ϸ� ���ӽ¸�!";

	gotoxy(20, 20); cout << "�� - �÷��̾� ��ġ";
	gotoxy(20, 21); cout << "�� - ���� ��������";
	gotoxy(20, 22); cout << "�Ȣ� - ��ֹ�";
	gotoxy(20, 23); cout << "�� - ����";
	gotoxy(20, 24); cout << "�� - �ź�ο� ����";
	gotoxy(10, 26); system("pause");
	system("cls");
}

void MainMenu::InDunPrint(class PlayerClass& p)
{
	ItemInventory inven;
	while (true)
	{
		gotoxy(18, 10); cout << "�÷��̾� ���� ���� - 1 �Է�" << endl;
		gotoxy(18, 11); cout << "���������� �̵� - 2 �Է�" << endl;
		gotoxy(18, 12); cout << "�κ��丮 - 3 �Է�" << endl;
		gotoxy(18, 13);cout << "���� ���� - 4 �Է�" << endl;
		gotoxy(18, 14);cout << "���� ���� - 0" << endl;
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
			cout << "���� ���������� �̵��մϴ�." << endl;
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
	cout << "�̸� : " << p.GetName() << endl;
	cout << "ü�� : " << p.GetHealth() << "/" << p.GetFullHP() << endl;
	cout << "���ݷ� : " << p.GetDamage() << endl;
	cout << "���� : " << p.GetDefense() << endl;
	cout << "���� : " << p.GetMP() << "/" << p.GetFullMP() << endl;
	cout << "���� : " << p.GetLev() << endl;
	cout << "����ġ : " << p.GetExp() << endl;
	cout << "������� : " << p.GetMoney() << endl;
	LinePrint();
	cout << "����� ���� Ƚ�� : " << p.GetGoblin() << endl;
	cout << "�ں�Ʈ�� ���� Ƚ�� : " << p.GetCobolt() << endl;
	cout << "Ʈ���� ���� Ƚ�� : " << p.GetTroll() << endl;
	cout << "����Ÿ� ���� Ƚ�� : " << p.GetOgre() << endl;
	cout << "Ȳ�ݰ���� ���� Ƚ�� : " << p.GetGoldgoblin() << endl;
	LinePrint();
	cout << "���͸� ���� �� Ƚ�� : " << count << endl;
	LinePrint();
	system("pause");
	system("cls");
}

