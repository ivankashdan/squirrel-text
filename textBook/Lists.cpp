#include "Combo.h"
#include <vector>

const std::vector <Starter> Starters
{
	{ "acorn" },
	{ "bottle" },
	{ "grass" },
	{ "rock" },
	{ "sock" }
};

const std::vector <Special> Specials
{
	{"tea", { "acorn", "bottle" }},
};

const std::vector <Combo> Combos
{
	{{"acorn", "bottle"}},
	{ {"grass", "rock"} }

};