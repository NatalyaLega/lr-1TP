#pragma once

typedef struct Unit //������� �������
{
	int data = 0; //��������
	Unit* prev = 0; //��������� �� ��������� �������
} Unit;

class parQueue
{
private:
	Unit* last = 0; //��������� �� "�����" �������
protected:
	int size; //������ �������

public:

	parQueue(); //����������� ��� ����������
	~parQueue(); //����������
	Unit* get_last(); //���������� ������� ������ ����� �������
	int pop(); //�������� �������� �������
	void push(int el); //���������� �������� �������
	void print(); //����� �� ������� �������
	void merge(parQueue& Q1); //������� ���� ��������
	void copy(parQueue& Q); //����������� �������
	bool isEmpty(); //�������� �� �������������
};