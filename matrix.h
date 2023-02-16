#pragma once
#include "libs.h"
#include "defines.h"
#include <array>

class Matrix
{
private:
	
	// TODO: use bitset or a pointer here
	//std::vector<std::vector<int>&&> &&matrix;


public:

	Matrix() = default;
	/// <summary>
	/// clears console before output matrix
	/// </summary>
	void updateScreen();
};