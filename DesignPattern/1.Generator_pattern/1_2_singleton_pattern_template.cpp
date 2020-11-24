#include<iostream>
#include <memory>

template<typename T>
class Singleton
{		
protected:
	// 외부에서 생성자 금지
	Singleton()
	{
		std::cout << "Singleton가 생성이 되었습니다" << std::endl;
	}

public:
	// 외부에서 복사 생성자 금지
	Singleton(const Singleton& rhs) = delete;
	Singleton& operator= (const Singleton) = delete;

	static std::shared_ptr<T> getInstance()
	{
		static std::shared_ptr<T> instance(new T, [](T* ptr) { 
			delete ptr; std::cout << "Singleton가 제거되었습니다" << std::endl;}
		);

		return instance;
	}
};

class Config : public Singleton<Config>
{
public:
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

	static void Deleter(Config* p_test)
	{
		std::cout << "Config가 제거되었습니다" << std::endl;
		delete p_test;
	}
};

int main()
{
	// cfg1과 cfg2가 동일한 주소값을 가짐
	auto cfg1 = Singleton<Config>::getInstance();
	auto cfg2 = Singleton<Config>::getInstance();
}