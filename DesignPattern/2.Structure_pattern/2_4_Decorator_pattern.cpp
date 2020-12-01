#include<iostream>
#include <memory>
#include <string>

__interface Component
{
public:
	std::string product();
	int price();
};

// 장식자 클래스
class Decorate : public Component
{
public:
	virtual std::string product() = 0;
	virtual int price() = 0;
};

class Product1 : public Component
{
public:
	std::string product()
	{
		return "원피스";
	}

	int price()
	{
		return 20000;
	}
};

class i7 : public Decorate
{
public:
	std::shared_ptr<Component> base;

public:
	i7(std::shared_ptr<Component> base)
	{
		this->base = base;
	}

	std::string product()
	{
		return base->product() + ", i7";
	}

	int price()
	{
		return base->price() + 475000;
	}
};

class ssd256 : public Decorate
{
public:
	std::shared_ptr<Component> base;

public:
	ssd256(std::shared_ptr<Component> base)
	{
		this->base = base;
	}

	std::string product()
	{
		return base->product() + ", ssd256";
	}

	int price()
	{
		return base->price() + 110000;
	}
};

int main()
{
	auto pd1 = std::make_shared<Product1>();
	
	auto spec = std::make_shared<i7>(pd1);
	auto spec2 = std::make_shared<ssd256>(spec);

	std::cout << "스펙 = " << spec2->product() << std::endl;
	std::cout << "가격 = " << spec2->price() << std::endl;
	
	return 0;
}