#include<iostream>
#include <memory>
#include <string>

class Math
{
public:
	float twoTime(float sum)
	{
		std::cout << "실수 2배 적용합니다." << std::endl;
		return sum * 2.;
	}

	float halfTime(float sum)
	{
		std::cout << "실수 1/2배 적용합니다." << std::endl;
		return sum / 2.;
	}
};

__interface Adapter
{
public:
	virtual int twiceOf(int num);
	virtual int halfOf(int num);
};

class Object : public Adapter
{
private:
	std::shared_ptr<Math> adapter;

public:
	Object()
	{
		adapter = std::make_shared<Math>();
	}

	int twiceOf(int num)
	{
		std::cout << "정수 2배 적용합니다." << std::endl;
		int _num = adapter->twoTime((float)num);
		return (int)_num;
	}

	int halfOf(int num)
	{
		std::cout << "정수 1/2배 적용합니다." << std::endl;
		int _num = adapter->halfTime((float)num);
		return (int)_num;
	}
};

int main()
{
	auto obj = std::make_shared<Object>();

	std::cout << obj->twiceOf(5) << std::endl;

	std::cout << obj->halfOf(4) << std::endl;
}