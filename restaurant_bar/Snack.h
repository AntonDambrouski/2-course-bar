#pragma once
#include<iostream>
#include<fstream>
class Basket;
using namespace std;
class Snack
{
public:
	friend Basket;
	Snack();
	~Snack();
	void push_back();//���������� �������� � ����� ������
	void clear();// �������� ������
	int GetSize() { return Size; }//�������� ���������� ��������� � ������
	int& operator[](const int index);// ������������� �������� [] 
	void insert(int index);//���������� �������� � ������ �� ���������� �������
	void removeAt(int index);//�������� �������� � ������ �� ���������� �������
	void pop_back(); //�������� ���������� �������� � ������
	void Get_Snack_info(int index); // �������� ���������� � �������
	void SaveToFile();
	void read();
	void Sort_by_first_letter(char letter);
	void Get_name_id(const int index);
private:
	class Node
	{
	public:
		Node* pPrev;
		Node* pNext;
		int id;//���������� id
		char name[32];//��������
		float cost;//����
		char description[254];//������� ��������
		char timetoprepare[32];//����� �������������
		Node(Node* pNext = nullptr, Node* pPrev = nullptr)
		{
			this->pNext = pNext;
			this->pPrev = pPrev;
		}
	};
	int Size = 0;
	int uniquefordrinks;
	Node* head;
	Node* tail;
};

