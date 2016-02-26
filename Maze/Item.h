#pragma once
ref class Item abstract
{
protected:
	int row; //row location in maze
	int col; //column location in maze
	int icon; //icon indicator(0-right, 1=left, 2=up, 3=down)

public:
	Item(void) {};
public:

	//Initializing Constructor
	Item(int newRow, int newCol)
	{
		//Verify and set to initialization parameters
		if (newRow >= 0) row = newRow;
		if (newCol >= 0) col = newCol;
	};

	//Accessor Methods
	int getRow() { return row; }
	int getCol() { return col; }
	virtual System::Drawing::Icon^ getIcon() = 0;
	virtual void setIcon() = 0;

	//Mutator Methods
	void setRow(int newRow) { row = newRow; }
	void setCol(int newCol) { col = newCol; }

	void MoveTo(int newRow, int newCol)
	{
		setRow(newRow);
		setCol(newCol); 

	};

	
};
