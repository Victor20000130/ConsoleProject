#include "BattleClass.h"
#include "PlayerClass.h"
#include "MonsterClass.h"
#include "MainMenu.h"



BattleClass::BattleClass(const string& pName)
	: pName(pName)
{
}

void BattleClass::BattleRun(class PlayerClass& p, const int stagecount)
{

	MonsterClass* m[5];
	m[0] = new MonsterClass("고블린", 50, 3, 0, 0, 0);
	m[1] = new MonsterClass("코볼트", 70, 6, 0, 0, 0);
	m[2] = new MonsterClass("트롤", 150, 10, 0, 0, 0);
	m[3] = new MonsterClass("오우거", 180, 15, 0, 0, 0);
	m[4] = new MonsterClass("황금고블린", 80, 6, 0, 0, 0);

	if (stagecount % 10 == 0)
	{
		m[0] = new MonsterClass("분노한 고블린", 100, 10, 0, 0, 0);
		m[1] = new MonsterClass("분노한 코볼트", 150, 15, 0, 0, 0);
		m[2] = new MonsterClass("분노한 트롤", 200, 20, 0, 0, 0);
		m[3] = new MonsterClass("분노한 오우거", 250, 25, 0, 0, 0);
		m[4] = new MonsterClass("드래곤", 300, 30, 0, 0, 0);
	}

	random_device rd;
	uniform_int_distribution<int> distribution(1, 100);
	system("cls");
	if (distribution(rd) >= 1 && distribution(rd) < 30) // 고블린
	{
		uniform_int_distribution<int> money(50, 80);
		uniform_int_distribution<int> exp(5, 10);
		m[0]->SetExp(exp(rd));
		m[0]->SetMoney(money(rd));
		p.SetGoblin(p.GetGoblin() + Fight(p, *m[0]));
		return;
	}
	else if (distribution(rd) >= 30 && distribution(rd) < 50) // 코볼트
	{
		uniform_int_distribution<int> money(80, 100);
		uniform_int_distribution<int> exp(12, 15);
		m[1]->SetExp(exp(rd));
		m[1]->SetMoney(money(rd));
		p.SetCobolt(p.GetCobolt() + Fight(p, *m[1]));
		return;
	}
	else if (distribution(rd) >= 50 && distribution(rd) < 62) // 트롤
	{
		uniform_int_distribution<int> money(100, 150);
		uniform_int_distribution<int> exp(17, 22);
		m[2]->SetExp(exp(rd));
		m[2]->SetMoney(money(rd));
		p.SetTroll(p.GetTroll() + Fight(p, *m[2]));
		return;
	}
	else if (distribution(rd) >= 62 && distribution(rd) < 65) // 오우거
	{
		uniform_int_distribution<int> money(150, 200);
		uniform_int_distribution<int> exp(25, 30);
		m[3]->SetExp(exp(rd));
		m[3]->SetMoney(money(rd));
		p.SetOgre(p.GetOgre() + Fight(p, *m[3]));
		return;
	}
	else if (distribution(rd) >= 65 && distribution(rd) < 66)
	{
		uniform_int_distribution<int> money(200, 250);
		uniform_int_distribution<int> exp(30, 60);
		m[4]->SetExp(exp(rd));
		m[4]->SetMoney(money(rd));
		p.SetGoldgoblin(p.GetGoldgoblin() + Fight(p, *m[4]));
		if (stagecount % 10 == 0)
		{
			cout << "평화를 되찾았다! 승리!" << endl;
			exit(0);
		}
		return;
	}
	else
	{
		cout << "허탕이네..." << endl;
		Sleep(1500);
		return;
	}
	delete[] m;
}

int BattleClass::Fight(class PlayerClass& p, class MonsterClass& m)
{
	int input = 0;
	p.Meet(m.GetName());
	while (true)
	{
		p.DisPlay();
		m.DisPlay();
		input = p.Choice(input);
		switch (input)
		{
		case 1:
			p.Attack();
			m.TakeDamage(p.GetDamage());
			break;
		case 2:
			if (p.GetMP() < 10)
			{
				MpLess();
				break;
			}
			p.Heal();
			break;
		case 3:
			if (p.GetMP() < 10)
			{
				MpLess();
				break;
			}
			p.Slash();
			m.TakeDamage(p.GetDamage() * 1000);
			break;
		default:
			ErrMessage();
			continue;
		}

		if (m.GetHealth() <= 0)
		{
			cout << "몬스터 컷!" << endl;
			cout << m.GetExp() << "만큼의 경험치 획득!" << endl;
			cout << m.GetMoney() << "만큼의 골드 획득!" << endl;
			p.SetExp(p.GetExp() + m.GetExp());
			p.SetMoney(p.GetMoney() + m.GetMoney());
			system("pause");
			system("cls");
			if (p.GetExp() >= 100)
			{
				cout << "레벨업!" << endl;
				cout << "공격력 5 증가!" << endl;
				cout << "최대 마나 5 증가!" << endl;
				cout << "최대체력 10 증가!" << endl;
				p.SetLev(p.GetLev() + 1);
				p.SetExp(p.GetExp() - 100);
				p.SetFullHP(p.GetFullHP() + 10);
				p.SetFullMP(p.GetFullMP() + 5);
				p.SetDamage(p.GetDamage() + 5);
			}
			cout << "현재 체력 : " << p.GetHealth() << "/" << p.GetFullHP() << endl;
			cout << "기본 공격력 : " << p.GetDamage() << endl;
			cout << "현재 마나 : " << p.GetMP() << "/" << p.GetFullMP() << endl;
			cout << "현재 레벨 : " << p.GetLev() << endl;
			cout << "현재 경험치 : " << p.GetExp() << endl;
			cout << "보유 골드 : " << p.GetMoney() << endl;
			system("pause");
			system("cls");
			return 1;
		}

		random_device rd;
		uniform_int_distribution<int> distributionMonster(1, 100);
		if (distributionMonster(rd) < 50)
		{
			m.Attack();
			p.TakeDamage(m.GetDamage());
		}
		else
		{
			m.PowerUP();
			p.TakeDamage(m.GetDamage() * 1.5);
		}
		if (p.GetHealth() <= 0)
		{
			cout << "플레이어가 사망하였습니다." << endl;
			cout << "게임을 종료합니다." << endl;
			exit(0);
		}
		
	}
}


void BattleClass::ErrMessage()
{
	cout << "잘못된 입력입니다." << endl;
	system("pause");
}

void BattleClass::MpLess()
{
	cout << "MP가 부족합니다" << endl;
	Sleep(1500);
	system("cls");
}