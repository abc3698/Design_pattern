#include<iostream>
#include <memory>
//class Config
//{
//private:
//	// �ܺο��� ������ ����
//	Config()
//	{
//		std::cout << "Config�� ������ �Ǿ����ϴ�" << std::endl;
//	}
//	// �ܺο��� ���� ������ ����
//	Config(Config& rhs)
//	{
//		std::cout << "Config�� ���� �Ǿ����ϴ�" << std::endl;
//	}
//
//	static void Deleter(Config* p_test)
//	{
//		std::cout << "Config�� ���ŵǾ����ϴ�" << std::endl;
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
	// �ܺο��� ������ ����
	Config()
	{
		std::cout << "Config�� ������ �Ǿ����ϴ�" << std::endl;
	}
	// �ܺο��� ���� ������ ����
	Config(Config& rhs)
	{
		std::cout << "Config�� ���� �Ǿ����ϴ�" << std::endl;
	}
	
	static Config* instance;	
};

class Env : public Config
{
public:
	void setting()
	{
		std::cout << "�ý��� ȯ���� �����մϴ�" << std::endl;
	}

	static Config* getInstance()
	{
		if (instance == nullptr)
		{
			std::cout << "Env�� ������ �Ǿ����ϴ�" << std::endl;
			instance = new Env;
		}
		std::cout << "Env�� ��ȯ �Ǿ����ϴ�" << std::endl;
		return instance;
	}

	static void Delete()
	{
		if (instance != nullptr)
		{
			std::cout << "Env�� ���ŵǾ����ϴ�" << std::endl;
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