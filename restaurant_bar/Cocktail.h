#pragma once
#include<iostream>
#include<fstream>
class Basket;
using namespace std;
class Cocktail
{
public:
	friend Basket;
	Cocktail();
	~Cocktail();
	void push_back();//добавление элемента в конец списка
	void clear();// очистить список
	int GetSize() { return Size; }//получить количество елементов в списке
	int& operator[](const int index);// перегруженный оператор [] 
	void insert(int index);//добавление элемента в список по указанному индексу
	void removeAt(int index);//удаление элемента в списке по указанному индексу
	void pop_back(); //удаление последнего элемента в списке
	void Get_Cocktail_info(int index); // получить информацию о напитке
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
		int id;//уникальный id
		char name[32];//название
		float cost;//цена
		char description[254];//краткое описание
		int rate;//рейтинг, количество звёзд от 1 до 5
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

