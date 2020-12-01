#include<iostream>
#include <memory>
#include <string>
#include <vector>
class Disk
{
public:
	std::string name = "디스크";
};

class Memory
{
public:
	std::string name = "메모리";
};

class Monitor32
{
public:
	std::string name = "32인치";
};

class Monitor
{
public:
	std::vector<std::shared_ptr<Monitor32>> screen;
	std::string name = "모니터";

public:
	void addMonitor(std::shared_ptr<Monitor32> monitor)
	{
		screen.push_back(monitor);
	}

	void show()
	{
		for (auto s : screen)
		{
			std::string n = ">>" + s->name;
			std::cout << n << std::endl;
		}
	}
};

class Computer
{
public:
	std::shared_ptr<Monitor> monitor;	
	std::shared_ptr<Disk> disk;
	std::shared_ptr<Memory> memory;

	std::string name = "구성";

public:
	void setMonitor(std::shared_ptr<Monitor> monitor)
	{
		this->monitor = monitor;
	}

	void setDisk(std::shared_ptr<Disk> disk)
	{
		this->disk = disk;
	}

	void setMemory(std::shared_ptr<Memory> memory)
	{
		this->memory = memory;
	}
};

int main()
{
	auto obj = std::make_shared<Computer>();
	obj->setMonitor(std::make_shared<Monitor>());
	obj->monitor->addMonitor(std::make_shared<Monitor32>());
	obj->monitor->addMonitor(std::make_shared<Monitor32>());

	obj->setDisk(std::make_shared<Disk>());
	obj->setMemory(std::make_shared<Memory>());

	std::cout << obj->name << std::endl;
	std::cout << obj->monitor->name << std::endl;
	obj->monitor->show();
	std::cout << obj->disk->name << std::endl;
	std::cout << obj->memory->name << std::endl;
	return 0;
}