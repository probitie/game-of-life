#pragma once
#include "libs.h"
#include "defines.h"
#include <array>

// GoL board
class Matrix
{
private:

	enum State 
	{
		DEAD,
		ALIVE
	};

	using row_type = std::vector<bool>;
	using matrix_type = std::vector<row_type>;
	using coordinate_sequnce = std::vector<std::pair<int, int>>;
	// TODO: use bitset or a pointer here
	matrix_type matrix;
	const int height{};
	const int width{};

	void create_matrix(const int rows, const int cols);
	void fill_matrix(const coordinate_sequnce& mask);

public:

	// TODO: move matrix code to another class
	Matrix();

	/// <summary>
	/// clears console before output matrix
	/// </summary>
	void update();

	void live();

	int count_alive(const coordinate_sequnce& neighbours);
	void reborn_cells_near_alives(const coordinate_sequnce& neighbours);

	/// <summary>
	/// returns cells around one with this coordinates
	/// 
	/// actually it looks like {row - 1, col}, {row - 1, col - 1}; {row, col - 1} ...
	/// </summary>
	/// <param name="row"></param>
	/// <param name="col"></param>
	/// <returns></returns>
	coordinate_sequnce get_neighbours(const int row, const int col);
};