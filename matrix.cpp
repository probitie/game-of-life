#include "matrix.h"

Matrix::Matrix() : matrix{}, height{20}, width{20}
{
	// pass filled rows in compact fomat (like vector<pair<int, int>> coordinates)
	create_matrix(height, width);
	fill_matrix(coordinate_sequnce{ {2, 2}, {2, 3}, {3, 2}, {2, 1} });
}

void Matrix::fill_matrix(const coordinate_sequnce& mask)
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
	// leave border 1 cell wide
	for (int i = 1; i < matrix.size() - 1; ++i)
	{
		for (int j = 1; j < matrix.at(0).size() - 1; ++j)
		{
			if (cur_elem(matrix) == ALIVE)
			{
				const coordinate_sequnce& neighbours = get_neighbours(i, j);

				const int cur_count_alive = count_alive(neighbours);

				if (cur_count_alive < 2 || cur_count_alive > 3)
				{
					// kill cell
					cur_elem(matrix) = DEAD;
				}
				// else - 2 or 3 cells around - do nothing

				// i check dead cells only after finding alive one because checking dead cells makes sense if
				// there are alive cells around
				reborn_cells_near_alives(neighbours);
			}
		}
	}


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

void Matrix::reborn_cells_near_alives(const coordinate_sequnce& neighbours)
{
	for (const auto& neighbour : neighbours)
	{
		const auto& his_neighbours =
			get_neighbours(neighbour.first, neighbour.second);

		if (count_alive(his_neighbours) == 3)
		{
			// reborn
			matrix.at(neighbour.first).at(neighbour.second) = ALIVE;
		}
	}
}

int Matrix::count_alive(const coordinate_sequnce& neighbours)
{
	int res{};
	for (const auto& pair : neighbours)
	{
		if (matrix.at(pair.first).at(pair.second) == ALIVE)
			++res;
	}
	return res;
}

Matrix::coordinate_sequnce Matrix::get_neighbours(const int row, const int col)
{
	const int low_h = 0;
	const int low_w = 0;
	const int high_h = height - 1;
	const int high_w = width - 1;
#define clamp_row(val) std::clamp( val, low_h,  high_h)
#define clamp_col(val) std::clamp( val, low_w,  high_w)

	return 
	{	
		/// . . . . . 
		/// . * * * .
		//  . . x . .
		/// . . . . .
		{clamp_row(row - 1), col},
		{clamp_row(row - 1), clamp_col(col - 1)},
		{clamp_row(row - 1), clamp_col(col + 1)},

		/// . . . . . 
		/// . . . . .
		//  . . x . .
		/// . * * * .
		{clamp_row(row + 1), col},         
		{clamp_row(row + 1), clamp_col(col - 1)},		
		{clamp_row(row + 1), clamp_col(col + 1)},		

		/// . . . . . 
		/// . . . . .
		//  . * x * .
		/// . . . . .
		{row, clamp_col(col - 1)},			
		{row, clamp_col(col + 1)},			
	};
}


void Matrix::update()
{
	clear_console();

	for (int i = 0; i < matrix.size(); i++)
	{
		for (int j = 0; j < matrix.at(0).size(); j++)
		{
			screen_buffer << (cur_elem(matrix) == DEAD ? '.' : '*') << " ";
		}
		screen_buffer << "\n";
	}

	// live is after drawind to show initial state of a game
	live();
	screen_buffer << flush;
};