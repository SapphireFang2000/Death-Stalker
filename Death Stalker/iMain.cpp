#include "iGraphics.h"
#include "background_rendering.h"
#include "character_rendering.h"

#define screenWidth 1200
#define screenHeight 600

//:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::Idraw Here::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::://

void iDraw()
{
	iClear();

	//Background Images Renderring
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


/*function iMouseMove() is called when the user presses and drags the mouse.
(mx, my) is the position where the mouse pointer is.
*/


void iMouseMove(int mx, int my)
{

}
//*******************************************************************ipassiveMouse***********************************************************************//
void iPassiveMouseMove(int mx, int my)
{

}

void iMouse(int button, int state, int mx, int my)
{

	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{


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
			theKnightIndex = 0;

		standPosition = false;
	}
	else if (key == GLUT_KEY_LEFT)
	{
		theKnightCordinateX -= 10;

		theKnightIndex--;

		if (theKnightIndex <= 0)
			theKnightIndex = 7;

		standPosition = false;
	}

	else if (key == GLUT_KEY_HOME)
	{

	}

}

int main()
{
	//Background Images Renderring
	setAll();

	iInitialize(screenWidth, screenHeight, "Death Stalker");
	iStart();

	return 0;
}
