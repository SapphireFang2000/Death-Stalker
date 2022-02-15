#ifndef MENUBACKGROUND_H_INCLUDED
#define MENUBACKGROUND_H_INCLUDED
#include<iostream>
#include<string>
#include <sstream>
using namespace std;
#define screenWidth 1200
#define screenHeight 600
#define jumpLimit 250

int dx = 10;
int dy = 10;
char ubImage[62][30] = { "images\\bg\\ubg\\ubg_1.bmp", "images\\bg\\ubg\\ubg_2.bmp", "images\\bg\\ubg\\ubg_3.bmp", "images\\bg\\ubg\\ubg_4.bmp", "images\\bg\\ubg\\ubg_5.bmp", "images\\bg\\ubg\\ubg_6.bmp", "images\\bg\\ubg\\ubg_7.bmp", "images\\bg\\ubg\\ubg_8.bmp", "images\\bg\\ubg\\ubg_9.bmp", "images\\bg\\ubg\\ubg_10.bmp", "images\\bg\\ubg\\ubg_11.bmp",
                         "images\\bg\\ubg\\ubg_12.bmp", "images\\bg\\ubg\\ubg_13.bmp", "images\\bg\\ubg\\ubg_14.bmp", "images\\bg\\ubg\\ubg_15.bmp", "images\\bg\\ubg\\ubg_16.bmp", "images\\bg\\ubg\\ubg_17.bmp", "images\\bg\\ubg\\ubg_18.bmp", "images\\bg\\ubg\\ubg_19.bmp", "images\\bg\\ubg\\ubg_20.bmp", "images\\bg\\ubg\\ubg_21.bmp",
                         "images\\bg\\ubg\\ubg_22.bmp", "images\\bg\\ubg\\ubg_23.bmp", "images\\bg\\ubg\\ubg_24.bmp", "images\\bg\\ubg\\ubg_25.bmp", "images\\bg\\ubg\\ubg_26.bmp", "images\\bg\\ubg\\ubg_27.bmp", "images\\bg\\ubg\\ubg_28.bmp", "images\\bg\\ubg\\ubg_29.bmp", "images\\bg\\ubg\\ubg_30.bmp", "images\\bg\\ubg\\ubg_31.bmp", "images\\bg\\ubg\\ubg_32.bmp",
                         "images\\bg\\ubg\\ubg_33.bmp", "images\\bg\\ubg\\ubg_34.bmp", "images\\bg\\ubg\\ubg_35.bmp", "images\\bg\\ubg\\ubg_36.bmp", "images\\bg\\ubg\\ubg_37.bmp", "images\\bg\\ubg\\ubg_38.bmp", "images\\bg\\ubg\\ubg_39.bmp", "images\\bg\\ubg\\ubg_40.bmp", "images\\bg\\ubg\\ubg_41.bmp", "images\\bg\\ubg\\ubg_42.bmp", "images\\bg\\ubg\\ubg_43.bmp",
                         "images\\bg\\ubg\\ubg_44.bmp", "images\\bg\\ubg\\ubg_45.bmp", "images\\bg\\ubg\\ubg_46.bmp", "images\\bg\\ubg\\ubg_47.bmp", "images\\bg\\ubg\\ubg_48.bmp", "images\\bg\\ubg\\ubg_49.bmp", "images\\bg\\ubg\\ubg_50.bmp", "images\\bg\\ubg\\ubg_51.bmp", "images\\bg\\ubg\\ubg_52.bmp", "images\\bg\\ubg\\ubg_53.bmp", "images\\bg\\ubg\\ubg_54.bmp", "images\\bg\\ubg\\ubg_55.bmp", "images\\bg\\ubg\\ubg_56.bmp", "images\\bg\\ubg\\ubg_57.bmp", "images\\bg\\ubg\\ubg_58.bmp", "images\\bg\\ubg\\ubg_59.bmp", "images\\bg\\ubg\\ubg_60.bmp", "images\\bg\\ubg\\ubg_61.bmp", "images\\bg\\ubg\\ubg_62.bmp"
                       };

