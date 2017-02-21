#pragma once
#include "stdafx.h"
#include "card.h"
#include <string>
#include <vector>
class cardSet
{
public:
	cardSet();
	~cardSet();
	void loadSet(const std::string);
	void addCard();
	//void removeCard();
	void printSet();
	void saveSet(const std::string);
	void sortSet();
	card searchSet(const std::string, int, int);
	int printSize();

private:
	std::string setName;
	int cardsInSet;
	std:: vector<card> myCards;

};

