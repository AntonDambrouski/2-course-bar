#include "Cocktail.h"


Cocktail::Cocktail()
{
	Size = 0;
	head = tail = nullptr;
	uniquefordrinks = 1; //id для всех элементов
	read();
}

Cocktail::~Cocktail()
{
	if (Size)
	{
		SaveToFile();
	}
	clear();
}

void Cocktail::push_back()
{
	if (Size == 0) // если размер = 0, создаём новый объект 
	{
		head = tail = new Node();// новый объект
		cout << "Введите название коктейля: ";
		cin.ignore(1, '\n');
		cin.getline(head->name, 32);
		cout << "Введите цену: ";
		cin >> head->cost;
		while (head->cost < 0)
		{
			cout << "Цена не может быть отрицательной!\n";
			cin >> head->cost;
		}
		cout << "Введите краткое описание: ";
		cin.ignore(1, '\n');
		cin.getline(head->description, 254);
		cout << "Укажите рейтинг от 1 до 5 звезды: ";
		cin >> head->rate;
		while (head->rate > 5 || head->rate < 0)
		{
			cin >> head->rate;
		}
		head->id = uniquefordrinks;
		uniquefordrinks++;
		Size++;
	}
	else							  //если размер != 0, то добавим объект в конец
	{
		Node* addtoback = new Node(); //создаём объект для добавления
		addtoback->pPrev = tail;	  //предыдущий равен наш последний элемент
		tail->pNext = addtoback;	  //следующий после последнего была пустота, теперь это наш новый объект
		tail = addtoback;			  //наш хвост сново последний
		cout << "Введите название коктейля: ";
		cin.ignore(1, '\n');
		cin.getline(addtoback->name, 32);
		cout << "Введите цену: ";
		cin >> addtoback->cost;
		while (addtoback->cost < 0)
		{
			cout << "Цена не может быть отрицательной!\n";
			cin >> addtoback->cost;
		}
		cout << "Введите краткое описание: ";
		cin.ignore(1, '\n');
		cin.getline(addtoback->description, 254);
		cout << "Укажите рейтинг от 1 до 5 звезды: ";
		cin >> addtoback->rate;
		while (addtoback->rate > 5 || addtoback->rate < 0)
		{
			cin >> addtoback->rate;
		}
		addtoback->id = uniquefordrinks;
		uniquefordrinks++;
		Size++;
	}
}

void Cocktail::clear()
{
	while (Size)//пока размер не равен 0, вызываем метод удалить с конца
	{
		pop_back();
	}
	uniquefordrinks = 1;
}

int& Cocktail::operator[](const int index)
{
	if (index == 0)
	{
		return head->id;
	}
	else if (Size / 2 > index)
	{
		int counter = 0;
		Node* search = head;
		while (search != nullptr)
		{
			if (index == counter)
			{
				return search->id;
			}
			search = search->pNext;
			counter++;
		}
	}
	else
	{
		int counter = Size - 1;
		Node* search = tail;
		while (search != nullptr)
		{
			if (counter == index)
			{
				return search->id;
			}
			search = search->pPrev;
			counter--;
		}
	}
}

void Cocktail::insert(int index)
{
	if (Size == 0)
	{
		push_back();
	}
	else if (head->id == index)
	{
		Node* ToAdd = new Node(head);
		cout << "Введите название коктейля: ";
		cin.ignore(1, '\n');
		cin.getline(ToAdd->name, 32);
		cout << "Введите цену: ";
		cin >> ToAdd->cost;
		while (ToAdd->cost < 0)
		{
			cout << "Цена не может быть отрицательной!\n";
			cin >> ToAdd->cost;
		}
		cout << "Введите краткое описание: ";
		cin.ignore(1, '\n');
		cin.getline(ToAdd->description, 32);
		cout << "Укажите рейтинг от 1 до 5 звезды: ";
		cin >> ToAdd->rate;
		while (ToAdd->rate > 5 || ToAdd->rate < 0)
		{
			cin >> ToAdd->rate;
		}
		ToAdd->id = uniquefordrinks;
		uniquefordrinks++;
		Size++;
		head->pPrev = ToAdd;
		head = ToAdd;
	}
	else if (index > Size)
	{
		push_back();
	}
	else
	{
		Node* search = head;
		while (search != nullptr)
		{
			if (search->id == index)
			{
				search = search->pPrev;
				break;
			}
			search = search->pNext;
		}
		Node* ToAdd = new Node();
		cout << "Введите название коктейля: ";
		cin.ignore(1, '\n');
		cin.getline(ToAdd->name, 32);
		cout << "Введите цену: ";
		cin >> ToAdd->cost;
		while (ToAdd->cost < 0)
		{
			cout << "Цена не может быть отрицательной!\n";
			cin >> ToAdd->cost;
		}
		cout << "Введите краткое описание: ";
		cin.ignore(1, '\n');
		cin.getline(ToAdd->description, 32);
		cout << "Укажите рейтинг от 1 до 5 звезды: ";
		cin >> ToAdd->rate;
		while (ToAdd->rate > 5 || ToAdd->rate < 0)
		{
			cin >> ToAdd->rate;
		}
		ToAdd->id = uniquefordrinks;
		uniquefordrinks++;
		Size++;
		ToAdd->pPrev = search;
		ToAdd->pNext = search->pNext;
		Node* Next = search->pNext;
		search->pNext = ToAdd;
		Next->pPrev = ToAdd;
	}
}

