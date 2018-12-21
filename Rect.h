#pragma once
#include"SDL.h"
#include"Point.h"
#include"Shape.h"

/** Rect class **/

class Rect: public Shape{
public:
    Point topLeft;
    Point bottomRight;
public:
    Rect(SDL_Rect*); //
    void Draw(SDL_Renderer*); //To Draw the shape.
};

