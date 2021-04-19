#ifndef UTILITY_H
#define UTILITY_H

#include "linkedlist.hpp"

/**
 * A single 2D point.
 */
typedef struct Point
{
    int coorX; // x-coordinate.
    int coorY; // y-coordinate.
} Point;

/**
 * Convert integers to digits.
 * @param data integers that will be converted.
 * @return digits (ex: 214 = 3 digits).
 *
 * Author:	Bryan Azriel Parulian (191511008)
 */
int getIntegerDigits(int data);

/**
 * Create arrayMap. [Constructor]
 * @return arrayMap.
 *
 * Author:	Bryan Azriel Parulian (191511008)
 */
bool **Array__create();

#endif
