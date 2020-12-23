#include<iostream>
#include <memory>
#include <string>

__interface LightState
{
	virtual std::shared_ptr<LightState> lightOn() = 0;
	virtual std::shared_ptr<LightState> lightOff() = 0;
	virtual bool lightState() = 0;
};

class LightLamp : public LightState
{
private:
	bool lightstate = false;

public:
	LightLamp()
	{
		std::cout << "LightLamp 객체를 생성합니다." << std::endl;
	}

	std::shared_ptr<LightState> lightOn()
	{
		std::cout << "전구를 On 합니다" << std::endl;
		lightstate = true;

		return std::make_shared<LightLamp>(*this);
	}

	std::shared_ptr<LightState> lightOff()
	{
		std::cout << "전구를 Off 합니다" << std::endl;
		lightstate = false;

		return std::make_shared<LightLamp>(*this);
	}

	bool lightState()
	{
		return lightstate;
	}
};

int main()
{
	auto obj = std::make_shared<LightLamp>();

	std::cout << obj->lightOn()->lightState() << std::endl;
	std::cout << obj->lightOff()->lightState() << std::endl;

	std::cout << obj->lightOn()->lightState() << std::endl;
	std::cout << obj->lightOn()->lightState() << std::endl;
	return 0;
}