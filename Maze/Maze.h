#pragma once
#include "Mouse.h"
#include "Cell.h"
#include "Cheese.h"

ref class Maze
{
private:
	Cheese^ myCheese;
	Mouse^ myMouse;
	array <Cell^, 2>^ grid;
public:
	static const int NUMROWS = 16;
	static const int NUMCOLS = 20;
	Maze() 
	{
		//Create cheese
		myCheese = gcnew Cheese();

		//Create mouse
		myMouse = gcnew Mouse();
		
		//Construct grid array
		grid = gcnew array<Cell^, 2>(NUMROWS, NUMCOLS);
		for (int row = 0; row < NUMROWS; row++)
		{
			for (int col = 0; col < NUMCOLS; col++)
			{
				grid[row, col] = gcnew Cell(row, col, true);
			}
		}
	};
	Cheese^ getCheese() { return myCheese; };
	Mouse^ getMouse() { return myMouse; };
	array <Cell^, 2>^ getGrid() { return grid; };
};
