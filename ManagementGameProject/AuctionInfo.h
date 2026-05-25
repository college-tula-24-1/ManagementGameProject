#pragma once
#include "Money.h"

struct AuctionPair
{
	int count = 0;
	Money price;
};

struct AuctionInfo
{
	AuctionPair material;
	AuctionPair product;
};

