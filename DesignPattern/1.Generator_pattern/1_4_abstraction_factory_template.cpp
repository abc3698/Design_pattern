﻿#include <iostream>
#include <string>
#include <memory>

class TireProdct
{
public:
	virtual void makeAssemble() = 0;
};

class DoorProdct
{
public:
	virtual void makeAssemble() = 0;
};

template<typename T1, typename T2>
class Factory
{
public:
	virtual std::shared_ptr<T1> createTire() = 0;
	virtual std::shared_ptr<T2> createDoor() = 0;
};

class StateTireProdct : public TireProdct
{
public:
	StateTireProdct()
	{
		std::cout << "StateTireProdct를 생성합니다" << std::endl;
	}

	void makeAssemble()
	{
		std::cout << "메소드 호촐 StateTireProdct - makeAssemble" << std::endl;
		std::cout << "미국형 타이어 장착" << std::endl;
	}
};

class StateDoorProdct : public DoorProdct
{
public:
	StateDoorProdct()
	{
		std::cout << "StateDoorProdct를 생성합니다" << std::endl;
	}

	void makeAssemble()
	{
		std::cout << "메소드 호촐 StateDoorProdct - makeAssemble" << std::endl;
		std::cout << "미국형 도어 장착" << std::endl;
	}
};

template<typename T1, typename T2>
class StateFactory : public Factory<T1, T2>
{
public:
	StateFactory()
	{
		std::cout << "StateFactory를 생성합니다" << std::endl;
	}

	std::shared_ptr<T1> createTire()
	{
		return std::make_shared<StateTireProdct>();
	}

	std::shared_ptr<T2> createDoor()
	{
		return std::make_shared<StateDoorProdct>();
	}
};

class KoreaTireProdct : public TireProdct
{
public:
	KoreaTireProdct()
	{
		std::cout << "KoreaTireProdct를 생성합니다" << std::endl;
	}

	void makeAssemble()
	{
		std::cout << "메소드 호촐 KoreaTireProdct - makeAssemble" << std::endl;
		std::cout << "한국형 타이어 장착" << std::endl;
	}
};

class KoreaDoorProdct : public DoorProdct
{
public:
	KoreaDoorProdct()
	{
		std::cout << "KoreaDoorProdct를 생성합니다" << std::endl;
	}

	void makeAssemble()
	{
		std::cout << "메소드 호촐 KoreaDoorProdct - makeAssemble" << std::endl;
		std::cout << "한국형 도어 장착" << std::endl;
	}
};

template<typename T1, typename T2>
class KoreaFactory : public Factory<T1, T2>
{
public:
	KoreaFactory()
	{
		std::cout << "KoreaFactory를 생성합니다" << std::endl;
	}

	std::shared_ptr<T1> createTire()
	{
		return std::make_shared<KoreaTireProdct>();
	}

	std::shared_ptr<T2> createDoor()
	{
		return std::make_shared<KoreaDoorProdct>();
	}
};

int main()
{
	auto korea = std::make_shared<KoreaFactory<TireProdct, DoorProdct>>();
	auto ham = korea->createTire();
	ham->makeAssemble();

	auto bread = korea->createDoor();
	bread->makeAssemble();

	std::cout << std::endl;

	auto state = std::make_shared<StateFactory<TireProdct, DoorProdct>>();
	ham = state->createTire();
	ham->makeAssemble();

	bread = state->createDoor();
	bread->makeAssemble();
	return 0;
}