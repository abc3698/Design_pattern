#include<iostream>
#include <memory>
#include <string>
#include <stack>

class Hello
{
private:
	std::string message;

public:
	Hello(std::string msg) : message(msg) {}

	void setMessage(std::string msg) { message = msg; }

	std::string getMessage() const { return message; }

};

class Memento
{
protected:
	std::shared_ptr<Hello> obj;

public:
	Memento(std::shared_ptr<Hello> obj) : obj(obj)
	{

	}

	std::shared_ptr<Hello> getObject() const
	{
		return obj;
	}
};

class Originator
{
protected:
	std::shared_ptr<Hello> state;

public:
	std::shared_ptr<Memento> create()
	{
		std::cout << ">메멘토 객체를 생성합니다." << std::endl;
		return std::make_shared<Memento>(state);
	}

	void restore(std::shared_ptr<Memento> memento)
	{
		std::cout << ">메멘토 객체를 복원합니다." << std::endl;
		state = memento->getObject();
	}

	std::shared_ptr<Hello> getState() const
	{
		return state;
	}

	void setState(std::shared_ptr<Hello> state)
	{
		this->state = std::make_shared<Hello>(*state);
	}
};

class CareTaker
{
protected:
	std::stack<std::shared_ptr<Memento>> stack;

public:
	void push(std::shared_ptr<Originator> originator)
	{
		stack.push(originator->create());
	}

	std::shared_ptr<Hello> undo(std::shared_ptr<Originator> originator)
	{
		if (stack.empty())
			return nullptr;
		
		auto memento = stack.top();
		stack.pop();

		originator->restore(memento);

		return originator->getState();
	}
};


int main()
{
	/* Originator 코드 예시 */
	/*auto origin = std::make_shared<Originator>();

	auto obj = std::make_shared<Hello>("상태1 : 안녕하세요");
	std::cout << obj->getMessage() << std::endl;

	origin->setState(obj);
	auto memento = origin->create();

	obj->setMessage("상태2 : Hello nice meet you");
	std::cout << obj->getMessage() << std::endl;

	origin->restore(memento);
	obj = origin->getState();
	std::cout << obj->getMessage() << std::endl;*/

	/* Caretaker 코드 예시 */

	auto origin = std::make_shared<Originator>();
	auto care = std::make_shared<CareTaker>();

	auto obj = std::make_shared<Hello>("상태1 : 안녕하세요");
	std::cout << obj->getMessage() << std::endl;
	origin->setState(obj);
	care->push(origin);

	obj->setMessage("상태2 : Hello nice meet you");
	std::cout << obj->getMessage() << std::endl;
	origin->setState(obj);
	care->push(origin);

	obj->setMessage("상태3 : Guten Tag");
	std::cout << obj->getMessage() << std::endl;
	origin->setState(obj);
	care->push(origin);

	obj = care->undo(origin);
	std::cout << obj->getMessage() << std::endl;

	obj = care->undo(origin);
	std::cout << obj->getMessage() << std::endl;

	obj = care->undo(origin);
	std::cout << obj->getMessage() << std::endl;
	return 0;
}