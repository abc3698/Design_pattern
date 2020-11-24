#include<iostream>
#include <memory>
#include <string>

class CPU
{
private:
	std::string vendor;
public:
	CPU(std::string str) : vendor(str) {}

	std::string getVendor()
	{
		return vendor;
	}
};
class Memory
{
private:
	int size = 0;

public:
	Memory(int size = 0)
	{
		if (size > 0)
		{
			this->size = size;
		}
	}

	void setSize(int size)
	{
		this->size = size;
	}

	int getSize()
	{
		return size;
	}
};


class Storage
{
private:
	int size = 0;

public:
	Storage(int size = 0)
	{
		if (size > 0)
		{
			this->size = size;
		}
	}

	void setSize(int size)
	{
		this->size = size;
	}

	int getSize()
	{
		return size;
	}
};

class Computer
{
public:
	std::shared_ptr<CPU> _cpu;
	std::shared_ptr<Memory> _memory;
	std::shared_ptr<Storage> _storage;

public:
	Computer()
	{
		std::cout << "Computer를 생성합니다" << std::endl;
	}

	std::string _toString()
	{
		std::string str1 = "이 컴퓨터의 사양은 CPU = " + this->_cpu->getVendor();
		std::string str2 = ", RAM = " + std::to_string(this->memory()) + ".GB";
		std::string str3 = ", Storage = " + std::to_string(this->storage()) + ".GB 입니다" + "\n";
		
		return str1 + str2 + str3;
	}

	int memory()
	{
		return _memory->getSize();
	}

	int storage()
	{
		return _storage->getSize();
	}
};

class Algorithm
{
protected:
	std::shared_ptr<Computer> _composite;

public:
	virtual void setCpu(std::string str) = 0;
	virtual void setRam(int size) = 0;
	virtual void setStorage(int size) = 0;

	std::shared_ptr<Computer> getInstance()
	{
		return _composite;
	}
};

class ProductModel : public Algorithm
{
public:
	ProductModel()
	{
		std::cout << "ProductModel 객체를 생성합니다" << std::endl;
		_composite = std::make_shared<Computer>();
	}

	void setCpu(std::string str)
	{
		std::cout << "CPU를 설정합니다" << std::endl;		
		_composite->_cpu = std::make_shared<CPU>(str);
	}
	
	void setRam(int size)
	{
		std::cout << "RAM를 설정합니다" << std::endl;
		_composite->_memory = std::make_shared<Memory>(size);
	}
	
	void setStorage(int size)
	{
		std::cout << "Storage를 설정합니다" << std::endl;
		_composite->_storage = std::make_shared<Storage>(size);
	}
};

class Builder
{
protected:
	std::shared_ptr<Algorithm> _algorithm;

public:
	void setAlgorithm(std::shared_ptr<Algorithm> algorithm)
	{
		std::cout << "빌드 객체를 저장합니다" << std::endl;
		_algorithm = algorithm;
	}

	std::shared_ptr<Computer> getInstance()
	{
		return _algorithm->getInstance();
	}

	virtual std::shared_ptr<Builder> build() = 0;
};

class Factory : public Builder
{
public:
	Factory(std::shared_ptr<Algorithm> algorithm)
	{
		std::cout << "Factory 객체를 생성합니다" << std::endl;
		setAlgorithm(algorithm);
	}

	 std::shared_ptr<Builder> build()
	{
		std::cout << "===빌드합니다===" << std::endl;
		_algorithm->setCpu("i7");
		_algorithm->setRam(16);
		_algorithm->setStorage(512);		

		return std::make_shared<Factory>(*this);
	}
};

int main()
{
	auto algorithm = std::make_shared<ProductModel>();
	
	auto factory = std::make_shared<Factory>(algorithm);
	
	auto computer = factory->build()->getInstance();
	std::cout << computer->_toString();
}