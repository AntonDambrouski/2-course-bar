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
	void push_back();//добавление элемента в конец списка
	void clear();// очистить список
	int GetSize() { return Size_of_Drinks; }//получить количество элементов в списке
	int& operator[](const int index);// перегруженный оператор [] 
	void insert(int index);//добавление элемента в список по указанному индексу
	void removeAt(int index);//удаление элемента в списке по указанному индексу
	void pop_back(); //удаление последнего элемента в списке
	void Get_drinks_info(int index); // получить информацию о напитке
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
		int id;//уникальный id
		char type[32];//тип напитка
		char name[32];//название
		float cost;//цена
		int kolvo;//количество на складе
		int rate;//рейтинг, количество звёзд от 1 до 5
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
