#ifndef MUSIC_H_INCLUDED
#define MUSIC_H_INCLUDED

#include<iostream>
#include<string>
#include <sstream>
using namespace std;

int forceStop = 0;

void music()
{

    if (musicon == true && forceStop == 0)
    {
        PlaySound("Music\\music1.wav", NULL, SND_LOOP | SND_ASYNC);
        forceStop = 1;
    }
    else if (musicon == false)
        PlaySound(NULL, 0, 0);
}
#endif
