#include"iGraphics.h"
#include"enemyShootKnight.h"
#include"menuBackground.h"
#include"music.h"
#include<iostream>
#include<string>
#include <sstream>

using namespace std;
#define screenWidth 1200
#define screenHeight 600
#define jumpLimit 250

FILE *fp;

char highscoreStr[10];



int mposx, mposy;
/*
function iDraw() is called again and again by the system.
*/




void iDraw()
{
    //place your drawing codes here

    iClear();


    if (gamestate == -1)
    {
        iShowBMP(0, 0, homemenu);

        iShowBMP2(1000, 25, "Music\\music1.bmp", 0);
        iText(980, 170, "Music Turn On/Off", GLUT_BITMAP_TIMES_ROMAN_24);

        for (int i = 0; i < 6; i++)
        {
            iShowBMP2(bcoordinate[i].x, bcoordinate[i].y, button1[i], 0);
        }
    }
    else if (gamestate == 0 )
    {
        if (newGame)
        {
            //pause or restart option
            num = 0;
            setAll();
            file1 = 0;
            knightOn = true;
            for (int i = 0; i < 10000; i++)
            {
                s[i].shootOn = false;
                s[i].x = 0;
            }
            for (int i = 0; i < 100; i++)
            {
                e1[i].x = 1200;
                e2[i].x = 1200;
                e3[i].x = 1200;
                e1[i].On = false;
                e2[i].On = false;
                e3[i].On = false;

            }

            knightHealth = 10;
            knightCordinateX = 50, knightCordinateY = 135;
            flowerHealth = 20;
            flowerOn = false;
            gameEnd = false;
            newGame = false;

        }
        if (num >= 100)
        {
            flowerOn = true;
        }
        for (int i = 0; i< 62; i++)
        {
            iShowBMP(upperBackground[i].x, upperBackground[i].y, ubImage[i]);
            iShowBMP(lowerBackground[i].x, lowerBackground[i].y, lbImage[i]);
        }
        if (!flowerOn)
        {
            for (int i = 0; i < 100; i++)
            {
                if (e1[i].On)
                    iShowBMP2(e1[i].x, e1[i].y, roundEnemy[roundEnemyPictureIndex], 255);
                if (e2[i].On)
                    iShowBMP2(e2[i].x, e2[i].y, turtleEnemy[turtleEnemyPictureIndex], 255);
                if (e3[i].On)
                    iShowBMP2(e3[i].x, e3[i].y, ghostEnemy[ghostEnemyPictureIndex], 255);
                if (e4[i].On)
                    iShowBMP2(e4[i].x, e4[i].y, rockEnemy[rockEnemyPictureIndex], 255);
                if (e5[i].On)
                    iShowBMP2(e5[i].x, e5[i].y, fireEnemy[fireEnemyPictureIndex], 255);
            }
        }

        for (int i = 0; i < 10000; i++)
        {
            if (s[i].shootOn)
            {
                iShowBMP2(s[i].x, s[i].y, "images\\shoot\\1.bmp", 255);

            }
        }
        if (knightOn)
        {
            knightHealthX = 600, knightHealthY = 550;
            for (int i = 0; i < knightHealth; i++)
            {
                iShowBMP2(knightHealthX, knightHealthY, "images\\HealthIcon.bmp", 0);
                knightHealthX += 60;
            }
            if (knightJumpOn)
            {
                if (knightJumpUp)
                {
                    iShowBMP2(knightCordinateX, knightCordinateY + knightCordinateJump, knightJump[knightJumpIndex], 0);
                }
                else
                {
                    iShowBMP2(knightCordinateX, knightCordinateY + knightCordinateJump, knightJump[knightJumpIndex], 0);
                }
            }

            else
            {
                if (!knightIdelOn)
                {
                    knightIdelCounter++;
                    if (knightFRunOn)
                    {
                        iShowBMP2(knightCordinateX, knightCordinateY, knightFRun[knightFRunIndex], 0);
                    }
                    else if (knightDuckOn)
                    {
                        iShowBMP2(knightCordinateX, knightCordinateY, "images//1.bmp", 255);
                    }
                    else
                        iShowBMP2(knightCordinateX, knightCordinateY, knightBRun[knightBRunIndex], 0);
                    if (knightIdelCounter >= 5)
                    {
                        knightFRunOn = false;
                        knightDuckOn = false;
                        knightIdelCounter = 0;
                        knightIdelOn = true;
                        knightFRunIndex = 0;
                        knightBRunIndex = 0;
                    }
                }
                else
                    iShowBMP2(knightCordinateX, knightCordinateY, knightIdel[knightIdelIndex], 0);


            }
            if (flowerOn)
            {
                flowerHealthX = 400, flowerHealthY = 500;
                for (int i = 0; i < flowerHealth; i++)
                {
                    iShowBMP2(flowerHealthX, flowerHealthY, "images\\BossHealthIcon.bmp", 255);
                    flowerHealthX += 40;
                }
                if (flowerIdealOn)
                {
                    iShowBMP2(flowerCoordinateX, flowerCoordinateY, flowerIdeal[flowerIdealIndex], 255);
                }
                if (flower1AttackOn)
                {
                    iShowBMP2(flowerCoordinateX, flowerCoordinateY, flower1Attack[flower1AttackIndex], 255);
                }
                if (flower2AttackOn)
                {
                    iShowBMP2(flowerCoordinateX, flowerCoordinateY, flower2Attack[flower2AttackIndex], 255);
                }
                if (flowerDeathOn)
                {
                    iShowBMP2(flowerCoordinateX, flowerCoordinateY, flowerDeath[flowerDeathIndex], 255);
                }
                for (int i = 0; i < 100; i++)
                {
                    if (fs[i].On)
                        iShowBMP2(fs[i].x, fs[i].y, flowerAcorn[flowerAcornIndex], 255);
                }
            }
        }
        _itoa(num, strnum, 10);
        iSetColor(rand() % 255, rand() % 255, rand() % 255);
        iText(1085, 20, "Score: ", GLUT_BITMAP_TIMES_ROMAN_24);
        iText(1150, 20, strnum,GLUT_BITMAP_TIMES_ROMAN_24);

    }
    else if (gamestate == 1)
    {
        iShowBMP(0, 0, score);
      
        fp = fopen("highscore.txt", "r");
        int highscoreArray[1000];
        for (int i = 0; i < 1000; i++)
        {
            highscoreArray[i] = -1;
        }

        for (int i = 0; fscanf(fp, "%d", &highscoreArray[i]) != EOF; i++)
        {

        }
        int temp = 0;
        for (int i = 0; i < 1000; i++)
        {
            for (int j = i; j < 1000; j++)
            {
                if (highscoreArray[i] < highscoreArray[j])
                {
                    temp = highscoreArray[i];
                    highscoreArray[i] = highscoreArray[j];
                    highscoreArray[j] = temp;
                }
            }
        }



        fclose(fp);
        fp = fopen("highscore.txt", "w");

        for (int i = 0; i < 10; i++)
        {
            fprintf(fp, "%d\n",highscoreArray[i]);
        }
        fclose(fp);

        fp = fopen("highscore.txt", "r");
        int highscore[5];
        fscanf(fp, "%d%d%d%d%d", &highscore[0], &highscore[1], &highscore[2], &highscore[3], &highscore[4]);
        _itoa(highscore[0], highscoreStr, 10);
        iSetColor(255, 255, 255);
        _itoa(highscore[0], highscoreStr, 10);
        iText(440, 350, highscoreStr, GLUT_BITMAP_TIMES_ROMAN_24);
        iText(410, 350, "1 .", GLUT_BITMAP_TIMES_ROMAN_24);

        _itoa(highscore[1], highscoreStr, 10);
        iText(440, 300, highscoreStr, GLUT_BITMAP_TIMES_ROMAN_24);
        iText(410, 300, "2 .", GLUT_BITMAP_TIMES_ROMAN_24);

        _itoa(highscore[2], highscoreStr, 10);
        iText(440, 250, highscoreStr, GLUT_BITMAP_TIMES_ROMAN_24);
        iText(410, 250, "3 .", GLUT_BITMAP_TIMES_ROMAN_24);

        _itoa(highscore[3], highscoreStr, 10);
        iText(440, 200, highscoreStr, GLUT_BITMAP_TIMES_ROMAN_24);
        iText(410, 200, "4 .", GLUT_BITMAP_TIMES_ROMAN_24);

        _itoa(highscore[4], highscoreStr, 10);
        iText(440, 150, highscoreStr, GLUT_BITMAP_TIMES_ROMAN_24);
        iText(410, 150, "5 .", GLUT_BITMAP_TIMES_ROMAN_24);


        fclose(fp);



    }
    else if (gamestate == 2)
    {

        iShowBMP2(0, 0, "images\\bc\\instuction1.bmp", 0);

    }
    else if (gamestate == 3)
    {

        iShowBMP2(0, 0, "images\\bc\\about_us1.bmp", 0);

    }


    else if (gamestate == 4)
    {

        iSetColor(0, 0, 0);
        exit(0);
    }
    else if (gamestate == 5) // show story 5* 6* 7*
    {
        iShowBMP2(0, 0, story1,0);
        iShowBMP2(550, 20, next1,0);
    }
    else if (gamestate == 6)
    {
        iShowBMP(0, 0, story2);
        iShowBMP2(950, 50, next1,0);
    }
    else if (gamestate == 7)
    {
        iShowBMP(0, 0, story3);
        iShowBMP2(1000, 165, next1,0);
    }
    if (gameEnd)
    {
        iSetColor(rand() % 255, rand() % 255, rand() % 255);
        iShowBMP(0, 0, "images\\GameOver.bmp");
        iText(50, 25, "Press q to go back to main menu", GLUT_BITMAP_TIMES_ROMAN_24);
        _itoa(num, strnum, 10);
        iSetColor(rand() % 255, rand() % 255, rand() % 255);
        iText(1085, 20, "Score: ", GLUT_BITMAP_TIMES_ROMAN_24);
        iText(1150, 20, strnum, GLUT_BITMAP_TIMES_ROMAN_24);
        if (file) 					
        {
            fp = fopen("highscore.txt", "a");
            fprintf(fp, "%d \n", num);
            fclose(fp);
            file = false;
        }



    }
}

