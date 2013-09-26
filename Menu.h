// Menu.h - Menu Class declaration
// Written by Neil Casey

#pragma once

#include "DarkGDK.h"
#include "Variables.h"

class Menu
{
public:
	// buttons / pressed or not pressed
	bool Play;
	bool Quit;

	// true when a menu is up
	bool MenuUp;

	// init constructor
	Menu(const int& type);
};