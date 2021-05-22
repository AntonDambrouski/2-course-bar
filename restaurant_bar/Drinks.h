#pragma once
#include<iostream>
#include<fstream>

using namespace std;
class Basket;
class Drinks
{
public:
	Drinks();
	~Drinks();
	void push_back();//���������� �������� � ����� ������
	void clear();// �������� ������
	int GetSize() { return Size_of_Drinks; }//�������� ���������� ��������� � ������
	int& operator[](const int index);// ������������� �������� [] 
	void insert(int index);//���������� �������� � ������ �� ���������� �������
	void removeAt(int index);//�������� �������� � ������ �� ���������� �������
	void pop_back(); //�������� ���������� �������� � ������
	void Get_drinks_info(int index); // �������� ���������� � �������
	void SaveToFile();
	void read();
	void Add_kolv(int index);
	void Sort_by_first_letter(char letter);
	void Get_name_id(const int index);
	friend Basket;
private:
	class Node
	{
	public:
		Node* pPrev;
		Node* pNext;
		int id;//���������� id
		char type[32];//��� �������
		char name[32];//��������
		float cost;//����
		int kolvo;//���������� �� ������
		int rate;//�������, ���������� ���� �� 1 �� 5
		Node(Node* pNext = nullptr, Node* pPrev = nullptr)
		{
			this->pNext = pNext;
			this->pPrev = pPrev;
		}
	};
	int Size_of_Drinks = 0;
	int uniquefordrinks;
	Node* head;
	Node* tail;
};
