#include "Basket.h"

Basket::Basket()
{
	Size = 0;
	uniqueID = 1;
	head = tail = nullptr;
}

Basket::~Basket()
{
	clear();
}

void Basket::push_back_drinks(Drinks& drinks, int index)
{
	int kolv;
	if (Size == 0)
	{
		head = tail = new Node();
		Drinks::Node* search = drinks.head;
		while (search != nullptr)
		{
			if (search->id == index)
			{
				break;
			}
			search = search->pNext;
		}
		if (search != nullptr)
		{
			if (search->kolvo < 1)
			{
				cout << "Данного товара нет на складе!" << endl;
			}
			else
			{

				cout << "\nВведите количество покупаемого товара: ";
				cin >> kolv;
				while (kolv < 1)
				{
					cout << "Нельзя заказать меньше одного товара!" << endl;
					cout << "\nВведите количество покупаемого товара: ";
					cin >> kolv;
				}
				this->head->whatshow = 1;
				this->head->id = uniqueID;
				this->head->type = search->type;
				this->head->name = search->name;
				this->head->cost = search->cost;
				this->head->kolvo = search->kolvo;
				this->head->rate = search->rate;
				if (search->kolvo < kolv)
				{
					cout << "Не хватает товара!\n";
					cout << "Записали максимальное количество." << endl;
					this->head->kolvo = search->kolvo;
					search->kolvo = 0;
				}
				else
				{
					this->head->kolvo = kolv;
					search->kolvo -= kolv;
				}
				Size++;
				uniqueID++;
			}
		}
	}
	else
	{
		Node* ToAdd = new Node();
		tail->pNext = ToAdd;
		ToAdd->pPrev = tail;
		tail = ToAdd;
		Drinks::Node* search = drinks.head;
		while (search != nullptr)
		{
			if (search->id == index)
			{
				break;
			}
			search = search->pNext;
		}
		if (search != nullptr)
		{
			if (search->kolvo < 1)
			{
				cout << "Данного товара нет на складе!" << endl;
			}
			else
			{
				cout << "\nВведите количество покупаемого товара: ";
				cin >> kolv;
				while (kolv < 1)
				{
					cout << "Нельзя заказать меньше одного товара!" << endl;
					cout << "\nВведите количество покупаемого товара: ";
					cin >> kolv;
				}
				ToAdd->whatshow = 1;
				ToAdd->id = uniqueID;
				ToAdd->type = search->type;
				ToAdd->name = search->name;
				ToAdd->cost = search->cost;
				ToAdd->kolvo = search->kolvo;
				ToAdd->rate = search->rate;
				if (search->kolvo < kolv)
				{
					cout << "Не хватает товара!\n";
					cout << "Записали максимальное количество." << endl;
					this->head->kolvo = search->kolvo;
					search->kolvo = 0;
				}
				else
				{
					this->head->kolvo = kolv;
					search->kolvo -= kolv;
				}
				Size++;
				uniqueID++;
			}
		}
	}
}

void Basket::push_back_cocktails(Cocktail& cocktails, int index)
{
	int kolv;
	if (Size == 0)
	{
		head = tail = new Node();
		Cocktail::Node* search = cocktails.head;
		while (search != nullptr)
		{
			if (search->id == index)
			{
				break;
			}
			search = search->pNext;
		}
		if (search != nullptr)
		{
			cout << "\nВведите количество покупаемого товара: ";
			cin >> kolv;
			while (kolv < 1)
			{
				cout << "Нельзя заказать меняше одного товара!" << endl;
				cout << "\nВведите количество покупаемого товара: ";
				cin >> kolv;
			}
			this->head->whatshow = 2;
			this->head->id = uniqueID;
			this->head->name = search->name;
			this->head->cost = search->cost;
			this->head->kolvo = kolv;
			this->head->description = search->description;
			this->head->rate = search->rate;
			Size++;
			uniqueID++;
		}
	}
	else
	{
		Node* ToAdd = new Node();
		tail->pNext = ToAdd;
		ToAdd->pPrev = tail;
		tail = ToAdd;
		Cocktail::Node* search = cocktails.head;
		while (search != nullptr)
		{
			if (search->id == index)
			{
				break;
			}
			search = search->pNext;
		}
		if (search != nullptr)
		{
			cout << "\nВведите количество покупаемого товара: ";
			cin >> kolv;
			while (kolv < 1)
			{
				cout << "Нельзя заказать меняше одного товара!" << endl;
				cout << "\nВведите количество покупаемого товара: ";
				cin >> kolv;
			}
			ToAdd->whatshow = 2;
			ToAdd->id = uniqueID;
			ToAdd->name = search->name;
			ToAdd->cost = search->cost;
			ToAdd->kolvo = kolv;
			ToAdd->description = search->description;
			ToAdd->rate = search->rate;
			Size++;
			uniqueID++;
		}
	}
}

