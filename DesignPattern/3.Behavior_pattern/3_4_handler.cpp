#include <iostream>
#include <string>
#include <memory>

class Chain
{
protected:
	std::shared_ptr<Chain> next;

public:
	void setNext(std::shared_ptr<Chain> obj)
	{
		next = obj;
	}

	virtual std::string execute(std::string event) = 0;
};

class Order : public Chain
{
public:
	std::string execute(std::string event)
	{
		if (event == "order")
		{			
			return "주문을 처리합니다.";
		}

		if(this->next == nullptr)
			return "동작이 없습니다.";

		return this->next->execute(event);
	}

};

class Cancel : public Chain
{
public:
	std::string execute(std::string event)
	{
		if (event == "cancel")
		{
			return "주문을 취소합니다.";
		}

		if (this->next == nullptr)
			return "동작이 없습니다.";

		return this->next->execute(event);
	}	
};

class Handler
{
public:
	std::string event(std::string msg)
	{
		auto first = std::make_shared<Order>();

		first->setNext(std::make_shared<Cancel>());

		return first->execute(msg);
	}
};

int main()
{
	auto handler = std::make_shared<Handler>();
	std::cout << handler->event("caancel") << std::endl;
}