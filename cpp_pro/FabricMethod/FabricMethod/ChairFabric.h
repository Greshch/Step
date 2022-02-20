#pragma once
#include "FurnitureFabric.h"
class ChairFabric : public FurnitureFabric
{
public:
	virtual std::vector<Furniture*> FillInCorners() override;
};

