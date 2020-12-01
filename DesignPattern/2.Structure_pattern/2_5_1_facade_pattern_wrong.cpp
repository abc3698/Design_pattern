#include<iostream>
#include <memory>
#include <string>

class Thermometer
{
public:
	float temp;

public:
	float getTemperature()
	{
		return temp;
	}
};

class Temperature
{
public:
	std::shared_ptr<Thermometer> station;

private:
	std::shared_ptr<Thermometer> getThermometer()
	{
		return station;
	}

public:
	Temperature(std::shared_ptr<Thermometer> station)
	{
		this->station = station;
	}

	float getTemp()
	{		
		return this->station->getTemperature();
	}
};