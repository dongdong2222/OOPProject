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

