#include "PlayerClass.h"
#include "Item.h"
#include<vector>
using namespace std;
PlayerClass::PlayerClass(const string& name, const int health, const int damage, const int mp, const float defense, const int FullHP, const int FullMP, const int level, const int exp, const int money, const int goblin, const int cobolt, const int troll, const int ogre, const int goldgoblin, const int h_potion, const int m_potion)
	:ConsolCharacter(name, health, damage, mp), defense(defense), FullHP(FullHP), FullMP(FullMP), level(level), exp(exp), money(money), goblin(goblin), cobolt(cobolt), troll(troll), ogre(ogre), goldgoblin(goldgoblin), h_potion(h_potion), m_potion(m_potion)
{
}

void PlayerClass::Attack() const
{
	cout << "���谡 " << name << "�� ����!" << endl;
	Sleep(1500);
	system("cls");
}

void PlayerClass::TakeDamage(const int damage)
{	
	int tempdamage = damage;
	tempdamage -= damage * (defense / 100);
	health -= tempdamage;
	cout << "���谡 " << name << "��(��) '" << tempdamage << "' �� ���ظ� �Ծ���!" << endl;
	cout << "���谡 " << name << "�� ���� ü�� : " << health << endl;
	Sleep(1700);
	system("cls");
}

void PlayerClass::DisPlay() const
{
	cout << "�̸� : " << name << endl;
	cout << "ü�� : " << health << "/" << FullHP << endl;
	cout << "���ݷ� : " << damage << endl;
	cout << "���� : " << defense << endl;
	cout << "���� : " << mp << "/" << FullMP << endl;
	cout << "���� : " << level << endl;
	cout << "����ġ : " << exp << endl;
	cout << endl;
}

void PlayerClass::Meet(const string& Mname)
{
	cout << "����� " << Mname << "��(��) �����Ͽ���!" << endl;
	Sleep(1500);
	system("cls");
}

void PlayerClass::Heal()
{
	health += 10;
	mp -= 10;
	if (health > 100)
	{
		health = 100;
	}
	cout << "ü�� 10 ȸ��! ���� ü�� : " << health << endl;
	cout << "10�� ���� �Ҹ�! ���� ���� : " << mp << endl;
	cout << endl;
	Sleep(1500);
	system("cls");
}

int PlayerClass::Choice(int Choice)
{
	cout << "1. �����ϱ�\n2. ȸ���ϱ�\n3. ��ų���" << endl;
	cin >> Choice;
	system("cls");
	return Choice;
}

void PlayerClass::Slash()
{
	cout << "������!!!" << endl;
	mp -= 10;
	cout << "10�� ���� �Ҹ�! ���� ���� : " << mp << endl;
	Sleep(1500);
	system("cls");
}

void PlayerClass::equipItem(Item& item)
{
	if (isItemEquipped(item))
	{
		cout << "�ش� �������� �����Ǿ� ����." << endl;
		return;
	}
	equippedItems.push_back(item);

	item.SetEquipped(true);

	damage += item.GetAttack();

	defense += item.GetDefense();

	cout << item.GetName() << "(" << item.GetType() << ") ������ ����" << endl;
	
}

void PlayerClass::UnequipItem(Item& item)
{
	for (auto it = equippedItems.begin(); it != equippedItems.end(); ++it)
	{
		if ((*it).GetName() == item.GetName())
		{
			damage -= (*it).GetAttack();

			defense -= (*it).GetDefense();

			(*it).SetEquipped(false);
			
			cout << "'" << item.GetName() << "' (" << item.GetType() << ") ������ Ż��" << endl;

			equippedItems.erase(it);

			return;
		}
	}
	cout << "'" << item.GetName() << "' (" << item.GetType() << ") �������� �����Ǿ� ���� ����" << endl;
}

void PlayerClass::displayEquippedItems() const
{
	if (equippedItems.empty())
	{
		cout << "������ ������ ����" << endl;
		return;
	}
	cout << "������ ������ ��� : " << endl;
	for (const auto& item : equippedItems)
	{
		cout << "'" << item.GetName() << "' (" << item.GetType() << ") = ���ݷ� : " << item.GetAttack() << " , ���� : " << item.GetDefense();

		if (item.isEquipped())
		{
			cout << " <������>";
		}
		cout << endl;
	}
}

void PlayerClass::displayAvailableItem(const vector<Item>& availableItmes) const
{
	if (availableItmes.empty())
	{
		cout << "��밡���� ������ ����" << endl;
		return;
	}
	cout << "��밡���� ������ ���" << endl;

	for (size_t i = 0; i < availableItmes.size(); ++i)
	{
		const Item& item = availableItmes[i];
		cout << i + 1 << ". '" << item.GetName() << "' (" << item.GetType() << ") = ���ݷ� : " << item.GetAttack() << " , ���� : " << item.GetDefense();

		if (isItemEquipped(item))
		{
			cout << " <������>";
		}
		cout << endl;
	}
	cout << endl;
}

bool PlayerClass::isItemEquipped(const Item& item) const
{
	for (const auto& equippedItem : equippedItems)
	{
		if (equippedItem.GetName() == item.GetName())
		{
			return true;
		}

	}
	return false;
}

