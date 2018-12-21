#pragma once
#include"SDL.h"
#include"Point.h"
#include"Shape.h"

/** Line class **/

class Line: public Shape{
public:
    Point start; //This point stores the x and y coordinates of the point where user clicks the mouse button down.
    Point stop; //This point stores the x and y coordinates of the point where user leaves the mouse button up.
public:
    Line(Point, Point);
    void Draw(SDL_Renderer*); //To draw the Shape.
};

