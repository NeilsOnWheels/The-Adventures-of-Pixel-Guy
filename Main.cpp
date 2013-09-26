// main.cpp - The Adventures of Pixel Guy main entry point
// Written by Neil Casey
// Saved in Neil->MyDocuments->VisualStudios2008->Projects

/*
The following files had lines that needed to be commeneted out because I was getting
Compile errors:
darksdktext.h
darksdkimage.h
darksdkbasic3d.h
darksdk.h
*/

#include "Player.h"
#include "Load.h"
#include "Variables.h"
#include "TileMap.h"
#include "Enemy.h" // maybe not since its included in tilmap.h
#include "Menu.h"
#include "DarkGDK.h"

void DarkGDK ( void )
{
	dbSyncOn   ( );
	dbSyncRate ( SYNC );
	dbDisableEscapeKey ( );

	bool play = true;

	while ( play )
	{
		Loader loader;
		loader.LoadImages();

		TileMap theMap;
		theMap.LoadMap();
	
		Player player;
		player.InitializeVariables();

		Enemy enemy1(ENEMY_ID1, SPAWNX_ONE, SPAWNY_ONE); 
		Enemy enemy2(ENEMY_ID2, SPAWNX_TWO, GROUND_SPAWN);
		Enemy enemy3(ENEMY_ID3, SPAWNX_THREE, GROUND_SPAWN);
		Enemy enemy4(ENEMY_ID4, SPAWNX_FOUR, SPAWNY_FOUR);
		Enemy enemy5(ENEMY_ID5, SPAWNX_FIVE, SPAWNY_FIVE);
		Enemy enemy6(ENEMY_ID6, SPAWNX_SIX, GROUND_SPAWN);
		Enemy enemy7(ENEMY_ID7, SPAWNX_SEVEN, SPAWNY_SEVEN);
		Enemy enemy8(ENEMY_ID8, SPAWNX_EIGHT, SPAWNY_EIGHT);
		Enemy enemy9(ENEMY_ID9, SPAWNX_NINE, GROUND_SPAWN);
		Enemy enemy10(ENEMY_ID10, SPAWNX_TEN, GROUND_SPAWN);

		// main menu
		Menu mainMenu(MAIN);

		bool pauseMenuUp = false;
		bool deathMenuUp = false;

		while ( LoopGDK ( ) )
		{	
			if ( mainMenu.MenuUp )
			{
				// Quit
				if ( dbKeyState(Q_KEY) )
				{
					break; // Why did I put this break before the subsequent line?
					// Better Question: why is it here at all?
					play = false;
				}
				
				// Play
				else if ( dbKeyState(P_KEY) )
				{
					mainMenu.MenuUp = false;
					dbDeleteImage(MAIN_MENU_PIC_ID);
					dbDeleteSprite(MAIN_MENU_ID);
				}
			}

			if ( pauseMenuUp )
			{
				// Quit
				if ( dbKeyState(Q_KEY) )
				{
					break;
					play = false;
				}
				
				// Play
				else if ( dbKeyState(P_KEY) )
				{
					dbDeleteImage(PAUSE_MENU_PIC_ID);
					dbDeleteSprite(PAUSE_MENU_ID);
					pauseMenuUp = false;
				}

			}

			if ( deathMenuUp )
			{
				// Quit
				if ( dbKeyState(Q_KEY) )
				{
					break;
					play = false;
				}
				
				// Play
				else if ( dbKeyState(P_KEY) )
				{
					dbDeleteImage(DEATH_MENU_PIC_ID);
					dbDeleteSprite(DEATH_MENU_ID);
					deathMenuUp = false;
					play = true;
					break;
				}
			}

			player.Gravity();
			player.PlayerControl();
			player.PlayerJump();

			enemy1.Movement(ENEMY_ID1);
			enemy2.Movement(ENEMY_ID2);
			enemy3.Movement(ENEMY_ID3);
			enemy4.Movement(ENEMY_ID4);
			enemy5.Movement(ENEMY_ID5);
			enemy6.Movement(ENEMY_ID6);
			enemy7.Movement(ENEMY_ID7);
			enemy8.Movement(ENEMY_ID8);
			enemy9.Movement(ENEMY_ID9);
			enemy10.Movement(ENEMY_ID10);

			// Pressing S pauses the game 
			if ( dbKeyState(S_KEY) )
			{
				dbLoadImage(PAUSE_MENU, PAUSE_MENU_PIC_ID);
				Menu pauseMenu(PAUSE);
				pauseMenuUp = true;
			}
			
			// Dying brings up the death screen
			else if ( player.Dead )
			{
				dbLoadImage(DEATH_MENU, DEATH_MENU_PIC_ID);
				Menu deathMenu(DEATH);
				deathMenuUp = true;
			}

			// checking to see if the player has reached the flag
			if ( player.XCoord >= ENDX )
			{
 				play = true;
				break;
			}

			if ( dbEscapeKey() )
			{
				break;
				play = false;
			}

			dbSync();
		}

	}

	return;
}
