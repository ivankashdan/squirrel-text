#include "Combo.h"

Item::Item(std::string n = "") : name{ n }, ingredients{ {n} } 
{
}

Starter::Starter(std::string n = "") : Item{ n }
{
	ingredients = {n};
}

Combo::Combo(std::vector<std::string> ing = {""}) {
	

	for (int i = 0; i < ing.size(); i++)
	{
			name += ing[i];
			if (i != ing.size()-1)
				name += '_';
	}

	ingredients = ing;

}

Special::Special(std::string n = "", std::vector<std::string> ing = {""}) {

	name = n;
	ingredients = ing;

}








