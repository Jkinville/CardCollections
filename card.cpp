#include "stdafx.h"
#include "card.h"

#include "cardSet.h"


card::card()
{
	name = "null";
	amountOwned = 0;
	location = "Null Binder";
};
void card::setName(std::string input)
{
	name = input;
};
std::string card::printName()
{
	return name;
};
void card::setAmount(unsigned short input)
{
	amountOwned = input;
};
void card::setLoc(std::string input)
{
	location = input;
};
unsigned short card::printAmount()
{
	return amountOwned;
}

card::~card()
{
}
