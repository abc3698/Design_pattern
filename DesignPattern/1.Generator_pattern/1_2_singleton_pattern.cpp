#include<iostream>
#include <memory>
//class Config
//{
//private:
//	// 외부에서 생성자 금지
//	Config()
//	{
//		std::cout << "Config가 생성이 되었습니다" << std::endl;
//	}
//	// 외부에서 복사 생성자 금지
//	Config(Config& rhs)
//	{
//		std::cout << "Config가 복사 되었습니다" << std::endl;
//	}
//
//	static void Deleter(Config* p_test)
//	{
//		std::cout << "Config가 제거되었습니다" << std::endl;
//		delete p_test;
//	}
//
//	static std::shared_ptr<Config> instance;
//
//public:
//	static std::shared_ptr<Config> getInstance()
//	{
//		instance = std::make_shared<Config>();
//		return instance;
//	}
//};
//
//int main()
//{
//	auto cfg1 = Config::getInstance();
//	auto cfg2 = Config::getInstance();	
//}

class Config
{
protected:
	// 외부에서 생성자 금지
	Config()
	{
		std::cout << "Config가 생성이 되었습니다" << std::endl;
	}
	// 외부에서 복사 생성자 금지
	Config(Config& rhs)
	{
		std::cout << "Config가 복사 되었습니다" << std::endl;
	}
	
	static Config* instance;	
};

class Env : public Config
{
public:
	void setting()
	{
		std::cout << "시스템 환경을 설정합니다" << std::endl;
	}

	static Config* getInstance()
	{
		if (instance == nullptr)
		{
			std::cout << "Env가 생성이 되었습니다" << std::endl;
			instance = new Env;
		}
		std::cout << "Env가 반환 되었습니다" << std::endl;
		return instance;
	}

	static void Delete()
	{
		if (instance != nullptr)
		{
			std::cout << "Env가 제거되었습니다" << std::endl;
			delete instance;
		}
	}
};

Config* Config::instance = nullptr;

int main()
{
	auto cfg1 = Env::getInstance();	
	static_cast<Env*>(cfg1)->setting();
	Env::Delete();
}