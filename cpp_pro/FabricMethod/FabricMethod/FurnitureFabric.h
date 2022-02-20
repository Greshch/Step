#pragma once
#include <vector>
#include "Furniture.h"

struct FurnitureFabric abstract
{
	virtual std::vector<Furniture*> FillInCorners() = 0;
};