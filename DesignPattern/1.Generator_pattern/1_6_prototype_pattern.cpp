#include<iostream>
#include <memory>
#include <string>

class Hello
{
private:
	std::string msg;

public:
	Hello(std::string msg)
	{
		std::cout << "Hello�� �����մϴ�" << std::endl;
		this->msg = msg;
	}

	void setMessage(std::string msg)
	{
		this->msg = msg;
	}

	std::string getMessage()
	{
		return this->msg;
	}

	std::shared_ptr<Hello> clone()
	{
		return std::make_shared<Hello>(*this);
	}
};

int main()
{
	auto hello = std::make_shared<Hello>("�ȳ��ϼ���");
	std::cout << "���� ���� : " << hello->getMessage() << std::endl;

	auto hello2 = hello->clone();
	hello2->setMessage("Hello world");
	std::cout << "���� ���� : " << hello2->getMessage() << std::endl;
}