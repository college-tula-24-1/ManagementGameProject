#include "Money.h"

void Money::Reduce()
{
	dollars += cents / 100;
	cents = cents % 100;
}

Money::Money() : Money(0, 0) {}

Money::Money(int dollars, int cents)
	: dollars{ dollars }, cents{ cents } { Reduce(); }

int Money::Dollars() { return dollars; }

int Money::Cents() { return cents; }

Money Money::Add(Money money)
{
	dollars += money.dollars;
	cents += money.cents;
	Reduce();
	return *this;
}

Money Money::Add(int dollars) 
{ 
	this->dollars += dollars;
	return *this;
}

void Money::operator+=(Money money)
{
	*this = this->Add(money);
}

void Money::operator+=(int dollars)
{
	*this = this->Add(dollars);
}

void Money::operator-=(Money money)
{
	*this = *this - money;
}

void Money::operator-=(int dollars)
{
	*this = *this - dollars;
}

std::string Money::ToString()
{
	return "$" + std::to_string(dollars) + "." + std::to_string(cents);
}

Money operator+(Money left, Money right)
{
	return left.Add(right);
}

Money operator+(Money money, int dollars)
{
	return money.Add(dollars);
}

Money operator-(Money left, Money right)
{
	return left.Add(Money(-right.dollars, -right.cents));
}

Money operator-(Money money, int dollars)
{
	return money + -dollars;
}

Money operator*(Money money, int count)
{
	return Money(money.dollars * count, money.cents * count);
}

Money operator/(Money money, int count)
{
	return Money(money.dollars / count, money.cents / count);
}

Money operator%(Money money, int percent)
{
	return Money(money * percent / 100);
}

bool operator<(Money left, Money right)
{
	return left.dollars * 100 + left.cents < right.dollars * 100 + right.cents;
}

bool operator<=(Money left, Money right)
{
	return !(left > right);
}

bool operator>(Money left, Money right)
{
	return left.dollars * 100 + left.cents > right.dollars * 100 + right.cents;
}

bool operator>=(Money left, Money right)
{
	return !(left < right);
}

bool operator==(Money left, Money right)
{
	return left.dollars * 100 + left.cents == right.dollars * 100 + right.cents;
}

bool operator!=(Money left, Money right)
{
	return !(left == right);
}


