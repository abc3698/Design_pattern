#include <iostream>
#include <string>
#include <memory>

class Language {
public:
    virtual std::string text() = 0;
};

class Factory
{
protected:
    virtual std::shared_ptr<Language>  factory() = 0;
public:
    virtual std::shared_ptr<Language> getInstance()
    {
        return factory();
    }
};

class Korea : public Language
{
    public:
        std::string text() override
        {
            std::string str = "안녕하세요";
            return str;
        }
};

class English : public Language
{
public:
    std::string text() override
    {
        std::string str = "Hello";
        return str;
    }
};

class KoreaFactory final : public Factory {
protected:
    virtual std::shared_ptr<Language> factory()
    {
        return std::make_shared<Korea>();
    }
};

class EnglishFactory final : public Factory {
protected:
    virtual std::shared_ptr<Language> factory()
    {
        return std::make_shared<English>();
    }
};

class Hello
{
public:    
    std::string greeting(std::string type)
    {
        std::shared_ptr<Factory> factory;
        if (type == "korea")
        {
            factory = std::make_shared<KoreaFactory>();
        }
        else
        {
            factory = std::make_shared<EnglishFactory>();
        }        

        auto language = factory->getInstance();
        std::string str = language->text();
                
        return str;
    }
};

int main()
{
    Hello hello;
    std::cout << hello.greeting("eng") << std::endl;
}