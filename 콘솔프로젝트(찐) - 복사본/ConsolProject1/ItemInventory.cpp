#include "ItemInventory.h"
using namespace std;

void ItemInventory::InitItems()
{
	availableItems.push_back(Item("검", "무기", 10, 0));
	availableItems.push_back(Item("방패", "방어구", 0, 20));
	availableItems.push_back(Item("갑옷", "방어구", 0, 30));
	availableItems.push_back(Item("목걸이", "악세서리", 0, 5));

	
}


void ItemInventory::InventoryRun(class PlayerClass& player)
{
	while (true)
	{
		ShowMenu();
		int choice;
		cin >> choice;
		system("cls");
		ItemMenu::Option op = static_cast<ItemMenu::Option>(choice);
		switch (op)
		{
		case ItemMenu::Option::EQUIP_ITEM:
			EquipItem(player);
			break;
		case ItemMenu::Option::INEQUIP_ITEM:
			UnEquipItem(player);
			break;
		case ItemMenu::Option::DISPLAY_EQUIPPED:
			player.displayEquippedItems();
			break;
		case ItemMenu::Option::DISPLAY_AVAILABLE:
			player.displayAvailableItem(availableItems);
			break;
		case ItemMenu::Option::DISPLAY_POTION:
			player.displayPotion();
			break;
		case ItemMenu::Option::EXIT:
			return;
		default:
			cout << "다시 시도" << endl;
			Sleep(1000);
			system("cls");
			break;
		}

	}
}

void ItemInventory::ShowMenu()
{
	cout << "======================================" << endl;
	cout << "1. 아이템 장착하기" << endl;
	cout << "2. 아이템 탈착하기" << endl;
	cout << "3. 장착된 아이템 목록" << endl;
	cout << "4. 사용가능한 아이템 목록" << endl;
	cout << "5. 사용가능한 포션 목록" << endl;
	cout << "6. 뒤로가기" << endl;
	cout << "메뉴를 선택하세요." << endl;
	cout << "======================================" << endl;
}

void ItemInventory::EquipItem(class PlayerClass& player)
{
	cout << "장착할 아이템 선택 (1-" << availableItems.size() << ") : " << endl;
	player.displayAvailableItem(availableItems);
	cout << "뒤로가기 0 입력" << endl;
	int itemIdx;
	cin >> itemIdx;
	if (itemIdx >= 1 && itemIdx <= availableItems.size())
	{
		system("cls");
		Item& selectItem = availableItems[itemIdx - 1];
		player.equipItem(selectItem);
	}
	else if (itemIdx == 0)
	{
		return;
	}
	else
	{
		cout << "다시 시도" << endl;
		Sleep(1000);
		system("cls");
	}
}

void ItemInventory::UnEquipItem(class PlayerClass& player)
{
	player.displayEquippedItems();

	cout << "탈착할 아이템을 선택 (1-" << player.getEquippedItemCount() << ")" << endl;
	cout << endl;	
	cout << "뒤로가기 0 입력" << endl;
	int itemIdx;
	cin >> itemIdx;
	if (itemIdx >= 1 && itemIdx <= player.getEquippedItemCount())
	{
		Item& selectItem = player.getEquippedItem(itemIdx - 1);
		system("cls");
		player.UnequipItem(selectItem);
	}
	else if (itemIdx == 0)
	{
		return;
	}
	else
	{
		cout << "다시 시도" << endl;
		Sleep(1000);
		system("cls");
	}
}

