#pragma once
#pragma once
#include "Item.h"

ref class Cheese : public Item
{
protected:
	//Class variables
	static System::Drawing::Icon^ myIcon;

public:
	Cheese(void) { setIcon(); };

	//Initializing Constructor
	Cheese(int row, int col);

	System::Drawing::Icon^ Cheese::getIcon() override;
	void Cheese::setIcon() override;


};
