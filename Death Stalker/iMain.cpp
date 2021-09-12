#include "iGraphics.h"
#include "menu.h"
#include "background_rendering.h"
#include "character_rendering.h"

#define screenWidth 1200
#define screenHeight 600

//:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::Controller::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::://
int gameState = -1;
//:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::Idraw Here::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::://

void iDraw()
{
	iClear();

	//Home Menu Renderring
	if (gameState == -1)
	{
		iShowBMP(0, 0, "Images\\menu\\background.bmp");//Background of menu

		if (buttonColor == 0)
		{
			for (int i = 0; i <= 5; i++)
			{
				iShowBMP2(bCordinate[i].x, bCordinate[i].y, button1[i], 0);
			}
		}
		else if (buttonColor == 1)
		{
			for (int i = 0; i <= 5; i++)
			{
				iShowBMP2(bCordinate[i].x, bCordinate[i].y, button2[i], 0);
			}
		}
	}
	else if (gameState == 0)
	{
		// Background Renderring
		for (int i = 0; i<5; i++)
		{
			iShowBMP2(upperBackground[i].x, upperBackground[i].y, upperBackgroundImage[i], 0);
			iShowBMP2(lowerBackground[i].x, lowerBackground[i].y, lowerBackgroundImage[i], 0);
		}

		//Character Renderring
		if (!standPosition)
		{
			iShowBMP2(theKnightCordinateX, theKnightCordinateY, theKnight[theKnightIndex], 0);
			standCounter++;

			if (standCounter >= 20)
			{
				standCounter = 0;
				theKnightIndex = 0;
				standPosition = true;
			}
		}
		else
		{
			iShowBMP2(theKnightCordinateX, theKnightCordinateY, theKnightStand, 0);
		}
	}
	else if (gameState == 1)//resume
	{
		iShowBMP2(300, 300, button1[1], 0);
	}
	else if (gameState == 2)//exit
	{
		exit(0);
		/*iShowBMP2(300,300,button1[2], 0);*/
	}
	else if (gameState == 3)//About Us
	{
		iShowBMP2(300, 300, button1[3], 0);
	}
	else if (gameState == 4)//high score
	{
		iShowBMP2(300, 300, button1[4], 0);
	}
	else if (gameState == 5)//story
	{
		iShowBMP2(0, 0, "Images\\menu\\story\\1.bmp", 0);
	}
	else
	{

	}

	iShowBMP2(pointer_x, pointer_y, "Images\\menu\\pointer1.bmp", 0);
}

/*function iMouseMove() is called when the user presses and drags the mouse.
(mx, my) is the position where the mouse pointer is.
*/


void iMouseMove(int mx, int my)
{

}

//*******************************************************************ipassiveMouse***********************************************************************//

void iPassiveMouseMove(int mx, int my)
{
	pointer_x = mx - 31;
	pointer_y = my - 16;
	for (int i = 0; i<3; i++) //need correction only exit button changes
	{
		if (pointer_x >= bCordinate[i].x && pointer_x <= bCordinate[i].x + 294 && pointer_y >= bCordinate[i].y && pointer_y <= bCordinate[i].y + 214)
		{
			buttonColor = 1;
			printf("\n----Color \t Color \t-----\n");
		}
		else
		{
			buttonColor = 0;
		}

	}
}

void iMouse(int button, int state, int mx, int my)
{

	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		{
			for (int i = 0; i <= 5; i++)
			{
				if (mx >= bCordinate[i].x && mx <= bCordinate[i].x + 294 && my >= bCordinate[i].y && my <= bCordinate[i].y + 214)
				{
					gameState = i;
				}
			}
			printf("x=%d y=%d\n", mx, my);
		}
	}

	if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{

	}
}

/*
function iKeyboard() is called whenever the user hits a key in keyboard.
key- holds the ASCII value of the key pressed.
*/

void iKeyboard(unsigned char key)
{
	if (key == '\r')
	{

	}
}

/*
function iSpecialKeyboard() is called whenver user hits special keys like-
function keys, home, end, pg up, pg down, arraows etc. you have to use
appropriate constants to detect them. A list is:
GLUT_KEY_F1, GLUT_KEY_F2, GLUT_KEY_F3, GLUT_KEY_F4, GLUT_KEY_F5, GLUT_KEY_F6,
GLUT_KEY_F7, GLUT_KEY_F8, GLUT_KEY_F9, GLUT_KEY_F10, GLUT_KEY_F11, GLUT_KEY_F12,
GLUT_KEY_LEFT, GLUT_KEY_UP, GLUT_KEY_RIGHT, GLUT_KEY_DOWN, GLUT_KEY_PAGE UP,
GLUT_KEY_PAGE DOWN, GLUT_KEY_HOME, GLUT_KEY_END, GLUT_KEY_INSERT
*/

void iSpecialKeyboard(unsigned char key)
{


	if (key == GLUT_KEY_RIGHT)
	{
		theKnightCordinateX += 10;

		theKnightIndex++;

		if (theKnightIndex >= 9)
		{
			theKnightIndex = 0;
		}

		standPosition = false;
	}
	else if (key == GLUT_KEY_LEFT)
	{
		theKnightCordinateX -= 10;

		theKnightIndex--;

		if (theKnightIndex <= 0)
		{
			theKnightIndex = 7;
		}

		standPosition = false;
	}
	else if (key == GLUT_KEY_HOME)
	{

	}
}


int main()
{
	buttonCodinateInitialise();//For Button Control
	setAll();//For Background Image Renderring

	iInitialize(screenWidth, screenHeight, "Death Stalker");
	iStart();

	return 0;
}
