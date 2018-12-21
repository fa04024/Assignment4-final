#include"Rect.h"
#include<iostream>
using namespace std;
#include"Shape.h"

Rect::Rect(SDL_Rect* rect)
{
    fillRect= new SDL_Rect; //Stores rectangle objects in fillRect.
    fillRect->x=rect->x; //Equating the x coordinate of rect equal to the x coordinate of fillRect.
    fillRect->y=rect->y; //Equating the y coordinate of rect equal to the y coordinate of fillRect.
    fillRect->w=rect->w; //Equating the w coordinate of rect equal to the w coordinate of fillRect.
    fillRect->h=rect->h; //Equating the h coordinate of rect equal to the h coordinate of fillRect.
}


/** Draws the rectangle **/

void Rect::Draw(SDL_Renderer* gRenderer) //Where to draw the rectangle and what to draw.
{
    SDL_SetRenderDrawColor( gRenderer, C.red , C.blue, C.green, 0xFF ); //Fill a rectangle on the current rendering target with the drawing color.
    SDL_RenderFillRect( gRenderer, fillRect );
}

