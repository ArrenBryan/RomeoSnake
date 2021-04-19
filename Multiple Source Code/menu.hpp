#ifndef MENU_H
#define MENU_H

#include <string.h>
#include "renderer.hpp"
#include "game.hpp"
#include "config.hpp"

/**
 * Snake body direction enum.
 */
typedef enum Button
{
    arrowright = 0,       // player pressed arrow right.
    arrowleft = 1,        // player pressed arrow left.
    arrowup = 2,          // player pressed arrow up.
    arrowdown = 3,        // player pressed arrow down.
    enter = 4,			  // player pressed enter.			
    esc = 5,			  // player pressed esc.
} Button;

/**
 * Controller cursor menu.
 * @param ket information about the specific cursor menu that will controled. 
 *
 * Author:	Azhar Bani Rashif (191511007)
 *			Bryan Azriel Parulian (191511008)
 *			Hana Tiara Fadilah (191511014)
 */
void Menu__cursorControlMenu(const char ket[15]);

/**
 * Checking if cursor menu exceed / surpass the button. 
 * @param x x-coordinate.
 * @param y y-coordinate.
 * @param ket information about the specific how many button in that menu will displayed.  
 *
 * Author:	Azhar Bani Rashif (191511007)
 *			Bryan Azriel Parulian (191511008)
 *			Hana Tiara Fadilah (191511014)
 */
void Menu__checkCursorButton(int *x, int *y, const char ket[15]);

/**
 * Checking the input if enter button pressed.
 * @param x x-coordinate.
 * @param y y-coordinate.
 * @param ket information about the specific menu that will displayed.  
 *
 * Author:	Azhar Bani Rashif (191511007)
 *			Bryan Azriel Parulian (191511008)
 *			Hana Tiara Fadilah (191511014)
 */
void Menu__checkEnterButton(int x, int y, const char ket[15]);

#endif
