#pragma once
#include <iostream>
#include <string>
class card
{
public:
	card();
	~card();
	void setName(std::string);
	std::string printName();
	void setAmount(unsigned short);
	void setLoc(std::string);
	//void search();
	unsigned short printAmount();
	
private:
	std::string name;
	//cardSet set;
	unsigned short amountOwned;
	std::string location;
};

