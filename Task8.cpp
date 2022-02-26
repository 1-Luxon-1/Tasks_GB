#include<iostream>
#include<random>
#include<chrono>
#include<stdlib.h>
using namespace std;

///////////////////////////////////////////////////////////////////////////////
enum TCell:char 
{
	CROSS = 'X',
	ZERO = '0',
	EMPTY = '_'
};

enum TProgress 
{
	IN_PROGRESS,
	WON_HUMAN,
	WON_COMPUTER,
	DRAW
};

struct TCoord
{
	size_t x{0};
	size_t y{0};
};

struct TGame
{
	const size_t SIZE{ 3 };
	TCell** ppFiled {nullptr};
	TCell human;
	TCell ai;
	TProgress progress{IN_PROGRESS};
	size_t turn{0};
};
///////////////////////////////////////////////////////////////////////////////////////////////////

int32_t getRandomNum(int32_t min, int32_t max)
{
	const static auto seed = chrono::system_clock::now().time_since_epoch().count();
	static mt19937_64 generator(seed);
	uniform_int_distribution<int32_t> dis(min, max);
	return dis(generator);
}


//--------------------------------------------------------
void __fastcall initGame(TGame& g)
{
	g.ppFiled = new TCell * [g.SIZE];
	for (size_t i = 0; i < g.SIZE; i++)
	{
		g.ppFiled[i] = new TCell[g.SIZE];
	}

	for (size_t y = 0; y < g.SIZE; y++)
	{
		for (size_t x = 0; x < g.SIZE; x++)
		{
			g.ppFiled[y][x]= EMPTY;
		}
	}
	if (getRandomNum(0, 10) < 5)
	{
		g.human = CROSS;
		g.ai = ZERO;
		g.turn = 0;
	}
	else
	{
		g.human = ZERO;
		g.ai = CROSS;
		g.turn = 1;
	}
}

//--------------------------------------------------------
void deinitGame(TGame& g)
{
	for (size_t i = 0; i < g.SIZE; i++)
	{
		delete [] g.ppFiled[i];
	}
	delete[] g.ppFiled;
	g.ppFiled = nullptr;
}

//--------------------------------------------------------
void __fastcall printGame(const TGame& g)
{
	cout << "    ";
	for (size_t x = 0; x < g.SIZE; x++)
	{
		cout << x + 1 << "   ";
	}
	cout << endl;
	for (size_t y = 0; y < g.SIZE; y++)
	{
		cout << y + 1 << " | ";
		for (size_t x = 0; x < g.SIZE; x++)
		{
			cout << g.ppFiled[y][x] << " | ";
		}
		cout << endl;
	}
	cout << endl << " Human: " << g.human << endl << " Computer: " << g.ai << endl;
}

//--------------------------------------------------------
TProgress __fastcall getWon(const TGame& g)
{
	for (size_t y = 0; y < g.SIZE; y++)
	{
		if (g.ppFiled[y][0] == g.ppFiled[y][1] && g.ppFiled[y][0] == g.ppFiled[y][2])
		{
			if (g.ppFiled[y][0] == g.human)
			{
				return WON_HUMAN;
			}
			if (g.ppFiled[y][0] == g.ai)
			{
				return WON_COMPUTER;
			}
		}
	}

	for (size_t x = 0; x < g.SIZE; x++)
	{
		if (g.ppFiled[0][x] == g.ppFiled[1][x] && g.ppFiled[0][x] == g.ppFiled[2][x])
		{
			if (g.ppFiled[0][x] == g.human)
			{
				return WON_HUMAN;
			}
			if (g.ppFiled[0][x] == g.ai)
			{
				return WON_COMPUTER;
			}
		}
	}

	
	if (g.ppFiled[0][0] == g.ppFiled[1][1] && g.ppFiled[0][0] == g.ppFiled[2][2])
	{
		if (g.ppFiled[0][0] == g.human)
		{
			return WON_HUMAN;
		}
		if (g.ppFiled[0][0] == g.ai)
		{
			return WON_COMPUTER;
		}
	}

	if (g.ppFiled[0][2] == g.ppFiled[1][1] && g.ppFiled[0][2] == g.ppFiled[2][0])
	{
		if (g.ppFiled[1][1] == g.human)
		{
			return WON_HUMAN;
		}
		if (g.ppFiled[1][1] == g.ai)
		{
			return WON_COMPUTER;
		}
	}

	bool draw{ true };
	for (size_t y = 0; y < g.SIZE; y++)
	{
		for (size_t x = 0; x < g.SIZE; x++)
		{
			if (g.ppFiled[y][x] == EMPTY)
			{
				draw = false;
				break;
			}

		}
		if (!draw)
		{
			break;
		}
	}

	if (draw)
	{
		return DRAW;
	}
return IN_PROGRESS;
}

