#include <iostream>
#include <string>
#include <memory>
#include <map>

__interface State
{
public:
	virtual void process() = 0;
};

class StateOrder : public State
{
public:
	void process() { std::cout << "주문" << std::endl; }
};

class StatePay : public State
{
public:
	void process() { std::cout << "결제중" << std::endl; }
};

class StateOrdered : public State
{
public:
	void process() { std::cout << "주문완료" << std::endl; }
};

class StateFinish : public State
{
public:
	void process() { std::cout << "처리완료" << std::endl; }
};

class JinyOrder
{
private:
	std::map<std::string, std::shared_ptr<State>> state;

public:
	JinyOrder()
	{
		state.insert(std::make_pair("ORDER", std::make_shared<StateOrder>()));
		state.insert(std::make_pair("PAY", std::make_shared<StatePay>()));
		state.insert(std::make_pair("ORDERED", std::make_shared<StateOrdered>()));
		state.insert(std::make_pair("FINISH", std::make_shared<StateFinish>()));
	}

	void process(std::string status)
	{
		state[status]->process();
	}
};

int main()
{
	auto obj = std::make_shared<JinyOrder>();
	obj->process("ORDERED");
}