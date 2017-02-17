// cardCollectionTracker.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include "card.h"
#include "cardSet.h"
#include <fstream>
int main()
{
	cardSet newSet;
	newSet.loadSet("new_file_3");
	newSet.printSet();
	card newCard;
	newCard = newSet.searchSet("zach", newSet.printSize(), 0);
	std::cout << newCard.printName() << " " << newCard.printAmount();
	std::cin.clear();
	std::cin.ignore(255, '\n');
	std::cin.get();
    return 0;
}

