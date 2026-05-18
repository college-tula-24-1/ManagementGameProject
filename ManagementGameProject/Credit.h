#pragma once
#include "Money.h"

class Credit
{
	Money amount;
	int period;

public:
	Credit(Money amount, int period);
	
	int Period() const;
	bool PeriodDec();
	Money Amount() const;
	Money Percent() const;
};

