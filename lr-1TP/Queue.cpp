#include <iostream>
#include "Queue.h"
using namespace std;

parQueue::parQueue() //конструктор - инициализация размер и последнего элемент
{
	size = 0;
	last = nullptr;
}

parQueue::~parQueue() //деструктор
{
	while (size > 0) //пока размер > 0
	{
		Unit* temp = last; //временной переменной присваиваем значение последнего
		last = temp->prev; //последняя становится "предыдущей"
		delete temp; //удаляем последнюю
		size--; //уменьшаем размер
	}
}

Unit* parQueue::get_last()  //возвр. последний элемент
{
	return last;
}

int parQueue::pop()
{
	setlocale(LC_ALL, "Rus");
	Unit* tmp = last;
	int deldata = 0;

	if (tmp->prev == nullptr) //если в очереди один элемент (указатель на предыдущий элемент нулевой), то
	{
		deldata = tmp->data;
		delete last; //удаляем "последний" элемент
		last = nullptr; //и присваиваем ему ноль
		size--; //уменьшаем размер
	}
	else
	{	// в последнем содержится указатель на "следующий" элемент очереди, но не на последний
		while (tmp->prev->prev != nullptr) //идем по элементам до "второго" в очереди
		{
			tmp = tmp->prev;
		}
		deldata = tmp->prev->data;
		delete tmp->prev;
		tmp->prev = nullptr;
		size--;
	}
	return deldata;
}

void parQueue::push(int el)  //добавление элемента
{
	Unit* new_unit = new Unit; //выделяем память под новый элемент
	new_unit->prev = last; //указатель нового элемента указывает на последний в очереди
	last = new_unit; //теперь новый элемент стал последним
	last->data = el; //присваиваем данные
	size++;
}

void parQueue::print() //вывод
{
	Unit* tmp = last;

	while (tmp->prev != nullptr)
	{
		cout << tmp->data << " --> "; //выводим значения (с конца), пока указатель на следующий элемент не будет нулевым
		tmp = tmp->prev;
	}
	cout << tmp->data << endl; //вывели последний элемент
}

void parQueue::copy(parQueue& Q) // копирование очереди
{
	int* buff = new int[Q.size]; //создаем буферный массив
	Unit* el_queue = Q.last; //создаем переменную очереди

	for (int i = Q.size - 1; i >= 0; i--)
	{
		buff[i] = el_queue->data; //во временный массив заносим данные от "конца" текущей очереди
		el_queue = el_queue->prev; //переходим дальше по очереди
	}

	for (int i = 0; i < Q.size; i++)
	{
		this->push(buff[i]);
	}

	delete[] buff;  
}

void parQueue::merge(parQueue& Q1) //слияние 2х очередей
{
	int* buff1 = new int[Q1.size];
	Unit* el_queue1 = Q1.last;

	for (int i = Q1.size - 1; i >= 0; i--)
	{
		buff1[i] = el_queue1->data;
		el_queue1 = el_queue1->prev;
	}

	for (int i = 0; i < Q1.size; i++)
	{
		this->push(buff1[i]);
	}
	delete[] buff1;
	cout << "Слияние успешно завершено!" << endl;
}

bool parQueue::isEmpty() //проверка
{
	if (size == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}
