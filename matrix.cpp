#include "matrix.h"

void Matrix::updateScreen()
{
	clear_console();

	for_range(3) 
	{
		out << "* * *" << "\n";
	}
};