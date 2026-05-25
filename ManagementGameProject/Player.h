#pragma once
#include <vector>

#include "Factory.h"
#include "Credit.h"
#include "AuctionInfo.h"

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
	
	Money MonthlyExpenses();

	AuctionPair MaterialRequest(AuctionPair materialPair);
	Money MaterialResponse(int materialCount);

	Money Production();

	AuctionPair ProductRequest(AuctionPair productPair);
	Money ProductResponse(int productCount);

	Money CreditRate();

	Money CreditRepayment();

	Money CreditTake();

	Money FactoryBuilding();

};

#include "Banker.h"
