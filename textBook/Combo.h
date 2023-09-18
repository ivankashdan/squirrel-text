#pragma once
#include<iostream>
#include<vector>
#include<array>
#include "Items.cpp"

class Item {
public:
	//items id;
	std::vector<std::string> ingredients;
	std::string name;
	int stage = 0;
	Item(std::string);
	
private:
};

class Starter : public Item {
public:
	Starter(std::string);
	
};

class Combo : public Item {
public:
	Combo(std::vector<std::string>);
	
};

class Special : public Item {
public:
	Special(std::string, std::vector<std::string>);
	
};