void Cocktail::removeAt(int index)
{
	if (head->id == index)		//если айди головы равен нужному айди, то проверяем на количество элементов
	{
		if (Size == 1) // если размер один, значит есть только голова и удалим её
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

void Cocktail::pop_back()
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

void Cocktail::Get_Cocktail_info(int index) // также работаем с индексами
{
	if (index == head->id)
	{
		cout << "Индекс: " << head->id << endl;
		cout << "Название: " << head->name << endl;
		cout << "Цена: " << head->cost << " руб." << endl;
		cout << "Описание: " << head->description << endl;
		cout << "Рейтинг: " << head->rate << endl;
		cout << "---------------------------------" << endl;
	}
	else if (Size / 2 > index)
	{
		Node* ToShow = head;
		while (ToShow != nullptr)
		{
			if (ToShow->id == index)
			{
				break;
			}
			ToShow = ToShow->pNext;
		}
		cout << "Индекс: " << ToShow->id << endl;
		cout << "Название: " << ToShow->name << endl;
		cout << "Цена: " << ToShow->cost << " руб." << endl;
		cout << "Описание: " << ToShow->description << endl;
		cout << "Рейтинг: " << ToShow->rate << endl;
		cout << "---------------------------------" << endl;
	}
	else
	{
		Node* ToShow = tail;
		while (ToShow != nullptr)
		{
			if (ToShow->id == index)
			{
				break;
			}
			ToShow = ToShow->pPrev;
		}
		if (ToShow != nullptr)
		{
			cout << "Индекс: " << ToShow->id << endl;
			cout << "Название: " << ToShow->name << endl;
			cout << "Цена: " << ToShow->cost << " руб." << endl;
			cout << "Описание: " << ToShow->description << endl;
			cout << "Рейтинг: " << ToShow->rate << endl;
			cout << "---------------------------------" << endl;
		}
	}
}

void Cocktail::SaveToFile()
{
	Node* ToSave = head;
	ofstream fout;
	fout.open("Obj_read_save\\cocktail.txt");
	while (ToSave != nullptr)
	{
		fout.write((char*)ToSave, sizeof(Node));
		ToSave = ToSave->pNext;
	}
	fout.close();
}

void Cocktail::read()
{
	fstream fin;
	fin.open("Obj_read_save\\cocktail.txt");
	head = tail = new Node();
	Node* ToAdd = head;
	Node* Prev = head;
	while (fin.read((char*)ToAdd, sizeof(Node)))
	{
		if (Size != 0)
		{
			Prev->pNext = ToAdd;
			ToAdd->pPrev = Prev;
		}
		if (ToAdd->id != 0)
		{
			Prev = ToAdd;
			tail = ToAdd;
			ToAdd = Prev->pNext;
			ToAdd = new Node();
			Size++;
		}
	}
	if (Size == 0)
	{
		delete head;
	}
	else
	{
		tail->pNext = nullptr;
		uniquefordrinks = tail->id + 1;
	}
	fin.close();
}

void Cocktail::Sort_by_first_letter(char letter)
{
	char up = letter, down = letter;
	up -= 32;
	down += 32;
	int pause = 4, counter = 0;
	Node* search = head;
	if (Size == 0)
	{
		cout << "Ничего не найдено." << endl;
	}
	else
	{
		while (search != nullptr)
		{
			if (search->name[0] == letter || search->name[0] == up || search->name[0] == down)
			{
				if (counter == pause)
				{
					system("pause");
					pause += 4;
				}
				Get_Cocktail_info(search->id);
				counter++;
			}
			search = search->pNext;
		}
	}
}


void Cocktail::Get_name_id(const int index)
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