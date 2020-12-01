#include<iostream>
#include <memory>
#include <string>

class Hello
{
public:
	void console(std::string msg)
	{
		std::cout << msg << std::endl;
	}
};

class Korea
{
public:
	std::shared_ptr<Hello> hello;

public:
	Korea(std::shared_ptr<Hello> hello)
	{
		this->hello = hello;
	}

	void Hello()
	{
		hello->console("안녕하세요");
	}
};

class English
{
public:
	std::shared_ptr<Hello> hello;

public:
	English(std::shared_ptr<Hello> hello)
	{
		this->hello = hello;
	}

	void Hello()
	{
		hello->console("Hello");
	}
};

int main()
{	
	auto hello = std::make_shared<Hello>();

	auto ko = std::make_shared<Korea>(hello);
	ko->Hello();

	auto en = std::make_shared<English>(hello);
	en->Hello();

	return 0;
}