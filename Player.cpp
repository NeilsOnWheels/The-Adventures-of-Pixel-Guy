// player.cpp - Player class implementation
// Written by Neil Casey

#pragma once

#include "Player.h"

using namespace std;

// Init constructor
Player:: Player()
{
	dbCreateAnimatedSprite(PLAYER_ID, PLAYER_CYCLE, 
		FRAME_WIDTH, FRAME_HEIGHT, PLAYER_PIC_ID);
	dbSprite(PLAYER_ID, SPAWN_X, SPAWN_Y, PLAYER_PIC_ID);
	dbScaleSprite(PLAYER_ID, SCALE_DOWN);
}

void Player:: InitializeVariables() 
{
	jumping = false;
	onGround = false;
	spaceKeyPressed = false;
	facingRight = true;
	Dead = false;
	XCoord = 200;
}

// Moves the map when called.
// direction is the direction the player is "walking" in:
// 0 is left 1 is right
void Player:: UpdateMap(bool direction)
{
	for ( int y = 0, i = 2; y < MAP_HEIGHT; y++, i++ )
	{
		for ( int x = 0; x < MAP_WIDTH; x++, i++ )
		{
			if ( direction )
			{
				dbRotateSprite(i, QUARTER);
				dbMoveSprite(i, SPEED);
				dbRotateSprite(i, ZERO);
			}

			else if ( !direction )
			{
				dbRotateSprite(i, THREE_QUARTER);
				dbMoveSprite(i, SPEED);
				dbRotateSprite(i, ZERO);
			}
		}
	}

	if ( direction )
	{
		XCoord -= SPEED;
	}

	else if ( !direction )
	{
		XCoord += SPEED;
	}
}

void Player:: PlayerControl() 
{
	// check if he's falling and set the animation frame
	if ( falling )
	{
		dbSetSpriteFrame(PLAYER_ID, FALL);
	}

	// moving right
	if ( dbRightKey() )
	{
		if ( !facingRight )
		{
			dbMirrorSprite(PLAYER_ID);
			facingRight = true;
		}

		// sprite id, start frame, end frame, time delay (ms?)
		dbPlaySprite(PLAYER_ID, STAND, WALK_2, DELAY);

		UpdateMap(0);

		// if sprite 1 collides with sprite 2
		//if ( dbSpriteCollision(1, 2) == 1 )
		// with the zero in place, this pretty
		// much means "if sprite1 collides with 
		// any other sprite"
		if ( dbSpriteCollision(PLAYER_ID, ANYTHING) > 0 )
		{
			// move back to the left and it will look like he is restricted
			UpdateMap(1);
		}
	}

	// moving left
	else if ( dbLeftKey() )
	{
		if ( facingRight )
		{
			dbMirrorSprite(PLAYER_ID);
			facingRight = false;
		}

		// sprite id, start frame, end frame, time delay (ms?)
		dbPlaySprite(PLAYER_ID, STAND, WALK_2, DELAY);

		UpdateMap(1);

		if ( dbSpriteCollision(PLAYER_ID, ANYTHING) > 0 )
		{	
			UpdateMap(0);
			// move back to the right
		}
	}
	
	// check if he's falling again, 
	// se he doesnt keep walking in midair
	// for example if he walks off a ledge
	else if ( falling )
	{
		dbSetSpriteFrame(PLAYER_ID, FALL);
	}

	else
	{
		// sprite id, cycle frame
		dbSetSpriteFrame(PLAYER_ID, STAND);
	}
}

