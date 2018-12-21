#pragma once
#include<time.h>
#include<stdlib.h>
struct Color
{
    int red;
    int green;
    int blue;

    Color()
    {
        red = rand()%256;
        green = rand()%255;
        blue = rand()%255;
    }

    Color(int red, int green, int blue)
    {
        this->red = red;
        this->green = green;
        this->blue = blue;
    }
};
