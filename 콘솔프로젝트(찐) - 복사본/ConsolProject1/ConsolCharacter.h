#pragma once
#include<iostream>
#include<Windows.h>
#include<random>
using namespace std;
class ConsolCharacter
{
protected:
	string name;
	int health;
	int damage;
	int mp;
public:
	ConsolCharacter(const string& name, const int health, const int damage, const int mp);
	virtual ~ConsolCharacter();

public:
	virtual void Attack()const = 0;
	virtual void TakeDamage(int damage) = 0;
	virtual void DisPlay()const = 0;


};

