#include "ItemInventory.h"
using namespace std;

void ItemInventory::InitItems()
{
	availableItems.push_back(Item("��", "����", 10, 0));
	availableItems.push_back(Item("����", "��", 0, 20));
	availableItems.push_back(Item("����", "��", 0, 30));
	availableItems.push_back(Item("�����", "�Ǽ�����", 0, 5));

	
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
			cout << "�ٽ� �õ�" << endl;
			Sleep(1000);
			system("cls");
			break;
		}

	}
}

void ItemInventory::ShowMenu()
{
	cout << "======================================" << endl;
	cout << "1. ������ �����ϱ�" << endl;
	cout << "2. ������ Ż���ϱ�" << endl;
	cout << "3. ������ ������ ���" << endl;
	cout << "4. ��밡���� ������ ���" << endl;
	cout << "5. ��밡���� ���� ���" << endl;
	cout << "6. �ڷΰ���" << endl;
	cout << "�޴��� �����ϼ���." << endl;
	cout << "======================================" << endl;
}

void ItemInventory::EquipItem(class PlayerClass& player)
{
	cout << "������ ������ ���� (1-" << availableItems.size() << ") : " << endl;
	player.displayAvailableItem(availableItems);
	cout << "�ڷΰ��� 0 �Է�" << endl;
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
		cout << "�ٽ� �õ�" << endl;
		Sleep(1000);
		system("cls");
	}
}

void ItemInventory::UnEquipItem(class PlayerClass& player)
{
	player.displayEquippedItems();

	cout << "Ż���� �������� ���� (1-" << player.getEquippedItemCount() << ")" << endl;
	cout << endl;	
	cout << "�ڷΰ��� 0 �Է�" << endl;
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
		cout << "�ٽ� �õ�" << endl;
		Sleep(1000);
		system("cls");
	}
}

