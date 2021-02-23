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
    int Get_random_orientation();
    bool Is_spot_occupied(char spot);
    void Add_ship_to_board(char ship);
    bool Is_in_bounds(int coords);
    bool Is_not_overlapping(int x, int y, int orientation);
    void Place_spot(int x, int y, char ship);
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

int Board::Get_random_orientation()
{
    int random = (rand() % 10) + 1;
    // return 0 for horizontal or 1 for vertical
    if (random % 2 == 0)
    {
        return 0;
    }
    return 1;
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

void Board::Add_ship_to_board(char ship)
{
    bool placed = false;
    int x = Get_random_x();
    int y = Get_random_y();
    int orientation = Get_random_orientation();

    if (orientation == 0)
    {
        while (placed == false)
        {
            // horizontal
            if (Is_in_bounds(x) && Is_not_overlapping(x, y, orientation))
            {
                //soemthing
                Place_spot(x - 1, y, ship);
                Place_spot(x, y, ship);
                Place_spot(x + 1, y, ship);
                placed = true;
            }
            else
            {
                x = Get_random_x();
                y = Get_random_y();
            }
        }
    }
    else
    {
        while (placed == false)
        {
            // vertical
            if (Is_in_bounds(y) && Is_not_overlapping(x, y, orientation))
            {
                //soemthing
                Place_spot(x, y - 1, ship);
                Place_spot(x, y, ship);
                Place_spot(x, y + 1, ship);
                placed = true;
            }
            else
            {
                x = Get_random_x();
                y = Get_random_y();
            }
        }
    }
};


bool Board::Is_in_bounds(int coord)
{
    if (coord -1 > 0 && coord > 0 && coord + 1 > 0)
    {
        return true;
    }
    return false;
};

bool Board::Is_not_overlapping(int x, int y, int orientation)
{
    if (orientation == 0)
    {
        // horizontal
        if (
            !Is_spot_occupied(play_space[x - 1][y]) &&
            !Is_spot_occupied(play_space[x][y]) &&
            !Is_spot_occupied(play_space[x + 1][y]))

        {
            return true;
        }
    }
    else
    {
        // vertical
        if (
            !Is_spot_occupied(play_space[x][y - 1]) &&
            !Is_spot_occupied(play_space[x][y]) &&
            !Is_spot_occupied(play_space[x][y + 1]))
        {
            return true;
        }
    }
    return false;
};

    void Board::Place_spot(int x, int y, char ship)
    {
        play_space[x][y] = ship;
    };

    void Board::Place_destroyer()
    {
        bool placed = false;
        int x = Get_random_x();
        int y = Get_random_y();
        std::cout << Get_random_orientation() << std::endl;
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
        Add_ship_to_board('C');
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