// TileMap.cpp - TileMap class implementation
// Written by Neil Casey

#pragma once

#include "TileMap.h"

using namespace std;

void TileMap:: LoadMap() 
{
	// o is nothing
	// G is ground
	// W is wall
	// 15x80
	// We are gonna have the window have a width of 20
	
	int tempMap[MAP_HEIGHT][MAP_WIDTH] = 
	{   //0  1  2  3  4  5  6  7  8  9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 31 32 33 34 35 36 37 38 39 40 41 42 43 44 45 46 47 48 49 50 51 52 53 54 55 56 57 58 59 60 61 62 63 64 65 66 67 68 69 70 71 72 73 74 75 76 77 78 79
		{ o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, W, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o },
		{ o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, W, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o },
		{ o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, P, o, o, o, W, o, o, o, P, o, o, o, o, o, o, P, o, o, o, o, o, o, o, o, o, o, o, o, P, o, o, o, P, o, o, W, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o },
		{ o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, W, o, W, o, o, o, P, P, P, P, P, P, P, W, o, o, o, o, o, o, o, o, o, o, o, o, P, P, P, P, P, o, o, W, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o },
		{ o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, P, P, o, o, o, o, o, o, W, o, W, o, o, P, P, P, o, o, o, o, P, W, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, W, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o },
		{ W, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, W, o, W, o, o, o, o, o, o, o, o, o, P, W, o, o, o, o, P, P, P, P, P, o, o, o, o, o, o, o, o, o, o, W, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o },
		{ W, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, P, P, o, o, o, o, W, o, o, o, o, o, o, o, o, o, o, o, P, W, o, o, o, o, o, o, o, o, o, o, o, P, o, o, o, P, o, o, o, W, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o },
		{ W, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, W, o, o, o, P, P, P, P, P, P, P, o, P, W, o, o, o, o, o, o, o, o, o, o, o, P, P, P, P, P, o, o, o, W, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o },
		{ W, o, o, o, o, o, o, o, o, o, o, o, o, o, o, P, o, o, o, o, o, o, o, P, o, o, W, o, o, o, o, o, o, o, o, o, o, o, P, W, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, W, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o },
		{ W, o, o, o, o, o, o, o, o, o, o, o, o, o, o, P, P, P, P, P, P, P, P, P, o, o, W, o, o, o, o, o, o, o, o, o, o, o, P, W, P, P, P, P, P, P, P, P, P, o, o, o, o, o, o, o, o, o, o, W, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o },
		{ W, o, o, o, o, o, o, o, o, o, o, o, P, P, o, o, o, o, o, o, o, o, o, o, o, o, W, o, o, o, o, o, o, P, P, P, P, P, P, W, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, W, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, F },
		{ W, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, W, o, o, o, o, o, o, o, o, o, o, o, o, W, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, W, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o },
		{ W, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, W, o, o, o, o, o, o, o, o, o, o, o, o, W, o, o, o, o, o, o, o, o, o, P, o, o, o, o, o, o, o, o, o, W, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o },
		{ G, G, G, G, G, G, G, G, G, G, G, G, G, G, G, G, G, G, G, G, G, G, G, G, G, G, G, G, G, G, G, G, G, G, G, G, G, G, G, G, G, G, G, G, G, G, G, G, G, G, G, G, G, G, G, G, G, G, G, G, G, G, G, G, G, G, G, G, G, G, G, G, G, G, G, G, G, G, G, G },
		{ G, G, G, G, G, G, G, G, G, G, G, G, G, G, G, G, G, G, G, G, G, G, G, G, G, G, G, G, G, G, G, G, G, G, G, G, G, G, G, G, G, G, G, G, G, G, G, G, G, G, G, G, G, G, G, G, G, G, G, G, G, G, G, G, G, G, G, G, G, G, G, G, G, G, G, G, G, G, G, G }
	};

	// x and y coordinates are multiplied by 32 (FACTOR)
	// to fit the map to the output window.
	// so one tile, or one array element will be 32x32 pixels.
	// "Fine coordinates"
	// Our "window" width will be 20.

	// copy tempMap to map
	for ( int y = 0; y < MAP_HEIGHT; y++ )
	{
		for ( int x = 0; x < MAP_WIDTH; x++ )
			Map[y][x] = tempMap[y][x];
	}

	// Draw the tiles in the map
	for ( int y = 0, i = TILE_START; y < MAP_HEIGHT; y++, i++ )
	{
		for ( int x = 0; x < MAP_WIDTH; x++, i++ )
		{
			// 0 is empty air
			
			// 3 is the ground
			if ( Map[y][x] == G )
				dbSprite ( i, x * FACTOR, y * FACTOR, GROUND_PIC_ID );

			// 4 is a platform
			else if ( Map[y][x] == P )
				dbSprite ( i, x * FACTOR, y * FACTOR, PLATFORM_PIC_ID );

			// 2 is a wall
			else if ( Map[y][x] == W )
				dbSprite ( i, x * FACTOR, y * FACTOR, WALL_PIC_ID);
			
			// Flag
			else if ( Map[y][x] == F )
				dbSprite (i, x * FACTOR, y * FACTOR, FLAG_PIC_ID);
		}
	}
}



