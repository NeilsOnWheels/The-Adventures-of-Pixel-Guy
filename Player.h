// Player.h - Player class definition
// Written by Neil Casey

#pragma once

#include "DarkGDK.h"
#include "Variables.h"

using namespace std;

class Player
{
public:

	// Public variables
	bool onGround;
	bool facingRight;
	bool jumping;
	bool falling;
	bool spaceKeyPressed;
	int jumpStartTimer;
	int XCoord;
	bool Dead;

	// Init constructor
	Player();

	void InitializeVariables();

	// 0 is left 1 is right
	void UpdateMap(bool direction);

	void PlayerControl();

	void PlayerJump();

	void Gravity();
	
};

