#pragma once
#include<map>
#include<string>

using namespace std;
class PotionClass
{
private:
	string name;
	int health;
	int price;

public:
	PotionClass() : name(""), health(0), price(0) {}
	PotionClass(const string& n, int h, int p) : name(n), health(h), price(p) {}

	string GetName()const { return name; }
	int GetHealth()const { return health; }
	int GetPrice()const { return price; }

};