void Basket::push_back_snacks(Snack& snacks, int index)
{
	int kolv;
	if (Size == 0)
	{
		head = tail = new Node();
		Snack::Node* search = snacks.head;
		while (search != nullptr)
		{
			if (search->id == index)
			{
				break;
			}
			search = search->pNext;
		}
		if (search != nullptr)
		{
			cout << "\nВведите количество покупаемого товара: ";
			cin >> kolv;
			while (kolv < 1)
			{
				cout << "Нельзя заказать меняше одного товара!" << endl;
				cout << "\nВведите количество покупаемого товара: ";
				cin >> kolv;
			}
			this->head->whatshow = 3;
			this->head->id = uniqueID;
			this->head->name = search->name;
			this->head->cost = search->cost;
			this->head->kolvo = kolv;
			this->head->description = search->description;
			this->head->timetoprepare = search->timetoprepare;
			Size++;
			uniqueID++;
		}
	}
	else
	{
		Node* ToAdd = new Node();
		tail->pNext = ToAdd;
		ToAdd->pPrev = tail;
		tail = ToAdd;
		Snack::Node* search = snacks.head;
		while (search != nullptr)
		{
			if (search->id == index)
			{
				break;
			}
			search = search->pNext;
		}
		if (search != nullptr)
		{
			cout << "\nВведите количество покупаемого товара: ";
			cin >> kolv;
			while (kolv < 1)
			{
				cout << "Нельзя заказать меняше одного товара!" << endl;
				cout << "\nВведите количество покупаемого товара: ";
				cin >> kolv;
			}
			ToAdd->whatshow = 3;
			ToAdd->id = uniqueID;
			ToAdd->name = search->name;
			ToAdd->cost = search->cost;
			ToAdd->kolvo = kolv;
			ToAdd->description = search->description;
			ToAdd->timetoprepare = search->timetoprepare;
			Size++;
			uniqueID++;
		}
	}
}

void Basket::Get_basket_info()
{
	
	int size = 4;
	int move = 0;
	Node* ToShow = head;
	while (ToShow != nullptr)
	{
		if (move == size)
		{
			system("pause");
			size += 4;
		}
		if (ToShow->whatshow == 1)
		{
			cout << "Индекс: " << ToShow->id << endl;
			cout << "Тип напитка: " << ToShow->type << endl;
			cout << "Название : " << ToShow->name << endl;
			cout << "Цена: " << ToShow->cost << " руб." << endl;
			cout << "Рейтинг: " << ToShow->rate << endl;
			cout << "Количество в корзине: " << ToShow->kolvo << endl;
			cout << "---------------------------------" << endl;
		}
		else if (ToShow->whatshow == 2)
		{
			cout << "Индекс: " << ToShow->id << endl;
			cout << "Название : " << ToShow->name << endl;
			cout << "Цена: " << ToShow->cost << " руб." << endl;
			cout << "Описание: " << ToShow->description << endl;
			cout << "Рейтинг: " << ToShow->rate << endl;
			cout << "Количество в корзине: " << ToShow->kolvo << endl;
			cout << "---------------------------------" << endl;
		}
		else if (ToShow->whatshow == 3)
		{
			cout << "Индекс: " << ToShow->id << endl;
			cout << "Название : " << ToShow->name << endl;
			cout << "Цена: " << ToShow->cost << " руб." << endl;
			cout << "Описание: " << ToShow->description << endl;
			cout << "Количество в корзине: " << ToShow->kolvo << endl;
			cout << "---------------------------------" << endl;
		}
		ToShow = ToShow->pNext;
		move++;
	}
}

void Basket::clear()
{
	while (Size)//пока размер не равен 0, вызываем метод удалить с конца
	{
		pop_back();
	}
	uniqueID = 1;
}

