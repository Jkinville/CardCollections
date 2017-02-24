// cardCollectionTracker.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include "menu.h"
int main()
{
	menu newMenu;
	newMenu.mainMenu();
	std::cin.clear();
	std::cin.ignore(255, '\n');
	std::cin.get();
    return 0;
}

