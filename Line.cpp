#include"Line.h"
#include<iostream>
using namespace std;
#include"Shape.h"
#include"SDL.h"
#include"Point.h"

/** Draws the rectangle **/
Line::Line(Point s,Point e)
{
    start=s;
    stop=e;
}
void Line::Draw(SDL_Renderer* gRenderer) //Where to draw the rectangle and what to draw.
{
    SDL_SetRenderDrawColor( gRenderer, C.red , C.blue, C.green, 0xFF );
    SDL_RenderDrawLine(gRenderer,start.x,start.y,stop.x,stop.y );
}

