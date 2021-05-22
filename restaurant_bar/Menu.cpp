#include "Menu.h"


void Menu(Drinks& drinks, Cocktail& cocktail, Snack& snack)
{
	SetConsoleTitle(_T("�������������"));
	int choose;
	int index;
	int choose_2;
	int size = 4;
	while (true)
	{
		system("mode con cols=65 lines=24");
		cout << "\t--- ���� ---\n";
		cout << "*\t1 - �������� ����� � �����." << endl;
		cout << "*\t2 - �������� ������ �������." << endl;
		cout << "*\t3 - �������� ����� � ������������ ����� � ������." << endl;
		cout << "*\t4 - ����� ������ �� id, ��� ����� ���� ����� id." << endl;
		cout << "*\t5 - �������� ������." << endl;
		cout << "*\t6 - �������� ������." << endl;
		cout << "*\t7 - ��������� ���������� �������� �� ������(�� id)." << endl;
		cout << "#\t8 - ����� �� ������ �����." << endl;
		cout << "\n$Admin$\n  0 - ��������� ������� ����." << endl;
		cin >> choose;
		switch (choose)
		{
		case 1:
		{
			while (true)
			{


				system("cls");
				cout << "����� ����� ������� ��������?\n";
				cout << "1 - �������\n2 - ��������\n3 - ����� �������\n0 - �����\n";
				cin >> choose_2;
				while (choose_2 < 0 || choose_2 > 3)
				{
					system("cls");
					cout << "����� ����� ������� ��������?\n";
					cout << "1 - �������\n2 - ��������\n3 - ����� �������\n0 - �����\n";
					cin >> choose_2;
				}
				if (choose_2 == 1) { drinks.push_back(); }
				else if (choose_2 == 2) { cocktail.push_back(); }
				else if (choose_2 == 3) { snack.push_back(); }
				else if (choose_2 == 0)
				{
					system("cls");
					break;
				}
			}
			system("cls");
			break;
		}
		case 2:
		{

			system("cls");
			system("mode con cols=65 lines=40");
			cout << "���������� � ����� ������� ������� ����������?\n";
			cout << "1 - �������\n2 - ��������\n3 - ����� �������\n";
			cin >> choose_2;
			while (choose_2 < 1 || choose_2 > 3)
			{
				system("cls");
				cout << "���������� � ����� ������� ������� ����������?\n";
				cout << "1 - �������\n2 - ��������\n3 - ����� �������\n";
				cin >> choose_2;
			}
			if (choose_2 == 1)
			{
				if (drinks.GetSize() != 0)
				{
					for (int i = 0; i < drinks.GetSize(); i++)
					{
						if (i == size)
						{
							system("pause");
							size += 4;
						}
						drinks.Get_drinks_info(drinks[i]);
					}
					size = 4;
				}
				else cout << "������ ����!" << endl;
			}

			if (choose_2 == 2)
			{
				if (cocktail.GetSize() != 0)
				{
					for (int i = 0; i < cocktail.GetSize(); i++)
					{
						if (i == size)
						{
							system("pause");
							size += 4;
						}
						cocktail.Get_Cocktail_info(cocktail[i]);
					}
					size = 4;
				}
				else cout << "������ ����!" << endl;
			}

			if (choose_2 == 3)
			{
				if (snack.GetSize() != 0)
				{
					for (int i = 0; i < snack.GetSize(); i++)
					{
						if (i == size)
						{
							system("pause");
							size += 4;
						}
						snack.Get_Snack_info(snack[i]);
					}
					size = 4;
				}
				else cout << "������ ����!" << endl;
			}
			system("pause");
			system("cls");
			break;
		}
		case 3:
		{
			cout << "����� ����� ������� ��������?\n";
			cout << "1 - �������\n2 - ��������\n3 - ����� �������\n";
			cin >> choose_2;
			while (choose_2 < 1 || choose_2 > 3)
			{
				cout << "����� ����� ������� ��������?\n";
				cout << "1 - �������\n2 - ��������\n3 - ����� �������\n";
				cin >> choose_2;
			}
			cout << "������� ID ��������: ";
			cin >> index;
			while (index <= 0)
			{
				cout << "���������� ���������� � 1!" << endl;
				cout << "������� ID ��������: ";
				cin >> index;

			}
			if (choose_2 == 1) { drinks.insert(index); };
			if (choose_2 == 2) { cocktail.insert(index); };
			if (choose_2 == 3) { snack.insert(index); };
			system("cls");
			break;
		}
		case 4:
		{
			if (drinks.GetSize() == 0 && cocktail.GetSize() == 0 && snack.GetSize() == 0)
			{
				cout << "������ ����!" << endl;
			}
			else {
				cout << "����� ����� ������� �����?\n";
				cout << "1 - �������\n2 - ��������\n3 - ����� �������\n";
				cin >> choose_2;
				cout << "������� ID ��������: ";
				cin >> index;
				while (index <= 0)
				{
					cout << "���������� ���������� � 1!" << endl;
					cout << "������� ID ��������: ";
					cin >> index;
				}
				if (choose_2 == 1)
				{
					if (drinks.GetSize())
					{
						drinks.Get_drinks_info(index);
					}
				}
				if (choose_2 == 2)
				{
					if (cocktail.GetSize())
					{
						cocktail.Get_Cocktail_info(index);
					}
				}
				if (choose_2 == 3)
				{
					if (snack.GetSize())
					{
						snack.Get_Snack_info(index);
					}
				}
			}
			system("pause");
			system("cls");
			break;
		}
		case 5:
		{
			system("mode con cols=65 lines=40");
			while (true)
			{


				system("cls");
				size = 13;
				cout << "������ ������� ������� �������?" << endl;
				cout << "1 - �������\n2 - ��������\n3 - ����� �������\n0 - �����\n";
				cin >> choose_2;
				while (choose_2 < 0 || choose_2 > 3)
				{
					cout << "1 - �������\n2 - ��������\n3 - ����� �������\n0 - �����\n";
					cin >> choose_2;
				}
				if (choose_2 != 0)
				{
					Get_name_id(drinks, cocktail, snack, choose_2);
					cout << "������� ID ��������: ";
					cin >> index;
					while (index <= 0)
					{
						cout << "���������� ���������� � 1!" << endl;
						cout << "������� ID ��������: ";
						cin >> index;
					}
					if (choose_2 == 1 && drinks.GetSize() != 0) { drinks.removeAt(index); }
					else if (choose_2 == 2 && cocktail.GetSize() != 0) { cocktail.removeAt(index); }
					else if (choose_2 == 3 && snack.GetSize() != 0) { snack.removeAt(index); }
				}
				else
				{
					system("cls");
					break;
				}
				system("cls");
			}
			break;
		}
		case 6:
		{
			system("cls");
			system("mode con cols=40 lines=15");
			cout << "1 - ������� ��� �������\n2 - ������� ��� ��������\n3 - ������� ��� �����\n4 - ������� ��\n0 - �����\n";
			cin >> choose_2;
			while (choose_2 < 0 || choose_2 > 4)
			{
				system("cls");
				cout << "1 - ������� ��� �������\n2 - ������� ��� ��������\n3 - ������� ��� �����\n4 - ������� ��\n0 - �����\n";
				cin >> choose_2;
			}
			if (drinks.GetSize() != 0 && choose_2 == 1) { drinks.clear(); }
			else if (cocktail.GetSize() != 0 && choose_2 == 2) { cocktail.clear(); }
			else if (snack.GetSize() != 0 && choose_2 == 3) { snack.clear(); }
			else if (choose_2 == 4)
			{
				if (drinks.GetSize() != 0) { drinks.clear(); }
				if (cocktail.GetSize() != 0) { cocktail.clear(); }
				if (snack.GetSize() != 0) { snack.clear(); }
			}
			else if (choose_2 == 0)
			{
				system("cls");
				break;
			}
			system("cls");
			break;
		}
		case 7:
		{
			system("mode con cols=65 lines=40");
			while (true)
			{

				system("cls");
				size = 13;
				for (int i = 0; i < drinks.GetSize(); i++)
				{
					if (i == size)
					{
						system("pause");
						size += 13;
					}
					cout << "*   ";
					drinks.Get_name_id(i);
				}
				if (drinks.GetSize() != 0)
				{
					cout << "������� id ������� ��� ����������: ";
					cin >> index;
					while (index <= 0)
					{
						cout << "���������� ���������� � 1!" << endl;
						cout << "������� ID ��������: ";
						cin >> index;
					}
					drinks.Add_kolv(index);
				}
				else
				{
					cout << "������ ����!" << endl;
				}
				cout << "\n1 - ����������\n0 - �����" << endl;
				cin >> choose;
				while (choose<0 || choose>1)
				{
					system("cls");
					cout << "\n1 - ����������\n0 - �����" << endl;
					cin >> choose;
				}
				if (choose == 0)
				{
					system("pause");
					system("cls");
					break;
				}
				else
				{
					system("pause");
					system("cls");
				}
				
			}
			break;
		}
		case 8:
		{
			system("cls");
			system("mode con cols=65 lines=40");
			if (drinks.GetSize() == 0 && cocktail.GetSize() == 0 && snack.GetSize() == 0)
			{
				cout << "������ ����!" << endl;
			}
			else
			{
				char ch[28];
				cout << "� ����� ��������� ������� ������ �����.\n";
				cout << "1 - �������\n2 - ��������\n3 - ����� �������\n";
				cin >> choose_2;

				cout << "������� ����� ��� ������.";
				cin >> ch;
				if (choose_2 == 1) { drinks.Sort_by_first_letter(ch[0]); };
				if (choose_2 == 2) { cocktail.Sort_by_first_letter(ch[0]); };
				if (choose_2 == 3) { snack.Sort_by_first_letter(ch[0]); };
			}
			system("pause");
			system("cls");
			break;
		}
		case 0: { system("cls"); return; }
		default:  system("cls");
			break;
		}
	}
}

