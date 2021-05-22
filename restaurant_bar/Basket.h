#pragma once
#include"Drinks.h"
#include"Cocktail.h"
#include"Snack.h"

class Basket
{
public:
	Basket();
	~Basket();
	void push_back_drinks(Drinks& drinks, int index);//добавление элемента в конец списка
	void push_back_cocktails(Cocktail& cocktails, int index);
	void push_back_snacks(Snack& snacks, int index);
	void Get_basket_info();
	void clear();// очистить список
	int GetSize() { return Size; }//получить количество елементов в списке
	void removeAt(int index);//удаление элемента в списке по указанному индексу
	void pop_back(); //удаление последнего элемента в списке
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
		int id;//уникальный id
		string name;//название
		string type;
		float cost;//цена
		string description;//краткое описание
		string timetoprepare;
		int rate;//рейтинг, количество звёзд от 1 до 5
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