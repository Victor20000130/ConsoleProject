#pragma once
#include"ConsolCharacter.h"
#include<vector>
#include"Item.h"
#include"PotionClass.h"
#include<map>
class PlayerClass : public ConsolCharacter
{
private:
	vector<Item> equippedItems;
	float defense;
	int FullHP;
	int FullMP;
	int level;
	int exp;
	int money;
	int goblin;
	int cobolt;
	int troll;
	int ogre;
	int goldgoblin;
	int h_potion;
	int m_potion;
	map<string, PotionClass> potion;

public:
	PlayerClass(const string& name, const int health, const int damage, const int mp, const float defense, const int FullHP, const int FullMP, const int level, const int exp, const int money, const int goblin, const int cobolt, const int troll, const int ogre, const int goldgoblin, const int h_potion, const int m_potion);

	string GetName()const { return name; }
	void SetName(const string& n) { name = n; }
	int GetDamage()const { return damage; }
	void SetDamage(const int d) { damage = d; }
	int GetDefense()const { return defense; }
	int GetMP()const { return mp; }
	void SetMP(const int m) { mp = m; }
	int GetHealth()const { return health; }
	void SetHealth(const int h) { health = h; }
	int GetLev()const { return level; }
	void SetLev(const int lev) { level = lev; }
	int GetExp()const { return exp; }
	void SetExp(const int ex) { exp = ex; }
	int GetMoney()const { return money; }
	void SetMoney(const int mon) { money = mon; }
	int GetFullHP()const { return FullHP; }
	void SetFullHP(const int Fhp) { FullHP = Fhp; }
	int GetFullMP()const { return FullMP; }
	void SetFullMP(const int Fmp) { FullMP = Fmp; }
	int GetH_potion()const { return h_potion; }
	void SetH_potion(const int hpo) { h_potion = hpo; }
	int GetM_potion()const { return m_potion; }
	void SetM_potion(const int mpo) { m_potion = mpo; }

	int GetGoblin()const { return goblin; }
	int GetCobolt()const { return cobolt; }
	int GetTroll()const { return troll; }
	int GetOgre()const { return ogre; }
	int GetGoldgoblin()const { return goldgoblin; }

	void SetGoblin(const int g) { goblin = g; }
	void SetCobolt(const int c) { cobolt = c; }
	void SetTroll(const int t) { troll = t; }
	void SetOgre(const int o) { ogre = o; }
	void SetGoldgoblin(const int gg) { goldgoblin = gg; }


	void Attack()const override;
	void TakeDamage(const int damage)override;
	void DisPlay()const override;

	void Meet(const string& Mname);

	void Heal();
	int Choice(int Choice);
	void Slash();


	void equipItem(Item& item);
	void UnequipItem(Item& item);
	void displayEquippedItems()const;
	void displayAvailableItem(const vector<Item>& availableItmes)const;
	int getEquippedItemCount()const { return equippedItems.size(); }
	Item& getEquippedItem(int index) { return equippedItems[index]; }
	bool isItemEquipped(const Item& item)const;

	void Potionmap();
	void displayPotion();
	void usePotion();
};


