#pragma once
#include "Maze.h"
#include "Utility.h"

namespace MazeProject 
{

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private:
		//Instance variables
		//Mouse^ myMouse;
		//array <Cell^, 2>^ maze;
		Maze^ maze;
		char direction;

		//Drawing objects
		Graphics^ g;
		Brush^ grayBrush;
		Brush^ whiteBrush;
		Brush^ burlyBrush;
		Brush^ paleTurquoiseBrush;

		Pen^ blackPen;

		//Static constants
		/*static const int NUMROWS = 16;
		static const int NUMCOLS = 20;*/
		static const int CELLSIZE = 25;
	private: System::Windows::Forms::Panel^  panel1;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Timer^  timer1;
	private: System::Windows::Forms::Label^  label1;
	private: System::ComponentModel::IContainer^  components;



			 /// <summary>
			 /// Required designer variable.
			 /// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
			 void InitializeComponent(void)
			 {
				 this->components = (gcnew System::ComponentModel::Container());
				 this->panel1 = (gcnew System::Windows::Forms::Panel());
				 this->button1 = (gcnew System::Windows::Forms::Button());
				 this->button2 = (gcnew System::Windows::Forms::Button());
				 this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
				 this->label1 = (gcnew System::Windows::Forms::Label());
				 this->SuspendLayout();
				 // 
				 // panel1
				 // 
				 this->panel1->Location = System::Drawing::Point(33, 43);
				 this->panel1->Name = L"panel1";
				 this->panel1->Size = System::Drawing::Size(1493, 994);
				 this->panel1->TabIndex = 0;
				 // 
				 // button1
				 // 
				 this->button1->Location = System::Drawing::Point(1085, 1077);
				 this->button1->Name = L"button1";
				 this->button1->Size = System::Drawing::Size(168, 63);
				 this->button1->TabIndex = 1;
				 this->button1->Text = L"Start";
				 this->button1->UseVisualStyleBackColor = true;
				 this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
				 // 
				 // button2
				 // 
				 this->button2->Location = System::Drawing::Point(1307, 1077);
				 this->button2->Name = L"button2";
				 this->button2->Size = System::Drawing::Size(155, 63);
				 this->button2->TabIndex = 2;
				 this->button2->Text = L"Stop";
				 this->button2->UseVisualStyleBackColor = true;
				 this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
				 // 
				 // timer1
				 // 
				 this->timer1->Tick += gcnew System::EventHandler(this, &MyForm::timer1_Tick);
				 // 
				 // label1
				 // 
				 this->label1->AutoSize = true;
				 this->label1->Location = System::Drawing::Point(145, 1093);
				 this->label1->Name = L"label1";
				 this->label1->Size = System::Drawing::Size(93, 32);
				 this->label1->TabIndex = 3;
				 this->label1->Text = L"label1";
				 // 
				 // MyForm
				 // 
				 this->AutoScaleDimensions = System::Drawing::SizeF(16, 31);
				 this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
				 this->AutoSize = true;
				 this->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
				 this->ClientSize = System::Drawing::Size(1580, 1178);
				 this->Controls->Add(this->label1);
				 this->Controls->Add(this->panel1);
				 this->Controls->Add(this->button2);
				 this->Controls->Add(this->button1);
				 this->Name = L"MyForm";
				 this->Text = L"Maze";
				 this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
				 this->ResumeLayout(false);
				 this->PerformLayout();

			 }
#pragma endregion
	private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e) {

//		int row, col;


		g = panel1->CreateGraphics();
		grayBrush = gcnew System::Drawing::SolidBrush(Color::Gray);
		whiteBrush = gcnew System::Drawing::SolidBrush(Color::White);
		burlyBrush = gcnew System::Drawing::SolidBrush(Color::BurlyWood);
		paleTurquoiseBrush = gcnew System::Drawing::SolidBrush(Color::PaleTurquoise);
		blackPen = gcnew System::Drawing::Pen(Color::Black);

		maze = gcnew Maze();
		////Construct maze array
		//maze = gcnew array<Cell^, 2>(NUMROWS, NUMCOLS);
		//for (row = 0; row < NUMROWS; row++)
		//{
		//	for (col = 0; col < NUMCOLS; col++)
		//	{
		//		maze[row, col] = gcnew Cell(row, col, true);
		//	}
		//}
	}


	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {

		//Local variables
		int x, y;
		Drawing::Icon^ cheese = gcnew System::Drawing::Icon("cheese.ico");

		//Starting postion for mouse
		int mouseRow = 9;
		int mouseCol = 0;

		//Starting cheese location
		int cheeseRow = 11;
		int cheeseCol = 8;

		//Set initial direction
		direction = 'r';

		//Move Mouse
		maze->getMouse()->MoveTo(mouseRow, mouseCol);
		//maze->getMouse() = gcnew Mouse(mouseRow, mouseCol);
	
		//Draw the maze
		drawMaze();

		//Draw cheese
		x = cheeseCol * CELLSIZE;
		y = cheeseRow * CELLSIZE;
		Rectangle cheeseRect = Rectangle(x, y, CELLSIZE, CELLSIZE);
		g->DrawIcon(cheese, cheeseRect);
		maze->getGrid()[cheeseRow, cheeseCol]->setCheese(true);
		//explain
		//array <Cell^, 2>^ grid= maze->getGrid();
		//grid[1,0]

		//Draw the mouse
		//myMouse->setRow(mouseRow);
		//myMouse->setCol(mouseCol);
		x = mouseCol * CELLSIZE;
		y = mouseRow * CELLSIZE;
		Rectangle mouseRect = Rectangle(x, y, CELLSIZE, CELLSIZE);
		g->DrawIcon(maze->getMouse()->getIcon(), mouseRect);

		//Start the timer
		timer1->Start();


	}

	private: void drawMaze()
	{
		//Declare local variables;
//		int row, col;
		int x, y;

		//Refresh the panel
		panel1->Refresh();

		//Draw the empty maze
		for (int row = 0; row < maze->NUMROWS; row++)
		{
			for (int col = 0; col < maze->NUMCOLS; col++)
			{
				x = col * CELLSIZE;
				y = row * CELLSIZE;
				Rectangle gridRect = Rectangle(x, y, CELLSIZE - 1, CELLSIZE - 1);
				g->FillRectangle(whiteBrush, gridRect);
				g->DrawRectangle(blackPen, gridRect);
			}
		}
	}
	private: bool edge()
	{
		if (direction == 'r') {
			if (maze->getMouse()->getCol() < maze->NUMCOLS - 1) return false;
		}
		else if (direction == 'l') {
			if (maze->getMouse()->getCol() > 0) return false;
		}
		else if (direction == 'u') {
			if (maze->getMouse()->getRow() > 0) return false;
		}
		else if (direction == 'd') {
			if (maze->getMouse()->getRow() < maze->NUMROWS - 1) return false;
		}
		return true;

	}
	private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) {
		//Declare local variables;
		int x, y;
		int row, col;

		//Initializing local variables;
		row = maze->getMouse()->getRow();
		col = maze->getMouse()->getCol();
		x = maze->getMouse()->getCol() * CELLSIZE;
		y = maze->getMouse()->getRow() * CELLSIZE;

		//Create current myMouse position
		Rectangle oldRect = Rectangle(x, y, CELLSIZE, CELLSIZE);


		if (!edge())
		{
			//Fill old mouse position with BurlyWood
			if( maze->getGrid()[row,col]->getAccess())
				g->FillRectangle(paleTurquoiseBrush, oldRect);
			else
				g->FillRectangle(burlyBrush, oldRect);
			g->DrawRectangle(blackPen, oldRect);
			
			maze->getGrid()[row, col]->setAccess(false);

			//Move in the chosen direction
			//direction = pickupADirection();
			switch (direction)
			{
			case 'r':
				maze->getMouse()->goRight();
				break;
			case 'l':
				maze->getMouse()->goLeft();
				break;
			case 'u':
				maze->getMouse()->goUp();
				break;
			case 'd':
				maze->getMouse()->goDown();
				break;
			}


			//Draw mouse at new location
			row = maze->getMouse()->getRow();
			col = maze->getMouse()->getCol();

			//Check access if never access then go ahead
			if (maze->getGrid()[row, col]->getAccess())
			{


				x = col * CELLSIZE;
				y = row * CELLSIZE;
				Rectangle mouseRect = Rectangle(x, y, CELLSIZE, CELLSIZE);
				g->DrawIcon(maze->getMouse()->getIcon(), mouseRect);

				//if mouse moves into cell with cheese, congratulations!
				if (maze->getGrid()[row, col]->getCheese())
				{
					maze->getGrid()[row, col]->setCheese(false);
					timer1->Stop();
					MessageBox::Show("Congratulation!", "You found it");
				}
			}
			else // if have access then skip, pick up another direction
			{
				direction = pickupADirection();
			}
		}
		else // at the edge
		{
			switch (direction)
			{
			case 'r':
				direction = 'd';
				break;
			case 'l':
				direction = 'u';
				break;
			case 'u':
				direction = 'r';
				break;
			case 'd':
				direction = 'l';
				break;
			}

			//int ret = Utility::getRand();
			//label1->Text = ret.ToString();
			//
			//switch (ret) {
			//case 0:
			//	direction = 'd';
			//	break;
			//case 1:
			//	direction = 'u';
			//	break;
			//case 2:
			//	direction = 'r';
			//	break;
			//case 3:
			//	direction = 'l';
			//	break;
			//}
		}
	}


	private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
		timer1->Stop();
	}
	
			 private: char pickupADirection()
			 {
				 int ret = Utility::getRand();
				 label1->Text = ret.ToString();

				 switch (ret) {
				 case 0:
					 direction = 'd';
					 break;
				 case 1:
					 direction = 'u';
					 break;
				 case 2:
					 direction = 'r';
					 break;
				 case 3:
					 direction = 'l';
					 break;
				 }
				 return direction;
			 }

};
}

