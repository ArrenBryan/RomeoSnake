#include "heapsort.hpp"

void HeapSortMin (DataHighscore *data, int arrayLength)
{
	int i;
	BuildMaxHeapify (data, arrayLength);
	
	// Sorting Process
	for (i = arrayLength - 1; i > 0; i--)
	{
		Swap (data, 0, i);
		MaxHeapify (data, i, 0, arrayLength);
	}
}

void HeapSortMax (DataHighscore *data, int arrayLength)
{
	int i;
	BuildMinHeapify (data, arrayLength);
	
	// Sorting Process
	for (i = arrayLength - 1; i > 0; i--)
	{
		Swap (data, 0, i);
		MinHeapify (data, i, 0, arrayLength);
	}
}
void BuildMinHeapify (DataHighscore *data, int arrayLength)
{
	int startIndex = getParentIndex (arrayLength - 1);
	int heapSize = arrayLength;
	int i;
	
	for (i = startIndex; i >= 0; i--)
	{
		MinHeapify (data, heapSize, i, arrayLength);
	}
}

void BuildMaxHeapify (DataHighscore *data, int arrayLength)
{
	int startIndex = getParentIndex (arrayLength - 1);
	int heapSize = arrayLength;
	int i;
	
	for (i = startIndex; i >= 0; i--)
	{
		MaxHeapify (data, heapSize, i, arrayLength);
	}
}

void MinHeapify (DataHighscore *data, int heapSize, int index, int arrayLength)
{
	int smallest = index;
	int leftChild = getChildLeftIndex (index);
	int rightChild = getChildRightIndex (index);

	if (leftChild < heapSize && data[leftChild].playerScore < data[smallest].playerScore)
	{
		smallest = leftChild;
	}
	
	if (rightChild < heapSize && data[rightChild].playerScore < data[smallest].playerScore)
	{
		smallest = rightChild;
	}
	
	if (smallest != index)
	{
		Swap (data, index, smallest);
		MinHeapify (data, heapSize, smallest, arrayLength);
	}
}

void MaxHeapify (DataHighscore *data, int heapSize, int index, int arrayLength)
{
	int largest = index;
	int leftChild = getChildLeftIndex (index);
	int rightChild = getChildRightIndex (index);

	if (leftChild < heapSize && data[leftChild].playerScore > data[largest].playerScore)
	{
		largest = leftChild;
	}
	
	if (rightChild < heapSize && data[rightChild].playerScore > data[largest].playerScore)
	{
		largest = rightChild;
	}
	
	if (largest != index)
	{
		Swap (data, index, largest);
		MaxHeapify (data, heapSize, largest, arrayLength);
	}
}

int getParentIndex (int curr)
{
	return (curr - 1) / 2;
}

int getChildLeftIndex (int curr)
{
	return 2*curr + 1;
}

int getChildRightIndex (int curr)
{
	return 2*curr + 2;
}

void Swap (DataHighscore *data, int i, int j)
{
	DataHighscore temp;
	temp = data[i];
	data[i] = data[j];
	data[j] = temp;
}