//--------------------------------------------------------
TCoord __fastcall getHumanCoord(const TGame& g)
{
	TCoord c{0};
	do {
		cout << " Enter to X (1..3): ";
		cin >> c.x;
		cout << " Enter to Y (1..3): ";
		cin >> c.y;

		c.x--;
		c.y--;
	} while (c.x > 2 || c.y > 2 || g.ppFiled[c.y][c.x] != EMPTY);
	return c;
}


//--------------------------------------------------------
TCoord __fastcall getComputerCoord(TGame& g)
{

	for (size_t y = 0; y < g.SIZE; y++)
	{
		for (size_t x = 0; x < g.SIZE; x++)
		{
			g.ppFiled[y][x] = g.ai;
			if (getWon(g) == WON_COMPUTER)
			{
				g.ppFiled[y][x] = EMPTY;
				return { y, x };
			}
			g.ppFiled[y][x] = EMPTY;
		}
	}


	for (size_t y = 0; y < g.SIZE; y++)
	{
		for (size_t x = 0; x < g.SIZE; x++)
		{
			g.ppFiled[y][x] = g.human;
			if (getWon(g) == WON_HUMAN)
			{
				g.ppFiled[y][x] = EMPTY;
				return { y, x };
			}
			g.ppFiled[y][x] = EMPTY;
		}
	}

	if (g.ppFiled[1][1] == EMPTY)
	{
		return { 1, 1 };
	}

	TCoord buf[4];
	size_t num = 0;
	if (g.ppFiled[0][0] == EMPTY)
	{
		buf[num] = { 0, 0 }; 
		num++;
	}
	if (g.ppFiled[2][0] == EMPTY)
	{
		buf[num] = { 2, 0 };
		num++;
	}
	if (g.ppFiled[0][2] == EMPTY)
	{
		buf[num] = { 0, 2 };
		num++;
	}
	if (g.ppFiled[2][2] == EMPTY)
	{
		buf[num] = { 2, 2 };
		num++;
	}

	if (num > 0)
	{
		const size_t index = getRandomNum(0, 1000) % num;
		return buf[index];
	}

	num = 0;
	if (g.ppFiled[0][1] == EMPTY)
	{
		buf[num] = { 0, 1 };
		num++;
	}
	if (g.ppFiled[1][0] == EMPTY)
	{
		buf[num] = { 1, 0 };
		num++;
	}if (g.ppFiled[2][1] == EMPTY)
	{
		buf[num] = { 2, 1 };
		num++;
	}if (g.ppFiled[1][2] == EMPTY)
	{
		buf[num] = { 1, 2 };
		num++;
	}

	if (num > 0)
	{
		const size_t index = getRandomNum(0, 1000) % num;
		return buf[index];
	}
}


//--------------------------------------------------------
void congrats(const TGame& g)
{
	if (g.progress == WON_HUMAN)
	{
		cout << " Human won =)" << endl;
	}
	else if (g.progress == WON_COMPUTER)
	{
		cout << " Computer won =/" << endl;
	}
	else if (g.progress == DRAW)
	{
		cout << " It is draw =(" << endl;
	}
}

////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////
int main()
{
	TGame g;
	initGame(g);
	printGame(g);
	do {
		if (g.turn % 2 == 0)
		{
			TCoord c = getHumanCoord(g);
			g.ppFiled[c.y][c.x] = g.human;
		}
		else
		{
			TCoord c = getComputerCoord(g);
			g.ppFiled[c.y][c.x] = g.ai;
		}

		g.turn++;
		system("cls");
		printGame(g);
		g.progress = getWon(g);

	} while (g.progress == IN_PROGRESS);

	congrats(g);
	deinitGame(g);
	return 0;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////