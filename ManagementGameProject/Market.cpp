#include "Market.h"

Market::Market() : level{ 3 }{}

int Market::Level()
{
	return this->level;
}

AuctionInfo Market::Auction()
{
	return AuctionInfo();
}
