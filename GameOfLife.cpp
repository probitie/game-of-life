// GameOfLife.cpp : Defines the entry point for the application.
//

#include "GameOfLife.h"

using namespace std;

#define clear_console() system("cls")

#define out std::cout // outstream

// TODO: use postfix notation like 4s or 10ms (i've seen it somewhere already)

// sleep(4000) means sleep for 4 sec
#define sleep(ms) std::this_thread::sleep_for(std::chrono::milliseconds(ms));

// WARNING: additional behavior - throws 'i' counter variable into the scope
#define for_range(range) for(int i = 0; i < range; ++i)

// singleton
class Matrix
{
public:
	/// <summary>
	/// clears console before output matrix
	/// </summary>
	void updateScreen()
	{
		clear_console();
		
		for_range(3) {
			out << "* * *" << "\n";
		}
	};
};

int main()
{	
	Matrix matrix; // todo set initial field

	for_range(10)
	{
		matrix.updateScreen();
		out << "ee " << i;
		sleep(1000);
	};
	return 0;
}
