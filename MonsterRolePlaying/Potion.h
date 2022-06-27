#ifndef POTION_H
#define POTION_H

class Potion
{
public:
	enum Type
	{
		health,
		strength,
		poison,
		max_potion,
	};

	enum Size
	{
		small,
		medium,
		large,
		max_size,
	};

	Potion(Type myType, Size mySize);
	static Potion getRandomPotion();

	const std::string_view getTypeStr() const;
	const std::string_view getSizeStr() const;

	const Type getType() const { return m_potionType; }
	const Size getSize() const { return m_size; }

private:
	Type m_potionType{};
	Size m_size{};
};

#endif