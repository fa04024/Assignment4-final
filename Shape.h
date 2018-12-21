#ifndef SHAPE_H
#define SHAPE_H
#include"SDL.h"
#include"Color.h"
class Shape
{
    public:
        Color C; //Making a color object in shape.
        SDL_Rect* fillRect;
        Shape();
        virtual void Draw(SDL_Renderer* gRenderer)=0; //So that the compiler does not say that Draw function is not defined in shape.

        virtual ~Shape();

    protected:

    private:
};

#endif // SHAPE_H
