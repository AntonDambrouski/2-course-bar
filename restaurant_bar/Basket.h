#pragma once
#include"Drinks.h"
#include"Cocktail.h"
#include"Snack.h"

class Basket
{
public:
	Basket();
	~Basket();
	void push_back_drinks(Drinks& drinks, int index);//���������� �������� � ����� ������
	void push_back_cocktails(Cocktail& cocktails, int index);
	void push_back_snacks(Snack& snacks, int index);
	void Get_basket_info();
	void clear();// �������� ������
	int GetSize() { return Size; }//�������� ���������� ��������� � ������
	void removeAt(int index);//�������� �������� � ������ �� ���������� �������
	void pop_back(); //�������� ���������� �������� � ������
	void PrintBasketToFile();
	void Read_from_basket();
	void Get_check();
	void Get_name_id(const int index);
private:
	class Node
	{
	public:
		Node* pPrev;
		Node* pNext;
		int id;//���������� id
		string name;//��������
		string type;
		float cost;//����
		string description;//������� ��������
		string timetoprepare;
		int rate;//�������, ���������� ���� �� 1 �� 5
		int kolvo;
		int whatshow;
		Node(Node* pNext = nullptr, Node* pPrev = nullptr)
		{
			this->pNext = pNext;
			this->pPrev = pPrev;
		}
	};
	int Size = 0;
	int uniqueID;
	Node* head;
	Node* tail;
};