#include<iostream>
#include <memory>
#include <string>

/*Algorithm*/
__interface Weapon
{
public:
	virtual void attack() = 0;
};

/*Concrete Algorithm*/
class Knife : public Weapon
{
public:
	void attack()
	{
		std::cout << "칼로 공격합니다." << std::endl;
	}
};

class Gun : public Weapon
{
public:
	void attack()
	{
		std::cout << "총으로 공격합니다." << std::endl;
	}
};

/*Stategy*/
class Stategy
{
protected:
	std::shared_ptr<Weapon> delegate;

public:
	void setWeapon(std::shared_ptr<Weapon> weapon)
	{
		std::cout << "===무기를 교환합니다.===" << std::endl;
		delegate = weapon;
	}

	virtual void attack() = 0;
};

/*Concrete Stategy*/
class Charactor : public Stategy
{
public:
	void attack()
	{
		if (delegate == nullptr)
		{
			std::cout << "맨손 공격합니다." << std::endl;
		}
		else
		{
			delegate->attack();
		}
	}
};

int main()
{
	auto obj = std::make_shared<Charactor>();
	obj->attack();

	obj->setWeapon(std::make_shared<Knife>());
	obj->attack();

	obj->setWeapon(std::make_shared<Gun>());
	obj->attack();
}