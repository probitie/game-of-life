// GameOfLife.cpp : Defines the entry point for the application.
//

/// 
///  ... it is better to have a bad something than a good nothing ...
///

/// ( so do not judge my code too much )

#include "libs.h"
#include "matrix.h"
#include "defines.h"


int main()
{	
	Matrix matrix{}; // todo set initial field

	while(1)
	{
		matrix.update();
		sleep(1000);
	};
	return 0;
}
