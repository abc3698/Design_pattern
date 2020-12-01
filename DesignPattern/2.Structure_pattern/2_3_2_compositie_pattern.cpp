#include<iostream>
#include <memory>
#include <string>
#include <map>
class Component
{
private:
	std::string name;

public:
	virtual ~Component() = default;

	std::string getName()
	{
		return name;
	}

	void setName(std::string name)
	{
		this->name = name;
	}
};

class Leaf : public Component
{
private:
	std::string data;

public:
	Leaf(std::string name)
	{
		this->setName(name);
	}

	std::string getData()
	{
		return data;
	}

	void setData(std::string data)
	{
		this->data = data;
	}
};

class Composite : public Component
{
public:
	std::map<std::string, std::shared_ptr<Component>> child;

public:
	Composite(std::string name)
	{
		this->setName(name);
	}

	void addNode(std::shared_ptr<Component> folder)
	{
		auto str = folder->getName();
		child.insert(std::make_pair(str, folder));
	}

	void removeNode(std::shared_ptr<Component> folder)
	{
		auto str = folder->getName();
		child.erase(str);
	}

	bool isNode()
	{
		return child.empty();
	}
};

void tree(std::shared_ptr<Composite>& com)
{
	auto arr = com->child;

	for (auto key : arr)
	{
		if (typeid(*key.second.get()) == typeid(Composite))
		{
			std::cout << "Folder = " << key.first;

			auto temp = std::static_pointer_cast<Composite>(key.second);
			if (!temp->isNode())
			{
				std::cout << std::endl;
				tree(temp);
			}
			else
			{
				std::cout << "... 노드 없음" << std::endl;
			}
		}
		else if (typeid(*key.second.get()) == typeid(Leaf))
		{
			std::cout << "\tFile = " << key.first << std::endl;
		}
		else
		{
			std::cout << "??" << std::endl;
		}
	}
}

int main()
{
	auto root = std::make_shared<Composite>("root");
	auto home = std::make_shared<Composite>("home");
	auto hojin = std::make_shared<Composite>("hojin");
	auto jiny = std::make_shared<Composite>("jiny");
	auto user = std::make_shared<Composite>("user");
	auto temp = std::make_shared<Composite>("temp");

	auto img1 = std::make_shared<Leaf>("img1");
	auto img2 = std::make_shared<Leaf>("img2");
	auto img3 = std::make_shared<Leaf>("img3");
	auto img4 = std::make_shared<Leaf>("img4");

	root->addNode(home);
	root->addNode(user);

	{
		user->addNode(hojin);
		{
			hojin->addNode(img1);
			hojin->addNode(img2);
			hojin->addNode(img3);
			hojin->addNode(img4);
		}
		user->addNode(jiny);
	}
	root->addNode(temp);

	tree(root);
}