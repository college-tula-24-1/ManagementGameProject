#pragma once
#include <vector>

#include "Factory.h"
#include "Credit.h"

class Banker;

class Player
{
	std::string name;

	Banker* banker;

	FactoryBuilder* factoryBuilder;
	std::vector<Factory*> factories;
	std::vector<Credit*> creadits;

	int materials; // ESM
	int products;  // EGP

	Money account;
public:
	Player(Banker* banker, std::string name = "");
	

};

#include "Banker.h"
