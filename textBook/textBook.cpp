#include "Combo.h"
#include "Lists.cpp"
#include <iostream>

std::vector <Item> Inventory;
Item Selected{ "" };

int checkSpecial(std::string ing, int &stage) { //WIP

	for (auto s : Specials) {

		if (ing == s.name) {  //if an ingredient is a special add more
			// but what if 

			for (auto sing : s.ingredients) {

				 checkSpecial(sing, stage);
				 
			}
			stage++;
		}
	}

	return 1;
}

void StagePass() { //WIP
	for (auto s : Specials) {

		for (auto ing : s.ingredients) {

		
			checkSpecial(ing, s.stage);
			s.stage++;
		}
	}

}

void PopulateInv() {
	for (auto& s : Starters)
		Inventory.push_back(s);
	//for (auto s : Specials) // temporary
	//	Inventory.push_back(s);

}

void ShowInv() {
	using namespace std;
	cout << "Objects available:\n\n";

	for (auto& i : Inventory)
		cout << i.name << "\n";

	cout << "\n";
}



void combineItem(const std::string& input) {
	for (const auto& c : Combos) {
		bool allIng = true;
		for (const auto& ing : c.ingredients) {

			if (ing != input || ing != Selected.name) {
				allIng = false;
				break;
			}

		}

		if (allIng) {
			Selected = c;
			return;
		}
	}
}


void SelectItem() {

	using namespace std;

	cout << "Select item:\n\n";

	string input;
	cin >> input;
	cout << "\n";

	for (int i = 0; i < Inventory.size(); i++)
	{
		if (input == Inventory[i].name) {

			if (Selected.name == "")
			{
				Selected = Inventory[i];
			}
			else
			{
				combineItem(input);
			}


			Inventory.erase(Inventory.begin() + i);
			return;


		}
	}
	cout << "^ You don't have that item. Try again\n\n";

}

void ShowItem() {

	if (Selected.name != "") {
		std::cout << "/////////////////////////\n";
		std::cout << "        " << Selected.name << " : " << Selected.stage <<"\n";
		std::cout << "/////////////////////////\n\n";
	}
	else 
		std::cout << "/////////////////////////\n\n";
}

int main()
{
	using namespace std;

	//StagePass();

	PopulateInv();

	while (Inventory.size() != 0) {
		ShowInv();
		SelectItem();
		ShowItem();
	}

	cout << "\n";
	return 0;



	//for (auto s : Specials)
	//	cout << s.name << "\n";

	//cout << "\n";

	//for (auto c : Combos)
	//	cout << c.name << "\n";


}