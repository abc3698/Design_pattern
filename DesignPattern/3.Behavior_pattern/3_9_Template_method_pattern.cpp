#include<iostream>
#include <memory>
#include <string>

class SandWich
{
protected:
	virtual std::string bread() = 0;
	virtual std::string jam() = 0;

public:
	void make()
	{
		std::string msg;

		msg.append(this->bread());
		msg.append("+");
		msg.append(this->jam());
		msg.append("로 구성됩니다");

		std::cout << msg << std::endl;
	}
};

class Strawberry : public SandWich
{
protected:
	std::string bread()
	{
		return "식빵";
	}

	std::string jam()
	{
		return "딸기잼";
	}
};

class StrawberryRye : public Strawberry
{
protected:
	std::string bread()
	{
		return "호밀";
	}	
};

int main()
{
	auto obj1 = std::make_shared<Strawberry>();
	obj1->make();

	auto obj2 = std::make_shared<StrawberryRye>();
	obj2->make();
}