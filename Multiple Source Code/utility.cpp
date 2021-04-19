#include "utility.hpp"

int getIntegerDigits(int data)
{
	int digitNumbers = 0;
	
	while (data != 0)
	{
		digitNumbers++;
		data = data / 10;
	}
	
	return digitNumbers;
}

bool **Array__create()
{
	int cols = 21, rows = 12;
	bool **arrayMap = (bool**) malloc (cols * sizeof(bool*));
	int i;
	for (i = 0; i < cols; i++)
	{
		arrayMap[i] = (bool*) malloc (rows * sizeof(bool));
	}

	return arrayMap;
}
