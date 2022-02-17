#pragma once

typedef struct Unit //элемент очереди
{
	int data = 0; //значение
	Unit* prev = 0; //указатель на предыдущи элемент
} Unit;

class parQueue
{
private:
	Unit* last = 0; //указатель на "конец" очереди
protected:
	int size; //размер очереди

public:

	parQueue(); //конструктор без параметров
	~parQueue(); //деструктор
	Unit* get_last(); //объ€вление функции вз€ти€ конца очереди
	int pop(); //удаление элемента очереди
	void push(int el); //добавление элемента очереди
	void print(); //вывод на консоль очереди
	void merge(parQueue& Q1); //сли€ние двух очередей
	void copy(parQueue& Q); //копирование очереди
	bool isEmpty(); //проверка на заполненность
};