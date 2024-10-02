#include "DunClass.h"
#include "BattleClass.h"
#include "PlayerClass.h"
#include "ItemInventory.h"
#include "Color.h"
DunClass::DunClass(const int maxarr, const int arrline, const string& square, const string& player, const string& dungeon, const string& box1, const string& box2, const string& monster, const string& statue, const string& tile)
	:MAXARR(maxarr), ARRLINE(arrline), square(square), player(player), dungeon(dungeon), box1(box1), box2(box2), monster(monster), statue(statue), tile() {}

void DunClass::DisPlay()
{
	for (int i = 0; i < 2; i++)
	{
		cout << endl;
	}
	cout.width(7);
	for (int i = 0; i < MAXARR; i++)
	{
		random_device rd;
		uniform_int_distribution<int> distribution(1, 4);
		if (tile[i] == monster && tile[i - (ARRLINE)] == square && distribution(rd) == 1)
		{
			tile[i] = square;
			tile[i - ARRLINE] = monster;
		}
			else if (tile[i] == monster && tile[i + (ARRLINE)] == square && distribution(rd) == 2)
		{
			tile[i] = square;
			tile[i + ARRLINE] = monster;
		}
		else if (tile[i] == monster && tile[i - 1] == square && distribution(rd) == 3)
		{
			tile[i] = square;
			tile[i - 1] = monster;
		}
		else if (tile[i] == monster && tile[i + 1 ] == square && distribution(rd) == 4)
		{
			tile[i] = square;
			tile[i + 1] = monster;
		}
	}	
	for (int i = 0; i < MAXARR; i++)
	{
		if (tile[i] == square)
		{
			SetColor(8);
		}
		else if (tile[i] == monster)
		{
			SetColor(4);
		}
		else if (tile[i] == box1 || tile[i] == box2)
		{
			SetColor(6);
		}
		else if (tile[i] == player)
		{
			SetColor(10);
		}
		else if (tile[i] == dungeon)
		{
			SetColor(13);
		}
		else if (tile[i] == statue)
		{
			SetColor(11);
		}
		cout << tile[i];
		SetColor(15);
		if ((i + 1) % ARRLINE == 0)
		{
			cout << endl;
			cout.width(7);
		}
	}
	cout << "�κ��丮 - 1 �Է�" << endl;
	cout << "����â - 2 �Է�";

}
void DunClass::Obstacle()
{
	for (int i = 0; i < MAXARR; i++)
	{
		tile[i] = square;
	}
	Random(box1);
	Random(monster);
	Random(box2);
	Random(square);
	Respawn(statue);
	for (int i = 0; i < MAXARR; i++)
	{
		if (i + ARRLINE > MAXARR)
		{
			break;
		}
		if (tile[i] == box1 || tile[i] == box2 && tile[i + ARRLINE + 1] == box1 || tile[i + ARRLINE + 1] == box2)
		{
			tile[i] = square;
		}
		else if (tile[i] == box1 || tile[i] == box2 && tile[i + ARRLINE - 1] == box1 || tile[i + ARRLINE - 1] == box2)
		{
			tile[i] = square;
		}
	}
	Respawn(player);
	Respawn(dungeon);
	for (int i = 0; i < MAXARR; i++)
	{
		if (tile[i] == player || tile[i] == dungeon)
		{
			if (i - ARRLINE > 0)
			{
				tile[i - ARRLINE] = square;
			}
			if (i > 0)
			{
				tile[i - 1] = square;
			}
			if (i + ARRLINE < MAXARR)
			{
				tile[i + ARRLINE] = square;
			}
			if (i < MAXARR - 1)
			{
				tile[i + 1] = square;
			}
		}
	}

}
void DunClass::Random(const string& temp)
{
	random_device rd;
	uniform_int_distribution<int> distribution(0, MAXARR - 1);
	int dest, sour;
	for (int i = 0; i < 500; i++)
	{
		dest = distribution(rd);
		sour = distribution(rd);

		tile[dest] = tile[sour];
		tile[sour] = temp;
	}

}
void DunClass::Respawn(const string& temp)
{
	random_device rd;
	uniform_int_distribution<int> distribution(0, MAXARR - 1);
	int dest, sour;
	dest = distribution(rd);
	sour = distribution(rd);
	tile[dest] = tile[sour];
	tile[sour] = temp;
}


int DunClass::Stage(DunClass& map,class BattleClass& B, class PlayerClass& p, const int stagecount)
{
	
	int temp;
	int count = 0;
	Obstacle();
	while (true)
	{
		system("cls");
		map.DisPlay();
		temp = map.Move(map, p);
		switch (temp)
		{
		case 1:
			return count;
		case 2:
			system("cls");
			cout << "���Ϳ� ����Ʈ!" << endl;
			Sleep(1500);
			B.BattleRun(p, stagecount);
			continue;
		case 3:
			system("cls");
			cout << "����� �ź�ο� ����� �������� ������ ã�Ҵ�...!" << endl;
			Sleep(1500);
			map.StoneStatue(p);
		}
	}
	delete[] tile;
}

