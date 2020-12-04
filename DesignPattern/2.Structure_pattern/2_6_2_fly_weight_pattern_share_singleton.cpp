#include<iostream>
#include <memory>
#include <string>
#include <map>

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
private :
	// 공유 메모리
	std::map<std::string, std::shared_ptr<Hello>> pool;

public:
	std::shared_ptr<Hello> make(std::string name)
	{
		if (pool.find(name) == pool.end())
		{
			std::cout << "팩토리 생성 요청 = ";
			pool.insert(std::make_pair(name, Hello::getInstance()));
			return pool[name];
		}
		
		std::cout << "저장된 pool 객체 반환" << std::endl;
		return pool[name];
	}
};

int main()
{
	auto factory = std::make_shared<Factory>();
	// 팩토리 객체 1
	auto hello1 = factory->make("Hello");

	// 팩토리 객체 2
	auto hello2 = factory->make("Hello");

	if (hello1 == hello2)
	{
		std::cout << "동일 객체입니다." << std::endl;
	}
	else
	{
		std::cout << "서로 다른 객체입니다." << std::endl;
	}
}