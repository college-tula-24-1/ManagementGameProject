#pragma once
#include <vector>
#include <map>

#include <ranges>
#include <algorithm>

#include "Player.h"
#include "Market.h"

class Banker
{
	std::vector<Player*> players;
	Market* market;

	void MonthlyExpenses();

	AuctionInfo Auction();

	void MaterialAuction(AuctionPair materialPair);

	void Production();

	void ProductAuction(AuctionPair productPair);

	void CreditService();

	void FactoryBuilding();

	bool IsGameOver();

public:
	Banker();

	void AddPlayer(Player* player);
	void CreatePlayer();

	void GameMonth();
	void GameCycle();
};

