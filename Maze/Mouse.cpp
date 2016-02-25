#include "Mouse.h"
Mouse::Mouse(int newRow, int newCol) : Item(newRow, newCol)
{
	setIcon();
}

void Mouse::setIcon()
{
	mouseRight = gcnew System::Drawing::Icon("mouseRight.ico");
	mouseLeft = gcnew System::Drawing::Icon("mouseLeft.ico");
	mouseUp = gcnew System::Drawing::Icon("mouseUp.ico");
	mouseDown = gcnew System::Drawing::Icon("mouseDown.ico");
	icon = 0;
}

System::Drawing::Icon^ Mouse::getIcon()
{
	if (icon == 0)
		return mouseRight;
	else if (icon == 1)
		return mouseLeft;
	else if (icon == 2)
		return mouseUp;
	else
		return mouseDown;
}
