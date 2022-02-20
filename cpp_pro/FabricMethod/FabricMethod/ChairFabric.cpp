#include "ChairFabric.h"
#include "Chair.h"

std::vector<Furniture*> ChairFabric::FillInCorners()
{
	return {
		new Chair, nullptr, nullptr, new Chair,
		nullptr, nullptr, nullptr, nullptr,
		nullptr, nullptr, nullptr, nullptr,
		nullptr, nullptr, nullptr, nullptr,
		new Chair, nullptr, nullptr, new Chair
	};
}
