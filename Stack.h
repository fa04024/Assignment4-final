#pragma once
#include"Node.h"

class Stack
{
private:
    Node* head;
public:
    Stack();
    ~Stack();
    void Push(Shape*); //Pushing a shape pointer type in stack.
    Shape* Pop(); //Popping an object from stack that is of type Shape*
    void Show(SDL_Renderer* gRenderer); //To show the shape on the screen.
};
