#pragma once

#define LData int
#define LEN 20
class ArrayList
{
private:
	LData arr[LEN];
	int numOfData;
	int curPosition;
public:
	ArrayList();
	void LInsert(LData data);
	bool LFirst(LData* data);
	bool LNext(LData* data);
	LData LRemove();
	int LCount();
};

