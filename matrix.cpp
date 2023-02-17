#include "matrix.h"

Matrix::Matrix() : matrix{}
{
	// pass filled rows in compact fomat (like vector<pair<int, int>> coordinates)
	create_matrix(20, 20);
	fill_matrix(mask_type{ {2, 2}, {3, 3}, {4, 4}, {5, 1} });
}

void Matrix::fill_matrix(const mask_type& mask)
{
	for_range(mask.size())
	{
		auto& pair = mask.at(i);
		matrix.at(pair.first).at(pair.second) = 1;
	}
}

/// <summary>
/// 
/// </summary>
/// <param name="rows"></param>
/// <param name="cols"></param>
/// <param name="mask"> which cells are filled </param>
void Matrix::create_matrix(const int rows, const int cols)
{
	for_range_var(rows, i)
	{
		matrix.push_back(row_type{});
			for_range_var(cols, j)
		{
			matrix.at(i).push_back(0);
		};
	}
}

// finite state machine: state 0 and state 1
void Matrix::live()
{
	/*
	
	go through matrix

	find a live cell (value 1 / true)

	+ - 1: get all neighbours
	count how much of them are alive

	if < 2 
		kill current cell
	if 2-3 
		pass
	if > 3
		kill cell

	check dead cells around
		for each check neighbours
			if there 3 neighbours - make it alive

	...
	draw the result(in other method)

	*/
}

void Matrix::update()
{
	clear_console();

	live();

	for (int i = 0; i < matrix.size(); i++)
	{
		for (int j = 0; j < matrix.at(0).size(); j++)
		{
			screen_buffer << (cur_elem(matrix) == 0 ? '.' : '*') << " ";
		}
		screen_buffer << "\n";
	}
	screen_buffer << flush;
};