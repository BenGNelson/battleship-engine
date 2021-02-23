#include <random>

class Ship
{
public:
    Ship(char type, int size);
    char Get_type();
    int Get_size();
    int Get_orientation();

private:
    char type;
    int size;
    int orientation;
    int Set_orientation();
};

Ship::Ship(char t, int s)
{
    type = t;
    size = s;
};

char Ship::Get_type()
{
    return type;
};

int Ship::Get_size()
{
    return size;
};

int Ship::Get_orientation()
{
    return orientation;
};

int Ship::Set_orientation()
{
    int random = (rand() % 10) + 1;
    // return 0 for horizontal or 1 for vertical
    if (random % 2 == 0)
    {
        return 0;
    }
    return 1;
};