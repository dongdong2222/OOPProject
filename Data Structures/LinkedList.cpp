#include "LinkedList.h"
#include <iostream>
//��������
bool WhoIsPrecede(LData d1, LData d2)
{
	if (d1 < d2)
		return true; //d1�� ���� ������ �ռ���.
	else
		return false; //d2�� ���ļ����� �ռ��ų� ����.
}

LinkedList::LinkedList() :numofData(0), comp(WhoIsPrecede)
{
	head = new Node(0, NULL);

}

void LinkedList::LInsert(LData data)
{
	if (comp == NULL)
		FInsert(data); //���ı��ؾ��� �߰�
	else
		SInsert(data); //���ı��ش�� �߰�

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

	before = cur; //before->next �Ұ�
	cur = cur->next;
	*data = cur->data;
	return true;
}

LData LinkedList::LRemove() //���� ȣ���� �Ұ��ϴ�.
{
	Node* temp = cur;
	LData data = temp->data;
	before->next = cur->next;
	cur = before; //LFirst �� LNext�� ȣ��Ǹ� before�� �缳���� �̷���

	delete temp;
	numofData--;
	return data;
}
void LinkedList::SInsert(LData data)
{
	Node* newNode = new Node(data, NULL);
	Node* pred = head;
	
	//comp�� true�� d1�� d2���� ���Ļ� �տ� ��ġ�Ѵ� false�� �ƴϴ�
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

	cur = cur->prev; // Ʋ��
	delete rpos;
	numofData--;
	return rdata;
}