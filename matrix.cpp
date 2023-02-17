#include "matrix.h"

Matrix::Matrix() : matrix{}
{
	// pass filled rows in compact fomat (like vector<pair<int, int>> coordinates)
	fill_matrix(20, 20, mask_type{ {2, 2}, {3, 3}, {4, 4}, {5, 1} });
}

/// <summary>
/// 
/// </summary>
/// <param name="rows"></param>
/// <param name="cols"></param>
/// <param name="mask"> which cells are filled </param>
void Matrix::fill_matrix(const int rows, const int cols, const mask_type &mask)
{
	for_range_var(rows, i)
	{
		matrix.push_back(row_type{});
			for_range_var(cols, j)
		{
			matrix.at(i).push_back(0);
		};
	}

	// fill matrix
	for_range(mask.size())
	{
		auto& pair = mask.at(i);
		matrix.at(pair.first).at(pair.second) = 1;
	}
}

void Matrix::updateScreen()
{
	clear_console();

	for (int i = 0; i < matrix.size(); i++)
	{
		for (int j = 0; j < matrix.at(0).size(); j++)
		{
			screen_buffer << cur_elem(matrix) << " ";
		}
		screen_buffer << "\n";
	}
	screen_buffer << flush;
};