#pragma once
#include "Item.h"

ref class Mouse : public Item
{
protected:
	//Class variables
	static System::Drawing::Icon^ mouseRight;
	static System::Drawing::Icon^ mouseLeft;
	static System::Drawing::Icon^ mouseUp;
	static System::Drawing::Icon^ mouseDown;
private:
	Mouse(void) {};
public:

	//Initializing Constructor
	Mouse(int row, int col);

	System::Drawing::Icon^ Mouse::getIcon() override;
	void Mouse::setIcon() override;

	//Utility methods
	void goRight() { col++; icon = 0; }
	void goLeft() { col--; icon = 1; }
	void goUp() { row--; icon = 2; }
	void goDown() { row++; icon = 3; }
};
