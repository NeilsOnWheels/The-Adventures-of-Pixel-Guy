// Enemy.h - Enemy class definition
// Written by Neil Casey

#pragma once

#include "DarkGDK.h"
#include "Variables.h"

using namespace std;

class Enemy 
{
public:
	// data members:
	bool facingRight;
	bool movingRight;
	
	// Init constuctor
	// Need to supply a sprite ID number
	// and x and y spawn coordinates
	Enemy(const int& enemyID, const int& xSpawn, const int& ySpawn);

	void Movement(const int& id);

};