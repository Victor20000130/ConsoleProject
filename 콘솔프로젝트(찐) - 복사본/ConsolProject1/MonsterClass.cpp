#include "MonsterClass.h"

MonsterClass::MonsterClass(const string& name, const int health, const int damage, const int mp, const int exp, const int money)
	:ConsolCharacter(name, health, damage, mp), exp(exp), money(money)
{
}

void MonsterClass::Attack() const
{
	cout << name << "�� ����!" << endl;
	Sleep(1500);
	system("cls");
}

void MonsterClass::TakeDamage(int damage)
{
	health -= damage;
	cout << name << "��(��) " << damage << "�� ���ظ� ����!" << endl;
	cout << name << "�� ���� ü�� : " << health << endl;
	Sleep(1700);
	system("cls");
}

void MonsterClass::DisPlay() const
{
	cout << endl;
	cout << "���� ����" << endl;
	cout << "�̸� : " << name << endl;
	cout << "ü�� : " << health << endl;
	cout << "���ݷ� : " << damage << endl;
	cout << endl;
}

void MonsterClass::PowerUP()
{
	cout << name << "�� ������!" << endl;
	Sleep(1500);
	system("cls");
}
