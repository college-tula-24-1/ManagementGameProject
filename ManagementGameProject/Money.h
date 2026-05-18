#pragma once
#include <string>

class Money
{
	int dollars;
	int cents;

	void Reduce();

public:
	Money();
	Money(int dollars, int cents);

	int Dollars();
	int Cents();

	Money Add(Money money);
	Money Add(int dollars);

	friend Money operator+(Money left, Money right);
	friend Money operator+(Money money, int dollars);

	void operator+=(Money money);
	void operator+=(int dollars);

	friend Money operator-(Money left, Money right);
	friend Money operator-(Money money, int dollars);

	void operator-=(Money money);
	void operator-=(int dollars);

	friend Money operator*(Money money, int count);
	friend Money operator/(Money money, int count);
	friend Money operator%(Money money, int percent);

	friend bool operator<(Money left, Money right);
	friend bool operator<=(Money left, Money right);
	friend bool operator>(Money left, Money right);
	friend bool operator>=(Money left, Money right);
	friend bool operator==(Money left, Money right);
	friend bool operator!=(Money left, Money right);

	std::string ToString();
};


