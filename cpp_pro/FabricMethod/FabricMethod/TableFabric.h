#pragma once
#include "FurnitureFabric.h"
class TableFabric : public FurnitureFabric
{
public:
	virtual std::vector<Furniture*> FillInCorners() override;
};

