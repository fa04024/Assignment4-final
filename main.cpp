/*This source code copyrighted by Lazy Foo' Productions (2004-2015)
and may not be redistributed without written permission.*/

//Using SDL, SDL_image, standard IO, math, and strings
#include <SDL.h>
#include <stdio.h>
#include <string>
#include <cmath>
#include <iostream>
#include"Rect.h"
#include"Stack.h"
#include"stdlib.h"
#include"time.h"
#include"Shape.h"
#include"Color.h"
#include"Line.h"
#include"Point.h"
using namespace std;


//Screen dimension constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

//Starts up SDL and creates window
bool init();

//Loads media
bool loadMedia();

//Frees media and shuts down SDL
void close();

//Loads individual image as texture
//SDL_Texture* loadTexture( std::string path );

//The window we'll be rendering to
SDL_Window* gWindow = NULL;

//The window renderer
SDL_Renderer* gRenderer = NULL;

bool init()
{
	//Initialization mouseClicked
	bool success = true;

	//Initialize SDL
	if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
	{
		printf( "SDL could not initialize! SDL Error: %s\n", SDL_GetError() );
		success = false;
	}
	else
	{
		//Set texture filtering to linear
		if( !SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1" ) )
		{
			printf( "Warning: Linear texture filtering not enabled!" );
		}

		//Create window
		gWindow = SDL_CreateWindow( "SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
		if( gWindow == NULL )
		{
			printf( "Window could not be created! SDL Error: %s\n", SDL_GetError() );
			success = false;
		}
		else
		{
			//Create renderer for window
			gRenderer = SDL_CreateRenderer( gWindow, -1, SDL_RENDERER_ACCELERATED );
			if( gRenderer == NULL )
			{
				printf( "Renderer could not be created! SDL Error: %s\n", SDL_GetError() );
				success = false;
			}
			else
			{
				//Initialize renderer color
				SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );
			}
		}
	}

	return success;
}

bool loadMedia()
{
	//Loading success mouseClicked
	bool success = true;

	//Nothing to load
	return success;
}

void close()
{
	//Destroy window
	SDL_DestroyRenderer( gRenderer );
	SDL_DestroyWindow( gWindow );
	gWindow = NULL;
	gRenderer = NULL;

	//Quit SDL subsystems
//	IMG_Quit();
	SDL_Quit();
}
int main( int argc, char* args[] )
{
    bool R;
    srand(time(NULL));
	//Start up SDL and create window
	if( !init() )
	{
		printf( "Failed to initialize!\n" );
	}
	else
	{

		if( !loadMedia() )  //Load media
		{
			printf( "Failed to load media!\n" );
		}
		else
		{
			bool quit = false;  //Main loop controller

			SDL_Event e;        //Event handler that takes care of all events

			bool mouseClicked = false;
			SDL_Rect fillRect;
			Stack S; //Making first stack.
			Stack S1; //Making second stack.
			Shape* poppedShape;

			int oldx = 0;
            int oldy = 0;
            Point startPoint;
            Point endPoint;

            Rect* rect = NULL;
            Line* line=NULL;

			//While application is running
			while( !quit )
			{

				//Handle events on queue
				while( SDL_PollEvent( &e ) != 0 )
				{
					//User requests quit
					if ((e.key.keysym.sym==SDLK_r) &&(e.type==SDL_KEYDOWN))
                    {
                        R=true;
                    }
                    if ((e.key.keysym.sym==SDLK_l) && (e.type==SDL_KEYDOWN))
                    {
                        R=false;
                    }
					if( e.type == SDL_QUIT )
					{
						quit = true;
					}

					if( e.type == SDL_MOUSEMOTION || e.type == SDL_MOUSEBUTTONDOWN || e.type == SDL_MOUSEBUTTONUP )
                    {
                        //Get mouse position
                        int x, y;
                        SDL_GetMouseState( &x, &y );

                        if(e.type ==  SDL_MOUSEMOTION)
                        {

                            if(mouseClicked == true)
                                fillRect = { oldx , oldy , x - oldx, y - oldy };

                        }

                        if((e.type==SDL_MOUSEBUTTONDOWN) && (e.button.button==SDL_BUTTON_RIGHT))
                        {
                            mouseClicked = true; //Check if the mouse if clicked.
                            poppedShape=S.Pop(); //Pops from the stack S and stores in a variable.
                            S1.Push(poppedShape); //Pops the object in the other stack.
                        }

                        //
                        else if((e.type==SDL_MOUSEBUTTONDOWN) && (e.button.button==SDL_BUTTON_MIDDLE))
                        {
                            S.Push(S1.Pop()); //Push the object in first stack by popping it from second stack.
                        }

                        //If left mouse button is pressed it stores the start coordinates of mouse.
                        else if((e.type == SDL_MOUSEBUTTONDOWN)&& (e.button.button==SDL_BUTTON_LEFT))
                        {
                            if(mouseClicked == false)
                            {
                                mouseClicked = true;
                                oldx = x;
                                oldy = y;

                                startPoint.x= x; //for line
                                startPoint.y= y; //for line
                            }
                        }
                        //If left mouse button is left.
                        if(e.type == SDL_MOUSEBUTTONUP && e.button.button == SDL_BUTTON_LEFT)
                        {
                            mouseClicked = false;

                            endPoint.x=x; //Storing coordinates in a point where user left the mouse button.
                            endPoint.y=y;

                            if (R==true)
                            {
                                rect = new Rect(&fillRect); //Making a new rect object.
                                S.Push(rect); //Pushing the rectangle in the original stack.

                            }
                            else if (R==false)
                            {
                                line=new Line(startPoint,endPoint); //Making a new object for line.
                                S.Push(line); //Pushing that line in the stack.
                            }

                        }

                    }
				}
                //Clear screen

                SDL_SetRenderDrawColor( gRenderer, 255, 255, 255, 0xFF ); //setting the color of the SDL window screen
				SDL_RenderClear( gRenderer ); //clearing the screen whenever a new rectangle is made.

             //   if ((rect != NULL) && (line!=NULL))//If rect pointer in pointing towards rect object.
              //  {

                    //SDL_SetRenderDrawColor( gRenderer, C.red , C.blue, C.green, 0xFF );
                    S.Show(gRenderer);
                    //rect->Draw(gRenderer); //kahan pr bnana hai aur kya bnana hai.
                //}

				//Update screen
				SDL_RenderPresent( gRenderer ); //update the screen.


			}
		}
	}

	//Free resources and close SDL
	close();

	return 0;
}