/*
function iMouseMove() is called when the user presses and drags the mouse.
(mx, my) is the position where the mouse pointer is.
*/
void iMouseMove(int mx, int my)
{
    //place your codes here
}

/*
function iMouse() is called when the user presses/releases the mouse.
(mx, my) is the position where the mouse pointer is.
*/
void iMouse(int button, int state, int mx, int my)
{
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
        for (int i = 0; i < 5; i++)
        {
            if (mx >= bcoordinate[i].x && mx <= bcoordinate[i].x + 215 && my >= bcoordinate[i].y && my <= bcoordinate[i].y + 60)
            {
                if (i == 0)
                    gamestate = 5;
                gamestate = i;
                if (i == 0)
                    music();
                else if (i == 1)
                    music();
                else if (i == 2)
                    music();
                else  PlaySound("Music\\music2.wav", NULL, SND_LOOP | SND_ASYNC);
            }
        }
        if (mx >= bcoordinate[5].x && mx <= bcoordinate[5].x + 215 && my >= bcoordinate[5].y && my <= bcoordinate[5].y + 60)
        {
            gamestate = 5;
            newGame = true;
            gameEnd = false;
        }
        if (mx >= 1075 && mx <= 1200 && my >= 0 && my <= 50)
        {
            gamestate = -1;
            PlaySound("Music\\music1.wav", NULL, SND_LOOP | SND_ASYNC);
        }
        //for story
        if (mx >= 550 && mx <= 800 && my >= 0 && my <= 150)
        {
            gamestate = 6;
        }
        if (mx >= 950 && mx <= 1050 && my >= 50 && my <= 200)
        {
            gamestate = 7;
        }
        if (mx >= 1000 && mx <= 1200 && my >= 165 && my <= 300)
        {
            gamestate = 0;
        }
        if (mx >= 950 && mx <= 1100 && my >= 50 && my <= 200)
        {
            musicon = false;
        }
        //place your codes here

    }
    if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
    {
        //place your codes here
    }
    printf("%d %d ", mx, my);
}
/*iPassiveMouseMove is called to detect and use
the mouse point without pressing any button */

