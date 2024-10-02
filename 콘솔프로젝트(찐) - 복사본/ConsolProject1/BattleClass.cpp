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
	m[0] = new MonsterClass("���", 50, 3, 0, 0, 0);
	m[1] = new MonsterClass("�ں�Ʈ", 70, 6, 0, 0, 0);
	m[2] = new MonsterClass("Ʈ��", 150, 10, 0, 0, 0);
	m[3] = new MonsterClass("�����", 180, 15, 0, 0, 0);
	m[4] = new MonsterClass("Ȳ�ݰ��", 80, 6, 0, 0, 0);

	if (stagecount % 10 == 0)
	{
		m[0] = new MonsterClass("�г��� ���", 100, 10, 0, 0, 0);
		m[1] = new MonsterClass("�г��� �ں�Ʈ", 150, 15, 0, 0, 0);
		m[2] = new MonsterClass("�г��� Ʈ��", 200, 20, 0, 0, 0);
		m[3] = new MonsterClass("�г��� �����", 250, 25, 0, 0, 0);
		m[4] = new MonsterClass("�巡��", 300, 30, 0, 0, 0);
	}

	random_device rd;
	uniform_int_distribution<int> distribution(1, 100);
	system("cls");
	if (distribution(rd) >= 1 && distribution(rd) < 30) // ���
	{
		uniform_int_distribution<int> money(50, 80);
		uniform_int_distribution<int> exp(5, 10);
		m[0]->SetExp(exp(rd));
		m[0]->SetMoney(money(rd));
		p.SetGoblin(p.GetGoblin() + Fight(p, *m[0]));
		return;
	}
	else if (distribution(rd) >= 30 && distribution(rd) < 50) // �ں�Ʈ
	{
		uniform_int_distribution<int> money(80, 100);
		uniform_int_distribution<int> exp(12, 15);
		m[1]->SetExp(exp(rd));
		m[1]->SetMoney(money(rd));
		p.SetCobolt(p.GetCobolt() + Fight(p, *m[1]));
		return;
	}
	else if (distribution(rd) >= 50 && distribution(rd) < 62) // Ʈ��
	{
		uniform_int_distribution<int> money(100, 150);
		uniform_int_distribution<int> exp(17, 22);
		m[2]->SetExp(exp(rd));
		m[2]->SetMoney(money(rd));
		p.SetTroll(p.GetTroll() + Fight(p, *m[2]));
		return;
	}
	else if (distribution(rd) >= 62 && distribution(rd) < 65) // �����
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
			cout << "��ȭ�� ��ã�Ҵ�! �¸�!" << endl;
			exit(0);
		}
		return;
	}
	else
	{
		cout << "�����̳�..." << endl;
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
			cout << "���� ��!" << endl;
			cout << m.GetExp() << "��ŭ�� ����ġ ȹ��!" << endl;
			cout << m.GetMoney() << "��ŭ�� ��� ȹ��!" << endl;
			p.SetExp(p.GetExp() + m.GetExp());
			p.SetMoney(p.GetMoney() + m.GetMoney());
			system("pause");
			system("cls");
			if (p.GetExp() >= 100)
			{
				cout << "������!" << endl;
				cout << "���ݷ� 5 ����!" << endl;
				cout << "�ִ� ���� 5 ����!" << endl;
				cout << "�ִ�ü�� 10 ����!" << endl;
				p.SetLev(p.GetLev() + 1);
				p.SetExp(p.GetExp() - 100);
				p.SetFullHP(p.GetFullHP() + 10);
				p.SetFullMP(p.GetFullMP() + 5);
				p.SetDamage(p.GetDamage() + 5);
			}
			cout << "���� ü�� : " << p.GetHealth() << "/" << p.GetFullHP() << endl;
			cout << "�⺻ ���ݷ� : " << p.GetDamage() << endl;
			cout << "���� ���� : " << p.GetMP() << "/" << p.GetFullMP() << endl;
			cout << "���� ���� : " << p.GetLev() << endl;
			cout << "���� ����ġ : " << p.GetExp() << endl;
			cout << "���� ��� : " << p.GetMoney() << endl;
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
			cout << "�÷��̾ ����Ͽ����ϴ�." << endl;
			cout << "������ �����մϴ�." << endl;
			exit(0);
		}
		
	}
}


void BattleClass::ErrMessage()
{
	cout << "�߸��� �Է��Դϴ�." << endl;
	system("pause");
}

void BattleClass::MpLess()
{
	cout << "MP�� �����մϴ�" << endl;
	Sleep(1500);
	system("cls");
}