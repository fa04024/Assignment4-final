#include"Stack.h"
#include"Rect.h"
#include"Shape.h"
#include <iostream>
using namespace std;

Stack::Stack()
{
    head = NULL;
}

Stack::~Stack()
{
    head = NULL;
}

void Stack::Push(Shape* ptr)
{
    if (head == NULL)
    {
        head = new Node;
        head->ptr =ptr;
        head->next = NULL;
    }
    else
    {
        Node* temp = head;
        head = new Node;
        head->ptr = ptr;
        head->next = temp;
    }
    cout<<"Pushing "<<head->ptr<<endl;
}

Shape* Stack::Pop()
{
    Shape* ptr = NULL;
    if(head != NULL)
    {
        Node* temp = head;
        head = head->next;
        ptr = temp->ptr;
        delete temp;
        temp = NULL;
    }

    cout<<"Popping "<<ptr<<endl;

    return ptr;
}


void Stack::Show(SDL_Renderer* gRenderer)
{
    Node* temp = head;
    while(temp!=NULL)
    {
        temp->ptr->Draw(gRenderer); //Where to make and what shape to make.
        temp = temp->next;
    }
}

