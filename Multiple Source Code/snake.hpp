#ifndef SNAKE_H
#define SNAKE_H

#include "renderer.hpp"
#include "linkedlist.hpp"
#include "utility.hpp"

typedef struct Data
{
	char *playerName;
	int score[6];
} Data;

/**
 * Snake body direction enum.
 */
typedef enum Direction
{
    noDirection = 0, // No direction.
    right = 1,       // Snake turn right.
    left = 2,        // Snake turn left.
    up = 3,          // Snake towards up.
    down = 4,        // Snake towards down.
} Direction;

/**
 * Defines a single snake body in the linked list.
 */
typedef struct SnakeBody
{
	Point *coord;			// Body coordinate.	
	Direction turn;			// Body turn.
    Direction direction;	// Body direction.
} SnakeBody;

/**
 * Defines a snake stats.
 */
typedef struct SnakeStats
{
	int snakeAlive;
	int snakeSpeed;
	int snakeBoostGauge;
} SnakeStats;

/**
 * Defines a food stats.
 */
typedef struct FoodStats
{
	int randomChance;
	int delayRespawn;
	int timer;
	int isExist;
} FoodStats;

/**
 * Initialize new SnakeBody. [Constuctor]
 * @param l LinkedList instance.
 *
 * Author:	Bryan Azriel Parulian (191511008)
 */
void Snake__create(LinkedList *l);

/**
 * Initialize new SnakeStats. [Constuctor]
 * @return SnakeStats instance.
 *
 * Author:	Bryan Azriel Parulian (191511008)
 */
SnakeStats *SnakeStats__create();

/**
 * Initialize new value of SnakeHead.
 * @return new value of SnakeHead
 *
 * Author:	Bryan Azriel Parulian (191511008)
 */
SnakeBody *SnakeHead__valueCreate();

/**
 * Initialize new value of SnakeBody.
 * @param l LinkedList instance.
 * @return new value of SnakeBody.
 *
 * Author:	Bryan Azriel Parulian (191511008)
 */
SnakeBody *SnakeBody__valueCreate(LinkedList *l);

/**
 * Updating value LinkedList (SnakeBody).
 * @param l LinkedList instance.
 * @param addPoint additional coordinate.
 *
 * Author:	Bryan Azriel Parulian (191511008)
 */
void Snake__updateCoord(LinkedList *l, Point addPoint);

/**
 * Controller snake.
 * @param l LinkedList instance.
 * @param ss SnakeStats instance.
 * @param gridSize Map grid size.
 *
 * Author:	Ariraja Nuralamsyah (191511005)
 *			Bryan Azriel Parulian (191511008)
 *			Heldi Apriadi (191511015)
 */
void Snake__controller(LinkedList *l, SnakeStats *ss, int gridSize);

/**
 * Controller computer snake.
 * @param l LinkedList instance.
 * @param ss SnakeStats instance.
 * @param gridSize Map grid size.
 * @param tempS temporary coordinates that will be rendered for computer snake. 
 *
 * Author:	Ariraja Nuralamsyah (191511005)
 *			Heldi Apriadi (191511015)
 */
void Snake__controllerComputer(LinkedList *l, SnakeStats *ss, int gridSize, Point tempS);

/**
 * Displaying snake when dying.
 *
 * Author:	Ariraja Nuralamsyah (191511005)
 *			Bryan Azriel Parulian (191511008)
 *			Heldi Apriadi (191511015)
 */
void Snake__dyingCondition();

/**
 * Adding new node to Linked List.
 * @param l LinkedList instance.
 *
 * Author:	Ariraja Nuralamsyah (191511005)
 *			Bryan Azriel Parulian (191511008)
 */
void Snake__eatingProcess(LinkedList *l);

/**
 * Checking if snake collapse the snakebody.
 * @param l LinkedList instance.
 * @return condition when snake is already dead or not.
 *
 * Author:	Ariraja Nuralamsyah (191511005)
 *			Bryan Azriel Parulian (191511008)
 *			Heldi Apriadi (191511015)
 */
int Snake__collisionBody(LinkedList *l);

