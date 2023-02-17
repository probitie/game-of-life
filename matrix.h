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

	void create_matrix(const int rows, const int cols);
	void fill_matrix(const mask_type& mask);

public:

	// TODO: move matrix code to another class
	Matrix();

	/// <summary>
	/// clears console before output matrix
	/// </summary>
	void update();

	void live();
};