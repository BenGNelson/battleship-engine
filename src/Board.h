#include <random>

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
    void Place_destroyer();
    void Place_cruiser();
    void Place_battleship();
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

void Board::Place_destroyer()
{
    bool placed = false;
    int x = Get_random_x();
    int y = Get_random_y();
    while (placed == false)
    {
        if (Is_spot_occupied(play_space[x][y]) == false)
        {
            play_space[x][y] = 'D';
            placed = true;
        }
        else
        {
            x = Get_random_x();
            y = Get_random_y();
        }
    }
};

void Board::Place_cruiser()
{
    bool placed = false;
    int x = Get_random_x();
    int y = Get_random_y();
    while (placed == false)
    {
        if (Is_spot_occupied(play_space[x][y]) == false)
        {
            play_space[x][y] = 'C';
            placed = true;
        }
        else
        {
            x = Get_random_x();
            y = Get_random_y();
        }
    }
};

void Board::Place_battleship()
{
    bool placed = false;
    int x = Get_random_x();
    int y = Get_random_y();
    while (placed == false)
    {
        if (Is_spot_occupied(play_space[x][y]) == false)
        {
            play_space[x][y] = 'B';
            placed = true;
        }
        else
        {
            x = Get_random_x();
            y = Get_random_y();
        }
    }
};

void Board::Place_ships()
{
    Place_destroyer();
    Place_cruiser();
    Place_battleship();
};