void PlayerClass::Potionmap()
{

	potion.insert(make_pair("hp", PotionClass("ü�¹���", 50, 100)));
	potion.insert(make_pair("mp", PotionClass("��������", 50, 100)));
	while (true)
	{
	cout << "��ü ȸ���� ���" << endl;
	for (const auto& pair : potion)
	{
		cout << "=================================" << endl;
		cout << "Ű : " << "'" << pair.first << "'" << endl;
		cout << "�̸� : " << pair.second.GetName() << endl;
		cout << "ȸ���� : " << pair.second.GetHealth() << endl;
		cout << "���� : " << pair.second.GetPrice() << endl;
		cout << "=================================" << endl;
	}

		string searchKey;
		cout << "������ ȸ������ Ű�� �Է�" << endl;
		cout << "���ư��� - 0" << endl;
		cin >> searchKey;
		system("cls");
		if (searchKey == "0")
		{
			return;
		}
		auto it = potion.find(searchKey);
		if (it != potion.end())
		{
			cout << "ã�� ȸ����" << endl;
			cout << "�̸� : " << it->second.GetName() << endl;
			cout << "ȸ���� : " << it->second.GetHealth() << endl;
			cout << "���� : " << it->second.GetPrice() << endl;
			cout << "ȸ���� ���� - 1" << endl;
			cout << "�ڷ� ���� - 0" << endl;
			int choice;
			cin >> choice;
			system("cls");
			if (choice == 0)
			{
				continue;
			}
			else if (choice == 1)
			{
				if (GetMoney() < it->second.GetPrice())
				{
					cout << "�� ����" << endl;
					return;
				}
				SetMoney(GetMoney() - it->second.GetPrice());
				if (searchKey == "hp")
				{
					SetH_potion(GetH_potion() + 1);
				}
				else if (searchKey == "mp")
				{
					SetM_potion(GetM_potion() + 1);
				}
				else
				{
					cout << "�ش� ȸ���� ã�� �� ����" << endl;
					return;
				}
			}
		}
		else
		{
			cout << "�ش� ȸ���� ã�� �� ����" << endl;
			return;
		}
	}
}

void PlayerClass::displayPotion()
{
	while (true)
	{
		int choice;
		cout << "���� ȸ���� ���" << endl;
		cout << "ü�¹��� : " << GetH_potion() << "��" << endl;
		cout << "�������� : " << GetM_potion() << "��" << endl;
		cout << "����ϱ� - 1 �Է�" << endl;
		cout << "�ڷΰ��� - 0 �Է�" << endl;
		cin >> choice;
		if (choice == 1)
		{
			usePotion();
		}
		else if (choice == 0)
		{
			system("cls");
			return;
		}
		else
		{
			cout << "�߸��� �Է�" << endl;
			Sleep(1000);
			system("cls");
			continue;
		}
	}
}

void PlayerClass::usePotion()
{
	potion.insert(make_pair("hp", PotionClass("ü�¹���", 50, 100)));
	potion.insert(make_pair("mp", PotionClass("��������", 25, 100)));
	for (const auto& pair : potion)
	{
		cout << "=================================" << endl;
		cout << "Ű : " << "'" << pair.first << "'" << endl;
		cout << "�̸� : " << pair.second.GetName() << endl;
		cout << "ȸ���� : " << pair.second.GetHealth() << endl;
		cout << "���� : " << pair.second.GetPrice() << endl;
		cout << "=================================" << endl;
	}
	string searchKey;
	cout << "����� ȸ������ Ű�� �Է� : ";
	cin >> searchKey;
	system("cls");
	auto it = potion.find(searchKey);
	if (it != potion.end())
	{
		cout << "ã�� ȸ����" << endl;
		cout << "�̸� : " << it->second.GetName() << endl;
		cout << "ȸ���� : " << it->second.GetHealth() << endl;
		cout << "���� : " << it->second.GetPrice() << endl;
		cout << "ȸ���� ��� - 1" << endl;
		cout << "�ڷ� ���� - 2" << endl;
		int choice;
		cin >> choice;
		system("cls");
		if (choice == 2)
		{
			return;
		}
		else if (choice == 1)
		{
			if (searchKey == "hp")
			{
				if (GetH_potion() <= 0)
				{
					cout << "�����ϰ� �ִ� ȸ���� ����" << endl;
					Sleep(1000);
					system("cls");
					return;
				}
				SetH_potion(GetH_potion() - 1);
				SetHealth(GetHealth() + it->second.GetHealth());
				if (GetHealth() > GetFullHP())
				{
					SetHealth(GetFullHP());
				}
			}
			else if (searchKey == "mp")
			{
				if (GetM_potion() <= 0)
				{
					cout << "�����ϰ� �ִ� ȸ���� ����" << endl;
					Sleep(1000);
					system("cls");
					return;
				}
				SetM_potion(GetM_potion() - 1);
				SetMP(GetMP() + it->second.GetHealth());
				if (GetMP() > GetFullMP())
				{
					SetMP(GetFullMP());
				}
			}
			else
			{
				cout << "�ش� ȸ���� ã�� �� ����" << endl;
				Sleep(1000);
				system("cls");
				return;
			}
		}
	}
	else
	{
		cout << "�ش� ȸ���� ã�� �� ����" << endl;
		Sleep(1000);
		system("cls");
		return;
	}
}

