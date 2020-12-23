#include <iostream>
#include <string>
#include <memory>
#include <vector>

__interface Colleague;

__interface Mediator
{
public:	
	virtual void addColleague(std::shared_ptr<Colleague> obj) = 0;		
	virtual void mediate(std::string data, std::string user) = 0;

};

__interface Colleague
{
public:
	virtual void setMediator(std::shared_ptr<Mediator> mediator) = 0;
};

class User : public Colleague
{
protected:
	std::shared_ptr<Mediator> mediator;
	std::string name;

public:
	User(std::string name) : name(name)
	{
		std::cout << "Colleague가 등재되었습니다" << std::endl;
	}	

	std::string userName()
	{
		return name;
	}

	void send(std::string data)
	{
		mediator->mediate(data, this->name);
	}

	void setMediator(std::shared_ptr<Mediator> mediator)
	{
		this->mediator = mediator;
	}

	void message(std::string data)
	{
		std::cout << data << std::endl;
	}
};

class Server : public Mediator
{
protected:
	std::vector< std::shared_ptr<Colleague>> colleagues;

public:
	Server()
	{
		std::cout << "중재자 생성이 되었습니다" << std::endl;
	}

	void addColleague(std::shared_ptr<Colleague> obj)
	{
		colleagues.push_back(obj);
	}

	void mediate(std::string data, std::string user)
	{
		std::cout << ">> " + user + "로부터 서버 메시지를 받았습니다." << std::endl;

		for (auto& o : colleagues)
		{
			auto user = std::static_pointer_cast<User>(o);
			std::cout << "<< " + user->userName() << " : ";
			user->message(data);
		}
	}
};

int main()
{
	auto mediator = std::make_shared<Server>();

	auto user1 = std::make_shared<User>("James");
	user1->setMediator(mediator);
	mediator->addColleague(user1);

	auto user2 = std::make_shared<User>("Jiny");
	user2->setMediator(mediator);
	mediator->addColleague(user2);

	auto user3 = std::make_shared<User>("eric");
	user3->setMediator(mediator);
	mediator->addColleague(user3);

	user1->send("안녕하세요, 저는 james 입니다.");
	std::cout << std::endl;

	user2->send("안녕하세요, 저는 Jiny 입니다.");
	std::cout << std::endl;

	user3->send("안녕하세요, 저는 eric 입니다.");
	std::cout << std::endl;
}



