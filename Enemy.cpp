// Enemy.h - Enemy class implementation
// Written by Neil Casey

#pragma once

#include "Enemy.h"

using namespace std;

// Init constructor
// Need to provide enemy Id, and its spawn coordinates
Enemy::Enemy(const int& enemyID, const int& xSpawn, const int& ySpawn) 
{
	dbCreateAnimatedSprite(enemyID, ENEMY_CYCLE, 
		ENEMY_FRAME_WIDTH, ENEMY_FRAME_HEIGHT, ENEMY_PIC_ID);
	dbSprite(enemyID, xSpawn, ySpawn, ENEMY_PIC_ID);
	dbScaleSprite(enemyID, ENEMY_SCALE_DOWN);
}

// The enemies simply walk until they bump into something, 
// then they turn around. They only have horizontal movement.
void Enemy:: Movement(const int& id) 
{
	dbPlaySprite(id, ENEMY_START, ENEMY_END, ENEMY_DELAY);

	// turn around when colliding with a wall or ground piece
	if ( dbSpriteCollision(id, ANYTHING) > 0 )
	{
		if ( movingRight )
		{
			dbRotateSprite(id, THREE_QUARTER);
			dbMoveSprite(id, ENEMY_SPEED);
			dbRotateSprite(id, ZERO);
			movingRight = false;
		}

		else
		{
			dbRotateSprite(id, QUARTER);
			dbMoveSprite(id, ENEMY_SPEED);
			dbRotateSprite(id, ZERO);
			movingRight = true;
		}
	}
	
	// Not colliding with anything
	else
	{
		if ( movingRight )
		{
			dbRotateSprite(id, QUARTER);
			dbMoveSprite(id, ENEMY_SPEED);
			dbRotateSprite(id, ZERO);
		}

		else
		{
			dbRotateSprite(id, THREE_QUARTER);
			dbMoveSprite(id, ENEMY_SPEED);
			dbRotateSprite(id, ZERO);
		}
	}
}




