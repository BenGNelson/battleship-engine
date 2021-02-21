#include <random>

class Board {
    public:
        Board(int l, int w);
        int Get_length();
        int Get_width();
        void Print();


    private:
        int length;
        int width;
        char **play_space;
        void Place_ships();
        void Place_destroyer();

};

Board::Board (int l, int w) {
    length = l;
    width = w;

    play_space = new char *[length];
	for (int i = 0; i < length; i++)
	{
		play_space[i] = new char[width];
		for (int j = 0; j < width; j++)
		{
			play_space[i][j] = 'O';
		}
	}

    Place_ships();
};

int Board::Get_length () {
    return length;
};

int Board::Get_width () {
    return width;
};

void Board::Print() {
	for (int i = 0; i < length; ++i)
	{
		for (int j = 0; j < width; ++j)
		{
			std::cout << play_space[i][j] << ' ';
		}
		std::cout << std::endl;
	}
};

void Board::Place_ships() {
    Place_destroyer();
}

void Board::Place_destroyer() {
    int rand_x = (rand() % length);
    int rand_y = (rand() % width);

    std::cout << rand_x << " " << rand_y << "\n";
    play_space[rand_x][rand_y] = 'X';
};