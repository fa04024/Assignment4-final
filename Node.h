#pragma once
#include"Rect.h"

struct Node{
Node()
{
    //ctor
}

~Node()
{
    //delete[] ptr;
    //delete[] next;
}
    Shape* ptr; //There are two parameters stored in stack. A Shape* type ptr and next.
    Node* next;
};
