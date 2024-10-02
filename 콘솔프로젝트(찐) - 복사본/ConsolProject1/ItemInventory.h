#pragma once
#include"PlayerClass.h"
#include"Item.h"
#include"ItemMenu.h"
using namespace std;
class ItemInventory
{
private:

	vector<Item> availableItems;

public:
	ItemInventory()
	{
		InitItems();

	}
	~ItemInventory()
	{
	}

public:
	void InitItems();
	void InventoryRun(class PlayerClass& player);
	void ShowMenu();
	void EquipItem(class PlayerClass& player);
	void UnEquipItem(class PlayerClass& player);

	
};

