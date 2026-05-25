#include "Banker.h"

Banker::Banker()
{
	market = new Market();
}

void Banker::GameMonth()
{
	MonthlyExpenses();
	AuctionInfo auctionInfo = Auction();
	MaterialAuction(auctionInfo.material);
	Production();
	ProductAuction(auctionInfo.product);
	CreditService();
	FactoryBuilding();
}

void Banker::GameCycle()
{
	while(true)
	{
		GameMonth();
		if (IsGameOver())
			break;
	}
}

void Banker::MonthlyExpenses()
{
	std::ranges::remove_if(players,
		[](Player* player) {
			return player->MonthlyExpenses() < 0;
		});
}

AuctionInfo Banker::Auction()
{
	return AuctionInfo();
}

void Banker::MaterialAuction(AuctionPair materialPair)
{
	typedef std::pair<Player*, AuctionPair> PlayerPair;

	std::vector<PlayerPair> playersPairs;
	
	std::ranges::for_each(players,
		[&playersPairs,
		materialPair](Player* player) {
			playersPairs.push_back(
				std::make_pair(player,
					player->MaterialRequest(materialPair)
				));
		});

	//for (int i{}; i < players.size(); i++)
	//{
	//	AuctionPair playerPair = players[i]->MaterialRequest(materialPair);
	//	playersPairs.insert(std::make_pair(players[i], playerPair));
	//}

	std::ranges::sort(playersPairs,
		[](PlayerPair left, PlayerPair right)
		{
			return left.second.price > right.second.price;
		});

	std::ranges::for_each(playersPairs,
		[&materialPair](PlayerPair playerPair)
		{
			int materialCount{};

			if (materialPair.count > 0)
			{
				if (materialPair.count >= playerPair.second.count)
					materialCount = playerPair.second.count;
				else
					materialCount = materialPair.count;
				materialPair.count -= playerPair.second.count;
			}

			playerPair.first->MaterialResponse(materialCount);
		});
	
}

void Banker::Production()
{}

void Banker::ProductAuction(AuctionPair productPair)
{}

void Banker::CreditService()
{}

void Banker::FactoryBuilding()
{}

bool Banker::IsGameOver()
{
	return false;
}
