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
	cout << "모험가 " << name << "의 공격!" << endl;
	Sleep(1500);
	system("cls");
}

void PlayerClass::TakeDamage(const int damage)
{	
	int tempdamage = damage;
	tempdamage -= damage * (defense / 100);
	health -= tempdamage;
	cout << "모험가 " << name << "이(가) '" << tempdamage << "' 의 피해를 입었다!" << endl;
	cout << "모험가 " << name << "의 현재 체력 : " << health << endl;
	Sleep(1700);
	system("cls");
}

void PlayerClass::DisPlay() const
{
	cout << "이름 : " << name << endl;
	cout << "체력 : " << health << "/" << FullHP << endl;
	cout << "공격력 : " << damage << endl;
	cout << "방어력 : " << defense << endl;
	cout << "마나 : " << mp << "/" << FullMP << endl;
	cout << "레벨 : " << level << endl;
	cout << "경험치 : " << exp << endl;
	cout << endl;
}

void PlayerClass::Meet(const string& Mname)
{
	cout << "당신은 " << Mname << "과(와) 조우하였다!" << endl;
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
	cout << "체력 10 회복! 현재 체력 : " << health << endl;
	cout << "10의 마나 소모! 현재 마나 : " << mp << endl;
	cout << endl;
	Sleep(1500);
	system("cls");
}

int PlayerClass::Choice(int Choice)
{
	cout << "1. 공격하기\n2. 회복하기\n3. 스킬사용" << endl;
	cin >> Choice;
	system("cls");
	return Choice;
}

void PlayerClass::Slash()
{
	cout << "슬래쉬!!!" << endl;
	mp -= 10;
	cout << "10의 마나 소모! 현재 마나 : " << mp << endl;
	Sleep(1500);
	system("cls");
}

void PlayerClass::equipItem(Item& item)
{
	if (isItemEquipped(item))
	{
		cout << "해당 아이템은 장착되어 있음." << endl;
		return;
	}
	equippedItems.push_back(item);

	item.SetEquipped(true);

	damage += item.GetAttack();

	defense += item.GetDefense();

	cout << item.GetName() << "(" << item.GetType() << ") 아이템 장착" << endl;
	
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
			
			cout << "'" << item.GetName() << "' (" << item.GetType() << ") 아이템 탈착" << endl;

			equippedItems.erase(it);

			return;
		}
	}
	cout << "'" << item.GetName() << "' (" << item.GetType() << ") 아이템이 장착되어 있지 않음" << endl;
}

void PlayerClass::displayEquippedItems() const
{
	if (equippedItems.empty())
	{
		cout << "장착된 아이템 없음" << endl;
		return;
	}
	cout << "장착된 아이템 목록 : " << endl;
	for (const auto& item : equippedItems)
	{
		cout << "'" << item.GetName() << "' (" << item.GetType() << ") = 공격력 : " << item.GetAttack() << " , 방어력 : " << item.GetDefense();

		if (item.isEquipped())
		{
			cout << " <장착중>";
		}
		cout << endl;
	}
}

void PlayerClass::displayAvailableItem(const vector<Item>& availableItmes) const
{
	if (availableItmes.empty())
	{
		cout << "사용가능한 아이템 없음" << endl;
		return;
	}
	cout << "사용가능한 아이템 목록" << endl;

	for (size_t i = 0; i < availableItmes.size(); ++i)
	{
		const Item& item = availableItmes[i];
		cout << i + 1 << ". '" << item.GetName() << "' (" << item.GetType() << ") = 공격력 : " << item.GetAttack() << " , 방어력 : " << item.GetDefense();

		if (isItemEquipped(item))
		{
			cout << " <장착중>";
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

	potion.insert(make_pair("hp", PotionClass("체력물약", 50, 100)));
	potion.insert(make_pair("mp", PotionClass("마나물약", 50, 100)));
	while (true)
	{
	cout << "전체 회복약 목록" << endl;
	for (const auto& pair : potion)
	{
		cout << "=================================" << endl;
		cout << "키 : " << "'" << pair.first << "'" << endl;
		cout << "이름 : " << pair.second.GetName() << endl;
		cout << "회복량 : " << pair.second.GetHealth() << endl;
		cout << "가격 : " << pair.second.GetPrice() << endl;
		cout << "=================================" << endl;
	}

		string searchKey;
		cout << "구매할 회복약의 키를 입력" << endl;
		cout << "돌아가기 - 0" << endl;
		cin >> searchKey;
		system("cls");
		if (searchKey == "0")
		{
			return;
		}
		auto it = potion.find(searchKey);
		if (it != potion.end())
		{
			cout << "찾은 회복약" << endl;
			cout << "이름 : " << it->second.GetName() << endl;
			cout << "회복량 : " << it->second.GetHealth() << endl;
			cout << "가격 : " << it->second.GetPrice() << endl;
			cout << "회복약 구매 - 1" << endl;
			cout << "뒤로 가기 - 0" << endl;
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
					cout << "돈 부족" << endl;
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
					cout << "해당 회복약 찾을 수 없음" << endl;
					return;
				}
			}
		}
		else
		{
			cout << "해당 회복약 찾을 수 없음" << endl;
			return;
		}
	}
}

void PlayerClass::displayPotion()
{
	while (true)
	{
		int choice;
		cout << "보유 회복약 목록" << endl;
		cout << "체력물약 : " << GetH_potion() << "개" << endl;
		cout << "마나물약 : " << GetM_potion() << "개" << endl;
		cout << "사용하기 - 1 입력" << endl;
		cout << "뒤로가기 - 0 입력" << endl;
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
			cout << "잘못된 입력" << endl;
			Sleep(1000);
			system("cls");
			continue;
		}
	}
}

void PlayerClass::usePotion()
{
	potion.insert(make_pair("hp", PotionClass("체력물약", 50, 100)));
	potion.insert(make_pair("mp", PotionClass("마나물약", 25, 100)));
	for (const auto& pair : potion)
	{
		cout << "=================================" << endl;
		cout << "키 : " << "'" << pair.first << "'" << endl;
		cout << "이름 : " << pair.second.GetName() << endl;
		cout << "회복량 : " << pair.second.GetHealth() << endl;
		cout << "가격 : " << pair.second.GetPrice() << endl;
		cout << "=================================" << endl;
	}
	string searchKey;
	cout << "사용할 회복약의 키를 입력 : ";
	cin >> searchKey;
	system("cls");
	auto it = potion.find(searchKey);
	if (it != potion.end())
	{
		cout << "찾은 회복약" << endl;
		cout << "이름 : " << it->second.GetName() << endl;
		cout << "회복량 : " << it->second.GetHealth() << endl;
		cout << "가격 : " << it->second.GetPrice() << endl;
		cout << "회복약 사용 - 1" << endl;
		cout << "뒤로 가기 - 2" << endl;
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
					cout << "보유하고 있는 회복약 없음" << endl;
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
					cout << "보유하고 있는 회복약 없음" << endl;
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
				cout << "해당 회복약 찾을 수 없음" << endl;
				Sleep(1000);
				system("cls");
				return;
			}
		}
	}
	else
	{
		cout << "해당 회복약 찾을 수 없음" << endl;
		Sleep(1000);
		system("cls");
		return;
	}
}

