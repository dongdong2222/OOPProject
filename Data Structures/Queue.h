#pragma once

#define Data int
class Queue
{
private:
	Data list[10];
	int front;
	int rear;
public:
	Queue() : front(0), rear(0)
	{  }
	bool QIsEmpty();
	void Enqueue(Data data);
	Data Dequeue();
	Data Qpeek();

	int MoveFront()
	{
		if (front == 9)
			return 0;
		front++;
		return front;
	}
	int MoveRear()
	{
		if (rear == 9)
			return 0;
		rear++;
		return rear;

	}
};

