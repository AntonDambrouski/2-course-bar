#include "Drinks.h"


Drinks::Drinks()
{
	Size_of_Drinks = 0;
	head = tail = nullptr;
	uniquefordrinks = 1; //id для всех элементов
	read();
}

Drinks::~Drinks()
{
	if (Size_of_Drinks)
	{
		SaveToFile();
	}
	clear();
}

void Drinks::push_back()
{
	if (Size_of_Drinks == 0)
	{
		head = tail = new Node();
		cout << "Введите название напитка: ";
		cin.ignore(1, '\n');
		cin.getline(head->name, 32);
		cout << "Введите тип: ";
		cin.getline(head->type, 32);
		cout << "Введите цену: ";
		cin >> head->cost;
		while (head->cost < 0)
		{
			cout << "Цена не может быть отрицательной!\n";
			cin >> head->cost;
		}
		cout << "Введите количество на складе: ";
		cin >> head->kolvo;
		cout << "Укажите рейтинг от 1 до 5 звезды: ";
		cin >> head->rate;
		while (head->rate < 0 || head->rate > 5)
		{
			cin >> head->rate;
		}
		head->id = uniquefordrinks;
		uniquefordrinks++;
		Size_of_Drinks++;
	}
	else
	{
		Node* addtoback = new Node();
		addtoback->pPrev = tail;
		tail->pNext = addtoback;
		tail = addtoback;
		cout << "Введите название напитка: ";
		cin.ignore(1, '\n');
		cin.getline(addtoback->name, 32);
		cout << "Введите тип: ";
		cin.getline(addtoback->type, 32);
		cout << "Введите цену: ";
		cin >> addtoback->cost;
		while (addtoback->cost < 0)
		{
			cout << "Цена не может быть отрицательной!\n";
			cin >> addtoback->cost;
		}
		cout << "Введите количество на складе: ";
		cin >> addtoback->kolvo;
		cout << "Укажите рейтинг от 1 до 5 звезды: ";
		cin >> addtoback->rate;
		while (addtoback->rate < 0 || addtoback->rate > 5)
		{
			cin >> addtoback->rate;
		}
		addtoback->id = uniquefordrinks;
		uniquefordrinks++;
		Size_of_Drinks++;
	}
}

void Drinks::clear()
{
	while (Size_of_Drinks)//пока размер не равен 0, вызываем метод удалить с конца
	{
		pop_back();
	}
	uniquefordrinks = 1;
}

int& Drinks::operator[](const int index)
{
	if (index == 0)
	{
		return head->id;
	}
	else if (Size_of_Drinks / 2 > index)
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
		int counter = Size_of_Drinks - 1;
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

void Drinks::insert(int index)
{
	if (Size_of_Drinks == 0) //если размер = 0, просто вызываем функцию вставка  в конец
	{
		push_back();
	}
	else if (head->id == index) // если айди головы равен нужного айди, то вставляем элемент на место головы
	{
		Node* ToAdd = new Node(head);
		cout << "Введите название напитка: ";
		cin.ignore(1, '\n');
		cin.getline(ToAdd->name, 32);
		cout << "Введите тип: ";
		cin.getline(ToAdd->type, 32);
		cout << "Введите цену: ";
		cin >> ToAdd->cost;
		while (ToAdd->cost < 0)
		{
			cout << "Цена не может быть отрицательной!\n";
			cin >> ToAdd->cost;
		}
		cout << "Введите количество на складе: ";
		cin >> ToAdd->kolvo;
		cout << "Укажите рейтинг от 1 до 5 звезды: ";
		cin >> ToAdd->rate;
		while (ToAdd->rate < 0 || ToAdd->rate > 5)
		{
			cin >> ToAdd->rate;
		}
		ToAdd->id = uniquefordrinks;
		uniquefordrinks++;
		Size_of_Drinks++;
		head->pPrev = ToAdd;
		head = ToAdd;
	}
	else if (index > Size_of_Drinks) // если индекс больше чем размер, пихаем в конец
	{
		push_back();
	}
	else							// иначе ищем элемент начиная с головы по индексу и произодим внедрение
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
		cout << "Введите название напитка: ";
		cin.ignore(1, '\n');
		cin.getline(ToAdd->name, 32);
		cout << "Введите тип: ";
		cin.getline(ToAdd->type, 32);
		cout << "Введите цену: ";
		cin >> ToAdd->cost;
		while (ToAdd->cost < 0)
		{
			cout << "Цена не может быть отрицательной!\n";
			cin >> ToAdd->cost;
		}
		cout << "Введите количество на складе: ";
		cin >> ToAdd->kolvo;
		cout << "Укажите рейтинг от 1 до 5 звезды: ";
		cin >> ToAdd->rate;
		while (ToAdd->rate < 0 || ToAdd->rate > 5)
		{
			cin >> ToAdd->rate;
		}
		ToAdd->id = uniquefordrinks;
		uniquefordrinks++;
		Size_of_Drinks++;
		ToAdd->pPrev = search;
		ToAdd->pNext = search->pNext;
		Node* Next = search->pNext;
		search->pNext = ToAdd;
		Next->pPrev = ToAdd;
	}
}

