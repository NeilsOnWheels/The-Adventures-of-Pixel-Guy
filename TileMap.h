// TileMap.h - TileMap class definition
// Written by Neil Casey

#pragma once

#include "DarkGDK.h"
//#include "Variables.h"
#include "Enemy.h"

using namespace std;

class TileMap
{
public:
	void LoadMap();

	private:
		int Map[MAP_HEIGHT][MAP_WIDTH];
		
};