#include "Player.h"

Player::Player(Banker* banker, std::string name) 
	: banker{ banker },
	name{ name }
{
	factoryBuilder = new FactoryBuilder();

	factories.push_back(factoryBuilder->GetFactory());
	factories.push_back(factoryBuilder->Set()->GetFactory());

	materials = 4;
	products = 2;
	account = *(new Money(10000, 0));
}
