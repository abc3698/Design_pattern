#include<iostream>
#include <memory>
#include <string>

/*Implementor*/
__interface Hello
{
public:
	virtual void greeting();
};

/*ConcreteImplementor*/
class English : public Hello
{
public:
	void greeting()
	{
		std::cout << "Hello" << std::endl;		
	}
};

/*ConcreteImplementor*/
class Krorea : public Hello
{
public:
	void greeting()
	{
		std::cout << "¾È³çÇÏ¼¼¿ä" << std::endl;
	}
};

int main()
{
	auto obj = std::make_shared<Krorea>();
	obj->greeting();

	auto obj2 = std::make_shared<English>();
	obj2->greeting();
}