char lbImage[62][30] = { "images\\bg\\lbg\\lbg_1.bmp", "images\\bg\\lbg\\lbg_2.bmp", "images\\bg\\lbg\\lbg_3.bmp", "images\\bg\\lbg\\lbg_4.bmp", "images\\bg\\lbg\\lbg_5.bmp", "images\\bg\\lbg\\lbg_6.bmp", "images\\bg\\lbg\\lbg_7.bmp", "images\\bg\\lbg\\lbg_8.bmp", "images\\bg\\lbg\\lbg_9.bmp", "images\\bg\\lbg\\lbg_10.bmp", "images\\bg\\lbg\\lbg_11.bmp",
                         "images\\bg\\lbg\\lbg_12.bmp", "images\\bg\\lbg\\lbg_13.bmp", "images\\bg\\lbg\\lbg_14.bmp", "images\\bg\\lbg\\lbg_15.bmp", "images\\bg\\lbg\\lbg_16.bmp", "images\\bg\\lbg\\lbg_17.bmp", "images\\bg\\lbg\\lbg_18.bmp", "images\\bg\\lbg\\lbg_19.bmp", "images\\bg\\lbg\\lbg_20.bmp", "images\\bg\\lbg\\lbg_21.bmp",
                         "images\\bg\\lbg\\lbg_22.bmp", "images\\bg\\lbg\\lbg_23.bmp", "images\\bg\\lbg\\lbg_24.bmp", "images\\bg\\lbg\\lbg_25.bmp", "images\\bg\\lbg\\lbg_26.bmp", "images\\bg\\lbg\\lbg_27.bmp", "images\\bg\\lbg\\lbg_28.bmp", "images\\bg\\lbg\\lbg_29.bmp", "images\\bg\\lbg\\lbg_30.bmp", "images\\bg\\lbg\\lbg_31.bmp", "images\\bg\\lbg\\lbg_32.bmp",
                         "images\\bg\\lbg\\lbg_33.bmp", "images\\bg\\lbg\\lbg_34.bmp", "images\\bg\\lbg\\lbg_35.bmp", "images\\bg\\lbg\\lbg_36.bmp", "images\\bg\\lbg\\lbg_37.bmp", "images\\bg\\lbg\\lbg_38.bmp", "images\\bg\\lbg\\lbg_39.bmp", "images\\bg\\lbg\\lbg_40.bmp", "images\\bg\\lbg\\lbg_41.bmp", "images\\bg\\lbg\\lbg_42.bmp", "images\\bg\\lbg\\lbg_43.bmp",
                         "images\\bg\\lbg\\lbg_44.bmp", "images\\bg\\lbg\\lbg_45.bmp", "images\\bg\\lbg\\lbg_46.bmp", "images\\bg\\lbg\\lbg_47.bmp", "images\\bg\\lbg\\lbg_48.bmp", "images\\bg\\lbg\\lbg_49.bmp", "images\\bg\\lbg\\lbg_50.bmp", "images\\bg\\lbg\\lbg_51.bmp", "images\\bg\\lbg\\lbg_52.bmp", "images\\bg\\lbg\\lbg_53.bmp", "images\\bg\\lbg\\lbg_54.bmp", "images\\bg\\lbg\\lbg_55.bmp", "images\\bg\\lbg\\lbg_56.bmp", "images\\bg\\lbg\\lbg_57.bmp", "images\\bg\\lbg\\lbg_58.bmp", "images\\bg\\lbg\\lbg_59.bmp", "images\\bg\\lbg\\lbg_60.bmp", "images\\bg\\lbg\\lbg_61.bmp", "images\\bg\\lbg\\lbg_62.bmp"
                       };

struct background
{

    int x;
    int y;

} upperBackground[62], lowerBackground[62];
//Shamim
struct buttoncoordinate
{
    int x, y;


} bcoordinate[6];

char button1[6][30] = { "images\\menu\\resume1.bmp", "images\\menu\\highscore1.bmp", "images\\menu\\instruction1.bmp", "images\\menu\\about_us1.bmp", "images\\menu\\exit1.bmp", "images\\menu\\start3.bmp" };
char homemenu[30] = { "images\\bc\\homemenu.bmp" };
char score[25] = { "images\\bc\\high_score.bmp" };
char underbatton[26] = { "images\\bg\\underbatton.bmp" };
char underscore[30] = { "images\\bg\\underscore.bmp" };
char about[22] = { "images\\bc\\about.bmp" };
char instruction[30] = { "images\\bc\\instruction1.bmp" };
char yellow[22] = { "images\\bc\\yellow.bmp" };
char forward1[30] = { "images\\bc\\forward.bmp" };
char forwardmovement[31] = { "images\\bc\\forwardmovement.bmp" };
char backward[23] = { "images\\bc\\backward.bmp" };
char backwardmovement[31] = { "images\\bc\\backwardmovement.bmp" };
char flying[22] = { "images\\bc\\jump.bmp" };
char flyingmovement[27] = { "images\\bc\\jumpmovement.bmp" };
char duck[22] = { "images\\bc\\duck.bmp" };
char duckmovement[27] = { "images\\bc\\duckmovement.bmp" };
char sky[22] = { "images\\bc\\sky.bmp" };
char menu[22] = { "images\\bc\\menu.bmp" };
char story1[30] = { "images\\story\\story1.bmp" };
char story2[30] = { "images\\story\\story2.bmp" };
char story3[30] = { "images\\story\\story3.bmp" };
char next1[30] = { "images\\story\\next1.bmp" };
char next2[30] = { "images\\story\\next2.bmp" };
char next3[30] = { "images\\story\\next3.bmp" };




int gamestate = -1; //-1 for menu 0 for game
bool newGame = true;

//shamim
bool musicon = true;

void setAll()
{

    int sum = 0;
    for (int i = 0; i < 62; i++)
    {

        upperBackground[i].y = 120;
        lowerBackground[i].y = 0;
        upperBackground[i].x = sum;
        lowerBackground[i].x = sum;
        sum += 20;
    }



}



#endif
