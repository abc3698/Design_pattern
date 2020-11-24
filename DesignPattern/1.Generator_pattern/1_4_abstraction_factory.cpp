#include <iostream>
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

class Factory
{
public:
	virtual std::shared_ptr<TireProdct> createTire() = 0;
	virtual std::shared_ptr<DoorProdct> createDoor() = 0;
};

class StateTireProdct : public TireProdct
{
public:
	StateTireProdct()
	{
		std::cout << "StateTireProdct�� �����մϴ�" << std::endl;
	}

	void makeAssemble()
	{
		std::cout << "�޼ҵ� ȣ�� StateTireProdct - makeAssemble" << std::endl;
		std::cout << "�̱��� Ÿ�̾� ����" << std::endl;
	}
};

class StateDoorProdct : public DoorProdct
{
public:
	StateDoorProdct()
	{
		std::cout << "StateDoorProdct�� �����մϴ�" << std::endl;
	}

	void makeAssemble()
	{
		std::cout << "�޼ҵ� ȣ�� StateDoorProdct - makeAssemble" << std::endl;
		std::cout << "�̱��� ���� ����" << std::endl;
	}
};

class StateFactory : public Factory
{
public:
	StateFactory()
	{
		std::cout << "StateFactory�� �����մϴ�" << std::endl;
	}

	std::shared_ptr<TireProdct> createTire()
	{
		return std::make_shared<StateTireProdct>();
	}

	std::shared_ptr<DoorProdct> createDoor()
	{
		return std::make_shared<StateDoorProdct>();
	}
};

class KoreaTireProdct : public TireProdct
{
public:
	KoreaTireProdct()
	{
		std::cout << "KoreaTireProdct�� �����մϴ�" << std::endl;
	}

	void makeAssemble()
	{
		std::cout << "�޼ҵ� ȣ�� KoreaTireProdct - makeAssemble" << std::endl;
		std::cout << "�ѱ��� Ÿ�̾� ����" << std::endl;
	}
};

class KoreaDoorProdct : public DoorProdct
{
public:
	KoreaDoorProdct()
	{
		std::cout << "KoreaDoorProdct�� �����մϴ�" << std::endl;
	}

	void makeAssemble()
	{
		std::cout << "�޼ҵ� ȣ�� KoreaDoorProdct - makeAssemble" << std::endl;
		std::cout << "�ѱ��� ���� ����" << std::endl;
	}
};

class KoreaFactory : public Factory
{
public:
	KoreaFactory()
	{
		std::cout << "KoreaFactory�� �����մϴ�" << std::endl;
	}

	std::shared_ptr<TireProdct> createTire()
	{
		return std::make_shared<KoreaTireProdct>();
	}

	std::shared_ptr<DoorProdct> createDoor()
	{
		return std::make_shared<KoreaDoorProdct>();
	}
};

int main()
{
	auto korea = std::make_shared<KoreaFactory>();
	auto ham = korea->createTire();
	ham->makeAssemble();

	auto bread = korea->createDoor();
	bread->makeAssemble();

	std::cout << std::endl;

	auto state = std::make_shared<StateFactory>();
	ham = state->createTire();
	ham->makeAssemble();

	bread = state->createDoor();
	bread->makeAssemble();
	return 0;
}