void Basket::removeAt(int index)
{
	if (head->id == index)		//если айди головы равен нужному айди, то проверяем на количество элементов
	{
		if (Size == 1)			// если размер один, значит есть только голова и удалим её
		{
			delete head;
			Size--;
		}
		else					// иначе голову двигаем на элемент в перёд и удаляем то что осталось
		{
			Node* ToDel = head;
			head = ToDel->pNext;
			delete ToDel;
			head->pPrev = nullptr;
			Size--;
		}
	}
	else if (tail->id == index) // если айди хвоста равно нужному айди, метод удалить с конца
	{
		pop_back();
	}
	else						// иначе ищем по айди и удаляем
	{
		Node* previosly = head;
		while (previosly != nullptr)
		{
			if (previosly->id == index)
			{
				previosly = previosly->pPrev;
				break;
			}
			previosly = previosly->pNext;
		}
		if (previosly == nullptr)
		{
			return;
		}
		else
		{
			Node* ToDel = previosly->pNext;
			Node* Next = ToDel->pNext;
			previosly->pNext = Next;
			Next->pPrev = previosly;
			delete ToDel;
			Size--;
		}
	}
}

void Basket::pop_back()
{
	if (Size == 1) // размер = 1, удаляем голову
	{
		delete head;
		Size--;
	}
	else				// если != 1, то двигаем нашу голову вперёд
	{
		Node* ToDel = tail;
		tail = ToDel->pPrev;
		tail->pNext = nullptr;
		delete ToDel;
		Size--;
	}
}

void Basket::PrintBasketToFile()
{
	ofstream fout;
	fout.open("Basket\\basket.txt");
	Node* Setinfo = head;

	while (Setinfo != nullptr)
	{
		if (Setinfo->whatshow == 1)
		{
			fout << "Индекс: " << Setinfo->id << endl;
			fout << "Тип напитка: " << Setinfo->type << endl;
			fout << "Название : " << Setinfo->name << endl;
			fout << "Цена: " << Setinfo->cost << " руб." << endl;
			fout << "Рейтинг: " << Setinfo->rate << endl;
			fout << "Количество в корзине: " << Setinfo->kolvo << endl;
			fout << "---------------------------------" << endl;
		}
		else if (Setinfo->whatshow == 2)
		{
			fout << "Индекс: " << Setinfo->id << endl;
			fout << "Название : " << Setinfo->name << endl;
			fout << "Цена: " << Setinfo->cost << " руб." << endl;
			fout << "Описание: " << Setinfo->description << endl;
			fout << "Рейтинг: " << Setinfo->rate << endl;
			fout << "Количество в корзине: " << Setinfo->kolvo << endl;
			fout << "---------------------------------" << endl;
		}
		else if (Setinfo->whatshow == 3)
		{
			fout << "Индекс: " << Setinfo->id << endl;
			fout << "Название : " << Setinfo->name << endl;
			fout << "Цена: " << Setinfo->cost << " руб." << endl;
			fout << "Описание: " << Setinfo->description << endl;
			fout << "Количество в корзине: " << Setinfo->kolvo << endl;
			fout << "---------------------------------" << endl;
		}
		Setinfo = Setinfo->pNext;
	}
	fout.close();
}

void Basket::Read_from_basket()
{
	system("mode con cols=65 lines=40");
	int size = 0;
	ifstream fin;
	fin.open("Basket\\basket.txt");
	char ch[254];
	while (fin.getline(ch, 254))
	{
		if (size == 35 || size == 70 || size == 105)
		{
			system("pause");
		}
		cout << ch << endl;
		size++;
	}
	fin.close();
}

void Basket::Get_check()
{
	float itog = 0;
	if (Size != 0)
	{
		Get_basket_info();

		Node* count = head;
		while (count != nullptr)
		{
			itog += count->cost * count->kolvo;
			count = count->pNext;
		}
		cout << "Итого с вас : " << itog << " руб." << endl;
		clear();
	}
	else
	{
		cout << "Корзина пустая" << endl;
	}
}

void Basket::Get_name_id(const int index)
{
	if (index == 0)
	{
		cout << head->name << endl;
		cout << "id: " << head->id << endl;
	}
	else
	{
		int counter = 0;
		Node* search = head;
		while (search != nullptr)
		{
			if (index == counter)
			{
				cout << search->name << endl;
				cout << "id: " << search->id << endl;
			}
			search = search->pNext;
			counter++;

		}
	}
}