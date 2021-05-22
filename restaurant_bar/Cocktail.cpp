#include "Cocktail.h"


Cocktail::Cocktail()
{
	Size = 0;
	head = tail = nullptr;
	uniquefordrinks = 1; //id ��� ���� ���������
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
	if (Size == 0) // ���� ������ = 0, ������ ����� ������ 
	{
		head = tail = new Node();// ����� ������
		cout << "������� �������� ��������: ";
		cin.ignore(1, '\n');
		cin.getline(head->name, 32);
		cout << "������� ����: ";
		cin >> head->cost;
		while (head->cost < 0)
		{
			cout << "���� �� ����� ���� �������������!\n";
			cin >> head->cost;
		}
		cout << "������� ������� ��������: ";
		cin.ignore(1, '\n');
		cin.getline(head->description, 254);
		cout << "������� ������� �� 1 �� 5 ������: ";
		cin >> head->rate;
		while (head->rate > 5 || head->rate < 0)
		{
			cin >> head->rate;
		}
		head->id = uniquefordrinks;
		uniquefordrinks++;
		Size++;
	}
	else							  //���� ������ != 0, �� ������� ������ � �����
	{
		Node* addtoback = new Node(); //������ ������ ��� ����������
		addtoback->pPrev = tail;	  //���������� ����� ��� ��������� �������
		tail->pNext = addtoback;	  //��������� ����� ���������� ���� �������, ������ ��� ��� ����� ������
		tail = addtoback;			  //��� ����� ����� ���������
		cout << "������� �������� ��������: ";
		cin.ignore(1, '\n');
		cin.getline(addtoback->name, 32);
		cout << "������� ����: ";
		cin >> addtoback->cost;
		while (addtoback->cost < 0)
		{
			cout << "���� �� ����� ���� �������������!\n";
			cin >> addtoback->cost;
		}
		cout << "������� ������� ��������: ";
		cin.ignore(1, '\n');
		cin.getline(addtoback->description, 254);
		cout << "������� ������� �� 1 �� 5 ������: ";
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
	while (Size)//���� ������ �� ����� 0, �������� ����� ������� � �����
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
		cout << "������� �������� ��������: ";
		cin.ignore(1, '\n');
		cin.getline(ToAdd->name, 32);
		cout << "������� ����: ";
		cin >> ToAdd->cost;
		while (ToAdd->cost < 0)
		{
			cout << "���� �� ����� ���� �������������!\n";
			cin >> ToAdd->cost;
		}
		cout << "������� ������� ��������: ";
		cin.ignore(1, '\n');
		cin.getline(ToAdd->description, 32);
		cout << "������� ������� �� 1 �� 5 ������: ";
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
		cout << "������� �������� ��������: ";
		cin.ignore(1, '\n');
		cin.getline(ToAdd->name, 32);
		cout << "������� ����: ";
		cin >> ToAdd->cost;
		while (ToAdd->cost < 0)
		{
			cout << "���� �� ����� ���� �������������!\n";
			cin >> ToAdd->cost;
		}
		cout << "������� ������� ��������: ";
		cin.ignore(1, '\n');
		cin.getline(ToAdd->description, 32);
		cout << "������� ������� �� 1 �� 5 ������: ";
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
	if (head->id == index)		//���� ���� ������ ����� ������� ����, �� ��������� �� ���������� ���������
	{
		if (Size == 1) // ���� ������ ����, ������ ���� ������ ������ � ������ �
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

void Cocktail::pop_back()
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

void Cocktail::Get_Cocktail_info(int index) // ����� �������� � ���������
{
	if (index == head->id)
	{
		cout << "������: " << head->id << endl;
		cout << "��������: " << head->name << endl;
		cout << "����: " << head->cost << " ���." << endl;
		cout << "��������: " << head->description << endl;
		cout << "�������: " << head->rate << endl;
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
		cout << "������: " << ToShow->id << endl;
		cout << "��������: " << ToShow->name << endl;
		cout << "����: " << ToShow->cost << " ���." << endl;
		cout << "��������: " << ToShow->description << endl;
		cout << "�������: " << ToShow->rate << endl;
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
			cout << "������: " << ToShow->id << endl;
			cout << "��������: " << ToShow->name << endl;
			cout << "����: " << ToShow->cost << " ���." << endl;
			cout << "��������: " << ToShow->description << endl;
			cout << "�������: " << ToShow->rate << endl;
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
		cout << "������ �� �������." << endl;
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