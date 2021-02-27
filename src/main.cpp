#include <iostream>
#include "Menus.h"

void start_main_menu();

int main()
{
	srand((unsigned)time(0));
	//TODO Make this start main menu
	start_main_menu();
	//Start_game();
}

void start_main_menu()
{
	display_banner();
	display_menu();
}