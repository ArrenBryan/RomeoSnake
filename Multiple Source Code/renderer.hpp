#ifndef RENDERER_H
#define RENDERER_H

#include <graphics.h>
#include <string.h>
#include "linkedlist.hpp"
#include "menu.hpp"
#include "snake.hpp"
#include "heapsort.hpp"
#include "utility.hpp"

typedef struct SpriteHandler
{
	void *wallMap;				// SpriteHandler for wall.
	void *backgroundMap;		// SpriteHandler for background map.
	void *apple;				// SpriteHandler for apple.
	void *mouse;				// SpriteHandler for mouse.
	void *potion;				// SpriteHandler for potion.
	void *bodyHorizontal;		// SpriteHandler for SnakeBody on horizontal direction.
	void *bodyVertical;			// SpriteHandler for SnakeBody on vertical direction.
	void *tailKanan;			// SpriteHandler for SnakeTail on right direction.
	void *tailKiri;				// SpriteHandler for SnakeTail on left direction.
	void *tailAtas;				// SpriteHandler for SnakeTail on up direction.
	void *tailBawah;			// SpriteHandler for SnakeTail on down direction.
	void *bodyTurn1;			// SpriteHandler for SnakeBody when turning.
	void *bodyTurn2;			// SpriteHandler for SnakeBody when turning.
	void *bodyTurn3;			// SpriteHandler for SnakeBody when turning.
	void *bodyTurn4;			// SpriteHandler for SnakeBody when turning.
	void *barBoost;				// SpriteHandler for bar boost gauge
	void *numericalScore[10];	// SpriteHandler for Set of Numeric (scoring purpose).
	void *playerName;			// SpriteHandler for Player Name.
///	void *obstacle[8];			// SpriteHandler for Set of Obstacle.
} SpriteHandler;

/**
 * Initialize new SpriteHandler. [Constructor]
 * @param gridSize Map grid size.
 * @return SpriteHandler instance.
 *
 * Author:	Ariraja Nuralamsyah (191511005)
 *			Bryan Azriel Parulian (191511008)
 *			Heldi Apriadi (191511015)
 */
SpriteHandler *SpriteHandler__create(int gridSize);

/**
 * Rendering background of maps.
 * @param sh SpriteHandler instance.
 *
 * Author:	Ariraja Nuralamsyah (191511005)
 *			Bryan Azriel Parulian (191511008)
 *			Heldi Apriadi (191511015)
 */
void Rendering__backgroundMap(SpriteHandler *sh);

/**
 * Rendering wall of maps.
 * @param sh SpriteHandler instance.
 *
 * Author:	Ariraja Nuralamsyah (191511005)
 *			Bryan Azriel Parulian (191511008)
 *			Heldi Apriadi (191511015)
 */
void Rendering__wallMap(SpriteHandler *sh);

/**
 * Rendering bar boost gauge.
 * @param sh SpriteHandler instance.
 * @param snakeBoostGauge current value of snakeBoostGauge.
 * @param isEating condition when snake is already eating or not.
 *
 * Author:	Bryan Azriel Parulian (191511008)
 *			Heldi Apriadi (191511015)
 */
void Rendering__barBoost(void* barBoost, int *snakeBoostGauge, int isEating);

/**
 * Rendering foods (apple, mouse, potion).
 * @param sh SpriteHandler instance.
 * @param x x-coordinate of foods.
 * @param y y-coordinate of foods.
 * @param ket information about the specific food that will rendered. 
 *
 * Author:	Ariraja Nuralamsyah (191511005)
 *			Bryan Azriel Parulian (191511008)
 */
void Rendering__food(SpriteHandler *sh, int x, int y, const char ket[15]);

/**
 * Rendering apple.
 * @param sh SpriteHandler instance.
 * @param x x-coordinate of foods.
 * @param y y-coordinate of foods. 
 *
 * Author:	Ariraja Nuralamsyah (191511005)
 */
