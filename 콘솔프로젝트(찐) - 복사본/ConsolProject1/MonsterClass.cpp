#include "MonsterClass.h"

MonsterClass::MonsterClass(const string& name, const int health, const int damage, const int mp, const int exp, const int money)
	:ConsolCharacter(name, health, damage, mp), exp(exp), money(money)
{
}

void MonsterClass::Attack() const
{
	cout << name << "의 공격!" << endl;
	Sleep(1500);
	system("cls");
}

void MonsterClass::TakeDamage(int damage)
{
	health -= damage;
	cout << name << "이(가) " << damage << "의 피해를 입음!" << endl;
	cout << name << "의 현재 체력 : " << health << endl;
	Sleep(1700);
	system("cls");
}

void MonsterClass::DisPlay() const
{
	cout << endl;
	cout << "몬스터 정보" << endl;
	cout << "이름 : " << name << endl;
	cout << "체력 : " << health << endl;
	cout << "공격력 : " << damage << endl;
	cout << endl;
}

void MonsterClass::PowerUP()
{
	cout << name << "의 강공격!" << endl;
	Sleep(1500);
	system("cls");
}
