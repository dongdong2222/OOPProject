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


CLinkedList::CLinkedList() : numofData(0), cur(NULL)
{
	head = new FNode(0);
	tail = new FNode(0);
	head->next = tail;
	tail->prev = head;

}
void CLinkedList::LInsert(LData data)
{
	FNode* newNode = new FNode(data);

	newNode->next = head->next;
	head->next->prev = newNode;
	head->next = newNode;
	newNode->prev = head;

	numofData++;
}

bool CLinkedList::LFirst(LData* data)
{
	if (head->next == NULL)
		return false;

	cur = head->next;
	*data = cur->data;
	return true;
}

bool CLinkedList::LNext(LData* data)
{
	if (cur->next == tail)
		return false;

	cur = cur->next;
	*data = cur->data;
	return true;
}

bool CLinkedList::LPrevious(LData* data)
{
	if (cur->prev == head)
		return false;

	cur = cur->prev;
	*data = cur->data;
	return true;
}

LData CLinkedList::LRemove()
{
	FNode* rpos = cur;
	LData rdata = cur->data;

	cur->prev->next = cur->next;
	cur->next->prev = cur->prev;

	cur = cur->prev; // 틀림
	delete rpos;
	numofData--;
	return rdata;
}