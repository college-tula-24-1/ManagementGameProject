#pragma once
#include <vector>

#include "Player.h"
#include "Market.h"

class Banker
{
	std::vector<Player*> players;
	Market* market;

public:
	Banker();

	void AddPlayer(Player* player);
	void CreatePlayer();

	void Step();
	void Cycle();

	void MonthlyExpenses();

	AuctionInfo Auction();

	void MaterialAuction();

	void Production();

	void ProductAuction();

	void CreditService();

	void FactoryBulding();
};

