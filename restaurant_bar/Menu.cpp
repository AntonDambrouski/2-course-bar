#include "Menu.h"


void Menu(Drinks& drinks, Cocktail& cocktail, Snack& snack)
{
	SetConsoleTitle(_T("Администратор"));
	int choose;
	int index;
	int choose_2;
	int size = 4;
	while (true)
	{
		system("mode con cols=65 lines=24");
		cout << "\t--- Меню ---\n";
		cout << "*\t1 - добавить товар в конец." << endl;
		cout << "*\t2 - просмотр списка товаров." << endl;
		cout << "*\t3 - добавить товар в произвольное место в списке." << endl;
		cout << "*\t4 - поиск товара по id, для этого надо знать id." << endl;
		cout << "*\t5 - удаление товара." << endl;
		cout << "*\t6 - очистить список." << endl;
		cout << "*\t7 - пополнить количество напитков на складе(по id)." << endl;
		cout << "#\t8 - поиск по превой букве." << endl;
		cout << "\n$Admin$\n  0 - вернуться главное меню." << endl;
		cin >> choose;
		switch (choose)
		{
		case 1:
		{
			while (true)
			{


				system("cls");
				cout << "Какой товар желаете добавить?\n";
				cout << "1 - напиток\n2 - коктейль\n3 - лёгкая закуска\n0 - выход\n";
				cin >> choose_2;
				while (choose_2 < 0 || choose_2 > 3)
				{
					system("cls");
					cout << "Какой товар желаете добавить?\n";
					cout << "1 - напиток\n2 - коктейль\n3 - лёгкая закуска\n0 - выход\n";
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
			cout << "Информацию о каких товарах желаете посмотреть?\n";
			cout << "1 - напитки\n2 - коктейли\n3 - лёгкие закуски\n";
			cin >> choose_2;
			while (choose_2 < 1 || choose_2 > 3)
			{
				system("cls");
				cout << "Информацию о каких товарах желаете посмотреть?\n";
				cout << "1 - напитки\n2 - коктейли\n3 - лёгкие закуски\n";
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
				else cout << "Список пуст!" << endl;
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
				else cout << "Список пуст!" << endl;
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
				else cout << "Список пуст!" << endl;
			}
			system("pause");
			system("cls");
			break;
		}
		case 3:
		{
			cout << "Какой товар желаете добавить?\n";
			cout << "1 - напиток\n2 - коктейль\n3 - лёгкая закуска\n";
			cin >> choose_2;
			while (choose_2 < 1 || choose_2 > 3)
			{
				cout << "Какой товар желаете добавить?\n";
				cout << "1 - напиток\n2 - коктейль\n3 - лёгкая закуска\n";
				cin >> choose_2;
			}
			cout << "Введите ID продукта: ";
			cin >> index;
			while (index <= 0)
			{
				cout << "Индексация начинается с 1!" << endl;
				cout << "Введите ID продукта: ";
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
				cout << "Список пуст!" << endl;
			}
			else {
				cout << "Какой товар желаете найти?\n";
				cout << "1 - напиток\n2 - коктейль\n3 - лёгкая закуска\n";
				cin >> choose_2;
				cout << "Введите ID продукта: ";
				cin >> index;
				while (index <= 0)
				{
					cout << "Индексация начинается с 1!" << endl;
					cout << "Введите ID продукта: ";
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
				cout << "Откуда желаете удалить элемент?" << endl;
				cout << "1 - напиток\n2 - коктейль\n3 - лёгкая закуска\n0 - назад\n";
				cin >> choose_2;
				while (choose_2 < 0 || choose_2 > 3)
				{
					cout << "1 - напиток\n2 - коктейль\n3 - лёгкая закуска\n0 - назад\n";
					cin >> choose_2;
				}
				if (choose_2 != 0)
				{
					Get_name_id(drinks, cocktail, snack, choose_2);
					cout << "Введите ID продукта: ";
					cin >> index;
					while (index <= 0)
					{
						cout << "Индексация начинается с 1!" << endl;
						cout << "Введите ID продукта: ";
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
			cout << "1 - удалить все напитки\n2 - удалить все коктейли\n3 - удалить все блюда\n4 - удалить всё\n0 - назад\n";
			cin >> choose_2;
			while (choose_2 < 0 || choose_2 > 4)
			{
				system("cls");
				cout << "1 - удалить все напитки\n2 - удалить все коктейли\n3 - удалить все блюда\n4 - удалить всё\n0 - назад\n";
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
					cout << "Введите id напитка для добавления: ";
					cin >> index;
					while (index <= 0)
					{
						cout << "Индексация начинается с 1!" << endl;
						cout << "Введите ID продукта: ";
						cin >> index;
					}
					drinks.Add_kolv(index);
				}
				else
				{
					cout << "Список пуст!" << endl;
				}
				cout << "\n1 - продолжить\n0 - назад" << endl;
				cin >> choose;
				while (choose<0 || choose>1)
				{
					system("cls");
					cout << "\n1 - продолжить\n0 - назад" << endl;
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
				cout << "Список пуст!" << endl;
			}
			else
			{
				char ch[28];
				cout << "В какой категории желаете начать поиск.\n";
				cout << "1 - напиток\n2 - коктейль\n3 - лёгкая закуска\n";
				cin >> choose_2;

				cout << "Введите букву для поиска.";
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
	SetConsoleTitle(_T("Пользователь"));
	system("mode con cols=65 lines=24");
	int choose;
	int index;
	int choose_2;
	int size = 4;
	while (true)
	{
		system("mode con cols=65 lines=24");
		cout << "\n\t--------------------------------------\n";
		cout << "*\t1 - просмотр списка товаров." << endl;
		cout << "#\t2 - поиск товара на складе по первой букве." << endl;
		cout << "#\t3 - сделать заказ." << endl;
		cout << "#\t4 - показать корзину." << endl;
		cout << "#\t5 - очистить корзину." << endl;
		cout << "#\t6 - сохранить информацию товаров в корзине в файл." << endl;
		cout << "#\t7 - чтение корзины с файла." << endl;
		cout << "#\t8 - удаление элемента с корзины." << endl;
		cout << "#\t9 - выписка чека." << endl;
		cout << "\n\n\t---Дополнителные функции---" << endl;
		cout << "^^^\t10 - узнать количество элементов." << endl;
		cout << "\n$User$\n  0 - вернуться главное меню." << endl;
		cin >> choose;
		switch (choose)
		{
		case 1:
		{
			system("cls");
			system("mode con cols=65 lines=40");
			size = 4;
			cout << "Информацию о каких товарах желаете посмотреть?\n";
			cout << "1 - напитки\n2 - коктейли\n3 - лёгкие закуски\n";
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
				else cout << "Список пуст!" << endl;
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
				else cout << "Список пуст!" << endl;
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
				else cout << "Список пуст!" << endl;
			}
			else
			{
				cout << "\nТакого товара не существует!" << endl;
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
				cout << "Список пуст!" << endl;
			}
			else
			{
				char ch[28];
				cout << "В какой категории желаете начать поиск.\n";
				cout << "1 - напиток\n2 - коктейль\n3 - лёгкая закуска\n";
				cin >> choose_2;

				cout << "Введите букву для поиска.";
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
			if (drinks.GetSize() == 0 && cocktail.GetSize() == 0 && snack.GetSize() == 0) { cout << "Список пуст!" << endl; }
			else
			{
				while (true)
				{


					cout << "Какой товар желаете найти?\n";
					cout << "1 - напиток\n2 - коктейль\n3 - лёгкая закуска\n0 - выход\n";
					cin >> choose_2;
					while (choose_2 < 0 || choose_2 > 3)
					{
						cout << "1 - напиток\n2 - коктейль\n3 - лёгкая закуска\n0 - выход\n";
						cin >> choose_2;
					}
					if (choose_2 != 0)
					{


						Get_name_id(drinks, cocktail, snack, choose_2);
						cout << "Введите ID товара: ";
						cin >> index;
						while (index <= 0)
						{
							cout << "Индексация начинается с 1!" << endl;
							cout << "Введите ID продукта: ";
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
							cout << "Товара под таким индексом не существует!" << endl;
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
							cout << "Товара под таким индексом не существует!" << endl;
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
							cout << "Товара под таким индексом не существует!" << endl;
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
				cout << "Корзина пуста." << endl;
			}
			else
			{
				cout << "\t---Ваша корзина---\n";
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
				cout << "корзина пуста!" << endl;
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
			cout << "Введите id элемента для удаления: ";
			cin >> index;
			while (index <= 0)
			{
				cout << "Индексация начинается с 1!" << endl;
				cout << "Введите ID продукта: ";
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
			cout << "Количество напитков на базе: " << drinks.GetSize() << endl;
			cout << "Видов коктейлей на базе: " << cocktail.GetSize() << endl;
			cout << "Видов блюд на базе: " << snack.GetSize() << endl;
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
