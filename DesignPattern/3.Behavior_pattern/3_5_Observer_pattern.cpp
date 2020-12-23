#include <iostream>
#include <string>
#include <memory>
#include <vector>

/*Observer class*/
class Observer
{
protected:
	std::string name;

public:
	Observer(std::string name) : name(name) {}
	std::string getName() { return name; }
	virtual void update() = 0;
};

/*Concrete Observer class*/
class UserA : public Observer
{
public:
	UserA(std::string name) : Observer(name)
	{
		std::cout << "UserA 객체를 생성합니다." << std::endl;
	}

	void update()
	{
		std::cout << name << " 갱신합니다." << std::endl;
	}
};

/*Concrete Observer class*/
class UserB : public Observer
{
public:
	UserB(std::string name) : Observer(name)
	{
		std::cout << "UserB 객체를 생성합니다." << std::endl;
	}

	void update()
	{
		std::cout << name << " 갱신합니다." << std::endl;
	}
};

/*Subject class*/
__interface Subject
{
public:
	virtual void addObserver(std::shared_ptr<Observer> o) = 0;
	virtual void deleteObserver(std::shared_ptr<Observer> o) = 0;
	virtual void notiObserver() = 0;
};

/*Concrete Subject class*/
class Members : public Subject
{
private:
	std::vector<std::shared_ptr<Observer>> objs;

public:
	Members()
	{
		std::cout << "Concrete Subject 객체를 생성합니다." << std::endl;
	}

	void addObserver(std::shared_ptr<Observer> o)
	{
		std::cout << "감시자 객체를 추가합니다." << std::endl;
		objs.push_back(o);
	}

	void deleteObserver(std::shared_ptr<Observer> o)
	{
		int idx = 0;
		bool isDelete = false;
		for (auto& po : objs)
		{
			if (po->getName() == o->getName())
			{
				isDelete = true;
				break;
			}
			++idx;
		}

		if (isDelete)
			objs.erase(objs.begin() + idx);
	}

	void notiObserver()
	{
		for (auto& po : objs)
		{
			std::cout << "감시자=> ";
			po->update();
		}
	}
};

int main()
{
	std::cout << "감시자 패턴을 실행합니다." << std::endl;

	auto subject = std::make_shared<Members>();

	auto a = std::make_shared<UserA>("Jiny");
	auto b = std::make_shared<UserB>("Eric");

	subject->addObserver(a);
	subject->addObserver(b);

	subject->notiObserver();

	return 0;
}