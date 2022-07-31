#pragma once

#define LData int

class Node
{
private:
public:
	LData data;
	Node* next;
	Node(LData data, Node* next) :data(data), next(next)
	{ }
};

class FNode
{
public:
	LData data;
	FNode* prev;
	FNode* next;
	FNode(LData data) :data(data)
	{ }
};

class LinkedList
{
private:
	Node* head;
	Node* cur; //���� ������ ���
	Node* before; //������ ���
	int numofData; //��ȿ�� ����� ��
	bool (*comp)(LData d1, LData d2);

public:
	LinkedList();
	void LInsert(LData data);
	void FInsert(LData data);
	void SInsert(LData data);
	bool LFirst(LData* data);
	bool LNext(LData* data);
	LData LRemove();
	int LCount();
	//�߰�
	void SetSortRule(bool (*comp)(LData num1, LData num2));
};




class CLinkedList
{
private:
	FNode* head;
	FNode* tail;
	FNode* cur;
	int numofData;
public:
	CLinkedList();
	void LInsert(LData data);
	bool LFirst(LData* data);
	bool LNext(LData* data);
	bool LPrevious(LData* data);
	LData LRemove();

};

