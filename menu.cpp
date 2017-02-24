#include "stdafx.h"
#include <iostream>
#include "cardSet.h"
#include "menu.h"
#include <string>
#include "card.h"

int menu::mainMenu()
{
	char input = 'n';
	do {
		
		std::cout << "******************************************\n" <<
			"*              a)Add Card                *\n" <<
			"*              b)Search Card             *\n" <<
			"*              c)Display Set             *\n" <<
			"*              d)exit                    *\n" <<
			"******************************************\n" 
			<< "Chose and option: ";
		std::cin >> input;
		switch (input)
		{
		case 'a':
		case 'A':
			addCard();
			break;
		case 'b':
		case 'B':
			search();
			break;
		case 'c':
		case 'C':
			displaySet();
			break;
		case 'd':
		case 'D':
			return 0;
		default:
			std::cout << "Please enter a valid input\n";
			mainMenu();
			break;
		}
	} while (std::cin);
	
}
void menu::addCard()
{
	std::cout << "Please enter the card's set: ";
	std::string setName;
	std::cin >> setName;
	cardSet cardSet;
	cardSet.loadSet(setName);
	cardSet.addCard();
	cardSet.sortSet();
	cardSet.saveSet(setName);
	cardSet.~cardSet();
}
void menu::displaySet()
{
	std::cout << "Please enter the set's name: ";
	std::string setName;
	std::cin >> setName;
	cardSet cardSet;
	cardSet.loadSet(setName);
	cardSet.printSet();
}
void menu::search()
{
	std::cout << "Please enter the card's set: ";
	std::string setName;
	std::cin >> setName;
	std::cin.clear();
	std::cin.ignore(1000, '\n');
	cardSet cardSet;
	cardSet.loadSet(setName);
	char cont;
	do 
	{
		std::cout << "Enter the card's name: ";
		std::string cardName;
		getline(std::cin, cardName);
		std::cin.clear();
		std::cin.ignore(1000, '\n');
		card newCard;
		newCard = cardSet.searchSet(cardName);
		if (newCard.printName() == "null")
		{
			cont = 'y';
		}
		else
		{
			std::cout << "Found\n Name:" << newCard.printName() << "\nAmount:" << newCard.printAmount() << std::endl
				<< "Continue? y/n; ";
				std::cin >> cont;
		}
	} while (cont == 'y' || cont == 'Y');
}