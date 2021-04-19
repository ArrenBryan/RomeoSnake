/**
 *	Referance: https://www.geeksforgeeks.org/heap-sort/
 */

#ifndef HEAPSORT_H
#define HEAPSORT_H

#include <stdio.h>

typedef struct DataHighscore
{
	char playerName[5];
	int playerScore;
} DataHighscore;

/**
 * Heap Sort from minimum numbers to maximum numbers.
 *
 * @param data data array of numbers and player names.
 * @param arrayLength length of the array.
 *
 * Modified by Bryan Azriel Parulian (191511008)
 */
void HeapSortMin (DataHighscore *data, int arrayLength);

/**
 * Heap Sort from maximum numbers to minimum numbers.
 *
 * @param data data array of numbers and player names.
 * @param arrayLength length of the array.
 *
 * Modified by Bryan Azriel Parulian (191511008)
 */
void HeapSortMax (DataHighscore *data, int arrayLength);

/**
 * Build minimum heap.
 *
 * @param data data array of numbers and player names.
 * @param arrayLength length of the array.
 *
 * Modified by Bryan Azriel Parulian (191511008)
 */
void BuildMinHeapify (DataHighscore *data, int arrayLength);

/**
 * Build maximum heap.
 *
 * @param data data array of numbers and player names.
 * @param arrayLength length of the array.
 *
 * Modified by Bryan Azriel Parulian (191511008)
 */
void BuildMaxHeapify (DataHighscore *data, int arrayLength);

/**
 * Build minimum heap.
 *
 * @param data data array of numbers and player names.
 * @param heapSize size of the heap.
 * @param index index node / index array.
 * @param arrayLength length of the array.
 *
 * Modified by Bryan Azriel Parulian (191511008)
 */
void MinHeapify (DataHighscore *data, int heapSize, int index, int arrayLength);

/**
 * Build maximum heap.
 *
 * @param data data array of numbers and player names.
 * @param heapSize size of the heap.
 * @param index index node / index array.
 * @param arrayLength length of the array.
 *
 * Modified by Bryan Azriel Parulian (191511008)
 */
void MaxHeapify (DataHighscore *data, int heapSize, int index, int arrayLength);

/**
 * Get index of its parent.
 *
 * @param curr current index
 * @return index of its parent.
 *
 * Author: Bryan Azriel Parulian (191511008)
 */
int getParentIndex (int curr);

/**
 * Get index of its leftchild.
 *
 * @param curr current index
 * @return index of its leftchild.
 *
 * Author: Bryan Azriel Parulian (191511008)
 */
int getChildLeftIndex (int curr);

/**
 * Get index of its rightchild.
 *
 * @param curr current index
 * @return index of its rightchild.
 *
 * Author: Bryan Azriel Parulian (191511008)
 */
int getChildRightIndex (int curr);

/**
 * Swap numbers on array.
 *
 * @param data array of numbers and player names.
 * @param i the index that will swap.
 * @param j the index that will swap.
 *
 * Author: Bryan Azriel Parulian (191511008)
 */
void Swap (DataHighscore *data, int i, int j);

#endif