void DunClass::StoneStatue(class PlayerClass& player)
{
	while (true)
	{
	int choice;
	int money;
	cout << "���󿡰� ������ ��ġ�ڽ��ϱ�?" << endl;
	cout << "��ģ�� - 1 �Է�" << endl;
	cout << "���ư��� - 2 �Է�" << endl;
	cin >> choice;
	if (choice == 2)
	{
		return;
	}
	else if (choice == 1)
	{
		cout << "���� ��� : " << player.GetMoney() << endl;
		cout << "�󸶸� ��ġ�ڽ��ϱ�?" << endl;
		cout << "���ư��� - 0" << endl;
		cin >> money;
		if (money == 0)
		{
			return;
		}
		if (money < 100)
		{
			system("cls");
			cout << "...." << endl;
			Sleep(1000);
			system("cls");
			cout << "������ �����Ѱ�..?" << endl;
			Sleep(1000);
			system("cls");
			continue;
		}
		if (money > player.GetMoney())
		{
			cout << "���� �����ϴ�..." << endl;
			cin.clear(money);
			Sleep(1000);
			system("cls");
			continue;
		}
		else if (money < player.GetMoney())
		{
			player.SetMoney(player.GetMoney() - money);
			player.SetHealth(player.GetHealth() + (money / 100));
			if (player.GetHealth() > player.GetFullHP())
			{
				player.SetHealth(player.GetFullHP());
			}
			player.SetMP(player.GetMP() + (money / 100));
			if (player.GetMP() > player.GetFullMP())
			{
				player.SetMP(player.GetFullMP());
			}
			cout << "ü���� " << money / 100 << "��ŭ ȸ���Ǿ���." << endl;
			cout << "������ " << money / 100 << "��ŭ ȸ���Ǿ���." << endl;
			system("pause");
			system("cls");
			return;
		}
		else
		{
			cout << "...�ƹ� ������ ����" << endl;
			cin.clear();
			Sleep(1000);
			system("cls");
			continue;
		}
	}
	else
	{
		cout << "�ٽ� �������ּ���" << endl;
		Sleep(1000);
		system("cls");
		continue;
	}
	}
}



int DunClass::Move(class DunClass& map,class PlayerClass& player)
{
	ItemInventory Ii;
	int input = _getch();
	if (input == 49)
	{
		system("cls");
		Ii.InventoryRun(player);
	}
	else if(input == 50)
	{
		system("cls");
		player.DisPlay();
		system("pause");
		system("cls");
	}
	if (input == 224)
	{
		input = _getch();
	}
		switch (input)
		{
		case 72://��
			input = map.MoveUp(map);
			break;
		case 80://�Ʒ�
			input = map.MoveDown(map);
			break;
		case 75://����
			input = map.MoveLeft(map);
			break;
		case 77://������
			input = map.MoveRight(map);
			break;
		default:
			break;
		}
		return input;
}

int DunClass::MoveUp(DunClass& map)
{
	string temp;
	for (int i = 0; i < MAXARR; i++)
	{
		if (tile[i] == player && i - ARRLINE >= 0)
		{
			if (tile[i - ARRLINE] == box1 || tile[i - ARRLINE] == box2)
			{
				continue;
			}
			temp = tile[i - ARRLINE];
			tile[i] = square;
			tile[i - ARRLINE] = player;
			break;
		}
	}
	if (temp == dungeon)
	{
		delete[] tile;
		return 1;
	}
	else if (temp == monster)
	{
		return 2;
	}
	else if (temp == statue)
	{
		return 3;
	}
	return 0;
}

int DunClass::MoveDown(DunClass& map)
{
	string temp;
	for (int i = 0; i < MAXARR; i++)
	{
		if (tile[i] == player && i + ARRLINE <= (MAXARR - 1))
		{
			if (tile[i + ARRLINE] == box1 || tile[i + ARRLINE] == box2)
			{
				continue;
			}
			temp = tile[i + ARRLINE];
			tile[i] = square;
			tile[i + ARRLINE] = player;
			break;
		}
	}
	if (temp == dungeon)
	{
		delete[] tile;
		return 1;
	}
	else if (temp == monster)
	{
		return 2;
	}
	else if (temp == statue)
	{
		return 3;
	}
	return 0;
}

int DunClass::MoveRight(DunClass& map)
{
	string temp;
	for (int i = 0; i < MAXARR; i++)
	{
		if (tile[i] == player && i % ARRLINE != ARRLINE - 1)
		{
			if (tile[i + 1] == box1 || tile[i + 1] == box2)
			{
				continue;
			}
			temp = tile[i + 1];
			tile[i] = square;
			tile[i + 1] = player;
			break;
		}
	}
	if (temp == dungeon)
	{
		delete[] tile;
		return 1;
	}
	else if (temp == monster)
	{
		return 2;
	}
	else if (temp == statue)
	{
		return 3;
	}
	return 0;
}

int DunClass::MoveLeft(DunClass& map)
{
	string temp;
	for (int i = 0; i < MAXARR; i++)
	{
		if (tile[i] == player && i % ARRLINE != 0)
		{
			if (tile[i - 1] == box1 || tile[i - 1] == box2)
			{
				continue;
			}
			temp = tile[i - 1];
			tile[i] = square;
			tile[i - 1] = player;
			break;
		}
	} 
	if (temp == dungeon)
	{
		delete[] tile;
		return 1;
	}
	else if (temp == monster)
	{
		return 2;
	}
	else if (temp == statue)
	{
		return 3;
	}
	return 0;
}


