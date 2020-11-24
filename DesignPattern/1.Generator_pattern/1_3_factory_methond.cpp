#include<iostream>
#include <memory>
#include <string>
class Prodcut
{
public:
	virtual void Name() = 0;
};
class LGProduct : public Prodcut
{
public:
	void Name()
	{
		std::cout << "LGProduct를 생성합니다" << std::endl;
	}
};

class SamsungProduct : public Prodcut
{
public:
	void Name()
	{
		std::cout << "Samsung Product를 생성합니다" << std::endl;
	}
};

class Factory
{
protected:
	std::shared_ptr<Prodcut>  create(std::string model)
	{
		return this->createProduct(model);
	}
public:
	virtual std::shared_ptr<Prodcut> createProduct(std::string model) = 0;
};

class ProductFactory final : public Factory {
public:
	ProductFactory()
	{
		std::cout << "ProductFactory를 생성합니다" << std::endl;
	}

	virtual std::shared_ptr<Prodcut> createProduct(std::string model)
	{
		if(model == "LG")
			return std::make_shared<LGProduct>();
		return std::make_shared<SamsungProduct>();
	}
};

int main()
{
	auto fac = new ProductFactory;
	auto pro = fac->createProduct("LG");
	pro->Name();

	pro = fac->createProduct("Samsung");
	pro->Name();
	return 0;
}