/**
 * Checking if conputer snake collapse the snakebody and the wall.
 * @param l LinkedList instance.
 * @return condition when snake is already dead or not.
 *
 * Author:	Bryan Azriel Parulian (191511008)
 *			Heldi Apriadi (191511015)
 */
int Snake__collisionComputer(LinkedList *l);

/**
 * Checking if snake collapse the wall.
 * @param l LinkedList instance.
 *
 * Author:	Ariraja Nuralamsyah (191511005)
 *			Bryan Azriel Parulian (191511008)
 *			Heldi Apriadi (191511015)
 */
void Snake__collisionMaps(LinkedList *l);

/* =============================================================================================== */

/**
 * Getting random food coordinate.
 * @param l LinkedList instance.
 * @param apple coordinate of apple.
 * @param mouse coordinate of mouse.
 * @param potion coordinate of potion.
 * @param ket information about the specific food that will get the random coordinate.
 *
 * Author:	Ariraja Nuralamsyah (191511005)
 *			Bryan Azriel Parulian (191511008)
 */
void Food__getRandCoordNonObs(LinkedList *l, Point *apple, Point *mouse, Point *potion, const char ket[8]);

/**
 * Checking if food collapse with snake or other food.
 * @param l LinkedList instance.
 * @param apple coordinate of apple.
 * @param mouse coordinate of mouse.
 * @param potion coordinate of potion.
 * @param ketFood information about the specific food that will checked.
 *
 * Author:	Ariraja Nuralamsyah (191511005)
 *			Bryan Azriel Parulian (191511008)
 */
void Food__checkCollisionNonObs(LinkedList *l, Point *apple, Point *mouse, Point *potion, const char ketFood[8]);

/**
 * Checking if foods are eaten by snake.
 * @param l LinkedList instance.
 * @param apple coordinate of apple.
 * @param mouse coordinate of mouse.
 * @param potion coordinate of potion.
 * @param dataPlayer Datas of player (name and score).
 * @param mousestats FoodStats instance (mouse).
 * @param potionstats FoodStats instance (potion).
 * @param ss SnakeStats instance.
 * @param barBoost image / spritehandler for bar boost gauge.
 *
 * Author:	Ariraja Nuralamsyah (191511005)
 *			Bryan Azriel Parulian (191511008)
 */
void Food__checkEatFoodNonObs(LinkedList *l, Point *apple, Point *mouse, Point *potion, Data *dataPlayer, FoodStats *mousestats, FoodStats *potionstats, SnakeStats *ss, void* barBoost);

/**
 * Checking the duration of special food (mouse and potion)
 * @param l LinkedList instance.
 * @param apple coordinate of apple.
 * @param mouse coordinate of mouse.
 * @param potion coordinate of potion.
 * @param score gamescore point.
 * @param mousestats FoodStats instance (mouse).
 * @param potionstats FoodStats instance (potion).
 * @param snakeSpeed current snake speed.
 *
 * Author:	Ariraja Nuralamsyah (191511005)
 *			Bryan Azriel Parulian (191511008)
 */
void Food__checkDuration(LinkedList *l, Point *apple, Point *mouse, Point *potion, FoodStats *mousestats, FoodStats *potionstats, int snakeSpeed);

/**
 * Getting random apple coordinates.
 * @param l LinkedList instance.
 * @param apple coordinate of apple.
 *
 * Author:	Ariraja Nuralamsyah (191511005)
 */
void Food__getRandCoordApple(LinkedList *l, Point *apple);

/**
 * Checking if food collapse with computer snake or other food.
 * @param l LinkedList instance.
 * @param apple coordinate of apple.
 *
 * Author:	Ariraja Nuralamsyah (191511005)
 */
void Food__checkCollisionAppleNonObs(LinkedList *l, Point *apple);

/**
 * Checking if foods are eaten by computer snake.
 * @param l LinkedList instance.
 * @param apple coordinate of apple.
 * @param dataPlayer player datas (name and score).
 * @param ss SnakeStats instance.
 *
 * Author:	Ariraja Nuralamsyah (191511005)
 */
void Food__checkEatAppleComputerSnake(LinkedList *l, Point *apple, Data *dataPlayer, SnakeStats *ss);

#endif
