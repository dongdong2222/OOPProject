#include "Queue.h"

bool Queue::QIsEmpty()
{
	if (front == rear)
		return true;
	return false;
}
void Queue::Enqueue(Data data)
{
	if (rear + 1 == front) // full�Ͻ�
		return;
	list[MoveRear()] = data;
}

Data Queue::Dequeue()
{
	if (QIsEmpty()) //empty�Ͻ�
		return -1;
	MoveFront();
	return list[front];
}

Data Queue::Qpeek()
{
	int index = front + 1;
	return list[index];
}