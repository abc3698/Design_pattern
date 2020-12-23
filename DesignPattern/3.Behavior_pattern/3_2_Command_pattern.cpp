#include <iostream>
#include <string>
#include <memory>
#include <map>

__interface Command
{
public:
	virtual void execute() = 0;
};

class Exe1 : public Command
{
public:
	Exe1()
	{
		std::cout << "Exe1 객체를 생성합니다" << std::endl;
	}

	void execute()
	{
		std::cout << "명령 1을 실행합니다" << std::endl;
	}
};

class Concrete
{
public:
	void action1()
	{
		std::cout << "동작1 : 안녕하세요" << std::endl;
	}

	void action2()
	{
		std::cout << "동작2 : 즐거운 시간 되세요" << std::endl;
	}
};

class Exe2 : public Command
{
private:
	std::shared_ptr<Concrete> receiver;

public:
	Exe2(std::shared_ptr<Concrete> receiver)
	{
		std::cout << "Exe2 객체를 생성합니다" << std::endl;
		// 객촌 의존성 주입
		this->receiver = receiver;
	}

	void execute()
	{
		std::cout << "명령 2을 실행합니다" << std::endl;
		receiver->action1();
		receiver->action2();
	}
};

class Invoker
{
public:
	std::map<std::string, std::shared_ptr<Command>> cmd;

public:
	void setCommand(std::string key, std::shared_ptr<Command> command)
	{
		cmd.insert(std::make_pair(key, command));
	}

	void remove(std::string key)
	{
		auto it = cmd.find(key);
		if (it == cmd.end())
		{
			std::cout << "Wrong Key" << std::endl;
			return;
		}
		cmd.erase(it);
	}

	void execute(std::string key)
	{
		auto it = cmd.find(key);
		if (it == cmd.end())
		{
			std::cout << "Wrong Key" << std::endl;
			return;
		}
		cmd[key]->execute();
	}
};

int main()
{
	auto invoker = std::make_shared<Invoker>();	

	invoker->setCommand("cmd", []()->std::shared_ptr<Command>
		{
			class labmad_command : public Command
			{
				void execute()
				{
					std::cout << "명령을 실행합니다" << std::endl;					
				}
			};
			return std::make_shared<labmad_command>();
		}());

	invoker->execute("cmd");

	/*auto exe1 = std::make_shared<Exe1>();
	auto receiver = std::make_shared<Concrete>();
	auto exe2 = std::make_shared<Exe2>(receiver);


	auto invoker = std::make_shared<Invoker>();
	invoker->setCommand("cmd1", exe1);
	invoker->setCommand("cmd2", exe2);

	invoker->execute("cmd1");
	invoker->execute("cmd2");*/
}