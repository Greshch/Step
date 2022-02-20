#include "TableFabric.h"
#include "Table.h"

std::vector<Furniture*> TableFabric::FillInCorners()
{
	return {
		new Table, nullptr, nullptr, new Table,
		nullptr, nullptr, nullptr, nullptr,
		nullptr, nullptr, nullptr, nullptr,
		nullptr, nullptr, nullptr, nullptr,
		new Table, nullptr, nullptr, new Table
	};
}
