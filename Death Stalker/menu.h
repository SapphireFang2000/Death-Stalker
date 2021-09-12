//Menu Renderring
#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

int pointer_x = 0;//co-ordinate of pointer
int pointer_y = 0;
int buttonColor = 0;//if pointer is above button what will happen

char button1[10][50] = {"Images\\menu\\start1.bmp","Images\\menu\\resume1.bmp","Images\\menu\\exit1.bmp","Images\\menu\\about_us1.bmp","Images\\menu\\highscore1.bmp","Images\\menu\\story1.bmp"}; //White button (before touch)
char button2[10][35] = {"Images\\menu\\start2.bmp","Images\\menu\\resume2.bmp","Images\\menu\\exit2.bmp","Images\\menu\\about_us2.bmp","Images\\menu\\highscore2.bmp","Images\\menu\\story2.bmp"};//Colour button (after touch)

struct buttonCordinate
{
	int x;
	int y;

}bCordinate[6]; 

void buttonCodinateInitialise() 
{
	
		bCordinate[0].x = 800;//Start
		bCordinate[0].y = 220;
		
		bCordinate[1].x = 900;//Resume
		bCordinate[1].y = 50;

		bCordinate[2].x = 470;//Exit
		bCordinate[2].y = 0;

		bCordinate[3].x = 50;//about
		bCordinate[3].y = 0;

		bCordinate[4].x = 50;//about
		bCordinate[4].y = 100;

		bCordinate[5].x = 50;//about
		bCordinate[5].y = 200;
}

#endif  
