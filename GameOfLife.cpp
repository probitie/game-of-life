// GameOfLife.cpp : Defines the entry point for the application.
//
#include "libs.h"
#include "matrix.h"
#include "defines.h"


int main()
{	
	Matrix matrix{}; // todo set initial field

	for_range(10)
	{
		matrix.updateScreen();
		out << "ee " << i;
		sleep(1000);
	};
	return 0;
}
