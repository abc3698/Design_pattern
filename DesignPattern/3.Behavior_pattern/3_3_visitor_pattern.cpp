#include <iostream>
#include <string>
#include <memory>
#include <vector>
#include<algorithm>
class Product;

class Visitor
{
public:
    virtual std::string order(std::shared_ptr<Product> visitable) = 0;
};

class Product
{
protected:
    std::string name;
    int price;
    int num;

    Product(std::string name, int price, int num = 1)
        : name(name), price(price), num(num)
    {

    }

public:
    void setName(std::string name)
    {
        this->name = name;
    }

    std::string getName() const
    {
        return this->name;
    }

    void setPrice(int price)
    {
        this->price = price;
    }

    int getPrice() const
    {
        return this->price;
    }

    void setNum(int num)
    {
        this->num = num;
    }

    int getNum() const
    {
        return this->num;
    }

    float getTax(const int tax = 10)
    {
        return (price * num) * (float)tax / 100;
    }

    virtual std::string accept(std::shared_ptr<Visitor> visitor) = 0;
};

class Cart : public Product
{
public:
    Cart(std::string name, int price, int num = 1)
        : Product(name, price, num)
    {

    }

    std::string list()
    {
        std::string order = this->name + ", 수량=" + std::to_string(this->num) + ", 가격=" \
            + std::to_string(this->num * this->price) + " 입니다.";

        return order;
    }

    std::string accept(std::shared_ptr<Visitor> visitor)
    {        
        return visitor->order(std::make_shared<Cart>(*this));
    }
};

class Visitant : public Visitor
{
private:
    int total = 0;
    int num = 0;

public:
    Visitant()
    {
        std::cout << "주문을 처리합니다." << std::endl;
    }

    std::string order(std::shared_ptr<Product> visitable)
    {
        std::cout << "==상품 내역==" << std::endl;        
        if (typeid(*visitable.get()) == typeid(Cart))
        {
            std::string msg = "상품명: " + visitable->getName();
            msg.append(", 수량: " + std::to_string(visitable->getNum()));

            int total = visitable->getPrice() * visitable->getNum();
            msg.append(", 가격: " + std::to_string(total) + " 입니다\n");

            this->total += total;
            msg.append("합계: " + std::to_string(this->total));

            ++num;
            return msg;
        }
    }

    int getToal()
    {
        return total;
    }

    int getNum()
    {
        return num;
    }
};

int main()
{
    /*auto cart = std::make_shared<Cart>("컵라면", 900, 2);
    std::cout << cart->accept(std::make_shared<Visitant>()) << std::endl;*/

    std::vector<std::shared_ptr<Cart>> list{
        std::make_shared<Cart>("컵라면", 900, 3),
        std::make_shared<Cart>("아이스크림", 1500, 1),
        std::make_shared<Cart>("음료수", 2800, 1)
    };

    auto visitant = std::make_shared<Visitant>();
    
    std::for_each(list.begin(), list.end(), [&visitant](auto p)
    {
        std::cout << p->accept(visitant2) << std::endl;
    });

    std::cout << std::endl << std::endl;

    std::cout << "감사합니다. 주문건수: " + std::to_string(visitant->getNum()) << std::endl;
    std::cout << "주문 합계: " + std::to_string(visitant->getToal()) << std::endl;
}