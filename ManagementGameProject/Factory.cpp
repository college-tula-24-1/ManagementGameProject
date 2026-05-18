#include "Factory.h"

Factory::Factory()
	: built{ true },
	freezingPeriod{ 0 },
	automated{ false }{}

bool Factory::Automated() const
{
	return automated && freezingPeriod == 0;
}

int Factory::FreezingPeriod() const
{
	return freezingPeriod;
}

bool Factory::FreezingPeriodDec()
{
	return --freezingPeriod > 0;
}

void Factory::SetAutomated()
{
	if (built && !automated)
	{
		automated = true;
		freezingPeriod = 9;
	}
}

FactoryBuilder::FactoryBuilder()
	: factory{ new Factory() }{}

FactoryBuilder* FactoryBuilder::Set()
{
	factory = new Factory();
	return this;
}

FactoryBuilder* FactoryBuilder::Built(bool built)
{
	factory->built = built;
	return this;
}

FactoryBuilder* FactoryBuilder::Auotmated(bool automated)
{
	factory->automated = automated;
	return this;
}

FactoryBuilder* FactoryBuilder::Period(int period)
{
	factory->freezingPeriod = period;
	return this;
}

Factory* FactoryBuilder::GetFactory()
{
	return factory;
}

