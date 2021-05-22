#pragma once
#include"Basket.h"
#include <tchar.h>
#include<Windows.h>
using namespace std;

void Menu(Drinks& drinks, Cocktail& cocktail, Snack& snack);
void Menu_for_user(Drinks& drinks, Cocktail& cocktail, Snack& snack, Basket& basket);
void Get_name_id(Drinks& drinks, Cocktail& cocktail, Snack& snack, int choose);
