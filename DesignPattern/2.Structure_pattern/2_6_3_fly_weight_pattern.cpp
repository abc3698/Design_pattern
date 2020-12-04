#include<iostream>
#include <memory>
#include <string>
#include <map>

__interface flyweight
{
public:
	virtual void code() = 0;
};

class MorseG : public flyweight
{
public:
	MorseG()
	{
		std::cout << "MorseG 객체를 생성합니다." << std::endl;
	}

	void code()
	{
		std::cout << "*";
		std::cout << "*";
		std::cout << "-";
		std::cout << "*";

		std::cout << " ";
	}
};

class MorseO : public flyweight
{
public:
	MorseO()
	{
		std::cout << "MorseO 객체를 생성합니다." << std::endl;
	}

	void code()
	{
		std::cout << "-";
		std::cout << "-";
		std::cout << "-";		

		std::cout << " ";
	}
};

class MorseL : public flyweight
{
public:
	MorseL()
	{
		std::cout << "MorseL 객체를 생성합니다." << std::endl;
	}

	void code()
	{
		std::cout << "*";
		std::cout << "-";
		std::cout << "*";		
		std::cout << "*";

		std::cout << " ";
	}
};

class MorseE : public flyweight
{
public:
	MorseE()
	{
		std::cout << "MorseE 객체를 생성합니다." << std::endl;
	}

	void code()
	{
		std::cout << "*";

		std::cout << " ";
	}
};

class Factory
{
private:
	// 공유 메모리
	std::map<char, std::shared_ptr<flyweight>> pool;

public:
	std::shared_ptr<flyweight> getCode(char ch)
	{
		ch = toupper(ch);
		if (pool.find(ch) == pool.end())
		{
			switch(ch)
			{
			case 'G':
				pool.insert(std::make_pair(ch, std::make_shared<MorseG>()));
				break;

			case 'O':
				pool.insert(std::make_pair(ch, std::make_shared<MorseO>()));
				break;

			case 'L':
				pool.insert(std::make_pair(ch, std::make_shared<MorseL>()));
				break;

			case 'E':
				pool.insert(std::make_pair(ch, std::make_shared<MorseE>()));
				break;
			}			
		}
		
		return pool[ch];
	}
};

int main()
{
	auto share = std::make_shared<Factory>();

	std::string name = "goooogllleee";
	std::cout << "원본 이름 = " << name << std::endl;

	for (int i = 0; i < name.size(); ++i)
	{
		std::cout << name[i] << "=> ";
		share->getCode(name[i])->code();
		std::cout << std::endl;
	}

	return 0;
}