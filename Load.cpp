// Load.cpp - Load class that loads all pictures and sprites
// Written by Neil Casey

#pragma once

#include "Load.h"

void Loader:: LoadImages() 
{
	// red, green, blue values; this is the background of the sprite
	dbSetImageColorKey(RED, GREEN, BLUE);
	
	// images are saved in same folder as project
	// second argument is "a load id". all images will have a unique load id.
	dbLoadImage(WALL, WALL_PIC_ID);
	dbLoadImage(GROUND, GROUND_PIC_ID);
	dbLoadImage(PLATFORM, PLATFORM_PIC_ID);
	dbLoadImage(FLAG, FLAG_PIC_ID);
	dbLoadImage(MAIN_MENU, MAIN_MENU_PIC_ID);
	/*dbLoadImage(PAUSE_MENU, PAUSE_MENU_PIC_ID);
	dbLoadImage(DEATH_MENU, DEATH_MENU_PIC_ID);*/
}



