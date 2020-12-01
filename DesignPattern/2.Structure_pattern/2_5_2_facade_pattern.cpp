#include<iostream>
#include <memory>
#include <string>

class Package1
{
public:
	Package1()
	{
		std::cout << "Package1 객체가 생성이 되었습니다" << std::endl;
	}

	void process()
	{
		std::cout << "패키지1 작업을 진행합니다." << std::endl;
	}
};

class Package2
{
public:
	Package2()
	{
		std::cout << "Package2 객체가 생성이 되었습니다" << std::endl;
	}

	void process()
	{
		std::cout << "패키지2 작업을 진행합니다." << std::endl;
	}
};

class Package3
{
public:
	Package3()
	{
		std::cout << "Package3 객체가 생성이 되었습니다" << std::endl;
	}

	void process()
	{
		std::cout << "패키지3 작업을 진행합니다." << std::endl;
	}
};

class Facade
{
private:
	std::shared_ptr<Package1> _package1;
	std::shared_ptr<Package2> _package2;
	std::shared_ptr<Package3> _package3;

public:
	Facade()
	{
		this->_package1 = std::make_shared<Package1>();
		this->_package2 = std::make_shared<Package2>();
		this->_package3 = std::make_shared<Package3>();
	}

	void processAll()
	{
		this->_package1->process();
		this->_package2->process();
		this->_package3->process();
	}
};

int main()
{
	auto obj1 = std::make_shared<Facade>();
	obj1->processAll();

	return 0;
}