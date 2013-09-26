// Menu.cpp - Menu class implementation
// Written by Neil Casey

#include "Menu.h"

// init constructor
Menu:: Menu(const int& type)
{
	if ( type == 1 )
	{
		dbSprite(MAIN_MENU_ID, MENUX, MENUY, MAIN_MENU_PIC_ID);
	}

	else if (type == 2)
	{
		dbSprite(PAUSE_MENU_ID, MENUX, MENUY, PAUSE_MENU_PIC_ID);
	}

	else if ( type == 3 )
	{
		dbSprite(DEATH_MENU_ID, MENUX, MENUY, DEATH_MENU_PIC_ID);
	}

	MenuUp = true;
}

