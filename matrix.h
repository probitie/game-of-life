#pragma once
#include "libs.h"
#include "defines.h"
#include <array>

class Matrix
{
private:
	using matrix_type = std::vector<std::vector<int>>;
	// TODO: use bitset or a pointer here
	matrix_type matrix;


public:

	Matrix();
	/// <summary>
	/// clears console before output matrix
	/// </summary>
	void updateScreen();
};