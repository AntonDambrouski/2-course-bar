#include"Basket.h"
#include "Menu.h"
#include"resource.h"

void change_password(string& password, string& enter_password);
int SignIn(string& password, string& enter_password);
void change_textcolor();
void PrintBAR();
void Spravka();

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
  	Drinks drinks;
	Cocktail cocktail;
	Snack snack;
	Basket basket;
	string password = "1", enter_password;
	int choose = 0;
	while (true)
	{
		SetConsoleTitle(_T("Главное меню"));
		system("mode con cols=80 lines=20");
		PrintBAR();
		cout << "1 - войти\n2 - справка\n3 - изменить цвет консоли\n0 - выход\n";
		cin >> choose;
		switch (choose)
		{
		case 1:
		{
			choose = SignIn(password, enter_password);
			if (choose == 2)
			{
				system("cls");
				Menu(drinks, cocktail, snack);
				system("mode con cols=80 lines=20");
			}
			if (choose == 1)
			{
				system("cls");
				Menu_for_user(drinks, cocktail, snack, basket);
				system("mode con cols=80 lines=20");
			}
			break;
		}
		case 2:
		{
			Spravka();
			system("cls");
			break;
		}
		case 3:
		{
			change_textcolor();
			break;
		}
		case 0:
		{
			return 0;
		}
		default:
			system("cls");
			break;
		}
	}
	return 0;
};

void change_password(string& password, string& enter_password)
{

	string accept;
	cout << "Введите старый пароль:";
	cin >> enter_password;
	while (password != enter_password)
	{
		cout << "Неверный пароль!\n";
		cout << "Введите старый пароль: ";
		cin >> enter_password;
	}
	cout << "\nВведите новый пароль:";
	cin >> enter_password;
	cout << "Повторите пароль: ";
	cin >> accept;
	while (enter_password != accept)
	{
		cout << "Неверный пароль!\n";
		cout << "Повторите пароль: ";
		cin >> accept;
	}
	ofstream fout;
	fout.open("Password\\pasw.txt");
	fout << enter_password;
	fout.close();

}

int SignIn(string& password, string& enter_password)
{
	system("cls");
	system("mode con cols=45 lines=20");
	SetConsoleTitle(_T("Вход"));
	int choose = 0;
	fstream fin;
	fin.open("Password\\pasw.txt");
	char ch[32];
	while (fin.getline(ch, 32))
	{
		password = ch;
	}
	fin.close();
	cout << "\n\nВойти как пользователь - 1\nВойти как администратор - 2\n0 - вернуться в главное меню\n";
	cin >> choose;
	while (choose < 0 || choose > 2)
	{
		system("cls");
		cout << "\n\nВойти как пользователь - 1\nВойти как администратор - 2\n0 - вернуться в главное меню\n";
		cin >> choose;
	}
	if (choose == 2)
	{
		system("cls");
		cout << "\nВвести пароль - 1\nСменить пароль - 2\n0 - вернуться в главное меню\n";
		cin >> choose;
		while (choose < 0 || choose > 2)
		{
			system("cls");
			cout << "\nВвести пароль - 1\nСменить пароль - 2\n0 - вернуться в главное меню\n";
			cin >> choose;
		}
		if (choose == 1)
		{
			cout << "Введите пароль: ";
			cin >> enter_password;
			while (password != enter_password)
			{
				cout << "Неверный пароль!\n";
				cout << "Введите пароль: ";
				cin >> enter_password;
			}

			return 2;
		}
		else if (choose == 2)
		{
			change_password(password, enter_password);
			return 2;
		}
		else if (choose == 0) return 0;
	}
	if (choose == 1)
	{
		return 1;
	}
	if (choose == 0)
	{
		system("cls");
		system("mode con cols=80 lines=20");
		return 0;
	}

}

void change_textcolor()
{
	system("cls");
	SetConsoleTitle(_T("Смена цвета консоли"));
	int choose = 1;
	while (choose)
	{
		cout << "Стандартная - 1" << endl;
		cout << "Тёмная тема_2: текст голубой, фон чёрный - 2" << endl;
		cout << "Зелёная лилия: текст жёлтый, фон зеленый - 3" << endl;
		cout << "Солнце в небе: текст жёлтый, фон голубой - 4" << endl;
		cout << "Светлая тема: текст чёрный, фон белый - 5" << endl;
		cout << "Выход - 0" << endl;
		cin >> choose;
		if (choose == 1) { system("color 07"); }
		if (choose == 2) { system("color 03"); }
		if (choose == 3) { system("color 2E"); }
		if (choose == 4) { system("color 3E"); }
		if (choose == 5) { system("color F0"); }
		system("cls");
	}
}

void PrintBAR()
{
	cout << "\t\t\t\t     Welcome!\n";
	cout << endl;
	cout << endl;
	cout << "\t\t\t#######       ######      ######" << endl;
	cout << "\t\t\t##    ##     ##    ##     ##   ##" << endl;
	cout << "\t\t\t#######      ########     ######" << endl;
	cout << "\t\t\t##    ##     ##    ##     ## ##" << endl;
	cout << "\t\t\t#######      ##    ##     ##   ##" << endl;
	cout << endl;
}

void Spravka()
{
	system("cls");
	SetConsoleTitle(_T("Справка"));
	system("mode con cols=80 lines=10");
	cout << "\t--Справка--" << endl;
	cout << "\nCreated by Anton Dombrovskiy" << endl;
	cout << "Group: 39 TP" << endl;
	cout << "Приложение разработано для бара" << endl;
	cout << "По всем вопросам писать на почту dombrovsliy2002@mail.ru" << endl;
	cout << "МГКЭ, Минск, 2020" << endl;
	cout << "--------------------------------------------------------" << endl;
	system("pause");
}