void Rendering__appleComputerSnake(SpriteHandler *sh, int x, int y);

/**
 * Rendering SnakeBody
 * @param l LinkedList instance.
 * @param sh SpriteHandler instance.
 *
 * Author:	Bryan Azriel Parulian (191511008)
 */
void Rendering__snakeBody(LinkedList *l, SpriteHandler *sh);

/**
 * Rendering cursor menu.
 * @param x x-coordinate
 * @param y y-coordinate
 * @param ket information about the specific cursor that will display.
 *
 * Author:	Azhar Bani Rashif (191511007)
 *			Bryan Azriel Parulian (191511008)
 */
void Rendering__cursorMenu(int x, int y, const char ket[15]);

/**
 * Rendering display menu.
 * There are 5 menus (main menu, player menu, mode menu, classic menu, help menu, loading screen).
 * @param ket information about the specific menu that will display.
 *
 * Author:	Azhar Bani Rashif (191511007)
 *			Bryan Azriel Parulian (191511008)
 */
void Rendering__displayMenu(const char ket[15]);

/**
 * Rendering player gamescore point.
 * @param sh SpriteHandler instance.
 * @param score scorepoint player.
 *
 * Author:	Ariraja Nuralamsyah (191511005)
 */
void Rendering__displayScore(SpriteHandler *sh, int score[]);

/**
 * Rendering top 5 highscore on classic easy mode.
 * @param gridSize Map grid size.
 *
 * Author:	Bryan Azriel Parulian (191511008)
 *			Heldi Apriadi (191511015)
 */
void Rendering__easyHighscore(int gridSize);

/**
 * Rendering score when gameover.
 * @param sh SpriteHandler instance.
 * @param score gamescore player.
 *
 * Author:	Ariraja Nuralamsyah (191511005)
 *			Heldi Apriadi (191511015)
 */
void Rendering__lastScore(SpriteHandler *sh, int score[]);

/**
 * Rendering background when game is over.
 *
 * Author:	Heldi Apriadi (191511015)
 */
void Rendering__gameOver();

/**
 * Rendering background when player input the player name.
 *
 * Author:	Azhar Bani Rashif (191511007)
 */
void Rendering__inputName();

/**
 * Rendering alphabetical / character of player name.
 * @param playerName the name of player / user.
 * @param arrayLength the length of array (player name).
 * @param gridSize Map grid size.
 *
 * Author:	Ariraja Nuralamsyah (191511005)
 *			Azhar Bani Rashif (191511007)
 *			Bryan Azriel Parulian (191511008)
 *			Heldi Apriadi (191511015)
 */
void Rendering__characterInput (char playerName[], int arrayLength, int gridSize);

/**
 * Rendering player name.
 * @param playerName the name of player / user.
 * @param gridSize Map grid size.
 *
 * Author:	Ariraja Nuralamsyah (191511005)
 *			Bryan Azriel Parulian (191511008)
 *			Heldi Apriadi (191511015)
 */
void Rendering__playerName (char *playerName, int gridSize);

/**
 * Rendering board game.
 *
 * Author:	Azhar Bani Rashif (191511007)
 *			Heldi Apriadi (191511015)
 */
void Rendering__boardGame();

/**
 * Rendering classic medium obstacle.
 * This feature is available in 1 Source Code (another source code).
 *
 * Author:	Heldi Apriadi (191511015)
 */
//void Rendering__obstacleMedium(SpriteHandler *sh, Point coordObstacle[])

/**
 * Rendering classic hard obstacle.
 * This feature is available in 1 Source Code (another source code).
 *
 * Author:	Heldi Apriadi (191511015)
 */
//void Rendering__obstacleHard(SpriteHandler *sh, Point coordObstacle[])

/**
 * Rendering classic expert obstacle.
 * This feature is available in 1 Source Code (another source code).
 *
 * Author:	Heldi Apriadi (191511015)
 */
//void Rendering__obstacleExpert(SpriteHandler *sh, Point coordObstacle[])

#endif
