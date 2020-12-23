#include <iostream>
#include <string>
#include <memory>
#include <vector>

class Fruit
{
public:
	std::string name;

public:
	Fruit(std::string name)
	{
		this->name = name;
	}
	std::string getName()
	{
		return this->name;
	}
};

template <typename T, typename U>
class Iterator {
private:
	typedef typename std::vector<T>::iterator iter_type;
	U* aggregate;
	iter_type it;

public:
	Iterator(U* p_data) : aggregate(p_data) {
		it = aggregate->m_data.begin();
	}

	void first()
	{
		it = aggregate->m_data.begin();
	}

	bool isNext() {
		if (it == aggregate->m_data.end())
			return false;
		else
			return true;
	}

	T next()
	{		
		T obj = *it;		
		it++;
		return obj;
	}
};

template <typename T>
class Collection {	
	friend class Iterator<std::shared_ptr<T>, Collection>;
private:
	std::vector<std::shared_ptr<T>> m_data;

public:
	void Add(std::shared_ptr<T> obj) 
	{
		m_data.push_back(obj);
	}

	std::shared_ptr<Iterator<std::shared_ptr<T>, Collection>> iterator()
	{
		return std::make_shared<Iterator<std::shared_ptr<T>, Collection>>(this);
	}
};

int main()
{
	Collection<Fruit> collect;

	collect.Add(std::make_shared<Fruit>("A"));
	collect.Add(std::make_shared<Fruit>("B"));
	collect.Add(std::make_shared<Fruit>("C"));

	auto it = collect.iterator();

	while (it->isNext())
	{
		auto item = it->next();
		std::cout << item->getName() << std::endl;
	}

	std::cout << std::endl;

	collect.Add(std::make_shared<Fruit>("D"));
	it->first();

	while (it->isNext())
	{
		auto item = it->next();
		std::cout << item->getName() << std::endl;
	}
}