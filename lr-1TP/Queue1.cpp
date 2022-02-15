#include <iostream>
#include "Queue1.h"
using namespace std;

int sonQueue_private::function23()
{
	Unit* last = get_last();  //указатель на тип данных 
	int sum = 0; //инициализирую сумму

	if (size == 0)
	{
		cout << "Очередь пуста!" << endl;
	}
	else
	{
		while (last != nullptr)
		{
			if (last->data % 2 == 0) {
				sum += last->data;
			}
			last = last->prev;
		}
	}
	return sum;
}
int sonQueue_private::pop() { return parQueue::pop(); }
void sonQueue_private::push(int el) { return parQueue::push(el); }
void sonQueue_private::print() { return parQueue::print(); }
void sonQueue_private::merge(sonQueue_private& Q1) { return parQueue::merge(Q1); }
void sonQueue_private::copy(sonQueue_private& Q1) { return parQueue::copy(Q1); }
bool sonQueue_private::isEmpty() { return parQueue::isEmpty(); }

int sonQueue_protected::function23()
{
	Unit* last = get_last();  //указатель на тип данных 
	int sum = 0; //инициализирую сумму

	if (size == 0)
	{
		cout << "Очередь пуста!" << endl;
	}
	else
	{
		while (last != nullptr)
		{
			if (last->data % 2 == 0)
				sum = sum + last->data;
		}
	}
	return sum;
}
int sonQueue_protected::pop() { return parQueue::pop(); }
void sonQueue_protected::push(int el) { return parQueue::push(el); }
void sonQueue_protected::print() { return parQueue::print(); }
void sonQueue_protected::merge(sonQueue_protected& Q1) { return parQueue::merge(Q1); }
void sonQueue_protected::copy(sonQueue_protected& Q1) { return parQueue::copy(Q1); }
bool sonQueue_protected::isEmpty() { return parQueue::isEmpty(); }

int sonQueue_public::function23()
{
	Unit* last = get_last();  //указатель на тип данных 
	int sum = 0; //инициализирую сумму

	if (size == 0)
	{
		cout << "Очередь пуста!" << endl;
	}
	else
	{
		while (last != nullptr)
		{
			if (last->data % 2 == 0)
				sum = sum + last->data;
		}
	}
	return sum;
}