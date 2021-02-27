#include <random>

#include "Ship.h"

class Board
{
public:
    Board(int l, int w);
    int get_length();
    int get_width();
    void print();

private:
    int length;
    int width;
    char **play_space;
    int get_random_x();
    int get_random_y();
    bool is_spot_occupied(char spot);
    void add_ship_to_board(Ship ship);
    void add_ship_horizontally(int x, int y,Ship ship);
    void add_ship_vertically(int x, int y,Ship ship);
    bool is_in_bounds(int coords, int size);
    bool is_overlapping(int x, int y, Ship ship);
    void place_spot(int x, int y, char ship);
    void place_ships();
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

    place_ships();
};

int Board::get_length()
{
    return length;
};

int Board::get_width()
{
    return width;
};

int Board::get_random_x()
{
    return (rand() % length);
};

int Board::get_random_y()
{
    return (rand() % width);
};

bool Board::is_spot_occupied(char spot)
{
    if (spot == '-')
    {
        return false;
    }
    return true;
};

void Board::print()
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

void Board::add_ship_to_board(Ship ship)
{
    bool placed = false;
    int x = get_random_x();
    int y = get_random_y();

    if (ship.Get_orientation() == 0)
    {
        // horizontal
        add_ship_horizontally(x, y, ship);
    }
    else
    {
        // vertical
        add_ship_vertically(x, y, ship);
    }
};

void Board::add_ship_horizontally(int x, int y, Ship ship)
{
    bool placed = false;

    while (placed == false)
        {
            if (is_in_bounds(x, ship.Get_size()) && !is_overlapping(x, y, ship))
            {
                for (int i = 0; i < ship.Get_size(); i++)
                {
                    place_spot(x + i, y, ship.Get_type());
                }
                placed = true;
            }
            else
            {
                x = get_random_x();
                y = get_random_y();
            }
        }
}

void Board::add_ship_vertically(int x, int y, Ship ship)
{
    bool placed = false;

    while (placed == false)
        {
            if (is_in_bounds(y, ship.Get_size()) && !is_overlapping(x, y, ship))
            {
                for (int i = 0; i < ship.Get_size(); i++)
                {
                    place_spot(x, y + i, ship.Get_type());
                }
                placed = true;
            }
            else
            {
                x = get_random_x();
                y = get_random_y();
            }
        }
}


bool Board::is_in_bounds(int coord, int size)
{
    if ((coord + (size - 1)) > (get_length() - 1))
    {
        return false;
    }
    return true;
};

bool Board::is_overlapping(int x, int y, Ship ship)
{
    bool overlapping = false;

    if (ship.Get_orientation() == 0)
    {
        // horizontal
        for (int i = 0; i < ship.Get_size(); i++)
        {
            if (is_spot_occupied(play_space[y][x + i]))
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
            if (is_spot_occupied(play_space[y + i][x]))
            {
                overlapping = true;
            }
        }
    }
    return overlapping;
};

void Board::place_spot(int x, int y, char ship)
{
    play_space[y][x] = ship;
};

void Board::place_ships()
{
    Ship destroyer('D', 2);
    Ship cruiser('C', 3);
    Ship battleship('B', 4);
    add_ship_to_board(destroyer);
    add_ship_to_board(cruiser);
    add_ship_to_board(battleship);
};