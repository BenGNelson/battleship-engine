#include <iostream>
#include <vector>
#include "Board.h"

using namespace std;

void Start_game();
void Start_main_menu();

int main()
{
	srand((unsigned)time(0));
	//TODO Make this start main menu
	Start_main_menu();
	//Start_game();
}

void Start_game()
{
	// create boards
	Board board1(8, 8);
	board1.Print();
	cout << "Here is the game\n";
	return;
}

void Start_main_menu()
{
	// display banner
	cout << "                   ____   _       ____  __ __                            \n";
	cout << "                  |    \\ | |     /    ||  |  |                           \n";
	cout << "                  |  o  )| |    |  o  ||  |  |                           \n";
	cout << "                  |   _/ | |___ |     ||  ~  |                           \n";
	cout << "                  |  |   |     ||  _  ||___, |                           \n";
	cout << "                  |  |   |     ||  |  ||     |                           \n";
	cout << "                  |__|   |_____||__|__||____/                            \n";
	cout << "                                                                         \n";
	cout << "   ____    ____  ______  ______  _        ___   _____ __ __  ____  ____  \n";
	cout << "  |    \\  /    ||      ||      || |      /  _] / ___/|  |  ||    ||    \\ \n";
	cout << "  |  o  )|  o  ||      ||      || |     /  [_ (   \\_ |  |  | |  | |  o  )\n";
	cout << "  |     ||     ||_|  |_||_|  |_|| |___ |    _] \\__  ||  _  | |  | |   _/ \n";
	cout << "  |  O  ||  _  |  |  |    |  |  |     ||   [_  /  \\ ||  |  | |  | |  |   \n";
	cout << "  |     ||  |  |  |  |    |  |  |     ||     | \\    ||  |  | |  | |  |   \n";
	cout << "  |_____||__|__|  |__|    |__|  |_____||_____|  \\___||__|__||____||__|   \n";
	cout << "                                                                         \n";

	// display menu
	cout << "Main Menu\n"
		 << "1. Play\n"
		 << "2. Exit\n"
		 << "Enter your selection: ";
	string selection = "";
	cin >> selection;

	// ensure user makes correct choice
	while (selection.compare("1") != 0 && selection.compare("2") != 0)
	{
		cout << "Please make a proper selection by entering 1 or 2\nEnter your selection: ";
		cin >> selection;
	}

	// act on user choice by beginning the game or exiting
	if (selection.compare("1") == 0)
	{
		Start_game();
		// play the game
	}
	else if (selection.compare("2") == 0)
	{
		cout << "Exiting...\n";
		// exit
	}
	return;
}