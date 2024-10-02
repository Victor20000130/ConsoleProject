#pragma once
#include"ConsolCharacter.h"
class MonsterClass : public ConsolCharacter
{
private:
	int exp;
	int money;
public:
	MonsterClass(const string& name, const int health, const int damage, const int mp, const int exp, const int money);

	string GetName()const { return name; }
	int GetHealth()const { return health; }
	int GetDamage()const { return damage; }
	int GetExp()const { return exp; }
	void SetExp(const int ex) { exp = ex; }
	int GetMoney()const { return money; }
	void SetMoney(const int mon) { money = mon; }
	void SetName(const string& n) { name = n; }
	void SetHealth(const int h) { health = h; }
	void SetDamage(const int d) { damage = d; }
	void Attack()const override;
	void TakeDamage(int damage)override;
	void DisPlay()const override;

	void PowerUP();
};