void Menu_for_user(Drinks& drinks, Cocktail& cocktail, Snack& snack, Basket& basket)
{
	SetConsoleTitle(_T("������������"));
	system("mode con cols=65 lines=24");
	int choose;
	int index;
	int choose_2;
	int size = 4;
	while (true)
	{
		system("mode con cols=65 lines=24");
		cout << "\n\t--------------------------------------\n";
		cout << "*\t1 - �������� ������ �������." << endl;
		cout << "#\t2 - ����� ������ �� ������ �� ������ �����." << endl;
		cout << "#\t3 - ������� �����." << endl;
		cout << "#\t4 - �������� �������." << endl;
		cout << "#\t5 - �������� �������." << endl;
		cout << "#\t6 - ��������� ���������� ������� � ������� � ����." << endl;
		cout << "#\t7 - ������ ������� � �����." << endl;
		cout << "#\t8 - �������� �������� � �������." << endl;
		cout << "#\t9 - ������� ����." << endl;
		cout << "\n\n\t---������������� �������---" << endl;
		cout << "^^^\t10 - ������ ���������� ���������." << endl;
		cout << "\n$User$\n  0 - ��������� ������� ����." << endl;
		cin >> choose;
		switch (choose)
		{
		case 1:
		{
			system("cls");
			system("mode con cols=65 lines=40");
			size = 4;
			cout << "���������� � ����� ������� ������� ����������?\n";
			cout << "1 - �������\n2 - ��������\n3 - ����� �������\n";
			cin >> choose_2;
			if (choose_2 == 1)
			{
				if (drinks.GetSize() != 0)
				{
					for (int i = 0; i < drinks.GetSize(); i++)
					{
						if (i == size)
						{
							system("pause");
							size += 4;
						}
						drinks.Get_drinks_info(drinks[i]);
					}
					size = 4;
				}
				else cout << "������ ����!" << endl;
			}
			else if (choose_2 == 2)
			{
				if (cocktail.GetSize() != 0)
				{
					for (int i = 0; i < cocktail.GetSize(); i++)
					{
						if (i == size)
						{
							system("pause");
							size += 4;
						}
						cocktail.Get_Cocktail_info(cocktail[i]);
					}
					size = 4;
				}
				else cout << "������ ����!" << endl;
			}
			else if (choose_2 == 3)
			{
				if (snack.GetSize() != 0)
				{
					for (int i = 0; i < snack.GetSize(); i++)
					{
						if (i == size)
						{
							system("pause");
							size += 4;
						}
						snack.Get_Snack_info(i + 1);
					};
				}
				else cout << "������ ����!" << endl;
			}
			else
			{
				cout << "\n������ ������ �� ����������!" << endl;
			}
			system("pause");
			system("cls");
			break;
		}
		case 2:
		{
			system("cls");
			system("mode con cols=65 lines=40");
			if (drinks.GetSize() == 0 && cocktail.GetSize() == 0 && snack.GetSize() == 0)
			{
				cout << "������ ����!" << endl;
			}
			else
			{
				char ch[28];
				cout << "� ����� ��������� ������� ������ �����.\n";
				cout << "1 - �������\n2 - ��������\n3 - ����� �������\n";
				cin >> choose_2;

				cout << "������� ����� ��� ������.";
				cin >> ch;
				if (choose_2 == 1) { drinks.Sort_by_first_letter(ch[0]); };
				if (choose_2 == 2) { cocktail.Sort_by_first_letter(ch[0]); };
				if (choose_2 == 3) { snack.Sort_by_first_letter(ch[0]); };
			}
			system("pause");
			system("cls");
			break;
		}
		case 3:
		{
			system("cls");
			system("mode con cols=65 lines=40");
			if (drinks.GetSize() == 0 && cocktail.GetSize() == 0 && snack.GetSize() == 0) { cout << "������ ����!" << endl; }
			else
			{
				while (true)
				{


					cout << "����� ����� ������� �����?\n";
					cout << "1 - �������\n2 - ��������\n3 - ����� �������\n0 - �����\n";
					cin >> choose_2;
					while (choose_2 < 0 || choose_2 > 3)
					{
						cout << "1 - �������\n2 - ��������\n3 - ����� �������\n0 - �����\n";
						cin >> choose_2;
					}
					if (choose_2 != 0)
					{


						Get_name_id(drinks, cocktail, snack, choose_2);
						cout << "������� ID ������: ";
						cin >> index;
						while (index <= 0)
						{
							cout << "���������� ���������� � 1!" << endl;
							cout << "������� ID ��������: ";
							cin >> index;
						}
					}
					if (choose_2 == 1)
					{
						if (drinks.GetSize())
						{
							drinks.Get_drinks_info(index);
							basket.push_back_drinks(drinks, index);
						}
						else
						{
							cout << "������ ��� ����� �������� �� ����������!" << endl;
						}
					}
					else if (choose_2 == 2)
					{
						if (cocktail.GetSize())
						{
							cocktail.Get_Cocktail_info(index);
							basket.push_back_cocktails(cocktail, index);
						}
						else
						{
							cout << "������ ��� ����� �������� �� ����������!" << endl;
						}
					}
					else if (choose_2 == 3)
					{
						if (snack.GetSize())
						{
							snack.Get_Snack_info(index);
							basket.push_back_snacks(snack, index);
						}
						else
						{
							cout << "������ ��� ����� �������� �� ����������!" << endl;
						}
					}
					else if (choose_2 == 0)
					{
						system("cls");
						break;
					}
					system("pause");
					system("cls");
				}

			}
			break;
		}
		case 4:
		{
			system("mode con cols=65 lines=40");
			system("cls");
			if (basket.GetSize() == 0)
			{
				cout << "������� �����." << endl;
			}
			else
			{
				cout << "\t---���� �������---\n";
				cout << "\t------------------\n\n" << endl;
				basket.Get_basket_info();
			}
			system("pause");
			system("cls");
			break;
		}
		case 5:
		{
			basket.clear();
			system("cls");
			break;
		}
		case 6:
		{
			if (basket.GetSize() == 0)
			{
				cout << "������� �����!" << endl;
			}
			else
				basket.PrintBasketToFile();
			system("pause");
			system("cls");
			break;
		}
		case 7:
		{
			basket.Read_from_basket();
			system("pause");
			system("cls");
			break;
		}
		case 8:
		{
			system("cls");
			system("mode con cols=65 lines=40");
			size = 13;
			for (int i = 0; i < basket.GetSize(); i++)
			{
				if (i == size)
				{
					system("pause");
					size += 13;
				}
				cout << "*   ";
				basket.Get_name_id(i);
			}
			cout << "������� id �������� ��� ��������: ";
			cin >> index;
			while (index <= 0)
			{
				cout << "���������� ���������� � 1!" << endl;
				cout << "������� ID ��������: ";
				cin >> index;
			}
			if (basket.GetSize())
			{
				basket.removeAt(index);
			}
			system("cls");
			break;
		}
		case 9:
		{
			system("cls");
			basket.Get_check();
			system("pause");
			system("cls");
			break;
		}
		case 10:
		{
			cout << "\n---------------------------" << endl;
			cout << "���������� �������� �� ����: " << drinks.GetSize() << endl;
			cout << "����� ��������� �� ����: " << cocktail.GetSize() << endl;
			cout << "����� ���� �� ����: " << snack.GetSize() << endl;
			cout << "\n---------------------------" << endl;
			system("pause");
			system("cls");
			break;

		}
		case 0: { system("cls"); return; }
		default: system("cls");
			break;
		}
	}
}

void Get_name_id(Drinks& drinks, Cocktail& cocktail, Snack& snack, int choose)
{
	int size = 13;
	if (choose == 1)
	{
		for (int i = 0; i < drinks.GetSize(); i++)
		{
			cout << "*  ";
			drinks.Get_name_id(i);
			if (i == size)
			{
				system("pause");
				size += 13;
			}
		}
	}
	if (choose == 2)
	{
		for (int i = 0; i < cocktail.GetSize(); i++)
		{
			cout << "*  ";
			cocktail.Get_name_id(i);
			if (i == size)
			{
				system("pause");
				size += 13;
			}
		}
	}
	if (choose == 3)
	{
		for (int i = 0; i < snack.GetSize(); i++)
		{
			cout << "*  ";
			snack.Get_name_id(i);
			if (i == size)
			{
				system("pause");
				size += 13;
			}
		}
	}
}
