#pragma once
#include <string>
using std::string;

struct Furniture abstract
{
	virtual string GetName() = 0;
};