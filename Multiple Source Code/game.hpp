#ifndef GAME_H
#define GAME_H

#define KEY_A 0x41
#define KEY_B 0x42
#define KEY_C 0x43
#define KEY_D 0x44 
#define KEY_E 0x45 
#define KEY_F 0x46 
#define KEY_G 0x47 
#define KEY_H 0x48 
#define KEY_I 0x49 
#define KEY_J 0x4A 
#define KEY_K 0x4B 
#define KEY_L 0x4C 
#define KEY_M 0x4D 
#define KEY_N 0x4E 
#define KEY_O 0x4F 
#define KEY_P 0x50 
#define KEY_Q 0x51 
#define KEY_R 0x52 
#define KEY_S 0x53 
#define KEY_T 0x54 
#define KEY_U 0x55 
#define KEY_V 0x56 
#define KEY_W 0x57 
#define KEY_X 0x58 
#define KEY_Y 0x59 
#define KEY_Z 0x5A 

#define KEY_0 0x30 
#define KEY_1 0x31 
#define KEY_2 0x32 
#define KEY_3 0x33 
#define KEY_4 0x34 
#define KEY_5 0x35 
#define KEY_6 0x36 
#define KEY_7 0x37 
#define KEY_8 0x38 
#define KEY_9 0x39

#define MAXBOOSTBAR 40

#include <graphics.h>
#include <time.h>

#include "snake.hpp"
#include "linkedlist.hpp"
#include "renderer.hpp"
#include "menu.hpp"
#include "heapsort.hpp"
#include "tree.hpp"
#include "queuestack.hpp"

/**
 * Game object.
 */
typedef struct Game
{
    int gridSize;   // Map grid size.
    int gridWidth;  // Map width.
    int gridHeight; // Map height.

    int windowWidth; // Calculated window width.
    int windowHeight; // Calculated window height.
} Game;

/**
 * Initialize new Game. [Constructor]
 * @param gridSize Map grid size.
 * @param gridWidth Map width.
 * @param gridHeight Map height.
 * @return Game instance.
 *
 * Author:	Bryan Azriel Parulian (191511008)
 */
Game *Game__create(int gridSize, int gridWidth, int gridHeight);

/**
 * Run the game.
 * @param g Game instance.
 *
 * Author:	Bryan Azriel Parulian (191511008)
 */
void Game__run(Game *g);

/**
 * Adding gamescore.
 * @param score gamescore player.
 * @param addScore additional gamescore point.
 *
 * Author:	Ariraja Nuralamsyah (191511005)
 *			Bryan Azriel Parulian (191511008)
 */
void Game__addingScore(int score[], int addScore);

/**
 * Get player name.
 * @param gridSize Map grid size.
 * @return array of player name.
 *
 * Author:	Ariraja Nuralamsyah (191511005)
 *			Bryan Azriel Parulian (191511008)
 *			Heldi Apriadi (191511015)
 */
char *Game__getPlayerName (int gridSize);

/**
 * Save data player to file (ScoreData.txt).
 * @param playerScore gamescore player.
 * @param playerName gamename player.
 *
 * Author:	Azhar Bani Rashif (191511007)
 *			Bryan Azriel Parulian (191511008)
 *			Heldi Apriadi (191511015)
 */
void Game__saveScore (int playerScore[], char *playerName);

/**
 * Save sorted data from max to min to file (Highscore.txt).
 * @param data player datas (name and score).
 * @param arrayLength length of the array.
 *
 * Author:	Bryan Azriel Parulian (191511008)
 */
void Game__saveSortedScore (DataHighscore *data, int arrayLength);

/**
 * Sort data score to highscore.
 * @param data player datas (name and score).
 * @param arrayLength length of the array.
 *
 * Author:	Bryan Azriel Parulian (191511008)
 */
void Game__sortingScore();

/**
 * Get array length.
 * @return length of the array.
 *
 * Author:	Bryan Azriel Parulian (191511008)
 */
int getArrayLength();

/**
 * Initialize new array of data highscore. [Constructor]
 * @param arrayLength length of the array.
 * @return DataHighscore instance.
 *
 * Author:	Bryan Azriel Parulian (191511008)
 */
DataHighscore *Game__arrayCreate (int arrayLength);

/**
 * Get path to apple for computer snake.
 * @param l Linkedlist instance.
 * @param arrayMap 2 dimensional array that contents true/false (isVisited or not).
 * @param appleCoord apple coordinates.
 * @return stack that contents coordinates towards the apple.
 *
 * Author:	Bryan Azriel Parulian (191511008)
 */
Stack *getPathFood(LinkedList *l, bool **arrayMap, Point appleCoord);

/**
 * Update arrayMap for the body of the snake and the wall is filled true (isVisited = true).
 * @param l Linkedlist instance.
 * @param arrayMap 2 dimensional array that contents true/false (isVisited or not).
 *
 * Author:	Bryan Azriel Parulian (191511008)
 *			Heldi Apriadi (191511015)
 */
void updateArraySnake(bool **arrayMap, LinkedList *l);

/**
 * Update arrayMap for the path that already passed.
 * @param arrayMap 2 dimensional array that contents true/false (isVisited or not).
 * @param grid grid coordinates that will be passed.
 *
 * Author:	Heldi Apriadi (191511015)
 */
void updateArrayPath(bool **arrayMap, Point grid);

/**
 * Update arrayMap for the path that already passed.
 * @param arrayMap 2 dimensional array that contents true/false (isVisited or not).
 * @param grid grid coordinates that already passed.
 * @param ket information about the specific direction that will be passed. 
 * @return true/false that the path can be passed.
 *
 * Author: Bryan Azriel Parulian (191511008)
 */
bool isPathVisited(bool **arrayMap, Point grid, const char ket[6]);

/**
 * Run computer snake mode.
 *
 * Author:	Ariraja Nuralamsyah (191511005)
 *			Bryan Azriel Parulian (191511008)
 *			Heldi Apriadi (191511015)
 */
void Game__computerSnake();

/**
 * Run classic mode without obstacle (Level Easy).
 *
 * Author:	Ariraja Nuralamsyah (191511005)
 *			Bryan Azriel Parulian (191511008)
 *			Heldi Apriadi (191511015)
 */
void Game__classicNonObs();

#endif