void Player:: PlayerJump() 
{
	if  ( dbSpaceKey() && !spaceKeyPressed )
	{
		if ( !jumping && onGround )
		{
			spaceKeyPressed = true;
			jumping = true;
			onGround = false;

			// dbTimer() returns the current time in miliseconds
			jumpStartTimer = dbTimer();
		}
	}

	if ( jumping )
	{	
		if ( (dbTimer() - jumpStartTimer) < JUMP_TIME )
		{	
			dbSetSpriteFrame(PLAYER_ID, JUMP);

			// move him upward
			dbMoveSprite(PLAYER_ID, SPEED);
		}
		
		// in 600 ms, he gets to the peak of his jump, stays there
		// for another 100 ms, then is no longer jumping. At that
		// point Gravity will take over and make him descend.
		if ( (dbTimer() - jumpStartTimer) > PEAK_TIME )
		{
			jumping = false;
			falling = true;
		}
	}

	if ( !dbSpaceKey() )
	{
		spaceKeyPressed = false;
	}

	// check to see if he bumps his head on something above him
	if ( jumping && dbSpriteCollision(PLAYER_ID, ANYTHING) > 0 )
	{
		jumping = false;
		falling = true;
		dbRotateSprite(PLAYER_ID, TWO_QUARTER);
		dbMoveSprite(PLAYER_ID, SPEED);
		dbRotateSprite(PLAYER_ID, ZERO);
	}
	
	// if he collides with an enemy from the side, he dies
	if ( onGround && !falling )
	{
		if ( dbSpriteCollision(PLAYER_ID, ENEMY_ID1) ||
			 dbSpriteCollision(PLAYER_ID, ENEMY_ID2) ||
			 dbSpriteCollision(PLAYER_ID, ENEMY_ID3) ||
			 dbSpriteCollision(PLAYER_ID, ENEMY_ID4) ||
			 dbSpriteCollision(PLAYER_ID, ENEMY_ID5) ||
			 dbSpriteCollision(PLAYER_ID, ENEMY_ID6) ||
			 dbSpriteCollision(PLAYER_ID, ENEMY_ID7) ||
			 dbSpriteCollision(PLAYER_ID, ENEMY_ID8) ||
			 dbSpriteCollision(PLAYER_ID, ENEMY_ID9) ||
			 dbSpriteCollision(PLAYER_ID, ENEMY_ID10) )
		{
			dbDeleteImage(PLAYER_ID);
			dbDeleteSprite(PLAYER_ID);
			Dead = true;
		}
	}
		
}

void Player:: Gravity()
{
	// checking to see if player is colliding with anything;
	// Lets try this: if he collides with something while falling.
	// this checks if he is colliding with something below him
	if ( dbSpriteCollision(PLAYER_ID, ANYTHING) > 0 && falling)
	{
		// move back up
		dbMoveSprite(PLAYER_ID, SPEED);
		onGround = true;
		falling = false;
	}

	// for situations like when he walks off a ledge
	// if not colliding with anything
	if ( dbSpriteCollision(PLAYER_ID, ANYTHING) <= 0 )
	{
		onGround = false;
	}

	if ( !onGround )
	{
		if ( !jumping )
		{
			falling = true;
		}
	}

	if ( falling )
	{
		// move downward
		dbRotateSprite(PLAYER_ID, TWO_QUARTER);
		dbMoveSprite(PLAYER_ID, SPEED); // , 3);
		dbRotateSprite(PLAYER_ID, ZERO);
		
		// if he collides with an enemy, the enemy dies
		if ( dbSpriteCollision(PLAYER_ID, ENEMY_ID1) )
		{
			//dbDeleteImage(ENEMY_ID1);
			dbDeleteSprite(ENEMY_ID1);
		}

		if ( dbSpriteCollision(PLAYER_ID, ENEMY_ID2) )
		{
			//dbDeleteImage(ENEMY_ID2);
			dbDeleteSprite(ENEMY_ID2);
		}

		if ( dbSpriteCollision(PLAYER_ID, ENEMY_ID3) )
		{
			//dbDeleteImage(ENEMY_ID3);
			dbDeleteSprite(ENEMY_ID3);
		}

		if ( dbSpriteCollision(PLAYER_ID, ENEMY_ID4) )
		{
			//dbDeleteImage(ENEMY_ID4);
			dbDeleteSprite(ENEMY_ID4);
		}
		if ( dbSpriteCollision(PLAYER_ID, ENEMY_ID5) )
		{
			//dbDeleteImage(ENEMY_ID5);
			dbDeleteSprite(ENEMY_ID5);
		}

		if ( dbSpriteCollision(PLAYER_ID, ENEMY_ID6) )
		{
			//dbDeleteImage(ENEMY_ID6);
			dbDeleteSprite(ENEMY_ID6);
		}

		if ( dbSpriteCollision(PLAYER_ID, ENEMY_ID7) )
		{
			//dbDeleteImage(ENEMY_ID7);
			dbDeleteSprite(ENEMY_ID7);
		}

		if ( dbSpriteCollision(PLAYER_ID, ENEMY_ID8) )
		{
			//dbDeleteImage(ENEMY_ID8);
			dbDeleteSprite(ENEMY_ID8);
		}

		if ( dbSpriteCollision(PLAYER_ID, ENEMY_ID9) )
		{
			//dbDeleteImage(ENEMY_ID9);
			dbDeleteSprite(ENEMY_ID9);
		}

		if ( dbSpriteCollision(PLAYER_ID, ENEMY_ID10) )
		{
			//dbDeleteImage(ENEMY_ID10);
			dbDeleteSprite(ENEMY_ID10);
		}

		// checking to see if player is colliding with anything;
		if ( dbSpriteCollision(PLAYER_ID, ANYTHING) > 0 )
		{
			// move back up
			dbMoveSprite(PLAYER_ID, SPEED);
			onGround = true;
			falling = false;
		}
	}
}



