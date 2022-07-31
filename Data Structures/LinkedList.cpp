#include "LinkedList.h"
#include <iostream>
//오름차순
bool WhoIsPrecede(LData d1, LData d2)
{
	if (d1 < d2)
		return true; //d1이 정렬 순서상 앞선다.
	else
		return false; //d2가 정렬순서상 앞서거나 같다.
}

LinkedList::LinkedList() :numofData(0), comp(WhoIsPrecede)
{
	head = new Node(0, NULL);

}

void LinkedList::LInsert(LData data)
{
	if (comp == NULL)
		FInsert(data); //정렬기준없이 추가
	else
		SInsert(data); //정렬기준대로 추가

	numofData++;
}

void LinkedList::FInsert(LData data)
{
	Node* newNode = new Node(data, NULL);
	newNode->next = head->next;
	head->next = newNode;
}

bool LinkedList::LFirst(LData* data)
{
	if (head->next == NULL)
		return false;

	before = head;
	cur = head->next;
	*data = cur->data;

	return true;
}

bool LinkedList::LNext(LData* data)
{
	if (cur->next == NULL)
		return false;

	before = cur; //before->next 불가
	cur = cur->next;
	*data = cur->data;
	return true;
}

LData LinkedList::LRemove() //연속 호출이 불가하다.
{
	Node* temp = cur;
	LData data = temp->data;
	before->next = cur->next;
	cur = before; //LFirst 나 LNext가 호출되면 before의 재설정이 이뤄짐

	delete temp;
	numofData--;
	return data;
}
void LinkedList::SInsert(LData data)
{
	Node* newNode = new Node(data, NULL);
	Node* pred = head;
	
	//comp가 true시 d1이 d2보다 정렬상 앞에 위치한다 false시 아니다
	while (pred->next == NULL && !comp(data, pred->next->data))
	{
		pred = pred->next;
	}

	newNode->next = pred->next;
	pred->next = newNode;
	numofData++;
}

void LinkedList::SetSortRule(bool (*comp)(LData num1, LData num2))
{
	this->comp = comp;
}

