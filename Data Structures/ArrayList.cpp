#include "ArrayList.h"

ArrayList::ArrayList() :numOfData(0), curPosition(-1)
{

}

void ArrayList::LInsert(LData data)
{
	if (numOfData > LEN)
		return;
	arr[numOfData++] = data;

}
bool ArrayList::LFirst(LData* data)
{
	if (numOfData == 0)
		return false;

	curPosition = 0;
	*data = arr[curPosition];
	return true;
}

bool ArrayList::LNext(LData* data)
{
	curPosition++;
	if (curPosition > (numOfData - 1))
		return false;

	*data = arr[curPosition];
	return true;
}

LData ArrayList::LRemove()
{
	LData rdata = arr[curPosition];

	for (int i = curPosition; i < numOfData - 1; i++)
	{
		arr[i] = arr[i + 1];
	}
	numOfData--;
	curPosition--;
	return rdata;
}

int ArrayList::LCount()
{
	return numOfData;
}