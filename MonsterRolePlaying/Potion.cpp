#include <random>
#include "Potion.h"

Potion::Potion(Type myType, Size mySize) : m_potionType{ myType }, m_size{ mySize }
{
}

Potion Potion::getRandomPotion()
{
	static std::random_device rd;
	static std::seed_seq seq{ rd(),rd() ,rd() ,rd(),rd(),rd(),rd(),rd() };
	static std::mt19937 mt{ seq };

	std::uniform_int_distribution distType(0, static_cast<int>(Type::max_potion) - 1);
	std::uniform_int_distribution distSize(0, static_cast<int>(Size::max_size) - 1);

	return Potion{ static_cast<Type>(distType(mt)),static_cast<Size>(distSize(mt)) };
}

const std::string_view Potion::getTypeStr() const
{
	switch (m_potionType)
	{
	case Type::health:     return "Health";
	case Type::strength:   return "Strength";
	case Type::poison:     return "Poison";
	default:               return "INVALID";
	}
}

const std::string_view Potion::getSizeStr() const
{
	switch (m_size)
	{
	case Size::small:     return "Small";
	case Size::medium:   return "Medium";
	case Size::large:     return "Large";
	default:               return "INVALID";
	}
}