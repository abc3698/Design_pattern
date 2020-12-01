#include<iostream>
#include <memory>
#include <string>

class Hello
{
private:
	static std::shared_ptr<Hello> instance;

public:
	static std::shared_ptr<Hello> getInstance()
	{
		if (instance != nullptr)
		{
			std::cout << "기존 객체를 반환합니다." << std::endl;
			return instance;
		}

		std::cout << "공유 객체를 생성합니다." << std::endl;
		instance = std::make_shared<Hello>();
		return instance;
	}

	void console(std::string msg)
	{
		std::cout << msg << std::endl;
	}
};

std::shared_ptr<Hello> Hello::instance = nullptr;

class Factory
{
public:
	std::shared_ptr<Hello> make()
	{
		std::cout << "팩토리 생성 요청 = ";
		return Hello::getInstance();
	}
};

int main()
{
	// 팩토리 객체 1
	auto hello1 = std::make_shared<Factory>()->make();

	// 팩토리 객체 2
	auto hello2 = std::make_shared<Factory>()->make();

	if (hello1 == hello2)
	{
		std::cout << "동일 객체입니다." << std::endl;
	}
	else
	{
		std::cout << "서로 다른 객체입니다." << std::endl;
	}
}