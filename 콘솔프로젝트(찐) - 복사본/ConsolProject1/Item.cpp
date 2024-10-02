#include "Item.h"

Item::Item(const string& name, const string type, int attack, int defense)
	:name(name), type(type), attack(attack), defense(defense), equipped(false)
{
}
