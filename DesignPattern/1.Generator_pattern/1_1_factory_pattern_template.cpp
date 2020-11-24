#include <iostream>
#include <string>
#include <memory>

class Language {
public:
    virtual std::string text() = 0;
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

template <typename T>
class Factory
{
protected:
    virtual std::shared_ptr<T> factory() = 0;
public:
    virtual std::shared_ptr<T> getInstance()
    {
        return factory();
    }
};

template <typename T1, typename T2>
class LanguageFactory final : public Factory<T1> {
protected:
    virtual std::shared_ptr<T1> factory() override
    {
        return std::make_shared<T2>();
    }
};


class Hello
{
public:
    std::string greeting(std::string type)
    {
        std::shared_ptr<Factory<Language>> factory;
        if (type == "korea")
        {
            factory = std::make_shared<LanguageFactory<Language, Korea>>();
        }
        else
        {
            factory = std::make_shared<LanguageFactory<Language, English>>();
        }

        auto language = factory->getInstance();
        std::string str = language->text();

        return str;
    }
};

int main()
{
    Hello hello;
    std::cout << hello.greeting("english") << std::endl;
}