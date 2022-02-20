#include <iostream>
#include "ChairFabric.h"
#include "TableFabric.h"
using namespace std;

void ShowRoom(vector<Furniture*>& obj);
void ClearRoom(vector<Furniture*>& obj);

int main()
{
	FurnitureFabric* fabric = /*new TableFabric*/ new ChairFabric;
	auto room = fabric->FillInCorners();
	ShowRoom(room);
	delete fabric;
	return 0;
}

void ShowRoom(vector<Furniture*>& obj)
{
	int sz = obj.size();
	for (int i = 0; i < sz; i++)
	{
		if (obj[i] != nullptr)
		{
			cout << obj[i]->GetName();
		}
		else
		{
			cout << "\t";
		}
		if ((i + 1) % 4 == 0)
		{
			cout << "\n";
		}
	}
	ClearRoom(obj);
}

void ClearRoom(vector<Furniture*>& obj)
{
	for (size_t i = 0; i < obj.size(); i++)
	{
		if (obj[i] != nullptr)
		{
			delete obj[i];
			obj[i] = nullptr;
		}
	}
}
