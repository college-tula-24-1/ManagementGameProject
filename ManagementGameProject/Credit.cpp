#include "Credit.h"

Credit::Credit(Money amount, int period)
	: amount{ amount },
	period{ period }{}

int Credit::Period() const
{
	return period;
}

bool Credit::PeriodDec()
{
	return --period > 0;
}

Money Credit::Amount() const
{
	return amount;
}

Money Credit::Percent() const
{
	return amount % 1;
}

