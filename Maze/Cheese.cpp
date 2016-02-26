#include "Cheese.h"
Cheese::Cheese(int newRow, int newCol) : Item(newRow, newCol)
{
	setIcon();
}

void Cheese::setIcon()
{
	myIcon = gcnew System::Drawing::Icon("cheese.ico");
	icon = 0;
}

System::Drawing::Icon^ Cheese::getIcon()
{
	return myIcon;
}
