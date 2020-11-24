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
		std::cout << "Hello를 생성합니다" << std::endl;
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
	auto hello = std::make_shared<Hello>("안녕하세요");
	std::cout << "원본 내용 : " << hello->getMessage() << std::endl;

	auto hello2 = hello->clone();
	hello2->setMessage("Hello world");
	std::cout << "수정 내용 : " << hello2->getMessage() << std::endl;
}