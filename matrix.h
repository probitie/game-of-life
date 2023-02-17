#pragma once
#include "libs.h"
#include "defines.h"
#include <array>

// GoL board
class Matrix
{
private:
	using row_type = std::vector<bool>;
	using matrix_type = std::vector<row_type>;
	using mask_type = std::vector<std::pair<int, int>>;
	// TODO: use bitset or a pointer here
	matrix_type matrix;


public:

	Matrix();

	// TODO: create_matrix and move filling to another method
	void fill_matrix(const int rows, const int cols, const mask_type& mask);

	/// <summary>
	/// clears console before output matrix
	/// </summary>
	void updateScreen();
};