void Drinks::removeAt(int index)
{
	if (head->id == index)		//если айди головы равен нужному айди, то проверяем на количество элементов
	{
		if (Size_of_Drinks == 1) // если размер один, значит есть только голова и удалим её
		{
			delete head;
			Size_of_Drinks--;
		}
		else					// иначе голову двигаем на элемент в перёд и удаляем то что осталось
		{
			Node* ToDel = head;
			head = ToDel->pNext;
			delete ToDel;
			head->pPrev = nullptr;
			Size_of_Drinks--;
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
			Size_of_Drinks--;
		}
	}
}

void Drinks::pop_back()
{
	if (Size_of_Drinks == 1) // размер = 1, удаляем голову
	{
		delete head;
		Size_of_Drinks--;
	}
	else				// если != 1, то двигаем нашу голову вперёд
	{
		Node* ToDel = tail;
		tail = ToDel->pPrev;
		tail->pNext = nullptr;
		delete ToDel;
		Size_of_Drinks--;
	}
}

void Drinks::Get_drinks_info(int index) // также работаем с индексами
{
	if (index == head->id)
	{
		cout << "Индекс: " << head->id << endl;
		cout << "Название : " << head->name << endl;
		cout << "Тип напитка: " << head->type << endl;
		cout << "Цена: " << head->cost << " руб." << endl;
		cout << "Количество на складе: " << head->kolvo << endl;
		cout << "Рейтинг: " << head->rate << endl;
		cout << "---------------------------------" << endl;
	}
	else if (Size_of_Drinks / 2 > index)
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
		if (ToShow == nullptr)
		{
			cout << "Товара под таким индексом не существует!" << endl;
			return;
		}
		else
		{
			cout << "Индекс: " << ToShow->id << endl;
			cout << "Название : " << ToShow->name << endl;
			cout << "Тип напитка: " << ToShow->type << endl;
			cout << "Цена: " << ToShow->cost << " руб." << endl;
			cout << "Количество на складе: " << ToShow->kolvo << endl;
			cout << "Рейтинг: " << ToShow->rate << endl;
			cout << "---------------------------------" << endl;
		}
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
		if (ToShow == nullptr)
		{
			cout << "Товара под таким индексом не существует!" << endl;
			return;
		}
		else
		{
			cout << "Индекс: " << ToShow->id << endl;
			cout << "Название : " << ToShow->name << endl;
			cout << "Тип напитка: " << ToShow->type << endl;
			cout << "Цена: " << ToShow->cost << " руб." << endl;
			cout << "Количество на складе: " << ToShow->kolvo << endl;
			cout << "Рейтинг: " << ToShow->rate << endl;
			cout << "---------------------------------" << endl;
		}
	}
}

void Drinks::SaveToFile()
{
	Node* ToSave = head;
	ofstream fout;
	fout.open("Obj_read_save\\drinks.txt");
	while (ToSave != nullptr)
	{
		fout.write((char*)ToSave, sizeof(Node));
		ToSave = ToSave->pNext;
	}
	fout.close();
}

void Drinks::read()
{
	fstream fin;
	fin.open("Obj_read_save\\drinks.txt");
	head = tail = new Node();
	Node* ToAdd = head;
	Node* Prev = head;
	while (fin.read((char*)ToAdd, sizeof(Node)))
	{
		if (Size_of_Drinks != 0)
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
			Size_of_Drinks++;
		}
	}
	if (Size_of_Drinks == 0)
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

void Drinks::Add_kolv(int index)
{
	Node* search = head;
	while (search != nullptr)
	{
		if (search->id == index)
		{
			cout << "Название: " << search->name << endl;
			cout << "Сейчас на складе: " << search->kolvo << endl;
			cout << "Cколько желаете добавить?" << endl;
			cin >> index;
			search->kolvo += index;
			break;
		}
		search = search->pNext;
	}
	if (search == nullptr)
	{
		cout << "Напитка под таким id не найдено!" << endl;
	}
}

void Drinks::Sort_by_first_letter(char letter)
{
	char up = letter, down = letter;
	up -= 32;
	int pause = 4, counter = 0;
	down += 32;
	Node* search = head;
	if (Size_of_Drinks == 0)
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
				counter++;
				Get_drinks_info(search->id);
			}
			search = search->pNext;
		}
	}
}

void Drinks::Get_name_id(const int index)
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
