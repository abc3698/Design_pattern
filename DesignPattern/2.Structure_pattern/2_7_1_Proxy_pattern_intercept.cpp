#include<iostream>
#include <memory>
#include <string>

const int ACT = 0x02;

__interface Subject
{
public:
	virtual void action() = 0;
};

class RealSubject : public Subject
{
public:
	RealSubject()
	{
		std::cout << "RealSubject 객체를 생성합니다." << std::endl;
	}

	void action()
	{
		std::cout << "RealSubject::action을 호출합니다." << std::endl;
		std::cout << "실제 action 작업을 처리합니다." << std::endl << std::endl;
	}
};

class Proxy : public Subject
{
private:
	std::shared_ptr<Subject> _object;
	int _permit;
private:
	void real()
	{
		std::cout << "실제 객체를 생성합니다." << std::endl;
		_object = std::make_shared<RealSubject>();
	}

public:
	Proxy(int permit)
	{
		std::cout << "Proxy 객체를 생성합니다." << std::endl << std::endl;		
		this->_permit = permit;
	}	

	void action()
	{
		std::cout << "Proxy::action을 호출합니다." << std::endl;		
		if (this->_permit & 0x02)
		{
			// 개으른 객체 생성
			if (!_object) this->real();
			_object->action();
		}
		else
		{
			std::cout << "action 실행 권한이 없습니다." << std::endl;
		}		
	}
};

int main()
{
	auto proxy = std::make_shared<Proxy>(0x01);	
	proxy->action();	

	proxy = std::make_shared<Proxy>(0x02);
	proxy->action();
	return 0;
}