#include "matrix.h"

Matrix::Matrix() : 
	matrix{ 
	{ 
		{0, 0, 1},
		{0, 1, 0},
		{1, 1, 1}
	} 
		  }
{
}

void Matrix::updateScreen()
{
	clear_console();

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			out << cur_elem(matrix) << " ";
		}
		out << "\n";
	}
	out << std::endl; // flush buffer
};