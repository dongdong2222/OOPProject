#include "ArrayList.h"
#include "LinkedList.h"
#include <iostream>
using namespace std;
int main()
{
	CLinkedList clist;
	int data;

	clist.LInsert(3);
	clist.LInsert(4);
	clist.LInsert(5);
	clist.LInsert(6);
	clist.LInsert(7);
	clist.LInsert(8);
	clist.LInsert(9);

	if (clist.LFirst(&data))
	{
		cout << data << endl;
		while (clist.LNext(&data))
		{
			cout << data << endl;
		}
	}
		
	if (clist.LFirst(&data))
	{
		if (data % 2 == 0)
			clist.LRemove();
		while (clist.LNext(&data))
		{
			if (data % 2 == 0)
				clist.LRemove();
		}
	}
	cout << "ÀçÁ¶È¸" << endl;
	if (clist.LFirst(&data))
	{
		cout << data << endl;
		while (clist.LNext(&data))
		{
			cout << data << endl;
		}
	}
}

