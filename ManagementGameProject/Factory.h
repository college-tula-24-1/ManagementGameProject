#pragma once
class FactoryBuilder;

class Factory
{
	bool automated;
	bool built;
	int freezingPeriod;
public:
	Factory();
		
	bool Automated() const;
	int FreezingPeriod() const;

	bool FreezingPeriodDec();
	void SetAutomated();

	friend class FactoryBuilder;
};

class FactoryBuilder
{
	Factory* factory;
public:
	FactoryBuilder();

	FactoryBuilder* Set();

	FactoryBuilder* Built(bool built = true);
	FactoryBuilder* Auotmated(bool automated = false);
	FactoryBuilder* Period(int period);

	Factory* GetFactory();
};

