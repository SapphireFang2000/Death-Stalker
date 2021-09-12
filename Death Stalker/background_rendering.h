//Background Renderring
#ifndef BACKGROUND_RENDERING_H_INCLUDED
#define BACKGROUND_RENDERING_H_INCLUDED
 
#define upperBackGroundSpeed 10
#define lowerBackGroundSpeed 10

//Background Images Renderring
char upperBackgroundImage[5][45] = {"Images\\background_images\\stage_1_01.bmp", "Images\\background_images\\stage_1_02.bmp", "Images\\background_images\\stage_1_03.bmp", "Images\\background_images\\stage_1_04.bmp", "Images\\background_images\\stage_1_05.bmp"};
char lowerBackgroundImage[5][45] = {"Images\\background_images\\stage_1_06.bmp", "Images\\background_images\\stage_1_07.bmp", "Images\\background_images\\stage_1_08.bmp", "Images\\background_images\\stage_1_09.bmp", "Images\\background_images\\stage_1_10.bmp"};

struct background
{
    int x;
    int y;
};

background upperBackground[5];
background lowerBackground[5];

//Background Images Coordinate Set
void setAll()
{
    int sum = 0;
    for (int i=0; i<5; i++)
    {
        upperBackground[i].y = 150;
        lowerBackground[i].y = 0;
        upperBackground[i].x = sum;
        lowerBackground[i].x = sum;
        sum += 240;
    }
}

#endif  
