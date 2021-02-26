#include <random>

#include "Ship.h"

class Board
{
public:
    Board(int l, int w);
    int Get_length();
    int Get_width();
    void Print();

private:
    int length;
    int width;
    char **play_space;
    int Get_random_x();
    int Get_random_y();
    bool Is_spot_occupied(char spot);
    void Add_ship_to_board(Ship ship);
    void Add_ship_horizontally(int x, int y,Ship ship);
    void Add_ship_vertically(int x, int y,Ship ship);
    bool Is_in_bounds(int coords, int size);
    bool Is_overlapping(int x, int y, Ship ship);
    void Place_spot(int x, int y, char ship);
    void Place_ships();
};

Board::Board(int l, int w)
{
    length = l;
    width = w;

    play_space = new char *[length];
    for (int i = 0; i < length; i++)
    {
        play_space[i] = new char[width];
        for (int j = 0; j < width; j++)
        {
            play_space[i][j] = '-';
        }
    }

    Place_ships();
};

int Board::Get_length()
{
    return length;
};

int Board::Get_width()
{
    return width;
};

int Board::Get_random_x()
{
    return (rand() % length);
};

int Board::Get_random_y()
{
    return (rand() % width);
};

bool Board::Is_spot_occupied(char spot)
{
    if (spot == '-')
    {
        return false;
    }
    return true;
};

void Board::Print()
{
    for (int i = 0; i < length; ++i)
    {
        for (int j = 0; j < width; ++j)
        {
            std::cout << play_space[i][j] << ' ';
        }
        std::cout << std::endl;
    }
};

void Board::Add_ship_to_board(Ship ship)
{
    bool placed = false;
    int x = Get_random_x();
    int y = Get_random_y();

    if (ship.Get_orientation() == 0)
    {
        // horizontal
        Add_ship_horizontally(x, y, ship);
    }
    else
    {
        // vertical
        Add_ship_vertically(x, y, ship);
    }
};

void Board::Add_ship_horizontally(int x, int y, Ship ship)
{
    bool placed = false;

    while (placed == false)
        {
            if (Is_in_bounds(x, ship.Get_size()) && !Is_overlapping(x, y, ship))
            {
                for (int i = 0; i < ship.Get_size(); i++)
                {
                    Place_spot(x + i, y, ship.Get_type());
                }
                placed = true;
            }
            else
            {
                x = Get_random_x();
                y = Get_random_y();
            }
        }
}

void Board::Add_ship_vertically(int x, int y, Ship ship)
{
    bool placed = false;

    while (placed == false)
        {
            if (Is_in_bounds(y, ship.Get_size()) && !Is_overlapping(x, y, ship))
            {
                for (int i = 0; i < ship.Get_size(); i++)
                {
                    Place_spot(x, y + i, ship.Get_type());
                }
                placed = true;
            }
            else
            {
                x = Get_random_x();
                y = Get_random_y();
            }
        }
}


bool Board::Is_in_bounds(int coord, int size)
{
    if ((coord + (size - 1)) > (Get_length() - 1))
    {
        return false;
    }
    return true;
};

bool Board::Is_overlapping(int x, int y, Ship ship)
{
    bool overlapping = false;

    if (ship.Get_orientation() == 0)
    {
        // horizontal
        for (int i = 0; i < ship.Get_size(); i++)
        {
            if (Is_spot_occupied(play_space[y][x + i]))
            {
                overlapping = true;
            }
        }
    }
    else
    {
        // horizontal
        for (int i = 0; i < ship.Get_size(); i++)
        {
            if (Is_spot_occupied(play_space[y + i][x]))
            {
                overlapping = true;
            }
        }
    }
    return overlapping;
};

void Board::Place_spot(int x, int y, char ship)
{
    play_space[y][x] = ship;
};

void Board::Place_ships()
{
    Ship destroyer('D', 2);
    Ship cruiser('C', 3);
    Ship battleship('B', 4);
    Add_ship_to_board(destroyer);
    Add_ship_to_board(cruiser);
    Add_ship_to_board(battleship);
};