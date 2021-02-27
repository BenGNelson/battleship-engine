#include <iostream>
#include <string>

#include "Board.h"

void display_banner();
void display_menu();
std::string get_user_input();
void validate_user_input(std::string& input);
void start_game();

void display_banner()
{
    std::cout << "                   ____   _       ____  __ __                            \n";
    std::cout << "                  |    \\ | |     /    ||  |  |                           \n";
    std::cout << "                  |  o  )| |    |  o  ||  |  |                           \n";
    std::cout << "                  |   _/ | |___ |     ||  ~  |                           \n";
    std::cout << "                  |  |   |     ||  _  ||___, |                           \n";
    std::cout << "                  |  |   |     ||  |  ||     |                           \n";
    std::cout << "                  |__|   |_____||__|__||____/                            \n";
    std::cout << "                                                                         \n";
    std::cout << "   ____    ____  ______  ______  _        ___   _____ __ __  ____  ____  \n";
    std::cout << "  |    \\  /    ||      ||      || |      /  _] / ___/|  |  ||    ||    \\ \n";
    std::cout << "  |  o  )|  o  ||      ||      || |     /  [_ (   \\_ |  |  | |  | |  o  )\n";
    std::cout << "  |     ||     ||_|  |_||_|  |_|| |___ |    _] \\__  ||  _  | |  | |   _/ \n";
    std::cout << "  |  O  ||  _  |  |  |    |  |  |     ||   [_  /  \\ ||  |  | |  | |  |   \n";
    std::cout << "  |     ||  |  |  |  |    |  |  |     ||     | \\    ||  |  | |  | |  |   \n";
    std::cout << "  |_____||__|__|  |__|    |__|  |_____||_____|  \\___||__|__||____||__|   \n";
    std::cout << "                                                                         \n";
}

void display_menu()
{
    std::cout << "Main Menu\n"
              << "1. Play\n"
              << "2. Exit\n"
              << "Enter your selection: ";

    std::string input = get_user_input();
    validate_user_input(input);
}

std::string get_user_input()
{
    std::string selection = "";
    std::cin >> selection;
    return selection;
}

void validate_user_input(std::string& input)
{
    // ensure user makes correct choice
    while (input.compare("1") != 0 && input.compare("2") != 0)
    {
        std::cout << "Please make a proper selection by entering 1 or 2\nEnter your selection: ";
        input = get_user_input();
    }

    // act on user choice by beginning the game or exiting
    if (input.compare("1") == 0)
    {
        start_game();
        // play the game
    }
    else if (input.compare("2") == 0)
    {
        std::cout << "Exiting...\n";
    }
    // just exit
    return;
}

void start_game()
{
    // create boards
    Board board1(8, 8);
    board1.print();
    std::cout << "Here is the game\n";
    return;
}