void iPassiveMouseMove(int mx, int my)
{
    //place your code here

    mposx = mx;
    mposy = my;

    if (mx == 2) {}       /*Something to do with mx*/
    else if (my == 2) {}  /*Something to do with my*/

}

/*
function iKeyboard() is called whenever the user hits a key in keyboard.
key- holds the ASCII value of the key pressed.
*/
void iKeyboard(unsigned char key)
{
    if (key == 'p')
    {

    }
    if (key == 'q')
    {
        gamestate = -1;
        gameEnd = false;
    }
    if (key == 'z')
    {
        s[shootindex].x = knightCordinateX + 15;
        s[shootindex].y = knightCordinateY + knightCordinateJump + 15;
        s[shootindex].shootOn = true;
        shootindex++;
        if (shootindex > 10000)
            shootindex = 0;

    }
    if (key == 's')
    {
        gamestate = 0;
    }
    if (key == 'm')
    {
        musicon =false ;
    }
    //place your codes for other keys here
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


    if (key == GLUT_KEY_UP)
    {

        if (gamestate == 0)
        {
            if (!knightJumpOn)
            {
                knightJumpOn = true;
                knightJumpUp = true;
            }
        }
    }
    if (key == GLUT_KEY_DOWN)
    {

    }
    if (key == GLUT_KEY_RIGHT)
    {
        if (gamestate == 0)
        {
            knightIdelOn = false;
            knightFRunOn = true;

            if (knightCordinateX <= 1100 && knightCordinateX >= 0)
                knightCordinateX += 30;  //knight speed
            knightFRunIndex++;
            if (knightFRunIndex >= 8)
                knightFRunIndex = 0;
            if (knightCordinateX >= 200)
            {
                for (int i = 0; i < 62; i++)
                {
                    upperBackground[i].x -= 5;
                    lowerBackground[i].x -= 5;

                    if (upperBackground[i].x <= 0)
                    {
                        upperBackground[i].x = 1200;

                    }
                    if (lowerBackground[i].x <= 0)
                    {
                        lowerBackground[i].x = 1200;
                    }
                }
            }
        }
    }
    if (key == GLUT_KEY_LEFT)
    {
        if (gamestate == 0)
        {
            knightIdelOn = false;
            knightFRunOn = false;
            if (knightCordinateX >= 100)
                knightCordinateX -= 30;  //knight speed
            knightBRunIndex++;
            if (knightBRunIndex >= 8)
                knightBRunIndex = 0;
        }
    }
    //place your codes for other keys here
}











int main()
{

    //place your own initialization codes here.
    iSetTimer(1000, music);
    int sum = 100;
    for (int i = 4; i >= 0; i--)
    {
        bcoordinate[i].x = 0;
        bcoordinate[i].y = sum;
        sum = sum + 80;
    }
    bcoordinate[5].x = 0;
    bcoordinate[5].y = 500;
    setAll();
    iSetTimer(40, jumpNShootSpeedNIdeal);


    iSetTimer(800, arriveEnemy);
    iSetTimer(100, enemySpeed);


    iSetTimer(100, flowerBoss);
    iSetTimer(5000, fAttackStart);




    iInitialize(screenWidth, screenHeight, "Death Stalker");
    return 0;
}
