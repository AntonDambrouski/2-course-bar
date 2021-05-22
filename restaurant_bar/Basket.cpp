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
				cout << "������� ������ ��� �� ������!" << endl;
			}
			else
			{

				cout << "\n������� ���������� ����������� ������: ";
				cin >> kolv;
				while (kolv < 1)
				{
					cout << "������ �������� ������ ������ ������!" << endl;
					cout << "\n������� ���������� ����������� ������: ";
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
					cout << "�� ������� ������!\n";
					cout << "�������� ������������ ����������." << endl;
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
				cout << "������� ������ ��� �� ������!" << endl;
			}
			else
			{
				cout << "\n������� ���������� ����������� ������: ";
				cin >> kolv;
				while (kolv < 1)
				{
					cout << "������ �������� ������ ������ ������!" << endl;
					cout << "\n������� ���������� ����������� ������: ";
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
					cout << "�� ������� ������!\n";
					cout << "�������� ������������ ����������." << endl;
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
			cout << "\n������� ���������� ����������� ������: ";
			cin >> kolv;
			while (kolv < 1)
			{
				cout << "������ �������� ������ ������ ������!" << endl;
				cout << "\n������� ���������� ����������� ������: ";
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
			cout << "\n������� ���������� ����������� ������: ";
			cin >> kolv;
			while (kolv < 1)
			{
				cout << "������ �������� ������ ������ ������!" << endl;
				cout << "\n������� ���������� ����������� ������: ";
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
			cout << "\n������� ���������� ����������� ������: ";
			cin >> kolv;
			while (kolv < 1)
			{
				cout << "������ �������� ������ ������ ������!" << endl;
				cout << "\n������� ���������� ����������� ������: ";
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
			cout << "\n������� ���������� ����������� ������: ";
			cin >> kolv;
			while (kolv < 1)
			{
				cout << "������ �������� ������ ������ ������!" << endl;
				cout << "\n������� ���������� ����������� ������: ";
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
			cout << "������: " << ToShow->id << endl;
			cout << "��� �������: " << ToShow->type << endl;
			cout << "�������� : " << ToShow->name << endl;
			cout << "����: " << ToShow->cost << " ���." << endl;
			cout << "�������: " << ToShow->rate << endl;
			cout << "���������� � �������: " << ToShow->kolvo << endl;
			cout << "---------------------------------" << endl;
		}
		else if (ToShow->whatshow == 2)
		{
			cout << "������: " << ToShow->id << endl;
			cout << "�������� : " << ToShow->name << endl;
			cout << "����: " << ToShow->cost << " ���." << endl;
			cout << "��������: " << ToShow->description << endl;
			cout << "�������: " << ToShow->rate << endl;
			cout << "���������� � �������: " << ToShow->kolvo << endl;
			cout << "---------------------------------" << endl;
		}
		else if (ToShow->whatshow == 3)
		{
			cout << "������: " << ToShow->id << endl;
			cout << "�������� : " << ToShow->name << endl;
			cout << "����: " << ToShow->cost << " ���." << endl;
			cout << "��������: " << ToShow->description << endl;
			cout << "���������� � �������: " << ToShow->kolvo << endl;
			cout << "---------------------------------" << endl;
		}
		ToShow = ToShow->pNext;
		move++;
	}
}

void Basket::clear()
{
	while (Size)//���� ������ �� ����� 0, �������� ����� ������� � �����
	{
		pop_back();
	}
	uniqueID = 1;
}

void Basket::removeAt(int index)
{
	if (head->id == index)		//���� ���� ������ ����� ������� ����, �� ��������� �� ���������� ���������
	{
		if (Size == 1)			// ���� ������ ����, ������ ���� ������ ������ � ������ �
		{
			delete head;
			Size--;
		}
		else					// ����� ������ ������� �� ������� � ���� � ������� �� ��� ��������
		{
			Node* ToDel = head;
			head = ToDel->pNext;
			delete ToDel;
			head->pPrev = nullptr;
			Size--;
		}
	}
	else if (tail->id == index) // ���� ���� ������ ����� ������� ����, ����� ������� � �����
	{
		pop_back();
	}
	else						// ����� ���� �� ���� � �������
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
	if (Size == 1) // ������ = 1, ������� ������
	{
		delete head;
		Size--;
	}
	else				// ���� != 1, �� ������� ���� ������ �����
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
			fout << "������: " << Setinfo->id << endl;
			fout << "��� �������: " << Setinfo->type << endl;
			fout << "�������� : " << Setinfo->name << endl;
			fout << "����: " << Setinfo->cost << " ���." << endl;
			fout << "�������: " << Setinfo->rate << endl;
			fout << "���������� � �������: " << Setinfo->kolvo << endl;
			fout << "---------------------------------" << endl;
		}
		else if (Setinfo->whatshow == 2)
		{
			fout << "������: " << Setinfo->id << endl;
			fout << "�������� : " << Setinfo->name << endl;
			fout << "����: " << Setinfo->cost << " ���." << endl;
			fout << "��������: " << Setinfo->description << endl;
			fout << "�������: " << Setinfo->rate << endl;
			fout << "���������� � �������: " << Setinfo->kolvo << endl;
			fout << "---------------------------------" << endl;
		}
		else if (Setinfo->whatshow == 3)
		{
			fout << "������: " << Setinfo->id << endl;
			fout << "�������� : " << Setinfo->name << endl;
			fout << "����: " << Setinfo->cost << " ���." << endl;
			fout << "��������: " << Setinfo->description << endl;
			fout << "���������� � �������: " << Setinfo->kolvo << endl;
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
		cout << "����� � ��� : " << itog << " ���." << endl;
		clear();
	}
	else
	{
		cout << "������� ������" << endl;
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