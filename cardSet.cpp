#include "stdafx.h"
#include <iostream>
#include "card.h"
#include <fstream>
#include "cardSet.h"
#include <string>


cardSet::cardSet()
{
	setName = "null";
	cardsInSet = 0;
}

void cardSet :: loadSet(const std::string input)
{
	std::fstream set;
	set.open(input);
	for (int cnt = 0; set; ++cnt)
	{
		card newCard;
		std::string name;
		std::getline(set, name);
		newCard.setName(name);
		int amount;
		set >> amount;
		newCard.setAmount(amount);
		myCards.push_back(newCard);
		myCards[0].printName();
		std::getline(set, name);
	}
	set.close();
	
}
void cardSet::addCard()
{
	char contninue;
	do {
		card newCard;
		std::cout << "Please enter the card name: ";
		std::string name;
		getline(std::cin, name);
		newCard.setName(name);
		std::cout << "Enter how many are in the collection: ";
		int amount;
		std::cin >> amount;
		newCard.setAmount(amount);
		std::cout << "Please enter the cards current location: ";
		std::cin.ignore(1000, '\n');
		std::string loc;
		std::cin >> loc;
		newCard.setLoc(loc);
		myCards.push_back(newCard);
		std::cout << "Continue? y/n: ";
		std::cin >> contninue;
	} while (contninue == 'y');
}
void cardSet::printSet()
{
	for (int cnt = 0; myCards.size() > cnt; ++cnt)
	{
		std::cout << myCards[cnt].printName() << " " << myCards[cnt].printAmount() << std::endl;
	}
}
void cardSet::saveSet(const std::string input)
{
	std::fstream file;
	file.open(input, std::ios::out | std::ios::trunc);
	for (int cnt = 1; myCards.size() > cnt; ++cnt)
	{
		file << myCards[cnt].printName() << std::endl << myCards[cnt].printAmount() << std::endl;
	}
}
card cardSet::searchSet(const std::string item, int hi, int low)
{
	bool found = false;
	while (found == false)
	{

		if (hi < low)
		{
			std::cout << item << " not found, returning to menu";
			return myCards[0];
		}
		int midpoint = low + (hi - low) / 2;
		std::string newName = myCards[midpoint].printName();
		if (newName.compare(item) >0)
		{
			hi = midpoint - 1;
		}
		if (newName.compare(item) <0)
		{
			low = midpoint + 1;
		}
		if (newName.compare(item) == 0)
		{
			return myCards[midpoint];
		}
	}
	
}
int cardSet::printSize()
{
	return myCards.size();
}
cardSet::~cardSet()
{
}
