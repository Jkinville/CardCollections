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
		std::cin.clear();
		std::cin.ignore(1000, '\n');
		getline(std::cin, name);
		newCard.setName(name);
		std::cout << "Enter how many are in the collection: ";
		int amount;
		std::cin >> amount;
		newCard.setAmount(amount);
		std::cout << "Please enter the cards current location: ";
		std::string loc;
		std::cin.clear();
		std::cin.ignore(1000, '\n');
		std::cin >> loc;
		newCard.setLoc(loc);
		myCards.push_back(newCard);
		std::cin.clear();
		std::cin.ignore(1000, '\n');
		std::cout << "Continue? y/n: ";
		std::cin >> contninue;
		std::cin.clear();
		std::cin.ignore(1000, '\n');
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
	for (int cnt = 0; myCards.size() > cnt; ++cnt)
	{
		file << myCards[cnt].printName() << std::endl << myCards[cnt].printAmount() << std::endl;
	}
	file.close();
}
card cardSet::searchSet(const std::string item)
{
	int hi = myCards.size(), low = 0;
	bool found = false;
	while (found == false)
	{

		if (hi < low)
		{
			std::cout << item << " not found, returning to menu";
			return myCards[myCards.size()-1];
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
void cardSet::sortSet()
{
	int holder;
	card temp;
	std::cout << "start of sort\n";
	for (int cnt = 1; cnt < myCards.size(); ++cnt)
	{
		std::cout << "First loop sort\n";
		holder = cnt;
		std::string holderName = myCards[holder].printName(), compareName = myCards[holder - 1].printName();
		while (holder > 0 && holderName.compare(myCards[holder - 1].printName()) <0)
		{
			std::cout << holder<< " \n";
			std::cout << "2nd loop\n";
			temp = myCards[holder];
			myCards[holder] = myCards[holder - 1];
			myCards[holder - 1] = temp;
			std::cout << myCards[holder].printName() << " " << myCards[holder - 1].printName();
			--holder;
			holderName = myCards[holder].printName();
			
		}
	}
	saveSet(setName);
}
int cardSet::printSize()
{
	return myCards.size();
}
cardSet::~cardSet()
{
	myCards.clear();
	std::cout << myCards.size();
}
